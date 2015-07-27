<?php
/**
 * @file
 * elife_article.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function elife_article_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'elife_article_version_node_group';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Article version node group';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'All nodes in the article version group';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Contextual filter: Content: Parent (field_elife_a_parent) */
  $handler->display->display_options['arguments']['field_elife_a_parent_target_id']['id'] = 'field_elife_a_parent_target_id';
  $handler->display->display_options['arguments']['field_elife_a_parent_target_id']['table'] = 'field_data_field_elife_a_parent';
  $handler->display->display_options['arguments']['field_elife_a_parent_target_id']['field'] = 'field_elife_a_parent_target_id';
  $handler->display->display_options['arguments']['field_elife_a_parent_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_elife_a_parent_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_elife_a_parent_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_elife_a_parent_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_elife_a_parent_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'elife_article_ver' => 'elife_article_ver',
    'elife_contributor' => 'elife_contributor',
    'elife_fragment' => 'elife_fragment',
  );
  $export['elife_article_version_node_group'] = $view;

  $view = new view();
  $view->name = 'elife_articles_without_pubdate';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Articles without pub-date';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['id'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['table'] = 'field_data_field_elife_a_versions';
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['field'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  /* Field: Content: First Publication Date */
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['id'] = 'field_elife_a_fpubdate';
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['table'] = 'field_data_field_elife_a_fpubdate';
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['field'] = 'field_elife_a_fpubdate';
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['label'] = '';
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['format_date_sql'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'elife_article' => 'elife_article',
  );
  /* Filter criterion: Content: Article versions (field_elife_a_versions:delta) */
  $handler->display->display_options['filters']['delta']['id'] = 'delta';
  $handler->display->display_options['filters']['delta']['table'] = 'field_data_field_elife_a_versions';
  $handler->display->display_options['filters']['delta']['field'] = 'delta';
  $handler->display->display_options['filters']['delta']['value']['value'] = '0';
  /* Filter criterion: Content: First Publication Date (field_elife_a_fpubdate) */
  $handler->display->display_options['filters']['field_elife_a_fpubdate_value']['id'] = 'field_elife_a_fpubdate_value';
  $handler->display->display_options['filters']['field_elife_a_fpubdate_value']['table'] = 'field_data_field_elife_a_fpubdate';
  $handler->display->display_options['filters']['field_elife_a_fpubdate_value']['field'] = 'field_elife_a_fpubdate_value';
  $handler->display->display_options['filters']['field_elife_a_fpubdate_value']['operator'] = 'empty';
  $export['elife_articles_without_pubdate'] = $view;

  $view = new view();
  $view->name = 'elife_contributor_ref_filter';
  $view->description = '';
  $view->tag = 'elife';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'Contributor references filter';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Field collection item: Entity with the Basic references (field_elife_a_basic_ref) */
  $handler->display->display_options['relationships']['field_elife_a_basic_ref_node']['id'] = 'field_elife_a_basic_ref_node';
  $handler->display->display_options['relationships']['field_elife_a_basic_ref_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_elife_a_basic_ref_node']['field'] = 'field_elife_a_basic_ref_node';
  /* Field: Field collection item: Key */
  $handler->display->display_options['fields']['field_elife_a_ref_key']['id'] = 'field_elife_a_ref_key';
  $handler->display->display_options['fields']['field_elife_a_ref_key']['table'] = 'field_data_field_elife_a_ref_key';
  $handler->display->display_options['fields']['field_elife_a_ref_key']['field'] = 'field_elife_a_ref_key';
  $handler->display->display_options['fields']['field_elife_a_ref_key']['label'] = '';
  $handler->display->display_options['fields']['field_elife_a_ref_key']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Type */
  $handler->display->display_options['fields']['field_elife_a_basic_ref_type']['id'] = 'field_elife_a_basic_ref_type';
  $handler->display->display_options['fields']['field_elife_a_basic_ref_type']['table'] = 'field_data_field_elife_a_basic_ref_type';
  $handler->display->display_options['fields']['field_elife_a_basic_ref_type']['field'] = 'field_elife_a_basic_ref_type';
  $handler->display->display_options['fields']['field_elife_a_basic_ref_type']['label'] = '';
  $handler->display->display_options['fields']['field_elife_a_basic_ref_type']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Field collection item ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['label'] = '';
  $handler->display->display_options['fields']['item_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['item_id']['separator'] = '';
  /* Sort criterion: Content: Basic references (field_elife_a_basic_ref:delta) */
  $handler->display->display_options['sorts']['delta']['id'] = 'delta';
  $handler->display->display_options['sorts']['delta']['table'] = 'field_data_field_elife_a_basic_ref';
  $handler->display->display_options['sorts']['delta']['field'] = 'delta';
  $handler->display->display_options['sorts']['delta']['relationship'] = 'field_elife_a_rel_ref_node';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_elife_a_basic_ref_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: Contributor basic reference filter */
  $handler = $view->new_display('entityreference', 'Contributor basic reference filter', 'contributor_basic_ref_filter');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'field_elife_a_basic_ref_type' => 'field_elife_a_basic_ref_type',
    'field_elife_a_ref_key' => 'field_elife_a_ref_key',
    'item_id' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_elife_a_basic_ref_type' => 'field_elife_a_basic_ref_type',
    'field_elife_a_ref_key' => 'field_elife_a_ref_key',
    'item_id' => 'item_id',
  );
  $handler->display->display_options['row_options']['separator'] = '|';
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: Contributor funding reference filter */
  $handler = $view->new_display('entityreference', 'Contributor funding reference filter', 'contributor_fund_ref_filter');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'field_elife_a_ref_key' => 'field_elife_a_ref_key',
    'item_id' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_elife_a_ref_key' => 'field_elife_a_ref_key',
    'item_id' => 'item_id',
  );
  $handler->display->display_options['row_options']['separator'] = '|';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field collection item: Entity with the Funding references (field_elife_a_fund_ref) */
  $handler->display->display_options['relationships']['field_elife_a_fund_ref_node']['id'] = 'field_elife_a_fund_ref_node';
  $handler->display->display_options['relationships']['field_elife_a_fund_ref_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_elife_a_fund_ref_node']['field'] = 'field_elife_a_fund_ref_node';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Key */
  $handler->display->display_options['fields']['field_elife_a_ref_key']['id'] = 'field_elife_a_ref_key';
  $handler->display->display_options['fields']['field_elife_a_ref_key']['table'] = 'field_data_field_elife_a_ref_key';
  $handler->display->display_options['fields']['field_elife_a_ref_key']['field'] = 'field_elife_a_ref_key';
  $handler->display->display_options['fields']['field_elife_a_ref_key']['label'] = '';
  $handler->display->display_options['fields']['field_elife_a_ref_key']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Field collection item ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['label'] = '';
  $handler->display->display_options['fields']['item_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['item_id']['separator'] = '';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Basic references (field_elife_a_basic_ref:delta) */
  $handler->display->display_options['sorts']['delta']['id'] = 'delta';
  $handler->display->display_options['sorts']['delta']['table'] = 'field_data_field_elife_a_basic_ref';
  $handler->display->display_options['sorts']['delta']['field'] = 'delta';
  $handler->display->display_options['sorts']['delta']['relationship'] = 'field_elife_a_fund_ref_node';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_elife_a_fund_ref_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: Contributor affiliation reference filter */
  $handler = $view->new_display('entityreference', 'Contributor affiliation reference filter', 'contributor_aff_ref_filter');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'field_elife_a_ref_key' => 'field_elife_a_ref_key',
    'item_id' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_elife_a_ref_key' => 'field_elife_a_ref_key',
    'item_id' => 'item_id',
  );
  $handler->display->display_options['row_options']['separator'] = '|';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field collection item: Entity with the Affiliation references (field_elife_a_aff_ref) */
  $handler->display->display_options['relationships']['field_elife_a_aff_ref_node']['id'] = 'field_elife_a_aff_ref_node';
  $handler->display->display_options['relationships']['field_elife_a_aff_ref_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_elife_a_aff_ref_node']['field'] = 'field_elife_a_aff_ref_node';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Key */
  $handler->display->display_options['fields']['field_elife_a_ref_key']['id'] = 'field_elife_a_ref_key';
  $handler->display->display_options['fields']['field_elife_a_ref_key']['table'] = 'field_data_field_elife_a_ref_key';
  $handler->display->display_options['fields']['field_elife_a_ref_key']['field'] = 'field_elife_a_ref_key';
  $handler->display->display_options['fields']['field_elife_a_ref_key']['label'] = '';
  $handler->display->display_options['fields']['field_elife_a_ref_key']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Field collection item ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['label'] = '';
  $handler->display->display_options['fields']['item_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['item_id']['separator'] = '';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Basic references (field_elife_a_basic_ref:delta) */
  $handler->display->display_options['sorts']['delta']['id'] = 'delta';
  $handler->display->display_options['sorts']['delta']['table'] = 'field_data_field_elife_a_basic_ref';
  $handler->display->display_options['sorts']['delta']['field'] = 'delta';
  $handler->display->display_options['sorts']['delta']['relationship'] = 'field_elife_a_aff_ref_node';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_elife_a_aff_ref_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: Contributor related object reference filter */
  $handler = $view->new_display('entityreference', 'Contributor related object reference filter', 'contributor_rel_ref_filter');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'field_elife_a_ref_key' => 'field_elife_a_ref_key',
    'item_id' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_elife_a_ref_key' => 'field_elife_a_ref_key',
    'item_id' => 'item_id',
  );
  $handler->display->display_options['row_options']['separator'] = '|';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field collection item: Entity with the Related object references (field_elife_a_rel_ref) */
  $handler->display->display_options['relationships']['field_elife_a_rel_ref_node']['id'] = 'field_elife_a_rel_ref_node';
  $handler->display->display_options['relationships']['field_elife_a_rel_ref_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_elife_a_rel_ref_node']['field'] = 'field_elife_a_rel_ref_node';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Key */
  $handler->display->display_options['fields']['field_elife_a_ref_key']['id'] = 'field_elife_a_ref_key';
  $handler->display->display_options['fields']['field_elife_a_ref_key']['table'] = 'field_data_field_elife_a_ref_key';
  $handler->display->display_options['fields']['field_elife_a_ref_key']['field'] = 'field_elife_a_ref_key';
  $handler->display->display_options['fields']['field_elife_a_ref_key']['label'] = '';
  $handler->display->display_options['fields']['field_elife_a_ref_key']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Field collection item ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['label'] = '';
  $handler->display->display_options['fields']['item_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['item_id']['separator'] = '';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Basic references (field_elife_a_basic_ref:delta) */
  $handler->display->display_options['sorts']['delta']['id'] = 'delta';
  $handler->display->display_options['sorts']['delta']['table'] = 'field_data_field_elife_a_basic_ref';
  $handler->display->display_options['sorts']['delta']['field'] = 'delta';
  $handler->display->display_options['sorts']['delta']['relationship'] = 'field_elife_a_rel_ref_node';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_elife_a_rel_ref_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: Contributor foot note reference filter */
  $handler = $view->new_display('entityreference', 'Contributor foot note reference filter', 'contributor_fn_ref_filter');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'field_elife_a_ref_key' => 'field_elife_a_ref_key',
    'item_id' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_elife_a_ref_key' => 'field_elife_a_ref_key',
    'item_id' => 'item_id',
  );
  $handler->display->display_options['row_options']['separator'] = '|';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field collection item: Entity with the Foot note references (field_elife_a_fn_ref) */
  $handler->display->display_options['relationships']['field_elife_a_fn_ref_node']['id'] = 'field_elife_a_fn_ref_node';
  $handler->display->display_options['relationships']['field_elife_a_fn_ref_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_elife_a_fn_ref_node']['field'] = 'field_elife_a_fn_ref_node';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Key */
  $handler->display->display_options['fields']['field_elife_a_ref_key']['id'] = 'field_elife_a_ref_key';
  $handler->display->display_options['fields']['field_elife_a_ref_key']['table'] = 'field_data_field_elife_a_ref_key';
  $handler->display->display_options['fields']['field_elife_a_ref_key']['field'] = 'field_elife_a_ref_key';
  $handler->display->display_options['fields']['field_elife_a_ref_key']['label'] = '';
  $handler->display->display_options['fields']['field_elife_a_ref_key']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Field collection item ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['label'] = '';
  $handler->display->display_options['fields']['item_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['item_id']['separator'] = '';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Basic references (field_elife_a_basic_ref:delta) */
  $handler->display->display_options['sorts']['delta']['id'] = 'delta';
  $handler->display->display_options['sorts']['delta']['table'] = 'field_data_field_elife_a_basic_ref';
  $handler->display->display_options['sorts']['delta']['field'] = 'delta';
  $handler->display->display_options['sorts']['delta']['relationship'] = 'field_elife_a_rel_ref_node';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_elife_a_fn_ref_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $export['elife_contributor_ref_filter'] = $view;

  $view = new view();
  $view->name = 'elife_orphaned_article_content';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Orphaned article content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Fragments and contributors';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'elife_article' => 'elife_article',
  );
  /* Filter criterion: Content: Article versions (field_elife_a_versions) */
  $handler->display->display_options['filters']['field_elife_a_versions_target_id']['id'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['filters']['field_elife_a_versions_target_id']['table'] = 'field_data_field_elife_a_versions';
  $handler->display->display_options['filters']['field_elife_a_versions_target_id']['field'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['filters']['field_elife_a_versions_target_id']['operator'] = 'empty';

  /* Display: Orphaned articles */
  $handler = $view->new_display('block', 'Orphaned articles', 'orphaned_ancestors');

  /* Display: Orphaned subarticles */
  $handler = $view->new_display('block', 'Orphaned subarticles', 'orphaned_subarticles');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Parent (field_elife_a_parent) */
  $handler->display->display_options['filters']['field_elife_a_parent_target_id_1']['id'] = 'field_elife_a_parent_target_id_1';
  $handler->display->display_options['filters']['field_elife_a_parent_target_id_1']['table'] = 'field_data_field_elife_a_parent';
  $handler->display->display_options['filters']['field_elife_a_parent_target_id_1']['field'] = 'field_elife_a_parent_target_id';
  $handler->display->display_options['filters']['field_elife_a_parent_target_id_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_elife_a_parent_target_id_1']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'elife_article_ver' => 'elife_article_ver',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  /* Filter criterion: Content: Sub article (field_elife_a_subarticle) */
  $handler->display->display_options['filters']['field_elife_a_subarticle_value']['id'] = 'field_elife_a_subarticle_value';
  $handler->display->display_options['filters']['field_elife_a_subarticle_value']['table'] = 'field_data_field_elife_a_subarticle';
  $handler->display->display_options['filters']['field_elife_a_subarticle_value']['field'] = 'field_elife_a_subarticle_value';
  $handler->display->display_options['filters']['field_elife_a_subarticle_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_elife_a_subarticle_value']['group'] = 1;

  /* Display: Orphaned fragments and contributors */
  $handler = $view->new_display('block', 'Orphaned fragments and contributors', 'orphaned_fragments_and_contributors');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Parent (field_elife_a_parent) */
  $handler->display->display_options['filters']['field_elife_a_parent_target_id_1']['id'] = 'field_elife_a_parent_target_id_1';
  $handler->display->display_options['filters']['field_elife_a_parent_target_id_1']['table'] = 'field_data_field_elife_a_parent';
  $handler->display->display_options['filters']['field_elife_a_parent_target_id_1']['field'] = 'field_elife_a_parent_target_id';
  $handler->display->display_options['filters']['field_elife_a_parent_target_id_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_elife_a_parent_target_id_1']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'elife_contributor' => 'elife_contributor',
    'elife_fragment' => 'elife_fragment',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  $export['elife_orphaned_article_content'] = $view;

  return $export;
}
