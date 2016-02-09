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
      'elife_users_prod',
      'googleanalytics',
      'google_tag',
    ],
    ELIFE_ENVIRONMENT_DEVELOPMENT => [
      'admin_devel',
      'devel',
      'diff',
      'ds_ui',
      'elife_users_dev',
      'field_ui',
      'field_validation_ui',
      'module_builder',
      'module_filter',
      'omega_tools',
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

/**
 * Implements hook_ctools_render_alter().
 */
function elife_profile_ctools_render_alter(&$info, &$page, &$context) {
  if ($page && in_array($context['task']['name'], array('node_view'), TRUE)) {
    $data = array_values($context['contexts']);
    // Below is nothing but to call hook_node_view which force to pass the node
    // object.
    // @see https://www.drupal.org/node/1606912#comment-8318685
    $langcode = $GLOBALS['language_content']->language;
    module_invoke_all('node_view', $data[0]->data, 'full', $langcode);
  }
}
