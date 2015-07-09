<?php
/**
 * @file
 * elife_article.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function elife_article_taxonomy_default_vocabularies() {
  return array(
    'elife_categories' => array(
      'name' => 'Categories',
      'machine_name' => 'elife_categories',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'elife_headings' => array(
      'name' => 'Headings',
      'machine_name' => 'elife_headings',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'elife_keywords' => array(
      'name' => 'Keywords',
      'machine_name' => 'elife_keywords',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
