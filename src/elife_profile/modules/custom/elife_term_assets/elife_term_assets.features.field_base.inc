<?php
/**
 * @file
 * elife_term_assets.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function elife_term_assets_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_elife_ta_term'
  $field_bases['field_elife_ta_term'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_elife_ta_term',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
