<?php

$plugin = array(
  'title' => t('Article Categories'),
  'single' => TRUE,
  'category' => array('eLife'),
  'edit form' => 'elife_article_categories_edit',
  'render callback' => 'elife_article_categories_render',
  'required context' => new ctools_context_required('Article Node', 'node'),
);

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function elife_article_categories_render($subtype, $conf, $args, $context) {
  $article_version = $context->data;

  /* @var EntityDrupalWrapper $ewrapper */
  if ($ewrapper = entity_metadata_wrapper('node', $article_version)) {
    if ($ewrapper->getBundle() == 'elife_article_ver' && !$ewrapper->field_elife_a_subarticle->value()) {
      $dto = elife_article_version_to_dto($article_version);

      $display_channel_links = _elife_article_display_channel_links($dto);
      $heading_links = _elife_article_heading_links($dto);
      $keyword_links = _elife_article_keyword_links($dto);
      $items = array_merge($display_channel_links, $heading_links, $keyword_links);

      if (!empty($items)) {
        $block = new stdClass();
        $block->content = theme('item_list', ['items' => $items, 'attributes' => ['class' => 'elife-article-categories']]);

        return $block;
      }
    }
  }
}


/**
 * Edit form callback for the content type.
 */
function elife_article_categories_edit($form, &$form_state) {
  return $form;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_categories_edit_form_submit(&$form, &$form_state) {
  // Nothing.
}
