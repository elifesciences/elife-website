<?php
/**
 * @file
 * elife_person_profile.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function elife_person_profile_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|elife_person_profile|elife_teaser_alternative';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'elife_person_profile';
  $ds_fieldsetting->view_mode = 'elife_teaser_alternative';
  $ds_fieldsetting->settings = array(
    'field_elife_p_affiliation' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'person-profile__suppl org',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_elife_p_first_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'suffix' => ' ',
        ),
      ),
    ),
    'field_elife_p_last_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_elife_p_organism' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'h6',
          'lb-cl' => 'person-profile__list-title',
          'lb-col' => TRUE,
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => 'person-profile__list-item',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_elife_p_research_focus' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'h6',
          'lb-cl' => 'person-profile__list-title',
          'lb-col' => TRUE,
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => 'person-profile__list-item',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_elife_p_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'person-profile__suppl role',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['node|elife_person_profile|elife_teaser_alternative'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|elife_person_profile|elife_teaser_compact';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'elife_person_profile';
  $ds_fieldsetting->view_mode = 'elife_teaser_compact';
  $ds_fieldsetting->settings = array(
    'field_elife_p_affiliation' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'person-profile-compact__title org',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_elife_p_first_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'suffix' => ' ',
        ),
      ),
    ),
    'field_elife_p_last_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_elife_p_photo' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'person-profile-compact__image-wrapper',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_elife_p_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'person-profile-compact__title role',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['node|elife_person_profile|elife_teaser_compact'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|elife_person_profile|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'elife_person_profile';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'elife_p_name' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
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
    'field_elife_p_affiliation' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'person-profile__figure-caption-suppl org',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_elife_p_competing_interest' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_elife_p_expertise' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_elife_p_first_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'suffix' => ' ',
        ),
      ),
    ),
    'field_elife_p_last_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_elife_p_photo' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_elife_p_profile' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_elife_p_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'person-profile__figure-caption-suppl role',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['node|elife_person_profile|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function elife_person_profile_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'elife_p_name';
  $ds_field->label = 'Name';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'elife_person_profile|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '[node:elife-p-name]',
      'format' => 'plain_text',
    ),
    'use_token' => 1,
  );
  $export['elife_p_name'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function elife_person_profile_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|elife_person_profile|elife_teaser_alternative';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'elife_person_profile';
  $ds_layout->view_mode = 'elife_teaser_alternative';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_elife_p_name',
        1 => 'field_elife_p_first_name',
        2 => 'field_elife_p_title',
        3 => 'field_elife_p_last_name',
        4 => 'field_elife_p_affiliation',
        5 => 'field_elife_p_research_focus',
        6 => 'field_elife_p_organism',
      ),
    ),
    'fields' => array(
      'group_elife_p_name' => 'ds_content',
      'field_elife_p_first_name' => 'ds_content',
      'field_elife_p_title' => 'ds_content',
      'field_elife_p_last_name' => 'ds_content',
      'field_elife_p_affiliation' => 'ds_content',
      'field_elife_p_research_focus' => 'ds_content',
      'field_elife_p_organism' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        'person-profile' => 'person-profile',
        'vcard' => 'vcard',
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
  $export['node|elife_person_profile|elife_teaser_alternative'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|elife_person_profile|elife_teaser_compact';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'elife_person_profile';
  $ds_layout->view_mode = 'elife_teaser_compact';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_elife_p_photo',
        1 => 'group_elife_p_text_wrapper',
        2 => 'field_elife_p_first_name',
        3 => 'field_elife_p_last_name',
        4 => 'group_elife_p_text',
        5 => 'group_elife_p_name',
        6 => 'field_elife_p_title',
        7 => 'field_elife_p_affiliation',
      ),
    ),
    'fields' => array(
      'field_elife_p_photo' => 'ds_content',
      'group_elife_p_text_wrapper' => 'ds_content',
      'field_elife_p_first_name' => 'ds_content',
      'field_elife_p_last_name' => 'ds_content',
      'group_elife_p_text' => 'ds_content',
      'group_elife_p_name' => 'ds_content',
      'field_elife_p_title' => 'ds_content',
      'field_elife_p_affiliation' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        'person-profile-compact' => 'person-profile-compact',
        'vcard' => 'vcard',
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
  $export['node|elife_person_profile|elife_teaser_compact'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|elife_person_profile|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'elife_person_profile';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'elife_p_name',
        1 => 'group_elife_p_link',
        2 => 'field_elife_p_competing_interest',
        3 => 'field_elife_p_photo',
        4 => 'field_elife_p_expertise',
        5 => 'group_elife_p_biog_outer',
        6 => 'group_elife_p_name',
        7 => 'field_elife_p_profile',
        8 => 'field_elife_p_title',
        9 => 'field_elife_p_affiliation',
        10 => 'group_elife_p_caption',
        11 => 'field_elife_p_first_name',
        12 => 'field_elife_p_last_name',
        13 => 'group_elife_p_biog_wrapper',
        14 => 'group_elife_p_biog',
        15 => 'group_elife_p_competing_interest',
      ),
    ),
    'fields' => array(
      'elife_p_name' => 'ds_content',
      'group_elife_p_link' => 'ds_content',
      'field_elife_p_competing_interest' => 'ds_content',
      'field_elife_p_photo' => 'ds_content',
      'field_elife_p_expertise' => 'ds_content',
      'group_elife_p_biog_outer' => 'ds_content',
      'group_elife_p_name' => 'ds_content',
      'field_elife_p_profile' => 'ds_content',
      'field_elife_p_title' => 'ds_content',
      'field_elife_p_affiliation' => 'ds_content',
      'group_elife_p_caption' => 'ds_content',
      'field_elife_p_first_name' => 'ds_content',
      'field_elife_p_last_name' => 'ds_content',
      'group_elife_p_biog_wrapper' => 'ds_content',
      'group_elife_p_biog' => 'ds_content',
      'group_elife_p_competing_interest' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        'person-profile--extended' => 'person-profile--extended',
        'vcard' => 'vcard',
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
  $export['node|elife_person_profile|teaser'] = $ds_layout;

  return $export;
}
