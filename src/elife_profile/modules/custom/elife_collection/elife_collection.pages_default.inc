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
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'eLife Collection',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'elife-collection',
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
  $display->layout = 'elife_collection';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'content' => NULL,
      'top_main' => NULL,
      'top_side_first' => NULL,
      'top_side_second' => NULL,
      'top_side_third' => NULL,
      'bottom_first' => NULL,
      'bottom_second' => NULL,
      'bottom_third' => NULL,
      'top_main_new' => NULL,
      'top_side_first_new' => NULL,
      'top_side_second_new' => NULL,
      'top_side_third_new' => NULL,
      'middle_new' => NULL,
      'bottom_first_new' => NULL,
      'bottom_second_new' => NULL,
      'bottom_third_new' => NULL,
      'hero_block' => NULL,
      'sidebar' => NULL,
    ),
    'hero_block' => array(
      'style' => 'naked',
    ),
    'content' => array(
      'style' => 'naked',
    ),
    'sidebar' => array(
      'style' => 'naked',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '62901465-8e54-4a60-a7f6-30122f6df2f2';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-f9b5062c-4672-4eb2-9f78-e2812c17facf';
  $pane->panel = 'content';
  $pane->type = 'elife_hero_block_text';
  $pane->subtype = 'elife_hero_block_text';
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
    'form_build_id' => 'form-tl7LX8j8jJGjll9IDg39e6fQgTVXF2iIwL93SuQ6tLc',
    'form_token' => 'RNHZAY1XJpwpANkSlQffqwNymstQVRmjjZE5hllM58k',
    'form_id' => 'elife_hero_block_text_plugin_edit',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f9b5062c-4672-4eb2-9f78-e2812c17facf';
  $display->content['new-f9b5062c-4672-4eb2-9f78-e2812c17facf'] = $pane;
  $display->panels['content'][0] = 'new-f9b5062c-4672-4eb2-9f78-e2812c17facf';
  $pane = new stdClass();
  $pane->pid = 'new-8736f0c8-de43-4ac6-9843-4446c3bee997';
  $pane->panel = 'content';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_elife_c_articles';
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
      'links' => 1,
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
  $pane->uuid = '8736f0c8-de43-4ac6-9843-4446c3bee997';
  $display->content['new-8736f0c8-de43-4ac6-9843-4446c3bee997'] = $pane;
  $display->panels['content'][1] = 'new-8736f0c8-de43-4ac6-9843-4446c3bee997';
  $pane = new stdClass();
  $pane->pid = 'new-f1071628-0206-473e-abaa-f387706c9f2b';
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
    'form_build_id' => 'form-1-KuONI_uImDa91o-dQ5MMn25mpxG5oCxFRsc82Pc-w',
    'form_token' => 'GtzRKLHJQvzSAsUP6Ex86n6HmCvQsbNTGqfqvDDBcPM',
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
  $pane->uuid = 'f1071628-0206-473e-abaa-f387706c9f2b';
  $display->content['new-f1071628-0206-473e-abaa-f387706c9f2b'] = $pane;
  $display->panels['hero_block'][0] = 'new-f1071628-0206-473e-abaa-f387706c9f2b';
  $pane = new stdClass();
  $pane->pid = 'new-168b4cd2-385d-4c3b-8e4a-531f961970de';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_elife_c_podcast';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'entityreference_entity_view',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'view_mode' => 'elife_teaser_compact',
      'links' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => 'Multimedia',
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
  $pane->uuid = '168b4cd2-385d-4c3b-8e4a-531f961970de';
  $display->content['new-168b4cd2-385d-4c3b-8e4a-531f961970de'] = $pane;
  $display->panels['sidebar'][0] = 'new-168b4cd2-385d-4c3b-8e4a-531f961970de';
  $pane = new stdClass();
  $pane->pid = 'new-6b511142-304f-4b43-a774-3498d9bfbaba';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_elife_c_related';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'entityreference_entity_view',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'view_mode' => 'elife_teaser_compact',
      'links' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => 'Related content',
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
  $pane->uuid = '6b511142-304f-4b43-a774-3498d9bfbaba';
  $display->content['new-6b511142-304f-4b43-a774-3498d9bfbaba'] = $pane;
  $display->panels['sidebar'][1] = 'new-6b511142-304f-4b43-a774-3498d9bfbaba';
  $pane = new stdClass();
  $pane->pid = 'new-5b27c539-c9ca-496a-ad58-4701f0ad8b6e';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_elife_c_curators';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'entityreference_entity_view',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'view_mode' => 'elife_teaser_compact',
      'links' => 0,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => 'Curators',
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
  $pane->uuid = '5b27c539-c9ca-496a-ad58-4701f0ad8b6e';
  $display->content['new-5b27c539-c9ca-496a-ad58-4701f0ad8b6e'] = $pane;
  $display->panels['sidebar'][2] = 'new-5b27c539-c9ca-496a-ad58-4701f0ad8b6e';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__elife_collection'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function elife_collection_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'elife_collections';
  $page->task = 'page';
  $page->admin_title = 'eLife Collections';
  $page->admin_description = '';
  $page->path = 'collections';
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
  $handler->name = 'page_elife_collections__panel_context_d642e0ca-188a-4fc4-91a4-e210ac50cf56';
  $handler->task = 'page';
  $handler->subtask = 'elife_collections';
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
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'collections',
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
  $display->title = 'eLife Collections';
  $display->uuid = '5dfe6c13-c83a-4c75-b4d9-a0ae7e580440';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-afc29ab0-1869-4047-ae5f-2740bd78c735';
  $pane->panel = 'content';
  $pane->type = 'elife_hero_block_text';
  $pane->subtype = 'elife_hero_block_text';
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
    'form_build_id' => 'form-zMUABCO2f8GZ83TgcF_QNBVYryW44MlM-vTZYWNiNR8',
    'form_token' => 'neReR5yzOrJ5n-9FRn0xOBTB7d6hUm9q4KtriwGVnwo',
    'form_id' => 'elife_hero_block_text_plugin_edit',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'afc29ab0-1869-4047-ae5f-2740bd78c735';
  $display->content['new-afc29ab0-1869-4047-ae5f-2740bd78c735'] = $pane;
  $display->panels['content'][0] = 'new-afc29ab0-1869-4047-ae5f-2740bd78c735';
  $pane = new stdClass();
  $pane->pid = 'new-2e5e1b24-884d-4aa4-99de-5b1ac06a80b2';
  $pane->panel = 'content';
  $pane->type = 'views_panes';
  $pane->subtype = 'elife_collections-panel_pane_1';
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
  $pane->uuid = '2e5e1b24-884d-4aa4-99de-5b1ac06a80b2';
  $display->content['new-2e5e1b24-884d-4aa4-99de-5b1ac06a80b2'] = $pane;
  $display->panels['content'][1] = 'new-2e5e1b24-884d-4aa4-99de-5b1ac06a80b2';
  $pane = new stdClass();
  $pane->pid = 'new-cce0aa23-abed-4d95-aa42-c0b348ea731f';
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
    'form_build_id' => 'form-5yn4JFbeCKhlVG_ZTDD6jzZS2PnPPaXV73QGnletzB8',
    'form_token' => 'oW139sAoHO_dGOQHeZi7ZRz8Ly2Qmrs3NaXdwFOllqQ',
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
  $pane->uuid = 'cce0aa23-abed-4d95-aa42-c0b348ea731f';
  $display->content['new-cce0aa23-abed-4d95-aa42-c0b348ea731f'] = $pane;
  $display->panels['hero_block'][0] = 'new-cce0aa23-abed-4d95-aa42-c0b348ea731f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-cce0aa23-abed-4d95-aa42-c0b348ea731f';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['elife_collections'] = $page;

  return $pages;

}
