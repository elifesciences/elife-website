<?php
/**
 * @file
 * plugins/content_types/elife_coverpage_front_matter.inc
 *
 * Prepare a ctools plugin to provide a display for the front matter items for
 * the front matter section
 */

$plugin = [
  'single' => TRUE,
  'icon' => 'icon_node_form.png',
  'title' => t('eLife Early Careers Spotlight'),
  'description' => t('Show rendered early careers spotlight item.'),
  'category' => t('eLife'),
  'edit form' => 'elife_early_careers_spotlight_edit',
  'render callback' => 'elife_early_careers_spotlight_render',
  'required context' => new ctools_context_required(t('Article Node'), 'node'),
];

/**
 * Return the spotlight items in the elife_early_careers_spotlight template.
 */
function elife_early_careers_spotlight_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->title = t('Early Careers Spotlight');

  $spotlight = $context->data;
  $lang = $spotlight->language;
  $reference = '';

  if (!empty($spotlight->field_elife_reference)) {
    $reference_nid = $spotlight->field_elife_reference[$lang][0]['nid'];
    $reference = 'node/' . $reference_nid;
  }
  elseif (!empty($spotlight->field_elife_reference_url)) {
    $reference = $spotlight->field_elife_reference_url[$lang][0]['value'];
  }
  $variables = [];

  if (!empty($reference)) {
    $variables['title'] = l($spotlight->title, $reference, ['attributes' => ['class' => []], 'html' => TRUE]);
  }
  else {
    $variables['title'] = $spotlight->title;
  }

  if (!empty($spotlight->body) && !empty($spotlight->body[$lang][0]['value']) && $body = field_view_field('node', $spotlight, 'body', ['label' => 'hidden'])) {
    unset($body['#theme']);
    $variables['body'] = render($body);
  }

  if ($section_heading = field_view_field('node', $spotlight, 'field_elife_section_heading', ['label' => 'hidden'])) {
    unset($section_heading['#theme']);
    $variables['section_heading'] = render($section_heading);
  }

  if ($view_more_url = field_view_field('node', $spotlight, 'field_elife_view_more_url', ['label' => 'hidden'])) {
    if ($view_more_label = field_view_field('node', $spotlight, 'field_elife_view_more_label', ['label' => 'hidden'])) {
      unset($view_more_label['#theme']);
      $view_more_label = render($view_more_label);
    }
    else {
      $view_more_label = t('View more');
    }
    unset($view_more_url['#theme']);
    $view_more_url = render($view_more_url);
    $variables['view_more'] = l($view_more_label, $view_more_url, ['attributes' => ['class' => ['ec-section--latest__more_link']], 'html' => TRUE]);
  }

  $block->content = theme('elife_early_careers_spotlight', $variables);
  return $block;
}

/**
 * Edit form callback for the content type.
 */
function elife_early_careers_spotlight_edit($form, &$form_state) {
  // Nothing.
  return $form;
}

/**
 * Edit form callback for the content type.
 */
function elife_early_careers_spotlight_edit_submit(&$form, &$form_state) {
  // Nothing.
}
