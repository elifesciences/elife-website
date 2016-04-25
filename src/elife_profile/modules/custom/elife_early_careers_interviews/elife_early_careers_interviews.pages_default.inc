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
    'title' => 'eLife Interview',
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
    'body' => '<p>This interview is part of <a href="%node:field-elife-i-series:url:relative"> %node:field-elife-i-series:field-elife-title:value</a>.</p>
',
    'format' => 'elife_full_html',
    'substitute' => 1,
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

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view__panel_context_23ee3ae6-f232-434c-af2c-48f18675cddc';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -26;
  $handler->conf = array(
    'title' => 'Interview Series',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'elife-collection',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
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
  $display->title = '%term:name: a collection of interviews';
  $display->uuid = 'a9905046-f098-468e-b1f3-b02084ffc598';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-88cba25b-ba59-4750-a290-8a815670dc02';
  $pane->panel = 'content';
  $pane->type = 'entity_field_extra';
  $pane->subtype = 'taxonomy_term:description';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
    'context' => 'argument_term_1',
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
  $pane->uuid = '88cba25b-ba59-4750-a290-8a815670dc02';
  $display->content['new-88cba25b-ba59-4750-a290-8a815670dc02'] = $pane;
  $display->panels['content'][0] = 'new-88cba25b-ba59-4750-a290-8a815670dc02';
  $pane = new stdClass();
  $pane->pid = 'new-95397a77-146d-44dc-8cf5-d66ff7f20c35';
  $pane->panel = 'content';
  $pane->type = 'views_panes';
  $pane->subtype = 'elife_early_careers_interviews-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'field_elife_i_series_target_id' => '%term:tid',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '95397a77-146d-44dc-8cf5-d66ff7f20c35';
  $display->content['new-95397a77-146d-44dc-8cf5-d66ff7f20c35'] = $pane;
  $display->panels['content'][1] = 'new-95397a77-146d-44dc-8cf5-d66ff7f20c35';
  $pane = new stdClass();
  $pane->pid = 'new-247637e1-3495-457f-ae0f-68505761347a';
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
    'form_build_id' => 'form-QZKeuQ5w1uAjEPug_AAKUdaNyZ5JBcE2aC3gSa-olh4',
    'form_token' => '_T8FusYUG_BGyWwHjzUzaQXs4d7pMueG-4jJlOluWpc',
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
  $pane->uuid = '247637e1-3495-457f-ae0f-68505761347a';
  $display->content['new-247637e1-3495-457f-ae0f-68505761347a'] = $pane;
  $display->panels['hero_block'][0] = 'new-247637e1-3495-457f-ae0f-68505761347a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-247637e1-3495-457f-ae0f-68505761347a';
  $handler->conf['display'] = $display;
  $export['term_view__panel_context_23ee3ae6-f232-434c-af2c-48f18675cddc'] = $handler;

  return $export;
}
