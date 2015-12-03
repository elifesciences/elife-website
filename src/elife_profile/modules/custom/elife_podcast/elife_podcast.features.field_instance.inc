<?php
/**
 * @file
 * elife_podcast.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function elife_podcast_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-elife_podcast-field_elife_p_chapters'.
  $field_instances['node-elife_podcast-field_elife_p_chapters'] = array(
    'bundle' => 'elife_podcast',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 2,
      ),
      'elife_teaser_compact' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_elife_p_chapters',
    'label' => 'Chapters',
    'required' => 1,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'inline_entity_form',
      'settings' => array(
        'fields' => array(),
        'label_help_description' => '',
        'type_settings' => array(
          'allow_existing' => 0,
          'allow_new' => 1,
          'delete_references' => 1,
          'label_plural' => 'chapters',
          'label_singular' => 'chapter',
          'match_operator' => 'CONTAINS',
          'override_labels' => 1,
        ),
      ),
      'type' => 'inline_entity_form',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'node-elife_podcast-field_elife_p_episode_number'.
  $field_instances['node-elife_podcast-field_elife_p_episode_number'] = array(
    'bundle' => 'elife_podcast',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 0,
      ),
      'elife_teaser_compact' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_elife_p_episode_number',
    'label' => 'Episode number',
    'required' => 1,
    'settings' => array(
      'max' => '',
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(
        'label_help_description' => '<p>This is the episode number of the podcast. It should be sequential, and must be unique.</p>',
      ),
      'type' => 'number',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'node-elife_podcast-field_elife_p_image'.
  $field_instances['node-elife_podcast-field_elife_p_image'] = array(
    'bundle' => 'elife_podcast',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'class' => '',
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 4,
      ),
      'elife_teaser_compact' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'class' => 'podcast-teaser__image',
          'image_link' => 'content',
          'image_style' => 'elife_hero_block_teaser',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_elife_p_image',
    'label' => 'Thumbnail',
    'required' => 1,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'podcast',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'caption_from_title' => 1,
        'insert' => 0,
        'insert_absolute' => 0,
        'insert_class' => '',
        'insert_default' => 'auto',
        'insert_styles' => array(
          'auto' => 'auto',
          'colorbox__elife_cover' => 0,
          'colorbox__elife_cover_mcr' => 0,
          'colorbox__elife_cover_sml' => 0,
          'colorbox__elife_front_matter' => 0,
          'colorbox__elife_hero_block' => 0,
          'colorbox__elife_hero_block_teaser' => 0,
          'colorbox__elife_person_profile' => 0,
          'colorbox__elife_person_square' => 0,
          'colorbox__elife_striking_image' => 0,
          'colorbox__focal_point_preview' => 0,
          'colorbox__large' => 0,
          'colorbox__medium' => 0,
          'colorbox__thumbnail' => 0,
          'icon_link' => 0,
          'image' => 0,
          'image_elife_cover' => 0,
          'image_elife_cover_mcr' => 0,
          'image_elife_cover_sml' => 0,
          'image_elife_front_matter' => 0,
          'image_elife_hero_block' => 0,
          'image_elife_hero_block_teaser' => 0,
          'image_elife_person_profile' => 0,
          'image_elife_person_square' => 0,
          'image_elife_striking_image' => 0,
          'image_focal_point_preview' => 0,
          'image_large' => 0,
          'image_medium' => 0,
          'image_thumbnail' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'label_help_description' => '<p>This image appears on the list of podcasts page. It will be shrunk and cropped to be a square.</p>',
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-elife_podcast-field_elife_p_text'.
  $field_instances['node-elife_podcast-field_elife_p_text'] = array(
    'bundle' => 'elife_podcast',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
      'elife_teaser_compact' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_elife_p_text',
    'label' => 'Introduction',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'elife_full_html' => 'elife_full_html',
          'plain_text' => 0,
        ),
        'allowed_formats_toggle' => 1,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'elife_full_html' => array(
              'weight' => 0,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'label_help_description' => '<p>This describes the contents on the podcast. It will appear on the podcast\'s page, as well as the list of podcasts page.</p>',
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-elife_podcast-field_elife_p_title'.
  $field_instances['node-elife_podcast-field_elife_p_title'] = array(
    'bundle' => 'elife_podcast',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<p>Example titles:</p>

<ul>
<li>Plants keep Thyme, cancer drug resistance and clear corneas</li>
<li>Multicellular life, potato blight and Hepatitis B</li>
<li>Undead Cells</li>
</ul>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'elife_teaser_compact' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_elife_p_title',
    'label' => 'Title',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'label_help_description' => '<p>This the title of the podcast. It should be reasonably short, and cover (at least) the main subjects covered.</p>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-elife_podcast-field_elife_p_url'.
  $field_instances['node-elife_podcast-field_elife_p_url'] = array(
    'bundle' => 'elife_podcast',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 3,
      ),
      'elife_teaser_compact' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_elife_p_url',
    'label' => 'MP3 URL',
    'required' => 1,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(
        'label_help_description' => '<p>This is the URL of the podcast MP3 file on The Naked Scientists website.</p>',
      ),
      'type' => 'link_field',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'node-elife_podcast_chapter-field_elife_pc_podcast'.
  $field_instances['node-elife_podcast_chapter-field_elife_pc_podcast'] = array(
    'bundle' => 'elife_podcast_chapter',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => -1,
      ),
      'elife_teaser_compact' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_elife_pc_podcast',
    'label' => 'Podcast',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'label_help_description' => '',
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => -1,
    ),
  );

  // Exported field_instance:
  // 'node-elife_podcast_chapter-field_elife_pc_subject'.
  $field_instances['node-elife_podcast_chapter-field_elife_pc_subject'] = array(
    'bundle' => 'elife_podcast_chapter',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<p>This is the list of articles or collections that are discussed in the chapter. You can search by their title or DOI.</p>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 2,
      ),
      'elife_teaser_compact' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_elife_pc_subject',
    'label' => 'Subjects',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'label_help_description' => '',
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-elife_podcast_chapter-field_elife_pc_text'.
  $field_instances['node-elife_podcast_chapter-field_elife_pc_text'] = array(
    'bundle' => 'elife_podcast_chapter',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<p>Example descriptions:</p>

<ul>
<li>How do salamanders survive repeated amputation of their limbs?</li>
<li>Covalent bonds help bacteria stick to tissue.</li>
<li>What causes tinnitus and hyperacusis?</li>
</ul>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'elife_teaser_compact' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_elife_pc_text',
    'label' => 'Description',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'label_help_description' => '<p>This is a sentence that describes the subject discussed in the chapter.</p>',
        'size' => 100,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'node-elife_podcast_chapter-field_elife_pc_text_inverse'.
  $field_instances['node-elife_podcast_chapter-field_elife_pc_text_inverse'] = array(
    'bundle' => 'elife_podcast_chapter',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<p>It should roughly take the format &lsquo;<i>Some Person</i> talks about <i>some subject</i> in episode <i>x</i> of the eLife Podcast&rsquo;.</p>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'elife_teaser_compact' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_elife_pc_text_inverse',
    'label' => 'Sidebar text',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'label_help_description' => '<p>This, if filled in, will appear on the subjects of this chapter. Keep it short, as it will be a link in the sidebar.</p>',
        'size' => 100,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-elife_podcast_chapter-field_elife_pc_title'.
  $field_instances['node-elife_podcast_chapter-field_elife_pc_title'] = array(
    'bundle' => 'elife_podcast_chapter',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<p>Example titles:</p>

<ul>
<li>Listen up!</li>
<li>It takes two</li>
<li>Chemical harpoons</li>
</ul>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'elife_teaser_compact' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_elife_pc_title',
    'label' => 'Title',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'label_help_description' => '<p>This should be a couple of words that describes the chapter.</p>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('<p>Example descriptions:</p>

<ul>
<li>How do salamanders survive repeated amputation of their limbs?</li>
<li>Covalent bonds help bacteria stick to tissue.</li>
<li>What causes tinnitus and hyperacusis?</li>
</ul>');
  t('<p>Example titles:</p>

<ul>
<li>Listen up!</li>
<li>It takes two</li>
<li>Chemical harpoons</li>
</ul>');
  t('<p>Example titles:</p>

<ul>
<li>Plants keep Thyme, cancer drug resistance and clear corneas</li>
<li>Multicellular life, potato blight and Hepatitis B</li>
<li>Undead Cells</li>
</ul>');
  t('<p>It should roughly take the format &lsquo;<i>Some Person</i> talks about <i>some subject</i> in episode <i>x</i> of the eLife Podcast&rsquo;.</p>');
  t('<p>This is the list of articles or collections that are discussed in the chapter. You can search by their title or DOI.</p>');
  t('Chapters');
  t('Description');
  t('Episode number');
  t('Introduction');
  t('MP3 URL');
  t('Podcast');
  t('Sidebar text');
  t('Subjects');
  t('Thumbnail');
  t('Title');

  return $field_instances;
}
