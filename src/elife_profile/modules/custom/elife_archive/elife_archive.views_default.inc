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
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['id'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['table'] = 'field_data_field_elife_a_versions';
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['field'] = 'field_elife_a_versions_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_elife_a_category_target_id']['id'] = 'field_elife_a_category_target_id';
  $handler->display->display_options['relationships']['field_elife_a_category_target_id']['table'] = 'field_data_field_elife_a_category';
  $handler->display->display_options['relationships']['field_elife_a_category_target_id']['field'] = 'field_elife_a_category_target_id';
  $handler->display->display_options['relationships']['field_elife_a_category_target_id']['relationship'] = 'field_elife_a_versions_target_id';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_elife_a_category_target_id';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  /* Field: Panel Pane - Node: eLife Article Listing */
  $handler->display->display_options['fields']['ctools_field_elife_article_listing']['id'] = 'ctools_field_elife_article_listing';
  $handler->display->display_options['fields']['ctools_field_elife_article_listing']['table'] = 'node';
  $handler->display->display_options['fields']['ctools_field_elife_article_listing']['field'] = 'ctools_field_elife_article_listing';
  $handler->display->display_options['fields']['ctools_field_elife_article_listing']['relationship'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['fields']['ctools_field_elife_article_listing']['label'] = '';
  $handler->display->display_options['fields']['ctools_field_elife_article_listing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ctools_field_elife_article_listing']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['ctools_field_elife_article_listing']['views_ctools_field'] = array(
    'display_options' => array(
      'title-as-link' => 'title-as-link',
      'impact' => 'impact',
      'doi' => 'doi',
      'display-channel' => 0,
      'heading' => 0,
      'authors' => 0,
    ),
    'image_style' => 'elife_striking_image',
    'css_styles' => array(
      'elife-article.css' => 0,
    ),
  );
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
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['use_fromto'] = 'no';
  /* Contextual filter: Content: Category (field_elife_a_category) */
  $handler->display->display_options['arguments']['field_elife_a_category_target_id']['id'] = 'field_elife_a_category_target_id';
  $handler->display->display_options['arguments']['field_elife_a_category_target_id']['table'] = 'field_data_field_elife_a_category';
  $handler->display->display_options['arguments']['field_elife_a_category_target_id']['field'] = 'field_elife_a_category_target_id';
  $handler->display->display_options['arguments']['field_elife_a_category_target_id']['relationship'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['arguments']['field_elife_a_category_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_elife_a_category_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_elife_a_category_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_elife_a_category_target_id']['summary_options']['items_per_page'] = '25';
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

  /* Display: Article archive (month) */
  $handler = $view->new_display('block', 'Article archive (month)', 'archive_month');

  /* Display: Article archive (year) */
  $handler = $view->new_display('block', 'Article archive (year)', 'archive_year');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['group']['element_type'] = '';
  $handler->display->display_options['style_options']['group']['class'] = '';
  $handler->display->display_options['style_options']['row']['element_type'] = '';
  $handler->display->display_options['style_options']['row']['first_class'] = '';
  $handler->display->display_options['style_options']['row']['last_class'] = '';
  $handler->display->display_options['style_options']['row']['striping_classes'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Node count */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['nid']['ui_name'] = 'Node count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['separator'] = '';
  /* Field: YYYY */
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['id'] = 'field_elife_a_fpubdate';
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['table'] = 'field_data_field_elife_a_fpubdate';
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['field'] = 'field_elife_a_fpubdate';
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['group_type'] = 'min';
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['ui_name'] = 'YYYY';
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['label'] = '';
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['settings'] = array(
    'format_type' => 'yyyy',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: MM */
  $handler->display->display_options['fields']['field_elife_a_fpubdate_1']['id'] = 'field_elife_a_fpubdate_1';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_1']['table'] = 'field_data_field_elife_a_fpubdate';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_1']['field'] = 'field_elife_a_fpubdate';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_1']['group_type'] = 'min';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_1']['ui_name'] = 'MM';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_1']['label'] = '';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_elife_a_fpubdate_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_elife_a_fpubdate_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_elife_a_fpubdate_1']['settings'] = array(
    'format_type' => 'mm',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Link to monthly archive */
  $handler->display->display_options['fields']['field_elife_a_fpubdate_2']['id'] = 'field_elife_a_fpubdate_2';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_2']['table'] = 'field_data_field_elife_a_fpubdate';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_2']['field'] = 'field_elife_a_fpubdate';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_2']['group_type'] = 'min';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_2']['ui_name'] = 'Link to monthly archive';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_2']['label'] = '';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_elife_a_fpubdate_2']['alter']['text'] = '[field_elife_a_fpubdate_2] ([nid])';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_elife_a_fpubdate_2']['alter']['path'] = 'archive/[field_elife_a_fpubdate]/[field_elife_a_fpubdate_1]';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_2']['alter']['alt'] = '[field_elife_a_fpubdate_2]';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_elife_a_fpubdate_2']['settings'] = array(
    'format_type' => 'f_y',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: YYYYMM */
  $handler->display->display_options['fields']['field_elife_a_fpubdate_3']['id'] = 'field_elife_a_fpubdate_3';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_3']['table'] = 'field_data_field_elife_a_fpubdate';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_3']['field'] = 'field_elife_a_fpubdate';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_3']['ui_name'] = 'YYYYMM';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_3']['label'] = '';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_3']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_elife_a_fpubdate_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_elife_a_fpubdate_3']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_elife_a_fpubdate_3']['settings'] = array(
    'format_type' => 'yyyymm',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_elife_a_fpubdate_3']['format_date_sql'] = 1;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: First Publication Date (field_elife_a_fpubdate) */
  $handler->display->display_options['sorts']['field_elife_a_fpubdate_value']['id'] = 'field_elife_a_fpubdate_value';
  $handler->display->display_options['sorts']['field_elife_a_fpubdate_value']['table'] = 'field_data_field_elife_a_fpubdate';
  $handler->display->display_options['sorts']['field_elife_a_fpubdate_value']['field'] = 'field_elife_a_fpubdate_value';
  $handler->display->display_options['sorts']['field_elife_a_fpubdate_value']['group_type'] = 'min';
  $handler->display->display_options['sorts']['field_elife_a_fpubdate_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: First Publication Date (field_elife_a_fpubdate) */
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['id'] = 'field_elife_a_fpubdate_value';
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['table'] = 'field_data_field_elife_a_fpubdate';
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['field'] = 'field_elife_a_fpubdate_value';
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['granularity'] = 'year';

  /* Display: Article archive (short) */
  $handler = $view->new_display('block', 'Article archive (short)', 'archive_short');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['group']['element_type'] = '';
  $handler->display->display_options['style_options']['group']['class'] = '';
  $handler->display->display_options['style_options']['row']['element_type'] = '';
  $handler->display->display_options['style_options']['row']['first_class'] = '';
  $handler->display->display_options['style_options']['row']['last_class'] = '';
  $handler->display->display_options['style_options']['row']['striping_classes'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Node count */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['nid']['ui_name'] = 'Node count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['separator'] = '';
  /* Field: YYYY */
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['id'] = 'field_elife_a_fpubdate';
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['table'] = 'field_data_field_elife_a_fpubdate';
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['field'] = 'field_elife_a_fpubdate';
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['group_type'] = 'min';
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['ui_name'] = 'YYYY';
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['label'] = '';
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['settings'] = array(
    'format_type' => 'yyyy',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: MM */
  $handler->display->display_options['fields']['field_elife_a_fpubdate_1']['id'] = 'field_elife_a_fpubdate_1';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_1']['table'] = 'field_data_field_elife_a_fpubdate';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_1']['field'] = 'field_elife_a_fpubdate';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_1']['group_type'] = 'min';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_1']['ui_name'] = 'MM';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_1']['label'] = '';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_elife_a_fpubdate_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_elife_a_fpubdate_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_elife_a_fpubdate_1']['settings'] = array(
    'format_type' => 'mm',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Link to monthly archive */
  $handler->display->display_options['fields']['field_elife_a_fpubdate_2']['id'] = 'field_elife_a_fpubdate_2';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_2']['table'] = 'field_data_field_elife_a_fpubdate';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_2']['field'] = 'field_elife_a_fpubdate';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_2']['group_type'] = 'min';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_2']['ui_name'] = 'Link to monthly archive';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_2']['label'] = '';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_elife_a_fpubdate_2']['alter']['path'] = 'archive/[field_elife_a_fpubdate]/[field_elife_a_fpubdate_1]';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_2']['alter']['alt'] = '[field_elife_a_fpubdate_2]';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_elife_a_fpubdate_2']['settings'] = array(
    'format_type' => 'm',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_elife_a_fpubdate_2']['format_date_sql'] = 0;
  /* Field: YYYYMM */
  $handler->display->display_options['fields']['field_elife_a_fpubdate_3']['id'] = 'field_elife_a_fpubdate_3';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_3']['table'] = 'field_data_field_elife_a_fpubdate';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_3']['field'] = 'field_elife_a_fpubdate';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_3']['ui_name'] = 'YYYYMM';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_3']['label'] = '';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_3']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_elife_a_fpubdate_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_elife_a_fpubdate_3']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_elife_a_fpubdate_3']['settings'] = array(
    'format_type' => 'yyyymm',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_elife_a_fpubdate_3']['format_date_sql'] = 1;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: First Publication Date (field_elife_a_fpubdate) */
  $handler->display->display_options['sorts']['field_elife_a_fpubdate_value']['id'] = 'field_elife_a_fpubdate_value';
  $handler->display->display_options['sorts']['field_elife_a_fpubdate_value']['table'] = 'field_data_field_elife_a_fpubdate';
  $handler->display->display_options['sorts']['field_elife_a_fpubdate_value']['field'] = 'field_elife_a_fpubdate_value';
  $handler->display->display_options['sorts']['field_elife_a_fpubdate_value']['group_type'] = 'min';
  $handler->display->display_options['sorts']['field_elife_a_fpubdate_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: First Publication Date (field_elife_a_fpubdate) */
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['id'] = 'field_elife_a_fpubdate_value';
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['table'] = 'field_data_field_elife_a_fpubdate';
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['field'] = 'field_elife_a_fpubdate_value';
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_elife_a_fpubdate_value']['granularity'] = 'year';
  $export['elife_archive_by_month'] = $view;

  return $export;
}
