<?php
/**
 * @file
 * elife_hero_block.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function elife_hero_block_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_elife_cta|node|elife_hero_block|form';
  $field_group->group_name = 'group_elife_cta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'elife_hero_block';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Call to action',
    'weight' => '2',
    'children' => array(
      0 => 'field_elife_cta_link',
      1 => 'field_elife_cta_text',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Call to action',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_elife_cta|node|elife_hero_block|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_elife_h_cc|node|elife_hero_block|form';
  $field_group->group_name = 'group_elife_h_cc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'elife_hero_block';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content column',
    'weight' => '3',
    'children' => array(
      0 => 'field_elife_cc',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Content column',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_elife_h_cc|node|elife_hero_block|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_elife_h_image|node|elife_hero_block|form';
  $field_group->group_name = 'group_elife_h_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'elife_hero_block';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image',
    'weight' => '1',
    'children' => array(
      0 => 'field_elife_h_credit',
      1 => 'field_elife_h_image',
      2 => 'field_elife_h_image_colour',
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
  $export['group_elife_h_image|node|elife_hero_block|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_elife_h_text|node|elife_hero_block|form';
  $field_group->group_name = 'group_elife_h_text';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'elife_hero_block';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Text',
    'weight' => '4',
    'children' => array(
      0 => 'field_elife_h_text',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Text',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_elife_h_text|node|elife_hero_block|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_elife_h_title|node|elife_hero_block|form';
  $field_group->group_name = 'group_elife_h_title';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'elife_hero_block';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Title',
    'weight' => '0',
    'children' => array(
      0 => 'field_elife_h_sub_title',
      1 => 'field_elife_h_path',
      2 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Title',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_elife_h_title|node|elife_hero_block|form'] = $field_group;

  return $export;
}
