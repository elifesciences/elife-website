<?php
/**
 * @file
 * elife_podcast.features.inc
 */

/**
 * Implements hook_default_cer().
 */
function elife_podcast_default_cer() {
  $items = array();
  $items['node:elife_podcast:field_elife_p_chapters*node:elife_podcast_chapter:field_elife_pc_podcast'] = entity_import('cer', '{
    "identifier" : "node:elife_podcast:field_elife_p_chapters*node:elife_podcast_chapter:field_elife_pc_podcast",
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_weight" : { "und" : [ { "value" : "0" } ] },
    "cer_left" : { "und" : [ { "path" : "node:elife_podcast:field_elife_p_chapters" } ] },
    "cer_right" : { "und" : [ { "path" : "node:elife_podcast_chapter:field_elife_pc_podcast" } ] }
  }');
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function elife_podcast_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "field_validation" && $api == "default_field_validation_rules") {
    return array("version" => "2");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function elife_podcast_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function elife_podcast_node_info() {
  $items = array(
    'elife_podcast' => array(
      'name' => t('eLife Podcast'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'elife_podcast_chapter' => array(
      'name' => t('eLife Podcast Chapter'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
