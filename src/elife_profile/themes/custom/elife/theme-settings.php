<?php

/**
 * @file
 * Theme Settings
 * Theme settings for the elife theme.
 * 
 * @see default-theme-settings.inc
 *
 * Implements hook_form_system_theme_settings_alter().
 *
 * @param $form
 *   Nested array of form elements that comprise the form.
 * @param $form_state
 *   A keyed array containing the current state of the form.
 *
 * Copyright (c) 2010-2011 Board of Trustees, Leland Stanford Jr. University
 * This software is open-source licensed under the GNU Public License Version 2 or later
 * The full license is available in the LICENSE.TXT file at the root of this repository
 *
 */

function elife_form_system_theme_settings_alter(&$form, &$form_state) {
    $form['more_settings_custom'] = array(
    '#type' => 'vertical_tabs',
    '#weight' => -9,
    '#default_tab' => 'defaults',
    '#prefix' => t('Custom Theme Settings'),
  );
  
  // include custom theme settings
  require(drupal_get_path('theme', 'elife') . '/inc/custom-theme-settings.inc');
}

