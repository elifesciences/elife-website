<?php
/**
 * @file
 * elife_hero_block.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function elife_hero_block_image_default_styles() {
  $styles = array();

  // Exported image style: elife_hero_block.
  $styles['elife_hero_block'] = array(
    'label' => 'eLife Hero Block',
    'effects' => array(
      1 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 1200,
          'height' => 400,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: elife_hero_block_teaser.
  $styles['elife_hero_block_teaser'] = array(
    'label' => 'eLife Hero Block Teaser',
    'effects' => array(
      1 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 150,
          'height' => 150,
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
