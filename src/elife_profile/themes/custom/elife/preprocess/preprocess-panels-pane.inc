<?php

/**
 * Add class for color coding category pane
 */
if (isset($vars['content']['#field_name']) && $vars['content']['#field_name'] ==  'field_highwire_article_category') {
  // Grab first tid if it exists
  if ($vars['content']['#items'][0]['tid'] >= 1 ) {
    $tid = $vars['content']['#items'][0]['tid'];
    $term = taxonomy_term_load($tid);
    $name = $term->name;
    $vars['classes_array'][] = 'elife-cat-' . drupal_html_class($name);
  } 
}