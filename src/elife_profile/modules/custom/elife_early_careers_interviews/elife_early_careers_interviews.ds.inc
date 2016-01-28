<?php
/**
 * @file
 * elife_early_careers_interviews.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function elife_early_careers_interviews_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'field_collection_item|field_elife_i_cv|default';
  $ds_fieldsetting->entity_type = 'field_collection_item';
  $ds_fieldsetting->bundle = 'field_elife_i_cv';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_elife_i_cv_date' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'suffix' => ': ',
          'fi' => TRUE,
          'fi-el' => 'b',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_elife_i_cv_text' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['field_collection_item|field_elife_i_cv|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|elife_early_careers_interview|elife_teaser_compact';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'elife_early_careers_interview';
  $ds_fieldsetting->view_mode = 'elife_teaser_compact';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => 'collection-teaser__title',
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_elife_i_text' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['node|elife_early_careers_interview|elife_teaser_compact'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|elife_early_careers_interview|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'elife_early_careers_interview';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => 'collection-teaser__title',
        'ft' => array(),
      ),
    ),
    'field_elife_i_images' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['node|elife_early_careers_interview|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function elife_early_careers_interviews_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_elife_i_cv|default';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_elife_i_cv';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_elife_i_cv_date',
        1 => 'field_elife_i_cv_text',
      ),
    ),
    'fields' => array(
      'field_elife_i_cv_date' => 'ds_content',
      'field_elife_i_cv_text' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
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
  $export['field_collection_item|field_elife_i_cv|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|elife_early_careers_interview|elife_teaser_compact';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'elife_early_careers_interview';
  $ds_layout->view_mode = 'elife_teaser_compact';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_elife_i_text',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_elife_i_text' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
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
  $export['node|elife_early_careers_interview|elife_teaser_compact'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|elife_early_careers_interview|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'elife_early_careers_interview';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_elife_i_images',
        1 => 'title',
        2 => 'field_elife_i_text',
      ),
    ),
    'fields' => array(
      'field_elife_i_images' => 'ds_content',
      'title' => 'ds_content',
      'field_elife_i_text' => 'ds_content',
    ),
    'limit' => array(
      'field_elife_i_images' => '1',
    ),
    'classes' => array(
      'layout_class' => array(
        'collection-teaser' => 'collection-teaser',
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
  $export['node|elife_early_careers_interview|teaser'] = $ds_layout;

  return $export;
}
