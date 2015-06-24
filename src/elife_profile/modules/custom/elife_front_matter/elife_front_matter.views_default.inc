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

  return $export;
}
