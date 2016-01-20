<?php

/**
 * @file
 * elife_content_alerts/plugins/layouts/elife_content_alerts/elife_content_alerts_vor.inc
 */

$plugin = array(
  'title' => t('eLife: Content alerts'),
  'category' => t('eLife'),
  'icon' => 'elife_content_alerts.png',
  'theme' => 'elife_content_alerts',
  'regions' => array(
    'header' => t('Header'),
    'logo' => t('Logo'),
    'alert_date' => t('Date'),
    'intro' => t('Intro'),
    'categories' => t('Categories'),
    'front' => t('Front matter'),
    'content' => t('Main content'),
  ),
);
