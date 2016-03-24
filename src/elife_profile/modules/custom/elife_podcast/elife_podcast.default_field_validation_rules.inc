<?php
/**
 * @file
 * elife_podcast.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function elife_podcast_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Embed HTTPS only';
  $rule->name = 'elife_p_text_https';
  $rule->field_name = 'field_elife_p_text';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'elife_podcast';
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
  $export['elife_p_text_https'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Unique episode number';
  $rule->name = 'elife_p_unique_number';
  $rule->field_name = 'field_elife_p_episode_number';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'elife_podcast';
  $rule->validator = 'field_validation_unique_validator';
  $rule->settings = array(
    'data' => 'bundle',
    'per_user' => 0,
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
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
  $rule->error_message = 'Looks to be a duplicate of [existing-entity-link]';
  $export['elife_p_unique_number'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'HTTPS URL';
  $rule->name = 'elife_p_url_https';
  $rule->field_name = 'field_elife_p_url';
  $rule->col = 'url';
  $rule->entity_type = 'node';
  $rule->bundle = 'elife_podcast';
  $rule->validator = 'field_validation_regex_validator';
  $rule->settings = array(
    'data' => '^https://',
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
  $rule->error_message = 'Must be a HTTPS URL';
  $export['elife_p_url_https'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Embed HTTPS only';
  $rule->name = 'elife_pc_text_https';
  $rule->field_name = 'field_elife_pc_text';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'elife_podcast_chapter';
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
  $export['elife_pc_text_https'] = $rule;

  return $export;
}
