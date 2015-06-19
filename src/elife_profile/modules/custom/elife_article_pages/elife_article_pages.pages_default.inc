<?php
/**
 * @file
 * elife_article_pages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function elife_article_pages_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__elife_research_article';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'eLife Research Article',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'elife_research_article',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'elife_article_ver' => 'elife_article_ver',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'entity_field_value:node:elife_article_ver:field_elife_a_article_type',
          'settings' => array(
            'field_elife_a_article_type' => array(
              'und' => array(
                0 => array(
                  'value' => 'research-article',
                  'format' => '',
                ),
              ),
            ),
            'field_elife_a_article_type_value' => array(
              0 => 'research-article',
            ),
            'field_elife_a_article_type_format' => array(
              0 => '',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'entity_field_value:node:elife_article_ver:field_elife_a_subarticle',
          'settings' => array(
            'field_elife_a_subarticle' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_elife_a_subarticle_value' => array(
              0 => 1,
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'elife_article';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'main' => NULL,
      'side_lens' => NULL,
      'side_link' => NULL,
      'side_top' => NULL,
      'side_bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'c1c86267-3c85-42ec-88cf-050803b3fad3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8466fbf9-7f5a-4ca1-8418-5a72f7770165';
    $pane->panel = 'main';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8466fbf9-7f5a-4ca1-8418-5a72f7770165';
    $display->content['new-8466fbf9-7f5a-4ca1-8418-5a72f7770165'] = $pane;
    $display->panels['main'][0] = 'new-8466fbf9-7f5a-4ca1-8418-5a72f7770165';
    $pane = new stdClass();
    $pane->pid = 'new-ffdb185e-6d8e-48b5-901a-2bbda76fa9ab';
    $pane->panel = 'side_top';
    $pane->type = 'views_panes';
    $pane->subtype = 'elife_article_podcast-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_elife_p_articles_value' => '%node:field-elife-a-article-id',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ffdb185e-6d8e-48b5-901a-2bbda76fa9ab';
    $display->content['new-ffdb185e-6d8e-48b5-901a-2bbda76fa9ab'] = $pane;
    $display->panels['side_top'][0] = 'new-ffdb185e-6d8e-48b5-901a-2bbda76fa9ab';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-ffdb185e-6d8e-48b5-901a-2bbda76fa9ab';
  $handler->conf['display'] = $display;
  $export['node_view__elife_research_article'] = $handler;

  return $export;
}
