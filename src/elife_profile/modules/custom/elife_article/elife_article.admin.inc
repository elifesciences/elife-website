<?php

/**
 * @file
 * Pre-populate the article html content into a field for search and in cache.
 */

/**
 * Settings form as implemented by hook_menu.
 */
function elife_article_eif_json_prepopulate_form($form, &$form_state) {
  $total = _elife_article_version_count();
  $emptys = _elife_article_empty_eif_json();
  $remaining = $total - count($emptys);

  $args = array(
    '@remaining' => $remaining,
    '@total' => $total,
  );
  if (empty($form_state['input'])) {
    drupal_set_message(t('@remaining/@total article versions have the associated eif json cached.', $args));
  }

  $form['flush_all'] = array(
    '#type' => 'checkbox',
    '#title' => t('Flush all stored eif json'),
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
function elife_article_eif_json_prepopulate_form_submit($form, &$form_state) {
  $force_empty = FALSE;
  if (!empty($form_state['values']['flush_all'])) {
    $force_empty = TRUE;
  }
  batch_set(elife_article_eif_json_prepopulate_process($force_empty));
}

/**
 * Process a batch of EIF Json populations.
 *
 * @param bool $force_empty
 *
 * @return array
 *   Array of batch instructions.
 */
function elife_article_eif_json_prepopulate_process($force_empty = FALSE) {
  $emptys = _elife_article_empty_eif_json($force_empty);
  $operations = [];
  if (!empty($emptys)) {
    $per_batch = variable_get('elife_eif_json_pre_batch', 50);
    for ($i = 0; $i < count($emptys); $i += $per_batch) {
      $operations[] = array(
        'elife_article_eif_json_prepopulate_process_items',
        array(
          array_slice($emptys, $i, $per_batch, TRUE),
        ),
      );
    }
  }
  // Build the batch instructions.
  $batch = array(
    'title' => t('Transfer EIF Json to relevant field.'),
    'operations' => $operations,
    'finished' => 'elife_article_eif_json_prepopulate_process_finished',
    'file' => drupal_get_path('module', 'elife_article') . '/elife_article.admin.inc',
  );
  return $batch;
}

/**
 * Process the items in a batch of EIF Json populations.
 *
 * @param array $items
 * @param array $context
 */
function elife_article_eif_json_prepopulate_process_items($items, &$context) {
  $context['results'] = array_merge($context['results'], array_keys($items));
  array_merge($context['results'], array_keys($items));
  foreach ($items as $article_version_id => $item) {
    $entity = node_load($item['nid']);
    $dto = elife_article_version_to_dto($entity, TRUE);
  }
}

/**
 * Review the status of the process after a single batch run.
 *
 * @param $success
 * @param $results
 * @param $operations
 */
function elife_article_eif_json_prepopulate_process_finished($success, $results, $operations) {
  if ($success) {
    drupal_set_message(t('@count article version EIF Json have been stored.', array('@count' => count($results))));
  }
  else {
    // An error occurred.
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    drupal_set_message(t('An error occurred while processing @operation with arguments : @args', array('@operation' => $error_operation[0], '@args' => $error_operation[1][0]->cid)));
  }
}

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
function elife_article_assets_source_settings_form($form, &$form_state) {
  $form['source_assets'] = array(
    '#title' => t('Settings for the retrieval of Article Version assets'),
    '#type' => 'fieldset',
  );

  if (!empty(variable_get('elife_article_source_assets_base_path')) && !empty(variable_get('elife_article_source_assets_xml_file_pattern')) && !empty(variable_get('elife_article_source_assets_pdf_file_pattern'))) {
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
      $example_pdf_path = elife_article_version_source_pdf_path($node);
      $example_pdf_download_path = elife_article_version_source_pdf_path($node, TRUE);
      $form['source_assets']['elife_article_source_assets_xml_example'] = array(
        '#type' => 'item',
        '#title' => t('Example source xml path'),
        '#markup' => $example_xml_path,
      );
      $form['source_assets']['elife_article_source_assets_pdf_example'] = array(
        '#type' => 'item',
        '#title' => t('Example source pdf path'),
        '#markup' => $example_pdf_path,
      );
      $form['source_assets']['elife_article_source_assets_pdf_download_example'] = array(
        '#type' => 'item',
        '#title' => t('Example source pdf download path'),
        '#markup' => $example_pdf_download_path,
      );
    }
  }

  $form['source_assets']['elife_article_source_assets_base_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Source assets base path'),
    '#default_value' => variable_get('elife_article_source_assets_base_path'),
  );
  $form['source_assets']['elife_article_source_assets_xml_file_pattern'] = array(
    '#type' => 'textfield',
    '#title' => t('Source XML file pattern'),
    '#default_value' => variable_get('elife_article_source_assets_xml_file_pattern'),
  );
  $form['source_assets']['elife_article_source_assets_pdf_file_pattern'] = array(
    '#type' => 'textfield',
    '#title' => t('Source PDF file pattern'),
    '#default_value' => variable_get('elife_article_source_assets_pdf_file_pattern'),
  );

  $form['source_assets']['elife_article_source_assets_glencoe_api'] = array(
    '#type' => 'textfield',
    '#title' => t('Glencoe API'),
    '#default_value' => variable_get('elife_article_source_assets_glencoe_api'),
  );

  return system_settings_form($form);
}

