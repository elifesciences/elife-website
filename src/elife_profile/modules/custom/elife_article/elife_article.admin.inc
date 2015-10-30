<?php

/**
 * @file
 * Pre-populate the article html content into a field for search and in cache.
 */

/**
 * Settings form as implemented by hook_menu.
 */
function elife_article_markup_prepopulate_form($form, &$form_state) {
  $total = _elife_article_version_count();
  $emptys = _elife_article_empty_main_text();
  $remaining = $total - count($emptys);

  $args = array(
    '@remaining' => $remaining,
    '@total' => $total,
  );
  if (empty($form_state['input'])) {
    drupal_set_message(t('@remaining/@total article versions have the associated markup cached.', $args));
  }

  $form['flush_all'] = array(
    '#type' => 'checkbox',
    '#title' => t('Flush all stored markup'),
    '#default_value' => FALSE,
  );

  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update'),
  );

  return $form;
}

/**
 * Submit handler.
 *
 * @param array $form
 *   Form API form.
 * @param array $form_state
 *   Form API form.
 */
function elife_article_markup_prepopulate_form_submit($form, &$form_state) {
  $force_empty = FALSE;
  if (!empty($form_state['values']['flush_all'])) {
    db_truncate('elife_markup')->execute();
    $force_empty = TRUE;
  }
  batch_set(elife_article_markup_prepopulate_process($force_empty));
}

/**
 * Process a batch of markup requests.
 *
 * @param bool $force_empty
 *
 * @return array
 *   Array of batch instructions.
 */
function elife_article_markup_prepopulate_process($force_empty = FALSE) {
  $emptys = _elife_article_empty_main_text($force_empty);
  $operations = [];
  if (!empty($emptys)) {
    $per_batch = variable_get('elife_markup_pre_batch', 10);
    for ($i = 0; $i < count($emptys); $i += $per_batch) {
      $operations[] = array(
        'elife_article_markup_prepopulate_process_items',
        array(
          array_slice($emptys, $i, $per_batch, TRUE),
        ),
      );
    }
  }
  // Build the batch instructions.
  $batch = array(
    'title' => t('Transfer markup to main text field and cache.'),
    'operations' => $operations,
    'finished' => 'elife_article_markup_prepopulate_process_finished',
    'file' => drupal_get_path('module', 'elife_article') . '/elife_article.admin.inc',
  );
  return $batch;
}

/**
 * Process the items in a batch of markup requests.
 *
 * @param array $items
 * @param array $context
 */
function elife_article_markup_prepopulate_process_items($items, &$context) {
  $context['results'] = array_merge($context['results'], array_values($items));
  array_merge($context['results'], array_values($items));
  _elife_article_emptys_markup_populate($items);

  foreach ($items as $article_version_id) {
    // Warm the markup query cache for this article version.
    _elife_article_markup_cache_warm($article_version_id);
  }
}

/**
 * Review the status of the process after a single batch run.
 *
 * @param $success
 * @param $results
 * @param $operations
 */
function elife_article_markup_prepopulate_process_finished($success, $results, $operations) {
  if ($success) {
    drupal_set_message(t('@count article version markup requests have been stored.', array('@count' => count($results))));
  }
  else {
    // An error occurred.
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    drupal_set_message(t('An error occurred while processing @operation with arguments : @args', array('@operation' => $error_operation[0], '@args' => $error_operation[1][0]->cid)));
  }
}

/**
 * Implements hook_admin_settings().
 */
function elife_article_xml_source_settings_form($form_state) {
  $form = array();
  $form['source_xml'] = array(
    '#title' => t('Settings for the retrieval of Article Version XML'),
    '#type' => 'fieldset',
  );

  if (!empty(variable_get('elife_article_source_xml_base_path')) && !empty(variable_get('elife_article_source_xml_file_pattern'))) {
    $query = new EntityFieldQueryExtraFields();

    $entities = $query->entityCondition('entity_type', 'node')
      ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT')
      ->propertyCondition('type', 'elife_article_ver')
      ->fieldCondition('field_elife_a_subarticle', 'value', 0)
      ->propertyCondition('status', 1)
      ->range(0, 1)
      ->execute();

    if (!empty($entities['node'])) {
      $nids = array_keys($entities['node']);
      $node = node_load(array_shift($nids));
      $example_xml_path = elife_article_version_source_xml_path($node);
      $form['source_xml']['elife_article_source_xml_example'] = array(
        '#type' => 'item',
        '#title' => t('Example source xml path'),
        '#markup' => $example_xml_path,
      );
    }
  }

  $form['source_xml']['elife_article_source_xml_base_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Source XML base path'),
    '#default_value' => variable_get('elife_article_source_xml_base_path'),
  );
  $form['source_xml']['elife_article_source_xml_file_pattern'] = array(
    '#type' => 'textfield',
    '#title' => t('Source XML file pattern'),
    '#default_value' => variable_get('elife_article_source_xml_file_pattern'),
  );

  if (module_exists('token')) {
    $form['source_xml']['elife_article_source_xml_file_pattern']['#description'] = t('Token replacement will be performed on this value.');
    $form['source_xml']['tokens'] = array(
      '#title' => t('Tokens'),
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['source_xml']['tokens']['help'] = array(
      '#theme' => 'token_tree',
      '#token_types' => array('node'),
    );
  }
  return system_settings_form($form);
}