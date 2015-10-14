<?php
/**
 * @file
 * elife_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function elife_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "elysia_cron" && $api == "default_elysia_cron_rules") {
    return array("version" => "1");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function elife_search_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function elife_search_default_search_api_index() {
  $items = array();
  $items['elife_articles_index'] = entity_import('search_api_index', '{
    "name" : "Articles index",
    "machine_name" : "elife_articles_index",
    "description" : null,
    "server" : "elife_solr",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "elife_article" ] },
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "field_elife_a_fpubdate" : { "type" : "date" },
        "field_elife_a_versions:field_elife_a_article_type" : { "type" : "list\\u003Cstring\\u003E" },
        "field_elife_a_versions:field_elife_a_category" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_elife_a_versions:field_elife_a_heading" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_elife_a_versions:field_elife_a_keyword:name" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" },
        "field_elife_a_versions:field_elife_a_main_text" : { "type" : "list\\u003Ctext\\u003E" },
        "field_elife_a_versions:title" : { "type" : "list\\u003Ctext\\u003E" },
        "search_api_language" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "teaser" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "field_elife_a_versions:title" : true,
              "field_elife_a_versions:field_elife_a_keyword:name" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "field_elife_a_versions:field_elife_a_main_text" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : {
              "field_elife_a_versions:title" : true,
              "field_elife_a_versions:field_elife_a_main_text" : true,
              "field_elife_a_versions:field_elife_a_keyword:name" : true
            }
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : { "fields" : [], "spaces" : "[^[:alnum:]]", "ignorable" : "[\\u0027]" }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : [],
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function elife_search_default_search_api_server() {
  $items = array();
  $items['elife_solr'] = entity_import('search_api_server', '{
    "name" : "Solr",
    "machine_name" : "elife_solr",
    "description" : "",
    "class" : "search_api_solr_service",
    "options" : {
      "clean_ids" : true,
      "site_hash" : true,
      "scheme" : "http",
      "host" : "localhost",
      "port" : "8983",
      "path" : "\\/solr\\/drupal",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0,
      "skip_schema_check" : 0,
      "solr_version" : "",
      "http_method" : "AUTO"
    },
    "enabled" : "1"
  }');
  return $items;
}
