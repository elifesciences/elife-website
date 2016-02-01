<?php

/**
 * @file
 * elife_templates/plugins/content_types/elife_article_reproducibility.inc
 */

use Drupal\elife_article\ElifeArticleVersion;
use eLife\EIF\ArticleVersion;

$plugin = array(
  'title' => t('eLife Reproducibility article'),
  'single' => TRUE,
  'category' => array('eLife'),
  'edit form' => 'elife_ctools_elife_article_reprod_edit',
  'render callback' => 'elife_ctools_elife_article_reprod_render',
  'required context' => new ctools_context_required(t('eLife Reproducibility article'), 'node'),
);

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function elife_ctools_elife_article_reprod_render($subtype, $conf, $args, $context) {
  $article_version = $context->data;
  $dto = elife_article_version_to_dto($article_version);

  $block = new stdClass();

  $variables = [
    'article_version' => $article_version,
    'title' => elife_house_style_check_markup($dto->getTitle()),
  ];

  elife_ctools_elife_article_repro_detail($dto, $variables);

  $block->content = theme('elife_article_block', $variables);

  return $block;
}

/**
 * Prepare detail output based upon display-channel.
 *
 * @param ArticleVersion $dto
 *   Node object.
 * @param array $variables
 *   Variables array to prepare for template.
 */
function elife_ctools_elife_article_repro_detail($dto, &$variables) {
  elife_ctools_elife_article_reprod_setup_once();
  $display_channel = $dto->getDisplayChannels();
  $display_channel = reset($display_channel);
  $article = ElifeArticleVersion::getArticle($dto->getArticleId());

  $subjects_class = ['elife-article__subjects'];
  $subject_class = ['elife-article__subject'];

  if ('registered report' == strtolower($display_channel)) {
    $variables['title'] = preg_replace('/^registered report: /i', '', $variables['title']);
    $items = [];
    $heading_links = _elife_article_heading_links($dto, ['attributes' => []]);
    foreach ($heading_links as $heading_link) {
      $items[] = [
        'data' => $heading_link,
        'class' => $subject_class,
      ];
    }

    $variables['section'] = theme('item_list', [
      'type' => 'ol',
      'items' => $items,
      'div_class' => 'no',
      'attributes' => [
        'class' => $subjects_class,
      ],
    ]);

    $related_articles = ElifeArticleVersion::retrieveRelatedArticles($article->nid, TRUE, TRUE, NULL, 1);
    $critical_relations = [];
    $repro_vars = [];
    foreach ($related_articles as $related_article) {
      $critical_relations[$related_article->criticalrelation_type][] = $related_article;
    }
    if ($original = elife_article_original_article($dto->getArticleVersionId())) {
      $original = json_decode(json_encode($original), FALSE);

      $original_date_split = explode('-', $original->date);
      if (count($original_date_split) > 2) {
        $original_date = date('F j, Y', strtotime($original->date));
        $original_date_machine = date('Ymd', strtotime($original->date));
      }
      elseif (count($original_date_split) > 1) {
        $original_date = date('F, Y', strtotime($original->date));
        $original_date_machine = date('Ym', strtotime($original->date));
      }
      else {
        $original_date = NULL;
        $original_date_machine = NULL;
      }

      $repro_vars['original'] = [
        'identifier' => 'original-article',
        'title' => l(t('Original Article'), 'http://dx.doi.org/' . $original->doi),
        'date' => $original_date,
        'date_machine' => $original_date_machine,
        'source' => $original->citeas,
        'author' => elife_ctools_elife_article_reprod_author_list($original->author, ['identifier' => 'repro-study-item']),
        'doi' => l($original->doi , 'http://dx.doi.org/' . $original->doi),
      ];
    }
    $repro_vars['registered-report'] = [
      'identifier' => 'registered-report',
      'title' => l($display_channel, 'node/' . $variables['article_version']->nid),
      'date' => $dto->getPubDate()->format('F j, Y'),
      'date_machine' => $dto->getPubDate()->format('Ymd'),
      'source' => $dto->getCiteAs(),
      'author' => elife_ctools_elife_article_reprod_author_list($dto->getSimpleAuthorList(), ['identifier' => 'repro-study-item']),
      'doi' => l($dto->getDoi(), $dto->getDoiUrl()),
    ];

    if (isset($critical_relations['replicates'])) {
      $related = node_load($critical_relations['replicates']->endpoints->related_to->article_ver_nid);
      $related_dto = elife_article_version_to_dto($related);
      $related_display_channel = $related_dto->getDisplayChannels();
      $related_display_channel = reset($related_display_channel);
      $repro_vars['replication-study'] = [
        'identifier' => 'repln-study-done',
        'title' => l($related_display_channel, 'node/' . $variables[$related->nid]),
        'date' => $related_dto->getPubDate()->format('F j, Y'),
        'date_machine' => $related_dto->getPubDate()->format('Ymd'),
        'source' => $related_dto->getCiteAs(),
        'author' => elife_ctools_elife_article_reprod_author_list($related_dto->getSimpleAuthorList()),
        'doi' => l($related_dto->getDoi(), $related_dto->getDoiUrl()),
      ];
    }
    else {
      $repro_vars['replication-study'] = [
        'title' => t('Replication Study'),
        'date' => t('Forthcoming'),
        'identifier' => 'repln-study-pending',
      ];
    }
    $detail = [];
    foreach ($repro_vars as $key => $vars) {
      $vars['details'] = theme('elife_article_repro_details', $vars);
      $detail[] = theme('elife_article_repro_block', $vars);
    }
    $variables['detail'] = implode("\n", $detail);
  }
  else {
    $variables['title'] = l($variables['title'], 'node/' . $variables['article_version']->nid);
    $display_channel_links = _elife_article_display_channel_links($dto, ['attributes' => []]);
    $items = [];
    foreach ($display_channel_links as $display_channel_link) {
      $items[] = [
        'data' => $display_channel_link,
        'class' => $subject_class,
      ];
    }

    $variables['section'] = theme('item_list', [
      'type' => 'ol',
      'items' => $items,
      'div_class' => 'no',
      'attributes' => [
        'class' => $subjects_class,
      ],
    ]);

    $variables['section_id'] = strtolower(preg_replace('/[^a-zA-Z0-9-]+/', '-', $display_channel));

    $article_vars = [
      'summary' => elife_house_style_check_markup($dto->getImpactStatement()),
      'author' => elife_ctools_elife_article_reprod_author_list($dto->getSimpleAuthorList(), ['identifier' => 'elife-article'], 0),
      'date' => $dto->getPubDate()->format('F j, Y'),
      'date_machine' => $dto->getPubDate()->format('Ymd'),
      'doi' => l($dto->getDoi(), $dto->getDoiUrl()),
    ];
    $variables['detail'] = theme('elife_article_detail', $article_vars);
  }
}

