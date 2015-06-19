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
 */
/**
 * Overrides theme_item_list().
 *
 * This offers the opportunity to add another class to the wrapping div of the
 * html list or to remove the wrapping div entirely
 */
function elife_newlook_item_list($variables) {
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
