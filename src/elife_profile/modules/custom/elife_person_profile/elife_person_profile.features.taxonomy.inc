<?php
/**
 * @file
 * elife_person_profile.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function elife_person_profile_taxonomy_default_vocabularies() {
  return array(
    'elife_p_experimental_organism' => array(
      'name' => 'Person experimental organism',
      'machine_name' => 'elife_p_experimental_organism',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'elife_p_expertise' => array(
      'name' => 'Person expertise',
      'machine_name' => 'elife_p_expertise',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'elife_p_research_focus' => array(
      'name' => 'Person research focus',
      'machine_name' => 'elife_p_research_focus',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
