<?php

// Composer Manager settings.
$conf['composer_manager_vendor_dir'] = __DIR__ . '/vendor';
$conf['composer_manager_file_dir'] = __DIR__;
$conf['composer_manager_autobuild_file'] = FALSE;
$conf['composer_manager_autobuild_packages'] = FALSE;

// Exeter Markup Service URI
$conf['elife_article_exeter_markup_service_uri'] = 'http://api.exetercs.com/job.api/xmltohtml?apiKey=6c8e740baa82f222c5e63b39ffac2613&accountKey=1';

// Include the local settings, this MUST contain the $databases variable (and
// any other sensitive credentials in the future), as well as any custom
// configuration required during development.
require __DIR__ . '/../local.settings.php';
