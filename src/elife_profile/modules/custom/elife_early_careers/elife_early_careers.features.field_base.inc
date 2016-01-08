<?php
/**
 * @file
 * elife_early_careers.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function elife_early_careers_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_elife_s_reference'.
  $field_bases['field_elife_s_reference'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_elife_s_reference',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'entityqueue' => array(
            'status' => 0,
          ),
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'elife_article_reference' => 'elife_article_reference',
          'elife_collection' => 'elife_collection',
          'elife_early_careers_interview' => 'elife_early_careers_interview',
          'elife_news_article' => 'elife_news_article',
          'elife_podcast' => 'elife_podcast',
        ),
      ),
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_elife_s_text'.
  $field_bases['field_elife_s_text'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_elife_s_text',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 500,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
