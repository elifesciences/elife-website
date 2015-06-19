<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 * 
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 *
 * Copyright (c) 2010-2011 Board of Trustees, Leland Stanford Jr. University
 * This software is open-source licensed under the GNU Public License Version 2 or later
 * The full license is available in the LICENSE.TXT file at the root of this repository
 */

 
function elife_form_alter(&$form, &$form_state, $form_id) {
  switch ($form_id) {
    // add a login link to the horizontal login bar block
    case 'user_login_block':
      if(theme_get_setting('user_login_form')) {
        $form['links']['#markup'] = "";
        
        $items = array();
        $items[] = l(t('Login'), 'user/login', array('attributes' => array('title' => t('Log in.'), 'class' => 'login-submit-link')));
        if (variable_get('user_register', USER_REGISTER_VISITORS_ADMINISTRATIVE_APPROVAL)) {
          $items[] = l(t('Register'), 'user/register', array('attributes' => array('title' => t('Create a new user account.'))));
        }
        $items[] = l(t('Password'), 'user/password', array('attributes' => array('title' => t('Request new password via e-mail.'))));
        $form['links']['#markup'] = theme('item_list', array('items' => $items));
      }
    
      // HTML5 placeholder attribute
      $form['name']['#attributes']['placeholder'] = theme_get_setting('user_login_name_placeholder');
      $form['pass']['#attributes']['placeholder'] = theme_get_setting('user_login_pass_placeholder');
      // Make labels invisible
	  	$form['name']['#title_display'] = 'invisible';
	  	$form['pass']['#title_display'] = 'invisible';
	  
      break;
      
    case 'search_block_form':
      // HTML5 placeholder attribute
      $form['search_block_form']['#attributes']['placeholder'] = theme_get_setting('custom_search_default_text');
      
      break;
  }
}


/**
 * Add unique class (mlid) to all menu items, as well as a class based on the link's title
 */
function elife_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';
  
	//create class from menu title 
	$menu_title_class = 'menu-' . drupal_html_class($element['#original_link']['link_title']);
	
	//add extra classes for menu items
  $element['#attributes']['class'][] = 'menu-' . $element['#original_link']['mlid'];
  $element['#attributes']['class'][] = $menu_title_class;

  if (!empty($element['#original_link']['options']) && !empty($element['#original_link']['options']['attributes']) && !empty($element['#original_link']['options']['attributes']['class'])) {
    foreach ($element['#original_link']['options']['attributes']['class'] as $class) {
      $element['#attributes']['class'][] = 'menu-li-' . $class;
    }
  }

  //set HTML to true for elife bar & main menu links 
  switch($element['#original_link']['menu_name']) {
  	case 'menu-elife-bar-menu':
  		$element['#localized_options']['html'] = true;
	  
		  if ($element['#href'] == '<front>') {
		  	$element['#attributes']['class'][] = 'active';
		  }
		  
		  break;
		  
		case 'main-menu': 
			$element['#localized_options']['html'] = true;
			
			break;
			 	
  }
	
  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";

}


/**
 * Output breadcrumb as an unorderd list with unique and first/last classes
 */
function elife_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];
  if (!empty($breadcrumb)) {
    // Provide a navigational heading to give context for breadcrumb links to
    // screen-reader users. Make the heading invisible with .element-invisible.
    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';
    $crumbs = '<ul class="breadcrumbs clearfix">';
    $array_size = count($breadcrumb);
    $i = 0;
    while ( $i < $array_size) {
      $crumbs .= '<li class="crumb breadcrumb-' . $i;
      if ($i == 0) {
        $crumbs .= ' first';
        $breadcrumb[$i] = l(t('eLife'), '<front>', array('html' => TRUE));
      }
      if ($i+1 == $array_size) {
        $crumbs .= ' last';
      }
      $crumbs .=  '"><span class="wrapper">' . $breadcrumb[$i] . '</span></li>';
      $i++;
    }
    $crumbs .= '</ul>';
    return $crumbs;
  }
}


/**
 * Override theme_form_element_label to add span element for custom radio buttons & checkboxes styling.
 */
