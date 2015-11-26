<?php

use Drupal\elife_article\ElifeMarkupService;

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
      $article_version_id = $dto->getArticleVersionId();
      $sections = ElifeMarkupService::getSectionLabels('main');

      $markup = elife_article_markup_service();
      $markup->addSectionQuery($article_version_id, array_keys($sections));
      $markup = _elife_article_markup_query($markup);
      $results = $markup->getResult($article_version_id);
      if (!empty($results)) {
        $links = [];
        $links['article']['data'] = elife_article_jumpto_link('Article', 'article', 'jnl_elife_article_article');
        foreach ($results as $section => $data) {
          if (!empty($data)) {
            $links['article']['children'][$section]['data'] = elife_article_jumpto_link($sections[$section], $section, 'jnl_elife_article_article');
          }
        }
        if (!empty($results['main-text'])) {
          libxml_use_internal_errors(TRUE);
          $xml = new DOMDocument();
          $xml->preserveWhiteSpace = FALSE;
          $xml->loadHTML('<meta http-equiv="content-type" content="text/html; charset=utf-8"><wrapper>' . implode("\n", $results['main-text']) . '</wrapper>');
          $xpath = new DOMXPath($xml);
          foreach ($xpath->query('//h3') as $i => $h3) {
            $links['article']['children']['main-text']['children'][] = elife_article_jumpto_link($h3->nodeValue, $h3->parentNode->getAttribute('id'), 'jnl_elife_article_article');
          }
          libxml_clear_errors();
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
