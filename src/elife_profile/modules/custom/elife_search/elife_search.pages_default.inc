<?php
/**
 * @file
 * elife_search.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function elife_search_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view__panel_context_84ba7cb7-4496-4023-b19f-cc3fa8388675';
  $handler->task = 'term_view';
  $handler->subtask = '';
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
    'name' => '',
    'access' => array(
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
  $display->title = '%term:name';
  $display->uuid = 'c1d3070e-d3f0-40f6-bc1c-c33aef5816aa';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-668225f4-c643-4d6c-b2c3-8cf156155240';
    $pane->panel = 'main';
    $pane->type = 'views_panes';
    $pane->subtype = 'elife_category-elife_category_description';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_elife_ca_category_value' => '%term:name',
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
    $pane->uuid = '668225f4-c643-4d6c-b2c3-8cf156155240';
    $display->content['new-668225f4-c643-4d6c-b2c3-8cf156155240'] = $pane;
    $display->panels['main'][0] = 'new-668225f4-c643-4d6c-b2c3-8cf156155240';
    $pane = new stdClass();
    $pane->pid = 'new-1c0723b7-ffe3-47db-af48-97c17d58ea22';
    $pane->panel = 'side_bottom';
    $pane->type = 'elife_content_alerts_sign_up';
    $pane->subtype = 'elife_content_alerts_sign_up';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'buttons' => NULL,
      'aligner_start' => NULL,
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'aligner_stop' => NULL,
      'override_title_markup' => NULL,
      'gid' => '',
      'custom_6' => '',
      'form_build_id' => 'form-auvcUw0sau7YGakqRhbqESBKK8mmkhcHLImLve0GvqQ',
      'form_token' => 'kkBqb1TrPm_RaRvb52R4WwfOsvkFd1O3AfyYcF8-4Cs',
      'form_id' => 'elife_content_alerts_sign_up_edit',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1c0723b7-ffe3-47db-af48-97c17d58ea22';
    $display->content['new-1c0723b7-ffe3-47db-af48-97c17d58ea22'] = $pane;
    $display->panels['side_bottom'][0] = 'new-1c0723b7-ffe3-47db-af48-97c17d58ea22';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-668225f4-c643-4d6c-b2c3-8cf156155240';
  $handler->conf['display'] = $display;
  $export['term_view__panel_context_84ba7cb7-4496-4023-b19f-cc3fa8388675'] = $handler;

  return $export;
}
