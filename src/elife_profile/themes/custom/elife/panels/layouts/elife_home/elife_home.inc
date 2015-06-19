<?php

/**
 * Implements hook_panels_layouts()
 */
function elife_elife_home_panels_layouts() {
  $items['elife_home'] = array( 											
    'title' => t('eLife: Home Layout'),
  	'category' => t('eLife'),														
  	'icon' => 'elife_home.png',							
    'theme' => 'elife_home',									
    'admin css' => '../elife-panels-admin.css',
    'regions' => array(																						    
    	'top_main' => t('Top Main (Carousel)'),
    	'top_side_first' => t('Top Sidebar First'),
    	'top_side_second' => t('Top Sidebar Second'),
    	'top_side_third' => t('Top Sidebar Third'),
			'middle' => t('Middle (Collapsible)'),
    	'bottom_first' => t('Bottom First (Left)'),
    	'bottom_second' => t('Bottom Second (Middle)'),
    	'bottom_third' => t('Bottom Third (Right)')
    ),
  );

  return $items;
}
