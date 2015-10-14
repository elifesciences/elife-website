<?php

$plugin = array(
  'title' => t('eLife - Lens Icon'),
  'single' => TRUE,
  'category' => array('eLife'),
  'edit form' => 'elife_lens_icon_edit_form',
  'render callback' => 'elife_lens_icon_render',
  'admin info' => 'elife_lens_icon_admin_info',
  'required context' => new ctools_context_required('Article Node', 'node'),
);

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function elife_lens_icon_render($subtype, $conf, $args, $context) {
  /* @var EntityDrupalWrapper $ewrapper */
  $ewrapper = entity_metadata_wrapper('node', $context->data);
  $article_id = $ewrapper->field_elife_a_article_id->value();
  $article_id = _elife_article_process_article_id($article_id);
  $url = $conf['lens_url'] . '/' . $article_id . '/index.html';
  $image_path = drupal_get_path('module', 'elife_templates') .
    '/images/lens.png';
  $variables = array(
    'path' => $image_path,
    'alt' => t('View in eLife Lens'),
    'title' => t('View in eLife Lens'),
  );
  $image = theme('image', $variables);
  $block = new stdClass();
  if ($ewrapper->field_elife_a_status->value() == 'VOR') {
    $block->content = l($image, $url, array('html' => TRUE));
  }
  return $block;
}


/**
 * Edit form callback for the content type.
 */
function elife_lens_icon_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['lens_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Lens Url'),
    '#default_value' => !empty($conf['lens_url']) ? $conf['lens_url'] : variable_get('lens_url', 'http://lens.elifesciences.org'),
    '#prefix' => '<div class="clear-block no-float">',
    '#suffix' => '</div>',
  );
  return $form;
}

/**
 * 'Edit form' callback for the content type.
 */
function elife_lens_icon_edit_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (!empty($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

function elife_lens_icon_admin_info($subtype, $conf, $context) {
  $output = new stdClass();
  $output->title = 'Article - Lens Icon';
  $output->content = '';
  return $output;
}
