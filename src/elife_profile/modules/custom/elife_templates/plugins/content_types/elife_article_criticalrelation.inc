<?php
/**
 * @file
 * elife_article_criticalrelation.inc
 */

use Drupal\elife_article\ElifeArticleVersion;

$plugin = array(
  'title' => t("eLife - Critical Relation Block"),
  'single' => TRUE,
  'description' => t('Used on elife replication study articles etc.'),
  'category' => array('eLife'),
  'edit form' => 'elife_article_criticalrelation_edit',
  'render callback' => 'elife_article_criticalrelation_render',
  'required context' => new ctools_context_required('Article Node', 'node'),
);

/**
 * Implements ctools plugin render callback function.
 */
function elife_article_criticalrelation_render($subtype, $conf, $args, $context) {
  $node = $context->data;

  /* @var EntityDrupalWrapper $ewrapper */
  if ($ewrapper = entity_metadata_wrapper('node', $node)) {
    if ($ewrapper->getBundle() == 'elife_article_ver') {
      if (!$ewrapper->field_elife_a_parent->raw()) {
        // @todo - elife - nlisgo - introduce original article

        $dto = elife_article_version_to_dto($node);
        $article = ElifeArticleVersion::getArticle($dto->getArticleId());
        // Get critical related articles.
        $related_articles = ElifeArticleVersion::retrieveRelatedArticles($article->nid, TRUE, TRUE, NULL, 1);
        $critical_relations = [];
        foreach ($related_articles as $related_article) {
          $critical_relations[$related_article->criticalrelation_type][] = $related_article;
        }
        if ($original_article = elife_article_original_article($dto->getArticleVersionId())) {
          $related_to = array(
            'related_to' => array(
              'display_channel' => 'original article',
            ),
            'related' => $original_article,
          );
          $critical_relations['original'][] = json_decode(json_encode($related_to), FALSE);
        }
        $content = '';
        foreach ($critical_relations as $critical_relation_type => $criticals) {
          $cri_blocks = [];
          $variables = [];

          foreach ($criticals as $cri) {
            $variables = [];
            if ($critical_relation_type != 'original') {
              $related_to = $cri->endpoints->related_to;
              $related = node_load($cri->endpoints->related_to->article_ver_nid);
              $related_dto = elife_article_version_to_dto($related);
              $impact_statement = $related_dto->getImpactStatement();
              $cite_as = $related_dto->getCiteAs();
              $doi_link = l($related_dto->getDoi(), $related_dto->getDoiUrl());
              $title = l($related_dto->getTitle(), 'node/' . $related->nid);
              $authors = $related_dto->getSimpleAuthorList();
            }
            else {
              $related_to = $cri->related_to;
              $related = $cri->related;
              $impact_statement = NULL;
              $cite_as = $related->citeas;
              $doi_link = l($related->doi, 'http://dx.doi.org/' . $related->doi);
              $title = l($related->title, 'http://dx.doi.org/' . $related->doi);
              $authors = $related->author;
            }
            if ($critical_relation_type == 'builds') {
              if (strtolower($related_to->display_channel) != 'research advance') {
                $variables['reln_title'] = t('Builds upon');
                $variables['reln_type'] = 'research-article';
                $variables['reln_type_id'] = 'researchArticle';
              }
              elseif (strtolower($related_to->display_channel) == 'research advance') {
                $variables['reln_title'] = t('Built upon by');
                $variables['reln_type'] = 'research-advance';
                $variables['reln_type_id'] = 'researchAdvance';
              }
            }
            elseif ($critical_relation_type == 'replicates') {
              if (strtolower($related_to->display_channel) == 'registered report') {
                $variables['reln_title'] = $related_to->display_channel;
                $variables['reln_type'] = 'registered-report';
                $variables['reln_type_id'] = 'registeredReport';
              }
              elseif (strtolower($related_to->display_channel) == 'replication study') {
                $variables['reln_title'] = $related_to->display_channel;
                $variables['reln_type'] = 'replication-study';
                $variables['reln_type_id'] = 'replicationStudy';
              }
            }
            elseif ($critical_relation_type == 'original') {
              $variables['reln_title'] = 'Original Article';
              $variables['reln_type'] = 'original-article';
              $variables['reln_type_id'] = 'originalArticle';
            }
            if (!empty($variables)) {
              $variables['other_title'] = $title;
              $author_limit = 10;
              $list_classes = ['critical-relation__bib_details__author_list'];
              if (!empty($authors) && count($authors) > $author_limit) {
                $authors = array_slice($authors, 0, $author_limit);
                $authors[] = 'et al.';
                $list_classes[] = 'critical-relation__bib_details__author_list--truncated';
              }
              if (!empty($authors)) {
                $author_list = [];
                foreach ($authors as $author) {
                  $author_list[] = [
                    'data' => $author,
                    'class' => [
                      'critical-relation__bib_details__author',
                    ],
                  ];
                }
                $variables['other_authors'] = theme('item_list', ['type' => 'ol', 'div_class' => 'no', 'items' => $author_list, 'attributes' => ['class' => $list_classes]]);
              }
              $variables['other_impact_statement'] = $impact_statement;
              $variables['other_citeas'] = $cite_as;
              $variables['other_doi_link'] = $doi_link;
              $cri_blocks[] = ['data' => theme('elife_article_criticalrelation', $variables), 'class' => ['critical-relation']];
            }
          }
          if (!empty($cri_blocks)) {
            $variables['criticalrelations'] = $cri_blocks;
            $content .= theme('elife_article_criticalrelation_block', $variables);
          }
        }
        if (!empty($content)) {
          drupal_add_css(drupal_get_path('module', 'elife_templates') . '/css/elife-critical-relation.css');
          $block = new stdClass();
          $block->content = $content;
          return $block;
        }
      }
    }
  }
}

/**
 * Edit form callback for the content type.
 */
function elife_article_criticalrelation_edit($form, &$form_state) {
  return $form;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_criticalrelation_edit_form_submit(&$form, &$form_state) {
  // Nothing.
}
