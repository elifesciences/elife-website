<?php
/**
 * @file
 * plugins/content_types/elife_coverpage_front_matter.inc
 *
 * Prepare a ctools plugin to provide a display for the front matter items for
 * the front matter section
 */

$plugin = array(
  'single' => TRUE,
  'icon' => 'icon_node_form.png',
  'title' => t('eLife Front Matter'),
  'description' => t('Show rendered front matter article.'),
  'category' => t('eLife'),
  'edit form' => 'elife_coverpage_front_matter_edit',
  'render callback' => 'elife_coverpage_front_matter_render',
  'required context' => new ctools_context_required(t('Article Node'), 'node'),
);

/**
 * Return the front matter items in the elife_front_matter template.
 */
function elife_coverpage_front_matter_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->title = t('Front Matter');

  $variables = array();
  /*
  $front = $context->data;
  $lang = $front->language;
  $reference = '';
  $section = elife_article_get_section();
  if (!empty($front->field_elife_reference)) {
    $reference_nid = $front->field_elife_reference[$lang][0]['nid'];
    $reference_node = node_load($reference_nid);
    $section = elife_article_get_section($reference_node);
    $reference = 'node/' . $reference_nid;
  }
  elseif (!empty($front->field_elife_reference_url)) {
    $reference = $front->field_elife_reference_url[$lang][0]['value'];
  }
  $variables = array();

  $variables['display'] = ($conf['front_matter_type']) ? $conf['front_matter_type'] : 'regular';

  // If this is a headline item and there is an image prepare the image.
  if (!empty($conf['front_matter_type']) && $conf['front_matter_type'] == 'headline' && !empty($front->field_elife_images)) {
    $image = $front->field_elife_images[$lang][0];
    $front_image = array(
      'style_name' => 'elife_coverpage_front_matter',
      'path' => $image['uri'],
      'width' => '',
      'height' => '',
      'alt' => $image['alt'],
      'title' => $image['title'],
      'attributes' => array(
        'class' => array(
          'headlines-secondary__top_image',
        ),
      ),
    );
    $variables['image'] = theme('image_style', $front_image);
  }

  $title_classes = array('headlines-secondary__item_title');

  if (empty($reference)) {
    $variables['title'] = $front->title;
  }
  else {
    $attribs = array('class' => $title_classes);
    $variables['title'] = l($front->title, $reference, array('attributes' => $attribs, 'html' => TRUE));
  }

  $variables['section'] = $section['code'];

  // If a relabel value has been supplied then use that value for the section.
  // name other was use standard.
  $section_name = (!empty($front->field_elife_relabel) && !empty($front->field_elife_relabel[$lang][0]['value'])) ? $front->field_elife_relabel[$lang][0]['value'] : $section['name'];
  $variables['section_name'] = $section_name;*/

  $block->content = theme('elife_coverpage_front_matter', $variables);
  return $block;
}

/**
 * Edit form callback for the content type.
 */
function elife_coverpage_front_matter_edit($form, &$form_state) {
  $conf = $form_state['conf'];

  // Allow front matter type to be set in views display: regular or headline.
  $form['front_matter_type'] = array(
    '#type' => 'select',
    '#title' => t('Display'),
    '#size' => 1,
    '#options' => array(
      'regular' => t('Regular'),
      'headline' => t('Headline'),
    ),
    '#multiple' => FALSE,
    '#description' => t('Headlines include an image'),
    '#default_value' => ($conf['front_matter_type']) ? $conf['front_matter_type'] : 'regular',
  );
  return $form;
}

/**
 * Edit form callback for the content type.
 */
function elife_coverpage_front_matter_edit_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}
