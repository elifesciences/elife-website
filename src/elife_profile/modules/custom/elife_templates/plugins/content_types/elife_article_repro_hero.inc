<?php

/**
 * @file
 * elife_templates/plugins/content_types/elife_article_repro_hero.inc
 */

use Drupal\elife_article\ElifeArticleVersion;

$plugin = array(
  'title' => t('eLife Reproducibility hero block'),
  'single' => TRUE,
  'category' => array('eLife'),
  'edit form' => 'elife_article_repro_hero_edit',
  'render callback' => 'elife_article_repro_hero_render',
);

/**
 * Run-time rendering of the body of the block (content type).
 *
 * See ctools_plugin_examples for more advanced info
 */
function elife_article_repro_hero_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $variables = [];
  if (!empty($conf['article_ids'])) {
    $article_ids = array_map('trim', explode(',', $conf['article_ids']));
    if (!empty($article_ids)) {
      $sticky_items = [];
      foreach ($article_ids as $article_id) {
        if ($article_version = ElifeArticleVersion::fromId($article_id, TRUE, 'elife_article_ver', [], 1)) {
          $article_dto = elife_article_version_to_dto($article_version);
          $article_display_channel = $article_dto->getDisplayChannels();
          $article_display_channel = reset($article_display_channel);
          $article_section_id = strtolower(preg_replace('/[^a-zA-Z0-9-]+/', '-', $article_display_channel));
          $sticky_items[] = [
            'data' => '<div class="sticky-list__item__type">' . $article_display_channel . '</div>' . l(elife_house_style_check_markup($article_dto->getTitle()), 'node/' . $article_version->nid, ['attributes' => ['class' => ['sticky-list__item__title']]]),
            'class' => ['sticky-list__item', 'sticky-list__item--' . $article_section_id],
          ];
        }
      }

      if (!empty($sticky_items)) {
        $variables['sticky_list'] = theme('item_list', [
          'type' => 'ul',
          'items' => $sticky_items,
          'div_class' => 'no',
          'attributes' => [
            'class' => [
              'sticky-list',
            ],
          ],
        ]);
      }
    }
  }
  $block->content = theme('elife_article_repro_hero', $variables);
  return $block;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_repro_hero_edit($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['article_ids'] = array(
    '#type' => 'textfield',
    '#title' => t('Article IDs'),
    '#description' => t('Comma separated list of Article IDs to introduce to the hero block'),
    '#default_value' => $conf['article_ids'],
  );

  return $form;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_repro_hero_edit_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}
