<?php
/**
 * @file
 * elife_labs.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function elife_labs_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function elife_labs_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function elife_labs_image_default_styles() {
  $styles = array();

  // Exported image style: elife_labs_tile.
  $styles['elife_labs_tile'] = array(
    'label' => 'eLife Labs Tile',
    'effects' => array(
      1 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 240,
          'height' => 140,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function elife_labs_node_info() {
  $items = array(
    'elife_labs_entry' => array(
      'name' => t('eLife Labs Entry'),
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
