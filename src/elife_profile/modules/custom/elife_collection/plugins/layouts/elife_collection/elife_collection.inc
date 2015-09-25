<?php

/**
 * @file
 * elife_templates/plugins/layouts/elife_collection/elife_collection.inc
 */

$plugin = array(
  'title' => t('eLife: Collection'),
  'category' => t('eLife'),
  'icon' => 'elife_collection.png',
  'theme' => 'elife_collection',
  'admin css' => 'elife-collection.css',
  'regions' => array(
    'hero_block' => t('Hero block'),
    'content' => t('Main Content'),
    'sidebar' => t('Sidebar'),
  ),
);
