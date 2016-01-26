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
  $handler->name = 'term_view__elife_category';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Category',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'elife_category',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'elife_categories' => 'elife_categories',
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
  $display->title = '%term:field_elife_category_plural';
  $display->uuid = '371b13fb-282f-49d9-91a5-f5d3fb3542e0';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-91a0e273-01f9-44e4-8449-b83237b6cfde';
  $pane->panel = 'main';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<h1>%term:field_elife_category_plural</h1>',
    'format' => 'elife_full_html',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'elife-search-title',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '91a0e273-01f9-44e4-8449-b83237b6cfde';
  $display->content['new-91a0e273-01f9-44e4-8449-b83237b6cfde'] = $pane;
  $display->panels['main'][0] = 'new-91a0e273-01f9-44e4-8449-b83237b6cfde';
  $pane = new stdClass();
  $pane->pid = 'new-51c87d30-0223-47a9-93dc-727352751f0c';
  $pane->panel = 'main';
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
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'elife-search-description',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '51c87d30-0223-47a9-93dc-727352751f0c';
  $display->content['new-51c87d30-0223-47a9-93dc-727352751f0c'] = $pane;
  $display->panels['main'][1] = 'new-51c87d30-0223-47a9-93dc-727352751f0c';
  $pane = new stdClass();
  $pane->pid = 'new-4113cfc8-b041-4717-bcf7-f819f1ecc0d1';
  $pane->panel = 'main';
  $pane->type = 'views_panes';
  $pane->subtype = 'elife_search-elife_search_taxonomy';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '4113cfc8-b041-4717-bcf7-f819f1ecc0d1';
  $display->content['new-4113cfc8-b041-4717-bcf7-f819f1ecc0d1'] = $pane;
  $display->panels['main'][2] = 'new-4113cfc8-b041-4717-bcf7-f819f1ecc0d1';
  $pane = new stdClass();
  $pane->pid = 'new-56faff60-2c62-4143-a8be-7d93328137c1';
  $pane->panel = 'side_top';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-SIa08AakMDsXncMkuP9LBk76nQqH4aUC';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Filter by topic',
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
  $pane->uuid = '56faff60-2c62-4143-a8be-7d93328137c1';
  $display->content['new-56faff60-2c62-4143-a8be-7d93328137c1'] = $pane;
  $display->panels['side_top'][0] = 'new-56faff60-2c62-4143-a8be-7d93328137c1';
  $pane = new stdClass();
  $pane->pid = 'new-b573d4f3-97cb-4136-ac2c-ff8ce83596c8';
  $pane->panel = 'side_top';
  $pane->type = 'elife_content_alerts_sign_up';
  $pane->subtype = 'elife_content_alerts_sign_up';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'buttons' => NULL,
    'aligner_start' => NULL,
    'override_title' => 1,
    'override_title_text' => 'Sign up for <em>eLife</em> alerts',
    'override_title_heading' => 'h2',
    'aligner_stop' => NULL,
    'override_title_markup' => NULL,
    'gid' => '',
    'custom_6' => '',
    'form_build_id' => 'form-gJhH0zjDOliwAQnjhbDchbL-asFTe5tx8ZvcH0s1Q_A',
    'form_token' => 'LX2PNcfCCP-I87ynTh9XGfrugxeX_UNIHzoEWa6O7vM',
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
  $pane->uuid = 'b573d4f3-97cb-4136-ac2c-ff8ce83596c8';
  $display->content['new-b573d4f3-97cb-4136-ac2c-ff8ce83596c8'] = $pane;
  $display->panels['side_top'][1] = 'new-b573d4f3-97cb-4136-ac2c-ff8ce83596c8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view__elife_category'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view__elife_heading';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Heading',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'elife_heading',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'elife_headings' => 'elife_headings',
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
  $display->title = '%term:title';
  $display->uuid = '01aab8f0-b714-4224-aed8-7d1ea27f1d7c';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-b0978c45-cd7a-44c9-8c91-ad346eb86ff2';
  $pane->panel = 'main';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<h1>%term:field_elife_title</h1>',
    'format' => 'elife_full_html',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'elife-search-title',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b0978c45-cd7a-44c9-8c91-ad346eb86ff2';
  $display->content['new-b0978c45-cd7a-44c9-8c91-ad346eb86ff2'] = $pane;
  $display->panels['main'][0] = 'new-b0978c45-cd7a-44c9-8c91-ad346eb86ff2';
  $pane = new stdClass();
  $pane->pid = 'new-3eb79288-4886-4656-baca-286f56ea3166';
  $pane->panel = 'main';
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
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'elife-search-description',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '3eb79288-4886-4656-baca-286f56ea3166';
  $display->content['new-3eb79288-4886-4656-baca-286f56ea3166'] = $pane;
  $display->panels['main'][1] = 'new-3eb79288-4886-4656-baca-286f56ea3166';
  $pane = new stdClass();
  $pane->pid = 'new-dc205b54-fefd-4b87-8a33-389a3632062f';
  $pane->panel = 'main';
  $pane->type = 'views_panes';
  $pane->subtype = 'elife_search-elife_search_taxonomy';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'dc205b54-fefd-4b87-8a33-389a3632062f';
  $display->content['new-dc205b54-fefd-4b87-8a33-389a3632062f'] = $pane;
  $display->panels['main'][2] = 'new-dc205b54-fefd-4b87-8a33-389a3632062f';
  $pane = new stdClass();
  $pane->pid = 'new-3748b5be-6627-4119-bca9-d09aeddcbc6f';
  $pane->panel = 'side_top';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-GBwQb5guFQK01aO7qduAxT19b4A9j87y';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Filter by content type',
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
  $pane->uuid = '3748b5be-6627-4119-bca9-d09aeddcbc6f';
  $display->content['new-3748b5be-6627-4119-bca9-d09aeddcbc6f'] = $pane;
  $display->panels['side_top'][0] = 'new-3748b5be-6627-4119-bca9-d09aeddcbc6f';
  $pane = new stdClass();
  $pane->pid = 'new-ed0d1a3f-56d8-4fe0-bdef-ba86fcd6477d';
  $pane->panel = 'side_top';
  $pane->type = 'elife_content_alerts_sign_up';
  $pane->subtype = 'elife_content_alerts_sign_up';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'buttons' => NULL,
    'aligner_start' => NULL,
    'override_title' => 1,
    'override_title_text' => 'Sign up for <em>eLife</em> alerts',
    'override_title_heading' => 'h2',
    'aligner_stop' => NULL,
    'override_title_markup' => NULL,
    'gid' => '',
    'custom_6' => '',
    'form_build_id' => 'form-tnGG6TEiB8wq7K79-TlaBUZQP3lcgi4KQSHp4ByUjFE',
    'form_token' => 'QGGnosR9MdSAxNJacENX-UwmP0nchuJBwUQ4zo7JE0E',
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
  $pane->uuid = 'ed0d1a3f-56d8-4fe0-bdef-ba86fcd6477d';
  $display->content['new-ed0d1a3f-56d8-4fe0-bdef-ba86fcd6477d'] = $pane;
  $display->panels['side_top'][1] = 'new-ed0d1a3f-56d8-4fe0-bdef-ba86fcd6477d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view__elife_heading'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view__elife_keyword';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'http_response';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'Keyword',
    'contexts' => array(),
    'relationships' => array(),
    'code' => '301',
    'destination' => 'elife/search?keyword="%term:name"',
    'name' => 'elife_keyword',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'elife_keywords' => 'elife_keywords',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $export['term_view__elife_keyword'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function elife_search_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'elife_search';
  $page->task = 'page';
  $page->admin_title = 'Search';
  $page->admin_description = '';
  $page->path = 'elife/search';
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
  $handler->name = 'page_elife_search__panel_context_763bb895-156d-4054-88e0-980183a2d1e3';
  $handler->task = 'page';
  $handler->subtask = 'elife_search';
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
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'elife/search',
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
  $display->title = 'Search Results';
  $display->uuid = '78351ac1-cae7-4474-a7f8-a0dad94ef954';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-94495932-7efa-4e99-b34a-4bf812979860';
  $pane->panel = 'main';
  $pane->type = 'views_panes';
  $pane->subtype = 'elife_search-elife_search_keyword';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Browse articles',
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
  $pane->uuid = '94495932-7efa-4e99-b34a-4bf812979860';
  $display->content['new-94495932-7efa-4e99-b34a-4bf812979860'] = $pane;
  $display->panels['main'][0] = 'new-94495932-7efa-4e99-b34a-4bf812979860';
  $pane = new stdClass();
  $pane->pid = 'new-cbdab124-7f63-4049-9b83-6f91bd3fb1f0';
  $pane->panel = 'side_top';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-GBwQb5guFQK01aO7qduAxT19b4A9j87y';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Filter by content type',
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
  $pane->uuid = 'cbdab124-7f63-4049-9b83-6f91bd3fb1f0';
  $display->content['new-cbdab124-7f63-4049-9b83-6f91bd3fb1f0'] = $pane;
  $display->panels['side_top'][0] = 'new-cbdab124-7f63-4049-9b83-6f91bd3fb1f0';
  $pane = new stdClass();
  $pane->pid = 'new-72547073-4e1e-497e-a577-d3aefef5d22e';
  $pane->panel = 'side_top';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-SIa08AakMDsXncMkuP9LBk76nQqH4aUC';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Filter by topic',
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
  $pane->uuid = '72547073-4e1e-497e-a577-d3aefef5d22e';
  $display->content['new-72547073-4e1e-497e-a577-d3aefef5d22e'] = $pane;
  $display->panels['side_top'][1] = 'new-72547073-4e1e-497e-a577-d3aefef5d22e';
  $pane = new stdClass();
  $pane->pid = 'new-265eea17-9a1f-4b38-ae00-9bb213a9d744';
  $pane->panel = 'side_top';
  $pane->type = 'elife_content_alerts_sign_up';
  $pane->subtype = 'elife_content_alerts_sign_up';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'buttons' => NULL,
    'aligner_start' => NULL,
    'override_title' => 1,
    'override_title_text' => 'Sign up for <em>eLife</em> alerts',
    'override_title_heading' => 'h2',
    'aligner_stop' => NULL,
    'override_title_markup' => NULL,
    'gid' => '',
    'custom_6' => '',
    'form_build_id' => 'form-d01xS-m0HH76N9DhrHsLsCUOhYTJ-DG_rO-LiWNL5_Q',
    'form_token' => '3_kO1g_TV3oTETxE4feAJuh0sKb9-5oqsexDDy2pJzQ',
    'form_id' => 'elife_content_alerts_sign_up_edit',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '265eea17-9a1f-4b38-ae00-9bb213a9d744';
  $display->content['new-265eea17-9a1f-4b38-ae00-9bb213a9d744'] = $pane;
  $display->panels['side_top'][2] = 'new-265eea17-9a1f-4b38-ae00-9bb213a9d744';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['elife_search'] = $page;

  return $pages;

}
