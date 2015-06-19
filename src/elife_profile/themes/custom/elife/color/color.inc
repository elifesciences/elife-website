<?php
/**
 * @file
 * Color
 *
 * Copyright (c) 2010-2011 Board of Trustees, Leland Stanford Jr. University
 * This software is open-source licensed under the GNU Public License Version 2 or later
 * The full license is available in the LICENSE.TXT file at the root of this repository
 */
// Put the logo path into JavaScript for the live preview.
drupal_add_js(array('color' => array('logo' => theme_get_setting('logo', 'chromega'))), 'setting');

$info = array(
  // Available colors and color labels used in theme.
  'fields' => array(
    'base' => t('Base Color'),
    'top' => t('Header top'),
    'bottom' => t('Header bottom'),
    'bg' => t('Content background'),
    'sidebar' => t('Sidebar background'),
    'sidebarborders' => t('Sidebar borders'),
    'footer' => t('Footer background'),
    'titleslogan' => t('Title and slogan'),
    'text' => t('Text color'),
    'link' => t('Link color'),
  ),
  // Pre-defined color schemes.
  'schemes' => array(
    'default' => array(
      'title' => t('Midori (default)'),
      'colors' => array(
        'base' => '#376e6a',
        'top' => '#457b77',
        'bottom' => '#54bd89',
        'bg' => '#ffffff',
        'sidebar' => '#f1f4f0',
        'sidebarborders' => '#ededed',
        'footer' => '#1f1d1c',
        'titleslogan' => '#fffeff',
        'text' => '#3b3b3b',
        'link' => '#018471',
      ),
    ),
    'sunrise' => array(
      'title' => t('Sunrise'),
      'colors' => array(
        'base' => '#b15548',
        'top' => '#c6766b',
        'bottom' => '#e1b0a5',
        'bg' => '#ffffff',
        'sidebar' => '#f1e2da',
        'sidebarborders' => '#efd4c7',
        'footer' => '#3f453f',
        'titleslogan' => '#ffeab7',
        'text' => '#3b3b3b',
        'link' => '#efaf59',
      ),
    ),
  ),

  // CSS files (excluding @import) to rewrite with new color scheme.
  'css' => array(
    'css/colors.css',
  ),

  // Files to copy.
  'copy' => array(
    'logo.png',
  ),

  // Gradient definitions.
  'gradients' => array(
    array(
      // (x, y, width, height).
      'dimension' => array(0, 0, 0, 0),
      // Direction of gradient ('vertical' or 'horizontal').
      'direction' => 'vertical',
      // Keys of colors to use for the gradient.
      'colors' => array('top', 'bottom'),
    ),
  ),

  // Color areas to fill (x, y, width, height).
  'fill' => array(),

  // Coordinates of all the theme slices (x, y, width, height)
  // with their filename as used in the stylesheet.
  'slices' => array(),

  // Reference color used for blending. Matches the base.png's colors.
  'blend_target' => '#ffffff',

  // Preview files.
  'preview_css' => 'color/preview.css',
  'preview_js' => 'color/preview.js',
  'preview_html' => 'color/preview.html',

  // Base file for image generation.
  'base_image' => 'color/base.png',
);
