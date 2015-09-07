<?php
/**
 * @file
 * elife_collection.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function elife_collection_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-elife_collection-field_elife_c_keyword'
  $field_instances['node-elife_collection-field_elife_c_keyword'] = array(
    'bundle' => 'elife_collection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_elife_c_keyword',
    'label' => 'Keyword',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Keyword');

  return $field_instances;
}
