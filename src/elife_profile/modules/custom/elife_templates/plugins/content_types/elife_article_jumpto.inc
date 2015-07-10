<?php

use Drupal\elife_article\ElifeMarkupService;
use Drupal\elife_article\ExeterMarkupService;

$plugin = array(
  'title' => t('Jump To'),
  'single' => TRUE,
  'category' => array('eLife'),
  'edit form' => 'elife_article_jumpto_edit',
  'render callback' => 'elife_article_jumpto_render',
  'required context' => new ctools_context_required('Article Node', 'node'),
);

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function elife_article_jumpto_render($subtype, $conf, $args, &$context) {
  $article_version = $context->data;

  /* @var EntityDrupalWrapper $ewrapper */
  if ($ewrapper = entity_metadata_wrapper('node', $article_version)) {
    if ($ewrapper->getBundle() == 'elife_article_ver' && !$ewrapper->field_elife_a_subarticle->value()) {
      $dto = elife_article_version_to_dto($article_version);
      $article_id = $dto->getArticleId();
      if (preg_match('/[0-9]*(?<id>[0-9]{5})[0-9]*/', $article_id, $matches)) {
        $article_id = $matches['id'];
      }
      $sections = ElifeMarkupService::getSectionLabels();

      $markup = new ExeterMarkupService();
      $markup->addSectionQuery($article_id, array_keys($sections));
      $markup->submitQuery();
      $results = $markup->getResult($article_id);
      if (!empty($results) && $dto->getStatus() == 'VOR') {
        $links = [];
        $links['article']['data'] = elife_article_jumpto_link('Article', 'article', 'jnl_elife_article_article');
        foreach ($results as $section => $data) {
          if (!empty($data)) {
            $links['article']['children'][$section]['data'] = elife_article_jumpto_link($sections[$section], $section, 'jnl_elife_article_article');
          }
        }
        if (!empty($results['main-text'])) {
          $xml = new DOMDocument();
          $xml->preserveWhiteSpace = FALSE;
          $xml->loadXML('<wrapper>' . implode("\n", $results['main-text']) . '</wrapper>');
          $xpath = new DOMXPath($xml);
          foreach ($xpath->query('//h2') as $i => $h2) {
            $links['article']['children']['main-text']['children'][] = elife_article_jumpto_link($h2->nodeValue, $h2->parentNode->getAttribute('id'), 'jnl_elife_article_article');
          }
        }
        $block = new stdClass();
        $block->content = '<div class="elife-jumpto">';
        $block->content .= theme('item_list', array('items' => $links));
        $block->content .= '</div>';

        drupal_add_js(drupal_get_path('module', 'elife_templates') . '/js/elife_article_jumpto.js');
        return $block;
      }
    }
  }
}

function elife_article_jumpto_link($name, $anchor, $tab, $class = NULL, $path = '', $attributes = array()) {
  $options = array(
    'external' => TRUE,
    'fragment' => $anchor,
    'attributes' => array(
      'class' => array('elife-article-jumplink'),
      'data-panel-ajax-tab' => $tab,
    ),
  );

  if ($class) {
    $options['attributes']['class'][] = $class;
  }

  $attributes += $options['attributes'];

  $options['attributes'] = $attributes;

  return l($name, $path, $options);

}


/**
 * Edit form callback for the content type.
 */
function elife_article_jumpto_edit($form, &$form_state) {
  return $form;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_jumpto_edit_submit(&$form, &$form_state) {
  // Nothing.
}
