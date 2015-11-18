<?php

$plugin = array(
  'title' => t('Article reference'),
  'keyword' => 'elife_article_reference',
  'description' => t('Adds an article reference parent from a node context.'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'context' => 'ctools_elife_article_reference_context',
  'edit form' => 'ctools_elife_article_reference_settings_form',
  'defaults' => array('type' => 'top'),
);

function ctools_elife_article_reference_context($context, $conf) {
  if (
    empty($context->data)
    ||
    !in_array($context->data->type, ['elife_article', 'elife_article_ver'])
  ) {
    return ctools_context_create_empty('node');
  }

  $article_reference = elife_article_reference_for_article_id($context->data->field_elife_a_article_id[LANGUAGE_NONE][0]['value']);

  return ctools_context_create('node', $article_reference);
}

function ctools_elife_article_reference_settings_form($form, &$form_state) {
  $conf = $form_state['conf'];

  return $form;
}
