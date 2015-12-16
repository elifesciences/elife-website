<?php
/**
 * @file
 * elife_house_style.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function elife_house_style_filter_default_formats() {
  $formats = array();

  // Exported format: eLife House Style.
  $formats['elife_house_style'] = array(
    'format' => 'elife_house_style',
    'name' => 'eLife House Style',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'elife_xml_elements' => array(
        'weight' => -20,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_html' => array(
        'weight' => -10,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<i> <sup> <sub>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
