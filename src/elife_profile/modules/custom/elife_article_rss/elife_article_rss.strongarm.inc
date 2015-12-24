<?php
/**
 * @file
 * elife_article_rss.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function elife_article_rss_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_elife_iso8601';
  $strongarm->value = 'c';
  $export['date_format_elife_iso8601'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_elife_rfc822';
  $strongarm->value = 'r';
  $export['date_format_elife_rfc822'] = $strongarm;

  return $export;
}
