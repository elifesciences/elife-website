<?php
/**
 * @file
 * elife_early_careers_interviews.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function elife_early_careers_interviews_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__elife_early_careers_interview';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'elife_teaser_alternative' => array(
        'custom_settings' => FALSE,
      ),
      'elife_teaser_compact' => array(
        'custom_settings' => TRUE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '50',
        ),
        'title' => array(
          'weight' => '-10',
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
      'display' => array(
        'sharethis' => array(
          'default' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '15',
            'visible' => FALSE,
          ),
          'elife_teaser_compact' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__elife_early_careers_interview'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_elife_early_careers_interview';
  $strongarm->value = array();
  $export['menu_options_elife_early_careers_interview'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_elife_early_careers_interview';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_elife_early_careers_interview'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_elife_early_careers_interview';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_elife_early_careers_interview'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_elife_early_careers_interview';
  $strongarm->value = '1';
  $export['node_preview_elife_early_careers_interview'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_elife_early_careers_interview';
  $strongarm->value = 0;
  $export['node_submitted_elife_early_careers_interview'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_elife_early_careers_interview_pattern';
  $strongarm->value = 'early-careers-interviews/[node:field-elife-i-first-name]-[node:field-elife-i-last-name]';
  $export['pathauto_node_elife_early_careers_interview_pattern'] = $strongarm;

  return $export;
}
