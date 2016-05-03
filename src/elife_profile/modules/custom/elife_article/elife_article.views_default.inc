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
