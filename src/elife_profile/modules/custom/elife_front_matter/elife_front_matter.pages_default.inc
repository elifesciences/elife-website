<?php
/**
 * @file
 * elife_front_matter.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function elife_front_matter_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'elife_cover';
  $page->task = 'page';
  $page->admin_title = 'eLife: Cover';
  $page->admin_description = '';
  $page->path = 'cover';
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
  $handler->name = 'page_elife_cover__panel_context_c2971eed-4f1c-4ae9-a563-91607e3c008c';
  $handler->task = 'page';
  $handler->subtask = 'elife_cover';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'elife-home-page',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'elife_omega_coverpage';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'banner' => NULL,
      'middle' => NULL,
      'nav' => NULL,
      'action' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '49437917-fdcf-4ab5-8915-f1620e70a146';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d5edf458-2389-481a-8804-299d06f2d855';
    $pane->panel = 'banner';
    $pane->type = 'block';
    $pane->subtype = 'elife_front_matter-elife_front_matter';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd5edf458-2389-481a-8804-299d06f2d855';
    $display->content['new-d5edf458-2389-481a-8804-299d06f2d855'] = $pane;
    $display->panels['banner'][0] = 'new-d5edf458-2389-481a-8804-299d06f2d855';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['elife_cover'] = $page;

  return $pages;

}
