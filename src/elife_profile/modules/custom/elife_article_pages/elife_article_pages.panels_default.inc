<?php
/**
 * @file
 * elife_article_pages.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function elife_article_pages_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'elife_article';
  $mini->category = '';
  $mini->admin_title = 'Article';
  $mini->admin_description = '';
  $mini->requiredcontexts = array(
    0 => array(
      'identifier' => 'Article Version',
      'keyword' => 'node',
      'name' => 'entity:node',
      'entity_id' => '',
      'id' => 1,
    ),
  );
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '9f0260ff-e8cb-46d6-8835-013bb577fc98';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2646571d-5051-4ccd-804f-1192462b7ae9';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_elife_a_doi';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'text_plain',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'requiredcontext_entity:node_1',
      'override_title' => 1,
      'override_title_text' => 'Main text',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'pane_title' => 'Main text',
        'pane_collapsed' => 0,
      ),
      'style' => 'collapsible',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2646571d-5051-4ccd-804f-1192462b7ae9';
    $display->content['new-2646571d-5051-4ccd-804f-1192462b7ae9'] = $pane;
    $display->panels['middle'][0] = 'new-2646571d-5051-4ccd-804f-1192462b7ae9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-2646571d-5051-4ccd-804f-1192462b7ae9';
  $mini->display = $display;
  $export['elife_article'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'elife_article_author';
  $mini->category = '';
  $mini->admin_title = 'Article & author info';
  $mini->admin_description = '';
  $mini->requiredcontexts = array(
    0 => array(
      'identifier' => 'Article Version',
      'keyword' => 'node',
      'name' => 'entity:node',
      'entity_id' => '',
      'id' => 1,
    ),
  );
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'a5c94191-72cf-4b52-aafc-5ac7036faede';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d5a20046-a0c5-4e16-a854-0543b9862123';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_elife_a_contributors';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'entityreference_label',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'link' => 0,
      ),
      'context' => 'requiredcontext_entity:node_1',
      'override_title' => 1,
      'override_title_text' => 'Author information',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'pane_title' => 'Author information',
        'pane_collapsed' => 0,
      ),
      'style' => 'collapsible',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd5a20046-a0c5-4e16-a854-0543b9862123';
    $display->content['new-d5a20046-a0c5-4e16-a854-0543b9862123'] = $pane;
    $display->panels['middle'][0] = 'new-d5a20046-a0c5-4e16-a854-0543b9862123';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-d5a20046-a0c5-4e16-a854-0543b9862123';
  $mini->display = $display;
  $export['elife_article_author'] = $mini;

  return $export;
}
