<?php
/**
 * @file
 * elife_article_pages.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function elife_article_pages_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panels_ajax_tab';
  $strongarm->value = array(
    'clean_url' => 1,
    'clean_url_delim' => '/',
    'panes' => array(
      'elife-article-tabs' => array(
        'elife_article' => '',
        'elife_article_metrics' => 'article-metrics',
      ),
      'elife-research-article-tabs' => array(
        'elife_article' => '',
        'elife_article_figdata' => 'article-data',
        'elife_article_metrics' => 'article-metrics',
        'elife_article_author' => 'article-info',
      ),
    ),
  );
  $export['panels_ajax_tab'] = $strongarm;

  return $export;
}
