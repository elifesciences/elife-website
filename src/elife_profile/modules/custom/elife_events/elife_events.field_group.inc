<?php
/**
 * @file
 * elife_events.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function elife_events_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_elife_e_details|node|elife_event|form';
  $field_group->group_name = 'group_elife_e_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'elife_event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '0',
    'children' => array(
      0 => 'field_elife_title',
      1 => 'field_elife_e_date',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-elife-e-details field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_elife_e_details|node|elife_event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_elife_e_text|node|elife_event|form';
  $field_group->group_name = 'group_elife_e_text';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'elife_event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Text',
    'weight' => '1',
    'children' => array(
      0 => 'field_elife_e_text',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-elife-e-text field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_elife_e_text|node|elife_event|form'] = $field_group;

  return $export;
}
