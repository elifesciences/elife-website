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
  $handler->weight = 6;
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
    $pane->pid = 'new-38367f86-bd51-47f1-89eb-8eedeb92e1bf';
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
    $pane->uuid = '38367f86-bd51-47f1-89eb-8eedeb92e1bf';
    $display->content['new-38367f86-bd51-47f1-89eb-8eedeb92e1bf'] = $pane;
    $display->panels['main'][0] = 'new-38367f86-bd51-47f1-89eb-8eedeb92e1bf';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'e8f3fed7-bfc0-4a4b-9df8-d0df72ef4fd5';
    $display->content['new-e8f3fed7-bfc0-4a4b-9df8-d0df72ef4fd5'] = $pane;
    $display->panels['main'][3] = 'new-e8f3fed7-bfc0-4a4b-9df8-d0df72ef4fd5';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'fb46f9e5-1dc3-4c3e-a22c-2ce70b0632d8';
    $display->content['new-fb46f9e5-1dc3-4c3e-a22c-2ce70b0632d8'] = $pane;
    $display->panels['main'][4] = 'new-fb46f9e5-1dc3-4c3e-a22c-2ce70b0632d8';
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '5e665e67-a315-4299-a106-b16e1123b6c6';
    $display->content['new-5e665e67-a315-4299-a106-b16e1123b6c6'] = $pane;
    $display->panels['main'][5] = 'new-5e665e67-a315-4299-a106-b16e1123b6c6';
    $pane = new stdClass();
    $pane->pid = 'new-09e0aca4-0d85-4789-8b35-b6ad8713abe4';
    $pane->panel = 'main';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_elife_a_parent';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '09e0aca4-0d85-4789-8b35-b6ad8713abe4';
    $display->content['new-09e0aca4-0d85-4789-8b35-b6ad8713abe4'] = $pane;
    $display->panels['main'][6] = 'new-09e0aca4-0d85-4789-8b35-b6ad8713abe4';
    $pane = new stdClass();
    $pane->pid = 'new-c83bdd6b-4f19-4d81-bb97-a265a0a8a5dd';
    $pane->panel = 'main';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_elife_a_fragments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_label',
      'delta_limit' => '0',
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = 'c83bdd6b-4f19-4d81-bb97-a265a0a8a5dd';
    $display->content['new-c83bdd6b-4f19-4d81-bb97-a265a0a8a5dd'] = $pane;
    $display->panels['main'][7] = 'new-c83bdd6b-4f19-4d81-bb97-a265a0a8a5dd';
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
  $handler->weight = 4;
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '08157a68-3288-4857-91ba-a43b1655e174';
    $display->content['new-08157a68-3288-4857-91ba-a43b1655e174'] = $pane;
    $display->panels['main'][3] = 'new-08157a68-3288-4857-91ba-a43b1655e174';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '407e8ab5-92e3-4e6d-9147-ddd506c06da7';
    $display->content['new-407e8ab5-92e3-4e6d-9147-ddd506c06da7'] = $pane;
    $display->panels['main'][4] = 'new-407e8ab5-92e3-4e6d-9147-ddd506c06da7';
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'c25c5118-e3c9-44c4-b3c1-43f789dbf0a9';
    $display->content['new-c25c5118-e3c9-44c4-b3c1-43f789dbf0a9'] = $pane;
    $display->panels['main'][5] = 'new-c25c5118-e3c9-44c4-b3c1-43f789dbf0a9';
    $pane = new stdClass();
    $pane->pid = 'new-b9f1b398-5930-4f0a-94d4-354e400f10c6';
    $pane->panel = 'main';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_elife_a_parent';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = 'b9f1b398-5930-4f0a-94d4-354e400f10c6';
    $display->content['new-b9f1b398-5930-4f0a-94d4-354e400f10c6'] = $pane;
    $display->panels['main'][6] = 'new-b9f1b398-5930-4f0a-94d4-354e400f10c6';
    $pane = new stdClass();
    $pane->pid = 'new-63ddeb40-6a42-4b5c-a1e9-94459a8d85b4';
    $pane->panel = 'main';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_elife_a_fragments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_label',
      'delta_limit' => '0',
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = '63ddeb40-6a42-4b5c-a1e9-94459a8d85b4';
    $display->content['new-63ddeb40-6a42-4b5c-a1e9-94459a8d85b4'] = $pane;
    $display->panels['main'][7] = 'new-63ddeb40-6a42-4b5c-a1e9-94459a8d85b4';
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
  $handler->weight = 5;
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '341e49ae-4f11-41ae-80a5-c07e3b6f1440';
    $display->content['new-341e49ae-4f11-41ae-80a5-c07e3b6f1440'] = $pane;
    $display->panels['main'][3] = 'new-341e49ae-4f11-41ae-80a5-c07e3b6f1440';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '637c6a4e-8242-44ed-a91a-1f73a70e970e';
    $display->content['new-637c6a4e-8242-44ed-a91a-1f73a70e970e'] = $pane;
    $display->panels['main'][4] = 'new-637c6a4e-8242-44ed-a91a-1f73a70e970e';
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'd4466721-e428-4b1d-90e4-93a14c5169b3';
    $display->content['new-d4466721-e428-4b1d-90e4-93a14c5169b3'] = $pane;
    $display->panels['main'][5] = 'new-d4466721-e428-4b1d-90e4-93a14c5169b3';
    $pane = new stdClass();
    $pane->pid = 'new-feca50bb-d9cc-4dbf-97ec-cd0b2652bc34';
    $pane->panel = 'main';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_elife_a_parent';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = 'feca50bb-d9cc-4dbf-97ec-cd0b2652bc34';
    $display->content['new-feca50bb-d9cc-4dbf-97ec-cd0b2652bc34'] = $pane;
    $display->panels['main'][6] = 'new-feca50bb-d9cc-4dbf-97ec-cd0b2652bc34';
    $pane = new stdClass();
    $pane->pid = 'new-8627c6bb-db7b-4e2c-a554-a6525eebc7a5';
    $pane->panel = 'main';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_elife_a_fragments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_label',
      'delta_limit' => '0',
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = '8627c6bb-db7b-4e2c-a554-a6525eebc7a5';
    $display->content['new-8627c6bb-db7b-4e2c-a554-a6525eebc7a5'] = $pane;
    $display->panels['main'][7] = 'new-8627c6bb-db7b-4e2c-a554-a6525eebc7a5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__elife_fragment_digest'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__elife_non_research_article';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7bafe3dd-937d-4542-be79-98794bc844f8';
    $display->content['new-7bafe3dd-937d-4542-be79-98794bc844f8'] = $pane;
    $display->panels['main'][0] = 'new-7bafe3dd-937d-4542-be79-98794bc844f8';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '8ba1fc2a-74db-4d2b-94f4-d8d6a3e25a8c';
    $display->content['new-8ba1fc2a-74db-4d2b-94f4-d8d6a3e25a8c'] = $pane;
    $display->panels['main'][1] = 'new-8ba1fc2a-74db-4d2b-94f4-d8d6a3e25a8c';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'b846e44d-db42-4d7b-9aa8-f7a17d1361fd';
    $display->content['new-b846e44d-db42-4d7b-9aa8-f7a17d1361fd'] = $pane;
    $display->panels['main'][2] = 'new-b846e44d-db42-4d7b-9aa8-f7a17d1361fd';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'e2418b5f-34be-4775-bb53-b6cefae0a375';
    $display->content['new-e2418b5f-34be-4775-bb53-b6cefae0a375'] = $pane;
    $display->panels['main'][3] = 'new-e2418b5f-34be-4775-bb53-b6cefae0a375';
    $pane = new stdClass();
    $pane->pid = 'new-df42c775-8128-4ada-8c58-5e18a6bfa72d';
    $pane->panel = 'main';
    $pane->type = 'panels_ajax_tab_tabs';
    $pane->subtype = 'panels_ajax_tab_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'mini_panels' => array(
        'elife_article_author' => array(
          'selected' => 0,
          'tab_title' => '',
          'url_id' => '',
          'weight' => '-10',
        ),
        'elife_article' => array(
          'selected' => 1,
          'tab_title' => '',
          'url_id' => '',
          'weight' => '-10',
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'df42c775-8128-4ada-8c58-5e18a6bfa72d';
    $display->content['new-df42c775-8128-4ada-8c58-5e18a6bfa72d'] = $pane;
    $display->panels['main'][4] = 'new-df42c775-8128-4ada-8c58-5e18a6bfa72d';
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '10c8f5e6-4659-46f7-b84b-86adec03ec85';
    $display->content['new-10c8f5e6-4659-46f7-b84b-86adec03ec85'] = $pane;
    $display->panels['main'][5] = 'new-10c8f5e6-4659-46f7-b84b-86adec03ec85';
    $pane = new stdClass();
    $pane->pid = 'new-071a4bce-8075-4788-ae20-d74f32bba2e7';
    $pane->panel = 'main';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_elife_a_fragments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_label',
      'delta_limit' => '0',
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '071a4bce-8075-4788-ae20-d74f32bba2e7';
    $display->content['new-071a4bce-8075-4788-ae20-d74f32bba2e7'] = $pane;
    $display->panels['main'][6] = 'new-071a4bce-8075-4788-ae20-d74f32bba2e7';
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
    $pane->pid = 'new-bb8bd804-2eec-4904-aba9-d0d3c3d037c4';
    $pane->panel = 'side_top';
    $pane->type = 'views_panes';
    $pane->subtype = 'elife_article_podcast-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_elife_p_articles_value' => '%node:field-elife-a-article-id',
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
    $pane->uuid = 'bb8bd804-2eec-4904-aba9-d0d3c3d037c4';
    $display->content['new-bb8bd804-2eec-4904-aba9-d0d3c3d037c4'] = $pane;
    $display->panels['side_top'][0] = 'new-bb8bd804-2eec-4904-aba9-d0d3c3d037c4';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b38d43dc-36d8-4afb-a1cc-335f8d79d401';
    $display->content['new-b38d43dc-36d8-4afb-a1cc-335f8d79d401'] = $pane;
    $display->panels['side_top'][1] = 'new-b38d43dc-36d8-4afb-a1cc-335f8d79d401';
    $pane = new stdClass();
    $pane->pid = 'new-9e65e0e4-4734-4e80-b701-8822cb20c66a';
    $pane->panel = 'top';
    $pane->type = 'panels_ajax_tab_tabs';
    $pane->subtype = 'panels_ajax_tab_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'mini_panels' => array(
        'elife_article_author' => array(
          'selected' => 0,
          'tab_title' => '',
          'url_id' => '',
          'weight' => '-10',
        ),
        'elife_article' => array(
          'selected' => 1,
          'tab_title' => '',
          'url_id' => '',
          'weight' => '-10',
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
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'eLife Research Article',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '91f6e30f-710f-44d0-a860-399dd44c5fc1';
    $display->content['new-91f6e30f-710f-44d0-a860-399dd44c5fc1'] = $pane;
    $display->panels['main'][0] = 'new-91f6e30f-710f-44d0-a860-399dd44c5fc1';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '5401af39-0812-4c15-ba97-c304199d447f';
    $display->content['new-5401af39-0812-4c15-ba97-c304199d447f'] = $pane;
    $display->panels['main'][1] = 'new-5401af39-0812-4c15-ba97-c304199d447f';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '094c9fb2-04b8-47f0-b7d8-4433b0550c06';
    $display->content['new-094c9fb2-04b8-47f0-b7d8-4433b0550c06'] = $pane;
    $display->panels['main'][2] = 'new-094c9fb2-04b8-47f0-b7d8-4433b0550c06';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'e8746d63-14e7-4e72-8ccb-04ea6dca5472';
    $display->content['new-e8746d63-14e7-4e72-8ccb-04ea6dca5472'] = $pane;
    $display->panels['main'][3] = 'new-e8746d63-14e7-4e72-8ccb-04ea6dca5472';
    $pane = new stdClass();
    $pane->pid = 'new-69b86d50-2406-4b36-8964-2594bebd1334';
    $pane->panel = 'main';
    $pane->type = 'panels_ajax_tab_tabs';
    $pane->subtype = 'panels_ajax_tab_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'mini_panels' => array(
        'elife_article_author' => array(
          'selected' => 1,
          'tab_title' => '',
          'url_id' => 'article-info',
          'weight' => '-10',
        ),
        'elife_article' => array(
          'selected' => 1,
          'tab_title' => '',
          'url_id' => '',
          'weight' => '-10',
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '69b86d50-2406-4b36-8964-2594bebd1334';
    $display->content['new-69b86d50-2406-4b36-8964-2594bebd1334'] = $pane;
    $display->panels['main'][4] = 'new-69b86d50-2406-4b36-8964-2594bebd1334';
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
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '7d03e893-1d66-4846-b954-4cd08ab3b760';
    $display->content['new-7d03e893-1d66-4846-b954-4cd08ab3b760'] = $pane;
    $display->panels['main'][5] = 'new-7d03e893-1d66-4846-b954-4cd08ab3b760';
    $pane = new stdClass();
    $pane->pid = 'new-f9fe78d3-3e34-45f8-9af5-d587bdaf4bd2';
    $pane->panel = 'main';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_elife_a_fragments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_label',
      'delta_limit' => '0',
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = 'f9fe78d3-3e34-45f8-9af5-d587bdaf4bd2';
    $display->content['new-f9fe78d3-3e34-45f8-9af5-d587bdaf4bd2'] = $pane;
    $display->panels['main'][6] = 'new-f9fe78d3-3e34-45f8-9af5-d587bdaf4bd2';
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
    $pane->pid = 'new-ffdb185e-6d8e-48b5-901a-2bbda76fa9ab';
    $pane->panel = 'side_top';
    $pane->type = 'views_panes';
    $pane->subtype = 'elife_article_podcast-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_elife_p_articles_value' => '%node:field-elife-a-article-id',
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
    $pane->uuid = 'ffdb185e-6d8e-48b5-901a-2bbda76fa9ab';
    $display->content['new-ffdb185e-6d8e-48b5-901a-2bbda76fa9ab'] = $pane;
    $display->panels['side_top'][0] = 'new-ffdb185e-6d8e-48b5-901a-2bbda76fa9ab';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'be3653ce-d915-40bd-80e9-7b31a479c687';
    $display->content['new-be3653ce-d915-40bd-80e9-7b31a479c687'] = $pane;
    $display->panels['side_top'][1] = 'new-be3653ce-d915-40bd-80e9-7b31a479c687';
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
        'elife_article_author' => array(
          'selected' => 1,
          'tab_title' => '',
          'url_id' => 'article-info',
          'weight' => '-9',
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
  $display->title_pane = 'new-ffdb185e-6d8e-48b5-901a-2bbda76fa9ab';
  $handler->conf['display'] = $display;
  $export['node_view__elife_research_article'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__elife_sub_article';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 3;
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '21d090fd-15ab-4c37-b8ce-87d648a972bf';
    $display->content['new-21d090fd-15ab-4c37-b8ce-87d648a972bf'] = $pane;
    $display->panels['main'][3] = 'new-21d090fd-15ab-4c37-b8ce-87d648a972bf';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'b3f0997e-8a71-4fe8-be78-ffa5d8919153';
    $display->content['new-b3f0997e-8a71-4fe8-be78-ffa5d8919153'] = $pane;
    $display->panels['main'][4] = 'new-b3f0997e-8a71-4fe8-be78-ffa5d8919153';
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '2c65d414-314b-4dce-a983-f36374fb9293';
    $display->content['new-2c65d414-314b-4dce-a983-f36374fb9293'] = $pane;
    $display->panels['main'][5] = 'new-2c65d414-314b-4dce-a983-f36374fb9293';
    $pane = new stdClass();
    $pane->pid = 'new-eee572da-64ea-4fc1-b5a0-00aea246beb2';
    $pane->panel = 'main';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_elife_a_parent';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = 'eee572da-64ea-4fc1-b5a0-00aea246beb2';
    $display->content['new-eee572da-64ea-4fc1-b5a0-00aea246beb2'] = $pane;
    $display->panels['main'][6] = 'new-eee572da-64ea-4fc1-b5a0-00aea246beb2';
    $pane = new stdClass();
    $pane->pid = 'new-1cd81622-287c-4fa3-bd87-e3a6f368f69f';
    $pane->panel = 'main';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_elife_a_fragments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_label',
      'delta_limit' => '0',
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = '1cd81622-287c-4fa3-bd87-e3a6f368f69f';
    $display->content['new-1cd81622-287c-4fa3-bd87-e3a6f368f69f'] = $pane;
    $display->panels['main'][7] = 'new-1cd81622-287c-4fa3-bd87-e3a6f368f69f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__elife_sub_article'] = $handler;

  return $export;
}
