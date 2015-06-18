<?php

/**
 * @file
 * Contains Batch API callbacks used during installation.
 */

/**
 * BatchAPI callback.
 *
 * @see elife_profile_install_additional_modules()
 */
function _elife_profile_enable_theme($theme, &$context) {
  theme_enable(array($theme));
  variable_set('theme_default', $theme);

  $context['message'] = st('Installed the default theme.');
}

/**
 * BatchAPI callback.
 *
 * @see elife_profile_install_additional_modules()
 */
function _elife_profile_enable_module($module, $module_name, &$context) {
  module_enable(array($module), FALSE);
  $context['message'] = st('Installed %module module.', array('%module' => $module_name));
}

/**
 * BatchAPI callback.
 *
 * @see elife_profile_install_additional_modules()
 */
function _elife_profile_flush_caches($operation, &$context) {
  $context['message'] = t('@operation', array('@operation' => $operation));
  drupal_flush_all_caches();
}

/**
 * BatchAPI callback.
 *
 * @see elife_profile_import_content()
 */
function _elife_profile_taxonomy_menu($operation, &$context) {
  $context['message'] = t('@operation', array('@operation' => $operation));


  // Set up taxonomy main menu.
  $vocabulary_machine_name = variable_get('elife_profile_demo_store', FALSE) ? 'collection' : 'product_category';
  if ($collection = taxonomy_vocabulary_machine_name_load($vocabulary_machine_name)) {
    $variable_name = _taxonomy_menu_build_variable('vocab_menu', $collection->vid);
    variable_set($variable_name, 'main-menu');
    $variable_name = _taxonomy_menu_build_variable('vocab_parent', $collection->vid);
    variable_set($variable_name, '0');
    $variable_name = _taxonomy_menu_build_variable('path', $collection->vid);
    variable_set($variable_name, 'elife_profile_taxonomy_term_path');
    $variable_name = _taxonomy_menu_build_variable('rebuild', $collection->vid);
    variable_set($variable_name, 1);
  }
}

/**
 * BatchAPI callback.
 *
 * @see elife_profile_import_content()
 */
function _elife_profile_import($operation, $type, &$context) {
  $context['message'] = t('@operation', array('@operation' => $type));
  $migration =  Migration::getInstance($operation);
  $migration->processImport();
}

/**
 * BatchAPI callback.
 *
 * @see elife_profile_import_content()
 */
function _elife_profile_post_import($operation, &$context) {
  $context['message'] = t('@operation', array('@operation' => $operation));

  _elife_profile_setup_blocks();
  _elife_profile_setup_crumbs();
}

/**
 * Configures the theme and assign blocks to the appropriate regions.
 */
function _elife_profile_setup_blocks() {
  $admin_theme = variable_get('admin_theme', 'seven');
  $default_theme = variable_get('theme_default', 'bartik');

  $blocks = array(
    array(
      'module' => 'system',
      'delta' => 'help',
      'theme' => $admin_theme,
      'status' => 1,
      'weight' => 0,
      'region' => 'help',
      'pages' => '',
      'cache' => DRUPAL_NO_CACHE,
    ),
    array(
      'module' => 'system',
      'delta' => 'main',
      'theme' => $default_theme,
      'status' => 1,
      'weight' => 0,
      'region' => 'content',
      'pages' => '<front>', // Do not show the block on front.
      'visibility' => 0,
      'cache' => DRUPAL_NO_CACHE,
    ),
    // Connector.
    array(
      'module' => 'connector',
      'delta' => 'one_click_block',
      'theme' => $default_theme,
      'status' => 1,
      'weight' => 1,
      'region' => 'content',
      'pages' => "user\r\nuser/login",
      'visibility' => BLOCK_VISIBILITY_LISTED,
      'cache' => DRUPAL_NO_CACHE,
    ),
    // Search sorting.
    array(
      'module' => 'search_api_sorts',
      'delta' => 'search-sorts',
      'theme' => $default_theme,
      'status' => 1,
      'weight' => -30,
      'region' => 'content',
      'pages' => 'products',
      'visibility' => BLOCK_VISIBILITY_LISTED,
      'cache' => DRUPAL_NO_CACHE,
    ),
  );

  drupal_static_reset();
  _block_rehash($admin_theme);
  _block_rehash($default_theme);
  foreach ($blocks as $record) {
    $module = array_shift($record);
    $delta = array_shift($record);
    $theme = array_shift($record);
    db_update('block')
      ->fields($record)
      ->condition('module', $module)
      ->condition('delta', $delta)
      ->condition('theme', $theme)
      ->execute();
  }
}

/**
 * Configures the Crumbs module and enables the required plugins.
 */
function _elife_profile_setup_crumbs() {
  variable_set('crumbs_show_current_page', TRUE);
  variable_set('crumbs_weights', elife_profile_crumbs_get_info());
}
