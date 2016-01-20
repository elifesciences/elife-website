<?php
/**
 * @file
 * elife_content_alerts.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function elife_content_alerts_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'elife_content_alerts_ui';
  $page->task = 'page';
  $page->admin_title = 'Content Alerts UI';
  $page->admin_description = '';
  $page->path = 'elife/content_alerts/!status/!dates';
  $page->access = array(
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'status' => array(
      'id' => 1,
      'identifier' => 'Status',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
    'dates' => array(
      'id' => 2,
      'identifier' => 'Dates',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_elife_content_alerts_ui__panel';
  $handler->task = 'page';
  $handler->subtask = 'elife_content_alerts_ui';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Content Alerts UI',
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
          'name' => 'perm',
          'settings' => array(
            'perm' => 'access elife content alerts json',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'robots' => array(
          'value' => array(
            'noindex' => 'noindex',
            'nofollow' => 'nofollow',
            'noarchive' => 'noarchive',
            'nosnippet' => 'nosnippet',
            'noodp' => 'noodp',
            'noydir' => 'noydir',
            'noimageindex' => 'noimageindex',
            'notranslate' => 'notranslate',
            'index' => 0,
            'follow' => 0,
          ),
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'elife_content_alerts';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'content' => NULL,
      'header' => NULL,
      'categories' => NULL,
      'front' => NULL,
      'alert_date' => NULL,
      'logo' => NULL,
      'intro' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '1c1f07b2-4314-4653-9b66-726200c50218';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-6067403b-0edc-49e0-818d-0b8845cce90b';
  $pane->panel = 'alert_date';
  $pane->type = 'block';
  $pane->subtype = 'elife_content_alerts-elife_content_alerts_date';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '6067403b-0edc-49e0-818d-0b8845cce90b';
  $display->content['new-6067403b-0edc-49e0-818d-0b8845cce90b'] = $pane;
  $display->panels['alert_date'][0] = 'new-6067403b-0edc-49e0-818d-0b8845cce90b';
  $pane = new stdClass();
  $pane->pid = 'new-143ec083-b8c8-4e2c-8d8c-37a7727774a1';
  $pane->panel = 'categories';
  $pane->type = 'views';
  $pane->subtype = 'elife_content_alerts';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'content_alerts_categories',
    'context' => array(
      0 => 'argument_string_2.raw',
      1 => 'argument_string_1.raw',
    ),
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
  $pane->uuid = '143ec083-b8c8-4e2c-8d8c-37a7727774a1';
  $display->content['new-143ec083-b8c8-4e2c-8d8c-37a7727774a1'] = $pane;
  $display->panels['categories'][0] = 'new-143ec083-b8c8-4e2c-8d8c-37a7727774a1';
  $pane = new stdClass();
  $pane->pid = 'new-e5c17a51-afee-49dc-8af7-a22fab0b18f2';
  $pane->panel = 'content';
  $pane->type = 'views';
  $pane->subtype = 'elife_content_alerts';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'content_alerts',
    'context' => array(
      0 => 'argument_string_2.raw',
      1 => 'argument_string_1.raw',
    ),
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
  $pane->uuid = 'e5c17a51-afee-49dc-8af7-a22fab0b18f2';
  $display->content['new-e5c17a51-afee-49dc-8af7-a22fab0b18f2'] = $pane;
  $display->panels['content'][0] = 'new-e5c17a51-afee-49dc-8af7-a22fab0b18f2';
  $pane = new stdClass();
  $pane->pid = 'new-153e4d3a-cd94-4033-b049-dce3938700dc';
  $pane->panel = 'front';
  $pane->type = 'views';
  $pane->subtype = 'elife_content_alerts';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'content_alerts_front',
    'context' => array(
      0 => 'argument_string_2.raw',
      1 => 'argument_string_1.raw',
    ),
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
  $pane->uuid = '153e4d3a-cd94-4033-b049-dce3938700dc';
  $display->content['new-153e4d3a-cd94-4033-b049-dce3938700dc'] = $pane;
  $display->panels['front'][0] = 'new-153e4d3a-cd94-4033-b049-dce3938700dc';
  $pane = new stdClass();
  $pane->pid = 'new-8be0c05d-5e82-4302-8325-5df378a7e16e';
  $pane->panel = 'header';
  $pane->type = 'block';
  $pane->subtype = 'elife_content_alerts-elife_content_alerts_header';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '8be0c05d-5e82-4302-8325-5df378a7e16e';
  $display->content['new-8be0c05d-5e82-4302-8325-5df378a7e16e'] = $pane;
  $display->panels['header'][0] = 'new-8be0c05d-5e82-4302-8325-5df378a7e16e';
  $pane = new stdClass();
  $pane->pid = 'new-5093e35f-6fb2-4ea9-9f0d-162c200c3541';
  $pane->panel = 'intro';
  $pane->type = 'block';
  $pane->subtype = 'elife_content_alerts-elife_content_alerts_intro';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '5093e35f-6fb2-4ea9-9f0d-162c200c3541';
  $display->content['new-5093e35f-6fb2-4ea9-9f0d-162c200c3541'] = $pane;
  $display->panels['intro'][0] = 'new-5093e35f-6fb2-4ea9-9f0d-162c200c3541';
  $pane = new stdClass();
  $pane->pid = 'new-5092bceb-fdd8-409d-9b08-d747f79aed3e';
  $pane->panel = 'logo';
  $pane->type = 'block';
  $pane->subtype = 'elife_content_alerts-elife_content_alerts_logo';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '5092bceb-fdd8-409d-9b08-d747f79aed3e';
  $display->content['new-5092bceb-fdd8-409d-9b08-d747f79aed3e'] = $pane;
  $display->panels['logo'][0] = 'new-5092bceb-fdd8-409d-9b08-d747f79aed3e';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-153e4d3a-cd94-4033-b049-dce3938700dc';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['elife_content_alerts_ui'] = $page;

  return $pages;

}
