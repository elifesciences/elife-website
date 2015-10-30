<?php
/**
 * @file
 * elife_news.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function elife_news_taxonomy_default_vocabularies() {
  return array(
    'elife_n_category' => array(
      'name' => 'News category',
      'machine_name' => 'elife_n_category',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