/**
 * Prepare author list with limit.
 *
 * @param array $authors
 * @param array $options
 * @param int $limit
 */
function elife_ctools_elife_article_reprod_author_list($authors, $options = [], $limit = 10) {
  $options += [
    'type' => 'ol',
    'identifier' => 'author',
    'list_class' => [
      '__bib_details__author_list',
    ],
    'list_class_truncated' => '__bib_details__author_list--truncated',
    'item_class' => [
      '__bib_details__author',
    ],
  ];

  $type = $options['type'];
  $list_class = $options['list_class'];
  $item_class = $options['item_class'];

  if ($limit > 1 && count($authors) > $limit) {
    $authors = array_slice($authors, 0, $limit);
    $authors[] = 'et al.';
    $list_class[] = $options['list_class_truncated'];
  }

  if (!empty($options['identifier'])) {
    foreach ($list_class as $key => $value) {
      $list_class[$key] = $options['identifier'] . $value;
    }
    foreach ($item_class as $key => $value) {
      $item_class[$key] = $options['identifier'] . $value;
    }
  }

  $authors_list = [];
  foreach ($authors as $author) {
    $authors_list[] = [
      'data' => $author,
      'class' => $item_class,
    ];
  }

  return theme('item_list', [
    'type' => $type,
    'items' => $authors_list,
    'div_class' => 'no',
    'attributes' => [
      'class' => $list_class,
    ],
  ]);
}

/**
 * Setup that just needs to be run once.
 */
function elife_ctools_elife_article_reprod_setup_once() {
  $cache = &drupal_static(__FUNCTION__, FALSE);

  if (empty($cache)) {
    $cache = TRUE;
    drupal_add_css(drupal_get_path('module', 'elife_templates') . '/css/elife-article.css');
    drupal_add_css(drupal_get_path('module', 'elife_templates') . '/css/elife-repro-listing-page.css');
    drupal_add_css(drupal_get_path('module', 'elife_templates') . '/css/elife-repro-hero.css');
    drupal_add_css(drupal_get_path('module', 'elife_templates') . '/css/elife-repro-sticky-list.css');
    drupal_add_css(drupal_get_path('module', 'elife_templates') . '/css/elife-repro-study-item.css');
  }

  return $cache;
}

/**
 * Edit form callback for the content type.
 */
function elife_ctools_elife_article_reprod_edit($form, &$form_state) {
  return $form;
}

/**
 * Edit form submit callback for the content type.
 */
function elife_ctools_elife_article_reprod_edit_submit(&$form, &$form_state) {
  // Nothing.
}
