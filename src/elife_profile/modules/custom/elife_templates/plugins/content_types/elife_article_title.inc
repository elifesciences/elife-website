<?php

/**
 * @file
 * elife_article_title.inc
 */

use Drupal\elife_article\ElifeArticleVersion;

$plugin = array(
  'title' => t('Article - Title'),
  'single' => TRUE,
  'category' => array('eLife'),
  'edit form' => 'elife_article_title_edit',
  'render callback' => 'elife_article_title_render',
  'required context' => new ctools_context_required('Article Node', 'node'),
);

define('ELIFE_TEMPLATES_URL_CREATIVECOMMONS', 'https://creativecommons.org');
define('ELIFE_TEMPLATES_URL_OPEN_ACCESS', 'http://en.wikipedia.org/wiki/Open_access');

/**
 * Run-time rendering of the body of the block (content type).
 *
 * See ctools_plugin_examples for more advanced info.
 */
function elife_article_title_render($subtype, $conf, $args, $context) {
  $article_version = $context->data;
  $dto = elife_article_version_to_dto($article_version);

  $pdf_path = elife_article_version_source_pdf_local($article_version, TRUE);
  $pdf_path_remote = elife_article_version_source_pdf_path($article_version);
  $pdf_head = array_change_key_case(get_headers($pdf_path_remote, TRUE));
  if (empty($pdf_head['content-length'])) {
    $pdf_path = FALSE;
  }

  $figures_pdf_path = elife_article_version_source_figures_pdf_local($article_version, TRUE);
  $figures_pdf_path_remote = elife_article_version_source_figures_pdf_path($article_version);
  $figures_pdf_head = array_change_key_case(get_headers($figures_pdf_path_remote, TRUE));
  if (empty($figures_pdf_head['content-length'])) {
    $figures_pdf_path = FALSE;
  }

  // Add JS for icon cluetips.
  drupal_add_library('cluetip', 'cluetip');
  drupal_add_js(drupal_get_path('module', 'elife_templates') . '/js/elife_article_title.js');

  $block = new stdClass();
  $block->content = '<div class="elife-article-indicators clearfix">';

  $img_oa = theme('image', array(
      'alt' => t('Open access'),
      'title' => t('Open access'),
      'path' => drupal_get_path('module', 'elife_templates') . '/images/oa.png',
    )
  );
  $block->content .= l($img_oa, ELIFE_TEMPLATES_URL_OPEN_ACCESS, array('html' => TRUE));

  $markup = elife_article_markup_service();
  $markup->addSectionQuery($dto->getArticleVersionId(), 'cc-link');
  $markup = _elife_article_markup_query($markup);
  $cc_link = trim($markup->output());
  if (empty($cc_link)) {
    $cc_link = ELIFE_TEMPLATES_URL_CREATIVECOMMONS;
  }

  $img_cc = theme('image', array(
      'alt' => t('Copyright info'),
      'title' => t('Copyright info'),
      'path' => drupal_get_path('module', 'elife_templates') . '/images/cc.png',
    )
  );
  $block->content .= l($img_cc, $cc_link, array('html' => TRUE));

  if ($pdf_path) {
    $img_pdf = theme('image', array(
        'alt' => t('Download PDF'),
        'width' => 22,
        'attributes' => array('class' => 'visible-small'),
        'title' => t('Download PDF'),
        'path' => drupal_get_path('module', 'elife_templates') . '/images/pdf.png',
      )
    );

    $block->content .= l($img_pdf, $pdf_path, array(
        'external' => TRUE,
        'html' => TRUE,
        'attributes' => array(
          'title' => t('PDF'),
          'class' => array('pdf-download'),
          'type' => 'application/pdf',
          'rel' => 'alternative',
          'data-article-identifier' => $dto->getDoi(),
          'data-download-type' => 'pdf-article',
        ),
      )
    );
  }

  if ($figures_pdf_path) {
    $img_figs = theme('image', array(
        'alt' => t('Download figures'),
        'width' => 22,
        'attributes' => array('class' => 'visible-small'),
        'title' => t('Download figures'),
        'path' => drupal_get_path('module', 'elife_templates') . '/images/figs.png',
      )
    );

    $block->content .= l($img_figs, $figures_pdf_path, array(
        'external' => TRUE,
        'html' => TRUE,
        'attributes' => array(
          'title' => t('Figures'),
          'class' => array('figures-download'),
          'type' => 'application/pdf',
          'rel' => 'alternative',
          'data-article-identifier' => $dto->getDoi(),
          'data-download-type' => 'pdf-figures',
        ),
      )
    );
  }

  $article = ElifeArticleVersion::getArticle($dto->getArticleId());
  $related_articles = ElifeArticleVersion::retrieveRelatedArticles($dto->getDoi(), TRUE, TRUE, NULL, 0);
  if (!empty($related_articles)) {
    $img_related = theme('image', array(
        'alt' => t('Related content'),
        'width' => 20,
        'attributes' => array('class' => 'visible-small'),
        'title' => t('Related content'),
        'path' => drupal_get_path('module', 'elife_templates') . '/images/related.gif',
      )
    );

    $block->content .= l($img_related, 'node/' . $article_version->nid, array(
        'html' => TRUE,
        'fragment' => 'related-content',
        'attributes' => array(
          'title' => t('Related content'),
          'rel' => '#related-content',
          'class' => array('js-trigger-cluetip', 'related-content'),
        ),
      )
    );
  }

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
  $title_text = $article_version->field_elife_title[LANGUAGE_NONE][0]['safe_value'];

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
