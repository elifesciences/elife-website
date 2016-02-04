<?php
/**
 * @file
 * elife_annual_reports.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function elife_annual_reports_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_node_elife_annual_report';
  $strongarm->value = '1';
  $export['auto_entitylabel_node_elife_annual_report'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_pattern_node_elife_annual_report';
  $strongarm->value = 'The eLife Sciences [node:field-elife-ar-year] Annual Report';
  $export['auto_entitylabel_pattern_node_elife_annual_report'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_php_node_elife_annual_report';
  $strongarm->value = 0;
  $export['auto_entitylabel_php_node_elife_annual_report'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__elife_annual_report';
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
          'weight' => '48',
        ),
        'rabbit_hole' => array(
          'weight' => '47',
        ),
        'redirect' => array(
          'weight' => '49',
        ),
      ),
      'display' => array(
        'sharethis' => array(
          'teaser' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__elife_annual_report'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_elife_annual_report';
  $strongarm->value = array();
  $export['menu_options_elife_annual_report'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_elife_annual_report';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_elife_annual_report'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_elife_annual_report';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_elife_annual_report'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_elife_annual_report';
  $strongarm->value = '1';
  $export['node_preview_elife_annual_report'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_elife_annual_report';
  $strongarm->value = 0;
  $export['node_submitted_elife_annual_report'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_elife_annual_report_pattern';
  $strongarm->value = '';
  $export['pathauto_node_elife_annual_report_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_module_elife_annual_report';
  $strongarm->value = 'rh_node';
  $export['rh_module_elife_annual_report'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_node_action_elife_annual_report';
  $strongarm->value = '2';
  $export['rh_node_action_elife_annual_report'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_elife_annual_report';
  $strongarm->value = array(
    'status' => '0',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_elife_annual_report'] = $strongarm;

  return $export;
}
