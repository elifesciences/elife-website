<?php 
/**
 * @file
 * Custom Theme Setting
 *
 * Copyright (c) 2010-2011 Board of Trustees, Leland Stanford Jr. University
 * This software is open-source licensed under the GNU Public License Version 2 or later
 * The full license is available in the LICENSE.TXT file at the root of this repository
 */
// Form Settings
  $form['more_settings_custom']['form_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Form Settings'),
    '#description' => t('In this section, you can control various form elements throughout the site, and if the theme should perform alterations on those forms.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['more_settings_custom']['form_settings']['user_login_form'] = array(
    '#type' => 'checkbox',
    '#title' => t('Modify Login Block'),
    '#default_value' => theme_get_setting('user_login_form'),
    '#description' => t('<p>The links on the login form are somewhat ugly, and lack a way to add a link without writing over the #markup in the $form[links] section. This modification adds a login link inline with the password request and register links, making a horizontal login block much nicer.</p>'),
  );
  if (module_exists('delta')) {
    $form['more_settings_custom']['form_settings']['user_login_form']['#description'] .= t('<p><strong>Notice:</strong> This is a global setting, and is unaffected by Delta overrides.</p>');
  }
  $form['more_settings_custom']['form_settings']['user_login_name_placeholder'] = array(
    '#type' => 'textfield',
    '#title' => t('Placeholder text for Username Field'),
    '#size' => 60,
    '#default_value' => theme_get_setting('user_login_name_placeholder'),
    '#description' => t('Only works via HTML5 aware browsers.'),
  );
  $form['more_settings_custom']['form_settings']['user_login_pass_placeholder'] = array(
    '#type' => 'textfield',
    '#title' => t('Placeholder text for Password Field'),
    '#size' => 60,
    '#default_value' => theme_get_setting('user_login_pass_placeholder'),
    '#description' => t('Only works via HTML5 aware browsers.'),
  );
  $form['more_settings_custom']['form_settings']['custom_search_default_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Placeholder text for Search field'),
    '#size' => 60,
    '#default_value' => theme_get_setting('custom_search_default_text'),
    '#description' => t('Only works via HTML5 aware browsers.'),
  );
