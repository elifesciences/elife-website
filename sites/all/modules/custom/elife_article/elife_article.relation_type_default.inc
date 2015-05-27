<?php
/**
 * @file
 * elife_article.relation_type_default.inc
 */

/**
 * Implements hook_relation_default_relation_types().
 */
function elife_article_relation_default_relation_types() {
  $export = array();

  $relation_type = new stdClass();
  $relation_type->disabled = FALSE; /* Edit this to true to make a default relation_type disabled initially */
  $relation_type->api_version = 1;
  $relation_type->relation_type = 'elife_relation';
  $relation_type->label = 'eLife Relation';
  $relation_type->reverse_label = 'eLife Relation';
  $relation_type->directional = 0;
  $relation_type->transitive = 0;
  $relation_type->r_unique = 0;
  $relation_type->min_arity = 2;
  $relation_type->max_arity = 2;
  $relation_type->source_bundles = array(
    0 => 'node:elife_article',
  );
  $relation_type->target_bundles = array();
  $export['elife_relation'] = $relation_type;

  return $export;
}
