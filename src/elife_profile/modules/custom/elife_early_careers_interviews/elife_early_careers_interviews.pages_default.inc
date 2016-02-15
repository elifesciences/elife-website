<?php
/**
 * @file
 * elife_early_careers_interviews.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function elife_early_careers_interviews_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_754ef2de-59f8-4514-9460-df9195811d14';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -20;
  $handler->conf = array(
    'title' => 'eLife Early Careers Interview',
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
              'elife_early_careers_interview' => 'elife_early_careers_interview',
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
  $display->uuid = 'd87f378d-c220-49b3-b55c-f1c44e30b10d';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-cd25f102-56a1-4e7d-8442-8791b2d31697';
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
  $pane->uuid = 'cd25f102-56a1-4e7d-8442-8791b2d31697';
  $display->content['new-cd25f102-56a1-4e7d-8442-8791b2d31697'] = $pane;
  $display->panels['main'][0] = 'new-cd25f102-56a1-4e7d-8442-8791b2d31697';
  $pane = new stdClass();
  $pane->pid = 'new-beba82c0-efa6-4402-9c02-74869bbdaabd';
  $pane->panel = 'main';
  $pane->type = 'node_created';
  $pane->subtype = 'node_created';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'format' => 'elife_date_only',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'beba82c0-efa6-4402-9c02-74869bbdaabd';
  $display->content['new-beba82c0-efa6-4402-9c02-74869bbdaabd'] = $pane;
  $display->panels['main'][1] = 'new-beba82c0-efa6-4402-9c02-74869bbdaabd';
  $pane = new stdClass();
  $pane->pid = 'new-26a3b037-2706-41e7-a548-9bc57bcaad47';
  $pane->panel = 'main';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<p>This interview is part of a <a href="/early-careers-interviews">series of interviews with early-career researchers</a>.</p>
',
    'format' => 'elife_full_html',
    'substitute' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '26a3b037-2706-41e7-a548-9bc57bcaad47';
  $display->content['new-26a3b037-2706-41e7-a548-9bc57bcaad47'] = $pane;
  $display->panels['main'][2] = 'new-26a3b037-2706-41e7-a548-9bc57bcaad47';
  $pane = new stdClass();
  $pane->pid = 'new-342707ed-6915-42c5-9127-7d2b5fba0218';
  $pane->panel = 'main';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_elife_i_text';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '342707ed-6915-42c5-9127-7d2b5fba0218';
  $display->content['new-342707ed-6915-42c5-9127-7d2b5fba0218'] = $pane;
  $display->panels['main'][3] = 'new-342707ed-6915-42c5-9127-7d2b5fba0218';
  $pane = new stdClass();
  $pane->pid = 'new-aa6bbd5d-5f8c-476a-9db8-7b0fc2751016';
  $pane->panel = 'main';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_elife_i_cv';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'field_collection_view',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'edit' => '',
      'delete' => '',
      'add' => '',
      'description' => 0,
      'view_mode' => 'full',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '%node:field_elife_i_first_name %node:field_elife_i_last_name CV',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'aa6bbd5d-5f8c-476a-9db8-7b0fc2751016';
  $display->content['new-aa6bbd5d-5f8c-476a-9db8-7b0fc2751016'] = $pane;
  $display->panels['main'][4] = 'new-aa6bbd5d-5f8c-476a-9db8-7b0fc2751016';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_754ef2de-59f8-4514-9460-df9195811d14'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function elife_early_careers_interviews_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'elife_early_careers_interviews';
  $page->task = 'page';
  $page->admin_title = 'eLife Early Careers Interviews';
  $page->admin_description = '';
  $page->path = 'early-careers-interviews';
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
  $handler->name = 'page_elife_early_careers_interviews__panel';
  $handler->task = 'page';
  $handler->subtask = 'elife_early_careers_interviews';
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
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'early-careers-interviews',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
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
  $display->title = 'Early-career researchers: a collection of interviews';
  $display->uuid = 'ed912f2b-660f-4453-91d5-3d87978f7b61';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-4c07cc0c-b9b9-4cad-bf3b-9ffa34293924';
  $pane->panel = 'content';
  $pane->type = 'views_panes';
  $pane->subtype = 'elife_early_careers_interviews-panel_pane_1';
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
  $pane->uuid = '4c07cc0c-b9b9-4cad-bf3b-9ffa34293924';
  $display->content['new-4c07cc0c-b9b9-4cad-bf3b-9ffa34293924'] = $pane;
  $display->panels['content'][0] = 'new-4c07cc0c-b9b9-4cad-bf3b-9ffa34293924';
  $pane = new stdClass();
  $pane->pid = 'new-8dd204e0-f99a-4053-8f64-a971899a9749';
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
    'form_build_id' => 'form-KoPPK4mfSBqWFAv_0JajEhQuxXOvcTG731IlhCKahvQ',
    'form_token' => 'MVXfIbnIUoV0ikWki5SjYe4bjqZfHsxG_xUbY_-iZAA',
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
  $pane->uuid = '8dd204e0-f99a-4053-8f64-a971899a9749';
  $display->content['new-8dd204e0-f99a-4053-8f64-a971899a9749'] = $pane;
  $display->panels['hero_block'][0] = 'new-8dd204e0-f99a-4053-8f64-a971899a9749';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['elife_early_careers_interviews'] = $page;

  return $pages;

}
