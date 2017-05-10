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
    'field_elife_pp_affiliation' => array(
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
    'field_elife_pp_first_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'suffix' => ' ',
        ),
      ),
    ),
    'field_elife_pp_last_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_elife_pp_organism' => array(
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
    'field_elife_pp_research_focus' => array(
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
    'field_elife_pp_title' => array(
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
    'field_elife_pp_affiliation' => array(
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
    'field_elife_pp_first_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'suffix' => ' ',
        ),
      ),
    ),
    'field_elife_pp_last_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_elife_pp_photo' => array(
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
    'field_elife_pp_title' => array(
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
    'elife_pp_name' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'h5',
          'fi-cl' => 'person-profile__biog-name',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_elife_pp_affiliation' => array(
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
    'field_elife_pp_expertise' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lbw' => 1,
          'lbw-el' => 'h6',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'person-profile__biog-expertise',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'ul',
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
    'field_elife_pp_first_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'suffix' => ' ',
        ),
      ),
    ),
    'field_elife_pp_interest' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lbw' => 1,
          'lbw-el' => 'h6',
        ),
      ),
    ),
    'field_elife_pp_last_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_elife_pp_photo' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_elife_pp_profile' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_elife_pp_research_focus' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Keywords',
          'lbw' => 1,
          'lbw-el' => 'h6',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'person-profile__biog-keywords',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'ul',
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
    'field_elife_pp_title' => array(
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
  $ds_field->field = 'elife_pp_name';
  $ds_field->label = 'Name';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'elife_person_profile|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '[node:elife-pp-name]',
      'format' => 'plain_text',
    ),
    'use_token' => 1,
  );
  $export['elife_pp_name'] = $ds_field;

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
        0 => 'group_elife_pp_name',
        1 => 'field_elife_pp_first_name',
        2 => 'field_elife_pp_title',
        3 => 'field_elife_pp_last_name',
        4 => 'field_elife_pp_affiliation',
        5 => 'field_elife_pp_research_focus',
        6 => 'field_elife_pp_organism',
      ),
    ),
    'fields' => array(
      'group_elife_pp_name' => 'ds_content',
      'field_elife_pp_first_name' => 'ds_content',
      'field_elife_pp_title' => 'ds_content',
      'field_elife_pp_last_name' => 'ds_content',
      'field_elife_pp_affiliation' => 'ds_content',
      'field_elife_pp_research_focus' => 'ds_content',
      'field_elife_pp_organism' => 'ds_content',
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
        0 => 'field_elife_pp_photo',
        1 => 'group_elife_pp_text_wrapper',
        2 => 'field_elife_pp_first_name',
        3 => 'field_elife_pp_last_name',
        4 => 'group_elife_pp_text',
        5 => 'group_elife_pp_name',
        6 => 'field_elife_pp_title',
        7 => 'field_elife_pp_affiliation',
      ),
    ),
    'fields' => array(
      'field_elife_pp_photo' => 'ds_content',
      'group_elife_pp_text_wrapper' => 'ds_content',
      'field_elife_pp_first_name' => 'ds_content',
      'field_elife_pp_last_name' => 'ds_content',
      'group_elife_pp_text' => 'ds_content',
      'group_elife_pp_name' => 'ds_content',
      'field_elife_pp_title' => 'ds_content',
      'field_elife_pp_affiliation' => 'ds_content',
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
        0 => 'elife_pp_name',
        1 => 'field_elife_pp_photo',
        2 => 'group_elife_pp_link',
        3 => 'field_elife_pp_interest',
        4 => 'group_elife_pp_biog_outer',
        5 => 'field_elife_pp_expertise',
        6 => 'group_elife_pp_name',
        7 => 'field_elife_pp_profile',
        8 => 'field_elife_pp_title',
        9 => 'field_elife_pp_affiliation',
        10 => 'field_elife_pp_research_focus',
        11 => 'group_elife_pp_caption',
        12 => 'field_elife_pp_first_name',
        13 => 'field_elife_pp_last_name',
        14 => 'group_elife_pp_biog_wrapper',
        15 => 'group_elife_pp_biog',
        16 => 'group_elife_pp_interest',
      ),
    ),
    'fields' => array(
      'elife_pp_name' => 'ds_content',
      'field_elife_pp_photo' => 'ds_content',
      'group_elife_pp_link' => 'ds_content',
      'field_elife_pp_interest' => 'ds_content',
      'group_elife_pp_biog_outer' => 'ds_content',
      'field_elife_pp_expertise' => 'ds_content',
      'group_elife_pp_name' => 'ds_content',
      'field_elife_pp_profile' => 'ds_content',
      'field_elife_pp_title' => 'ds_content',
      'field_elife_pp_affiliation' => 'ds_content',
      'field_elife_pp_research_focus' => 'ds_content',
      'group_elife_pp_caption' => 'ds_content',
      'field_elife_pp_first_name' => 'ds_content',
      'field_elife_pp_last_name' => 'ds_content',
      'group_elife_pp_biog_wrapper' => 'ds_content',
      'group_elife_pp_biog' => 'ds_content',
      'group_elife_pp_interest' => 'ds_content',
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
