<?php

use Monolog\Handler\ErrorLogHandler;

const ELIFE_ENVIRONMENT_PRODUCTION = 'production';
const ELIFE_ENVIRONMENT_DEVELOPMENT = 'development';
const ELIFE_ENVIRONMENT_TESTING = 'testing';

// Set up Composer.
require_once __DIR__ . '/../vendor/autoload.php';
$conf['elife_composer_vendor_path'] = __DIR__ . '/../vendor';

// Set up Drupal.
$conf['install_profile'] = 'elife_profile';
$conf['maintenance_theme'] = 'elife_maintenance';

// Don't allow modules to be added/updated through the UI.
$conf['allow_authorize_operations'] = FALSE;

// Don't use poormanscron.
$conf['cron_safe_threshold'] = 0;

// Set path for 403.
$conf['site_403'] = 'm4032404';

// Set up Pathologic.
$conf['pathologic_protocol_style'] = 'full';
$conf['pathologic_local_paths'] = [
  'http://elifesciences.org/',
  'https://elifesciences.org/',
  'http://www.elifesciences.org/',
  'https://www.elifesciences.org/',
  '/',
];

// Set up ImageMagick
$conf['image_toolkit'] = 'imagemagick';
$conf['imagemagick_quality'] = 75;
$conf['imagemagick_advanced_interlace'] = 'plane';

// Set up Disqus.
$conf['disqus_domain'] = 'elifesciences-staging'; // Staging by default.

// File cache directory.
$conf['elife_cache_dir'] = __DIR__ . '/../cache';

// Uploaded files directories.
$conf['file_public_path'] = 'sites/default/files';
$conf['file_private_path'] = __DIR__ . '/../private';
$conf['file_temporary_path'] = sys_get_temp_dir();

// Configure Redis.
$conf['redis_client_interface'] = extension_loaded('redis') ? 'PhpRedis' : 'Predis';
$conf['lock_inc'] = 'profiles/elife_profile/modules/contrib/redis/redis.lock.inc';
$conf['path_inc'] = 'profiles/elife_profile/modules/contrib/redis/redis.path.inc';
$conf['cache_backends'][] = 'profiles/elife_profile/modules/contrib/redis/redis.autoload.inc';
$conf['cache_default_class'] = 'Redis_Cache';
$conf['cache_class_cache_elife_markup'] = 'DrupalDatabaseCache';
$conf['cache_class_cache_elife_citation'] = 'DrupalDatabaseCache';

// String overrides.
$conf['locale_custom_strings_en'][''] = [
  'Allowed HTML tags: @tags' => 'Allowed HTML tags: @tags. (HTML character references such as <code>&amp;nbsp;</code> are also allowed)',
];

// Include the local settings, this MUST contain:
//
// - $databases
// - $conf['redis_client_host'] OR $conf['redis_client_socket']
// - $conf['imagemagick_convert']
// - $conf['elife_environment']
//
// It may also contain any custom configuration required by this environment.
require __DIR__ . '/../local.settings.php';

// Turn Pathologic setting into the expected string.
if (isset($conf['pathologic_local_paths'])) {
  $conf['pathologic_local_paths'] = implode("\n", $conf['pathologic_local_paths']);
}

// Use PHP's error log if Monolog hasn't been configured.
if (!isset($conf['elife_monolog_handlers'])) {
  $conf['elife_monolog_handlers'] = new ErrorLogHandler();
}

// The 'cache_form' bin must be assigned to non-volatile storage.
$conf['cache_class_cache_form'] = 'DrupalDatabaseCache';

if (function_exists('drush_get_context') && isset(drush_get_context()['command']['command']) && 'site-install' === drush_get_context()['command']['command']) {
  // If the site is being installed by Drush, Drupal can't cope with alternative
  // caches. So, we need to remove any cache variables and let it fall back to
  // using the database.
  foreach ($conf as $key => $value) {
    if ('cache_' === substr($key, 0, 6)) {
      unset($conf[$key]);
    }
  }
  unset($conf['lock_inc']);
  unset($conf['path_inc']);
}

// Setup lagotto_services.
$conf['lagotto_services_url'] = 'http://alm.svr.elifesciences.org';
$conf['lagotto_services_apikey'] = '5pVvShVqAJ9Ch3tFzori';

// Setup elife_article_almvis.
$conf['elife_article_almvis_metrics_url'] = 'https://prod--metrics.elifesciences.org/api/v1/article/hw,ga/';
$conf['elife_article_almvis_ga_switch_date'] = '2016-02-01';

// See https://www.drupal.org/node/2009584.
$conf['preserve_css_double_underscores'] = TRUE;

// Due to concurrency issues we can't currently process more than one article at a time.
$conf['elife_services_locks'] = 1;

// Hide error messages in production, otherwise show all.
$conf['error_level'] = (ELIFE_ENVIRONMENT_PRODUCTION === $conf['elife_environment'] ? ERROR_REPORTING_HIDE : ERROR_REPORTING_DISPLAY_ALL);

if (ELIFE_ENVIRONMENT_PRODUCTION === $conf['elife_environment']) {
  // Enable caching in production.
  $conf['cache'] = TRUE;
  $conf['page_cache_maximum_age'] = 3600;

  // Let a higher level handle page compression.
  $conf['page_compression'] = FALSE;

  // Let Drupal aggregate assets.
  $conf['preprocess_css'] = TRUE;
  $conf['preprocess_js'] = TRUE;

  // Let Drupal compress generated assets (since they only happen once).
  $conf['css_gzip_compression'] = TRUE;
  $conf['js_gzip_compression'] = TRUE;

  // No need for Drupal to cache the response.
  if (!class_exists('DrupalFakeCache')) {
    $conf['cache_backends'][] = 'includes/cache-install.inc';
  }
  $conf['cache_class_cache_page'] = 'DrupalFakeCache';
}
