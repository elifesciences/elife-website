<?php

$plugin = array(
  'title' => t('Article Markup for DOI'),
  'single' => TRUE,
  'category' => array('eLife'),
  'edit form' => 'elife_article_markup_doi_edit',
  'render callback' => 'elife_article_markup_doi_render',
  'required context' => new ctools_context_required('Article / Fragment Node', 'node'),
);

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function elife_article_markup_doi_render($subtype, $conf, $args, $context) {
  $node = $context->data;

  /* @var EntityDrupalWrapper $ewrapper */
  if ($ewrapper = entity_metadata_wrapper('node', $node)) {
    if (in_array($ewrapper->getBundle(), ['elife_article_ver', 'elife_fragment'])) {

      $doi = $ewrapper->field_elife_a_doi->value();
      $article_id = $ewrapper->field_elife_a_parent->field_elife_a_article_id->value();
      $article_id = _elife_article_process_article_id($article_id);

      $markup = elife_article_markup_service();
      $markup->addDoiQuery($article_id, $doi);
      $markup = _elife_article_markup_query($markup);
      $html = $markup->output();

      if ($html) {
        $block = new stdClass();
        $block->content = $html;

        return $block;
      }
    }
  }
}

/**
 * Edit form callback for the content type.
 */
function elife_article_markup_doi_edit($form, &$form_state) {
  return $form;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_markup_doi_edit_form_submit(&$form, &$form_state) {
  // Nothing.
}
