<?php
/**
 * @file
 * Preprocess Page
 *
 * Copyright (c) 2010-2011 Board of Trustees, Leland Stanford Jr. University
 * This software is open-source licensed under the GNU Public License Version 2 or later
 * The full license is available in the LICENSE.TXT file at the root of this repository
 */
?>
<?php 
	if (module_exists('page_manager')) {
		// if this is a panel page, add custom classes to #page div
		if ($panel_page = page_manager_get_current_page()) {
			
			//get info about panels template
			$display = panels_get_current_page_display();
				$layout = $display->layout;
				if (!empty($display->css_id)) {
					$cssID = $display->css_id;
				}
				
			//check for panel_type = 960 
			$this_layout = panels_get_layout($layout);
			if (isset($this_layout['panel_type'])) {
		    $layout_type = $this_layout['panel_type'];
		    
		    if ($layout_type == '960') {
					$vars['attributes_array']['class'][] = 'panels-960-grid';
				}
		  }
			
			//add custom classes to array
			$vars['attributes_array']['class'][] = 'panels-page';
			$vars['attributes_array']['class'][] = 'panels-layout-'.$layout;
			if (!empty($display->css_id)) {
				$vars['attributes_array']['class'][] = 'panels-style-id-'.$cssID;
			}
			
			// Unset page title so we can still use this for meta title but not allow it to display
			$vars['title_hidden'] = TRUE; 
		}
		else {
			$vars['attributes_array']['class'][] = 'no-panels-page';
		}
	}
