<?php
/**
 * @file
 * elife_collection.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function elife_collection_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_c_details|node|elife_collection|form';
  $field_group->group_name = 'group_c_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'elife_collection';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '1',
    'children' => array(
      0 => 'field_elife_c_curators',
      1 => 'field_elife_c_sub_title',
      2 => 'field_elife_c_text',
      3 => 'field_elife_c_title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_c_details|node|elife_collection|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_elife_c_content|node|elife_collection|form';
  $field_group->group_name = 'group_elife_c_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'elife_collection';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '3',
    'children' => array(
      0 => 'field_elife_c_articles',
      1 => 'field_elife_c_podcast',
      2 => 'field_elife_c_related',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Content',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_elife_c_content|node|elife_collection|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_elife_c_image|node|elife_collection|form';
  $field_group->group_name = 'group_elife_c_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'elife_collection';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image',
    'weight' => '2',
    'children' => array(
      0 => 'field_elife_c_image_credit',
      1 => 'field_elife_c_image',
      2 => 'field_elife_c_image_colour',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Image',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_elife_c_image|node|elife_collection|form'] = $field_group;

  return $export;
}
