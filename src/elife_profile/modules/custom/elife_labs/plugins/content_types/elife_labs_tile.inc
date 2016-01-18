<?php
/**
 * @file
 * plugins/content_types/elife_labs_tile.inc
 */

$plugin = array(
  'single' => TRUE,
  'icon' => 'icon_node_form.png',
  'title' => t('eLife Labs Tile'),
  'description' => t('Show a rendered labs landing page tile.'),
  'category' => t('eLife'),
  'edit form' => 'elife_labs_tile_edit',
  'render callback' => 'elife_labs_tile_render',
  'required context' => new ctools_context_required(t('Labs Entry Node'), 'node'),
);

/**
 * Prepare output for tile.
 */
function elife_labs_tile_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->title = t('eLife Labs Tile');

  $node = $context->data;

  if (!empty($node->field_elife_l_url[LANGUAGE_NONE])) {
    $url = $node->field_elife_l_url[LANGUAGE_NONE][0]['url'];
  }

  $tile_classes = ['elife-labs-tile'];

  $title = $node->field_elife_title[LANGUAGE_NONE][0]['safe_value'];
  if (!empty($node->field_elife_l_description[LANGUAGE_NONE])) {
    $description = $node->field_elife_l_description[LANGUAGE_NONE][0]['safe_value'];
    $tile_classes[] = 'elife-labs-tile--description';
  }
  elseif (!empty($node->field_elife_l_image[LANGUAGE_NONE])) {
    $imguri = $node->field_elife_l_image[LANGUAGE_NONE][0]['uri'];
    $alt = $node->field_elife_l_image[LANGUAGE_NONE][0]['alt'];
    $image_style = [
      'path' => $imguri,
      'attributes' => ['class' => ['elife-labs-tile__image']],
    ];
    $image_style['style_name'] = 'elife_labs_tile';
    if (!empty($alt)) {
      $image_style['alt'] = $alt;
    }
    $bg_image = theme('image_style', $image_style);
    $tile_classes[] = 'elife-labs-tile--wide-image';
  }

  /* tile-level indication that there is a link for this tile */
  if (empty($url)) {
    $tile_classes[] = 'elife-labs-tile--notlinked';
  }
  else {
    $tile_classes[] = 'elife-labs-tile--linked';
  }

  /* create the html */
  $block->content = '';
  $block->content .= '<li class="' . implode(' ', $tile_classes) . '">';
  if (!empty($url)) {
    $block->content .= '<a class="elife-labs-tile__link" href="' . check_url($url) . '">';
  }
  $block->content .= '<h3 class="elife-labs-tile__title">' . $title . '</h3>';
  if (!empty($description)) {
    $block->content .= '<p class="elife-labs-tile__description">' . $description . '</p>';
  }
  if (!empty($bg_image)) {
    $block->content .= $bg_image;
  }
  if (!empty($url)) {
    $block->content .= '</a>';
  }
  $block->content .= '</li>';

  if (!empty($url)) {
    // Run the URL through Pathologic.
    $block->content = check_markup($block->content, 'elife_labs_tile', LANGUAGE_NONE);
  }

  return $block;
}

/**
 * Edit form callback for the content type.
 */
function elife_labs_tile_edit($form, &$form_state) {
  return $form;
}

/**
 * Edit form callback for the content type.
 */
function elife_labs_tile_edit_form_submit(&$form, &$form_state) {
  // Nothing
}
