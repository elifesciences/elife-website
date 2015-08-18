<?php
/**
 * @file
 * plugins/content_types/elife_profile.inc
 */

$plugin = [
  'single' => TRUE,
  'icon' => 'icon_node_form.png',
  'title' => t('eLife Profile (Early Careers)'),
  'description' => t('Show rendered profile.'),
  'category' => t('eLife'),
  'edit form' => 'elife_early_careers_profile_edit',
  'render callback' => 'elife_early_careers_profile_render',
  'required context' => new ctools_context_required(t('Article Node'), 'node'),
];

/**
 * Prepare output for profile.
 */
function elife_early_careers_profile_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->title = t('Profile');

  $profile = $context->data;
  $lang = $profile->language;
  $variables = [];

  $variables['title'] = (($profile->field_elife_fname) ? $profile->field_elife_fname[$lang][0]['value'] . ' ' : '') . $profile->title;

  if (!empty($profile->field_elife_profile_title)) {
    $variables['profile_title'] = $profile->field_elife_profile_title[$lang][0]['value'];
  }

  if (!empty($profile->field_elife_images)) {
    $image = $profile->field_elife_images[$lang][0];
    $profile_image = [
      'style_name' => 'elife_career_profile',
      'path' => $image['uri'],
      'width' => '',
      'height' => '',
      'alt' => $variables['title'],
      'attributes' => [
        'class' => [
          'ec-profiles__person_biog_image',
          'ec-profiles__person_biog_image--in-flow',
        ],
      ],
    ];
    $variables['image_extra'] = theme('image_style', $profile_image);
    $extra['image_extra'] = $variables['image_extra'];
  }

  if (!empty($profile->field_elife_affiliation)) {
    $variables['affiliation'] = $profile->field_elife_affiliation[$lang][0]['value'];
  }

  if (!empty($profile->body) && !empty($profile->body[$lang][0]['value']) && $body = field_view_field('node', $profile, 'body', ['label' => 'hidden'])) {
    $extra['details'] = render($body);

    if ($additional = field_view_field('node', $profile, 'field_elife_additional_body', ['label' => 'hidden'])) {
      if ($additional_label = field_view_field('node', $profile, 'field_elife_additional_label', ['label' => 'hidden'])) {
        $extra['additional_label'] = render($additional_label);
      }

      $extra['additional'] = render($additional);
      $variables['coi'] = TRUE;
    }

    $variables['profile_extra'] = theme('elife_early_careers_profile_extra', $extra);
    $attributes['class'][] = 'ec-profiles__person_link_js_hook';
  }

  if (!empty($attributes)) {
    $variables['profile_attributes'] = drupal_attributes($attributes);
  }

  $block->content = theme('elife_early_careers_profile', $variables);
  return $block;
}

/**
 * Edit form callback for the content type.
 */
function elife_early_careers_profile_edit($form, &$form_state) {
  return $form;
}
