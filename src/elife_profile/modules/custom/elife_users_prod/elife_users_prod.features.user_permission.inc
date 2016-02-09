<?php
/**
 * @file
 * elife_users_prod.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function elife_users_prod_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer google analytics'.
  $permissions['administer google analytics'] = array(
    'name' => 'administer google analytics',
    'roles' => array(),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'administer google tag manager'.
  $permissions['administer google tag manager'] = array(
    'name' => 'administer google tag manager',
    'roles' => array(),
    'module' => 'google_tag',
  );

  // Exported permission: 'opt-in or out of tracking'.
  $permissions['opt-in or out of tracking'] = array(
    'name' => 'opt-in or out of tracking',
    'roles' => array(),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'use PHP for tracking visibility'.
  $permissions['use PHP for tracking visibility'] = array(
    'name' => 'use PHP for tracking visibility',
    'roles' => array(),
    'module' => 'googleanalytics',
  );

  return $permissions;
}
