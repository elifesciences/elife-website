<?php
/**
 * @file
 * plugins/content_types/elife_article_listing.inc
 *
 * Prepare a ctools plugin to provide a display for the elife article items for
 * the listings pages
 */

$plugin = array(
  'single' => TRUE,
  'icon' => 'icon_node_form.png',
  'title' => t('eLife Article Listing'),
  'description' => t('Show rendered eLife article capsule.'),
  'category' => t('eLife'),
  'edit form' => 'elife_article_listing_plugin_edit',
  'render callback' => 'elife_article_listing_plugin_render',
  'required context' => new ctools_context_required(t('Article Node'), 'node'),
);

/**
 * Return the elife article items in the elife_article_capsule template.
 */
function elife_article_listing_plugin_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->title = t('eLife Article capsule');

  /* @var EntityDrupalWrapper $ewrapper */
  $ewrapper = entity_metadata_wrapper('node', $context->data);
  $variables['title'] = l($ewrapper->title->value(), 'node/' . $ewrapper->nid->value(), array('html' => TRUE));

  $block->content = $variables['title'];
  return $block;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_listing_plugin_edit($form, &$form_state) {
  $conf = $form_state['conf'];
  return $form;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_listing_plugin_edit_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}
