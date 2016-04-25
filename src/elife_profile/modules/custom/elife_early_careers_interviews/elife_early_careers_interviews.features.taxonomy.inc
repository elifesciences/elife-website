<?php
/**
 * @file
 * elife_early_careers_interviews.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function elife_early_careers_interviews_taxonomy_default_vocabularies() {
  return array(
    'elife_i_series' => array(
      'name' => 'Interview series',
      'machine_name' => 'elife_i_series',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
