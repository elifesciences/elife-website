<?php
/**
 * @file
 * elife_early_careers_interviews.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function elife_early_careers_interviews_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_elife_i_interviewee|node|elife_early_careers_interview|form';
  $field_group->group_name = 'group_elife_i_interviewee';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'elife_early_careers_interview';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Interviewee Details',
    'weight' => '0',
    'children' => array(
      0 => 'field_elife_i_cv',
      1 => 'group_elife_i_name',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Interviewee Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_elife_i_interviewee|node|elife_early_careers_interview|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_elife_i_interview|node|elife_early_careers_interview|form';
  $field_group->group_name = 'group_elife_i_interview';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'elife_early_careers_interview';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Interview',
    'weight' => '5',
    'children' => array(
      0 => 'field_elife_i_images',
      1 => 'field_elife_i_text',
      2 => 'field_elife_i_title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Interview',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_elife_i_interview|node|elife_early_careers_interview|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_elife_i_name|node|elife_early_careers_interview|form';
  $field_group->group_name = 'group_elife_i_name';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'elife_early_careers_interview';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_elife_i_interviewee';
  $field_group->data = array(
    'label' => 'Name',
    'weight' => '0',
    'children' => array(
      0 => 'field_elife_i_first_name',
      1 => 'field_elife_i_last_name',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Name',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_elife_i_name|node|elife_early_careers_interview|form'] = $field_group;

  return $export;
}
