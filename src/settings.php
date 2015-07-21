<?php

// Set up Composer.
require_once __DIR__ . '/../vendor/autoload.php';
$conf['elife_composer_vendor_path'] = __DIR__ . '/../vendor';

// Don't allow modules to be added/updated through the UI.
$conf['allow_authorize_operations'] = FALSE;

// Set path for 403.
$conf['site_403'] = 'm4032404';

// Include the local settings, this MUST contain the $databases variable (and
// any other sensitive credentials in the future), as well as any custom
// configuration required during development.
require __DIR__ . '/../local.settings.php';
