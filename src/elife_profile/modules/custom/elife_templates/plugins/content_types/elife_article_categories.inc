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

      // The only reason these queries are necessary is because we do not have
      // the term ids in the dto.
      $display_channels = $dto->getDisplayChannels();
      $headings = $dto->getHeadings();
      $keyword_groups = $dto->getKeywords();
      $keywords = [];
      $exclude_keywords = ['Other', 'None'];
      foreach ($keyword_groups as $group => $group_keywords) {
        foreach ($group_keywords as $group_keyword) {
          if (!in_array($group_keyword, $exclude_keywords)) {
            $keywords[] = $group_keyword;
          }
        }
      }

      $items = [];
      if (!empty($display_channels)) {
        $query = new EntityFieldQueryExtraFields();
        $query->entityCondition('entity_type', 'taxonomy_term');
        $query->entityCondition('bundle', 'elife_categories');
        $query->fieldCondition('field_elife_category_type', 'value', 'display-channel');
        $query->propertyCondition('name', $display_channels, 'IN');
        $query->addExtraField('', 'name', 'name', 'taxonomy_term_data');
        if ($result = $query->execute()) {
          if (isset($result['taxonomy_term']) && !empty($result['taxonomy_term'])) {
            foreach ($result['taxonomy_term'] as $tid => $term) {
              $items[] = l($term->extraFields->name, 'taxonomy/term/' . $tid, ['attributes' => ['class' => ['category-display-channel']]]);
            }
          }
        }
      }
      if (!empty($headings)) {
        $query = new EntityFieldQueryExtraFields();
        $query->entityCondition('entity_type', 'taxonomy_term');
        $query->entityCondition('bundle', 'elife_headings');
        $query->propertyCondition('name', $headings, 'IN');
        $query->addExtraField('', 'name', 'name', 'taxonomy_term_data');
        if ($result = $query->execute()) {
          if (isset($result['taxonomy_term']) && !empty($result['taxonomy_term'])) {
            foreach ($result['taxonomy_term'] as $tid => $term) {
              $items[] = l($term->extraFields->name, 'taxonomy/term/' . $tid, ['attributes' => ['class' => ['category-heading']]]);
            }
          }
        }
      }
      if (!empty($keywords)) {
        $query = new EntityFieldQueryExtraFields();
        $query->entityCondition('entity_type', 'taxonomy_term');
        $query->entityCondition('bundle', 'elife_keywords');
        $query->fieldCondition('field_elife_a_full_title', 'value', $keywords, 'IN');
        $query->addExtraField('field_elife_a_full_title', 'value', 'value');
        if ($result = $query->execute()) {
          if (isset($result['taxonomy_term']) && !empty($result['taxonomy_term'])) {
            foreach ($result['taxonomy_term'] as $tid => $term) {
              $items[] = l(_elife_article_xmltohtml($term->extraFields->field_elife_a_full_title_value), 'taxonomy/term/' . $tid, ['html' => TRUE, 'attributes' => ['class' => ['keyword']]]);
            }
          }
        }
      }

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
