<?php
/**
 * @file
 * elife_hero_block.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function elife_hero_block_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Unique';
  $rule->name = 'elife_h_path_unique';
  $rule->field_name = 'field_elife_h_path';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'elife_hero_block';
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
  $export['elife_h_path_unique'] = $rule;

  return $export;
}
