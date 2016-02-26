<?php
/**
 * @file
 * elife_news.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function elife_news_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_081ad7e7-75ce-4b78-a933-5b06651f4c97';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -22;
  $handler->conf = array(
    'title' => 'eLife News article',
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
              'elife_news_article' => 'elife_news_article',
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
  $display->uuid = 'a50c0ca3-7437-4b16-ab55-0902f5bb9c14';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-98c0f7b0-3cd5-4107-a329-9f7253549922';
  $pane->panel = 'main';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Title',
    'title' => '',
    'body' => '<h2>%node:field_elife_title</h2>',
    'format' => 'elife_full_html',
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
  $pane->uuid = '98c0f7b0-3cd5-4107-a329-9f7253549922';
  $display->content['new-98c0f7b0-3cd5-4107-a329-9f7253549922'] = $pane;
  $display->panels['main'][0] = 'new-98c0f7b0-3cd5-4107-a329-9f7253549922';
  $pane = new stdClass();
  $pane->pid = 'new-75da6e11-ebd6-40f8-9ed7-d5058ec692a4';
  $pane->panel = 'main';
  $pane->type = 'node_created';
  $pane->subtype = 'node_created';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'format' => 'long',
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
  $pane->uuid = '75da6e11-ebd6-40f8-9ed7-d5058ec692a4';
  $display->content['new-75da6e11-ebd6-40f8-9ed7-d5058ec692a4'] = $pane;
  $display->panels['main'][1] = 'new-75da6e11-ebd6-40f8-9ed7-d5058ec692a4';
  $pane = new stdClass();
  $pane->pid = 'new-5bdb9e6f-1356-4faf-9317-9161b3802747';
  $pane->panel = 'main';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_elife_n_text';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '5bdb9e6f-1356-4faf-9317-9161b3802747';
  $display->content['new-5bdb9e6f-1356-4faf-9317-9161b3802747'] = $pane;
  $display->panels['main'][2] = 'new-5bdb9e6f-1356-4faf-9317-9161b3802747';
  $pane = new stdClass();
  $pane->pid = 'new-ef0c0eb2-a752-4ba0-87f8-42b35de945b3';
  $pane->panel = 'main';
  $pane->type = 'elife_disqus';
  $pane->subtype = 'elife_disqus';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:node_1',
    ),
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
  $pane->uuid = 'ef0c0eb2-a752-4ba0-87f8-42b35de945b3';
  $display->content['new-ef0c0eb2-a752-4ba0-87f8-42b35de945b3'] = $pane;
  $display->panels['main'][3] = 'new-ef0c0eb2-a752-4ba0-87f8-42b35de945b3';
  $pane = new stdClass();
  $pane->pid = 'new-6f03afda-0c32-4824-9fb4-fb842a5f3a5b';
  $pane->panel = 'side_top';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_elife_n_category';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'taxonomy_term_reference_link',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => 'Categories',
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
  $pane->uuid = '6f03afda-0c32-4824-9fb4-fb842a5f3a5b';
  $display->content['new-6f03afda-0c32-4824-9fb4-fb842a5f3a5b'] = $pane;
  $display->panels['side_top'][0] = 'new-6f03afda-0c32-4824-9fb4-fb842a5f3a5b';
  $pane = new stdClass();
  $pane->pid = 'new-2f0b2700-d293-4e07-b30e-b144649bef02';
  $pane->panel = 'side_top';
  $pane->type = 'elife_content_alerts_sign_up';
  $pane->subtype = 'elife_content_alerts_sign_up';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'buttons' => NULL,
    'aligner_start' => NULL,
    'override_title' => 1,
    'override_title_text' => 'Sign up for <i>eLife</i> alerts',
    'override_title_heading' => 'h2',
    'aligner_stop' => NULL,
    'override_title_markup' => NULL,
    'gid' => '',
    'custom_6' => 'elife-news_rev140402',
    'form_build_id' => 'form-oEIImDmSMUwh-aNxJoGUuiwYYWUNhHCdCyEsSIALemE',
    'form_token' => 'QL-zPqZBKctroxc079UBEkZ1nSJzIalc7UfeyQNSmLo',
    'form_id' => 'elife_content_alerts_sign_up_edit',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '2f0b2700-d293-4e07-b30e-b144649bef02';
  $display->content['new-2f0b2700-d293-4e07-b30e-b144649bef02'] = $pane;
  $display->panels['side_top'][1] = 'new-2f0b2700-d293-4e07-b30e-b144649bef02';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_081ad7e7-75ce-4b78-a933-5b06651f4c97'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view__panel_context_9b5f9964-3a95-4c4f-8d55-531af7430679';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -27;
  $handler->conf = array(
    'title' => 'News Category',
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
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'elife_n_category' => 'elife_n_category',
            ),
          ),
          'context' => 'argument_term_1',
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
  $display->title = 'eLife News: %term:field_elife_title';
  $display->uuid = '5c2a70c7-3974-4c3a-99af-4a5aa055b05a';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-f03b65ea-0d1c-4fe8-9d00-04d80cec2c13';
  $pane->panel = 'main';
  $pane->type = 'page_title';
  $pane->subtype = 'page_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'markup' => 'h1',
    'class' => '',
    'id' => '',
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
  $pane->uuid = 'f03b65ea-0d1c-4fe8-9d00-04d80cec2c13';
  $display->content['new-f03b65ea-0d1c-4fe8-9d00-04d80cec2c13'] = $pane;
  $display->panels['main'][0] = 'new-f03b65ea-0d1c-4fe8-9d00-04d80cec2c13';
  $pane = new stdClass();
  $pane->pid = 'new-162019da-221b-46bd-b032-2be91af4a981';
  $pane->panel = 'main';
  $pane->type = 'views_panes';
  $pane->subtype = 'elife_news-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'field_elife_n_category_tid' => '%term:tid',
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
  $pane->uuid = '162019da-221b-46bd-b032-2be91af4a981';
  $display->content['new-162019da-221b-46bd-b032-2be91af4a981'] = $pane;
  $display->panels['main'][1] = 'new-162019da-221b-46bd-b032-2be91af4a981';
  $pane = new stdClass();
  $pane->pid = 'new-261be101-a539-4fae-bfca-f3fc388e94c7';
  $pane->panel = 'side_top';
  $pane->type = 'views_panes';
  $pane->subtype = 'elife_news_categories-panel_pane_1';
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
  $pane->uuid = '261be101-a539-4fae-bfca-f3fc388e94c7';
  $display->content['new-261be101-a539-4fae-bfca-f3fc388e94c7'] = $pane;
  $display->panels['side_top'][0] = 'new-261be101-a539-4fae-bfca-f3fc388e94c7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-162019da-221b-46bd-b032-2be91af4a981';
  $handler->conf['display'] = $display;
  $export['term_view__panel_context_9b5f9964-3a95-4c4f-8d55-531af7430679'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function elife_news_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'elife_news';
  $page->task = 'page';
  $page->admin_title = 'eLife News';
  $page->admin_description = '';
  $page->path = 'elife-news';
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
  $handler->name = 'page_elife_news__panel';
  $handler->task = 'page';
  $handler->subtask = 'elife_news';
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
            'paths' => 'elife-news',
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
  $display->title = 'eLife News';
  $display->uuid = '3a44ed57-d201-4ee6-91f5-b50e3f60fcb2';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a9874889-48d5-4d51-b896-c3e113b1902c';
  $pane->panel = 'main';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<h1>eLife News</h1>
',
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
  $pane->uuid = 'a9874889-48d5-4d51-b896-c3e113b1902c';
  $display->content['new-a9874889-48d5-4d51-b896-c3e113b1902c'] = $pane;
  $display->panels['main'][0] = 'new-a9874889-48d5-4d51-b896-c3e113b1902c';
  $pane = new stdClass();
  $pane->pid = 'new-7cdea2a5-1403-4252-8df0-ae2352e04540';
  $pane->panel = 'main';
  $pane->type = 'views_panes';
  $pane->subtype = 'elife_news-panel_pane_1';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '7cdea2a5-1403-4252-8df0-ae2352e04540';
  $display->content['new-7cdea2a5-1403-4252-8df0-ae2352e04540'] = $pane;
  $display->panels['main'][1] = 'new-7cdea2a5-1403-4252-8df0-ae2352e04540';
  $pane = new stdClass();
  $pane->pid = 'new-7612c703-489e-474b-9a4f-88f6f5548c70';
  $pane->panel = 'side_top';
  $pane->type = 'views_panes';
  $pane->subtype = 'elife_news_categories-panel_pane_1';
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
  $pane->uuid = '7612c703-489e-474b-9a4f-88f6f5548c70';
  $display->content['new-7612c703-489e-474b-9a4f-88f6f5548c70'] = $pane;
  $display->panels['side_top'][0] = 'new-7612c703-489e-474b-9a4f-88f6f5548c70';
  $pane = new stdClass();
  $pane->pid = 'new-9ca8670c-d8a4-4eac-bc9b-c3f4db247cc2';
  $pane->panel = 'side_top';
  $pane->type = 'elife_content_alerts_sign_up';
  $pane->subtype = 'elife_content_alerts_sign_up';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'buttons' => NULL,
    'aligner_start' => NULL,
    'override_title' => 1,
    'override_title_text' => 'Sign up for <i>eLife</i> alerts',
    'override_title_heading' => 'h2',
    'aligner_stop' => NULL,
    'override_title_markup' => NULL,
    'gid' => '',
    'custom_6' => 'elife-news_rev140402',
    'form_build_id' => 'form-dvyoehVJPeqE1tK0tCTW3WLd9V_jrUIRyuhQ2pEa7P0',
    'form_token' => 'QL-zPqZBKctroxc079UBEkZ1nSJzIalc7UfeyQNSmLo',
    'form_id' => 'elife_content_alerts_sign_up_edit',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '9ca8670c-d8a4-4eac-bc9b-c3f4db247cc2';
  $display->content['new-9ca8670c-d8a4-4eac-bc9b-c3f4db247cc2'] = $pane;
  $display->panels['side_top'][1] = 'new-9ca8670c-d8a4-4eac-bc9b-c3f4db247cc2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-7cdea2a5-1403-4252-8df0-ae2352e04540';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['elife_news'] = $page;

  return $pages;

}
