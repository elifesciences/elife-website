<?php
/**
 * @file
 * elife_upcoming_articles.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function elife_upcoming_articles_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'elife_upcoming_articles';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'eLife Upcoming Articles';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Upcoming';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_elife_a_fpubdate',
      'rendered' => 1,
      'rendered_strip' => 1,
    ),
  );
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<p>There are currently no upcoming articles.</p>';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['id'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['table'] = 'field_data_field_elife_a_versions';
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['field'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['label'] = 'Article version';
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['required'] = TRUE;
  /* Field: Content: First Publication Date */
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['id'] = 'field_elife_a_fpubdate';
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['table'] = 'field_data_field_elife_a_fpubdate';
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['field'] = 'field_elife_a_fpubdate';
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['label'] = '';
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['element_type'] = 'h3';
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['settings'] = array(
    'format_type' => 'elife_date_only',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['format_date_sql'] = 0;
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
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'teaser';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  /* Sort criterion: Content: First Publication Date (field_elife_a_fpubdate) */
  $handler->display->display_options['sorts']['field_elife_a_fpubdate_value']['id'] = 'field_elife_a_fpubdate_value';
  $handler->display->display_options['sorts']['field_elife_a_fpubdate_value']['table'] = 'field_data_field_elife_a_fpubdate';
  $handler->display->display_options['sorts']['field_elife_a_fpubdate_value']['field'] = 'field_elife_a_fpubdate_value';
  $handler->display->display_options['sorts']['field_elife_a_fpubdate_value']['order'] = 'DESC';
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 1;
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
  /* Filter criterion: Content: Status (field_elife_a_status) */
  $handler->display->display_options['filters']['field_elife_a_status_value']['id'] = 'field_elife_a_status_value';
  $handler->display->display_options['filters']['field_elife_a_status_value']['table'] = 'field_data_field_elife_a_status';
  $handler->display->display_options['filters']['field_elife_a_status_value']['field'] = 'field_elife_a_status_value';
  $handler->display->display_options['filters']['field_elife_a_status_value']['relationship'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['filters']['field_elife_a_status_value']['value'] = array(
    'POA' => 'POA',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $export['elife_upcoming_articles'] = $view;

  return $export;
}
