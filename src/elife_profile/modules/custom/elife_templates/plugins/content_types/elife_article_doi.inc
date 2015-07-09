<?php

use eLife\EIF\ArticleVersion\SubArticle;
use eLife\EIF\ArticleVersion\Fragment;

$plugin = array(
  'title' => t('Article / Fragment - DOI, date, corrections, and other info'),
  'single' => TRUE,
  'category' => array('eLife'),
  'edit form' => 'elife_article_doi_edit',
  'render callback' => 'elife_article_doi_render',
  'required context' => new ctools_context_required('Article / Fragment Node', 'node'),
);

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function elife_article_doi_render($subtype, $conf, $args, $context) {
  $node = $context->data;

  /* @var EntityDrupalWrapper $ewrapper */
  if ($ewrapper = entity_metadata_wrapper('node', $node)) {
    // @todo - elife - nlisgo - output correction links
    $output = '';

    if (in_array($ewrapper->getBundle(), ['elife_article_ver', 'elife_fragment'])) {
      if ($ewrapper->field_elife_a_parent->raw()) {
        $article_version = elife_article_version_to_dto($ewrapper->field_elife_a_parent->value());
        $fragment = $article_version->getFragment($ewrapper->field_elife_a_doi->value());
      }
      else {
        $article_version = elife_article_version_to_dto($node);
        $fragment = FALSE;
      }

      if ($fragment) {
        $label = t('@type DOI', array('@type' => t('Article')));
        $doi = 'http://dx.doi.org/' . $fragment->getDoi();
        $doi_link = l($doi, $doi);
        $output .= '<div class="pane-elife-doi">';
        $output .= '<span class="elife-doi-doi"><span class="elife-doi-pre-label label">' . $label . ': </span><span class="elife-doi-doi">' . $doi_link . '</span></span>';
        $output .= '</div>';
      }

      $label = t('DOI');
      // Now print DOI and other misc info.
      if ($fragment && $fragment instanceof SubArticle) {
        $label = t('@type DOI', array('@type' => $fragment->getTitle()));
      }
      elseif ($fragment && $fragment instanceof Fragment) {
        $map = array(
          'table-wrap' => 'Table',
          'fig' => 'Figure',
          'abstract' => array(
            'Abstract' => 'Abstract',
            'eLife digest' => 'eLife digest',
          ),
          'media' => 'Media',
          'chem' => 'Chemical',
          'supplementary-material' => 'Source data',
        );

        $frag_type = $fragment->getType();

        if (array_key_exists($frag_type, $map)) {
          $label_type = $map[$frag_type];
          if (is_array($label_type)) {
            $label_type = $label_type[$fragment->getTitle()];
          }
          $label = t('@type DOI', array('@type' => $label_type));
        }
      }

      if ($fragment) {
        $doi = $fragment->getDoi();
      }
      else {
        $doi = $article_version->getDoi();
      }

      $output .= '<div class="pane-elife-doi">';

      $doi = 'http://dx.doi.org/' . $doi;
      $doi_link = l($doi, $doi);

      $output .= '<span class="elife-doi-doi"><span class="elife-doi-pre-label label">' . $label . ': </span><span class="elife-doi-doi">' . $doi_link . '</span></span>';

      // @todo - elife - nlisgo - introduce cite as value if main article page

      $output .= '</div>';

      $block = new stdClass();
      $block->content = $output;

      return $block;
    }
  }

}

/**
 * Edit form callback for the content type.
 */
function elife_article_doi_edit($form, &$form_state) {
  return $form;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_doi_edit_form_submit(&$form, &$form_state) {
  // Nothing.
}
