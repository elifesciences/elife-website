<?php
/**
 * @file
 * plugins/content_types/elife_disqus.inc
 *
 * Content type enable us to place the disqus comments as pane
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = [
  'title' => t('Disqus comments'),
  'description' => t('Disqus comments will be loaded in this pane'),
  'single' => TRUE,
  'category' => ['eLife'],
  'required context' => [
    new ctools_context_required(t('Entity Context'), 'entity'),
  ],
  'render callback' => 'elife_disqus_content_type_render',
  'edit form' => 'elife_disqus_content_type_edit_form',
];

/**
 * Edit form callback for the content type.
 */
function elife_disqus_content_type_edit_form($form, &$form_state) {
  // Get the form state i.e. configuration values to load the default values.
  $conf = $form_state['conf'];
  return $form;
}

/**
 * Render disqus comments.
 */
function elife_disqus_content_type_render($subtype, $conf, $panel_args, &$context) {
  $content = [];
  if (!empty($context[0]->data->disqus['domain'])) {
    drupal_add_js(['disqusComments' => $context[0]->data->disqus['domain']], 'setting');
    $args = [
      '!terms_link' => l('terms and conditions', 'terms-and-conditions-of-use'),
      '!competing_link' => l('competing interests', 'http://submit.elifesciences.org/html/elife_author_instructions.html#Competing_interests'),
    ];
    $content['rider'] = [
      '#type' => 'markup',
      '#markup' => t('If your username is different from your full name, we require you to identify yourself within the comment itself. Comments are checked by a moderator (and/or an eLife editor) before they appear. Comments should be constructive, relevant to the article, conform to our !terms_link, and include any pertinent !competing_link.', $args),
    ];

    $content['disqus'] = [
      '#type' => 'disqus',
      '#disqus' => $context[0]->data->disqus,
    ];
  }
  $block = new stdClass();

  $block->title = 'Comments';
  $block->content = $content;
  return $block;
}
