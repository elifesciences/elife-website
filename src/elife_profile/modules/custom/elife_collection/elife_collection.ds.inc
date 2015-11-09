<?php
/**
 * @file
 * elife_collection.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function elife_collection_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|elife_collection|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'elife_collection';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_elife_c_articles' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fis' => TRUE,
          'fis-el' => 'ol',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_elife_c_curators' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fis' => TRUE,
          'fis-el' => 'ol',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_elife_c_podcast' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_elife_c_related' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fis' => TRUE,
          'fis-el' => 'ol',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['node|elife_collection|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|elife_collection|elife_teaser_compact';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'elife_collection';
  $ds_fieldsetting->view_mode = 'elife_teaser_compact';
  $ds_fieldsetting->settings = array(
    'elife_c_curators_short' => array(
      'weight' => '1',
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
        'class' => 'collection-teaser__title',
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['node|elife_collection|elife_teaser_compact'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|elife_collection|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'elife_collection';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'elife_c_image' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'elife_c_text' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '1',
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
  );
  $export['node|elife_collection|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function elife_collection_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'elife_c_curators_short';
  $ds_field->label = 'Curators list (short)';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'elife_collection|*';
  $ds_field->properties = array();
  $export['elife_c_curators_short'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'elife_c_image';
  $ds_field->label = 'Image';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'elife_collection|teaser';
  $ds_field->properties = array();
  $export['elife_c_image'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'elife_c_text';
  $ds_field->label = 'Text';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'elife_collection|teaser';
  $ds_field->properties = array();
  $export['elife_c_text'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function elife_collection_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|elife_collection|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'elife_collection';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_elife_c_curators',
        1 => 'field_elife_c_articles',
        2 => 'field_elife_c_podcast',
        3 => 'field_elife_c_related',
        4 => 'sharethis',
      ),
    ),
    'fields' => array(
      'field_elife_c_curators' => 'ds_content',
      'field_elife_c_articles' => 'ds_content',
      'field_elife_c_podcast' => 'ds_content',
      'field_elife_c_related' => 'ds_content',
      'sharethis' => 'ds_content',
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
  $export['node|elife_collection|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|elife_collection|elife_teaser_compact';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'elife_collection';
  $ds_layout->view_mode = 'elife_teaser_compact';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'elife_c_curators_short',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'elife_c_curators_short' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        'collection-teaser' => 'collection-teaser',
        'collection-teaser--compact' => 'collection-teaser--compact',
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
  $export['node|elife_collection|elife_teaser_compact'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|elife_collection|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'elife_collection';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'elife_c_image',
        1 => 'title',
        2 => 'elife_c_text',
      ),
    ),
    'fields' => array(
      'elife_c_image' => 'ds_content',
      'title' => 'ds_content',
      'elife_c_text' => 'ds_content',
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
  $export['node|elife_collection|teaser'] = $ds_layout;

  return $export;
}
