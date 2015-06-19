<?php
/**
 * @file
 * elife_front_matter.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function elife_front_matter_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function elife_front_matter_node_info() {
  $items = array(
    'elife_cover' => array(
      'name' => t('eLife Cover'),
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
