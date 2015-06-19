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
  $view->name = 'elife_article_podcast';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'eLife Article Podcast';
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
  /* Contextual filter: Content: Articles (field_elife_p_articles) */
  $handler->display->display_options['arguments']['field_elife_p_articles_value']['id'] = 'field_elife_p_articles_value';
  $handler->display->display_options['arguments']['field_elife_p_articles_value']['table'] = 'field_data_field_elife_p_articles';
  $handler->display->display_options['arguments']['field_elife_p_articles_value']['field'] = 'field_elife_p_articles_value';
  $handler->display->display_options['arguments']['field_elife_p_articles_value']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_elife_p_articles_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_elife_p_articles_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_elife_p_articles_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_elife_p_articles_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_elife_p_articles_value']['limit'] = '0';
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

  /* Display: Article Podcast */
  $handler = $view->new_display('panel_pane', 'Article Podcast', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'field_elife_p_articles_value' => array(
      'type' => 'user',
      'context' => 'entity:field_collection_item.archived',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Articles (field_elife_p_articles)',
    ),
  );
  $export['elife_article_podcast'] = $view;

  return $export;
}
