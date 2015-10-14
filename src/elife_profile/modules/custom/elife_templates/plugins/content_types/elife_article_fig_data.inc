<?php

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

  $item_lists = [
    'fig' => [],
    'table-wrap' => [],
    'media' => [],
  ];
  $article_id = $dto->getArticleId();
  $article_id = _elife_article_process_article_id($article_id);
  $markup = elife_article_markup_service();
  foreach ($dto->getFragmentsOfType(array_keys($item_lists)) as $fragment) {
    $item_lists[$fragment->getType()]['items'][] = $fragment->getDoi();
    $markup->addDoiQuery($article_id, $fragment->getDoi());
  }

  $item_lists['datasets']['items'][] = 'datasets';
  $markup->addSectionQuery($article_id, 'datasets');

  foreach ($dto->getFragmentsOfType('supplementary-material', 0) as $fragment) {
    $item_lists[$fragment->getType()]['items'][] = $fragment->getDoi();
    $markup->addDoiQuery($article_id, $fragment->getDoi());
  }

  $markup = _elife_article_markup_query($markup);
  $results = $markup->getResults();

  if (!empty($results[$article_id])) {
    foreach ($item_lists as $type => $item_list) {
      $items = [];
      if (!empty($item_list['items'])) {
        foreach ($item_list['items'] as $k => $identifier) {

          if (!empty($results[$article_id][$identifier])) {
            $items[] = implode("\n", $results[$article_id][$identifier]);
          }
          elseif (!empty($results[$article_id]['doi::' . $identifier])) {
            $items[] = implode("\n", $results[$article_id]['doi::' . $identifier]);
          }
          // @todo - elife - nlisgo - when the markup service is reliable consider not outputting this value.
          else {
            $items[] = 'No result for: ' . $identifier;
          }
        }
      }
      if (!empty($items)) {
        $item_lists[$type]['items'] = $items;
      }
      else {
        unset($item_lists[$type]);
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
    $block->content = '<div class="elements-frag-data highwire-markup" id="fig-data">';
    $block->content .= $output;
    $block->content .= '</div>';
    return $block;
  }
}

function _elife_article_fig_data_title($type) {
  $links = array(
    'fig' => t('Figures'),
    'table-wrap' => t('Tables'),
    'media' => t('Movies'),
    'datasets' => t('Major datasets'),
    'supplementary-material' => t('Additional files'),
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
