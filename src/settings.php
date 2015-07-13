<?php

// Composer Manager settings.
$conf['composer_manager_vendor_dir'] = __DIR__ . '/vendor';
$conf['composer_manager_file_dir'] = __DIR__;
$conf['composer_manager_autobuild_file'] = FALSE;
$conf['composer_manager_autobuild_packages'] = FALSE;

// Don't allow modules to be added/updated through the UI.
$conf['allow_authorize_operations'] = FALSE;

// Include the local settings, this MUST contain the $databases variable (and
// any other sensitive credentials in the future), as well as any custom
// configuration required during development.
require __DIR__ . '/../local.settings.php';
