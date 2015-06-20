<?php
/**
 * @file
 * plugins/content_types/elife_coverpage_cover.inc
 *
 * Prepare a ctools plugin to provide a display for the cover items for the
 * front matter section
 */

$plugin = array(
  'single' => TRUE,
  'icon' => 'icon_node_form.png',
  'title' => t('eLife Cover article'),
  'description' => t('Show rendered cover article.'),
  'category' => t('eLife'),
  'edit form' => 'elife_coverpage_cover_edit',
  'render callback' => 'elife_coverpage_cover_render',
  'required context' => new ctools_context_required(t('Article Node'), 'node'),
);

/**
 * Return the cover article in the elife_cover_article template.
 */
function elife_coverpage_cover_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->title = t('Cover article');
/*
  $cover = $context->data;
  $lang = $cover->language;
  if (!empty($cover->field_elife_reference)) {
    // There is a node reference - fetch the node and use it's section type
    // and reference link.
    $reference_nid = $cover->field_elife_reference[$lang][0]['nid'];
    $reference_node = node_load($reference_nid);
    $section = elife_article_get_section($reference_node);
    $reference = 'node/' . $reference_nid;
  }
  elseif (!empty($cover->field_elife_reference_url)) {
    // Probably an external url so we have no classification possible.
    // Use the default 'other' value.
    $section = elife_article_get_section();
    $reference = $cover->field_elife_reference_url[$lang][0]['value'];
  }
  else {
    // If a link has not been provided, link to the homepage.
    // Get the default 'other' value.
    $section = elife_article_get_section();
    $reference = '';
  }
  $variables = array();

  $title_classes = array('headline-first__title_link');
  if (empty($reference)) {
    $variables['title'] = $cover->title;
  }
  else {
    $attrs = array(
      'attributes' => array('class' => $title_classes),
      'html' => TRUE,
    );

    $variables['title'] = l($cover->title, $reference, $attrs);
  }

  $text_appearance = $cover->field_elife_text_appearance[$lang][0]['value'];
  $variables['additional_classes'] = array('headline-first--' . $text_appearance . '-text');

  // If there is an image the introduce the caption and add an additional class.
  if (!empty($cover->field_elife_images)) {
    if (!empty($cover->field_elife_images[$lang][0]['title'])) {
      $variables['caption'] = $cover->field_elife_images[$lang][0]['title'];
    }
    $variables['additional_classes'][] = 'headline-first--has-image';
  }

  // If there's no action label, use a default, otherwise use the one supplied.
  if (empty($cover->field_elife_action_label) ||
      empty($cover->field_elife_action_label[$lang][0]['value'])) {
    $read_more_text = t('Read more');
  }
  else {
    $read_more_text = $cover->field_elife_action_label[$lang][0]['value'];
  }
  $read_more_classes = array(
    'headline-first__read_more',
    'headline-first__read_more--' . $section['code'],
  );
  if (!empty($reference)) {
    $attrs = array('attributes' => array('class' => $read_more_classes));
    $variables['read_more'] = l($read_more_text, $reference, $attrs);
  }
*/
  $variables = array();
  $block->content = theme('elife_coverpage_cover', $variables);
  return $block;
}

/**
 * Edit form callback for the content type.
 */
function elife_coverpage_cover_edit($form, &$form_state) {
  return $form;
}
