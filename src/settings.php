<?php

// Set up Composer.
require_once __DIR__ . '/../vendor/autoload.php';
$conf['elife_composer_vendor_path'] = __DIR__ . '/../vendor';

// Don't allow modules to be added/updated through the UI.
$conf['allow_authorize_operations'] = FALSE;

// Set path for 403.
$conf['site_403'] = 'm4032404';

// Set up Pathologic.
$conf['pathologic_protocol_style'] = 'full';
$conf['pathologic_local_paths'] = [
  'http://elifesciences.org',
  'https://elifesciences.org',
  'http://www.elifesciences.org',
  'https://www.elifesciences.org',
  '/',
];

// Include the local settings, this MUST contain the $databases variable (and
// any other sensitive credentials in the future), as well as any custom
// configuration required during development.
require __DIR__ . '/../local.settings.php';

// Turn Pathologic setting into the expected string.
if (isset($conf['pathologic_local_paths'])) {
  $conf['pathologic_local_paths'] = implode("\n", $conf['pathologic_local_paths']);
}
