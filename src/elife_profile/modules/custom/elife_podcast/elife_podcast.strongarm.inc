<?php
/**
 * @file
 * elife_podcast.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function elife_podcast_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__elife_podcast';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'elife_teaser_compact' => array(
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
      'revision' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '6',
        ),
        'title' => array(
          'weight' => '1',
        ),
        'path' => array(
          'weight' => '5',
        ),
        'redirect' => array(
          'weight' => '4',
        ),
        'rabbit_hole' => array(
          'weight' => '0',
        ),
      ),
      'display' => array(
        'sharethis' => array(
          'default' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'elife_teaser_compact' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__elife_podcast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_elife_podcast';
  $strongarm->value = array();
  $export['menu_options_elife_podcast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_elife_podcast';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_elife_podcast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_elife_podcast';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_elife_podcast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_elife_podcast';
  $strongarm->value = '1';
  $export['node_preview_elife_podcast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_elife_podcast';
  $strongarm->value = 0;
  $export['node_submitted_elife_podcast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_elife_podcast_pattern';
  $strongarm->value = 'content/[node:title]';
  $export['pathauto_node_elife_podcast_pattern'] = $strongarm;

  return $export;
}
