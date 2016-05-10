<?php
/**
 * @file
 * elife_person_profile.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function elife_person_profile_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_elife_pp_biog_outer|node|elife_person_profile|teaser';
  $field_group->group_name = 'group_elife_pp_biog_outer';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'elife_person_profile';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Biography outer',
    'weight' => '1',
    'children' => array(
      0 => 'group_elife_pp_biog_wrapper',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Biography outer',
      'instance_settings' => array(
        'classes' => 'person-profile__biog-outer',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $export['group_elife_pp_biog_outer|node|elife_person_profile|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_elife_pp_biog_wrapper|node|elife_person_profile|teaser';
  $field_group->group_name = 'group_elife_pp_biog_wrapper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'elife_person_profile';
  $field_group->mode = 'teaser';
  $field_group->parent_name = 'group_elife_pp_biog_outer';
  $field_group->data = array(
    'label' => 'Biography wrapper',
    'weight' => '25',
    'children' => array(
      0 => 'group_elife_pp_biog',
      1 => 'group_elife_pp_interest',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Biography wrapper',
      'instance_settings' => array(
        'classes' => 'person-profile__biog-wrapper',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $export['group_elife_pp_biog_wrapper|node|elife_person_profile|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_elife_pp_biog|node|elife_person_profile|teaser';
  $field_group->group_name = 'group_elife_pp_biog';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'elife_person_profile';
  $field_group->mode = 'teaser';
  $field_group->parent_name = 'group_elife_pp_biog_wrapper';
  $field_group->data = array(
    'label' => 'Biography',
    'weight' => '28',
    'children' => array(
      0 => 'field_elife_pp_expertise',
      1 => 'field_elife_pp_profile',
      2 => 'elife_pp_name',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Biography',
      'instance_settings' => array(
        'classes' => 'person-profile__biog',
        'element' => 'section',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $export['group_elife_pp_biog|node|elife_person_profile|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_elife_pp_caption|node|elife_person_profile|teaser';
  $field_group->group_name = 'group_elife_pp_caption';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'elife_person_profile';
  $field_group->mode = 'teaser';
  $field_group->parent_name = 'group_elife_pp_link';
  $field_group->data = array(
    'label' => 'Caption',
    'weight' => '4',
    'children' => array(
      0 => 'field_elife_pp_affiliation',
      1 => 'field_elife_pp_photo',
      2 => 'field_elife_pp_title',
      3 => 'group_elife_pp_name',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Caption',
      'instance_settings' => array(
        'classes' => 'person-profile__figure-caption',
        'element' => 'figcaption',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $export['group_elife_pp_caption|node|elife_person_profile|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_elife_pp_details|node|elife_person_profile|form';
  $field_group->group_name = 'group_elife_pp_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'elife_person_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '0',
    'children' => array(
      0 => 'field_elife_pp_interest',
      1 => 'field_elife_pp_past',
      2 => 'field_elife_pp_photo',
      3 => 'field_elife_pp_title',
      4 => 'field_elife_pp_type',
      5 => 'group_elife_pp_name',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_elife_pp_details|node|elife_person_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_elife_pp_interest|node|elife_person_profile|teaser';
  $field_group->group_name = 'group_elife_pp_interest';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'elife_person_profile';
  $field_group->mode = 'teaser';
  $field_group->parent_name = 'group_elife_pp_biog_wrapper';
  $field_group->data = array(
    'label' => 'Competing interests statement',
    'weight' => '29',
    'children' => array(
      0 => 'field_elife_pp_interest',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Competing interests statement',
      'instance_settings' => array(
        'classes' => 'person-profile__competing',
        'element' => 'section',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $export['group_elife_pp_interest|node|elife_person_profile|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_elife_pp_link|node|elife_person_profile|teaser';
  $field_group->group_name = 'group_elife_pp_link';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'elife_person_profile';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Link',
    'weight' => '0',
    'children' => array(
      0 => 'group_elife_pp_caption',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Link',
      'instance_settings' => array(
        'classes' => 'person-profile__link person-profile__link-js-hook',
        'element' => 'figure',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $export['group_elife_pp_link|node|elife_person_profile|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_elife_pp_name|node|elife_person_profile|elife_teaser_alternative';
  $field_group->group_name = 'group_elife_pp_name';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'elife_person_profile';
  $field_group->mode = 'elife_teaser_alternative';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Name',
    'weight' => '0',
    'children' => array(
      0 => 'field_elife_pp_first_name',
      1 => 'field_elife_pp_last_name',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Name',
      'instance_settings' => array(
        'classes' => 'p-name fn',
        'element' => 'h5',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $export['group_elife_pp_name|node|elife_person_profile|elife_teaser_alternative'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_elife_pp_name|node|elife_person_profile|elife_teaser_compact';
  $field_group->group_name = 'group_elife_pp_name';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'elife_person_profile';
  $field_group->mode = 'elife_teaser_compact';
  $field_group->parent_name = 'group_elife_pp_text';
  $field_group->data = array(
    'label' => 'Name',
    'weight' => '2',
    'children' => array(
      0 => 'field_elife_pp_first_name',
      1 => 'field_elife_pp_last_name',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Name',
      'instance_settings' => array(
        'classes' => 'person-profile-compact__name fn',
        'element' => 'span',
        'show_label' => '0',
        'label_element' => 'span',
        'attributes' => '',
      ),
    ),
  );
  $export['group_elife_pp_name|node|elife_person_profile|elife_teaser_compact'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_elife_pp_name|node|elife_person_profile|form';
  $field_group->group_name = 'group_elife_pp_name';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'elife_person_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_elife_pp_details';
  $field_group->data = array(
    'label' => 'Name',
    'weight' => '6',
    'children' => array(
      0 => 'field_elife_pp_first_name',
      1 => 'field_elife_pp_last_name',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Name',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_elife_pp_name|node|elife_person_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_elife_pp_name|node|elife_person_profile|teaser';
  $field_group->group_name = 'group_elife_pp_name';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'elife_person_profile';
  $field_group->mode = 'teaser';
  $field_group->parent_name = 'group_elife_pp_caption';
  $field_group->data = array(
    'label' => 'Name',
    'weight' => '1',
    'children' => array(
      0 => 'field_elife_pp_first_name',
      1 => 'field_elife_pp_last_name',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Name',
      'instance_settings' => array(
        'classes' => 'person-profile__figure-caption-name fn',
        'element' => 'h5',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $export['group_elife_pp_name|node|elife_person_profile|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_elife_pp_profile|node|elife_person_profile|form';
  $field_group->group_name = 'group_elife_pp_profile';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'elife_person_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Profile',
    'weight' => '1',
    'children' => array(
      0 => 'field_elife_pp_profile',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Profile',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_elife_pp_profile|node|elife_person_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_elife_pp_research|node|elife_person_profile|form';
  $field_group->group_name = 'group_elife_pp_research';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'elife_person_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Research',
    'weight' => '2',
    'children' => array(
      0 => 'field_elife_pp_affiliation',
      1 => 'field_elife_pp_expertise',
      2 => 'field_elife_pp_organism',
      3 => 'field_elife_pp_research_focus',
      4 => 'field_elife_pp_orcid',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Research',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_elife_pp_research|node|elife_person_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_elife_pp_text_wrapper|node|elife_person_profile|elife_teaser_compact';
  $field_group->group_name = 'group_elife_pp_text_wrapper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'elife_person_profile';
  $field_group->mode = 'elife_teaser_compact';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Text wrapper',
    'weight' => '1',
    'children' => array(
      0 => 'group_elife_pp_text',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Text wrapper',
      'instance_settings' => array(
        'classes' => 'person-profile-compact__text-wrapper',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $export['group_elife_pp_text_wrapper|node|elife_person_profile|elife_teaser_compact'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_elife_pp_text|node|elife_person_profile|elife_teaser_compact';
  $field_group->group_name = 'group_elife_pp_text';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'elife_person_profile';
  $field_group->mode = 'elife_teaser_compact';
  $field_group->parent_name = 'group_elife_pp_text_wrapper';
  $field_group->data = array(
    'label' => 'Text',
    'weight' => '2',
    'children' => array(
      0 => 'field_elife_pp_affiliation',
      1 => 'field_elife_pp_title',
      2 => 'group_elife_pp_name',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Text',
      'instance_settings' => array(
        'classes' => 'person-profile-compact__text',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $export['group_elife_pp_text|node|elife_person_profile|elife_teaser_compact'] = $field_group;

  return $export;
}
