<?php

/**
 * @file
 * elife_article_title.inc
 */

$plugin = array(
  'title' => t('Article - Title'),
  'single' => TRUE,
  'category' => array('eLife'),
  'edit form' => 'elife_article_title_edit',
  'render callback' => 'elife_article_title_render',
  'required context' => new ctools_context_required('Article Node', 'node'),
);

/**
 * Run-time rendering of the body of the block (content type).
 *
 * See ctools_plugin_examples for more advanced info.
 */
function elife_article_title_render($subtype, $conf, $args, $context) {
  $article_version = $context->data;
  $dto = elife_article_version_to_dto($article_version);

  $block = new stdClass();
  $block->content  = '<div class="elife-article-indicators clearfix">';

  $block->content .= '</div>';
  if ($dto->getStatus() == 'POA') {
    $block->content .= '<h3>' . t('ACCEPTED MANUSCRIPT') . '</h3>';
  }

  // If it's not a research article, check to see if it's a feature.
  // Identify the proper prefix to appear in the title:
  $title_prefix = '';

  $categories = $dto->getCategories();
  if (!empty($categories['sub-display-channel'])) {
    $title_prefix .= implode(': ', $categories['sub-display-channel']) . ': ';
  }

  // Now append the actual title (this version of it can contain HTML).
  $title_text = $dto->getTitle();

  $block->content .= '<h1 class="page-title">' . $title_prefix . $title_text . '</h1>';
  return $block;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_title_edit($form, &$form_state) {
  return $form;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_title_edit_form_submit(&$form, &$form_state) {
  // Nothing.
}
