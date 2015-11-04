<?php

use Drupal\elife_article\ElifeMarkupService;
use eLife\EIF\ArticleVersion;

$plugin = array(
  'title' => t('Author Info'),
  'single' => TRUE,
  'category' => array('eLife'),
  'edit form' => 'elife_article_author_info_edit',
  'render callback' => 'elife_article_author_info_render',
  'admin info' => 'elife_article_author_info_admin_info',
  'required context' => new ctools_context_required('Article Node', 'node'),
);

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function elife_article_author_info_render($subtype, $conf, $args, $context) {
  $article_version = $context->data;
  $dto = elife_article_version_to_dto($article_version);

  $sections = ElifeMarkupService::getSectionLabels();

  // Suppress titles for these sections.
  $sections['author-info-equal-contrib'] = '';
  $sections['author-info-other-footnotes'] = '';

  $conf_author_info_section = (!empty($conf['author_info_section'])) ? $conf['author_info_section'] : NULL;

  $author_info_sections = [];

  if ($conf_author_info_section) {
    foreach ($conf_author_info_section as $k => $conf_author_info_s) {
      if (!empty($conf_author_info_s)) {
        $author_info_sections[$conf_author_info_s] = [];
      }
      else {
        unset($conf_author_info_section[$k]);
      }
    }
  }

  foreach (array_keys($sections) as $section) {
    foreach (array_keys($author_info_sections) as $author_info_section) {
      if (strpos($section, $author_info_section) === 0) {
        $author_info_sections[$author_info_section][] = $section;
      }
    }
  }

  $author_info_queries = [];

  foreach ($author_info_sections as $author_info_section => $get_sections) {
    $markup = elife_article_markup_service();
    foreach ($get_sections as $get_section) {
      $markup->addSectionQuery($dto->getArticleVersionId(), $get_section);
    }
    $markup = _elife_article_markup_query($markup);
    $author_info_queries[$author_info_section] = $markup->getResults();
  }

  if (!empty($author_info_queries)) {
    $output = [];
    foreach ($author_info_queries as $author_info_section => $results) {
      if (!empty($results)) {
        $out = '';
        foreach ($results[$dto->getArticleVersionId()] as $section_id => $result) {
          if (!empty($result)) {
            if (!empty($sections[$section_id])) {
              $out .= '<h3>' . $sections[$section_id] . '</h3>';
            }
            $out .= implode("\n", $result) . "\n";
          }
        }
        $output[$author_info_section] = $out;
      }
    }



    if (!empty($output)) {
      $block = new stdClass();
      if ($conf_author_info_section) {
        $block->title = _elife_article_author_info_title($conf_author_info_section);
      }
      _elife_article_author_info_alter($output, $dto);
      $block->content = implode("\n", $output);
      return $block;
    }
  }
}

/**
 * Edit form callback for the content type.
 */
function elife_article_author_info_edit($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['author_info_section'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Sections'),
    '#required' => TRUE,
    '#options' => _elife_article_author_info_options(),
    '#default_value' => (!empty($conf['author_info_section'])) ? $conf['author_info_section'] : [],
  );

  return $form;
}

function _elife_article_author_info_options() {
  return [
    'author-info' => t('Author information'),
    'article-info' => t('Article information'),
  ];
}

/**
 * Edit form callback for the content type.
 */
function elife_article_author_info_edit_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
 * Admin info for markup section block.
 */
function elife_article_author_info_admin_info($subtype, $conf, $context) {
  $conf_author_info_section = (!empty($conf['author_info_section'])) ? $conf['author_info_section'] : NULL;
  if ($conf_author_info_section) {
    $block = new stdClass();
    $block->title = _elife_article_author_info_title($conf_author_info_section);
    $block->content = '';
    return $block;
  }
}

function _elife_article_author_info_title($conf_author_info_section) {
  $author_info_options = _elife_article_author_info_options();

  $chosen = [];
  if ($conf_author_info_section) {
    foreach ($conf_author_info_section as $conf_author_info_s) {
      if (!empty($conf_author_info_s)) {
        $chosen[] = $author_info_options[$conf_author_info_s];
      }
    }
  }

  return implode(', ', $chosen);
}

function _elife_article_author_info_alter(&$output, ArticleVersion $article_version) {
  if (isset($output['article-info'])) {
    // @todo - elife - nlisgo - output identification and publication history.
    $identification = '';
    $publication_history = '';
    $output['article-info'] = $identification . $publication_history . $output['article-info'];
  }
}
