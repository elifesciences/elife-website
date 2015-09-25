<?php

$plugin = array(
  'single' => TRUE,
  'icon' => 'icon_node_form.png',
  'title' => t('eLife Hero Block Text'),
  'description' => t('Show hero block text.'),
  'category' => t('eLife'),
  'edit form' => 'elife_hero_block_text_plugin_edit',
  'render callback' => 'elife_hero_block_text_plugin_render',
);

function elife_hero_block_text_plugin_render($subtype, $conf, $args, $context) {
  $hero_block = elife_hero_block_for_path();

  if (empty($hero_block) || empty($hero_block->field_elife_h_text)) {
    return NULL;
  }

  $block = new stdClass();
  $block->content = '<div style="border-bottom: 1px solid #eee; margin-bottom: 1em; padding-bottom: 1em;">' . $hero_block->field_elife_h_text[LANGUAGE_NONE][0]['safe_value'] . '</div>';

  return $block;
}

function elife_hero_block_text_plugin_edit($form, &$form_state) {
  $conf = $form_state['conf'];

  return $form;
}

function elife_hero_block_text_plugin_edit_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}
