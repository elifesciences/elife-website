<?php
/**
 * @file
 * elife_early_careers_interviews.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function elife_early_careers_interviews_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'elife_early_careers_interviews';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'eLife Interviews';
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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['type'] = 'ol';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<p>No interviews are currently available.</p>';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Series (field_elife_i_series) */
  $handler->display->display_options['arguments']['field_elife_i_series_target_id']['id'] = 'field_elife_i_series_target_id';
  $handler->display->display_options['arguments']['field_elife_i_series_target_id']['table'] = 'field_data_field_elife_i_series';
  $handler->display->display_options['arguments']['field_elife_i_series_target_id']['field'] = 'field_elife_i_series_target_id';
  $handler->display->display_options['arguments']['field_elife_i_series_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_elife_i_series_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_elife_i_series_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_elife_i_series_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_elife_i_series_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_elife_i_series_target_id']['validate']['fail'] = 'empty';
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
    'elife_early_careers_interview' => 'elife_early_careers_interview',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'field_elife_i_series_target_id' => array(
      'type' => 'user',
      'context' => 'entity:cer.cer_bidirectional',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Series (field_elife_i_series)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['elife_early_careers_interviews'] = $view;

  return $export;
}
