<?php
/**
 * @file
 * elife_article_rss.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function elife_article_rss_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'elife_articles_rss';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'eLife Articles RSS';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'eLife';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '1800';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '1800';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['id'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['table'] = 'field_data_field_elife_a_versions';
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['field'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['label'] = 'Article version';
  $handler->display->display_options['relationships']['field_elife_a_versions_target_id']['required'] = TRUE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Field: Title */
  $handler->display->display_options['fields']['field_elife_title']['id'] = 'field_elife_title';
  $handler->display->display_options['fields']['field_elife_title']['table'] = 'field_data_field_elife_title';
  $handler->display->display_options['fields']['field_elife_title']['field'] = 'field_elife_title';
  $handler->display->display_options['fields']['field_elife_title']['relationship'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['fields']['field_elife_title']['label'] = '';
  $handler->display->display_options['fields']['field_elife_title']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_elife_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_elife_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_elife_title']['group_column'] = 'entity_id';
  /* Field: First Publication Date (RFC 822) */
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['id'] = 'field_elife_a_fpubdate';
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['table'] = 'field_data_field_elife_a_fpubdate';
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['field'] = 'field_elife_a_fpubdate';
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['ui_name'] = 'First Publication Date (RFC 822)';
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['label'] = '';
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['settings'] = array(
    'format_type' => 'elife_rfc822',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['fields']['field_elife_a_fpubdate']['format_date_sql'] = 0;
  /* Field: First Publication Date (ISO 8601) */
  $handler->display->display_options['fields']['field_elife_a_fpubdate_1']['id'] = 'field_elife_a_fpubdate_1';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_1']['table'] = 'field_data_field_elife_a_fpubdate';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_1']['field'] = 'field_elife_a_fpubdate';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_1']['ui_name'] = 'First Publication Date (ISO 8601)';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_1']['label'] = '';
  $handler->display->display_options['fields']['field_elife_a_fpubdate_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_elife_a_fpubdate_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_elife_a_fpubdate_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_elife_a_fpubdate_1']['settings'] = array(
    'format_type' => 'elife_iso8601',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['fields']['field_elife_a_fpubdate_1']['format_date_sql'] = 0;
  /* Field: Field: DOI */
  $handler->display->display_options['fields']['field_elife_a_doi']['id'] = 'field_elife_a_doi';
  $handler->display->display_options['fields']['field_elife_a_doi']['table'] = 'field_data_field_elife_a_doi';
  $handler->display->display_options['fields']['field_elife_a_doi']['field'] = 'field_elife_a_doi';
  $handler->display->display_options['fields']['field_elife_a_doi']['relationship'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['fields']['field_elife_a_doi']['label'] = '';
  $handler->display->display_options['fields']['field_elife_a_doi']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_elife_a_doi']['alter']['text'] = 'http://dx.doi.org/[field_elife_a_doi-value]';
  $handler->display->display_options['fields']['field_elife_a_doi']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_elife_a_doi']['group_column'] = 'entity_id';
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['relationship'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['type'] = 'rss_category';
  $handler->display->display_options['fields']['term_node_tid']['limit'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'elife_headings' => 'elife_headings',
    'elife_keywords' => 'elife_keywords',
    'elife_categories' => 0,
    'elife_n_category' => 0,
    'elife_pp_experimental_organism' => 0,
    'elife_pp_expertise' => 0,
    'elife_pp_research_focus' => 0,
  );
  /* Field: Content: Abstract */
  $handler->display->display_options['fields']['field_elife_a_abstract']['id'] = 'field_elife_a_abstract';
  $handler->display->display_options['fields']['field_elife_a_abstract']['table'] = 'field_data_field_elife_a_abstract';
  $handler->display->display_options['fields']['field_elife_a_abstract']['field'] = 'field_elife_a_abstract';
  $handler->display->display_options['fields']['field_elife_a_abstract']['relationship'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['fields']['field_elife_a_abstract']['label'] = '';
  $handler->display->display_options['fields']['field_elife_a_abstract']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_elife_a_abstract']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_elife_a_abstract']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_elife_a_abstract']['group_column'] = 'entity_id';
  /* Field: Content: Contact emails */
  $handler->display->display_options['fields']['field_elife_a_emails']['id'] = 'field_elife_a_emails';
  $handler->display->display_options['fields']['field_elife_a_emails']['table'] = 'field_data_field_elife_a_emails';
  $handler->display->display_options['fields']['field_elife_a_emails']['field'] = 'field_elife_a_emails';
  $handler->display->display_options['fields']['field_elife_a_emails']['relationship'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['fields']['field_elife_a_emails']['label'] = '';
  $handler->display->display_options['fields']['field_elife_a_emails']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_elife_a_emails']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_elife_a_emails']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_elife_a_emails']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_elife_a_emails']['delta_offset'] = '0';
  /* Sort criterion: Content: First Publication Date (field_elife_a_fpubdate) */
  $handler->display->display_options['sorts']['field_elife_a_fpubdate_value']['id'] = 'field_elife_a_fpubdate_value';
  $handler->display->display_options['sorts']['field_elife_a_fpubdate_value']['table'] = 'field_data_field_elife_a_fpubdate';
  $handler->display->display_options['sorts']['field_elife_a_fpubdate_value']['field'] = 'field_elife_a_fpubdate_value';
  $handler->display->display_options['sorts']['field_elife_a_fpubdate_value']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
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
    'VOR' => 'VOR',
  );

  /* Display: Recent */
  $handler = $view->new_display('feed', 'Recent', 'recent');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss_fields';
  $handler->display->display_options['style_options']['channel'] = array(
    'core' => array(
      'views_rss_core' => array(
        'description' => 'Articles published in eLife',
        'language' => '',
        'category' => '',
        'image' => '',
        'copyright' => '',
        'managingEditor' => '',
        'webMaster' => '',
        'generator' => '',
        'docs' => '',
        'cloud' => '',
        'ttl' => '',
        'skipHours' => '',
        'skipDays' => '',
      ),
    ),
  );
  $handler->display->display_options['style_options']['item'] = array(
    'core' => array(
      'views_rss_core' => array(
        'title' => 'field_elife_title',
        'link' => 'path',
        'description' => 'field_elife_a_abstract',
        'author' => 'field_elife_a_emails',
        'category' => 'term_node_tid',
        'comments' => '',
        'enclosure' => '',
        'guid' => 'field_elife_a_doi',
        'pubDate' => 'field_elife_a_fpubdate',
      ),
    ),
    'dc' => array(
      'views_rss_dc' => array(
        'title' => '',
        'creator' => '',
        'subject' => '',
        'description' => '',
        'publisher' => '',
        'contributor' => '',
        'date' => 'field_elife_a_fpubdate_1',
        'type' => '',
        'format' => '',
        'identifier' => '',
        'source' => '',
        'language' => '',
        'relation' => '',
        'coverage' => '',
        'rights' => '',
      ),
    ),
  );
  $handler->display->display_options['style_options']['feed_settings'] = array(
    'absolute_paths' => 1,
    'feed_in_links' => 0,
  );
  $handler->display->display_options['path'] = 'rss/recent.xml';
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: Ahead */
  $handler = $view->new_display('feed', 'Ahead', 'ahead');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss_fields';
  $handler->display->display_options['style_options']['channel'] = array(
    'core' => array(
      'views_rss_core' => array(
        'description' => 'eLife PAP articles',
        'language' => '',
        'category' => '',
        'image' => '',
        'copyright' => '',
        'managingEditor' => '',
        'webMaster' => '',
        'generator' => '',
        'docs' => '',
        'cloud' => '',
        'ttl' => '',
        'skipHours' => '',
        'skipDays' => '',
      ),
    ),
  );
  $handler->display->display_options['style_options']['item'] = array(
    'core' => array(
      'views_rss_core' => array(
        'title' => 'field_elife_title',
        'link' => 'path',
        'description' => 'field_elife_a_abstract',
        'author' => 'field_elife_a_emails',
        'category' => 'term_node_tid',
        'comments' => '',
        'enclosure' => '',
        'guid' => 'field_elife_a_doi',
        'pubDate' => 'field_elife_a_fpubdate',
      ),
    ),
    'dc' => array(
      'views_rss_dc' => array(
        'title' => '',
        'creator' => '',
        'subject' => '',
        'description' => '',
        'publisher' => '',
        'contributor' => '',
        'date' => 'field_elife_a_fpubdate_1',
        'type' => '',
        'format' => '',
        'identifier' => '',
        'source' => '',
        'language' => '',
        'relation' => '',
        'coverage' => '',
        'rights' => '',
      ),
    ),
  );
  $handler->display->display_options['style_options']['feed_settings'] = array(
    'absolute_paths' => 1,
    'feed_in_links' => 0,
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'field_elife_a_versions_target_id';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
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
  $handler->display->display_options['path'] = 'rss/ahead.xml';
  $export['elife_articles_rss'] = $view;

  return $export;
}
