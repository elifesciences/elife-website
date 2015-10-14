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
        $markup_sections = array_keys(ElifeMarkupService::getSectionLabels());
        $markup_section = reset($markup_sections);
      }

      $article_id = $dto->getArticleId();
      $article_id = _elife_article_process_article_id($article_id);

      $markup = elife_article_markup_service();
      $markup->addSectionQuery($article_id, $markup_section);
      $markup = _elife_article_markup_query($markup);
      $html = $markup->output();

      if ($conf['markup_section'] == 'main-text' && $dto->getStatus() == 'VOR') {
        // @todo - elife - nlisgo - suppress main-text for now as creating a lot of noise!
        $html = '<p>Under construction</p>';
      }

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
    '#options' => ElifeMarkupService::getSectionLabels(),
    '#multiple' => FALSE,
    '#default_value' => ($conf['markup_section']) ? $conf['markup_section'] : NULL,
  );

  return $form;
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
  $markup_section_options = ElifeMarkupService::getSectionLabels();

  if (!$markup_section) {
    $markup_sections = array_keys($markup_section_options);
    $markup_section = reset($markup_sections);
  }

  $block = new stdClass();
  $block->title = $markup_section_options[$markup_section];
  $block->content = '';
  return $block;
}
