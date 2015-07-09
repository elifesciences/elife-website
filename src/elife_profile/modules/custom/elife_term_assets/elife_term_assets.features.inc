<?php
/**
 * @file
 * elife_term_assets.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function elife_term_assets_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function elife_term_assets_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function elife_term_assets_node_info() {
  $items = array(
    'elife_term_assets' => array(
      'name' => t('eLife Term Assets'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
