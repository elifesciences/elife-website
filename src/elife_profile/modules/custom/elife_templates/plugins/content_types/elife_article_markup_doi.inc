<?php

use eLife\EIF\ArticleVersion\Fragment;

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
      if ($ewrapper->field_elife_a_parent->raw()) {
        $article_version = elife_article_version_to_dto($ewrapper->field_elife_a_parent->value());
        $fragment = $article_version->getFragment($ewrapper->field_elife_a_doi->value());
        if ($fragment instanceof Fragment) {
          $fragment_type = $fragment->getType();
        }
        else {
          $fragment_type = 'sub-article';
        }

        $doi = $ewrapper->field_elife_a_doi->value();
        $article_version_id = $ewrapper->field_elife_a_parent->field_elife_a_article_version_id->value();

        $markup = elife_article_markup_service();
        $markup->addDoiQuery($article_version_id, $doi);
        $markup = _elife_article_markup_query($markup, TRUE, TRUE);
        $html = $markup->output();

        if ($html) {
          elife_templates_article_page_markup_assets();
          $block = new stdClass();
          $block->content = '<div class="fragment-type--' . $fragment_type . '">' . $html . '</div>';

          return $block;
        }
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
