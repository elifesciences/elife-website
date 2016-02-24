<?php
/**
 * @file
 * elife_disqus.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function elife_disqus_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'disqus_inherit_login';
  $strongarm->value = 0;
  $export['disqus_inherit_login'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'disqus_localization';
  $strongarm->value = 0;
  $export['disqus_localization'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'disqus_location';
  $strongarm->value = 'block';
  $export['disqus_location'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'disqus_logo';
  $strongarm->value = 0;
  $export['disqus_logo'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'disqus_nodetypes';
  $strongarm->value = array(
    'elife_article_ver' => 'elife_article_ver',
    'elife_news_article' => 'elife_news_article',
    'elife_annual_report' => 0,
    'elife_article' => 0,
    'elife_contributor' => 0,
    'elife_fragment' => 0,
    'elife_article_reference' => 0,
    'elife_collection' => 0,
    'elife_early_careers_spotlight' => 0,
    'elife_early_careers_interview' => 0,
    'elife_event' => 0,
    'elife_cover' => 0,
    'elife_front_matter' => 0,
    'elife_labs_entry' => 0,
    'elife_organisation' => 0,
    'elife_person_profile' => 0,
    'elife_podcast' => 0,
    'elife_podcast_chapter' => 0,
    'webform' => 0,
  );
  $export['disqus_nodetypes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'disqus_nodetypes_default';
  $strongarm->value = array(
    'elife_article_ver' => 'elife_article_ver',
    'elife_news_article' => 'elife_news_article',
    'elife_annual_report' => 0,
    'elife_article' => 0,
    'elife_contributor' => 0,
    'elife_fragment' => 0,
    'elife_article_reference' => 0,
    'elife_collection' => 0,
    'elife_early_careers_spotlight' => 0,
    'elife_early_careers_interview' => 0,
    'elife_event' => 0,
    'elife_cover' => 0,
    'elife_front_matter' => 0,
    'elife_labs_entry' => 0,
    'elife_organisation' => 0,
    'elife_person_profile' => 0,
    'elife_podcast' => 0,
    'elife_podcast_chapter' => 0,
    'webform' => 0,
  );
  $export['disqus_nodetypes_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'disqus_publickey';
  $strongarm->value = '';
  $export['disqus_publickey'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'disqus_secretkey';
  $strongarm->value = '';
  $export['disqus_secretkey'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'disqus_sso';
  $strongarm->value = 0;
  $export['disqus_sso'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'disqus_useraccesstoken';
  $strongarm->value = '';
  $export['disqus_useraccesstoken'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'disqus_use_site_logo';
  $strongarm->value = 0;
  $export['disqus_use_site_logo'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'disqus_weight';
  $strongarm->value = '50';
  $export['disqus_weight'] = $strongarm;

  return $export;
}
