<?php

/**
 * @file
 * elife_article_affiliation.inc
 */

$plugin = array(
  'title' => t('Article Affiliation'),
  'single' => TRUE,
  'description' => t('Show Article Affiliation.'),
  'category' => array('eLife'),
  'edit form' => 'elife_article_affiliation_edit',
  'render callback' => 'elife_article_affiliation_render',
  'required context' => new ctools_context_required('Article Node', 'node'),
);

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function elife_article_affiliation_render($subtype, $conf, $args, $context) {
  $article_version = $context->data;
  $dto = elife_article_version_to_dto($article_version);

  $block = new stdClass();

  $affiliations = [];
  $referenced = $dto->getReferenced();
  foreach ($referenced->getAffiliation() as $key => $affiliation) {
    $name = [];
    if ($institution = $affiliation->getInstitution()) {
      $name['institution'] = $institution;
    }
    if ($country = $affiliation->getCountry()) {
      $name['country'] = $country;
    }

    if (!empty($name)) {
      $affiliation = [];
      foreach ($name as $k => $n) {
        $affiliation[] = '<span class="' . $k . '">' . $n . '</span>';
      }

      $class = array(
        'elife-institution',
        $key,
      );
      $affiliations[] = '<span class="' . implode(' ', $class) . '">' . implode(' ', $affiliation) . '</span>';
    }
  }

  if (!empty($affiliations)) {
    $block->title = t('Affiliation details');
    $block->content = '<div class="elife-institutions-list">' . implode('; ', $affiliations) . '</div>';
  }

  return $block;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_affiliation_edit($form, &$form_state) {
  return $form;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_affiliation_edit_submit(&$form, &$form_state) {
  // Nothing.
}
