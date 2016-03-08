<?php
/**
 * @file
 * elife_events.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function elife_events_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_853346c8-1d55-4887-be41-676cd1368af5';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -20;
  $handler->conf = array(
    'title' => 'eLife Event',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'elife_event' => 'elife_event',
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
  $display->layout = 'elife_article';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'main' => NULL,
      'side_lens' => NULL,
      'side_link' => NULL,
      'side_top' => NULL,
      'side_bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '73286912-81d8-4b10-a2e1-66b7ac30ba31';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-42b0c9b6-2729-4896-840a-38f1467255ef';
  $pane->panel = 'main';
  $pane->type = 'node_title';
  $pane->subtype = 'node_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'link' => 0,
    'markup' => 'h2',
    'id' => '',
    'class' => '',
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '42b0c9b6-2729-4896-840a-38f1467255ef';
  $display->content['new-42b0c9b6-2729-4896-840a-38f1467255ef'] = $pane;
  $display->panels['main'][0] = 'new-42b0c9b6-2729-4896-840a-38f1467255ef';
  $pane = new stdClass();
  $pane->pid = 'new-02c324f2-e7bd-48ba-91a3-a14cfc1e7967';
  $pane->panel = 'main';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_elife_e_date';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'long',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
      'show_remaining_days' => 0,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '02c324f2-e7bd-48ba-91a3-a14cfc1e7967';
  $display->content['new-02c324f2-e7bd-48ba-91a3-a14cfc1e7967'] = $pane;
  $display->panels['main'][1] = 'new-02c324f2-e7bd-48ba-91a3-a14cfc1e7967';
  $pane = new stdClass();
  $pane->pid = 'new-9707fdb7-fec0-4f77-bf0f-4def0be0b528';
  $pane->panel = 'main';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_elife_e_text';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '9707fdb7-fec0-4f77-bf0f-4def0be0b528';
  $display->content['new-9707fdb7-fec0-4f77-bf0f-4def0be0b528'] = $pane;
  $display->panels['main'][2] = 'new-9707fdb7-fec0-4f77-bf0f-4def0be0b528';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_853346c8-1d55-4887-be41-676cd1368af5'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function elife_events_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'elife_events';
  $page->task = 'page';
  $page->admin_title = 'eLife Events';
  $page->admin_description = '';
  $page->path = 'events';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_elife_events__panel';
  $handler->task = 'page';
  $handler->subtask = 'elife_events';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'events',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'elife_article';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'main' => NULL,
      'side_lens' => NULL,
      'side_link' => NULL,
      'side_top' => NULL,
      'side_bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Events';
  $display->uuid = '74004ac7-9e07-4152-8efd-49c4a108236e';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-0fa4e7de-9795-4994-a4ad-062c20e68b7a';
  $pane->panel = 'main';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Title',
    'title' => '',
    'body' => '<h1>Events</h1>',
    'format' => 'elife_full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '0fa4e7de-9795-4994-a4ad-062c20e68b7a';
  $display->content['new-0fa4e7de-9795-4994-a4ad-062c20e68b7a'] = $pane;
  $display->panels['main'][0] = 'new-0fa4e7de-9795-4994-a4ad-062c20e68b7a';
  $pane = new stdClass();
  $pane->pid = 'new-6292736d-d7dd-4813-849a-082c937fa636';
  $pane->panel = 'main';
  $pane->type = 'views_panes';
  $pane->subtype = 'elife_events-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '6292736d-d7dd-4813-849a-082c937fa636';
  $display->content['new-6292736d-d7dd-4813-849a-082c937fa636'] = $pane;
  $display->panels['main'][1] = 'new-6292736d-d7dd-4813-849a-082c937fa636';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['elife_events'] = $page;

  return $pages;

}
