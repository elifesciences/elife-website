<?php
/**
 * @file
 * elife_term_reference.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function elife_term_reference_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'elife_term_description';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'eLife Term Description';
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
  /* Field: Content: Body */
  $handler->display->display_options['fields']['field_elife_ta_body']['id'] = 'field_elife_ta_body';
  $handler->display->display_options['fields']['field_elife_ta_body']['table'] = 'field_data_field_elife_ta_body';
  $handler->display->display_options['fields']['field_elife_ta_body']['field'] = 'field_elife_ta_body';
  $handler->display->display_options['fields']['field_elife_ta_body']['label'] = '';
  $handler->display->display_options['fields']['field_elife_ta_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_elife_ta_body']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Term (field_elife_ta_term) */
  $handler->display->display_options['arguments']['field_elife_ta_term_value']['id'] = 'field_elife_ta_term_value';
  $handler->display->display_options['arguments']['field_elife_ta_term_value']['table'] = 'field_data_field_elife_ta_term';
  $handler->display->display_options['arguments']['field_elife_ta_term_value']['field'] = 'field_elife_ta_term_value';
  $handler->display->display_options['arguments']['field_elife_ta_term_value']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_elife_ta_term_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_elife_ta_term_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_elife_ta_term_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_elife_ta_term_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_elife_ta_term_value']['limit'] = '0';
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
    'elife_term_reference' => 'elife_term_reference',
  );

  /* Display: Term description */
  $handler = $view->new_display('panel_pane', 'Term description', 'elife_term_description');
  $handler->display->display_options['argument_input'] = array(
    'field_elife_ta_term_value' => array(
      'type' => 'user',
      'context' => 'entity:field_collection_item.archived',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Term (field_elife_ta_term)',
    ),
  );
  $export['elife_term_description'] = $view;

  return $export;
}
