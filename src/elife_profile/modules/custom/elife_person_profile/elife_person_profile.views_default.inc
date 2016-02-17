<?php
/**
 * @file
 * elife_person_profile.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function elife_person_profile_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'elife_person_profiles';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'eLife person profiles';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'clearfix';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = 'custom';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '7200';
  $handler->display->display_options['cache']['output_lifespan'] = 'custom';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '7200';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 1;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'node|sticky';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'teaser';
  $handler->display->display_options['row_options']['advanced_fieldset']['advanced'] = TRUE;
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_elife_pp_photo']['id'] = 'field_elife_pp_photo';
  $handler->display->display_options['fields']['field_elife_pp_photo']['table'] = 'field_data_field_elife_pp_photo';
  $handler->display->display_options['fields']['field_elife_pp_photo']['field'] = 'field_elife_pp_photo';
  $handler->display->display_options['fields']['field_elife_pp_photo']['label'] = '';
  $handler->display->display_options['fields']['field_elife_pp_photo']['element_type'] = '0';
  $handler->display->display_options['fields']['field_elife_pp_photo']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_elife_pp_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_elife_pp_photo']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_elife_pp_photo']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_elife_pp_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_elife_pp_photo']['settings'] = array(
    'image_style' => 'elife_person_profile',
    'image_link' => '',
  );
  /* Field: Content: First name */
  $handler->display->display_options['fields']['field_elife_pp_first_name']['id'] = 'field_elife_pp_first_name';
  $handler->display->display_options['fields']['field_elife_pp_first_name']['table'] = 'field_data_field_elife_pp_first_name';
  $handler->display->display_options['fields']['field_elife_pp_first_name']['field'] = 'field_elife_pp_first_name';
  $handler->display->display_options['fields']['field_elife_pp_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_elife_pp_first_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_elife_pp_first_name']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_elife_pp_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_elife_pp_first_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_elife_pp_first_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_elife_pp_first_name']['type'] = 'text_plain';
  /* Field: Content: Last name */
  $handler->display->display_options['fields']['field_elife_pp_last_name']['id'] = 'field_elife_pp_last_name';
  $handler->display->display_options['fields']['field_elife_pp_last_name']['table'] = 'field_data_field_elife_pp_last_name';
  $handler->display->display_options['fields']['field_elife_pp_last_name']['field'] = 'field_elife_pp_last_name';
  $handler->display->display_options['fields']['field_elife_pp_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_elife_pp_last_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_elife_pp_last_name']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_elife_pp_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_elife_pp_last_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_elife_pp_last_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_elife_pp_last_name']['type'] = 'text_plain';
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Type (field_elife_pp_type) */
  $handler->display->display_options['sorts']['field_elife_pp_type_value']['id'] = 'field_elife_pp_type_value';
  $handler->display->display_options['sorts']['field_elife_pp_type_value']['table'] = 'field_data_field_elife_pp_type';
  $handler->display->display_options['sorts']['field_elife_pp_type_value']['field'] = 'field_elife_pp_type_value';
  /* Sort criterion: Content: Last name (field_elife_pp_last_name) */
  $handler->display->display_options['sorts']['field_elife_pp_last_name_value']['id'] = 'field_elife_pp_last_name_value';
  $handler->display->display_options['sorts']['field_elife_pp_last_name_value']['table'] = 'field_data_field_elife_pp_last_name';
  $handler->display->display_options['sorts']['field_elife_pp_last_name_value']['field'] = 'field_elife_pp_last_name_value';
  /* Sort criterion: Content: First name (field_elife_pp_first_name) */
  $handler->display->display_options['sorts']['field_elife_pp_first_name_value']['id'] = 'field_elife_pp_first_name_value';
  $handler->display->display_options['sorts']['field_elife_pp_first_name_value']['table'] = 'field_data_field_elife_pp_first_name';
  $handler->display->display_options['sorts']['field_elife_pp_first_name_value']['field'] = 'field_elife_pp_first_name_value';
  /* Contextual filter: Content: Type (field_elife_pp_type) */
  $handler->display->display_options['arguments']['field_elife_pp_type_value']['id'] = 'field_elife_pp_type_value';
  $handler->display->display_options['arguments']['field_elife_pp_type_value']['table'] = 'field_data_field_elife_pp_type';
  $handler->display->display_options['arguments']['field_elife_pp_type_value']['field'] = 'field_elife_pp_type_value';
  $handler->display->display_options['arguments']['field_elife_pp_type_value']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_elife_pp_type_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_elife_pp_type_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_elife_pp_type_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_elife_pp_type_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_elife_pp_type_value']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_elife_pp_type_value']['limit'] = '0';
  $handler->display->display_options['arguments']['field_elife_pp_type_value']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Past (field_elife_pp_past) */
  $handler->display->display_options['arguments']['field_elife_pp_past_value']['id'] = 'field_elife_pp_past_value';
  $handler->display->display_options['arguments']['field_elife_pp_past_value']['table'] = 'field_data_field_elife_pp_past';
  $handler->display->display_options['arguments']['field_elife_pp_past_value']['field'] = 'field_elife_pp_past_value';
  $handler->display->display_options['arguments']['field_elife_pp_past_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_elife_pp_past_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_elife_pp_past_value']['default_argument_options']['argument'] = '0';
  $handler->display->display_options['arguments']['field_elife_pp_past_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_elife_pp_past_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_elife_pp_past_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_elife_pp_past_value']['specify_validation'] = TRUE;
  /* Contextual filter: Content: Expertise (field_elife_pp_expertise) */
  $handler->display->display_options['arguments']['field_elife_pp_expertise_target_id']['id'] = 'field_elife_pp_expertise_target_id';
  $handler->display->display_options['arguments']['field_elife_pp_expertise_target_id']['table'] = 'field_data_field_elife_pp_expertise';
  $handler->display->display_options['arguments']['field_elife_pp_expertise_target_id']['field'] = 'field_elife_pp_expertise_target_id';
  $handler->display->display_options['arguments']['field_elife_pp_expertise_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_elife_pp_expertise_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_elife_pp_expertise_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_elife_pp_expertise_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_elife_pp_expertise_target_id']['specify_validation'] = TRUE;
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
    'elife_person_profile' => 'elife_person_profile',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $export['elife_person_profiles'] = $view;

  return $export;
}
