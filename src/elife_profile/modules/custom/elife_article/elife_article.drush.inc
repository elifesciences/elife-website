<?php

/**
 * @file
 * Drush integration for the elife_article module.
 */

/**
 * Implements hook_drush_command().
 */
function elife_article_drush_command() {
  $items['elife-markup-import'] = array(
    'bootstrap' => DRUSH_BOOTSTRAP_MAX,
    'drupal_dependencies' => array('elife_article'),
    'description' => 'Stores markup data for articles in fields and cache.',
    'options' => array(
      'flush' => '1 (default) or 0. Flush existing values from table.',
    ),
    'callback' => 'drush_elife_article_markup_import',
    'aliases' => array('elife-mi'),
  );

  return $items;
}

/**
 * Import the markup for the article versions in the system.
 */
function drush_elife_article_markup_import() {
  $flush = drush_get_option('flush');
  if (empty($flush) && $flush !== 0) {
    $flush = 1;
  }

  module_load_include('inc', 'elife_article', 'elife_article.admin');

  $form = array();
  $form_state = array();
  $form_state['values']['flush_all'] = $flush;

  elife_article_markup_prepopulate_form_submit($form, $form_state);
  $batch =& batch_get();
  $batch['progressive'] = FALSE;

  // Process the batch.
  drush_backend_batch_process();
}
