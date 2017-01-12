<?php
/**
 * @file
 * elife_front_matter.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function elife_front_matter_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_elife_fm_link|node|elife_cover|form';
  $field_group->group_name = 'group_elife_fm_link';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'elife_cover';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Link',
    'weight' => '4',
    'children' => array(
      0 => 'field_elife_fm_reference',
      1 => 'field_elife_fm_uri',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Link',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_elife_fm_link|node|elife_front_matter|form';
  $field_group->group_name = 'group_elife_fm_link';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'elife_front_matter';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Link',
    'weight' => '2',
    'children' => array(
      0 => 'field_elife_fm_reference',
      1 => 'field_elife_fm_uri',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Link',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Link');

  return $field_groups;
}
