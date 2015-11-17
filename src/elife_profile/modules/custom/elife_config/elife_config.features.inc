<?php
/**
 * @file
 * elife_config.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function elife_config_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "elysia_cron" && $api == "default_elysia_cron_rules") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_fe_date_custom_date_formats().
 */
function elife_config_fe_date_custom_date_formats() {
  $custom_date_formats = array();
  $custom_date_formats['F d, Y'] = 'F d, Y';
  return $custom_date_formats;
}

/**
 * Implements hook_date_format_types().
 */
function elife_config_date_format_types() {
  $format_types = array();
  // Exported date format type: elife_date_only
  $format_types['elife_date_only'] = 'Date only';
  return $format_types;
}
