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
    !empty($conf['custom_6']) ? $conf['custom_6'] : NULL,
    !empty($conf['gid']) ? $conf['gid'] : NULL
  );
  $block->content = drupal_render($sign_up_form);
  return $block;
}

/**
 * Edit form callback for the content type.
 */
function elife_content_alerts_sign_up_edit($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['gid'] = array(
    '#type' => 'textfield',
    '#title' => t('gid'),
    '#description' => t('If left blank the gid :gid will be used', array(':id' => elife_content_alerts_sign_up_gid(FALSE))),
    '#default_value' => $conf['gid'],
  );

  $form['custom_6'] = array(
    '#type' => 'textfield',
    '#title' => t('Sign up ID'),
    '#description' => t('If left blank the id :id will be used', array(':id' => elife_content_alerts_sign_up_id(FALSE))),
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
