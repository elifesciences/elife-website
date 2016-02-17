<?php
/**
 * @file
 * elife_collection.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function elife_collection_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'display_cache_node_elife_collection_elife_teaser_compact';
  $strongarm->value = array(
    'default' => array(
      'use' => '1',
      'page_granularity' => '0',
      'user_granularity' => '1',
      'granularity' => '1',
    ),
  );
  $export['display_cache_node_elife_collection_elife_teaser_compact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'display_cache_node_elife_collection_teaser';
  $strongarm->value = array(
    'default' => array(
      'use' => '1',
      'page_granularity' => '0',
      'user_granularity' => '1',
      'granularity' => '1',
    ),
    'field_elife_c_image' => array(
      'override' => '2',
      'page_granularity' => '0',
      'user_granularity' => '1',
      'granularity' => '1',
    ),
    'field_elife_c_text' => array(
      'override' => '2',
      'page_granularity' => '0',
      'user_granularity' => '1',
      'granularity' => '1',
    ),
  );
  $export['display_cache_node_elife_collection_teaser'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__elife_collection';
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
      'elife_teaser_compact' => array(
        'custom_settings' => TRUE,
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
          'weight' => '50',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '49',
        ),
        'redirect' => array(
          'weight' => '48',
        ),
        'rabbit_hole' => array(
          'weight' => '47',
        ),
      ),
      'display' => array(
        'sharethis' => array(
          'teaser' => array(
            'weight' => '18',
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
  $export['field_bundle_settings_node__elife_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_elife_collection';
  $strongarm->value = array();
  $export['menu_options_elife_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_elife_collection';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_elife_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_elife_collection';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_elife_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_elife_collection';
  $strongarm->value = '1';
  $export['node_preview_elife_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_elife_collection';
  $strongarm->value = 0;
  $export['node_submitted_elife_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_elife_collection_pattern';
  $strongarm->value = 'collections/[node:field-elife-c-title:value]';
  $export['pathauto_node_elife_collection_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_elife_collection';
  $strongarm->value = array(
    'status' => '1',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_elife_collection'] = $strongarm;

  return $export;
}
