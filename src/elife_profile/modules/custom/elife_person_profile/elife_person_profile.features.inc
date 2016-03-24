<?php
/**
 * @file
 * elife_person_profile.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function elife_person_profile_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "field_validation" && $api == "default_field_validation_rules") {
    return array("version" => "2");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function elife_person_profile_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function elife_person_profile_image_default_styles() {
  $styles = array();

  // Exported image style: elife_person_profile.
  $styles['elife_person_profile'] = array(
    'label' => 'eLife person profile',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 200,
          'height' => 134,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: elife_person_square.
  $styles['elife_person_square'] = array(
    'label' => 'eLife person square',
    'effects' => array(
      1 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 75,
          'height' => 75,
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
function elife_person_profile_node_info() {
  $items = array(
    'elife_person_profile' => array(
      'name' => t('eLife Person Profile'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
