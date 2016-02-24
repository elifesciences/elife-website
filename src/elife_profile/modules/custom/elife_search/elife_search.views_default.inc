<?php
/**
 * @file
 * elife_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function elife_search_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'elife_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_elife_articles_index';
  $view->human_name = 'eLife Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Search';
  $handler->display->display_options['css_class'] = 'search-form';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '4';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 25, 50, 75, 100';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Header: Global: Result summary with an additional token to change the items/page */
  $handler->display->display_options['header']['webform_result']['id'] = 'webform_result';
  $handler->display->display_options['header']['webform_result']['table'] = 'views';
  $handler->display->display_options['header']['webform_result']['field'] = 'webform_result';
  $handler->display->display_options['header']['webform_result']['content'] = '@items_per_page_links
<div class="elife-searchlist-pagerbar-count">Showing results @start&ndash;@end of @total</div>';
  /* Footer: Global: Result summary with an additional token to change the items/page */
  $handler->display->display_options['footer']['webform_result']['id'] = 'webform_result';
  $handler->display->display_options['footer']['webform_result']['table'] = 'views';
  $handler->display->display_options['footer']['webform_result']['field'] = 'webform_result';
  $handler->display->display_options['footer']['webform_result']['content'] = '@items_per_page_links
<div class="elife-searchlist-pagerbar-count">Showing results @start&ndash;@end of @total</div>';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<p>Your search yielded no results.</p>';
  /* Relationship: Indexed Content: Article versions */
  $handler->display->display_options['relationships']['field_elife_a_versions']['id'] = 'field_elife_a_versions';
  $handler->display->display_options['relationships']['field_elife_a_versions']['table'] = 'search_api_index_elife_articles_index';
  $handler->display->display_options['relationships']['field_elife_a_versions']['field'] = 'field_elife_a_versions';
  $handler->display->display_options['relationships']['field_elife_a_versions']['label'] = 'Article version';
  /* Field: Content: Rendered Content */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['relationship'] = 'field_elife_a_versions';
  $handler->display->display_options['fields']['rendered_entity']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity']['element_type'] = '0';
  $handler->display->display_options['fields']['rendered_entity']['element_label_type'] = '0';
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['rendered_entity']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'teaser';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_elife_articles_index';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  $handler->display->display_options['sorts']['search_api_relevance']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['search_api_relevance']['expose']['label'] = 'Relevance';
  /* Sort criterion: Indexed Content: First Publication Date */
  $handler->display->display_options['sorts']['field_elife_a_fpubdate']['id'] = 'field_elife_a_fpubdate';
  $handler->display->display_options['sorts']['field_elife_a_fpubdate']['table'] = 'search_api_index_elife_articles_index';
  $handler->display->display_options['sorts']['field_elife_a_fpubdate']['field'] = 'field_elife_a_fpubdate';
  $handler->display->display_options['sorts']['field_elife_a_fpubdate']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_elife_a_fpubdate']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_elife_a_fpubdate']['expose']['label'] = 'Date';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_elife_articles_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search for...';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'keyword';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Keyword search */
  $handler = $view->new_display('panel_pane', 'Keyword search', 'elife_search_keyword');
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Taxonomy */
  $handler = $view->new_display('panel_pane', 'Taxonomy', 'elife_search_taxonomy');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Category';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary with an additional token to change the items/page */
  $handler->display->display_options['header']['webform_result']['id'] = 'webform_result';
  $handler->display->display_options['header']['webform_result']['table'] = 'views';
  $handler->display->display_options['header']['webform_result']['field'] = 'webform_result';
  $handler->display->display_options['header']['webform_result']['content'] = '@items_per_page_links
<div class="elife-searchlist-pagerbar-count">Showing results @start&ndash;@end of @total</div>';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Indexed Content: First Publication Date */
  $handler->display->display_options['sorts']['field_elife_a_fpubdate']['id'] = 'field_elife_a_fpubdate';
  $handler->display->display_options['sorts']['field_elife_a_fpubdate']['table'] = 'search_api_index_elife_articles_index';
  $handler->display->display_options['sorts']['field_elife_a_fpubdate']['field'] = 'field_elife_a_fpubdate';
  $handler->display->display_options['sorts']['field_elife_a_fpubdate']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_elife_a_fpubdate']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_elife_a_fpubdate']['expose']['label'] = 'Date';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Search: Indexed taxonomy term fields */
  $handler->display->display_options['arguments']['search_api_views_taxonomy_term']['id'] = 'search_api_views_taxonomy_term';
  $handler->display->display_options['arguments']['search_api_views_taxonomy_term']['table'] = 'search_api_index_elife_articles_index';
  $handler->display->display_options['arguments']['search_api_views_taxonomy_term']['field'] = 'search_api_views_taxonomy_term';
  $handler->display->display_options['arguments']['search_api_views_taxonomy_term']['default_action'] = 'default';
  $handler->display->display_options['arguments']['search_api_views_taxonomy_term']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['search_api_views_taxonomy_term']['title'] = '%1';
  $handler->display->display_options['arguments']['search_api_views_taxonomy_term']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['search_api_views_taxonomy_term']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['search_api_views_taxonomy_term']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['search_api_views_taxonomy_term']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['search_api_views_taxonomy_term']['validate_options']['vocabularies'] = array(
    'elife_categories' => 'elife_categories',
    'elife_headings' => 'elife_headings',
  );
  $handler->display->display_options['arguments']['search_api_views_taxonomy_term']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['search_api_views_taxonomy_term']['not'] = 0;
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['elife_search'] = $view;

  return $export;
}
