<?php
/**
 * @file
 * elife_podcast.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function elife_podcast_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'elife_podcasts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'eLife Podcasts';
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
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<p>No podcasts are currently available.</p>';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Episode number (field_elife_p_episode_number) */
  $handler->display->display_options['sorts']['field_elife_p_episode_number_value']['id'] = 'field_elife_p_episode_number_value';
  $handler->display->display_options['sorts']['field_elife_p_episode_number_value']['table'] = 'field_data_field_elife_p_episode_number';
  $handler->display->display_options['sorts']['field_elife_p_episode_number_value']['field'] = 'field_elife_p_episode_number_value';
  $handler->display->display_options['sorts']['field_elife_p_episode_number_value']['order'] = 'DESC';
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
    'elife_podcast' => 'elife_podcast',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $export['elife_podcasts'] = $view;

  $view = new view();
  $view->name = 'elife_subject_podcasts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'eLife Subject Podcast';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Multimedia';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
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
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'elife_teaser_compact';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_elife_pc_subject_target_id']['id'] = 'field_elife_pc_subject_target_id';
  $handler->display->display_options['relationships']['field_elife_pc_subject_target_id']['table'] = 'field_data_field_elife_pc_subject';
  $handler->display->display_options['relationships']['field_elife_pc_subject_target_id']['field'] = 'field_elife_pc_subject_target_id';
  $handler->display->display_options['relationships']['field_elife_pc_subject_target_id']['label'] = 'Subject';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_elife_p_chapters_node']['id'] = 'reverse_field_elife_p_chapters_node';
  $handler->display->display_options['relationships']['reverse_field_elife_p_chapters_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_elife_p_chapters_node']['field'] = 'reverse_field_elife_p_chapters_node';
  $handler->display->display_options['relationships']['reverse_field_elife_p_chapters_node']['label'] = 'Podcast';
  $handler->display->display_options['relationships']['reverse_field_elife_p_chapters_node']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Episode number (field_elife_p_episode_number) */
  $handler->display->display_options['sorts']['field_elife_p_episode_number_value']['id'] = 'field_elife_p_episode_number_value';
  $handler->display->display_options['sorts']['field_elife_p_episode_number_value']['table'] = 'field_data_field_elife_p_episode_number';
  $handler->display->display_options['sorts']['field_elife_p_episode_number_value']['field'] = 'field_elife_p_episode_number_value';
  $handler->display->display_options['sorts']['field_elife_p_episode_number_value']['relationship'] = 'reverse_field_elife_p_chapters_node';
  $handler->display->display_options['sorts']['field_elife_p_episode_number_value']['order'] = 'DESC';
  /* Contextual filter: Content: Subjects (field_elife_pc_subject) */
  $handler->display->display_options['arguments']['field_elife_pc_subject_target_id']['id'] = 'field_elife_pc_subject_target_id';
  $handler->display->display_options['arguments']['field_elife_pc_subject_target_id']['table'] = 'field_data_field_elife_pc_subject';
  $handler->display->display_options['arguments']['field_elife_pc_subject_target_id']['field'] = 'field_elife_pc_subject_target_id';
  $handler->display->display_options['arguments']['field_elife_pc_subject_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_elife_pc_subject_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_elife_pc_subject_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_elife_pc_subject_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_elife_pc_subject_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_elife_pc_subject_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_elife_pc_subject_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_elife_pc_subject_target_id']['validate_options']['types'] = array(
    'elife_article_reference' => 'elife_article_reference',
    'elife_collection' => 'elife_collection',
  );
  $handler->display->display_options['arguments']['field_elife_pc_subject_target_id']['validate_options']['nid_type'] = 'nids';
  $handler->display->display_options['arguments']['field_elife_pc_subject_target_id']['break_phrase'] = TRUE;
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
    'elife_podcast_chapter' => 'elife_podcast_chapter',
  );
  /* Filter criterion: Content: Sidebar text (field_elife_pc_text_inverse) */
  $handler->display->display_options['filters']['field_elife_pc_text_inverse_value']['id'] = 'field_elife_pc_text_inverse_value';
  $handler->display->display_options['filters']['field_elife_pc_text_inverse_value']['table'] = 'field_data_field_elife_pc_text_inverse';
  $handler->display->display_options['filters']['field_elife_pc_text_inverse_value']['field'] = 'field_elife_pc_text_inverse_value';
  $handler->display->display_options['filters']['field_elife_pc_text_inverse_value']['operator'] = 'longerthan';
  $handler->display->display_options['filters']['field_elife_pc_text_inverse_value']['value'] = '0';

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
  $handler->display->display_options['argument_input'] = array(
    'field_elife_pc_subject_target_id' => array(
      'type' => 'user',
      'context' => 'entity:country.continent',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Article reference',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['elife_subject_podcasts'] = $view;

  return $export;
}
