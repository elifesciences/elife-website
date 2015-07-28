<?php

use Drupal\elife_article\ElifeArticleVersion;
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

      if (!$fragment) {
        $article = ElifeArticleVersion::getArticle($article_version->getArticleId());
        $related_articles = ElifeArticleVersion::retrieveRelatedArticles($article->nid, TRUE, TRUE, 1, 0);
        foreach ($related_articles as $related_article) {
          if ($related_article->article_type == 'corrected-article') {
            // Check if one endpoint has a display channel of Retraction.
            if (in_array('Retraction', $related_article->endpoint_types)) {
              if ($related_article->endpoints_flag == '1') {
                $label = t('View the retracted article');
              }
              else {
                $label = t('This article has been retracted');
              }
            }
            else {
              if ($related_article->endpoints_flag == '1') {
                $label = t('View the corrected article');
              }
              else {
                $label = t('This article has been corrected');
              }
            }

            $output .= '<span class="elife-article-correction">';
            $output .= l($label, 'node/' . $related_article->{$related_article->related_to_endpoint . '_article_ver_nid'});
            $output .= '</span>';
          }
        }
      }

      foreach ($doi_links as $label => $doi_link) {
        $output .= '<div class="pane-elife-doi">';
        $output .= '<span class="elife-doi-doi">';
        $output .= '<span class="elife-doi-pre-label label">' . $label . ': </span>';
        $output .= '<span class="elife-doi-doi">' . $doi_link . '</span>';
        $output .= '</span>';
        $output .= '</div>';
      }

      if (!$fragment) {
        $output .= '<span class="elife-doi-epubdate">';
        $output .= '<span class="elife-doi-epubdate-label label">' . t('Published') . '</span> ';
        $output .= '<span class="elife-doi-epubdate-data">' . ($article_version->getPubDate() ? $article_version->getPubDate()->format('F j, Y') : t('N/A')) . '</span>';
        $output .= '</span>';
        $output .= '<span class="elife-doi-cite-as">';
        $output .= '<span class="elife-doi-cite-as-label label">' . t('Cite as') . '</span> ';
        $output .= '<span class="elife-doi-cite-as-data">' . $article_version->getCiteAs() . '</span>';
        $output .= '</span>';
      }


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
