<?php

$plugin = array(
  'title' => t('Article Figure & Data'),
  'single' => TRUE,
  'category' => array('eLife'),
  'edit form' => 'elife_article_fig_data_edit',
  'render callback' => 'elife_article_fig_data_render',
  'required context' => new ctools_context_required('Article Node', 'node'),
);

/**
 * Run-time rendering of the body of the block (content type).
 */
function elife_article_fig_data_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->title = t('Article Figures & Data');
  $block->content = t('Figures & Data');
  return $block;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_fig_data_edit($form, &$form_state) {
  return $form;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_fig_data_edit_submit(&$form, &$form_state) {
  // Nothing.
}
