<?php
/**
 * @file
 * plugins/content_types/elife_front_matter_action.inc
 */

$plugin = [
  'title' => t('Home - Action Message'),
  'single' => TRUE,
  'category' => ['eLife'],
  'edit form' => 'elife_front_matter_action_edit',
  'render callback' => 'elife_front_matter_action_render',
];

/**
 * Run-time rendering of the body of the block (content type).
 *
 * @see ctools_plugin_examples()
 */
function elife_front_matter_action_render($subtype, $conf, $args, $context) {
  $block = new stdClass();

  $variables = [];
  $variables['imagealt'] = t('Randy Schekman Editor-in-Chief, Nobel Prize winner 2013');
  $variables['title'] = t('Early in your career?');
  $variables['choosetopic'] = t('Sign up');
  $variables['address'] = t('Email address');
  $variables['getelife_text'] = t('Stay at the forefront of your field with updates on new papers from <i>eLife</i>.');
  $variables['getelife_title'] = t('Get <i>eLife</i> by email');
  $variables['caption'] = t('eLife editors want early-career scientists to thrive – to receive clear and constructive input on papers, quick decisions, and great exposure. In addition to pain-free peer review, we offer early-career scientists a letter of recommendation from one of our senior editors.');
  $variables['read_more'] = t('Read more about publishing with <i>eLife</i>');
  $sign_up_form = drupal_get_form('elife_content_alerts_sign_up_form', 'homepage_rev140402');
  $variables['sign_up_form'] = drupal_render($sign_up_form);

  $block->content = theme('elife_front_matter_action', $variables);

  return $block;
}

/**
 * Edit form callback for the content type.
 */
function elife_front_matter_action_edit($form, &$form_state) {
  return $form;
}

/**
 * Edit form callback for the content type.
 */
function elife_front_matter_action_edit_form_submit(&$form, &$form_state) {
  // Nothing.
}
