<?php
/**
 * @file
 * elife_annual_reports.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function elife_annual_reports_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_elief_ar_url|node|elife_annual_report|form';
  $field_group->group_name = 'group_elief_ar_url';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'elife_annual_report';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'URLs',
    'weight' => '10',
    'children' => array(
      0 => 'field_elife_ar_url_web',
      1 => 'field_elife_ar_url_pdf',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-elief-ar-url field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_elief_ar_url|node|elife_annual_report|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('URLs');

  return $field_groups;
}
