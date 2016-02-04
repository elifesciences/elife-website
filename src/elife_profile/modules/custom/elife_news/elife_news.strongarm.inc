<?php
/**
 * @file
 * elife_news.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function elife_news_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__elife_news_article';
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
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'elife_teaser_alternative' => array(
        'custom_settings' => FALSE,
      ),
      'elife_teaser_compact' => array(
        'custom_settings' => TRUE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '50',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '49',
        ),
        'rabbit_hole' => array(
          'weight' => '47',
        ),
        'redirect' => array(
          'weight' => '48',
        ),
      ),
      'display' => array(
        'sharethis' => array(
          'default' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
          'elife_teaser_compact' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__elife_news_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_elife_news_article';
  $strongarm->value = array();
  $export['menu_options_elife_news_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_elife_news_article';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_elife_news_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_elife_news_article';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_elife_news_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_elife_news_article';
  $strongarm->value = '1';
  $export['node_preview_elife_news_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_elife_news_article';
  $strongarm->value = 0;
  $export['node_submitted_elife_news_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_elife_news_article_pattern';
  $strongarm->value = 'elife-news/[node:title]';
  $export['pathauto_node_elife_news_article_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_elife_n_category_pattern';
  $strongarm->value = 'elife-news/[term:name]';
  $export['pathauto_taxonomy_term_elife_n_category_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_elife_news_article';
  $strongarm->value = array(
    'status' => '1',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_elife_news_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_taxonomy_term_elife_n_category';
  $strongarm->value = array(
    'status' => '1',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_taxonomy_term_elife_n_category'] = $strongarm;

  return $export;
}
