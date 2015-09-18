<?php
/**
 * @file
 * plugins/content_types/elife_article_listing.inc
 *
 * Prepare a ctools plugin to provide a display for the elife article items for
 * the listings pages
 */

use Drupal\elife_article\ElifeArticleVersion;

$plugin = array(
  'single' => TRUE,
  'icon' => 'icon_node_form.png',
  'title' => t('eLife Article Listing'),
  'description' => t('Show rendered eLife article capsule.'),
  'category' => t('eLife'),
  'edit form' => 'elife_article_listing_plugin_edit',
  'render callback' => 'elife_article_listing_plugin_render',
  'required context' => new ctools_context_required(t('Article Node'), 'node'),
);

/**
 * Return the elife article items in the elife_article_capsule template.
 */
function elife_article_listing_plugin_render($subtype, $conf, $args, $context) {
  $node = $context->data;
  $block = new stdClass();

  $variables = array();

  $fields = array(
    'title' => 'field_elife_a_full_title',
  );

  foreach ($fields as $id => $field) {
    if ($value = field_view_field('node', $node, $field, array('label' => 'hidden'))) {
      unset($value['#theme']);
      $variables[$id] = drupal_render($value);
    }
  }

  _elife_article_listing_setup_once($conf);
  _elife_article_listing_detail($node, $variables, $conf);

  $block->content = theme('elife_article_block', $variables);

  return $block;
}

/**
 * Display options.
 *
 * @return array
 *   Array of predefined display options.
 */
function _elife_article_listing_display_options() {
  return array(
    'title-as-link' => t('Title as link'),
    'display-channel' => t('Display channel'),
    'heading' => t('Subject headings'),
    'impact' => t('Impact statement'),
    'authors' => t('Author list'),
    'doi' => t('DOI'),
  );
}

/**
 * Prepare detail output based upon display-channel.
 *
 * @param object $node
 *   Node object.
 * @param array $variables
 *   Variables array to prepare for template.
 */
function _elife_article_listing_detail($node, &$variables, $conf) {
  /* @var EntityDrupalWrapper $ewrapper */
  $ewrapper = entity_metadata_wrapper('node', $node);
  $article_id = $ewrapper->field_elife_a_article_id->value();

  $display_options = (isset($conf['display_options'])) ? $conf['display_options'] : array_keys(_elife_article_listing_display_options());

  foreach ($display_options as $option => $value) {
    if (empty($value)) {
      unset($display_options[$option]);
    }
  }

  $subjects_class = array('elife-article__subjects');
  $subject_class = array('elife-article__subject');
  $section = ElifeArticleVersion::getSection($article_id, 'article');
  $variables['section_id'] = $section['code'];

  if (in_array('display-channel', $display_options)) {
    $variables['section'] = $section['name'];

    $sections = array();
    if ($terms = taxonomy_get_term_by_name($variables['section'], 'elife_categories')) {
      $term = reset($terms);
      $sections[] = array(
        'data' => l($variables['section'],
          'taxonomy/term/' . $term->tid),
        'class' => $subject_class,
      );
    }

    $variables['section'] = theme('item_list', array(
      'type' => 'ol',
      'items' => $sections,
      'div_class' => 'no',
      'attributes' => array(
        'class' => $subjects_class,
      ),
    ));
  }

  if (in_array('title-as-link', $display_options)) {
    $variables['title'] = l($variables['title'], 'node/' . $node->nid, array('html' => TRUE));
  }
  $detail = array(
    'node' => $node,
  );

  if (in_array('authors', $display_options)) {
    $author_options = array(
      'type' => 'ol',
      'identifier' => 'elife-article',
    );
    $detail['author'] = '';
  }

  if (in_array('impact', $display_options) && $ewrapper->field_elife_a_author_imp->value()) {
    $detail['summary'] = $ewrapper->field_elife_a_author_imp->value->value();
  }

  if (in_array('doi', $display_options)) {
    $detail['doi'] = $ewrapper->field_elife_a_doi->value();
  }

  if (!empty($conf['image_style']) && $image_path = elife_article_reference_striking_image_path($ewrapper->field_elife_a_article_id->value(), $conf['image_style'])) {
    $detail['image'] = theme('image', array('path' => $image_path));
  }
  // elife_article_get_citation_dates($detail, $options['date_options']);
  $variables['detail'] = theme('elife_article_detail', $detail);
}

/**
 * Setup that just needs to be run once.
 */
function _elife_article_listing_setup_once($conf) {
  $cache = &drupal_static(__FUNCTION__, FALSE);

  if (empty($cache)) {
    $cache = TRUE;
    if (!empty($conf['css_styles'])) {
      foreach ($conf['css_styles'] as $css_style) {
        drupal_add_css(drupal_get_path('module', 'elife_templates') . '/css/' . $css_style);
      }
    }
  }

  return $cache;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_listing_plugin_edit($form, &$form_state) {
  $conf = $form_state['conf'];

  $display_options = _elife_article_listing_display_options();

  // Customise display of elements.
  $form['display_options'] = array(
    '#title' => t('Display elements'),
    '#type' => 'checkboxes',
    '#options' => $display_options,
    '#default_value' => !empty($conf['display_options']) ? $conf['display_options'] : array_keys($display_options),
  );

  // Allow display of image.
  $form['image_style'] = array(
    '#title' => t('Image style'),
    '#type' => 'select',
    '#size' => 1,
    '#options' => image_style_options(FALSE, PASS_THROUGH),
    '#empty_option' => '<' . t('no image') . '>',
    '#default_value' => isset($conf['image_style']) ? $conf['image_style'] : 'elife_striking_image',
    '#multiple' => FALSE,
  );

  // Include css styles.
  $form['css_styles'] = array(
    '#title' => t('Include css/js'),
    '#type' => 'checkboxes',
    '#options' => array(
      'elife-article.css' => 'elife-article.css',
    ),
    '#default_value' => !empty($conf['css_styles']) ? $conf['css_styles'] : NULL,
  );
  return $form;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_listing_plugin_edit_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}
