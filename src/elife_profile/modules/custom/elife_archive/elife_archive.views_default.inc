<?php
/**
 * @file
 * elife_archive.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function elife_archive_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'elife_archive_by_month';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Archive by month';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Article archive';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '21600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '21600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'name',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['id'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['table'] = 'field_data_field_elife_a_versions';
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['field'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['label'] = 'Article version';
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_elife_a_category_target_id']['id'] = 'field_elife_a_category_target_id';
  $handler->display->display_options['relationships']['field_elife_a_category_target_id']['table'] = 'field_data_field_elife_a_category';
  $handler->display->display_options['relationships']['field_elife_a_category_target_id']['field'] = 'field_elife_a_category_target_id';
  $handler->display->display_options['relationships']['field_elife_a_category_target_id']['relationship'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['relationships']['field_elife_a_category_target_id']['label'] = 'Article version category';
  $handler->display->display_options['relationships']['field_elife_a_category_target_id']['required'] = TRUE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_elife_a_category_target_id';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Content: Rendered Content */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['relationship'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['fields']['rendered_entity']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity']['element_type'] = '0';
  $handler->display->display_options['fields']['rendered_entity']['element_label_type'] = '0';
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['rendered_entity']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'teaser';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'field_elife_a_category_target_id';
  /* Sort criterion: Content: First Publication Date (field_elife_a_fpubdate) */
  $handler->display->display_options['sorts']['field_elife_a_fpubdate_value']['id'] = 'field_elife_a_fpubdate_value';
  $handler->display->display_options['sorts']['field_elife_a_fpubdate_value']['table'] = 'field_data_field_elife_a_fpubdate';
  $handler->display->display_options['sorts']['field_elife_a_fpubdate_value']['field'] = 'field_elife_a_fpubdate_value';
  $handler->display->display_options['sorts']['field_elife_a_fpubdate_value']['order'] = 'DESC';
  /* Contextual filter: Content: First Publication Date (field_elife_a_fpubdate) */
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['id'] = 'field_elife_a_fpubdate_value';
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['table'] = 'field_data_field_elife_a_fpubdate';
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['field'] = 'field_elife_a_fpubdate_value';
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['title'] = 'Article archive, %1';
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['summary']['sort_order'] = 'desc';
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['summary_options']['base_path'] = 'archive';
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['year_range'] = '2012:+0';
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['use_fromto'] = 'no';
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['title_format_custom'] = 'F Y';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
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
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'field_elife_a_category_target_id';
  $handler->display->display_options['filters']['name']['value'] = 'Editorial';
  $handler->display->display_options['filters']['name']['group'] = 2;
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name_1']['id'] = 'name_1';
  $handler->display->display_options['filters']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name_1']['field'] = 'name';
  $handler->display->display_options['filters']['name_1']['relationship'] = 'field_elife_a_category_target_id';
  $handler->display->display_options['filters']['name_1']['value'] = 'Feature article';
  $handler->display->display_options['filters']['name_1']['group'] = 2;
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name_2']['id'] = 'name_2';
  $handler->display->display_options['filters']['name_2']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name_2']['field'] = 'name';
  $handler->display->display_options['filters']['name_2']['relationship'] = 'field_elife_a_category_target_id';
  $handler->display->display_options['filters']['name_2']['value'] = 'Insight';
  $handler->display->display_options['filters']['name_2']['group'] = 2;
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name_3']['id'] = 'name_3';
  $handler->display->display_options['filters']['name_3']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name_3']['field'] = 'name';
  $handler->display->display_options['filters']['name_3']['relationship'] = 'field_elife_a_category_target_id';
  $handler->display->display_options['filters']['name_3']['value'] = 'Research article';
  $handler->display->display_options['filters']['name_3']['group'] = 2;
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name_4']['id'] = 'name_4';
  $handler->display->display_options['filters']['name_4']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name_4']['field'] = 'name';
  $handler->display->display_options['filters']['name_4']['relationship'] = 'field_elife_a_category_target_id';
  $handler->display->display_options['filters']['name_4']['value'] = 'Research advance';
  $handler->display->display_options['filters']['name_4']['group'] = 2;
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name_5']['id'] = 'name_5';
  $handler->display->display_options['filters']['name_5']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name_5']['field'] = 'name';
  $handler->display->display_options['filters']['name_5']['relationship'] = 'field_elife_a_category_target_id';
  $handler->display->display_options['filters']['name_5']['value'] = 'Registered report';
  $handler->display->display_options['filters']['name_5']['group'] = 2;
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name_6']['id'] = 'name_6';
  $handler->display->display_options['filters']['name_6']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name_6']['field'] = 'name';
  $handler->display->display_options['filters']['name_6']['relationship'] = 'field_elife_a_category_target_id';
  $handler->display->display_options['filters']['name_6']['value'] = 'Replication study';
  $handler->display->display_options['filters']['name_6']['group'] = 2;
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name_7']['id'] = 'name_7';
  $handler->display->display_options['filters']['name_7']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name_7']['field'] = 'name';
  $handler->display->display_options['filters']['name_7']['relationship'] = 'field_elife_a_category_target_id';
  $handler->display->display_options['filters']['name_7']['value'] = 'Short report';
  $handler->display->display_options['filters']['name_7']['group'] = 2;
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name_8']['id'] = 'name_8';
  $handler->display->display_options['filters']['name_8']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name_8']['field'] = 'name';
  $handler->display->display_options['filters']['name_8']['relationship'] = 'field_elife_a_category_target_id';
  $handler->display->display_options['filters']['name_8']['value'] = 'Tools and resources';
  $handler->display->display_options['filters']['name_8']['group'] = 2;
  /* Filter criterion: Content: Article versions (field_elife_a_versions:delta) */
  $handler->display->display_options['filters']['delta']['id'] = 'delta';
  $handler->display->display_options['filters']['delta']['table'] = 'field_data_field_elife_a_versions';
  $handler->display->display_options['filters']['delta']['field'] = 'delta';
  $handler->display->display_options['filters']['delta']['value']['value'] = '0';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $export['elife_archive_by_month'] = $view;

  return $export;
}
