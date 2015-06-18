<?php
/**
 * @file
 * elife_collection.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function elife_collection_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__elife_collection';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'eLife Collection',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'elife_collection',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'elife_collection' => 'elife_collection',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '62901465-8e54-4a60-a7f6-30122f6df2f2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9db98164-d8c7-41dc-b070-9d58891ab8b4';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'elife_collection_articles-elife_collection_articles';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_elife_a_full_title_value' => '%node:field-elife-c-keyword',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9db98164-d8c7-41dc-b070-9d58891ab8b4';
    $display->content['new-9db98164-d8c7-41dc-b070-9d58891ab8b4'] = $pane;
    $display->panels['middle'][0] = 'new-9db98164-d8c7-41dc-b070-9d58891ab8b4';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__elife_collection'] = $handler;

  return $export;
}
