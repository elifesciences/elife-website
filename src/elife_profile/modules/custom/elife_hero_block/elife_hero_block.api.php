<?php
/**
 * @file
 * Hooks provided by the eLife: Hero Block module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Alter the hero block content.
 *
 * @param string $content
 *   Hero block content.
 */
function hook_elife_hero_block_alter(&$content) {
  if (empty($content)) {
    $content = '<p>Hello, world!';
  }
}

/**
 * @} End of "addtogroup hooks".
 */
