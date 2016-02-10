<?php
/**
 * @file
 * Hooks provided by the eLife: Custom XML Sitemap Links module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Provide custom links for the XML sitemap.
 */
function hook_elife_xmlsitemap_custom_links() {
  return [
    'my_module' => [
      'my/path',
    ],
  ];
}

/**
 * @} End of "addtogroup hooks".
 */
