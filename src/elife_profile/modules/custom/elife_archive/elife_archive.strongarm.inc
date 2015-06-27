<?php
/**
 * @file
 * elife_archive.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function elife_archive_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_f_y';
  $strongarm->value = 'F Y';
  $export['date_format_f_y'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_mm';
  $strongarm->value = 'm';
  $export['date_format_mm'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_yyyy';
  $strongarm->value = 'Y';
  $export['date_format_yyyy'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_yyyymm';
  $strongarm->value = 'Ym';
  $export['date_format_yyyymm'] = $strongarm;

  return $export;
}
