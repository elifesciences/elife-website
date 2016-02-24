<?php

/**
 * @file
 * plugins/content_types/elife_content_alert.inc
 */

use Drupal\elife_article\ElifeArticleVersion;
use eLife\EIF\ArticleVersion\Contributor\CollabContributor;
use eLife\EIF\ArticleVersion\Contributor\OnBehalfOfContributor;
use eLife\EIF\ArticleVersion\Contributor\PersonContributor\BylineContributor;

$plugin = array(
  'title' => t('Article - Content Alert'),
  'single' => TRUE,
  'description' => t('Show Content Alert.'),
  'category' => array('eLife'),
  'edit form' => 'elife_content_alert_edit',
  'render callback' => 'elife_content_alert_render',
  'required context' => new ctools_context_required('Article Node', 'node'),
);

/**
 * Run-time rendering of the body of the block (content type).
 *
 * See ctools_plugin_examples for more advanced info.
 */
function elife_content_alert_render($subtype, $conf, $args, $context) {
  $article_version = $context->data;
  $dto = elife_article_version_to_dto($article_version);

  $query = _elife_content_alerts_query();

  $variables = [
    'url' => url('node/' . $article_version->nid, ['absolute' => TRUE, 'query' => $query]),
    'title' => $dto->getTitle(),
  ];

  $contributors = $dto->getContributors();
  $contributor_items = [];
  if (!empty($contributors)) {
    foreach ($contributors as $co => $contributor) {

      if ($contributor instanceof BylineContributor) {
        if ('author' !== $contributor->getType()) {
          continue;
        }
        // Ok.
      }
      elseif ($contributor instanceof CollabContributor) {
        // Ok.
      }
      elseif ($contributor instanceof OnBehalfOfContributor) {
        // Ok.
      }
      else {
        continue;
      }

      if (!empty($contributor->getName())) {
        $contributor_items[] = $contributor->getName();
      }
    }

    if (count($contributor_items) > 1) {
      $last_contributors = [];
      $last_contributors[] = array_pop($contributor_items);
      $last_contributors[] = array_pop($contributor_items);
      $last_contributors = array_reverse($last_contributors);
      $contributor_items[] = implode(t(' and '), $last_contributors);
    }

    if (!empty($contributor_items)) {
      $variables['contributors'] = implode(', ', $contributor_items);
    }
  }

  if (!empty($dto->getImpactStatement())) {
    $variables['impact_statement'] = $dto->getImpactStatement();
  }

  $article = ElifeArticleVersion::getArticle($dto->getArticleId());
  // Get related articles.
  if ($related_articles = ElifeArticleVersion::retrieveRelatedArticles($dto->getDoi(), TRUE, TRUE)) {
    $related_nids = [];
    foreach ($related_articles as $related_article) {
      $related_nids[] = $related_article->endpoints->related_to->article_ver_nid;
    }
    if ($related_nodes = node_load_multiple($related_nids)) {
      $related_items = [];
      foreach ($related_nodes as $related_node) {
        $related_dto = elife_article_version_to_dto($related_node);
        $related_display_channels = $related_dto->getDisplayChannels();
        $related_display_channel = reset($related_display_channels);
        $related_contributors = $related_dto->getContributors();
        $related_contributor_items = [];
        foreach ($related_contributors as $co => $contributor) {
          if ($contributor instanceof BylineContributor) {
            if ('author' !== $contributor->getType()) {
              continue;
            }
            // Ok.
          }
          elseif ($contributor instanceof CollabContributor) {
            // Ok.
          }
          elseif ($contributor instanceof OnBehalfOfContributor) {
            // Ok.
          }
          else {
            continue;
          }

          if (!empty($contributor->getName())) {
            $name = (count($related_contributor_items) > 0) ? t('et al.') : $contributor->getName();
            $related_contributor_items[] = $name;
          }

          if (count($related_contributor_items) > 1) {
            break;
          }
        }
        $related_contributor_list = implode(' ', $related_contributor_items);
        $related_link = l($related_contributor_list, 'node/' . $related_node->nid, ['absolute' => TRUE, 'query' => $query, 'attributes' => ['style' => 'color: #0961AB; text-decoration: none;']]);
        $related_items[] = t('@display_channel by !link', ['@display_channel' => $related_display_channel, '!link' => $related_link]);
      }
      if (!empty($related_items)) {
        if (count($related_items) > 1) {
          $last_related_items = [];
          $last_related_items[] = array_pop($related_items);
          $last_related_items[] = array_pop($related_items);
          $related_items[] = implode(t(' and '), $last_related_items);
        }
        $variables['related'] = t('See also: !related', ['!related' => implode(', ', $related_items)]);
      }
    }
  }

  $block = new stdClass();
  $block->content = theme('elife_content_alert', $variables);
  return $block;
}

/**
 * Edit form callback for the content type.
 */
function elife_content_alert_edit($form, &$form_state) {
  return $form;
}

/**
 * Edit form callback for the content type.
 */
function elife_content_alert_edit_submit(&$form, &$form_state) {
  // Nothing.
}
