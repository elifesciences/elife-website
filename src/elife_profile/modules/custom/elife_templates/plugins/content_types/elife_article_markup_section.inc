<?php

use Drupal\elife_article\ElifeMarkupService;

$plugin = array(
  'title' => t('Article Markup for Section'),
  'single' => TRUE,
  'category' => array('eLife'),
  'edit form' => 'elife_article_markup_section_edit',
  'render callback' => 'elife_article_markup_section_render',
  'admin info' => 'elife_article_markup_section_admin_info',
  'required context' => new ctools_context_required('Article', 'node'),
);

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function elife_article_markup_section_render($subtype, $conf, $args, $context) {
  $article_version = $context->data;

  /* @var EntityDrupalWrapper $ewrapper */
  if ($ewrapper = entity_metadata_wrapper('node', $article_version)) {
    if ($ewrapper->getBundle() == 'elife_article_ver' && !$ewrapper->field_elife_a_subarticle->value()) {
      $dto = elife_article_version_to_dto($article_version);

      $markup_section = ($conf['markup_section']) ? $conf['markup_section'] : NULL;

      if (!$markup_section) {
        $markup_sections = array_keys(_elife_article_markup_section_options());
        $markup_section = reset($markup_sections);
      }

      $article_id = $dto->getArticleId();
      if (preg_match('/[0-9]*(?<id>[0-9]{5})[0-9]*/', $article_id, $matches)) {
        $article_id = $matches['id'];
      }

      $markup = new ElifeMarkupService();
      $markup->addQuery($article_id, $markup_section);
      $markup->submitQuery();
      $html = $markup->output();

      if ($html) {
        $block = new stdClass();
        $block->content = $html;

        return $block;
      }
    }
  }
}

/**
 * Edit form callback for the content type.
 */
function elife_article_markup_section_edit($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['markup_section'] = array(
    '#type' => 'select',
    '#title' => t('Section'),
    '#size' => 1,
    '#options' => _elife_article_markup_section_options(),
    '#multiple' => FALSE,
    '#default_value' => ($conf['markup_section']) ? $conf['markup_section'] : NULL,
  );

  return $form;
}

/**
 * Markup sections.
 *
 * @return array
 *   Array of section labels with xpath queries as keys.
 */
function _elife_article_markup_section_options() {
  return [
    "//*[contains(concat(' ', @class, ' '), ' section ')]" => t('Main text'),
    "//*[@id='abstract']" => t('Abstract'),
    "//*[@id='elife-digest']" => t('Digest'),
    "//*[@id='references']" => t('References'),
    "//*[@id='ack-1']" => t('Acknowledgements'),
    "//*[@id='decision-letter']" => t('Decision letter'),
    "//*[@id='author-response']" => t('Author response'),
  ];
}

/**
 * Edit form callback for the content type.
 */
function elife_article_markup_section_edit_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
 * Admin info for markup section block.
 */
function elife_article_markup_section_admin_info($subtype, $conf, $context) {
  $markup_section = ($conf['markup_section']) ? $conf['markup_section'] : NULL;
  $markup_section_options = _elife_article_markup_section_options();

  if (!$markup_section) {
    $markup_sections = array_keys($markup_section_options);
    $markup_section = reset($markup_sections);
  }

  $block = new stdClass();
  $block->title = $markup_section_options[$markup_section];
  $block->content = '';
  return $block;
}