/**
 * Settings form as implemented by hook_menu.
 */
function elife_article_resolve_duplicates_form($form, &$form_state) {
  $duplicates = elife_article_detect_duplicates();

  foreach ($duplicates as $type => $type_duplicates) {
    $nid_string = '';
    foreach ($type_duplicates as $article_id => $result) {
      $nid_string .= ',' . $result->nids;
    }

    $args = array(
      '@type' => $type,
      '@count' => substr_count($nid_string, ',') - count($type_duplicates),
      '@article_count' => count($type_duplicates),
    );
    if (empty($form_state['input'])) {
      drupal_set_message(t('@count duplicate @type node(s) detected, affecting @article_count article(s).', $args));
    }
  }

  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Resolve duplicates'),
  );

  if (empty($duplicates)) {
    $form['actions']['submit']['#disabled'] = TRUE;
    drupal_set_message(t('No duplicate elife_article or elife_article_reference nodes detected.'));
  }

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
function elife_article_resolve_duplicates_form_submit($form, &$form_state) {
  elife_article_resolve_duplicates();
  drupal_set_message(t('Duplicates have been successfully resolved.'));
}

function _elife_article_rewrite_latest_paths_unprocessed($filter = FALSE) {
  $query = db_select('url_alias', 'ua');
  $query->addField('ua', 'pid', 'alias_pid');
  $query->addField('ua', 'alias', 'old_alias');
  if (!$filter) {
    $query->addExpression('n.nid', 'source_nid');
    $query->innerJoin('node', 'n', "CONCAT('node/', n.nid) = ua.source AND n.status = 1");
    $query->innerJoin('field_data_field_elife_a_versions', 'ver', 'ver.field_elife_a_versions_target_id = n.nid');
    $query->condition('ver.delta', 0);
    $query->condition('ua.alias', '^content/[0-9]+/e[0-9]{5}v[0-9]+$', 'REGEXP');
  }
  else {
    $query->addExpression('SUBSTRING(ua.source, 6)', 'source_nid');
    $query->condition('ua.alias', $filter . '%', 'LIKE');
  }
  $query->orderBy('ua.alias');
  $results = $query->execute()->fetchAllAssoc('source_nid');

  return ($results) ? $results : [];
}

function _elife_article_rewrite_latest_paths_processed() {
  $query = db_select('url_alias', 'ua');
  $query->addField('ua', 'pid', 'alias_pid');
  $query->addField('ua', 'alias', 'old_alias');
  $query->addExpression('n.nid', 'source_nid');
  $query->innerJoin('node', 'n', "CONCAT('node/', n.nid) = ua.source AND n.status = 1");
  $query->innerJoin('field_data_field_elife_a_versions', 'ver', 'ver.field_elife_a_versions_target_id = n.nid');
  $query->condition('ver.delta', 0);
  $query->condition('ua.alias', '^content/[0-9]+/e[0-9]{5}$', 'REGEXP');
  $query->orderBy('ua.alias');
  $results = $query->execute()->fetchAllAssoc('source_nid');

  return ($results) ? $results : [];
}

