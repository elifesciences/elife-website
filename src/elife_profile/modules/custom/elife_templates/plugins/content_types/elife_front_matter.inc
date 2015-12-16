<?php
/**
 * @file
 * plugins/content_types/elife_front_matter.inc
 *
 * Prepare a ctools plugin to provide a display for the front matter items for
 * the front matter section
 */

use Drupal\elife_article\ElifeArticleVersion;

$plugin = array(
  'single' => TRUE,
  'icon' => 'icon_node_form.png',
  'title' => t('eLife Front Matter'),
  'description' => t('Show rendered front matter article.'),
  'category' => t('eLife'),
  'edit form' => 'elife_front_matter_plugin_edit',
  'render callback' => 'elife_front_matter_plugin_render',
  'required context' => new ctools_context_required(t('Front Matter Node'), 'node'),
);

/**
 * Return the front matter items in the elife_front_matter template.
 */
function elife_front_matter_plugin_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->title = t('Front Matter');

  /* @var EntityDrupalWrapper $ewrapper */
  $ewrapper = entity_metadata_wrapper('node', $context->data);
  $reference = $ewrapper->field_elife_fm_reference->value();

  if('elife_article_reference' === $reference->type) {
    $reference = elife_article_reference_get_article_version($reference);
  }

  $variables = array();
  $variables['display'] = ($conf['front_matter_type']) ? $conf['front_matter_type'] : 'regular';

  // If this is a headline item and there is an image prepare the image.
  if (!empty($conf['front_matter_type']) && $conf['front_matter_type'] == 'headline' && $image_properties = $ewrapper->field_elife_image->value()) {
    $front_image = array(
      'style_name' => 'elife_front_matter',
      'path' => $image_properties['uri'],
      'width' => '',
      'height' => '',
      'alt' => $image_properties['alt'],
      'title' => $image_properties['title'],
      'attributes' => array(
        'class' => array(
          'headlines-secondary__top_image',
        ),
      ),
    );
    $variables['image'] = theme('image_style', $front_image);
  }

  $title_classes = array('headlines-secondary__item_title');
  $attribs = array('class' => $title_classes);
  $variables['title'] = l($ewrapper->field_elife_title->value()['safe_value'], 'node/' . $reference->nid, array('attributes' => $attribs, 'html' => TRUE));

  $variables['section'] = ElifeArticleVersion::getSectionCode($ewrapper->field_elife_fm_reference->value());

  // If a relabel value has been supplied then use that value for the section.
  // name other was use standard.
  $relabel = $ewrapper->field_elife_fm_relabel->value();
  if (empty($relabel)) {
    $section_name = ElifeArticleVersion::getSection($variables['section']);
  }
  else {
    $section_name = $relabel;
  }
  $variables['section_name'] = $section_name;

  $block->content = theme('elife_front_matter', $variables);
  return $block;
}

/**
 * Edit form callback for the content type.
 */
function elife_front_matter_plugin_edit($form, &$form_state) {
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
function elife_front_matter_plugin_edit_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}
