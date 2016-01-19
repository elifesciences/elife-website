<?php
/**
 * @file
 * elife_labs.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function elife_labs_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'elife_labs';
  $page->task = 'page';
  $page->admin_title = 'eLife Labs';
  $page->admin_description = '';
  $page->path = 'labs';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_elife_labs__panel';
  $handler->task = 'page';
  $handler->subtask = 'elife_labs';
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
            'paths' => 'labs',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'description' => array(
          'value' => 'eLife - Open access to the most promising advances in science',
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'elife_clean';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '600b1845-f255-408e-b91e-5f2bb67d1a8e';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-bf424fc7-0dff-4caa-8bef-51163a296ad4';
  $pane->panel = 'content';
  $pane->type = 'views_panes';
  $pane->subtype = 'elife_labs-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '%title',
    'override_title_heading' => 'h1',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'bf424fc7-0dff-4caa-8bef-51163a296ad4';
  $display->content['new-bf424fc7-0dff-4caa-8bef-51163a296ad4'] = $pane;
  $display->panels['content'][0] = 'new-bf424fc7-0dff-4caa-8bef-51163a296ad4';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-bf424fc7-0dff-4caa-8bef-51163a296ad4';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['elife_labs'] = $page;

  return $pages;

}
