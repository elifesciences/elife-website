<?php
/**
 * @file
 * elife_article_pages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function elife_article_pages_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__elife_fragment';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -24;
  $handler->conf = array(
    'title' => 'eLife Fragment',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Parent Article',
        'keyword' => 'parent',
        'name' => 'entity_from_field:field_elife_a_parent-node-node',
        'delta' => 0,
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'name' => 'elife_fragment',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'elife_fragment' => 'elife_fragment',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'title' => array(
          'value' => '[node:title] | [node:ancestor-title] | [site:name]',
        ),
        'description' => array(
          'value' => '[node:title] | [node:impact]',
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
  $display->title = '%node:title | %parent:title';
  $display->uuid = '87e8e098-71fe-4331-aa40-25e51d6def4e';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-c98db7fa-33ca-4ea6-844e-d4da2a7ae53d';
  $pane->panel = 'main';
  $pane->type = 'elife_article_title';
  $pane->subtype = 'elife_article_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'relationship_entity_from_field:field_elife_a_parent-node-node_1',
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
  $pane->uuid = 'c98db7fa-33ca-4ea6-844e-d4da2a7ae53d';
  $display->content['new-c98db7fa-33ca-4ea6-844e-d4da2a7ae53d'] = $pane;
  $display->panels['main'][0] = 'new-c98db7fa-33ca-4ea6-844e-d4da2a7ae53d';
  $pane = new stdClass();
  $pane->pid = 'new-c226b6ec-9c88-4a4e-bd65-64351caca849';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'c226b6ec-9c88-4a4e-bd65-64351caca849';
  $display->content['new-c226b6ec-9c88-4a4e-bd65-64351caca849'] = $pane;
  $display->panels['main'][1] = 'new-c226b6ec-9c88-4a4e-bd65-64351caca849';
  $pane = new stdClass();
  $pane->pid = 'new-079a0ecb-878b-45e3-a8a2-909c8f331785';
  $pane->panel = 'main';
  $pane->type = 'elife_article_authors';
  $pane->subtype = 'elife_article_authors';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'relationship_entity_from_field:field_elife_a_parent-node-node_1',
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
  $pane->uuid = '079a0ecb-878b-45e3-a8a2-909c8f331785';
  $display->content['new-079a0ecb-878b-45e3-a8a2-909c8f331785'] = $pane;
  $display->panels['main'][2] = 'new-079a0ecb-878b-45e3-a8a2-909c8f331785';
  $pane = new stdClass();
  $pane->pid = 'new-a4fa3037-6032-4eee-b88d-3eb3781a57e2';
  $pane->panel = 'main';
  $pane->type = 'elife_article_aff_details';
  $pane->subtype = 'elife_article_aff_details';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'relationship_entity_from_field:field_elife_a_parent-node-node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'pane_title' => 'Affiliation details',
      'pane_collapsed' => 1,
    ),
    'style' => 'collapsible',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'visible-small',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'a4fa3037-6032-4eee-b88d-3eb3781a57e2';
  $display->content['new-a4fa3037-6032-4eee-b88d-3eb3781a57e2'] = $pane;
  $display->panels['main'][3] = 'new-a4fa3037-6032-4eee-b88d-3eb3781a57e2';
  $pane = new stdClass();
  $pane->pid = 'new-e8f3fed7-bfc0-4a4b-9df8-d0df72ef4fd5';
  $pane->panel = 'main';
  $pane->type = 'elife_article_affiliation';
  $pane->subtype = 'elife_article_affiliation';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'relationship_entity_from_field:field_elife_a_parent-node-node_1',
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'e8f3fed7-bfc0-4a4b-9df8-d0df72ef4fd5';
  $display->content['new-e8f3fed7-bfc0-4a4b-9df8-d0df72ef4fd5'] = $pane;
  $display->panels['main'][4] = 'new-e8f3fed7-bfc0-4a4b-9df8-d0df72ef4fd5';
  $pane = new stdClass();
  $pane->pid = 'new-fb46f9e5-1dc3-4c3e-a22c-2ce70b0632d8';
  $pane->panel = 'main';
  $pane->type = 'elife_article_doi';
  $pane->subtype = 'elife_article_doi';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'fb46f9e5-1dc3-4c3e-a22c-2ce70b0632d8';
  $display->content['new-fb46f9e5-1dc3-4c3e-a22c-2ce70b0632d8'] = $pane;
  $display->panels['main'][5] = 'new-fb46f9e5-1dc3-4c3e-a22c-2ce70b0632d8';
  $pane = new stdClass();
  $pane->pid = 'new-5e665e67-a315-4299-a106-b16e1123b6c6';
  $pane->panel = 'main';
  $pane->type = 'elife_article_markup_doi';
  $pane->subtype = 'elife_article_markup_doi';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '5e665e67-a315-4299-a106-b16e1123b6c6';
  $display->content['new-5e665e67-a315-4299-a106-b16e1123b6c6'] = $pane;
  $display->panels['main'][6] = 'new-5e665e67-a315-4299-a106-b16e1123b6c6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__elife_fragment'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__elife_fragment_abstract';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -26;
  $handler->conf = array(
    'title' => 'eLife Fragment - Abstract',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Parent Article',
        'keyword' => 'parent',
        'name' => 'entity_from_field:field_elife_a_parent-node-node',
        'delta' => 0,
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'name' => 'elife_fragment_abstract',
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'elife_fragment' => 'elife_fragment',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'entity_field_value:node:elife_fragment:field_elife_a_frag_type',
          'settings' => array(
            'field_elife_a_frag_type' => array(
              'und' => array(
                0 => array(
                  'value' => 'abstract',
                  'format' => '',
                ),
              ),
            ),
            'field_elife_a_frag_type_value' => array(
              0 => 'abstract',
            ),
            'field_elife_a_frag_type_format' => array(
              0 => '',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        3 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => '*/abstract-1',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
    ),
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'title' => array(
          'value' => '[node:title] | [node:ancestor-title] | [site:name]',
        ),
        'description' => array(
          'value' => '[node:title] | [node:impact]',
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
  $display->title = '%node:title | %parent:title';
  $display->uuid = '5b3180e6-5d48-4dba-9992-99a5a2b61a5b';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-f8644341-05a9-4809-9456-dce194d21250';
  $pane->panel = 'main';
  $pane->type = 'elife_article_title';
  $pane->subtype = 'elife_article_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'relationship_entity_from_field:field_elife_a_parent-node-node_1',
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
  $pane->uuid = 'f8644341-05a9-4809-9456-dce194d21250';
  $display->content['new-f8644341-05a9-4809-9456-dce194d21250'] = $pane;
  $display->panels['main'][0] = 'new-f8644341-05a9-4809-9456-dce194d21250';
  $pane = new stdClass();
  $pane->pid = 'new-74ae3a34-62cb-4793-839b-6eae754ecac2';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '74ae3a34-62cb-4793-839b-6eae754ecac2';
  $display->content['new-74ae3a34-62cb-4793-839b-6eae754ecac2'] = $pane;
  $display->panels['main'][1] = 'new-74ae3a34-62cb-4793-839b-6eae754ecac2';
  $pane = new stdClass();
  $pane->pid = 'new-49085329-7a80-49e3-b500-3bef121fe068';
  $pane->panel = 'main';
  $pane->type = 'elife_article_authors';
  $pane->subtype = 'elife_article_authors';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'relationship_entity_from_field:field_elife_a_parent-node-node_1',
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
  $pane->uuid = '49085329-7a80-49e3-b500-3bef121fe068';
  $display->content['new-49085329-7a80-49e3-b500-3bef121fe068'] = $pane;
  $display->panels['main'][2] = 'new-49085329-7a80-49e3-b500-3bef121fe068';
  $pane = new stdClass();
  $pane->pid = 'new-76ef1e85-5ca6-46e8-af89-122b277cb1c0';
  $pane->panel = 'main';
  $pane->type = 'elife_article_aff_details';
  $pane->subtype = 'elife_article_aff_details';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'relationship_entity_from_field:field_elife_a_parent-node-node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'pane_title' => 'Affiliation details',
      'pane_collapsed' => 1,
    ),
    'style' => 'collapsible',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'visible-small',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '76ef1e85-5ca6-46e8-af89-122b277cb1c0';
  $display->content['new-76ef1e85-5ca6-46e8-af89-122b277cb1c0'] = $pane;
  $display->panels['main'][3] = 'new-76ef1e85-5ca6-46e8-af89-122b277cb1c0';
  $pane = new stdClass();
  $pane->pid = 'new-08157a68-3288-4857-91ba-a43b1655e174';
  $pane->panel = 'main';
  $pane->type = 'elife_article_affiliation';
  $pane->subtype = 'elife_article_affiliation';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'relationship_entity_from_field:field_elife_a_parent-node-node_1',
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '08157a68-3288-4857-91ba-a43b1655e174';
  $display->content['new-08157a68-3288-4857-91ba-a43b1655e174'] = $pane;
  $display->panels['main'][4] = 'new-08157a68-3288-4857-91ba-a43b1655e174';
  $pane = new stdClass();
  $pane->pid = 'new-407e8ab5-92e3-4e6d-9147-ddd506c06da7';
  $pane->panel = 'main';
  $pane->type = 'elife_article_doi';
  $pane->subtype = 'elife_article_doi';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '407e8ab5-92e3-4e6d-9147-ddd506c06da7';
  $display->content['new-407e8ab5-92e3-4e6d-9147-ddd506c06da7'] = $pane;
  $display->panels['main'][5] = 'new-407e8ab5-92e3-4e6d-9147-ddd506c06da7';
  $pane = new stdClass();
  $pane->pid = 'new-c25c5118-e3c9-44c4-b3c1-43f789dbf0a9';
  $pane->panel = 'main';
  $pane->type = 'elife_article_markup_doi';
  $pane->subtype = 'elife_article_markup_doi';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'c25c5118-e3c9-44c4-b3c1-43f789dbf0a9';
  $display->content['new-c25c5118-e3c9-44c4-b3c1-43f789dbf0a9'] = $pane;
  $display->panels['main'][6] = 'new-c25c5118-e3c9-44c4-b3c1-43f789dbf0a9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__elife_fragment_abstract'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__elife_fragment_digest';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -25;
  $handler->conf = array(
    'title' => 'eLife Fragment - Digest',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Parent Article',
        'keyword' => 'parent',
        'name' => 'entity_from_field:field_elife_a_parent-node-node',
        'delta' => 0,
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'name' => 'elife_fragment_digest',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'elife_fragment' => 'elife_fragment',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'entity_field_value:node:elife_fragment:field_elife_a_frag_type',
          'settings' => array(
            'field_elife_a_frag_type' => array(
              'und' => array(
                0 => array(
                  'value' => 'abstract',
                  'format' => '',
                ),
              ),
            ),
            'field_elife_a_frag_type_value' => array(
              0 => 'abstract',
            ),
            'field_elife_a_frag_type_format' => array(
              0 => '',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        3 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => '*/abstract-2',
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
        'title' => array(
          'value' => '[node:title] | [node:ancestor-title] | [site:name]',
        ),
        'description' => array(
          'value' => '[node:title] | [node:impact]',
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
  $display->title = '%node:title | %parent:title';
  $display->uuid = '20de8f83-b843-43e8-bac6-f31abbbe687c';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-5be92b96-2e70-4bea-a322-944e81ef908f';
  $pane->panel = 'main';
  $pane->type = 'elife_article_title';
  $pane->subtype = 'elife_article_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'relationship_entity_from_field:field_elife_a_parent-node-node_1',
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
  $pane->uuid = '5be92b96-2e70-4bea-a322-944e81ef908f';
  $display->content['new-5be92b96-2e70-4bea-a322-944e81ef908f'] = $pane;
  $display->panels['main'][0] = 'new-5be92b96-2e70-4bea-a322-944e81ef908f';
  $pane = new stdClass();
  $pane->pid = 'new-9f49ea9a-0b5e-40fc-8bf6-60dcccd07802';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '9f49ea9a-0b5e-40fc-8bf6-60dcccd07802';
  $display->content['new-9f49ea9a-0b5e-40fc-8bf6-60dcccd07802'] = $pane;
  $display->panels['main'][1] = 'new-9f49ea9a-0b5e-40fc-8bf6-60dcccd07802';
  $pane = new stdClass();
  $pane->pid = 'new-7b8efce0-acbd-40be-9235-60ef4c76c42b';
  $pane->panel = 'main';
  $pane->type = 'elife_article_authors';
  $pane->subtype = 'elife_article_authors';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'relationship_entity_from_field:field_elife_a_parent-node-node_1',
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
  $pane->uuid = '7b8efce0-acbd-40be-9235-60ef4c76c42b';
  $display->content['new-7b8efce0-acbd-40be-9235-60ef4c76c42b'] = $pane;
  $display->panels['main'][2] = 'new-7b8efce0-acbd-40be-9235-60ef4c76c42b';
  $pane = new stdClass();
  $pane->pid = 'new-8e383938-1f61-40be-87ca-c2196332ee13';
  $pane->panel = 'main';
  $pane->type = 'elife_article_aff_details';
  $pane->subtype = 'elife_article_aff_details';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'relationship_entity_from_field:field_elife_a_parent-node-node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'pane_title' => 'Affiliation details',
      'pane_collapsed' => 1,
    ),
    'style' => 'collapsible',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'visible-small',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '8e383938-1f61-40be-87ca-c2196332ee13';
  $display->content['new-8e383938-1f61-40be-87ca-c2196332ee13'] = $pane;
  $display->panels['main'][3] = 'new-8e383938-1f61-40be-87ca-c2196332ee13';
  $pane = new stdClass();
  $pane->pid = 'new-341e49ae-4f11-41ae-80a5-c07e3b6f1440';
  $pane->panel = 'main';
  $pane->type = 'elife_article_affiliation';
  $pane->subtype = 'elife_article_affiliation';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'relationship_entity_from_field:field_elife_a_parent-node-node_1',
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '341e49ae-4f11-41ae-80a5-c07e3b6f1440';
  $display->content['new-341e49ae-4f11-41ae-80a5-c07e3b6f1440'] = $pane;
  $display->panels['main'][4] = 'new-341e49ae-4f11-41ae-80a5-c07e3b6f1440';
  $pane = new stdClass();
  $pane->pid = 'new-637c6a4e-8242-44ed-a91a-1f73a70e970e';
  $pane->panel = 'main';
  $pane->type = 'elife_article_doi';
  $pane->subtype = 'elife_article_doi';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '637c6a4e-8242-44ed-a91a-1f73a70e970e';
  $display->content['new-637c6a4e-8242-44ed-a91a-1f73a70e970e'] = $pane;
  $display->panels['main'][5] = 'new-637c6a4e-8242-44ed-a91a-1f73a70e970e';
  $pane = new stdClass();
  $pane->pid = 'new-d4466721-e428-4b1d-90e4-93a14c5169b3';
  $pane->panel = 'main';
  $pane->type = 'elife_article_markup_doi';
  $pane->subtype = 'elife_article_markup_doi';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'd4466721-e428-4b1d-90e4-93a14c5169b3';
  $display->content['new-d4466721-e428-4b1d-90e4-93a14c5169b3'] = $pane;
  $display->panels['main'][6] = 'new-d4466721-e428-4b1d-90e4-93a14c5169b3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__elife_fragment_digest'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__elife_fragment_sub_article_';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -23;
  $handler->conf = array(
    'title' => 'eLife Fragment (Sub Article)',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Parent Article',
        'keyword' => 'parent',
        'name' => 'entity_from_field:field_elife_a_parent-node-node',
        'delta' => 0,
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'Parent Sub Article',
        'keyword' => 'parent_sub',
        'name' => 'entity_from_field:field_elife_a_parent_sub-node-node',
        'delta' => 0,
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'name' => 'elife_fragment_sub_article_',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'elife_fragment' => 'elife_fragment',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'entity_field_value:node:elife_fragment:field_elife_a_parent_sub',
          'settings' => array(
            'field_elife_a_parent_sub' => array(
              'und' => array(),
            ),
            'field_elife_a_parent_sub_target_id' => array(),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'title' => array(
          'value' => '[node:title] | [node:ancestor-title] | [site:name]',
        ),
        'description' => array(
          'value' => '[node:title] | [node:impact]',
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
  $display->title = '%node:title | %parent_sub:title | %parent:title';
  $display->uuid = '67972629-3f09-426e-b176-cfbbb30be54e';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-b12bc591-4707-4927-96b9-d67edb9350e3';
  $pane->panel = 'main';
  $pane->type = 'node_title';
  $pane->subtype = 'node_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'link' => 0,
    'markup' => 'h1',
    'id' => '',
    'class' => 'page-title',
    'context' => 'relationship_entity_from_field:field_elife_a_parent_sub-node-node_1',
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
  $pane->uuid = 'b12bc591-4707-4927-96b9-d67edb9350e3';
  $display->content['new-b12bc591-4707-4927-96b9-d67edb9350e3'] = $pane;
  $display->panels['main'][0] = 'new-b12bc591-4707-4927-96b9-d67edb9350e3';
  $pane = new stdClass();
  $pane->pid = 'new-5b00b4bc-69b2-49bc-ab98-5196de38060c';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '5b00b4bc-69b2-49bc-ab98-5196de38060c';
  $display->content['new-5b00b4bc-69b2-49bc-ab98-5196de38060c'] = $pane;
  $display->panels['main'][1] = 'new-5b00b4bc-69b2-49bc-ab98-5196de38060c';
  $pane = new stdClass();
  $pane->pid = 'new-2a14d1f2-6a56-47b9-9604-49242c132bab';
  $pane->panel = 'main';
  $pane->type = 'elife_article_authors';
  $pane->subtype = 'elife_article_authors';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'relationship_entity_from_field:field_elife_a_parent-node-node_1',
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
  $pane->uuid = '2a14d1f2-6a56-47b9-9604-49242c132bab';
  $display->content['new-2a14d1f2-6a56-47b9-9604-49242c132bab'] = $pane;
  $display->panels['main'][2] = 'new-2a14d1f2-6a56-47b9-9604-49242c132bab';
  $pane = new stdClass();
  $pane->pid = 'new-197e69f3-7f7d-43f7-89f0-1686184050cc';
  $pane->panel = 'main';
  $pane->type = 'elife_article_aff_details';
  $pane->subtype = 'elife_article_aff_details';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'relationship_entity_from_field:field_elife_a_parent-node-node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'pane_title' => 'Affiliation details',
      'pane_collapsed' => 1,
    ),
    'style' => 'collapsible',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'visible-small',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '197e69f3-7f7d-43f7-89f0-1686184050cc';
  $display->content['new-197e69f3-7f7d-43f7-89f0-1686184050cc'] = $pane;
  $display->panels['main'][3] = 'new-197e69f3-7f7d-43f7-89f0-1686184050cc';
  $pane = new stdClass();
  $pane->pid = 'new-8afee69e-23bf-46d0-bbde-d30fde7fc20b';
  $pane->panel = 'main';
  $pane->type = 'elife_article_affiliation';
  $pane->subtype = 'elife_article_affiliation';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'relationship_entity_from_field:field_elife_a_parent-node-node_1',
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '8afee69e-23bf-46d0-bbde-d30fde7fc20b';
  $display->content['new-8afee69e-23bf-46d0-bbde-d30fde7fc20b'] = $pane;
  $display->panels['main'][4] = 'new-8afee69e-23bf-46d0-bbde-d30fde7fc20b';
  $pane = new stdClass();
  $pane->pid = 'new-195f33d7-ad56-4785-ba74-c07ab90e852c';
  $pane->panel = 'main';
  $pane->type = 'elife_article_doi';
  $pane->subtype = 'elife_article_doi';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '195f33d7-ad56-4785-ba74-c07ab90e852c';
  $display->content['new-195f33d7-ad56-4785-ba74-c07ab90e852c'] = $pane;
  $display->panels['main'][5] = 'new-195f33d7-ad56-4785-ba74-c07ab90e852c';
  $pane = new stdClass();
  $pane->pid = 'new-45c46cfd-e14d-40e0-aea3-198346a55c41';
  $pane->panel = 'main';
  $pane->type = 'elife_article_markup_doi';
  $pane->subtype = 'elife_article_markup_doi';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '45c46cfd-e14d-40e0-aea3-198346a55c41';
  $display->content['new-45c46cfd-e14d-40e0-aea3-198346a55c41'] = $pane;
  $display->panels['main'][6] = 'new-45c46cfd-e14d-40e0-aea3-198346a55c41';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__elife_fragment_sub_article_'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__elife_non_research_article';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'eLife Non-Research Article',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'elife_non_research_article',
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'elife_article_ver' => 'elife_article_ver',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'entity_field_value:node:elife_article_ver:field_elife_a_article_type',
          'settings' => array(
            'field_elife_a_article_type' => array(
              'und' => array(
                0 => array(
                  'value' => 'research-article',
                  'format' => '',
                ),
              ),
            ),
            'field_elife_a_article_type_value' => array(
              0 => 'research-article',
            ),
            'field_elife_a_article_type_format' => array(
              0 => '',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => TRUE,
        ),
        2 => array(
          'name' => 'entity_field_value:node:elife_article_ver:field_elife_a_subarticle',
          'settings' => array(
            'field_elife_a_subarticle' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_elife_a_subarticle_value' => array(
              0 => 1,
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => TRUE,
        ),
      ),
    ),
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'title' => array(
          'value' => '[node:title] | [site:name]',
        ),
        'description' => array(
          'value' => '[node:title] | [node:impact]',
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
  $display->title = '%node:title';
  $display->uuid = '4d3c0807-1b50-42ca-a5fd-4080369bed9d';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-c5b50b28-b765-4583-96b4-0461453557d4';
  $pane->panel = 'main';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_elife_a_category';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'entityreference_label',
    'delta_limit' => '1',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
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
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'visible-small category-color-code',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'c5b50b28-b765-4583-96b4-0461453557d4';
  $display->content['new-c5b50b28-b765-4583-96b4-0461453557d4'] = $pane;
  $display->panels['main'][0] = 'new-c5b50b28-b765-4583-96b4-0461453557d4';
  $pane = new stdClass();
  $pane->pid = 'new-7bafe3dd-937d-4542-be79-98794bc844f8';
  $pane->panel = 'main';
  $pane->type = 'elife_article_title';
  $pane->subtype = 'elife_article_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->uuid = '7bafe3dd-937d-4542-be79-98794bc844f8';
  $display->content['new-7bafe3dd-937d-4542-be79-98794bc844f8'] = $pane;
  $display->panels['main'][1] = 'new-7bafe3dd-937d-4542-be79-98794bc844f8';
  $pane = new stdClass();
  $pane->pid = 'new-8ba1fc2a-74db-4d2b-94f4-d8d6a3e25a8c';
  $pane->panel = 'main';
  $pane->type = 'elife_article_authors';
  $pane->subtype = 'elife_article_authors';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '8ba1fc2a-74db-4d2b-94f4-d8d6a3e25a8c';
  $display->content['new-8ba1fc2a-74db-4d2b-94f4-d8d6a3e25a8c'] = $pane;
  $display->panels['main'][2] = 'new-8ba1fc2a-74db-4d2b-94f4-d8d6a3e25a8c';
  $pane = new stdClass();
  $pane->pid = 'new-88d22cc2-119f-40e0-9b07-917228739a38';
  $pane->panel = 'main';
  $pane->type = 'elife_article_aff_details';
  $pane->subtype = 'elife_article_aff_details';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'pane_title' => 'Affiliation details',
      'pane_collapsed' => 1,
    ),
    'style' => 'collapsible',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'visible-small',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '88d22cc2-119f-40e0-9b07-917228739a38';
  $display->content['new-88d22cc2-119f-40e0-9b07-917228739a38'] = $pane;
  $display->panels['main'][3] = 'new-88d22cc2-119f-40e0-9b07-917228739a38';
  $pane = new stdClass();
  $pane->pid = 'new-b846e44d-db42-4d7b-9aa8-f7a17d1361fd';
  $pane->panel = 'main';
  $pane->type = 'elife_article_affiliation';
  $pane->subtype = 'elife_article_affiliation';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'b846e44d-db42-4d7b-9aa8-f7a17d1361fd';
  $display->content['new-b846e44d-db42-4d7b-9aa8-f7a17d1361fd'] = $pane;
  $display->panels['main'][4] = 'new-b846e44d-db42-4d7b-9aa8-f7a17d1361fd';
  $pane = new stdClass();
  $pane->pid = 'new-e2418b5f-34be-4775-bb53-b6cefae0a375';
  $pane->panel = 'main';
  $pane->type = 'elife_article_doi';
  $pane->subtype = 'elife_article_doi';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'e2418b5f-34be-4775-bb53-b6cefae0a375';
  $display->content['new-e2418b5f-34be-4775-bb53-b6cefae0a375'] = $pane;
  $display->panels['main'][5] = 'new-e2418b5f-34be-4775-bb53-b6cefae0a375';
  $pane = new stdClass();
  $pane->pid = 'new-df42c775-8128-4ada-8c58-5e18a6bfa72d';
  $pane->panel = 'main';
  $pane->type = 'panels_ajax_tab_tabs';
  $pane->subtype = 'panels_ajax_tab_tabs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'mini_panels' => array(
      'elife_article' => array(
        'selected' => 1,
        'tab_title' => '',
        'url_id' => '',
        'weight' => '-10',
      ),
      'elife_article_metrics' => array(
        'selected' => 1,
        'tab_title' => '',
        'url_id' => 'article-metrics',
        'weight' => '-9',
      ),
      'elife_article_author' => array(
        'selected' => 0,
        'tab_title' => '',
        'url_id' => '',
        'weight' => '-8',
      ),
      'elife_article_figdata' => array(
        'selected' => 0,
        'tab_title' => '',
        'url_id' => '',
        'weight' => '-7',
      ),
    ),
    'container_id' => 'elife-article-tabs',
    'url_enabled' => 1,
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
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'visible-small',
  );
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'df42c775-8128-4ada-8c58-5e18a6bfa72d';
  $display->content['new-df42c775-8128-4ada-8c58-5e18a6bfa72d'] = $pane;
  $display->panels['main'][6] = 'new-df42c775-8128-4ada-8c58-5e18a6bfa72d';
  $pane = new stdClass();
  $pane->pid = 'new-10c8f5e6-4659-46f7-b84b-86adec03ec85';
  $pane->panel = 'main';
  $pane->type = 'panels_ajax_tab_container';
  $pane->subtype = 'panels_ajax_tab_container';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'container_id' => 'elife-article-tabs',
    'context' => array(
      0 => 'argument_entity_id:node_1',
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
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '10c8f5e6-4659-46f7-b84b-86adec03ec85';
  $display->content['new-10c8f5e6-4659-46f7-b84b-86adec03ec85'] = $pane;
  $display->panels['main'][7] = 'new-10c8f5e6-4659-46f7-b84b-86adec03ec85';
  $pane = new stdClass();
  $pane->pid = 'new-860c6450-ad7b-476e-ba3a-19ba6556582a';
  $pane->panel = 'side_bottom';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Jump-links floater container',
    'title' => '',
    'body' => 'placeholder-text',
    'format' => 'plain_text',
    'substitute' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => 'jump-links-anchor-container',
    'css_class' => 'hidden-small',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '860c6450-ad7b-476e-ba3a-19ba6556582a';
  $display->content['new-860c6450-ad7b-476e-ba3a-19ba6556582a'] = $pane;
  $display->panels['side_bottom'][0] = 'new-860c6450-ad7b-476e-ba3a-19ba6556582a';
  $pane = new stdClass();
  $pane->pid = 'new-75f75966-fa5e-4410-b4c1-1f9dd987d2a1';
  $pane->panel = 'side_lens';
  $pane->type = 'elife_lens_icon';
  $pane->subtype = 'elife_lens_icon';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'override_title_heading' => 'h2',
    'lens_url' => 'http://lens.elifesciences.org',
    'form_build_id' => 'form-nAi86nPbhW7FBIYOemKt5GHs4shk8waOeVi8omKNUis',
    'form_token' => 'wPceBBtmR3MeGmOZqtiry7rMOP4tc_ZgN4Wn70X-uvQ',
    'form_id' => 'elife_lens_icon_edit_form',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '75f75966-fa5e-4410-b4c1-1f9dd987d2a1';
  $display->content['new-75f75966-fa5e-4410-b4c1-1f9dd987d2a1'] = $pane;
  $display->panels['side_lens'][0] = 'new-75f75966-fa5e-4410-b4c1-1f9dd987d2a1';
  $pane = new stdClass();
  $pane->pid = 'new-d620c6d7-36bb-4ce9-aa9a-18cbd8f5708f';
  $pane->panel = 'side_link';
  $pane->type = 'elife_article_repro_belongs_to';
  $pane->subtype = 'elife_article_repro_belongs_to';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->uuid = 'd620c6d7-36bb-4ce9-aa9a-18cbd8f5708f';
  $display->content['new-d620c6d7-36bb-4ce9-aa9a-18cbd8f5708f'] = $pane;
  $display->panels['side_link'][0] = 'new-d620c6d7-36bb-4ce9-aa9a-18cbd8f5708f';
  $pane = new stdClass();
  $pane->pid = 'new-8bbd0ae9-474a-4ebe-9fe3-40e5cec3339f';
  $pane->panel = 'side_top';
  $pane->type = 'elife_article_toolbox';
  $pane->subtype = 'elife_article_toolbox';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->uuid = '8bbd0ae9-474a-4ebe-9fe3-40e5cec3339f';
  $display->content['new-8bbd0ae9-474a-4ebe-9fe3-40e5cec3339f'] = $pane;
  $display->panels['side_top'][0] = 'new-8bbd0ae9-474a-4ebe-9fe3-40e5cec3339f';
  $pane = new stdClass();
  $pane->pid = 'new-ed33ba58-643d-41af-837b-981bc20c804e';
  $pane->panel = 'side_top';
  $pane->type = 'elife_article_related';
  $pane->subtype = 'elife_article_related';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => 'Related content',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => 'related-content',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'ed33ba58-643d-41af-837b-981bc20c804e';
  $display->content['new-ed33ba58-643d-41af-837b-981bc20c804e'] = $pane;
  $display->panels['side_top'][1] = 'new-ed33ba58-643d-41af-837b-981bc20c804e';
  $pane = new stdClass();
  $pane->pid = 'new-74fd5ad8-bed3-4f4b-a975-6e7705a4cb4a';
  $pane->panel = 'side_top';
  $pane->type = 'views_panes';
  $pane->subtype = 'elife_subject_podcasts-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'field_elife_pc_subject_target_id' => '%elife_article_reference:nid',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '74fd5ad8-bed3-4f4b-a975-6e7705a4cb4a';
  $display->content['new-74fd5ad8-bed3-4f4b-a975-6e7705a4cb4a'] = $pane;
  $display->panels['side_top'][2] = 'new-74fd5ad8-bed3-4f4b-a975-6e7705a4cb4a';
  $pane = new stdClass();
  $pane->pid = 'new-69de4c64-59af-4e4c-82e7-b7730ad02c18';
  $pane->panel = 'side_top';
  $pane->type = 'elife_article_jumpto';
  $pane->subtype = 'elife_article_jumpto';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => 'Jump to:',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'hidden-small',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '69de4c64-59af-4e4c-82e7-b7730ad02c18';
  $display->content['new-69de4c64-59af-4e4c-82e7-b7730ad02c18'] = $pane;
  $display->panels['side_top'][3] = 'new-69de4c64-59af-4e4c-82e7-b7730ad02c18';
  $pane = new stdClass();
  $pane->pid = 'new-635d7835-caaa-4cbe-b9b0-e88719456987';
  $pane->panel = 'side_top';
  $pane->type = 'elife_article_categories';
  $pane->subtype = 'elife_article_categories';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => 'Categories & tags',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'hidden-small',
  );
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '635d7835-caaa-4cbe-b9b0-e88719456987';
  $display->content['new-635d7835-caaa-4cbe-b9b0-e88719456987'] = $pane;
  $display->panels['side_top'][4] = 'new-635d7835-caaa-4cbe-b9b0-e88719456987';
  $pane = new stdClass();
  $pane->pid = 'new-b38d43dc-36d8-4afb-a1cc-335f8d79d401';
  $pane->panel = 'side_top';
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
    'form_build_id' => 'form-KhD4_kuW5xtec5GC9rsmLPWuIZIJU5yQ_fQuSpUevuM',
    'form_token' => '6Jt7dNdc-ZWGaHatCl43gr6Iuglxc-Paf2GA2xLai9A',
    'form_id' => 'elife_content_alerts_sign_up_edit',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'b38d43dc-36d8-4afb-a1cc-335f8d79d401';
  $display->content['new-b38d43dc-36d8-4afb-a1cc-335f8d79d401'] = $pane;
  $display->panels['side_top'][5] = 'new-b38d43dc-36d8-4afb-a1cc-335f8d79d401';
  $pane = new stdClass();
  $pane->pid = 'new-9e65e0e4-4734-4e80-b701-8822cb20c66a';
  $pane->panel = 'top';
  $pane->type = 'panels_ajax_tab_tabs';
  $pane->subtype = 'panels_ajax_tab_tabs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'mini_panels' => array(
      'elife_article' => array(
        'selected' => 1,
        'tab_title' => '',
        'url_id' => '',
        'weight' => '-10',
      ),
      'elife_article_metrics' => array(
        'selected' => 1,
        'tab_title' => '',
        'url_id' => 'article-metrics',
        'weight' => '-9',
      ),
      'elife_article_author' => array(
        'selected' => 0,
        'tab_title' => '',
        'url_id' => '',
        'weight' => '-8',
      ),
      'elife_article_figdata' => array(
        'selected' => 0,
        'tab_title' => '',
        'url_id' => '',
        'weight' => '-7',
      ),
    ),
    'container_id' => 'elife-article-tabs',
    'url_enabled' => 1,
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
  $pane->css = array(
    'css_id' => 'article',
    'css_class' => 'hidden-small',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9e65e0e4-4734-4e80-b701-8822cb20c66a';
  $display->content['new-9e65e0e4-4734-4e80-b701-8822cb20c66a'] = $pane;
  $display->panels['top'][0] = 'new-9e65e0e4-4734-4e80-b701-8822cb20c66a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__elife_non_research_article'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__elife_research_article';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'eLife Research Article',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Article reference',
        'keyword' => 'elife_article_reference',
        'name' => 'article_reference',
        'type' => 'top',
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'name' => 'elife_research_article',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'elife_article_ver' => 'elife_article_ver',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'entity_field_value:node:elife_article_ver:field_elife_a_article_type',
          'settings' => array(
            'field_elife_a_article_type' => array(
              'und' => array(
                0 => array(
                  'value' => 'research-article',
                  'format' => '',
                ),
              ),
            ),
            'field_elife_a_article_type_value' => array(
              0 => 'research-article',
            ),
            'field_elife_a_article_type_format' => array(
              0 => '',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'entity_field_value:node:elife_article_ver:field_elife_a_subarticle',
          'settings' => array(
            'field_elife_a_subarticle' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_elife_a_subarticle_value' => array(
              0 => 1,
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'title' => array(
          'value' => '[node:title] | [site:name]',
        ),
        'description' => array(
          'value' => '[node:title] | [node:impact]',
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
  $display->title = '%node:title';
  $display->uuid = 'c1c86267-3c85-42ec-88cf-050803b3fad3';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-e77764eb-2a80-4a8a-b9c1-22ee9783c3c0';
  $pane->panel = 'main';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_elife_a_category';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'entityreference_label',
    'delta_limit' => '1',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
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
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'visible-small category-color-code',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'e77764eb-2a80-4a8a-b9c1-22ee9783c3c0';
  $display->content['new-e77764eb-2a80-4a8a-b9c1-22ee9783c3c0'] = $pane;
  $display->panels['main'][0] = 'new-e77764eb-2a80-4a8a-b9c1-22ee9783c3c0';
  $pane = new stdClass();
  $pane->pid = 'new-91f6e30f-710f-44d0-a860-399dd44c5fc1';
  $pane->panel = 'main';
  $pane->type = 'elife_article_title';
  $pane->subtype = 'elife_article_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->uuid = '91f6e30f-710f-44d0-a860-399dd44c5fc1';
  $display->content['new-91f6e30f-710f-44d0-a860-399dd44c5fc1'] = $pane;
  $display->panels['main'][1] = 'new-91f6e30f-710f-44d0-a860-399dd44c5fc1';
  $pane = new stdClass();
  $pane->pid = 'new-5401af39-0812-4c15-ba97-c304199d447f';
  $pane->panel = 'main';
  $pane->type = 'elife_article_authors';
  $pane->subtype = 'elife_article_authors';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '5401af39-0812-4c15-ba97-c304199d447f';
  $display->content['new-5401af39-0812-4c15-ba97-c304199d447f'] = $pane;
  $display->panels['main'][2] = 'new-5401af39-0812-4c15-ba97-c304199d447f';
  $pane = new stdClass();
  $pane->pid = 'new-82c57168-1163-42d1-8458-04828959847a';
  $pane->panel = 'main';
  $pane->type = 'elife_article_aff_details';
  $pane->subtype = 'elife_article_aff_details';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'pane_title' => 'Affiliation details',
      'pane_collapsed' => 1,
    ),
    'style' => 'collapsible',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'visible-small',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '82c57168-1163-42d1-8458-04828959847a';
  $display->content['new-82c57168-1163-42d1-8458-04828959847a'] = $pane;
  $display->panels['main'][3] = 'new-82c57168-1163-42d1-8458-04828959847a';
  $pane = new stdClass();
  $pane->pid = 'new-094c9fb2-04b8-47f0-b7d8-4433b0550c06';
  $pane->panel = 'main';
  $pane->type = 'elife_article_affiliation';
  $pane->subtype = 'elife_article_affiliation';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '094c9fb2-04b8-47f0-b7d8-4433b0550c06';
  $display->content['new-094c9fb2-04b8-47f0-b7d8-4433b0550c06'] = $pane;
  $display->panels['main'][4] = 'new-094c9fb2-04b8-47f0-b7d8-4433b0550c06';
  $pane = new stdClass();
  $pane->pid = 'new-e8746d63-14e7-4e72-8ccb-04ea6dca5472';
  $pane->panel = 'main';
  $pane->type = 'elife_article_doi';
  $pane->subtype = 'elife_article_doi';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'e8746d63-14e7-4e72-8ccb-04ea6dca5472';
  $display->content['new-e8746d63-14e7-4e72-8ccb-04ea6dca5472'] = $pane;
  $display->panels['main'][5] = 'new-e8746d63-14e7-4e72-8ccb-04ea6dca5472';
  $pane = new stdClass();
  $pane->pid = 'new-69b86d50-2406-4b36-8964-2594bebd1334';
  $pane->panel = 'main';
  $pane->type = 'panels_ajax_tab_tabs';
  $pane->subtype = 'panels_ajax_tab_tabs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'mini_panels' => array(
      'elife_article' => array(
        'selected' => 1,
        'tab_title' => '',
        'url_id' => '',
        'weight' => '-10',
      ),
      'elife_article_figdata' => array(
        'selected' => 1,
        'tab_title' => '',
        'url_id' => 'article-data',
        'weight' => '-9',
      ),
      'elife_article_metrics' => array(
        'selected' => 1,
        'tab_title' => '',
        'url_id' => 'article-metrics',
        'weight' => '-8',
      ),
      'elife_article_author' => array(
        'selected' => 1,
        'tab_title' => 'Article info',
        'url_id' => 'article-info',
        'weight' => '-7',
      ),
    ),
    'container_id' => 'elife-research-article-tabs',
    'url_enabled' => 1,
    'context' => array(
      0 => 'empty',
    ),
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
    'css_class' => 'visible-small',
  );
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '69b86d50-2406-4b36-8964-2594bebd1334';
  $display->content['new-69b86d50-2406-4b36-8964-2594bebd1334'] = $pane;
  $display->panels['main'][6] = 'new-69b86d50-2406-4b36-8964-2594bebd1334';
  $pane = new stdClass();
  $pane->pid = 'new-7d03e893-1d66-4846-b954-4cd08ab3b760';
  $pane->panel = 'main';
  $pane->type = 'panels_ajax_tab_container';
  $pane->subtype = 'panels_ajax_tab_container';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'container_id' => 'elife-research-article-tabs',
    'context' => array(
      0 => 'argument_entity_id:node_1',
    ),
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'article-text',
  );
  $pane->extras = array();
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '7d03e893-1d66-4846-b954-4cd08ab3b760';
  $display->content['new-7d03e893-1d66-4846-b954-4cd08ab3b760'] = $pane;
  $display->panels['main'][7] = 'new-7d03e893-1d66-4846-b954-4cd08ab3b760';
  $pane = new stdClass();
  $pane->pid = 'new-4f77048a-f8f1-4f37-87e0-3ceb9b627d2b';
  $pane->panel = 'side_bottom';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Jump-links floater container',
    'title' => '',
    'body' => 'placeholder-text',
    'format' => 'plain_text',
    'substitute' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => 'jump-links-anchor-container',
    'css_class' => 'hidden-small',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '4f77048a-f8f1-4f37-87e0-3ceb9b627d2b';
  $display->content['new-4f77048a-f8f1-4f37-87e0-3ceb9b627d2b'] = $pane;
  $display->panels['side_bottom'][0] = 'new-4f77048a-f8f1-4f37-87e0-3ceb9b627d2b';
  $pane = new stdClass();
  $pane->pid = 'new-5aa44b1d-408e-444f-ac50-98ecec1fc3bd';
  $pane->panel = 'side_lens';
  $pane->type = 'elife_lens_icon';
  $pane->subtype = 'elife_lens_icon';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'override_title_heading' => 'h2',
    'lens_url' => 'http://lens.elifesciences.org',
    'form_build_id' => 'form-eT-ED-u8WD-YdLSzSk6eQnso9-B9exJeqhZiVgXqdsU',
    'form_token' => 'wPceBBtmR3MeGmOZqtiry7rMOP4tc_ZgN4Wn70X-uvQ',
    'form_id' => 'elife_lens_icon_edit_form',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '5aa44b1d-408e-444f-ac50-98ecec1fc3bd';
  $display->content['new-5aa44b1d-408e-444f-ac50-98ecec1fc3bd'] = $pane;
  $display->panels['side_lens'][0] = 'new-5aa44b1d-408e-444f-ac50-98ecec1fc3bd';
  $pane = new stdClass();
  $pane->pid = 'new-bdde5886-02c1-4979-8096-b6b1af48e2b4';
  $pane->panel = 'side_link';
  $pane->type = 'elife_article_repro_belongs_to';
  $pane->subtype = 'elife_article_repro_belongs_to';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->uuid = 'bdde5886-02c1-4979-8096-b6b1af48e2b4';
  $display->content['new-bdde5886-02c1-4979-8096-b6b1af48e2b4'] = $pane;
  $display->panels['side_link'][0] = 'new-bdde5886-02c1-4979-8096-b6b1af48e2b4';
  $pane = new stdClass();
  $pane->pid = 'new-c3a4cd7c-d61d-429f-96d9-db367a359e26';
  $pane->panel = 'side_top';
  $pane->type = 'elife_article_toolbox';
  $pane->subtype = 'elife_article_toolbox';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->uuid = 'c3a4cd7c-d61d-429f-96d9-db367a359e26';
  $display->content['new-c3a4cd7c-d61d-429f-96d9-db367a359e26'] = $pane;
  $display->panels['side_top'][0] = 'new-c3a4cd7c-d61d-429f-96d9-db367a359e26';
  $pane = new stdClass();
  $pane->pid = 'new-f57dee68-7d17-40b4-85e3-293ed11e1198';
  $pane->panel = 'side_top';
  $pane->type = 'elife_article_related';
  $pane->subtype = 'elife_article_related';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => 'Related content',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => 'related-content',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'f57dee68-7d17-40b4-85e3-293ed11e1198';
  $display->content['new-f57dee68-7d17-40b4-85e3-293ed11e1198'] = $pane;
  $display->panels['side_top'][1] = 'new-f57dee68-7d17-40b4-85e3-293ed11e1198';
  $pane = new stdClass();
  $pane->pid = 'new-13c4779e-880b-46db-a38e-bc3cec009623';
  $pane->panel = 'side_top';
  $pane->type = 'views_panes';
  $pane->subtype = 'elife_subject_podcasts-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'field_elife_pc_subject_target_id' => '%elife_article_reference:nid',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '13c4779e-880b-46db-a38e-bc3cec009623';
  $display->content['new-13c4779e-880b-46db-a38e-bc3cec009623'] = $pane;
  $display->panels['side_top'][2] = 'new-13c4779e-880b-46db-a38e-bc3cec009623';
  $pane = new stdClass();
  $pane->pid = 'new-d9065221-a6d3-4ec2-b330-459713b5baed';
  $pane->panel = 'side_top';
  $pane->type = 'elife_article_jumpto';
  $pane->subtype = 'elife_article_jumpto';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => 'Jump to:',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'hidden-small',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'd9065221-a6d3-4ec2-b330-459713b5baed';
  $display->content['new-d9065221-a6d3-4ec2-b330-459713b5baed'] = $pane;
  $display->panels['side_top'][3] = 'new-d9065221-a6d3-4ec2-b330-459713b5baed';
  $pane = new stdClass();
  $pane->pid = 'new-e7d25bb3-f456-4715-a925-9a2914983115';
  $pane->panel = 'side_top';
  $pane->type = 'elife_article_categories';
  $pane->subtype = 'elife_article_categories';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => 'Categories & tags',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'hidden-small',
  );
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'e7d25bb3-f456-4715-a925-9a2914983115';
  $display->content['new-e7d25bb3-f456-4715-a925-9a2914983115'] = $pane;
  $display->panels['side_top'][4] = 'new-e7d25bb3-f456-4715-a925-9a2914983115';
  $pane = new stdClass();
  $pane->pid = 'new-be3653ce-d915-40bd-80e9-7b31a479c687';
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
    'form_build_id' => 'form-fb8zNTE6uVDRAqg8UsD3U6gVJXJ-OspBGfDBV_grBH0',
    'form_token' => '6Jt7dNdc-ZWGaHatCl43gr6Iuglxc-Paf2GA2xLai9A',
    'form_id' => 'elife_content_alerts_sign_up_edit',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'be3653ce-d915-40bd-80e9-7b31a479c687';
  $display->content['new-be3653ce-d915-40bd-80e9-7b31a479c687'] = $pane;
  $display->panels['side_top'][5] = 'new-be3653ce-d915-40bd-80e9-7b31a479c687';
  $pane = new stdClass();
  $pane->pid = 'new-2f7bfe63-2c67-4846-bee6-ab62caab867d';
  $pane->panel = 'top';
  $pane->type = 'panels_ajax_tab_tabs';
  $pane->subtype = 'panels_ajax_tab_tabs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'mini_panels' => array(
      'elife_article' => array(
        'selected' => 1,
        'tab_title' => '',
        'url_id' => '',
        'weight' => '-10',
      ),
      'elife_article_figdata' => array(
        'selected' => 1,
        'tab_title' => '',
        'url_id' => 'article-data',
        'weight' => '-9',
      ),
      'elife_article_metrics' => array(
        'selected' => 1,
        'tab_title' => '',
        'url_id' => 'article-metrics',
        'weight' => '-8',
      ),
      'elife_article_author' => array(
        'selected' => 1,
        'tab_title' => '',
        'url_id' => 'article-info',
        'weight' => '-7',
      ),
    ),
    'container_id' => 'elife-research-article-tabs',
    'url_enabled' => 1,
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
  $pane->css = array(
    'css_id' => 'article',
    'css_class' => 'hidden-small',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '2f7bfe63-2c67-4846-bee6-ab62caab867d';
  $display->content['new-2f7bfe63-2c67-4846-bee6-ab62caab867d'] = $pane;
  $display->panels['top'][0] = 'new-2f7bfe63-2c67-4846-bee6-ab62caab867d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__elife_research_article'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__elife_sub_article';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -27;
  $handler->conf = array(
    'title' => 'eLife Sub Article',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Parent Article',
        'keyword' => 'parent',
        'name' => 'entity_from_field:field_elife_a_parent-node-node',
        'delta' => 0,
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'name' => 'elife_sub_article',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'elife_article_ver' => 'elife_article_ver',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'entity_field_value:node:elife_article_ver:field_elife_a_subarticle',
          'settings' => array(
            'field_elife_a_subarticle' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_elife_a_subarticle_value' => array(
              0 => 1,
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'title' => array(
          'value' => '[node:title] | [node:ancestor-title] | [site:name]',
        ),
        'description' => array(
          'value' => '[node:title] | [node:impact]',
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
  $display->title = '%node:title | %parent:title';
  $display->uuid = 'e28c70c8-0736-4f75-9072-ca1f646aae96';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-3887e7e8-63a6-40cd-b0db-2dfa256c8671';
  $pane->panel = 'main';
  $pane->type = 'elife_article_title';
  $pane->subtype = 'elife_article_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'relationship_entity_from_field:field_elife_a_parent-node-node_1',
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
  $pane->uuid = '3887e7e8-63a6-40cd-b0db-2dfa256c8671';
  $display->content['new-3887e7e8-63a6-40cd-b0db-2dfa256c8671'] = $pane;
  $display->panels['main'][0] = 'new-3887e7e8-63a6-40cd-b0db-2dfa256c8671';
  $pane = new stdClass();
  $pane->pid = 'new-3c2eeacb-4398-4db5-8e80-2d1f8cfb18ee';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '3c2eeacb-4398-4db5-8e80-2d1f8cfb18ee';
  $display->content['new-3c2eeacb-4398-4db5-8e80-2d1f8cfb18ee'] = $pane;
  $display->panels['main'][1] = 'new-3c2eeacb-4398-4db5-8e80-2d1f8cfb18ee';
  $pane = new stdClass();
  $pane->pid = 'new-6617051e-7a29-4ea6-9469-7dc72e9cefc6';
  $pane->panel = 'main';
  $pane->type = 'elife_article_authors';
  $pane->subtype = 'elife_article_authors';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'relationship_entity_from_field:field_elife_a_parent-node-node_1',
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
  $pane->uuid = '6617051e-7a29-4ea6-9469-7dc72e9cefc6';
  $display->content['new-6617051e-7a29-4ea6-9469-7dc72e9cefc6'] = $pane;
  $display->panels['main'][2] = 'new-6617051e-7a29-4ea6-9469-7dc72e9cefc6';
  $pane = new stdClass();
  $pane->pid = 'new-d037a30d-fbff-4f38-8084-1b544df058ac';
  $pane->panel = 'main';
  $pane->type = 'elife_article_aff_details';
  $pane->subtype = 'elife_article_aff_details';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'relationship_entity_from_field:field_elife_a_parent-node-node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'pane_title' => 'Affiliation details',
      'pane_collapsed' => 1,
    ),
    'style' => 'collapsible',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'visible-small',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'd037a30d-fbff-4f38-8084-1b544df058ac';
  $display->content['new-d037a30d-fbff-4f38-8084-1b544df058ac'] = $pane;
  $display->panels['main'][3] = 'new-d037a30d-fbff-4f38-8084-1b544df058ac';
  $pane = new stdClass();
  $pane->pid = 'new-21d090fd-15ab-4c37-b8ce-87d648a972bf';
  $pane->panel = 'main';
  $pane->type = 'elife_article_affiliation';
  $pane->subtype = 'elife_article_affiliation';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'relationship_entity_from_field:field_elife_a_parent-node-node_1',
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '21d090fd-15ab-4c37-b8ce-87d648a972bf';
  $display->content['new-21d090fd-15ab-4c37-b8ce-87d648a972bf'] = $pane;
  $display->panels['main'][4] = 'new-21d090fd-15ab-4c37-b8ce-87d648a972bf';
  $pane = new stdClass();
  $pane->pid = 'new-b3f0997e-8a71-4fe8-be78-ffa5d8919153';
  $pane->panel = 'main';
  $pane->type = 'elife_article_doi';
  $pane->subtype = 'elife_article_doi';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'b3f0997e-8a71-4fe8-be78-ffa5d8919153';
  $display->content['new-b3f0997e-8a71-4fe8-be78-ffa5d8919153'] = $pane;
  $display->panels['main'][5] = 'new-b3f0997e-8a71-4fe8-be78-ffa5d8919153';
  $pane = new stdClass();
  $pane->pid = 'new-2c65d414-314b-4dce-a983-f36374fb9293';
  $pane->panel = 'main';
  $pane->type = 'elife_article_markup_doi';
  $pane->subtype = 'elife_article_markup_doi';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '2c65d414-314b-4dce-a983-f36374fb9293';
  $display->content['new-2c65d414-314b-4dce-a983-f36374fb9293'] = $pane;
  $display->panels['main'][6] = 'new-2c65d414-314b-4dce-a983-f36374fb9293';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__elife_sub_article'] = $handler;

  return $export;
}
