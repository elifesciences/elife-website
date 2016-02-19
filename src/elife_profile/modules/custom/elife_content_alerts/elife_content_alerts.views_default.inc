<?php
/**
 * @file
 * elife_content_alerts.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function elife_content_alerts_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'elife_content_alerts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'eLife Content Alerts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Content Alerts';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'name',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['group']['class'] = '';
  $handler->display->display_options['style_options']['row']['element_type'] = '';
  $handler->display->display_options['style_options']['row']['first_class'] = '';
  $handler->display->display_options['style_options']['row']['last_class'] = '';
  $handler->display->display_options['style_options']['row']['striping_classes'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['id'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['table'] = 'field_data_field_elife_a_versions';
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['field'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['label'] = 'Article Version';
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_elife_a_category_target_id']['id'] = 'field_elife_a_category_target_id';
  $handler->display->display_options['relationships']['field_elife_a_category_target_id']['table'] = 'field_data_field_elife_a_category';
  $handler->display->display_options['relationships']['field_elife_a_category_target_id']['field'] = 'field_elife_a_category_target_id';
  $handler->display->display_options['relationships']['field_elife_a_category_target_id']['relationship'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['relationships']['field_elife_a_category_target_id']['label'] = 'Category';
  $handler->display->display_options['relationships']['field_elife_a_category_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_elife_a_heading_target_id']['id'] = 'field_elife_a_heading_target_id';
  $handler->display->display_options['relationships']['field_elife_a_heading_target_id']['table'] = 'field_data_field_elife_a_heading';
  $handler->display->display_options['relationships']['field_elife_a_heading_target_id']['field'] = 'field_elife_a_heading_target_id';
  $handler->display->display_options['relationships']['field_elife_a_heading_target_id']['relationship'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['relationships']['field_elife_a_heading_target_id']['label'] = 'Heading';
  $handler->display->display_options['relationships']['field_elife_a_heading_target_id']['required'] = TRUE;
  /* Field: Panel Pane - Content: Article - Content Alert */
  $handler->display->display_options['fields']['ctools_field_elife_content_alert']['id'] = 'ctools_field_elife_content_alert';
  $handler->display->display_options['fields']['ctools_field_elife_content_alert']['table'] = 'node';
  $handler->display->display_options['fields']['ctools_field_elife_content_alert']['field'] = 'ctools_field_elife_content_alert';
  $handler->display->display_options['fields']['ctools_field_elife_content_alert']['relationship'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['fields']['ctools_field_elife_content_alert']['label'] = '';
  $handler->display->display_options['fields']['ctools_field_elife_content_alert']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ctools_field_elife_content_alert']['element_default_classes'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_elife_a_heading_target_id';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['relationship'] = 'field_elife_a_heading_target_id';
  /* Sort criterion: Content: Updated Date (field_elife_a_update) */
  $handler->display->display_options['sorts']['field_elife_a_update_value']['id'] = 'field_elife_a_update_value';
  $handler->display->display_options['sorts']['field_elife_a_update_value']['table'] = 'field_data_field_elife_a_update';
  $handler->display->display_options['sorts']['field_elife_a_update_value']['field'] = 'field_elife_a_update_value';
  $handler->display->display_options['sorts']['field_elife_a_update_value']['relationship'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['sorts']['field_elife_a_update_value']['order'] = 'DESC';
  /* Sort criterion: Content: First Publication Date (field_elife_a_fpubdate) */
  $handler->display->display_options['sorts']['field_elife_a_fpubdate_value']['id'] = 'field_elife_a_fpubdate_value';
  $handler->display->display_options['sorts']['field_elife_a_fpubdate_value']['table'] = 'field_data_field_elife_a_fpubdate';
  $handler->display->display_options['sorts']['field_elife_a_fpubdate_value']['field'] = 'field_elife_a_fpubdate_value';
  $handler->display->display_options['sorts']['field_elife_a_fpubdate_value']['order'] = 'DESC';
  /* Contextual filter: Content: Updated Date (field_elife_a_update) */
  $handler->display->display_options['arguments']['field_elife_a_update_value']['id'] = 'field_elife_a_update_value';
  $handler->display->display_options['arguments']['field_elife_a_update_value']['table'] = 'field_data_field_elife_a_update';
  $handler->display->display_options['arguments']['field_elife_a_update_value']['field'] = 'field_elife_a_update_value';
  $handler->display->display_options['arguments']['field_elife_a_update_value']['relationship'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['arguments']['field_elife_a_update_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_elife_a_update_value']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['field_elife_a_update_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_elife_a_update_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_elife_a_update_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_elife_a_update_value']['year_range'] = '2012:+0';
  $handler->display->display_options['arguments']['field_elife_a_update_value']['granularity'] = 'day';
  $handler->display->display_options['arguments']['field_elife_a_update_value']['granularity_reset'] = 0;
  $handler->display->display_options['arguments']['field_elife_a_update_value']['use_fromto'] = 'no';
  /* Contextual filter: Content: Status (field_elife_a_status) */
  $handler->display->display_options['arguments']['field_elife_a_status_value']['id'] = 'field_elife_a_status_value';
  $handler->display->display_options['arguments']['field_elife_a_status_value']['table'] = 'field_data_field_elife_a_status';
  $handler->display->display_options['arguments']['field_elife_a_status_value']['field'] = 'field_elife_a_status_value';
  $handler->display->display_options['arguments']['field_elife_a_status_value']['relationship'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['arguments']['field_elife_a_status_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_elife_a_status_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_elife_a_status_value']['default_argument_options']['argument'] = 'VOR';
  $handler->display->display_options['arguments']['field_elife_a_status_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_elife_a_status_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_elife_a_status_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_elife_a_status_value']['limit'] = '0';
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
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Article versions (field_elife_a_versions:delta) */
  $handler->display->display_options['filters']['delta']['id'] = 'delta';
  $handler->display->display_options['filters']['delta']['table'] = 'field_data_field_elife_a_versions';
  $handler->display->display_options['filters']['delta']['field'] = 'delta';
  $handler->display->display_options['filters']['delta']['value']['value'] = '0';
  $handler->display->display_options['filters']['delta']['group'] = 1;
  /* Filter criterion: Taxonomy term: Type (field_elife_category_type) */
  $handler->display->display_options['filters']['field_elife_category_type_value']['id'] = 'field_elife_category_type_value';
  $handler->display->display_options['filters']['field_elife_category_type_value']['table'] = 'field_data_field_elife_category_type';
  $handler->display->display_options['filters']['field_elife_category_type_value']['field'] = 'field_elife_category_type_value';
  $handler->display->display_options['filters']['field_elife_category_type_value']['relationship'] = 'field_elife_a_category_target_id';
  $handler->display->display_options['filters']['field_elife_category_type_value']['value'] = 'display-channel';
  $handler->display->display_options['filters']['field_elife_category_type_value']['group'] = 1;
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'field_elife_a_category_target_id';
  $handler->display->display_options['filters']['name']['operator'] = 'regular_expression';
  $handler->display->display_options['filters']['name']['value'] = '^(registered report|research advance|research article|replication study|short report|tools and resources)$';
  $handler->display->display_options['filters']['name']['group'] = 1;

  /* Display: Content Alerts */
  $handler = $view->new_display('block', 'Content Alerts', 'content_alerts');

  /* Display: Content Alerts - Categories */
  $handler = $view->new_display('block', 'Content Alerts - Categories', 'content_alerts_categories');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Content Alerts - Categories';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'name',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['group']['element_type'] = 'li';
  $handler->display->display_options['style_options']['group']['class'] = '';
  $handler->display->display_options['style_options']['row']['element_type'] = '';
  $handler->display->display_options['style_options']['row']['first_class'] = '';
  $handler->display->display_options['style_options']['row']['last_class'] = '';
  $handler->display->display_options['style_options']['row']['striping_classes'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: Content Alerts - Front Matter */
  $handler = $view->new_display('block', 'Content Alerts - Front Matter', 'content_alerts_front');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Content Alerts - Front Matter';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['element_type'] = '';
  $handler->display->display_options['style_options']['row']['first_class'] = '';
  $handler->display->display_options['style_options']['row']['last_class'] = '';
  $handler->display->display_options['style_options']['row']['striping_classes'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['id'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['table'] = 'field_data_field_elife_a_versions';
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['field'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['label'] = 'Article Version';
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_elife_a_category_target_id']['id'] = 'field_elife_a_category_target_id';
  $handler->display->display_options['relationships']['field_elife_a_category_target_id']['table'] = 'field_data_field_elife_a_category';
  $handler->display->display_options['relationships']['field_elife_a_category_target_id']['field'] = 'field_elife_a_category_target_id';
  $handler->display->display_options['relationships']['field_elife_a_category_target_id']['relationship'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['relationships']['field_elife_a_category_target_id']['label'] = 'Category';
  $handler->display->display_options['relationships']['field_elife_a_category_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Panel Pane - Content: Article - Content Alert */
  $handler->display->display_options['fields']['ctools_field_elife_content_alert']['id'] = 'ctools_field_elife_content_alert';
  $handler->display->display_options['fields']['ctools_field_elife_content_alert']['table'] = 'node';
  $handler->display->display_options['fields']['ctools_field_elife_content_alert']['field'] = 'ctools_field_elife_content_alert';
  $handler->display->display_options['fields']['ctools_field_elife_content_alert']['relationship'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['fields']['ctools_field_elife_content_alert']['label'] = '';
  $handler->display->display_options['fields']['ctools_field_elife_content_alert']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ctools_field_elife_content_alert']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Updated Date (field_elife_a_update) */
  $handler->display->display_options['sorts']['field_elife_a_update_value']['id'] = 'field_elife_a_update_value';
  $handler->display->display_options['sorts']['field_elife_a_update_value']['table'] = 'field_data_field_elife_a_update';
  $handler->display->display_options['sorts']['field_elife_a_update_value']['field'] = 'field_elife_a_update_value';
  $handler->display->display_options['sorts']['field_elife_a_update_value']['relationship'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['sorts']['field_elife_a_update_value']['order'] = 'DESC';
  /* Sort criterion: Content: First Publication Date (field_elife_a_fpubdate) */
  $handler->display->display_options['sorts']['field_elife_a_fpubdate_value']['id'] = 'field_elife_a_fpubdate_value';
  $handler->display->display_options['sorts']['field_elife_a_fpubdate_value']['table'] = 'field_data_field_elife_a_fpubdate';
  $handler->display->display_options['sorts']['field_elife_a_fpubdate_value']['field'] = 'field_elife_a_fpubdate_value';
  $handler->display->display_options['sorts']['field_elife_a_fpubdate_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Article versions (field_elife_a_versions:delta) */
  $handler->display->display_options['filters']['delta']['id'] = 'delta';
  $handler->display->display_options['filters']['delta']['table'] = 'field_data_field_elife_a_versions';
  $handler->display->display_options['filters']['delta']['field'] = 'delta';
  $handler->display->display_options['filters']['delta']['value']['value'] = '0';
  $handler->display->display_options['filters']['delta']['group'] = 1;
  /* Filter criterion: Taxonomy term: Type (field_elife_category_type) */
  $handler->display->display_options['filters']['field_elife_category_type_value']['id'] = 'field_elife_category_type_value';
  $handler->display->display_options['filters']['field_elife_category_type_value']['table'] = 'field_data_field_elife_category_type';
  $handler->display->display_options['filters']['field_elife_category_type_value']['field'] = 'field_elife_category_type_value';
  $handler->display->display_options['filters']['field_elife_category_type_value']['relationship'] = 'field_elife_a_category_target_id';
  $handler->display->display_options['filters']['field_elife_category_type_value']['value'] = 'display-channel';
  $handler->display->display_options['filters']['field_elife_category_type_value']['group'] = 1;
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'field_elife_a_category_target_id';
  $handler->display->display_options['filters']['name']['operator'] = 'regular_expression';
  $handler->display->display_options['filters']['name']['value'] = '^(editorial|feature article|insight)$';
  $handler->display->display_options['filters']['name']['group'] = 1;
  $export['elife_content_alerts'] = $view;

  return $export;
}
