<?php
/**
 * @file
 * elife_article_podcasts.inc
 */

use Drupal\elife_article\ElifeArticleVersion;

$plugin = array(
  'title' => t('Article Podcasts'),
  'single' => TRUE,
  'description' => t(''),
  'category' => array('eLife'),
  'edit form' => 'elife_article_podcasts_edit',
  'render callback' => 'elife_article_podcasts_render',
  'required context' => new ctools_context_required('Article Node', 'node'),
);

/**
 * Implements ctools plugin render callback function.
 */
function elife_article_podcasts_render($subtype, $conf, $args, $context) {
  $node = $context->data;

  $article_id = $node->field_elife_a_article_id[LANGUAGE_NONE][0]['value'];
  $article_reference = elife_article_reference_for_article_id($article_id);

  if (!$article_reference) {
    return NULL;
  }

  $view = views_get_view('elife_article_podcast');

  $content = $view->preview('block_1', [$article_reference->nid]);

  if (empty($view->result)) {
    return NULL;
  }

  $block = new stdClass();
  $block->title = t('Multimedia');
  $block->content = $content;

  return $block;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_podcasts_edit($form, &$form_state) {
  return $form;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_podcasts_edit_form_submit(&$form, &$form_state) {
  // Nothing.
}
