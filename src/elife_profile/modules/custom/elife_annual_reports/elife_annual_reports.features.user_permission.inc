<?php
/**
 * @file
 * elife_annual_reports.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function elife_annual_reports_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create elife_annual_report content'.
  $permissions['create elife_annual_report content'] = array(
    'name' => 'create elife_annual_report content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any elife_annual_report content'.
  $permissions['delete any elife_annual_report content'] = array(
    'name' => 'delete any elife_annual_report content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own elife_annual_report content'.
  $permissions['delete own elife_annual_report content'] = array(
    'name' => 'delete own elife_annual_report content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any elife_annual_report content'.
  $permissions['edit any elife_annual_report content'] = array(
    'name' => 'edit any elife_annual_report content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own elife_annual_report content'.
  $permissions['edit own elife_annual_report content'] = array(
    'name' => 'edit own elife_annual_report content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view any unpublished elife_annual_report content'.
  $permissions['view any unpublished elife_annual_report content'] = array(
    'name' => 'view any unpublished elife_annual_report content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'view_unpublished',
  );

  return $permissions;
}
