<?php
/**
 * @file
 * plugins/content_types/elife_content_alerts_sign_up.inc
 */

$plugin = array(
  'title' => t('eLife - Sign-up for news and updates'),
  'single' => TRUE,
  'category' => array('eLife'),
  'edit form' => 'elife_content_alerts_sign_up_edit',
  'render callback' => 'elife_content_alerts_sign_up_render',
  'all contexts' => TRUE,
);

/**
 * Run-time rendering of the body of the block (content type).
 *
 * See ctools_plugin_examples for more advanced info
 */
function elife_content_alerts_sign_up_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $sign_up_form = drupal_get_form(
    'elife_content_alerts_sign_up_form',
    !empty($conf['custom_6']) ? ctools_context_keyword_substitute($conf['custom_6'], [], $context) : NULL,
    !empty($conf['action']) ? ctools_context_keyword_substitute($conf['action'], [], $context) : NULL,
    !empty($conf['query']) ? ctools_context_keyword_substitute($conf['query'], [], $context) : NULL
  );
  $block->content = drupal_render($sign_up_form);
  return $block;
}

/**
 * Edit form callback for the content type.
 */
function elife_content_alerts_sign_up_edit($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['action'] = array(
    '#type' => 'textfield',
    '#title' => t('action'),
    '#description' => t('If left blank the action :action will be used', array(':action' => ELIFE_CONTENT_ALERT_DEFAULT_ACTION)),
    '#default_value' => $conf['action'],
  );

  $form['query'] = array(
    '#type' => 'textfield',
    '#title' => t('query'),
    '#default_value' => $conf['query'],
  );

  $form['custom_6'] = array(
    '#type' => 'textfield',
    '#title' => t('Sign up ID'),
    '#description' => t('If left blank the id :id will be used', array(':id' => ELIFE_CONTENT_ALERT_DEFAULT_ID)),
    '#default_value' => $conf['custom_6'],
  );

  return $form;
}

/**
 * Edit form callback for the content type.
 */
function elife_content_alerts_sign_up_edit_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}