function elife_form_element_label($variables) {
	$element = $variables['element'];
	$output = '';
	
  // This is also used in the installer, pre-database setup.
  $t = get_t();

  // If title and required marker are both empty, output no label.
  if ((!isset($element['#title']) || $element['#title'] === '') && empty($element['#required'])) {
    return '';
  }

  // If the element is required, a required marker is appended to the label.
  $required = !empty($element['#required']) ? theme('form_required_marker', array('element' => $element)) : '';

  $title = filter_xss_admin($element['#title']);

  $attributes = array();
  // Style the label as class option to display inline with the element.
  if ($element['#title_display'] == 'after') {
    $attributes['class'] = 'option';
  }
  // Show label only to screen readers to avoid disruption in visual flows.
  elseif ($element['#title_display'] == 'invisible') {
    $attributes['class'] = 'element-invisible';
  }

  if (!empty($element['#id'])) {
    $attributes['for'] = $element['#id'];
  }
  
  if ($element['#type'] == 'radio' || $element['#type'] == 'checkbox') {
  	$attributes['class'] .= ' option-' . drupal_html_class($element['#title']);
  	// Add extra span inside label for radio buttons & checkboxes.
  	$output = ' <label' . drupal_attributes($attributes) . '><span class="input-wrapper"></span><span class="label-wrapper">' . $t('!title !required', array('!title' => $title, '!required' => $required)) . "</span></label>\n";
  } 
  else {
  	// The leading whitespace helps visually separate fields from inline labels.
  	$output = ' <label' . drupal_attributes($attributes) . '><span class="label-wrapper">' . $t('!title !required', array('!title' => $title, '!required' => $required)) . "</span></label>\n";
  }
  
  return $output;
}


/**
* Override HTML for links. 
*/

function elife_link($vars) {

  // Allow #fragment links to be used via 'http://current/#fragment'
  if (strpos($vars['path'], 'http://current/#') === 0) {
    $vars['options']['fragment'] = str_replace('http://current/#', '', $vars['path']);
    $vars['path'] = '';
  }

  return '<a href="' . check_plain(url($vars['path'], $vars['options'])) . '"' . drupal_attributes($vars['options']['attributes']) . '>' . ($vars['options']['html'] ? $vars['text'] : check_plain($vars['text'])) . '</a>';
}

/**
 * Page preprocess hook
 */
function elife_preprocess_page(&$variables) {
  if(isset($variables['node'])) {
    $node = $variables['node'];
    if ($node->type == 'highwire_article' && $node->field_highwire_a_subcomponent[X][0]['value'] == 1) {
      $element = array(
        '#type' => 'html_tag',
        '#tag' => 'meta', 
        '#attributes' => array(
          'name' => 'robots', 
          'content' => 'noindex',
        ),
      );
      drupal_add_html_head($element, 'elife_noindex');
    }
  } 
}

/**
 * Available layouts.
 *
 * @return array
 *   Array of layouts
 */
function _elife_layouts() {
  return array(
    'normal' => 'all and (min-width: 768px)',
    'wide' => 'all and (min-width: 1220px)',
  );
}

/**
 * HTML preprocess hook
 */
function elife_preprocess_html(&$vars) {
  $path = drupal_get_path('theme', 'elife');
  $groups_css = array(
    99 => array(
      1 => $path . '/css/colors.css',
      2 => $path . '/css/alpha-reset.css',
      3 => $path . '/css/alpha-alpha.css',
      4 => $path . '/css/formalize.css',
      5 => $path . '/css/omega-text.css',
      6 => $path . '/css/omega-branding.css',
      7 => $path . '/css/omega-menu.css',
      8 => $path . '/css/omega-forms.css',
      9 => $path . '/css/omega-visuals.css',
      10 => $path . '/css/font-awesome.css',
    ),
    100 => array(
      1 => $path . '/css/elife-colorbox.css',
      2 => $path . '/css/global.css',
      3 => $path . '/css/elife-text.css',
      4 => $path . '/css/css3pie.css',
    ),
  );

  $layout = NULL;
  foreach ($groups_css as $group => $files) {
    $options = array(
      'media' => 'all',
      'group' => $group,
    );
    _elife_add_css_files($files, $layout, $options);
  }

  $files = array(
    1 => $path . '/css/print.css',
  );
  $options = array(
    'media' => 'print',
    'group' => 101,
  );
  _elife_add_css_files($files, $layout, $options);

  drupal_add_css($path . '/css/lte-ie8.css', array(
    'type' => 'file',
    'group' => 2000,
    'media' => 'all',
    'browsers' => array('IE' => 'lte IE 8', '!IE' => FALSE),
    'weight' => 100,
  ));

  // Introduce viewport meta attribute.
  $meta = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'viewport',
      'content' => 'width=device-width, initial-scale=1, maximum-scale=10, minimum-scale=1, user-scalable=yes',
    ),
  );

  drupal_add_html_head($meta, 'elife-viewport');

  $primary = 'normal';
  $layouts = _elife_layouts();

  $files = array(
    1 => $path . '/css/elife-default.css',
    2 => $path . '/css/elife-elife-default-normal.css',
    3 => $path . '/css/grid/elife_default/normal/elife-default-normal-32.css',
  );
  $layout = 'ie::' . $primary;
  $options = array(
    'media' => 'all',
    'browsers' => array('IE' => '(lt IE 9)&(!IEMobile)', '!IE' => FALSE),
    'group' => 1000,
  );
  _elife_add_css_files($files, $layout, $options);

  $layout = $primary;
  $options['media'] = $layouts[$layout];
  $options['browsers'] = array('IE' => 'gte IE 9', '!IE' => TRUE);
  $options['group'] += 100;
  _elife_add_css_files($files, $layout, $options);

  $files = array(
    1 => $path . '/css/elife-default.css',
    2 => $path . '/css/elife-elife-default-wide.css',
    3 => $path . '/css/grid/elife_default/wide/elife-default-wide-32.css',
  );
  $layout = 'wide';
  $options['media'] = $layouts[$layout];
  $options['group'] += 100;
  _elife_add_css_files($files, $layout, $options);

  drupal_add_js(array('omega' => array(
    'layouts' => array(
      'primary' => $primary,
      'order' => array_keys($layouts),
      'queries' => $layouts,
    ),
  )), 'setting');
}

