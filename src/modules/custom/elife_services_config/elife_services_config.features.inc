<?php
/**
 * @file
 * elife_services_config.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function elife_services_config_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "services" && $api == "services") {
    return array("version" => "3");
  }
}
