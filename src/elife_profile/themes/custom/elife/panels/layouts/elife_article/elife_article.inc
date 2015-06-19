<?php

/**
 * Implements hook_panels_layouts()
 */
function elife_elife_article_panels_layouts() {
  $items['elife_article'] = array(
    'title' => t('eLife: Article Layout'),
    'category' => t('eLife'),
    'icon' => 'elife_article.png',
    'theme' => 'elife_article',
    'admin css' => '../elife-panels-admin.css',
    'regions' => array(
      'top' => t('Top'),
      'main' => t('Main (Default content)'),
      'side_lens' => t('Sidebar Lens'),
      'side_link' => t('Sidebar Link'),
      'side_top' => t('Sidebar (Top)'),
      'side_bottom' => t('Sidebar (Bottom)'),
    ),
  );

  return $items;
}
