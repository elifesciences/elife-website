<?php

/**
 * Returns the current environment.
 *
 * @return string
 */
function elife_environment() {
  return variable_get('elife_environment', ELIFE_ENVIRONMENT_PRODUCTION);
}

/**
 * Returns environment-specific modules.
 *
 * @param string $environment
 *   Environment to check.
 * @param bool $inverse
 *   FALSE for modules required by this environment, TRUE for modules required
 *   by other environments (excluding those also required by this environment).
 *
 * @return array
 *   Modules.
 */
function elife_profile_environment_modules($environment, $inverse = FALSE) {
  static $modules = [
    ELIFE_ENVIRONMENT_PRODUCTION => [
    ],
    ELIFE_ENVIRONMENT_DEVELOPMENT => [
      'admin_devel',
      'context_ui',
      'delta_ui',
      'devel',
      'ds_ui',
      'field_ui',
      'field_validation_ui',
      'module_builder',
      'rules_admin',
      'update',
      'views_ui',
    ],
    ELIFE_ENVIRONMENT_TESTING => [
    ],
  ];

  if (!isset($modules[$environment])) {
    throw new LogicException('Invalid environment');
  }

  if (!$inverse) {
    return $modules[$environment];
  }
  else {
    $filtered = [];

    foreach ($modules as $this_environment => $environment_modules) {
      if ($environment === $this_environment) {
        continue;
      }

      $filtered = array_merge($filtered, $environment_modules);
    }

    return array_unique(array_diff($filtered, $modules[$environment]));
  }
}
