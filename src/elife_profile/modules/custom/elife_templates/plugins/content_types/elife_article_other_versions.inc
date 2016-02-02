<?php

use Drupal\elife_article\ElifeArticleVersion;

$plugin = array(
  'title' => t('Other versions'),
  'single' => TRUE,
  'category' => array('eLife'),
  'edit form' => 'elife_article_other_versions_edit',
  'render callback' => 'elife_article_other_versions_render',
  'required context' => new ctools_context_required('Article Node', 'node'),
);

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function elife_article_other_versions_render($subtype, $conf, $args, $context) {
  $article_version = $context->data;
  $dto = elife_article_version_to_dto($article_version);

  $versions = ElifeArticleVersion::fromId($dto->getArticleId());
  if (count($versions) > 1) {
    $items = [];
    foreach ($versions as $nid => $version) {
      $this_dto = ($nid != $article_version->nid) ? elife_article_version_to_dto($version) : $dto;
      $text = t('Version @version (@date)', ['@version' => $this_dto->getVersion(), '@date' => $this_dto->getUpdate()->format('F d, Y')]);
      if ($nid != $article_version->nid) {
        $text = l($text, 'node/' . $nid);
      }
      $items[] = [
        'data' => $text,
      ];
    }
    $block = new stdClass();
    $block->content = theme('item_list', [
      'type' => 'ul',
      'items' => $items,
      'div_class' => 'no',
      'attributes' => [
        'class' => 'issue-toc-list',
      ],
    ]);
    return $block;
  }
}

/**
 * Edit form callback for the content type.
 */
function elife_article_other_versions_edit($form, &$form_state) {
  return $form;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_other_versions_edit_submit(&$form, &$form_state) {
  // Nothing.
}
