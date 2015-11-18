<?php
/**
 * @file
 * elife_podcast.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function elife_podcast_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_elife_p_chapters|node|elife_podcast|form';
  $field_group->group_name = 'group_elife_p_chapters';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'elife_podcast';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Chapters',
    'weight' => '2',
    'children' => array(
      0 => 'field_elife_p_chapters',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-elife-p-chapters field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_elife_p_chapters|node|elife_podcast|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_elife_p_details|node|elife_podcast|form';
  $field_group->group_name = 'group_elife_p_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'elife_podcast';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '1',
    'children' => array(
      0 => 'field_elife_p_episode_number',
      1 => 'field_elife_p_title',
      2 => 'field_elife_p_url',
      3 => 'field_elife_p_image',
      4 => 'field_elife_p_text',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-elife-p-details field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_elife_p_details|node|elife_podcast|form'] = $field_group;

  return $export;
}
