<?php

/**
 * @file
 * elife_article_affiliation.inc
 */

use eLife\EIF\ArticleVersion;
use eLife\EIF\ArticleVersion\Affiliation;
use eLife\EIF\ArticleVersion\Contributor;
use eLife\EIF\ArticleVersion\Contributor\CollabContributor;
use eLife\EIF\ArticleVersion\Contributor\PersonContributor\BylineContributor;

$plugin = array(
  'title' => t('Article Affiliation'),
  'single' => TRUE,
  'description' => t('Show Article Affiliation.'),
  'category' => array('eLife'),
  'edit form' => 'elife_article_affiliation_edit',
  'render callback' => 'elife_article_affiliation_render',
  'required context' => new ctools_context_required('Article Node', 'node'),
);

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function elife_article_affiliation_render($subtype, $conf, $args, $context) {
  $article_version = $context->data;
  $dto = elife_article_version_to_dto($article_version);

  $affiliations = _elife_article_affiliation_list($dto);

  if (!empty($affiliations)) {
    $block = new stdClass();
    $block->title = t('Affiliation details');
    $block->content = '<div class="elife-institutions-list">' . implode('; ', $affiliations) . '</div>';
    return $block;
  }

}

function _elife_article_affiliation_list(ArticleVersion $dto) {
  $cache = _elife_article_affiliation_list_cache($dto);

  return $cache[$dto->getArticleVersionId()];
}

function _elife_article_affiliation_list_cache(ArticleVersion $dto) {
  $cache = &drupal_static(__FUNCTION__, []);

  if (!isset($cache[$dto->getArticleVersionId()])) {
    $affiliations_markup = [];
    $contributors = $dto->getContributors();
    if (!empty($contributors)) {
      $affiliations = [];
      $referenced_affs = $dto->getReferenced()->getAffiliation();
      foreach ($contributors as $co => $contributor) {
        if ($contributor->getType() != 'author') {
          continue;
        }
        if ($contributor instanceof BylineContributor || $contributor instanceof CollabContributor) {
          foreach ($contributor->getAffiliations() as $affiliation) {
            _elife_article_affiliation_list_process_item($affiliations, $affiliation, $co);
          }
          if ($references = $contributor->getReferences()) {
            if (!empty($references['affiliation'])) {
              foreach ($references['affiliation'] as $aff_id) {
                if (isset($referenced_affs[$aff_id])) {
                  _elife_article_affiliation_list_process_item($affiliations, $referenced_affs[$aff_id], $co);
                }
              }
            }
          }
        }
      }
      if (!empty($affiliations)) {
        foreach ($affiliations as $key => $affiliation) {
          $affiliations_markup[] = '<span class="elife-institution ' . implode(' ', $affiliations[$key]['positions']) . '">' . $affiliations[$key]['markup'] . '</span>';
        }
      }
    }
    $cache[$dto->getArticleVersionId()] = $affiliations_markup;
  }

  return $cache;
}

function _elife_article_affiliation_list_process_item(&$affiliations, Affiliation $affiliation, $pos) {
  $item_pos = 'item-' . $pos;
  $aff_name = [];
  $aff_str = '';
  if ($institution = $affiliation->getInstitution()) {
    $aff_name['institution'] = $institution;
  }
  if ($country = $affiliation->getCountry()) {
    $aff_name['country'] = $country;
  }

  if (!empty($aff_name)) {
    $aff = [];
    foreach ($aff_name as $k => $n) {
      $aff[] = '<span class="' . $k . '">' . $n . '</span>';
      $aff_str .= $n;
    }
  }
  if (!empty($aff)) {
    $aff_str = preg_replace('/[^A-z0-9]/', '', $aff_str);
    if (empty($affiliations[$aff_str])) {
      $affiliations[$aff_str]['markup'] = implode(', ', $aff);
    }
    if (empty($affiliations[$aff_str]['positions']) || !in_array($item_pos, $affiliations[$aff_str]['positions'])) {
      $affiliations[$aff_str]['positions'][] = $item_pos;
    }
  }
}

/**
 * Edit form callback for the content type.
 */
function elife_article_affiliation_edit($form, &$form_state) {
  return $form;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_affiliation_edit_submit(&$form, &$form_state) {
  // Nothing.
}
