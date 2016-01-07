<?php

/**
 * Implements hook_tokens_alter()
 *
 * Adds [node:body] and [node:summary] tokens for content types that have
 * replaced the body field with a different field, so that they can still be
 * used in a standard way.
 */
function elife_body_field_tokens_alter(array &$replacements, array $context) {
  if ('node' !== $context['type'] || empty($context['data']['node'])) {
    return;
  }

  $body_fields = module_invoke_all('elife_body_field');
  drupal_alter('elife_body_field', $body_fields);

  $node = $context['data']['node'];

  if (empty($body_fields[$node->type])) {
    return;
  }

  $body_field_items = field_get_items('node', $node, $body_fields[$node->type]);

  if (FALSE === $body_field_items) {
    return;
  }

  $sanitize = !empty($context['options']['sanitize']);
  $summary_length = 200;

  $text = !empty($body_field_items[0]['value']) ? strip_tags(check_markup($body_field_items[0]['value'], $body_field_items[0]['format'])) : '';
  $summary = !empty($body_field_items[0]['summary']) ? $body_field_items[0]['summary'] : truncate_utf8($text, $summary_length, TRUE, TRUE);

  $replacements['[node:body]'] = $sanitize ? filter_xss($text) : $text;
  $replacements['[node:summary]'] = $sanitize ? filter_xss($summary) : $summary;
}
