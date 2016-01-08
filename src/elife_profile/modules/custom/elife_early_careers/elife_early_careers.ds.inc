<?php
/**
 * @file
 * elife_early_careers.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function elife_early_careers_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|elife_early_careers_spotlight|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'elife_early_careers_spotlight';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'elife_s_heading' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'elife_s_title' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'elife_s_view_more' => array(
      'weight' => '15',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_elife_s_text' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'div',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'ec-section--latest__item-text',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['node|elife_early_careers_spotlight|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function elife_early_careers_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'elife_s_heading';
  $ds_field->label = 'Heading';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'elife_early_careers_spotlight|teaser';
  $ds_field->properties = array();
  $export['elife_s_heading'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'elife_s_title';
  $ds_field->label = 'Spotlight Title';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'elife_early_careers_spotlight|teaser';
  $ds_field->properties = array();
  $export['elife_s_title'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'elife_s_view_more';
  $ds_field->label = 'View more';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'elife_early_careers_spotlight|teaser';
  $ds_field->properties = array();
  $export['elife_s_view_more'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function elife_early_careers_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|elife_early_careers_spotlight|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'elife_early_careers_spotlight';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'elife_s_heading',
        1 => 'elife_s_title',
        2 => 'field_elife_s_text',
        3 => 'elife_s_view_more',
      ),
    ),
    'fields' => array(
      'elife_s_heading' => 'ds_content',
      'elife_s_title' => 'ds_content',
      'field_elife_s_text' => 'ds_content',
      'elife_s_view_more' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'article',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|elife_early_careers_spotlight|teaser'] = $ds_layout;

  return $export;
}
