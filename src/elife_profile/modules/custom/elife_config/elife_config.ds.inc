<?php
/**
 * @file
 * elife_config.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function elife_config_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'elife_teaser_alternative';
  $ds_view_mode->label = 'Alternative teaser';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['elife_teaser_alternative'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'elife_teaser_compact';
  $ds_view_mode->label = 'Compact teaser';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['elife_teaser_compact'] = $ds_view_mode;

  return $export;
}
