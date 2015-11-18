<?php
/**
 * @file
 * elife_article.default_elysia_cron_rules.inc
 */

/**
 * Implements hook_default_elysia_cron_rules().
 */
function elife_article_default_elysia_cron_rules() {
  $cron_rules = array();

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'elife_article_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '*/30 * * * *';
  $cron_rule->weight = 1;
  $cron_rule->context = NULL;
  $cron_rules['elife_article_cron'] = $cron_rule;

  return $cron_rules;

}
