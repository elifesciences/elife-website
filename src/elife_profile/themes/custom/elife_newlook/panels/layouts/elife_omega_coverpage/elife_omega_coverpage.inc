<?php

/**
 * Implements hook_panels_layouts()
 */
function elife_newlook_elife_omega_coverpage_panels_layouts() {
  $items['elife_omega_coverpage'] = array(
    'title' => t('Elife Coverpage'),
    'category' => t('Elife Omega: 30 Column Grid'),
    'icon' => 'elife_omega_coverpage.png',
    'theme' => 'elife_omega_coverpage',
    'admin css' => '../elife_omega_panels_admin_30.css',
      'regions' => array(
          'top' => t('Top'),
          'banner' => t('Banner'),
          'middle' => t('Middle'),
          'nav' => t('Middle-Nav'),
          'action' => t('Action'),
          'bottom' => t('Bottom'),
      ),
  );

  return $items;
}

