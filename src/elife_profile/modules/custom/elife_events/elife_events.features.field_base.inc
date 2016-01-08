<?php
/**
 * @file
 * elife_events.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function elife_events_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_elife_e_date'.
  $field_bases['field_elife_e_date'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_elife_e_date',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'date',
    'settings' => array(
      'cache_count' => 4,
      'cache_enabled' => 0,
      'granularity' => array(
        'day' => 'day',
        'hour' => 'hour',
        'minute' => 'minute',
        'month' => 'month',
        'second' => 0,
        'year' => 'year',
      ),
      'timezone_db' => 'UTC',
      'todate' => 'optional',
      'tz_handling' => 'date',
    ),
    'translatable' => 0,
    'type' => 'date',
  );

  // Exported field_base: 'field_elife_e_text'.
  $field_bases['field_elife_e_text'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_elife_e_text',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_with_summary',
  );

  return $field_bases;
}
