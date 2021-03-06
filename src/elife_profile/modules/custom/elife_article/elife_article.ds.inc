<?php
/**
 * @file
 * elife_article.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function elife_article_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|elife_article_ver|elife_teaser_compact';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'elife_article_ver';
  $ds_fieldsetting->view_mode = 'elife_teaser_compact';
  $ds_fieldsetting->settings = array(
    'elife_a_contributors_short' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'elife_a_meta_compact' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => 'article-teaser__title',
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['node|elife_article_ver|elife_teaser_compact'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|elife_article_ver|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'elife_article_ver';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'elife_a_lens_link' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'elife_a_status_text' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'elife_a_contributors' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'elife_a_meta' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => 'article-teaser__title',
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_elife_a_author_imp' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'article-teaser__impact-statement',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_elife_a_doi' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'article-teaser__doi',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['node|elife_article_ver|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function elife_article_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'elife_a_contributors';
  $ds_field->label = 'Contributors list';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'elife_article_ver|*';
  $ds_field->properties = array();
  $export['elife_a_contributors'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'elife_a_contributors_short';
  $ds_field->label = 'Contributors list (short)';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'elife_article_ver|*';
  $ds_field->properties = array();
  $export['elife_a_contributors_short'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'elife_a_lens_link';
  $ds_field->label = 'Lens link';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'elife_article_ver|*';
  $ds_field->properties = array();
  $export['elife_a_lens_link'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'elife_a_meta';
  $ds_field->label = 'Meta';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'elife_article_ver|*';
  $ds_field->properties = array();
  $export['elife_a_meta'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'elife_a_meta_compact';
  $ds_field->label = 'Meta (compact)';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'elife_article_ver|*';
  $ds_field->properties = array();
  $export['elife_a_meta_compact'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'elife_a_status_text';
  $ds_field->label = 'Status text';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'elife_article_ver|*';
  $ds_field->properties = array();
  $export['elife_a_status_text'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function elife_article_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|elife_article_ver|elife_teaser_compact';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'elife_article_ver';
  $ds_layout->view_mode = 'elife_teaser_compact';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        2 => 'elife_a_contributors_short',
        3 => 'elife_a_meta_compact',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'elife_a_contributors_short' => 'ds_content',
      'elife_a_meta_compact' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        'article-teaser' => 'article-teaser',
        'article-teaser--compact' => 'article-teaser--compact',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|elife_article_ver|elife_teaser_compact'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|elife_article_ver|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'elife_article_ver';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'elife_a_status_text',
        2 => 'field_elife_a_author_imp',
        3 => 'elife_a_contributors',
        4 => 'field_elife_a_doi',
        5 => 'elife_a_meta',
        6 => 'elife_a_lens_link',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'elife_a_status_text' => 'ds_content',
      'field_elife_a_author_imp' => 'ds_content',
      'elife_a_contributors' => 'ds_content',
      'field_elife_a_doi' => 'ds_content',
      'elife_a_meta' => 'ds_content',
      'elife_a_lens_link' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        'article-teaser' => 'article-teaser',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|elife_article_ver|teaser'] = $ds_layout;

  return $export;
}
