<?php
/**
 * @file
 * elife_podcast.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function elife_podcast_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_ea02a89c-cb53-4fca-b41b-93bfda1af74c';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -21;
  $handler->conf = array(
    'title' => 'eLife Podcast',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'elife-collection',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'elife_podcast' => 'elife_podcast',
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
  $display->layout = 'elife_collection';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'hero_block' => NULL,
      'content' => NULL,
      'sidebar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '6b8ec7b6-62f0-4838-a901-3698d5312398';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-2fc5222d-0057-447c-b15d-4c4d4b9bee28';
  $pane->panel = 'content';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_elife_p_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => 'elife_hero_block_teaser',
      'image_link' => '',
      'class' => '',
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '2fc5222d-0057-447c-b15d-4c4d4b9bee28';
  $display->content['new-2fc5222d-0057-447c-b15d-4c4d4b9bee28'] = $pane;
  $display->panels['content'][0] = 'new-2fc5222d-0057-447c-b15d-4c4d4b9bee28';
  $pane = new stdClass();
  $pane->pid = 'new-453b6619-f6d6-443e-88f6-e495d876f19f';
  $pane->panel = 'content';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_elife_p_text';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '453b6619-f6d6-443e-88f6-e495d876f19f';
  $display->content['new-453b6619-f6d6-443e-88f6-e495d876f19f'] = $pane;
  $display->panels['content'][1] = 'new-453b6619-f6d6-443e-88f6-e495d876f19f';
  $pane = new stdClass();
  $pane->pid = 'new-52e6d586-0f8a-469b-bcb8-4535e5f7560b';
  $pane->panel = 'content';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_elife_p_chapters';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'entityreference_entity_view',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'view_mode' => 'teaser',
      'links' => 0,
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '52e6d586-0f8a-469b-bcb8-4535e5f7560b';
  $display->content['new-52e6d586-0f8a-469b-bcb8-4535e5f7560b'] = $pane;
  $display->panels['content'][2] = 'new-52e6d586-0f8a-469b-bcb8-4535e5f7560b';
  $pane = new stdClass();
  $pane->pid = 'new-b3c9db1b-2144-4f65-b021-e369ee37caab';
  $pane->panel = 'hero_block';
  $pane->type = 'elife_hero_block';
  $pane->subtype = 'elife_hero_block';
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
    'form_build_id' => 'form-EDaVCL42KrqbCtsZCITu4265jzaCtCT98icB0yYA1PE',
    'form_token' => 'KgrendLh1dxBy5W6pvyJHINELXdfWkX-QzZjKWR3cDk',
    'form_id' => 'elife_hero_block_plugin_edit',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b3c9db1b-2144-4f65-b021-e369ee37caab';
  $display->content['new-b3c9db1b-2144-4f65-b021-e369ee37caab'] = $pane;
  $display->panels['hero_block'][0] = 'new-b3c9db1b-2144-4f65-b021-e369ee37caab';
  $pane = new stdClass();
  $pane->pid = 'new-c381dca6-7daf-45c5-8a1c-7a249c2c2e07';
  $pane->panel = 'sidebar';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Listen to other episodes of the eLife Podcast',
    'title' => '',
    'body' => '<a href="/podcast">Listen to other episodes of the eLife Podcast</a>',
    'format' => 'full_html',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'c381dca6-7daf-45c5-8a1c-7a249c2c2e07';
  $display->content['new-c381dca6-7daf-45c5-8a1c-7a249c2c2e07'] = $pane;
  $display->panels['sidebar'][0] = 'new-c381dca6-7daf-45c5-8a1c-7a249c2c2e07';
  $pane = new stdClass();
  $pane->pid = 'new-95c3f777-91d2-4920-9d50-2376c2fc0406';
  $pane->panel = 'sidebar';
  $pane->type = 'elife_podcast_sidebar';
  $pane->subtype = 'elife_podcast_sidebar';
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
    'form_build_id' => 'form-V_lsdVzH1g7BMJMBNBUnz1V7m4U91e4Q3FSxnG9rebo',
    'form_token' => '-ReoIfwJGxUjza3_E8IZFFNBi68PGc9PwA2IuVz-TKI',
    'form_id' => 'elife_podcast_sidebar_plugin_edit',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '95c3f777-91d2-4920-9d50-2376c2fc0406';
  $display->content['new-95c3f777-91d2-4920-9d50-2376c2fc0406'] = $pane;
  $display->panels['sidebar'][1] = 'new-95c3f777-91d2-4920-9d50-2376c2fc0406';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-b3c9db1b-2144-4f65-b021-e369ee37caab';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_ea02a89c-cb53-4fca-b41b-93bfda1af74c'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function elife_podcast_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'elife_podcasts';
  $page->task = 'page';
  $page->admin_title = 'eLife Podcasts';
  $page->admin_description = '';
  $page->path = 'podcast';
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
  $handler->name = 'page_elife_podcasts__panel';
  $handler->task = 'page';
  $handler->subtask = 'elife_podcasts';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'elife-collection',
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
            'paths' => 'podcast',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'elife_collection';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'hero_block' => NULL,
      'content' => NULL,
      'sidebar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'eLife Podcasts';
  $display->uuid = '08809c91-eeb7-4c40-a0ec-91cc63e15202';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-00b5bbbc-196e-42be-ae6c-a320495a0cec';
  $pane->panel = 'content';
  $pane->type = 'views_panes';
  $pane->subtype = 'elife_podcasts-panel_pane_1';
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
  $pane->uuid = '00b5bbbc-196e-42be-ae6c-a320495a0cec';
  $display->content['new-00b5bbbc-196e-42be-ae6c-a320495a0cec'] = $pane;
  $display->panels['content'][0] = 'new-00b5bbbc-196e-42be-ae6c-a320495a0cec';
  $pane = new stdClass();
  $pane->pid = 'new-87b89eb6-6cc4-4228-9c53-14e66e9b606b';
  $pane->panel = 'hero_block';
  $pane->type = 'elife_hero_block';
  $pane->subtype = 'elife_hero_block';
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
    'form_build_id' => 'form-8dhFweGcyxfPlKDwJQgEx5yc7JDfbXXrqwrQbLwS8pY',
    'form_token' => 'KgrendLh1dxBy5W6pvyJHINELXdfWkX-QzZjKWR3cDk',
    'form_id' => 'elife_hero_block_plugin_edit',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '87b89eb6-6cc4-4228-9c53-14e66e9b606b';
  $display->content['new-87b89eb6-6cc4-4228-9c53-14e66e9b606b'] = $pane;
  $display->panels['hero_block'][0] = 'new-87b89eb6-6cc4-4228-9c53-14e66e9b606b';
  $pane = new stdClass();
  $pane->pid = 'new-9844575b-8b31-4904-89ca-8a9fff635a0e';
  $pane->panel = 'sidebar';
  $pane->type = 'elife_podcast_sidebar';
  $pane->subtype = 'elife_podcast_sidebar';
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
    'form_build_id' => 'form-3rgSCSkGMk_uZ3iKcYpTV20cj7rVRXTQtU0JfAaLztE',
    'form_token' => '-ReoIfwJGxUjza3_E8IZFFNBi68PGc9PwA2IuVz-TKI',
    'form_id' => 'elife_podcast_sidebar_plugin_edit',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9844575b-8b31-4904-89ca-8a9fff635a0e';
  $display->content['new-9844575b-8b31-4904-89ca-8a9fff635a0e'] = $pane;
  $display->panels['sidebar'][0] = 'new-9844575b-8b31-4904-89ca-8a9fff635a0e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-87b89eb6-6cc4-4228-9c53-14e66e9b606b';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['elife_podcasts'] = $page;

  return $pages;

}