/**
 * Settings form as implemented by hook_menu.
 */
function elife_article_rewrite_latest_paths_form($form, &$form_state) {
  $processed = _elife_article_rewrite_latest_paths_processed();
  $remaining = _elife_article_rewrite_latest_paths_unprocessed();
  $total = count($processed) + count($remaining);
  $unprocessed = $total - count($remaining);

  $args = array(
    '@unprocessed' => $unprocessed,
    '@total' => $total,
  );
  if (empty($form_state['input'])) {
    drupal_set_message(t('@unprocessed/@total article version paths have been processed to the new format.', $args));
  }

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
function elife_article_rewrite_latest_paths_form_submit($form, &$form_state) {
  batch_set(elife_article_rewrite_latest_paths_process());
}

/**
 * Process a batch of article version paths to the new format.
 *
 * @return array
 *   Array of batch instructions.
 */
function elife_article_rewrite_latest_paths_process() {
  $remaining = _elife_article_rewrite_latest_paths_unprocessed();
  $operations = [];
  if (!empty($remaining)) {
    $per_batch = variable_get('elife_rewrite_latest_paths_batch', 50);
    for ($i = 0; $i < count($remaining); $i += $per_batch) {
      $operations[] = array(
        'elife_article_rewrite_latest_paths_process_items',
        array(
          array_slice($remaining, $i, $per_batch, TRUE),
        ),
      );
    }
  }
  // Build the batch instructions.
  $batch = array(
    'title' => t('Process paths for latest article versions to the new format.'),
    'operations' => $operations,
    'finished' => 'elife_article_rewrite_latest_paths_process_finished',
    'file' => drupal_get_path('module', 'elife_article') . '/elife_article.admin.inc',
  );
  return $batch;
}

function elife_article_rewrite_redirects() {
  $query = db_select('redirect', 're');
  $query->addField('re', 'rid');
  $query->addField('re', 'source');
  $query->condition('re.source', '^content/[0-9]+/e[0-9]{5}(v[0-9]+)?(/[^\/]+){0,}$', 'REGEXP');
  $query->orderBy('re.source');
  $results = $query->execute()->fetchAllKeyed();

  return ($results) ? $results : [];
}

/**
 * Process the items in a batch of article version paths.
 *
 * @param array $items
 * @param array $context
 */
function elife_article_rewrite_latest_paths_process_items($items, &$context) {
  $context['results'] = array_merge($context['results'], array_keys($items));
  array_merge($context['results'], array_keys($items));
  foreach ($items as $item) {
    $next = _elife_article_rewrite_latest_paths_unprocessed($item->old_alias);
    foreach ($next as $next_path) {
      $path = path_load(['pid' => $next_path->alias_pid]);
      if ($new_path = preg_replace('/^(content\/[0-9]+\/e[0-9]{5})v[0-9]+(.*)$/', '$1$2', $path['alias'])) {
        $path['alias'] = $new_path;
        path_save($path);
      }
    }
  }
  $redirects = elife_article_rewrite_redirects();
  if (!empty($redirects)) {
    $rids = array_keys($redirects);
    redirect_delete_multiple($rids);
  }
}

/**
 * Review the status of the process after a single batch run.
 *
 * @param $success
 * @param $results
 * @param $operations
 */
function elife_article_rewrite_latest_paths_process_finished($success, $results, $operations) {
  if ($success) {
    drupal_set_message(t('@count article version paths have been processed.', array('@count' => count($results))));
  }
  else {
    // An error occurred.
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    drupal_set_message(t('An error occurred while processing @operation with arguments : @args', array('@operation' => $error_operation[0], '@args' => $error_operation[1][0]->cid)));
  }
}
