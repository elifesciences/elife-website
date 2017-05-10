<?php
/**
 * @file
 * elife_upcoming_articles.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function elife_upcoming_articles_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'elife_upcoming_articles';
  $page->task = 'page';
  $page->admin_title = 'Upcoming articles';
  $page->admin_description = '';
  $page->path = 'upcoming';
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
  $handler->name = 'page_elife_upcoming_articles__panel';
  $handler->task = 'page';
  $handler->subtask = 'elife_upcoming_articles';
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
            'paths' => 'upcoming',
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
  $display->title = 'Upcoming';
  $display->uuid = 'f2cc2b95-504e-4989-8cbc-7bb961414d2d';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-17bed968-4ef7-4e21-9946-203b7b8c89ed';
  $pane->panel = 'main';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<h1>Upcoming</h1>',
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
  $pane->uuid = '17bed968-4ef7-4e21-9946-203b7b8c89ed';
  $display->content['new-17bed968-4ef7-4e21-9946-203b7b8c89ed'] = $pane;
  $display->panels['main'][0] = 'new-17bed968-4ef7-4e21-9946-203b7b8c89ed';
  $pane = new stdClass();
  $pane->pid = 'new-6c195b3d-5923-4eb4-ba14-7831df78c5b9';
  $pane->panel = 'main';
  $pane->type = 'views_panes';
  $pane->subtype = 'elife_upcoming_articles-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '6c195b3d-5923-4eb4-ba14-7831df78c5b9';
  $display->content['new-6c195b3d-5923-4eb4-ba14-7831df78c5b9'] = $pane;
  $display->panels['main'][1] = 'new-6c195b3d-5923-4eb4-ba14-7831df78c5b9';
  $pane = new stdClass();
  $pane->pid = 'new-13fdc934-da2d-4c91-aedf-8b517e8108e0';
  $pane->panel = 'side_top';
  $pane->type = 'elife_content_alerts_sign_up';
  $pane->subtype = 'elife_content_alerts_sign_up';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'buttons' => NULL,
    'aligner_start' => NULL,
    'override_title' => 1,
    'override_title_text' => 'Sign up to alerts on upcoming content from <i>eLife</i>',
    'override_title_heading' => 'h2',
    'aligner_stop' => NULL,
    'override_title_markup' => NULL,
    'gid' => '24',
    'custom_6' => 'poa_rev141013',
    'form_build_id' => 'form-NLsoIQ2HsBdrzaLbX-3EqzFthUnVN9u29u1O6YKVCKE',
    'form_token' => 'NEBokrsiXJQQonnKIA-W0e-LQpIUgfS-KUXQFUEz0Es',
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
  $pane->uuid = '13fdc934-da2d-4c91-aedf-8b517e8108e0';
  $display->content['new-13fdc934-da2d-4c91-aedf-8b517e8108e0'] = $pane;
  $display->panels['side_top'][0] = 'new-13fdc934-da2d-4c91-aedf-8b517e8108e0';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-6c195b3d-5923-4eb4-ba14-7831df78c5b9';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['elife_upcoming_articles'] = $page;

  return $pages;

}
