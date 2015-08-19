<?php
/**
 * @file
 * elife_person_profile.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function elife_person_profile_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_node_elife_person_profile';
  $strongarm->value = '1';
  $export['auto_entitylabel_node_elife_person_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_pattern_node_elife_person_profile';
  $strongarm->value = '[node:field-elife-p-last-name], [node:field-elife-p-first-name] ([node:field-elife-p-type])';
  $export['auto_entitylabel_pattern_node_elife_person_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_php_node_elife_person_profile';
  $strongarm->value = 0;
  $export['auto_entitylabel_php_node_elife_person_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__elife_person_profile';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'elife_teaser_reviewing_editor' => array(
        'custom_settings' => TRUE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'elife_teaser_alternative' => array(
        'custom_settings' => TRUE,
      ),
      'elife_teaser_compact' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '7',
        ),
        'title' => array(
          'weight' => '3',
        ),
        'path' => array(
          'weight' => '6',
        ),
        'rabbit_hole' => array(
          'weight' => '4',
        ),
        'redirect' => array(
          'weight' => '5',
        ),
      ),
      'display' => array(
        'sharethis' => array(
          'default' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '15',
            'visible' => FALSE,
          ),
          'elife_teaser_reviewing_editor' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
          'elife_teaser_alternative' => array(
            'weight' => '14',
            'visible' => FALSE,
          ),
          'elife_teaser_compact' => array(
            'weight' => '12',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__elife_person_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_elife_person_profile';
  $strongarm->value = array();
  $export['menu_options_elife_person_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_elife_person_profile';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_elife_person_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_elife_person_profile';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_elife_person_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_elife_person_profile';
  $strongarm->value = '1';
  $export['node_preview_elife_person_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_elife_person_profile';
  $strongarm->value = 0;
  $export['node_submitted_elife_person_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_module_elife_person_profile';
  $strongarm->value = 'rh_node';
  $export['rh_module_elife_person_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_node_action_elife_person_profile';
  $strongarm->value = '1';
  $export['rh_node_action_elife_person_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_node_override_elife_person_profile';
  $strongarm->value = 0;
  $export['rh_node_override_elife_person_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_node_redirect_elife_person_profile';
  $strongarm->value = '';
  $export['rh_node_redirect_elife_person_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_node_redirect_response_elife_person_profile';
  $strongarm->value = '301';
  $export['rh_node_redirect_response_elife_person_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_taxonomy_term_action_elife_p_experimental_organism';
  $strongarm->value = '2';
  $export['rh_taxonomy_term_action_elife_p_experimental_organism'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_taxonomy_term_action_elife_p_expertise';
  $strongarm->value = '2';
  $export['rh_taxonomy_term_action_elife_p_expertise'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_taxonomy_term_action_elife_p_research_focus';
  $strongarm->value = '2';
  $export['rh_taxonomy_term_action_elife_p_research_focus'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_taxonomy_term_override_elife_person_profile_type';
  $strongarm->value = 0;
  $export['rh_taxonomy_term_override_elife_person_profile_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_taxonomy_term_override_elife_p_experimental_organism';
  $strongarm->value = 0;
  $export['rh_taxonomy_term_override_elife_p_experimental_organism'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_taxonomy_term_override_elife_p_expertise';
  $strongarm->value = 0;
  $export['rh_taxonomy_term_override_elife_p_expertise'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_taxonomy_term_override_elife_p_research_focus';
  $strongarm->value = 0;
  $export['rh_taxonomy_term_override_elife_p_research_focus'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_taxonomy_term_redirect_elife_p_experimental_organism';
  $strongarm->value = '';
  $export['rh_taxonomy_term_redirect_elife_p_experimental_organism'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_taxonomy_term_redirect_elife_p_expertise';
  $strongarm->value = '';
  $export['rh_taxonomy_term_redirect_elife_p_expertise'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_taxonomy_term_redirect_elife_p_research_focus';
  $strongarm->value = '';
  $export['rh_taxonomy_term_redirect_elife_p_research_focus'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_taxonomy_term_redirect_response_elife_p_experimental_organism';
  $strongarm->value = '301';
  $export['rh_taxonomy_term_redirect_response_elife_p_experimental_organism'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_taxonomy_term_redirect_response_elife_p_expertise';
  $strongarm->value = '301';
  $export['rh_taxonomy_term_redirect_response_elife_p_expertise'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_taxonomy_term_redirect_response_elife_p_research_focus';
  $strongarm->value = '301';
  $export['rh_taxonomy_term_redirect_response_elife_p_research_focus'] = $strongarm;

  return $export;
}
