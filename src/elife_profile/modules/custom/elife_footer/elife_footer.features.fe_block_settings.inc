<?php
/**
 * @file
 * elife_footer.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function elife_footer_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['elife_footer-elife_footer'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 'elife_footer',
    'module' => 'elife_footer',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'elife' => array(
        'region' => 'footer_first',
        'status' => 1,
        'theme' => 'elife',
        'weight' => 0,
      ),
      'elife_newlook' => array(
        'region' => 'footer_first',
        'status' => 1,
        'theme' => 'elife_newlook',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
