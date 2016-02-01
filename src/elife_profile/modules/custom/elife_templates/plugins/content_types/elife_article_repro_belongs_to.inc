<?php

/**
 * @file
 * elife_templates/plugins/content_types/elife_article_repro_belongs_to.inc
 */

use Drupal\elife_article\ElifeArticleVersion;

$plugin = array(
  'title' => t('eLife Reproducibility - belongs to'),
  'single' => TRUE,
  'category' => array('eLife'),
  'edit form' => 'elife_article_repro_belongs_to_edit',
  'render callback' => 'elife_article_repro_belongs_to_render',
  'required context' => new ctools_context_required('Article Node', 'node'),
);

/**
 * Run-time rendering of the body of the block (content type).
 *
 * See ctools_plugin_examples for more advanced info
 */
function elife_article_repro_belongs_to_render($subtype, $conf, $args, $context) {
  $article_version = $context->data;
  $block = new stdClass();

  if ($dto = elife_article_version_to_dto($article_version)) {
    $keywords = $dto->getKeywords();
    if (!empty($keywords['author-keywords']) && in_array('reproducibility project: cancer biology', array_map('strtolower', $keywords['author-keywords']))) {
      elife_article_repro_belongs_to_setup_once();
      $block->content = theme('elife_article_repro_belongs_to');
    }
  }

  return $block;
}

/**
 * Setup that just needs to be run once.
 */
function elife_article_repro_belongs_to_setup_once() {
  $cache = &drupal_static(__FUNCTION__, FALSE);

  if (empty($cache)) {
    $cache = TRUE;
    drupal_add_css(drupal_get_path('module', 'elife_templates') . '/css/elife-repro-belongs-to.css');
  }

  return $cache;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_repro_belongs_to_edit($form, &$form_state) {
  return $form;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_repro_belongs_to_edit_submit(&$form, &$form_state) {
  // Nothing.
}
