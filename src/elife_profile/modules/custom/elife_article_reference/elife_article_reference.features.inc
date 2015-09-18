<?php
/**
 * @file
 * elife_article_reference.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function elife_article_reference_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function elife_article_reference_image_default_styles() {
  $styles = array();

  // Exported image style: elife_striking_image.
  $styles['elife_striking_image'] = array(
    'label' => 'elife_striking_image',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 60,
          'height' => 60,
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
function elife_article_reference_node_info() {
  $items = array(
    'elife_article_reference' => array(
      'name' => t('eLife Article Reference'),
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
