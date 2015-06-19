<?php

/**
 * Implements hook_panels_layouts()
 */
function elife_elife_home_extended_listing_panels_layouts() {
  $items['elife_home_extended_listing'] = array(
    'title' => t('eLife: Home Layout (extended listing)'),
  	'category' => t('eLife'),
  	'icon' => 'elife_home_extended_listing.png',
    'theme' => 'elife_home_extended_listing',
    // 'theme' => 'elife_home',
    'admin css' => '../elife-panels-admin.css',
    'regions' => array(
    	'top_main_new' => t('Top Main (Carousel)'),
    	'top_side_first_new' => t('Top Sidebar First'),
    	'top_side_second_new' => t('Top Sidebar Second'),
    	'top_side_third_new' => t('Top Sidebar Third'),
			'middle_new' => t('Middle (Collapsible)'),
    	'bottom_first_new' => t('Bottom First (Left)'),
    	'bottom_second_new' => t('Bottom Second (Middle)'),
    	'bottom_third_new' => t('Bottom Third (Right)')
    ),
  );

  return $items;
}
