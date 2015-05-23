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
  $export['elife_contributor_ref_filter'] = $view;

  return $export;
}
