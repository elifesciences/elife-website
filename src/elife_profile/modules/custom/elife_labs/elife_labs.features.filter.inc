<?php
/**
 * @file
 * elife_labs.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function elife_labs_filter_default_formats() {
  $formats = array();

  // Exported format: eLife Labs Tile.
  $formats['elife_labs_tile'] = array(
    'format' => 'elife_labs_tile',
    'name' => 'eLife Labs Tile',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'pathologic' => array(
        'weight' => 50,
        'status' => 1,
        'settings' => array(
          'settings_source' => 'global',
          'local_paths' => '',
          'protocol_style' => 'full',
          'local_settings' => array(
            'protocol_style' => 'full',
            'local_paths' => '',
          ),
        ),
      ),
    ),
  );

  return $formats;
}
