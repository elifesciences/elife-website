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
  $strongarm->name = 'date_format_elife_rfc822';
  $strongarm->value = 'D, d M Y H:i:s O';
  $export['date_format_elife_rfc822'] = $strongarm;

  return $export;
}
