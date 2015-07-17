<?php

use eLife\EIF\ArticleVersion\BaseFragment;
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
    $output = '';

    // @todo - elife - nlisgo - output correction links

    if (in_array($ewrapper->getBundle(), ['elife_article_ver', 'elife_fragment'])) {
      if ($ewrapper->field_elife_a_parent->raw()) {
        $article_version = elife_article_version_to_dto($ewrapper->field_elife_a_parent->value());
        $fragment = $article_version->getFragment($ewrapper->field_elife_a_doi->value());
      }
      else {
        $article_version = elife_article_version_to_dto($node);
        $fragment = FALSE;
      }

      $doi_links = [];
      if ($fragment instanceof BaseFragment) {
        if ($fragment instanceof Fragment && $ewrapper->field_elife_a_parent_sub->raw()) {
          $doi = 'http://dx.doi.org/' . $ewrapper->field_elife_a_parent_sub->field_elife_a_doi->value();
        }
        else {
          $doi = $article_version->getDoiUrl();
        }
        $label = t('@type DOI', array('@type' => t('Article')));
        $doi_link = l($doi, $doi);
        $doi_links[$label] = $doi_link;
      }

      // Now prepare DOI label for page that is being viewed.
      if ($fragment instanceof SubArticle) {
        $label = t('@type DOI', array('@type' => $fragment->getTitle()));
      }
      elseif ($fragment instanceof Fragment) {
        $map = array(
          'table-wrap' => t('Table'),
          'boxed-text' => t('Box'),
          'fig' => t('Figure'),
          'media' => t('Media'),
          'chem' => t('Chemical'),
          'supplementary-material' => t('Source data'),
        );

        $frag_type = $fragment->getType();

        $label_type = array_key_exists($frag_type, $map) ? $map[$frag_type] : $fragment->getTitle();

        $label = t('@type DOI', array('@type' => $label_type));
      }
      else {
        $label = t('DOI');
      }

      $doi = ($fragment instanceof BaseFragment) ? $fragment->getDoiUrl() : $article_version->getDoiUrl();
      $doi_link = l($doi, $doi);
      $doi_links[$label] = $doi_link;

      foreach ($doi_links as $label => $doi_link) {
        $output .= '<div class="pane-elife-doi">';
        $output .= '<span class="elife-doi-doi">';
        $output .= '<span class="elife-doi-pre-label label">' . $label . ': </span>';
        $output .= '<span class="elife-doi-doi">' . $doi_link . '</span>';
        $output .= '</span>';
        $output .= '</div>';
      }

      // @todo - elife - nlisgo - introduce cite as value if main article page

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
