<?php
/**
 * @file
 * Hooks provided by the eLife: Body Field module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Map of content type machine name to replacement body field machine names.
 */
function hook_elife_body_field() {
  return ['my_content_type' => 'field_my_body'];
}

/**
 * Alter the content type machine name to replacement body field machine names
 * map.
 *
 * @param array $content
 *   Map of content type machine name to replacement body field machine names.
 */
function hook_elife_body_field_alter(&$content) {
  $content['my_content_type'] = 'field_my_body';
}

/**
 * @} End of "addtogroup hooks".
 */
