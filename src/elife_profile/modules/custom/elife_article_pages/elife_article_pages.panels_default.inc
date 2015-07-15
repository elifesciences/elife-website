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
    $pane->pid = 'new-31ce8bb0-9a44-44c2-8d72-da9a22b1d4de';
    $pane->panel = 'middle';
    $pane->type = 'elife_article_markup_section';
    $pane->subtype = 'elife_article_markup_section';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'buttons' => NULL,
      'context' => 'requiredcontext_entity:node_1',
      'aligner_start' => NULL,
      'override_title' => 1,
      'override_title_text' => 'Abstract',
      'override_title_heading' => 'h2',
      'aligner_stop' => NULL,
      'override_title_markup' => NULL,
      'markup_section' => 'abstract',
      'form_build_id' => 'form-FRtiQu2aBU5meAhpeUQ7wbjHkGAF6wpfCawCYX1WIU8',
      'form_token' => 'XN19D8uvONsniaAUaCJukpFwVM9azBgezcBFG8f62Jk',
      'form_id' => 'elife_article_markup_section_edit',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'pane_title' => 'Abstract',
        'pane_collapsed' => 0,
      ),
      'style' => 'collapsible',
    );
    $pane->css = array(
      'css_id' => 'abstract',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '31ce8bb0-9a44-44c2-8d72-da9a22b1d4de';
    $display->content['new-31ce8bb0-9a44-44c2-8d72-da9a22b1d4de'] = $pane;
    $display->panels['middle'][0] = 'new-31ce8bb0-9a44-44c2-8d72-da9a22b1d4de';
    $pane = new stdClass();
    $pane->pid = 'new-9efce0c6-2e9f-44d7-8355-d0feea144b08';
    $pane->panel = 'middle';
    $pane->type = 'elife_article_markup_section';
    $pane->subtype = 'elife_article_markup_section';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'buttons' => NULL,
      'context' => 'requiredcontext_entity:node_1',
      'aligner_start' => NULL,
      'override_title' => 1,
      'override_title_text' => 'eLife digest',
      'override_title_heading' => 'h2',
      'aligner_stop' => NULL,
      'override_title_markup' => NULL,
      'markup_section' => 'digest',
      'form_build_id' => 'form-OUUnMFad2nrhf2wGPEPt4dhptilVS9YeKEneWd5birM',
      'form_token' => 'XN19D8uvONsniaAUaCJukpFwVM9azBgezcBFG8f62Jk',
      'form_id' => 'elife_article_markup_section_edit',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'pane_title' => 'eLife digest',
        'pane_collapsed' => 1,
      ),
      'style' => 'collapsible',
    );
    $pane->css = array(
      'css_id' => 'digest',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '9efce0c6-2e9f-44d7-8355-d0feea144b08';
    $display->content['new-9efce0c6-2e9f-44d7-8355-d0feea144b08'] = $pane;
    $display->panels['middle'][1] = 'new-9efce0c6-2e9f-44d7-8355-d0feea144b08';
    $pane = new stdClass();
    $pane->pid = 'new-bc1f6d30-5a88-481e-bdfc-7ed26d724e85';
    $pane->panel = 'middle';
    $pane->type = 'elife_article_markup_section';
    $pane->subtype = 'elife_article_markup_section';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'requiredcontext_entity:node_1',
      'override_title' => 1,
      'override_title_text' => 'Main text',
      'override_title_heading' => 'h2',
      'buttons' => NULL,
      'aligner_start' => NULL,
      'aligner_stop' => NULL,
      'override_title_markup' => NULL,
      'markup_section' => 'main-text',
      'form_build_id' => 'form-UnNQOq9AAbbo7qXHb-6aezcDaP83r39PPgKNVniIOiw',
      'form_token' => 'XN19D8uvONsniaAUaCJukpFwVM9azBgezcBFG8f62Jk',
      'form_id' => 'elife_article_markup_section_edit',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'pane_title' => 'Main text',
        'pane_collapsed' => 0,
      ),
      'style' => 'collapsible',
    );
    $pane->css = array(
      'css_id' => 'main-text',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'bc1f6d30-5a88-481e-bdfc-7ed26d724e85';
    $display->content['new-bc1f6d30-5a88-481e-bdfc-7ed26d724e85'] = $pane;
    $display->panels['middle'][2] = 'new-bc1f6d30-5a88-481e-bdfc-7ed26d724e85';
    $pane = new stdClass();
    $pane->pid = 'new-8dc640d5-3788-4c3c-b02d-d5ef20ac6e68';
    $pane->panel = 'middle';
    $pane->type = 'elife_article_markup_section';
    $pane->subtype = 'elife_article_markup_section';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'buttons' => NULL,
      'context' => 'requiredcontext_entity:node_1',
      'aligner_start' => NULL,
      'override_title' => 1,
      'override_title_text' => 'References',
      'override_title_heading' => 'h2',
      'aligner_stop' => NULL,
      'override_title_markup' => NULL,
      'markup_section' => 'references',
      'form_build_id' => 'form-waKU0jTWHHZpsq1cUOWTgiM76eoq0ca39981PLCIgds',
      'form_token' => 'XN19D8uvONsniaAUaCJukpFwVM9azBgezcBFG8f62Jk',
      'form_id' => 'elife_article_markup_section_edit',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'pane_title' => 'References',
        'pane_collapsed' => 0,
      ),
      'style' => 'collapsible',
    );
    $pane->css = array(
      'css_id' => 'references',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '8dc640d5-3788-4c3c-b02d-d5ef20ac6e68';
    $display->content['new-8dc640d5-3788-4c3c-b02d-d5ef20ac6e68'] = $pane;
    $display->panels['middle'][3] = 'new-8dc640d5-3788-4c3c-b02d-d5ef20ac6e68';
    $pane = new stdClass();
    $pane->pid = 'new-475f5538-860d-44af-afad-736aee0d2a8f';
    $pane->panel = 'middle';
    $pane->type = 'elife_article_markup_section';
    $pane->subtype = 'elife_article_markup_section';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'buttons' => NULL,
      'context' => 'requiredcontext_entity:node_1',
      'aligner_start' => NULL,
      'override_title' => 1,
      'override_title_text' => 'Acknowledgements',
      'override_title_heading' => 'h2',
      'aligner_stop' => NULL,
      'override_title_markup' => NULL,
      'markup_section' => 'acknowledgements',
      'form_build_id' => 'form-EuT2Wht4ygymQbVf8Yv6GkMaQ0WBP03L5xpcq3-Ic04',
      'form_token' => 'XN19D8uvONsniaAUaCJukpFwVM9azBgezcBFG8f62Jk',
      'form_id' => 'elife_article_markup_section_edit',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'pane_title' => 'Acknowledgements',
        'pane_collapsed' => 0,
      ),
      'style' => 'collapsible',
    );
    $pane->css = array(
      'css_id' => 'acknowledgements',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '475f5538-860d-44af-afad-736aee0d2a8f';
    $display->content['new-475f5538-860d-44af-afad-736aee0d2a8f'] = $pane;
    $display->panels['middle'][4] = 'new-475f5538-860d-44af-afad-736aee0d2a8f';
    $pane = new stdClass();
    $pane->pid = 'new-663f55ff-5967-447b-a183-19b84c23bd6f';
    $pane->panel = 'middle';
    $pane->type = 'elife_article_markup_section';
    $pane->subtype = 'elife_article_markup_section';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'buttons' => NULL,
      'context' => 'requiredcontext_entity:node_1',
      'aligner_start' => NULL,
      'override_title' => 1,
      'override_title_text' => 'Decision letter',
      'override_title_heading' => 'h2',
      'aligner_stop' => NULL,
      'override_title_markup' => NULL,
      'markup_section' => 'decision-letter',
      'form_build_id' => 'form-1cuCaDX211R_4FNyLxPG-RtGPzNYTcMvt4I_ViPXJ_U',
      'form_token' => 'XN19D8uvONsniaAUaCJukpFwVM9azBgezcBFG8f62Jk',
      'form_id' => 'elife_article_markup_section_edit',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'pane_title' => 'Decision letter',
        'pane_collapsed' => 0,
      ),
      'style' => 'collapsible',
    );
    $pane->css = array(
      'css_id' => 'decision-letter',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '663f55ff-5967-447b-a183-19b84c23bd6f';
    $display->content['new-663f55ff-5967-447b-a183-19b84c23bd6f'] = $pane;
    $display->panels['middle'][5] = 'new-663f55ff-5967-447b-a183-19b84c23bd6f';
    $pane = new stdClass();
    $pane->pid = 'new-21d3bd99-adae-4364-b949-33a4ac312f7d';
    $pane->panel = 'middle';
    $pane->type = 'elife_article_markup_section';
    $pane->subtype = 'elife_article_markup_section';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'buttons' => NULL,
      'context' => 'requiredcontext_entity:node_1',
      'aligner_start' => NULL,
      'override_title' => 1,
      'override_title_text' => 'Author response',
      'override_title_heading' => 'h2',
      'aligner_stop' => NULL,
      'override_title_markup' => NULL,
      'markup_section' => 'author-response',
      'form_build_id' => 'form-nOL6O2aWF5wivZWeokqrZZb5sPvgQnPQM44Lit3OBeU',
      'form_token' => 'XN19D8uvONsniaAUaCJukpFwVM9azBgezcBFG8f62Jk',
      'form_id' => 'elife_article_markup_section_edit',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'pane_title' => 'Author response',
        'pane_collapsed' => 0,
      ),
      'style' => 'collapsible',
    );
    $pane->css = array(
      'css_id' => 'author-response',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '21d3bd99-adae-4364-b949-33a4ac312f7d';
    $display->content['new-21d3bd99-adae-4364-b949-33a4ac312f7d'] = $pane;
    $display->panels['middle'][6] = 'new-21d3bd99-adae-4364-b949-33a4ac312f7d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
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
    $pane->subtype = 'node:field_elife_a_contributors_pri';
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
