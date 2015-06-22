<?php
/**
 * @file
 * elife_front_matter.features.inc
 */

/**
 * Implements hook_entityqueue_api().
 */
function elife_front_matter_entityqueue_api($module = NULL, $api = NULL) {
  if ($module == "entityqueue" && $api == "entityqueue_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_ctools_plugin_api().
 */
function elife_front_matter_ctools_plugin_api($module = NULL, $api = NULL) {
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
function elife_front_matter_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function elife_front_matter_image_default_styles() {
  $styles = array();

  // Exported image style: elife_cover.
  $styles['elife_cover'] = array(
    'effects' => array(
      2 => array(
        'name' => 'coloractions_convert',
        'data' => array(
          'format' => 'image/jpeg',
          'quality' => 100,
        ),
        'weight' => -10,
      ),
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1200,
          'height' => 600,
        ),
        'weight' => -9,
      ),
    ),
    'label' => 'elife_cover',
  );

  // Exported image style: elife_cover_mcr.
  $styles['elife_cover_mcr'] = array(
    'effects' => array(
      1 => array(
        'name' => 'coloractions_convert',
        'data' => array(
          'format' => 'image/jpeg',
          'quality' => 75,
        ),
        'weight' => 1,
      ),
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 400,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
      3 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 400,
          'height' => 200,
          'anchor' => 'left-center',
        ),
        'weight' => 3,
      ),
    ),
    'label' => 'elife_cover_mcr',
  );

  // Exported image style: elife_cover_sml.
  $styles['elife_cover_sml'] = array(
    'effects' => array(
      5 => array(
        'name' => 'coloractions_convert',
        'data' => array(
          'format' => 'image/jpeg',
          'quality' => 75,
        ),
        'weight' => 1,
      ),
      6 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 880,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
      7 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 880,
          'height' => 260,
          'anchor' => 'left-center',
        ),
        'weight' => 3,
      ),
    ),
    'label' => 'elife_cover_sml',
  );

  // Exported image style: elife_front_matter.
  $styles['elife_front_matter'] = array(
    'effects' => array(
      2 => array(
        'name' => 'coloractions_convert',
        'data' => array(
          'format' => 'image/jpeg',
          'quality' => 100,
        ),
        'weight' => -10,
      ),
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 240,
          'height' => 134,
        ),
        'weight' => -9,
      ),
    ),
    'label' => 'elife_front_matter',
  );

  return $styles;
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
    'elife_front_matter' => array(
      'name' => t('eLife Front Matter'),
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
