<?php
/**
 * @file
 * elife_article_rss.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function elife_article_rss_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function elife_article_rss_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_date_custom_date_formats().
 */
function elife_article_rss_fe_date_custom_date_formats() {
  $custom_date_formats = array();
  $custom_date_formats['D, d M Y H:i:s O'] = 'D, d M Y H:i:s O';
  return $custom_date_formats;
}

/**
 * Implements hook_date_format_types().
 */
function elife_article_rss_date_format_types() {
  $format_types = array();
  // Exported date format type: elife_rfc822
  $format_types['elife_rfc822'] = 'RFC 822';
  return $format_types;
}
