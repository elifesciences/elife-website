<?php

/**
 * @file
 * elife_article_related.inc
 */

use Drupal\elife_article\ElifeArticleVersion;
use eLife\EIF\ArticleVersion\Contributor\CollabContributor;
use eLife\EIF\ArticleVersion\Contributor\PersonContributor\BylineContributor;

$plugin = array(
  'title' => t('eLife - related content'),
  'single' => TRUE,
  'description' => t('Provides related articles for this article.'),
  'category' => array('eLife'),
  'edit form' => 'elife_article_related_content_edit',
  'render callback' => 'elife_article_related_content_render',
  'required context' => new ctools_context_required('Article Node', 'node'),
);

/**
 * Rendering function for elife_article_related_content.
 */
function elife_article_related_content_render($subtype, $conf, $args, &$context) {
  $node = $context->data;

  /* @var EntityDrupalWrapper $ewrapper */
  if ($ewrapper = entity_metadata_wrapper('node', $node)) {
    if ($ewrapper->getBundle() == 'elife_article_ver') {
      if (!$ewrapper->field_elife_a_parent->raw()) {
        $dto = elife_article_version_to_dto($node);
        $article = ElifeArticleVersion::getArticle($dto->getArticleId());
        $related_articles = ElifeArticleVersion::retrieveRelatedArticles($article->nid, TRUE, TRUE, 1);
        $items = [];
        foreach ($related_articles as $related_article) {
          $related = node_load($related_article->{$related_article->related_to_endpoint . '_article_ver_nid'});
          $related_dto = elife_article_version_to_dto($related);
          $variables = [
            'title' => l($related_dto->getTitle(), 'node/' . $related->nid, ['attributes' => ['class' => ['elife-cite-linked-title']]]),
          ];
          $display_channel_links = _elife_article_display_channel_links($dto);
          $heading_links = _elife_article_heading_links($dto);
          $cats_and_heads = array_merge($display_channel_links, $heading_links);
          $variables['cats_and_heads'] = theme('item_list', ['items' => $cats_and_heads, 'attributes' => ['class' => ['elife-citation-categories', 'inline']], 'nowrap' => TRUE]);
          $authors = [];
          foreach ($related_dto->getContributors() as $contributor) {
            $name = [];
            if ($contributor instanceof BylineContributor) {
              if ($contributor->getType() != 'author') {
                continue;
              }
              if ($given_names = $contributor->getGivenNames()) {
                $name['given-names'] = $given_names;
              }
              if ($surname = $contributor->getSurname()) {
                $name['surname'] = $surname;
              }
              if ($suffix = $contributor->getSuffix()) {
                $name['suffix'] = $suffix;
              }
            }
            elseif ($contributor instanceof CollabContributor) {
              if ($collab = $contributor->getCollab()) {
                $name['collab'] = $collab;
              }
            }
            if (!empty($name)) {
              $author = [];
              foreach ($name as $k => $n) {
                $author[] = '<span class="' . $k . '">' . $n . '</span>';
              }
              $authors[] = implode(' ', $author);
            }
            $variables['authors'] = implode(', ', $authors);
          }
          $items[] = theme('elife_article_related', $variables);
        }

        if (!empty($items)) {
          $block = new stdClass();
          $block->title = t('Related articles');
          $block->content = theme('item_list', ['items' => $items, 'attributes' => ['class' => 'elife-related-articles-list']]);
          return $block;
        }
      }
    }
  }
}

/**
 * Edit form callback for the content type.
 */
function elife_article_related_content_edit($form, &$form_state) {
  return $form;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_related_content_edit_submit(&$form, &$form_state) {
  // Nothing.
}

