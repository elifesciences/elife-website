<?php
/**
 * @file
 * elife_users.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function elife_users_user_default_roles() {
  $roles = array();

  // Exported role: eLife Administrator.
  $roles['eLife Administrator'] = array(
    'name' => 'eLife Administrator',
    'weight' => 4,
  );

  // Exported role: eLife Article Publisher.
  $roles['eLife Article Publisher'] = array(
    'name' => 'eLife Article Publisher',
    'weight' => 3,
  );

  // Exported role: eLife Editor.
  $roles['eLife Editor'] = array(
    'name' => 'eLife Editor',
    'weight' => 2,
  );

  return $roles;
}
