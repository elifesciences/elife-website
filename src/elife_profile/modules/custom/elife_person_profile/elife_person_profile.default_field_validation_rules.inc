<?php
/**
 * @file
 * elife_person_profile.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function elife_person_profile_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Embed HTTPS only';
  $rule->name = 'elife_pp_interest_https';
  $rule->field_name = 'field_elife_pp_interest';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'elife_person_profile';
  $rule->validator = 'field_validation_regex_validator';
  $rule->settings = array(
    'data' => '^((?!src=("|\')http://).)*$',
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      15 => 0,
      12 => 0,
      9 => 0,
    ),
    'errors' => 0,
    'condition' => 0,
    'condition_wrapper' => array(
      'condition_field' => '',
      'condition_operator' => 'equals',
      'condition_value' => '',
    ),
  );
  $rule->error_message = 'Embedded objects must be HTTPS';
  $export['elife_pp_interest_https'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'elife_pp_orcid_valid';
  $rule->name = 'elife_pp_orcid_valid';
  $rule->field_name = 'field_elife_pp_orcid';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'elife_person_profile';
  $rule->validator = 'field_validation_regex_validator';
  $rule->settings = array(
    'data' => '^[0-9]{4}-[0-9]{4}-[0-9]{4}-[0-9]{3}[0-9X]$',
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      15 => 0,
      12 => 0,
      9 => 0,
    ),
    'errors' => 0,
    'condition' => 0,
    'condition_wrapper' => array(
      'condition_field' => '',
      'condition_operator' => 'equals',
      'condition_value' => '',
    ),
  );
  $rule->error_message = 'Invalid ORCID';
  $export['elife_pp_orcid_valid'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Embed HTTPS only';
  $rule->name = 'elife_pp_profile_https';
  $rule->field_name = 'field_elife_pp_profile';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'elife_person_profile';
  $rule->validator = 'field_validation_regex_validator';
  $rule->settings = array(
    'data' => '^((?!src=("|\')http://).)*$',
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      15 => 0,
      12 => 0,
      9 => 0,
    ),
    'errors' => 0,
    'condition' => 0,
    'condition_wrapper' => array(
      'condition_field' => '',
      'condition_operator' => 'equals',
      'condition_value' => '',
    ),
  );
  $rule->error_message = 'Embedded objects must be HTTPS';
  $export['elife_pp_profile_https'] = $rule;

  return $export;
}
