<?php
/**
 * @file
 * Administration settings page definition for the eLife Resources module.
 */

/**
 * Implements hook_admin_settings().
 */
function elife_resources_admin_settings_form($form_state) {
  $form = array();
  $form['api'] = array(
    '#title' => t('General settings'),
    '#type' => 'fieldset',
  );
  $form['api']['elife_resources_cache_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Cache enabled'),
    '#default_value' => elifeResources::cacheEnabled(),
  );

  $form['api']['elife_resources_cache_time'] = array(
    '#type' => 'textfield',
    '#title' => t('Cache time'),
    '#description' => t('Provide in seconds.'),
    '#default_value' => elifeResources::getCacheTime(),
  );

  $form['api']['elife_resources_secret_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Secret key'),
    '#default_value' => elifeResources::getSecretKey(),
  );
  return system_settings_form($form);
}
