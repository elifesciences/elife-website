<?php
/**
 * @file
 * elife_footer.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function elife_footer_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'elife_footer';
  $context->description = 'eLife: Footer';
  $context->tag = '';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'elife_footer-elife_footer' => array(
          'module' => 'elife_footer',
          'delta' => 'elife_footer',
          'region' => 'footer_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('eLife: Footer');
  $export['elife_footer'] = $context;

  return $export;
}
