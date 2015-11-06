<?php

/**
 * @file
 * elife_article_authors.inc
 */

use eLife\EIF\ArticleVersion;
use eLife\EIF\ArticleVersion\Contributor;
use eLife\EIF\ArticleVersion\Contributor\OnBehalfOfContributor;
use eLife\EIF\ArticleVersion\Contributor\PersonContributor;
use eLife\EIF\ArticleVersion\Contributor\PersonContributor\BylineContributor;
use eLife\EIF\ArticleVersion\Contributor\CollabContributor;

$plugin = array(
  'title' => t('Article Authors'),
  'single' => TRUE,
  'description' => t('Show Article Authors.'),
  'category' => array('eLife'),
  'edit form' => 'elife_article_authors_edit',
  'render callback' => 'elife_article_authors_render',
  'required context' => new ctools_context_required('Article Node', 'node'),
);

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function elife_article_authors_render($subtype, $conf, $args, $context) {
  drupal_add_js(drupal_get_path('module', 'elife_templates') . '/js/elife_article_authors.js');
  $article_version = $context->data;
  $dto = elife_article_version_to_dto($article_version);

  $block = new stdClass();

  $authors = [];
  $contributors = $dto->getContributors();
  if (!empty($contributors)) {
    foreach ($contributors as $co => $contributor) {
      $name = [];
      if ($contributor instanceof BylineContributor) {
        if ($contributor->getType() != 'author') {
          continue;
        }
        $name = $contributor->getNameParts();
      }
      elseif ($contributor instanceof CollabContributor) {
        if ($collab = $contributor->getName()) {
          $name['collab'] = $collab;
        }
      }
      elseif ($contributor instanceof OnBehalfOfContributor) {
        if ($on_behalf_of = $contributor->getName()) {
          $name['on-behalf-of'] = $on_behalf_of;
        }
      }

      if (!empty($name)) {
        $author = [];
        foreach ($name as $k => $n) {
          $author[] = '<span class="' . $k . '">' . $n . '</span>';
        }

        $class = [
          'elife-article-author-item',
        ];

        if ($contributor instanceof Contributor) {

          if ($contributor->isCorresp() == 'yes') {
            $author[] = theme('image', array(
              'path' => drupal_get_path('module', 'elife_templates') . '/images/corresp.png',
              'attributes' => array(
                'class' => array(
                  'corresp-icon',
                ),
              )));
            $class[] = 'corresp';
          }
        }

        // @todo - elife - nlisgo - this should use theme_item_list
        $authors[] = '<li class="' . implode(' ', $class) . '" data-affiliation="item-' . $co . '">' . implode(' ', $author) . '</li>';
      }
    }
  }

  if (!empty($authors)) {
    $block->title = t('Article Authors');
    $block->content = '<div class="author-list"><ul>' . implode("\n", $authors) . '</ul></div>';
  }

  return $block;
}

/**
 * Get affiliations for the ArticleVersion.
 *
 * @param ArticleVersion $article_version
 *   Ensure that we only process the article author affiliations once.
 *
 * @return mixed
 *   Article affiliations for this article version.
 */
function _elife_article_authors_affiliation(ArticleVersion $article_version) {
  $affiliations = _elife_article_authors_affiliation_cache($article_version);
  return $affiliations[$article_version->getArticleVersionId()];
}

/**
 * Build up array of cached article affiliations.
 *
 * @param ArticleVersion $article_version
 *   Ensure that we only process the article author affiliations once.
 *
 * @return mixed
 *   Article affiliations.
 */
function _elife_article_authors_affiliation_cache(ArticleVersion $article_version) {
  $affiliations = &drupal_static(__FUNCTION__, []);
  if (!isset($affiliations[$article_version->getArticleVersionId()])) {

    $article_version_id = $article_version->getArticleVersionId();
    $referenced = $article_version->getReferenced();
    foreach ($referenced->getAffiliation() as $key => $affiliation) {
      $markup = elife_article_markup_service();
      $markup->addAffiliationQuery($article_version_id, $key);
      $markup = _elife_article_markup_query($markup);
      $affiliations[$article_version_id][$key] = $markup->output();
    }
  }

  return $affiliations;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_authors_edit($form, &$form_state) {
  return $form;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_authors_edit_submit(&$form, &$form_state) {
  // Nothing.
}
