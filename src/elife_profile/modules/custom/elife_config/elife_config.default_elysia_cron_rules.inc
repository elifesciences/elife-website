<?php
/**
 * @file
 * elife_config.default_elysia_cron_rules.inc
 */

/**
 * Implements hook_default_elysia_cron_rules().
 */
function elife_config_default_elysia_cron_rules() {
  $cron_rules = array();

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = ':default';
  $cron_rule->disable = FALSE;
  $cron_rule->rule = NULL;
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules[':default'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'ctools_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '0 */6 * * *';
  $cron_rule->weight = 0;
  $cron_rule->context = NULL;
  $cron_rules['ctools_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'elife_xmlsitemap_custom_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '4 0 * * *';
  $cron_rule->weight = -1;
  $cron_rule->context = NULL;
  $cron_rules['elife_xmlsitemap_custom_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'field_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '4 0 * * *';
  $cron_rule->weight = 0;
  $cron_rule->context = NULL;
  $cron_rules['field_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'googleanalytics_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '4 0 * * *';
  $cron_rule->weight = 0;
  $cron_rule->context = NULL;
  $cron_rules['googleanalytics_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'node_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '4 0 * * *';
  $cron_rule->weight = 0;
  $cron_rule->context = NULL;
  $cron_rules['node_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'redirect_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '4 0 * * *';
  $cron_rule->weight = 0;
  $cron_rule->context = NULL;
  $cron_rules['redirect_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'rules_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '*/15 * * * *';
  $cron_rule->weight = -1;
  $cron_rule->context = NULL;
  $cron_rules['rules_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'scheduler_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '*/15 * * * *';
  $cron_rule->weight = 0;
  $cron_rule->context = NULL;
  $cron_rules['scheduler_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'system_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '0 */6 * * *';
  $cron_rule->weight = 0;
  $cron_rule->context = NULL;
  $cron_rules['system_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'update_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '4 0 * * *';
  $cron_rule->weight = 1;
  $cron_rule->context = NULL;
  $cron_rules['update_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'views_bulk_operations_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '4 0 * * *';
  $cron_rule->weight = 0;
  $cron_rule->context = NULL;
  $cron_rules['views_bulk_operations_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'xmlsitemap_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '0 */6 * * *';
  $cron_rule->weight = 1;
  $cron_rule->context = NULL;
  $cron_rules['xmlsitemap_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'xmlsitemap_node_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '0 */6 * * *';
  $cron_rule->weight = 0;
  $cron_rule->context = NULL;
  $cron_rules['xmlsitemap_node_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'xmlsitemap_taxonomy_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '0 */6 * * *';
  $cron_rule->weight = 0;
  $cron_rule->context = NULL;
  $cron_rules['xmlsitemap_taxonomy_cron'] = $cron_rule;

  return $cron_rules;

}
