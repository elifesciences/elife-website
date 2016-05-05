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
  $items['elife-eif-import'] = array(
    'bootstrap' => DRUSH_BOOTSTRAP_MAX,
    'drupal_dependencies' => array('elife_article'),
    'description' => 'Stores EIF Json for articles.',
    'options' => array(
      'flush' => '1 (default) or 0. Flush existing values from table.',
    ),
    'callback' => 'drush_elife_article_eif_json_import',
    'aliases' => array('elife-ei'),
  );
  // admin/config/search/elife-rewrite-latest-paths
  $items['elife-rewrite-paths'] = array(
    'bootstrap' => DRUSH_BOOTSTRAP_MAX,
    'drupal_dependencies' => array('elife_article'),
    'description' => 'Rewrite paths from old to new format.',
    'callback' => 'drush_elife_article_rewrite_latest_paths',
    'aliases' => array('elife-rp'),
  );

  return $items;
}

/**
 * Import the EIF Json for the article versions in the system.
 */
function drush_elife_article_eif_json_import() {
  $flush = drush_get_option('flush');
  if (empty($flush) && $flush !== 0) {
    $flush = 1;
  }

  module_load_include('inc', 'elife_article', 'elife_article.admin');

  $form = array();
  $form_state = array();
  $form_state['values']['flush_all'] = $flush;

  elife_article_eif_json_prepopulate_form_submit($form, $form_state);
  $batch =& batch_get();
  $batch['progressive'] = FALSE;

  // Process the batch.
  drush_backend_batch_process();
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

/**
 * IRewrite paths of latest article versions from old to new format.
 */
function drush_elife_article_rewrite_latest_paths() {
  module_load_include('inc', 'elife_article', 'elife_article.admin');

  $form = array();
  $form_state = array();

  elife_article_rewrite_latest_paths_form_submit($form, $form_state);
  $batch =& batch_get();
  $batch['progressive'] = FALSE;

  // Process the batch.
  drush_backend_batch_process();
}
