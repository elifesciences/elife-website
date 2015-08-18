<?php
/**
 * @file
 * plugins/content_types/elife_profile.inc
 */

$plugin = array(
  'single' => TRUE,
  'icon' => 'icon_node_form.png',
  'title' => t('eLife Profile'),
  'description' => t('Show rendered profile.'),
  'category' => t('eLife'),
  'edit form' => 'elife_about_profile_edit',
  'render callback' => 'elife_about_profile_render',
  'required context' => new ctools_context_required(t('Article Node'), 'node'),
);

/**
 * Prepare output for profile.
 */
function elife_about_profile_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->title = t('Profile');

  $profile = $context->data;
  $lang = $profile->language;
  $variables = array();
  $extra = array();
  $attributes = array();

  $variables['title'] = (($profile->field_elife_fname) ? $profile->field_elife_fname[$lang][0]['value'] . ' ' : '') . $profile->title;

  if (!empty($profile->field_elife_profile_title)) {
    $variables['profile_title'] = $profile->field_elife_profile_title[$lang][0]['value'];
  }

  if (!empty($profile->field_elife_images)) {
    $image = $profile->field_elife_images[$lang][0];
    $profile_image = array(
      'style_name' => 'elife_profile',
      'path' => $image['uri'],
      'width' => '',
      'height' => '',
      'alt' => $variables['title'],
      'attributes' => array(
        'class' => array(
          'person-profile__biog-image',
          'person-profile__biog-image--in-flow',
        ),
      ),
    );
    $variables['image_extra'] = theme('image_style', $profile_image);
    $extra['image_extra'] = $variables['image_extra'];
  }

  if (!empty($profile->field_elife_affiliation)) {
    $variables['affiliation'] = $profile->field_elife_affiliation[$lang][0]['value'];
  }

  // Only introduce research focus and experimental org on /about.
  if (current_path() == 'about') {
    $categories = array(
      'research_focus' => 'field_elife_research_focus',
      'experimental_org' => 'field_elife_experimental_org',
    );

    foreach ($categories as $category => $field) {
      if (!empty($profile->{$field})) {
        $cats = $profile->{$field}[$lang];
        $items = array();
        foreach ($cats as $cat) {
          if (!empty($cat['value'])) {
            $items[] = array(
              'data' => $cat['value'],
              'class' => array(
                'person-profile__list-item',
                'p-category',
                'category',
              ),
            );
          }
        }

        if (!empty($items)) {
          $variables[$category] = theme('item_list', array('items' => $items));
        }
      }
    }
  }

  if (!empty($profile->body) && !empty($profile->body[$lang][0]['value']) && $body = field_view_field('node', $profile, 'body', array('label' => 'hidden'))) {
    $extra['details'] = render($body);

    if ($additional = field_view_field('node', $profile, 'field_elife_additional_body', array('label' => 'hidden'))) {
      if ($additional_label = field_view_field('node', $profile, 'field_elife_additional_label', array('label' => 'hidden'))) {
        $extra['additional_label'] = render($additional_label);
      }

      $extra['additional'] = render($additional);
      $variables['coi'] = TRUE;
    }

    $variables['profile_extra'] = theme('elife_profile_extra', $extra);
    $attributes['class'][] = 'person-profile__link-js-hook';
  }

  if (!empty($attributes)) {
    $variables['profile_attributes'] = drupal_attributes($attributes);
  }

  $block->content = theme('elife_profile', $variables);
  return $block;
}

/**
 * Edit form callback for the content type.
 */
function elife_about_profile_edit($form, &$form_state) {
  return $form;
}
