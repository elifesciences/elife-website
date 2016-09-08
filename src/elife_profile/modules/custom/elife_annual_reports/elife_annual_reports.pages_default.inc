<?php
/**
 * @file
 * elife_annual_reports.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function elife_annual_reports_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'elife_annual_reports';
  $page->task = 'page';
  $page->admin_title = 'eLife Annual Reports';
  $page->admin_description = '';
  $page->path = 'annual-reports';
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
  $handler->name = 'page_elife_annual_reports__panel';
  $handler->task = 'page';
  $handler->subtask = 'elife_annual_reports';
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
            'paths' => 'annual-reports',
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
      'content' => NULL,
      'top' => NULL,
      'main' => NULL,
      'side_lens' => NULL,
      'side_link' => NULL,
      'side_top' => NULL,
      'side_bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Annual reports';
  $display->uuid = '894b8f7f-06ea-4b26-a081-5628b38f07ac';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-7aefc06e-8cae-4610-8678-610445b4901d';
  $pane->panel = 'main';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<h1>Annual reports</h1>',
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
  $pane->uuid = '7aefc06e-8cae-4610-8678-610445b4901d';
  $display->content['new-7aefc06e-8cae-4610-8678-610445b4901d'] = $pane;
  $display->panels['main'][0] = 'new-7aefc06e-8cae-4610-8678-610445b4901d';
  $pane = new stdClass();
  $pane->pid = 'new-6bf48bd0-1e75-4a97-9fbe-5a12aabf8b9d';
  $pane->panel = 'main';
  $pane->type = 'views_panes';
  $pane->subtype = 'elife_annual_reports-panel_pane_1';
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
  $pane->uuid = '6bf48bd0-1e75-4a97-9fbe-5a12aabf8b9d';
  $display->content['new-6bf48bd0-1e75-4a97-9fbe-5a12aabf8b9d'] = $pane;
  $display->panels['main'][1] = 'new-6bf48bd0-1e75-4a97-9fbe-5a12aabf8b9d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-6bf48bd0-1e75-4a97-9fbe-5a12aabf8b9d';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['elife_annual_reports'] = $page;

  return $pages;

}
