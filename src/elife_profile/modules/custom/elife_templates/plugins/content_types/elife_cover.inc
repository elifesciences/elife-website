<?php
/**
 * @file
 * plugins/content_types/elife_cover.inc
 *
 * Prepare a ctools plugin to provide a display for the cover items for the
 * front matter section
 */

use Drupal\elife_article\ElifeArticleVersion;

$plugin = array(
  'single' => TRUE,
  'icon' => 'icon_node_form.png',
  'title' => t('eLife Cover article'),
  'description' => t('Show rendered cover article.'),
  'category' => t('eLife'),
  'edit form' => 'elife_cover_plugin_edit',
  'render callback' => 'elife_cover_plugin_render',
  'required context' => new ctools_context_required(t('Cover Node'), 'node'),
);

/**
 * Return the cover article in the elife_cover template.
 */
function elife_cover_plugin_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->title = t('Cover article');

  /* @var EntityDrupalWrapper $ewrapper */
  $ewrapper = entity_metadata_wrapper('node', $context->data);
  $reference = $ewrapper->field_elife_fm_reference->value();
  $section = ElifeArticleVersion::getSection($reference, $ewrapper->field_elife_fm_reference_type->value());

  $title_classes = array('headline-first__title_link');
  $attrs = array(
    'attributes' => array('class' => $title_classes),
    'html' => TRUE,
  );

  $variables = array();
  $variables['title'] = l($ewrapper->title->value(), $reference, $attrs);

  $text_appearance = $ewrapper->field_elife_c_text_appearance->value();
  $variables['additional_classes'] = array('headline-first--' . $text_appearance . '-text');

  // If there is an image the introduce the caption and add an additional class.
  if ($ewrapper->field_elife_image->value()) {
    if ($ewrapper->field_elife_image->title) {
      $variables['caption'] = $ewrapper->field_elife_image->title->value();
    }
    $variables['additional_classes'][] = 'headline-first--has-image';
  }

  // If there's no action label, use a default, otherwise use the one supplied.
  $action_label = $ewrapper->field_elife_c_action_label->value();
  if (empty($action_label)) {
    $read_more_text = t('Read more');
  }
  else {
    $read_more_text = $action_label;
  }
  $read_more_classes = array(
    'headline-first__read_more',
    'headline-first__read_more--' . $section['code'],
  );
  if (!empty($reference)) {
    $attrs = array('attributes' => array('class' => $read_more_classes));
    $variables['read_more'] = l($read_more_text, $reference, $attrs);
  }

  $block->content = theme('elife_cover', $variables);
  return $block;
}

/**
 * Edit form callback for the content type.
 */
function elife_cover_plugin_edit($form, &$form_state) {
  return $form;
}
