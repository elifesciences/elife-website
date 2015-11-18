<?php

$plugin = array(
  'single' => TRUE,
  'icon' => 'icon_node_form.png',
  'title' => t('eLife Podcast Sidebar'),
  'description' => t('Show podcast sidebar.'),
  'category' => t('eLife'),
  'edit form' => 'elife_podcast_sidebar_plugin_edit',
  'render callback' => 'elife_podcast_sidebar_plugin_render',
);

function elife_podcast_sidebar_plugin_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->content = theme('elife_podcast_sidebar');

  return $block;
}

function elife_podcast_sidebar_plugin_edit($form, &$form_state) {
  $conf = $form_state['conf'];

  return $form;
}

function elife_podcast_sidebar_plugin_edit_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}
