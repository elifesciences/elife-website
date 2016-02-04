<?php
/**
 * @file
 * elife_labs.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function elife_labs_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__elife_labs_entry';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '50',
        ),
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '49',
        ),
        'rabbit_hole' => array(
          'weight' => '47',
        ),
        'redirect' => array(
          'weight' => '48',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__elife_labs_entry'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_elife_labs_entry';
  $strongarm->value = array();
  $export['menu_options_elife_labs_entry'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_elife_labs_entry';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_elife_labs_entry'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_elife_labs_entry';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_elife_labs_entry'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_elife_labs_entry';
  $strongarm->value = '1';
  $export['node_preview_elife_labs_entry'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_elife_labs_entry';
  $strongarm->value = 0;
  $export['node_submitted_elife_labs_entry'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_elife_labs_entry_pattern';
  $strongarm->value = '';
  $export['pathauto_node_elife_labs_entry_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_module_elife_labs_entry';
  $strongarm->value = 'rh_node';
  $export['rh_module_elife_labs_entry'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_node_action_elife_labs_entry';
  $strongarm->value = '2';
  $export['rh_node_action_elife_labs_entry'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_elife_labs_entry';
  $strongarm->value = array(
    'status' => '0',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_elife_labs_entry'] = $strongarm;

  return $export;
}