function _elife_add_css_files($files, $layout = NULL, $options = array()) {
  $basename_prefix = (!empty($layout)) ? $layout . '::' : '';
  foreach ($files as $weight => $file) {
    $basename = $basename_prefix . $file;
    $options['data'] = $file;
    $options['basename'] = $basename;
    $options['weight'] = $weight;
    drupal_add_css($basename, $options);
  }
}

/**
 * Overrides theme_item_list().
 *
 * This offers the opportunity to add another class to the wrapping div of the
 * html list or to remove the wrapping div entirely
 */
function elife_item_list($variables) {
  $div_class = (!empty($variables['div_class'])) ? $variables['div_class'] : 'item-list';
  $items = $variables['items'];
  $title = $variables['title'];
  $type = $variables['type'];
  $attributes = $variables['attributes'];
  $first_last = (isset($variables['first_last']) && $variables['first_last'] === FALSE) ? FALSE : TRUE;

  // Only output the list container and title, if there are any list items.
  // Check to see whether the block title exists before adding a header.
  // Empty headers are not semantic and present accessibility challenges.
  // if div_class set to no then don't display wrapping div element
  $output = ($div_class != 'no') ? '<div class="' . $div_class  . '">' : '';
  if (isset($title) && $title !== '') {
    $output .= '<h3>' . $title . '</h3>';
  }

  if (!empty($items)) {
    $output .= "<$type" . drupal_attributes($attributes) . '>';
    $num_items = count($items);
    $i = 0;
    foreach ($items as $item) {
      $attributes = array();
      $children = array();
      $data = '';
      $i++;
      if (is_array($item)) {
        foreach ($item as $key => $value) {
          if ($key == 'data') {
            $data = $value;
          }
          elseif ($key == 'children') {
            $children = $value;
          }
          else {
            $attributes[$key] = $value;
          }
        }
      }
      else {
        $data = $item;
      }
      if (count($children) > 0) {
        // Render nested list.
        $data .= theme_item_list(array('items' => $children, 'title' => NULL, 'type' => $type, 'attributes' => $attributes));
      }
      if ($first_last) {
        if ($i == 1) {
          $attributes['class'][] = 'first';
        }
        if ($i == $num_items) {
          $attributes['class'][] = 'last';
        }
      }
      $output .= '<li' . drupal_attributes($attributes) . '>' . $data . "</li>\n";
    }
    $output .= "</$type>";
  }
  // if div_class set to no then don't display wrapping div element
  $output .= ($div_class != 'no') ? '</div>' : '';
  return $output;
}

/**
 * Implements hook_css_alter().
 */
function elife_css_alter(&$css) {
  // Hide the empty placeholder css files.
  $layout = 'empty';
  foreach($css as $key => $item) {
    if ((isset($item['basename']) && preg_match('/^' . $layout . '::/', $item['basename']))
      || preg_match('/elife\-default\-' . $layout . '/', $item['data'])) {
      unset($css[$key]);
    }
  }
}
