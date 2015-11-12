<?php

$plugin = array(
  'single' => TRUE,
  'icon' => 'icon_node_form.png',
  'title' => t('eLife Hero Block'),
  'description' => t('Show hero block.'),
  'category' => t('eLife'),
  'edit form' => 'elife_hero_block_plugin_edit',
  'render callback' => 'elife_hero_block_plugin_render',
);

function elife_hero_block_plugin_render($subtype, $conf, $args, $context) {
  $content = '';
  drupal_alter('elife_hero_block', $content);

  if (empty($content)) {
    return NULL;
  }

  drupal_add_css(drupal_get_path('module', 'elife_hero_block') . '/css/hero-block.css');
  $block = new stdClass();
  $block->content = $content;

  return $block;
}

function elife_hero_block_plugin_edit($form, &$form_state) {
  $conf = $form_state['conf'];

  return $form;
}

function elife_hero_block_plugin_edit_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}
