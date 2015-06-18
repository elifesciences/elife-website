<?php
/**
 * @file
 * elife_collection.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function elife_collection_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'elife_collection_articles';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'eLife Collection Articles';
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
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['element_type'] = '';
  $handler->display->display_options['style_options']['row']['first_class'] = '';
  $handler->display->display_options['style_options']['row']['last_class'] = '';
  $handler->display->display_options['style_options']['row']['striping_classes'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['id'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['table'] = 'field_data_field_elife_a_versions';
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['field'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_elife_a_keyword_target_id']['id'] = 'field_elife_a_keyword_target_id';
  $handler->display->display_options['relationships']['field_elife_a_keyword_target_id']['table'] = 'field_data_field_elife_a_keyword';
  $handler->display->display_options['relationships']['field_elife_a_keyword_target_id']['field'] = 'field_elife_a_keyword_target_id';
  $handler->display->display_options['relationships']['field_elife_a_keyword_target_id']['relationship'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['relationships']['field_elife_a_keyword_target_id']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: First Publication Date (field_elife_a_fpubdate) */
  $handler->display->display_options['sorts']['field_elife_a_fpubdate_value']['id'] = 'field_elife_a_fpubdate_value';
  $handler->display->display_options['sorts']['field_elife_a_fpubdate_value']['table'] = 'field_data_field_elife_a_fpubdate';
  $handler->display->display_options['sorts']['field_elife_a_fpubdate_value']['field'] = 'field_elife_a_fpubdate_value';
  $handler->display->display_options['sorts']['field_elife_a_fpubdate_value']['order'] = 'DESC';
  /* Sort criterion: Content: Updated Date (field_elife_a_update) */
  $handler->display->display_options['sorts']['field_elife_a_update_value']['id'] = 'field_elife_a_update_value';
  $handler->display->display_options['sorts']['field_elife_a_update_value']['table'] = 'field_data_field_elife_a_update';
  $handler->display->display_options['sorts']['field_elife_a_update_value']['field'] = 'field_elife_a_update_value';
  $handler->display->display_options['sorts']['field_elife_a_update_value']['relationship'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['sorts']['field_elife_a_update_value']['order'] = 'DESC';
  /* Contextual filter: Field: Full Title (field_elife_a_full_title) */
  $handler->display->display_options['arguments']['field_elife_a_full_title_value']['id'] = 'field_elife_a_full_title_value';
  $handler->display->display_options['arguments']['field_elife_a_full_title_value']['table'] = 'field_data_field_elife_a_full_title';
  $handler->display->display_options['arguments']['field_elife_a_full_title_value']['field'] = 'field_elife_a_full_title_value';
  $handler->display->display_options['arguments']['field_elife_a_full_title_value']['relationship'] = 'field_elife_a_keyword_target_id';
  $handler->display->display_options['arguments']['field_elife_a_full_title_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_elife_a_full_title_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_elife_a_full_title_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_elife_a_full_title_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_elife_a_full_title_value']['limit'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
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

  /* Display: Collection articles */
  $handler = $view->new_display('panel_pane', 'Collection articles', 'elife_collection_articles');
  $handler->display->display_options['argument_input'] = array(
    'field_elife_a_full_title_value' => array(
      'type' => 'user',
      'context' => 'node_edit_form.field_elife_a_full_title',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Field: Full Title (field_elife_a_full_title)',
    ),
  );
  $export['elife_collection_articles'] = $view;

  return $export;
}
