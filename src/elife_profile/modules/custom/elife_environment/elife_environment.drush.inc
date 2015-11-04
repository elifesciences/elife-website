<?php

/**
 * Implements hook_drush_command().
 */
function elife_environment_drush_command() {
  $items['elife-environment-modules'] = [
    'description' => dt('Enable/disable environment-specific modules'),
  ];
  return $items;
}

/**
 * Command callback. Enables/disables modules for the current environment.
 */
function drush_elife_environment_modules() {
  $enabled = elife_environment_enable_environment_modules();
  $disabled = elife_environment_disable_environment_modules();

  $flush_caches = FALSE;

  $return = [];

  if (empty($disabled)) {
    $return[] = t('Nothing to disable');
  }
  else {
    $return[] = t('Disabled: !modules', array('!modules' => implode(', ', $disabled)));
    $flush_caches = TRUE;
  }

  if (empty($enabled)) {
    $return[] = t('Nothing to enable');
  }
  else {
    $return[] = t('Enabled: !modules', array('!modules' => implode(', ', $enabled)));
    $flush_caches = TRUE;
  }

  if ($flush_caches) {
    drupal_flush_all_caches();
  }

  return implode(PHP_EOL, $return);
}
