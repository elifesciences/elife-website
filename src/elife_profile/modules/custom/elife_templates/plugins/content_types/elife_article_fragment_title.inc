<?php

/**
 * @file
 * elife_article_fragment_title.inc
 */

$plugin = array(
  'title' => t('Fragment - Title'),
  'single' => TRUE,
  'category' => array('eLife'),
  'edit form' => 'elife_article_fragment_title_edit',
  'render callback' => 'elife_article_fragment_title_render',
  'required context' => new ctools_context_required('Fragment Node', 'node'),
);

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function elife_article_fragment_title_render($subtype, $conf, $args, $context) {
  $node = $context->data;
  /* @var EntityDrupalWrapper $ewrapper */
  $ewrapper = entity_metadata_wrapper('node', $node);

  $block = new stdClass();

  $block->content  = '<div class="elife-article-indicators">';
  $block->content .= '<h2 class="page-title">' . $ewrapper->title->value() . '</h2>';
  $block->content .= '</div>';
  return $block;
}

/**
 * 'Edit form' callback for the content type.
 */
function elife_article_fragment_title_edit($form, &$form_state) {
  return $form;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_fragment_title_edit_form_submit(&$form, &$form_state) {
  // Nothing.
}
