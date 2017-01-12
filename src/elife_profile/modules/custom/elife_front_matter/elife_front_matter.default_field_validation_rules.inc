<?php
/**
 * @file
 * elife_front_matter.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function elife_front_matter_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'field_elife_c_uri';
  $rule->name = 'field_elife_fm_reference_uri';
  $rule->field_name = 'field_elife_fm_reference';
  $rule->col = 'target_id';
  $rule->entity_type = 'node';
  $rule->bundle = 'elife_cover';
  $rule->validator = 'field_validation_oneofseveral_validator';
  $rule->settings = array(
    'data' => 'field_elife_c_uri',
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      5 => 0,
      4 => 0,
      3 => 0,
    ),
    'errors' => 0,
    'condition' => 0,
    'condition_wrapper' => array(
      'condition_field' => '',
      'condition_operator' => 'equals',
      'condition_value' => '',
    ),
  );
  $rule->error_message = 'At least one value must be set';
  $export['field_elife_fm_reference_uri'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'field_elife_fm_reference_uri';
  $rule->name = 'field_elife_fm_reference_uri_fm';
  $rule->field_name = 'field_elife_fm_reference';
  $rule->col = 'target_id';
  $rule->entity_type = 'node';
  $rule->bundle = 'elife_front_matter';
  $rule->validator = 'field_validation_oneofseveral_validator';
  $rule->settings = array(
    'data' => 'field_elife_fm_uri',
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      5 => 0,
      4 => 0,
      3 => 0,
    ),
    'errors' => 0,
    'condition' => 0,
    'condition_wrapper' => array(
      'condition_field' => '',
      'condition_operator' => 'equals',
      'condition_value' => '',
    ),
  );
  $rule->error_message = 'At least one value must be set';
  $export['field_elife_fm_reference_uri_fm'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'field_elife_fm_uri';
  $rule->name = 'field_elife_fm_uri';
  $rule->field_name = 'field_elife_fm_uri';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'elife_front_matter';
  $rule->validator = 'field_validation_oneofseveral_validator';
  $rule->settings = array(
    'data' => 'field_elife_fm_uri',
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      5 => 0,
      4 => 0,
      3 => 0,
    ),
    'errors' => 0,
    'condition' => 0,
    'condition_wrapper' => array(
      'condition_field' => '',
      'condition_operator' => 'equals',
      'condition_value' => '',
    ),
  );
  $rule->error_message = 'At least one value must be set';
  $export['field_elife_fm_uri'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'field_elife_fm_uri_uri';
  $rule->name = 'field_elife_fm_uri_uri';
  $rule->field_name = 'field_elife_fm_uri';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'elife_cover';
  $rule->validator = 'field_validation_oneofseveral_validator';
  $rule->settings = array(
    'data' => 'field_elife_c_uri',
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      5 => 0,
      4 => 0,
      3 => 0,
    ),
    'errors' => 0,
    'condition' => 0,
    'condition_wrapper' => array(
      'condition_field' => '',
      'condition_operator' => 'equals',
      'condition_value' => '',
    ),
  );
  $rule->error_message = 'At least one value must be set';
  $export['field_elife_fm_uri_uri'] = $rule;

  return $export;
}
