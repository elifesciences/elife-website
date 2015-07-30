<?php

use Drupal\elife_article\ExeterMarkupService;
use eLife\EIF\ArticleVersion\Fragment;

$plugin = array(
  'title' => t('Article Figure & Data'),
  'single' => TRUE,
  'category' => array('eLife'),
  'edit form' => 'elife_article_fig_data_edit',
  'render callback' => 'elife_article_fig_data_render',
  'required context' => new ctools_context_required('Article Node', 'node'),
);

/**
 * Run-time rendering of the body of the block (content type).
 */
function elife_article_fig_data_render($subtype, $conf, $args, $context) {
  drupal_add_js(drupal_get_path('module', 'elife_templates') . '/js/elife_article_fig_data.js');
  $article_version = $context->data;
  $dto = elife_article_version_to_dto($article_version);

  $output = '';

  if ($dto->getFragments()) {
    $item_lists = [];
    foreach ($dto->getFragments() as $fragment) {
      if ($fragment instanceof Fragment) {
        if (in_array($fragment->getType(), ['fig', 'table-wrap', 'media']) && $markup = _elife_article_fig_data_markup($dto->getArticleId(), $fragment)) {
          $item_lists[$fragment->getType()]['items'][] = $markup;
        }
      }
    }
    foreach ($item_lists as $type => $item_list) {
      $item_list['attributes'] = [
        'class' => 'fig-data-list clearfix',
        'id' => 'fragments-' . $type,
      ];
      $output .= '<div id="fig-data-' . $type . '" class="group frag-' . $type . '">';
      $output .= _elife_article_fig_data_title($type);
      $output .= theme('item_list', $item_list);
      $output .= '</div>';
    }
  }

  if (!empty($output)) {
    $block = new stdClass();
    $block->title = t('Article Figures & Data');
    $block->content = $output;
    return $block;
  }
}

function _elife_article_fig_data_markup($article_id, Fragment $fragment) {
  if (preg_match('/[0-9]*(?<id>[0-9]{5})[0-9]*/', $article_id, $matches)) {
    $article_id = $matches['id'];
  }

  $markup = new ExeterMarkupService();
  $markup->addDoiQuery($article_id, $fragment->getDoi());
  $markup->submitQuery();
  return $markup->output();
}

function _elife_article_fig_data_title($type) {
  $links = array(
    'fig' => 'Figures',
    'table-wrap' => 'Tables',
    'media' => 'Movies',
    'datasets' => 'Major datasets',
    'additional-files' => 'Additional files',
  );

  $output = '<div class="elife-fig-data-title-jump">';

  foreach ($links as $link => $title) {
    $output .= '<span class="elife-fig-data-title-jump-link">';

    if ($link == $type) {
      $output .= '<h2>' . $title . '</h2>';
    }
    else {
      $output .= l($title, '', array('fragment' => 'fig-data-' . $link, 'external' => TRUE));
    }

    $output .= '</span>';
  }

  $output .= "</div>";

  return $output;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_fig_data_edit($form, &$form_state) {
  return $form;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_fig_data_edit_submit(&$form, &$form_state) {
  // Nothing.
}
