<?php
/**
 * @file
 * elife_front_matter.entityqueue_default.inc
 */

/**
 * Implements hook_entityqueue_default_queues().
 */
function elife_front_matter_entityqueue_default_queues() {
  $export = array();

  $queue = new EntityQueue();
  $queue->disabled = FALSE; /* Edit this to true to make a default queue disabled initially */
  $queue->api_version = 1;
  $queue->name = 'elife_cover';
  $queue->label = 'eLife: Cover';
  $queue->language = 'en';
  $queue->handler = 'simple';
  $queue->target_type = 'node';
  $queue->settings = array(
    'target_bundles' => array(
      'elife_cover' => 'elife_cover',
    ),
    'min_size' => '0',
    'max_size' => '3',
    'act_as_queue' => 1,
  );
  $export['elife_cover'] = $queue;

  $queue = new EntityQueue();
  $queue->disabled = FALSE; /* Edit this to true to make a default queue disabled initially */
  $queue->api_version = 1;
  $queue->name = 'elife_cover_preview';
  $queue->label = 'eLife: Cover (Preview)';
  $queue->language = 'en';
  $queue->handler = 'simple';
  $queue->target_type = 'node';
  $queue->settings = array(
    'target_bundles' => array(
      'elife_cover' => 'elife_cover',
    ),
    'min_size' => '0',
    'max_size' => '0',
    'act_as_queue' => 0,
  );
  $export['elife_cover_preview'] = $queue;

  $queue = new EntityQueue();
  $queue->disabled = FALSE; /* Edit this to true to make a default queue disabled initially */
  $queue->api_version = 1;
  $queue->name = 'elife_front_matter_col_1';
  $queue->label = 'eLife: Front Matter (Column 1)';
  $queue->language = 'en';
  $queue->handler = 'simple';
  $queue->target_type = 'node';
  $queue->settings = array(
    'target_bundles' => array(
      'elife_front_matter' => 'elife_front_matter',
    ),
    'min_size' => '0',
    'max_size' => '6',
    'act_as_queue' => 1,
  );
  $export['elife_front_matter_col_1'] = $queue;

  $queue = new EntityQueue();
  $queue->disabled = FALSE; /* Edit this to true to make a default queue disabled initially */
  $queue->api_version = 1;
  $queue->name = 'elife_front_matter_col_2';
  $queue->label = 'eLife: Front Matter (Column 2)';
  $queue->language = 'en';
  $queue->handler = 'simple';
  $queue->target_type = 'node';
  $queue->settings = array(
    'target_bundles' => array(
      'elife_front_matter' => 'elife_front_matter',
    ),
    'min_size' => '0',
    'max_size' => '6',
    'act_as_queue' => 1,
  );
  $export['elife_front_matter_col_2'] = $queue;

  $queue = new EntityQueue();
  $queue->disabled = FALSE; /* Edit this to true to make a default queue disabled initially */
  $queue->api_version = 1;
  $queue->name = 'elife_front_matter_preview_col_1';
  $queue->label = 'eLife: Front Matter (Preview Column 1)';
  $queue->language = 'en';
  $queue->handler = 'simple';
  $queue->target_type = 'node';
  $queue->settings = array(
    'target_bundles' => array(
      'elife_front_matter' => 'elife_front_matter',
    ),
    'min_size' => '0',
    'max_size' => '0',
    'act_as_queue' => 0,
  );
  $export['elife_front_matter_preview_col_1'] = $queue;

  $queue = new EntityQueue();
  $queue->disabled = FALSE; /* Edit this to true to make a default queue disabled initially */
  $queue->api_version = 1;
  $queue->name = 'elife_front_matter_preview_col_2';
  $queue->label = 'eLife: Front Matter (Preview Column 2)';
  $queue->language = 'en';
  $queue->handler = 'simple';
  $queue->target_type = 'node';
  $queue->settings = array(
    'target_bundles' => array(
      'elife_front_matter' => 'elife_front_matter',
    ),
    'min_size' => '0',
    'max_size' => '0',
    'act_as_queue' => 1,
  );
  $export['elife_front_matter_preview_col_2'] = $queue;

  return $export;
}
