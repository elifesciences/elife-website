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
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'front',
          'settings' => NULL,
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
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
  $pane->pid = 'new-03eb6718-8f00-44c5-88e0-30d129cf59d1';
  $pane->panel = 'action';
  $pane->type = 'elife_front_matter_action';
  $pane->subtype = 'elife_front_matter_action';
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
  $pane->uuid = '03eb6718-8f00-44c5-88e0-30d129cf59d1';
  $display->content['new-03eb6718-8f00-44c5-88e0-30d129cf59d1'] = $pane;
  $display->panels['action'][0] = 'new-03eb6718-8f00-44c5-88e0-30d129cf59d1';
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
  $pane = new stdClass();
  $pane->pid = 'new-079f17e6-90a2-4dde-93eb-659a9982cf2d';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'elife_latest_research-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '079f17e6-90a2-4dde-93eb-659a9982cf2d';
  $display->content['new-079f17e6-90a2-4dde-93eb-659a9982cf2d'] = $pane;
  $display->panels['middle'][0] = 'new-079f17e6-90a2-4dde-93eb-659a9982cf2d';
  $pane = new stdClass();
  $pane->pid = 'new-58388dd2-87cc-43f6-853c-9150b44b0671';
  $pane->panel = 'nav';
  $pane->type = 'elife_home_nav';
  $pane->subtype = 'elife_home_nav';
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
  $pane->uuid = '58388dd2-87cc-43f6-853c-9150b44b0671';
  $display->content['new-58388dd2-87cc-43f6-853c-9150b44b0671'] = $pane;
  $display->panels['nav'][0] = 'new-58388dd2-87cc-43f6-853c-9150b44b0671';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['elife_cover'] = $page;

  return $pages;

}
