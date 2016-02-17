<?php
/**
 * @file
 * elife_front_matter.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function elife_front_matter_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'elife_cover';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'eLife: Cover';
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
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['element_type'] = '';
  $handler->display->display_options['style_options']['row']['first_class'] = '';
  $handler->display->display_options['style_options']['row']['last_class'] = '';
  $handler->display->display_options['style_options']['row']['striping_classes'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entityqueue: Node Queue */
  $handler->display->display_options['relationships']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['table'] = 'node';
  $handler->display->display_options['relationships']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['required'] = TRUE;
  $handler->display->display_options['relationships']['entityqueue_relationship']['limit'] = 1;
  $handler->display->display_options['relationships']['entityqueue_relationship']['queues'] = array(
    'elife_cover' => 'elife_cover',
    'elife_cover_preview' => 0,
    'elife_front_matter_col_1' => 0,
    'elife_front_matter_col_2' => 0,
    'elife_front_matter_preview_col_1' => 0,
    'elife_front_matter_preview_col_2' => 0,
  );
  /* Field: Panel Pane - Node: eLife Cover article */
  $handler->display->display_options['fields']['ctools_field_elife_cover']['id'] = 'ctools_field_elife_cover';
  $handler->display->display_options['fields']['ctools_field_elife_cover']['table'] = 'node';
  $handler->display->display_options['fields']['ctools_field_elife_cover']['field'] = 'ctools_field_elife_cover';
  $handler->display->display_options['fields']['ctools_field_elife_cover']['label'] = '';
  $handler->display->display_options['fields']['ctools_field_elife_cover']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ctools_field_elife_cover']['element_default_classes'] = FALSE;
  /* Sort criterion: Entityqueue: Node Queue Position */
  $handler->display->display_options['sorts']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
  $handler->display->display_options['sorts']['entityqueue_relationship']['table'] = 'node';
  $handler->display->display_options['sorts']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
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
    'elife_cover' => 'elife_cover',
  );

  /* Display: Cover article */
  $handler = $view->new_display('block', 'Cover article', 'cover_article');
  $export['elife_cover'] = $view;

  $view = new view();
  $view->name = 'elife_front_matter';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'eLife Front Matter';
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
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '1';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['element_type'] = '';
  $handler->display->display_options['style_options']['row']['first_class'] = '';
  $handler->display->display_options['style_options']['row']['last_class'] = '';
  $handler->display->display_options['style_options']['row']['striping_classes'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entityqueue: Node Queue */
  $handler->display->display_options['relationships']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['table'] = 'node';
  $handler->display->display_options['relationships']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['required'] = TRUE;
  $handler->display->display_options['relationships']['entityqueue_relationship']['limit'] = 1;
  $handler->display->display_options['relationships']['entityqueue_relationship']['queues'] = array(
    'elife_front_matter_col_1' => 'elife_front_matter_col_1',
    'elife_cover' => 0,
    'elife_cover_preview' => 0,
    'elife_front_matter_col_2' => 0,
    'elife_front_matter_preview_col_1' => 0,
    'elife_front_matter_preview_col_2' => 0,
  );
  /* Field: Panel Pane - Node: eLife Front Matter */
  $handler->display->display_options['fields']['ctools_field_elife_front_matter']['id'] = 'ctools_field_elife_front_matter';
  $handler->display->display_options['fields']['ctools_field_elife_front_matter']['table'] = 'node';
  $handler->display->display_options['fields']['ctools_field_elife_front_matter']['field'] = 'ctools_field_elife_front_matter';
  $handler->display->display_options['fields']['ctools_field_elife_front_matter']['label'] = '';
  $handler->display->display_options['fields']['ctools_field_elife_front_matter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ctools_field_elife_front_matter']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['ctools_field_elife_front_matter']['views_ctools_field'] = array(
    'front_matter_type' => 'regular',
  );
  /* Sort criterion: Entityqueue: Node Queue Position */
  $handler->display->display_options['sorts']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
  $handler->display->display_options['sorts']['entityqueue_relationship']['table'] = 'node';
  $handler->display->display_options['sorts']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
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
    'elife_front_matter' => 'elife_front_matter',
  );

  /* Display: Front matter (Col 1) */
  $handler = $view->new_display('block', 'Front matter (Col 1)', 'front_matter_col_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'headlines-secondary';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: View area */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['label'] = 'Column header';
  $handler->display->display_options['header']['view']['view_to_insert'] = 'elife_front_matter:front_matter_col_1_head';

  /* Display: Front Matter - Headline (Col 1) */
  $handler = $view->new_display('block', 'Front Matter - Headline (Col 1)', 'front_matter_col_1_head');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Panel Pane - Node: eLife Front Matter */
  $handler->display->display_options['fields']['ctools_field_elife_front_matter']['id'] = 'ctools_field_elife_front_matter';
  $handler->display->display_options['fields']['ctools_field_elife_front_matter']['table'] = 'node';
  $handler->display->display_options['fields']['ctools_field_elife_front_matter']['field'] = 'ctools_field_elife_front_matter';
  $handler->display->display_options['fields']['ctools_field_elife_front_matter']['label'] = '';
  $handler->display->display_options['fields']['ctools_field_elife_front_matter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ctools_field_elife_front_matter']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['ctools_field_elife_front_matter']['views_ctools_field'] = array(
    'front_matter_type' => 'headline',
  );

  /* Display: Front matter (Col 2) */
  $handler = $view->new_display('block', 'Front matter (Col 2)', 'front_matter_col_2');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'headlines-secondary';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: View area */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['label'] = 'Column header';
  $handler->display->display_options['header']['view']['view_to_insert'] = 'elife_front_matter:front_matter_col_2_head';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entityqueue: Node Queue */
  $handler->display->display_options['relationships']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['table'] = 'node';
  $handler->display->display_options['relationships']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['required'] = TRUE;
  $handler->display->display_options['relationships']['entityqueue_relationship']['limit'] = 1;
  $handler->display->display_options['relationships']['entityqueue_relationship']['queues'] = array(
    'elife_front_matter_col_2' => 'elife_front_matter_col_2',
    'elife_cover' => 0,
    'elife_cover_preview' => 0,
    'elife_front_matter_col_1' => 0,
    'elife_front_matter_preview_col_1' => 0,
    'elife_front_matter_preview_col_2' => 0,
  );

  /* Display: Front Matter - Headline (Col 2) */
  $handler = $view->new_display('block', 'Front Matter - Headline (Col 2)', 'front_matter_col_2_head');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entityqueue: Node Queue */
  $handler->display->display_options['relationships']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['table'] = 'node';
  $handler->display->display_options['relationships']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['required'] = TRUE;
  $handler->display->display_options['relationships']['entityqueue_relationship']['limit'] = 1;
  $handler->display->display_options['relationships']['entityqueue_relationship']['queues'] = array(
    'elife_front_matter_col_2' => 'elife_front_matter_col_2',
    'elife_cover' => 0,
    'elife_cover_preview' => 0,
    'elife_front_matter_col_1' => 0,
    'elife_front_matter_preview_col_1' => 0,
    'elife_front_matter_preview_col_2' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Panel Pane - Node: eLife Front Matter */
  $handler->display->display_options['fields']['ctools_field_elife_front_matter']['id'] = 'ctools_field_elife_front_matter';
  $handler->display->display_options['fields']['ctools_field_elife_front_matter']['table'] = 'node';
  $handler->display->display_options['fields']['ctools_field_elife_front_matter']['field'] = 'ctools_field_elife_front_matter';
  $handler->display->display_options['fields']['ctools_field_elife_front_matter']['label'] = '';
  $handler->display->display_options['fields']['ctools_field_elife_front_matter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ctools_field_elife_front_matter']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['ctools_field_elife_front_matter']['views_ctools_field'] = array(
    'front_matter_type' => 'headline',
  );
  $export['elife_front_matter'] = $view;

  $view = new view();
  $view->name = 'elife_latest_research';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'eLife Latest Research';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'home-article-listing';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'home-article-listing__list-item';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['relationship'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<p>No articles currently available.</p>';
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
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
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
  /* Filter criterion: Content: Article versions (field_elife_a_versions:delta) */
  $handler->display->display_options['filters']['delta']['id'] = 'delta';
  $handler->display->display_options['filters']['delta']['table'] = 'field_data_field_elife_a_versions';
  $handler->display->display_options['filters']['delta']['field'] = 'delta';
  $handler->display->display_options['filters']['delta']['value']['value'] = '0';
  $handler->display->display_options['filters']['delta']['group'] = 1;
  /* Filter criterion: Content: Status (field_elife_a_status) */
  $handler->display->display_options['filters']['field_elife_a_status_value']['id'] = 'field_elife_a_status_value';
  $handler->display->display_options['filters']['field_elife_a_status_value']['table'] = 'field_data_field_elife_a_status';
  $handler->display->display_options['filters']['field_elife_a_status_value']['field'] = 'field_elife_a_status_value';
  $handler->display->display_options['filters']['field_elife_a_status_value']['relationship'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['filters']['field_elife_a_status_value']['value'] = array(
    'VOR' => 'VOR',
  );
  $handler->display->display_options['filters']['field_elife_a_status_value']['group'] = 1;
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name_3']['id'] = 'name_3';
  $handler->display->display_options['filters']['name_3']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name_3']['field'] = 'name';
  $handler->display->display_options['filters']['name_3']['relationship'] = 'field_elife_a_category_target_id';
  $handler->display->display_options['filters']['name_3']['value'] = 'Replication study';
  $handler->display->display_options['filters']['name_3']['group'] = 2;
  /* Filter criterion: Taxonomy term: Type (field_elife_category_type) */
  $handler->display->display_options['filters']['field_elife_category_type_value']['id'] = 'field_elife_category_type_value';
  $handler->display->display_options['filters']['field_elife_category_type_value']['table'] = 'field_data_field_elife_category_type';
  $handler->display->display_options['filters']['field_elife_category_type_value']['field'] = 'field_elife_category_type_value';
  $handler->display->display_options['filters']['field_elife_category_type_value']['relationship'] = 'field_elife_a_category_target_id';
  $handler->display->display_options['filters']['field_elife_category_type_value']['value'] = 'display-channel';
  $handler->display->display_options['filters']['field_elife_category_type_value']['group'] = 1;
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name_2']['id'] = 'name_2';
  $handler->display->display_options['filters']['name_2']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name_2']['field'] = 'name';
  $handler->display->display_options['filters']['name_2']['relationship'] = 'field_elife_a_category_target_id';
  $handler->display->display_options['filters']['name_2']['value'] = 'Research advance';
  $handler->display->display_options['filters']['name_2']['group'] = 2;
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name_1']['id'] = 'name_1';
  $handler->display->display_options['filters']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name_1']['field'] = 'name';
  $handler->display->display_options['filters']['name_1']['relationship'] = 'field_elife_a_category_target_id';
  $handler->display->display_options['filters']['name_1']['value'] = 'Research article';
  $handler->display->display_options['filters']['name_1']['group'] = 2;
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name_4']['id'] = 'name_4';
  $handler->display->display_options['filters']['name_4']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name_4']['field'] = 'name';
  $handler->display->display_options['filters']['name_4']['relationship'] = 'field_elife_a_category_target_id';
  $handler->display->display_options['filters']['name_4']['value'] = 'Short report';
  $handler->display->display_options['filters']['name_4']['group'] = 2;
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name_5']['id'] = 'name_5';
  $handler->display->display_options['filters']['name_5']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name_5']['field'] = 'name';
  $handler->display->display_options['filters']['name_5']['relationship'] = 'field_elife_a_category_target_id';
  $handler->display->display_options['filters']['name_5']['value'] = 'Tools and resources';
  $handler->display->display_options['filters']['name_5']['group'] = 2;

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['elife_latest_research'] = $view;

  return $export;
}
