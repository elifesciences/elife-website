<?php
/**
 * @file
 * elife_news.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function elife_news_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|elife_news_article|elife_teaser_compact';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'elife_news_article';
  $ds_fieldsetting->view_mode = 'elife_teaser_compact';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => 'news-teaser__title',
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_elife_n_text' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['node|elife_news_article|elife_teaser_compact'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|elife_news_article|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'elife_news_article';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => 'news-teaser__title',
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'post_date' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'ds_post_date_elife_date_only',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'news-teaser__date',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_elife_n_text' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['node|elife_news_article|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function elife_news_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|elife_news_article|elife_teaser_compact';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'elife_news_article';
  $ds_layout->view_mode = 'elife_teaser_compact';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_elife_n_text',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_elife_n_text' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        'news-teaser' => 'news-teaser',
        'news-teaser--compact' => 'news-teaser--compact',
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
  $export['node|elife_news_article|elife_teaser_compact'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|elife_news_article|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'elife_news_article';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'post_date',
        2 => 'field_elife_n_text',
        3 => 'sharethis',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'post_date' => 'ds_content',
      'field_elife_n_text' => 'ds_content',
      'sharethis' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        'news-teaser' => 'news-teaser',
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
  $export['node|elife_news_article|teaser'] = $ds_layout;

  return $export;
}
