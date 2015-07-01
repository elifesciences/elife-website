<?php

/**
 * @file
 * elife_article_authors.inc
 */

use Drupal\elife_article\ElifeArticleVersion;

$plugin = array(
  'title' => t('Article Authors'),
  'single' => TRUE,
  'description' => t('Show Article Authors.'),
  'category' => array('eLife'),
  'edit form' => 'elife_article_authors_edit',
  'render callback' => 'elife_article_authors_render',
  'required context' => new ctools_context_required('Article Node', 'node'),
);

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function elife_article_authors_render($subtype, $conf, $args, $context) {
  $node = $context->data;
  /* @var EntityDrupalWrapper $ewrapper */
  $ewrapper = entity_metadata_wrapper('node', $node);

  $block = new stdClass();

  $authors = array();
  $contributors = ElifeArticleVersion::getContributors($ewrapper->field_elife_a_article_version_id->value());
  if (!empty($contributors)) {
    foreach ($contributors as $contributor) {
      if ($contributor['type'] != 'author') {
        continue;
      }
      $author = array();
      foreach (array('given-names', 'surname', 'suffix') as $n) {
        if (!empty($contributor[$n])) {
          $author[] = '<span class="' . $n . '">' . $contributor[$n] . '</span>';
        }
      }
      if (!empty($author)) {
        $class = array(
          'elife-article-author-item',
        );
        if (!empty($contributor['corresp'])) {
          $author[] = theme('image', array(
            'path' => drupal_get_path('module', 'elife_templates') . '/images/corresp.png',
            'attributes' => array(
              'class' => array(
                'corresp-icon',
              ),
            )));
          $class[] = 'corresp';
        }
        $authors[] = '<span class="' . implode(' ', $class) . '">' . implode(' ', $author) . '</span>';
      }
    }
  }

  if (!empty($authors)) {
    $block->title = t('Article Authors');
    $block->content = '<div class="author-list"><ul>' . implode(', ', $authors) . '</ul></div>';
  }

  return $block;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_authors_edit($form, &$form_state) {
  return $form;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_authors_edit_submit(&$form, &$form_state) {
  // Nothing.
}
