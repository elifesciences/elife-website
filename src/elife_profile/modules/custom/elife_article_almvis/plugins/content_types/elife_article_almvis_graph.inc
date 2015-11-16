<?php
/**
 * @file
 * Server-side render function for the block rendering the article pageviews graph.
 */

$plugin = array(
  'title' => t('Article Metrics - ALMVIS Graph'),
  'single' => TRUE,
  'category' => array('eLife'),
  'edit form' => 'elife_article_almvis_graph_edit',
  'render callback' => 'elife_article_almvis_graph_render',
  'required context' => new ctools_context_required('Article Node', 'node'),
);

/**
 * Run-time rendering of the body of the block (content type).
 *
 * This function injects the Javascript and CSS files needed to render
 * the graph as SVG objects, and returns an appropriately tagged but empty
 * div block to put it in.
 *
 * TODO: elife - rivimey - move away from using a CSS ID here
 */
function elife_article_almvis_graph_render($subtype, $conf, $args, $context) {
  $article_version = $context->data;
  $dto = elife_article_version_to_dto($article_version);

  $block = new stdClass();

  /*
   * Prepare some standard arrays for our drupal_add_ calls. We prefer JS in the
   * footer, and CSS in the default group.
   */
  $jsoptions = array();
  $cssoptions = array('group' => CSS_DEFAULT);
  $modpath = drupal_get_path('module', 'elife_article_almvis');
  $doi = $dto->getDoi();

  // Lets make sure we're getting what we want:
  $doi = lagotto_services_validate_doi($doi);
  if ($doi) {
    drupal_add_js($modpath . '/js/d3.v3.js', $jsoptions);
    drupal_add_js($modpath . '/almviz/js/bootstrap.tooltip.js', $jsoptions);
    drupal_add_js($modpath . '/almviz/alm.js', $jsoptions);
    drupal_add_js($modpath . '/plugins/content_types/elife_article_almvis_graph.js', $jsoptions);
    drupal_add_js(array('elifeArticleAlmvis' => array('dailyNDays' => (int) ELIFE_ARTICLE_ALMVIS_DAILYNDAYS)), 'setting');

    drupal_add_css($modpath . '/almviz/css/bootstrap.tooltip.css', $cssoptions);
    drupal_add_css($modpath . '/almviz/css/almviz.css', $cssoptions);

    $early_release = ($dto->getStatus() == 'VOR') ? 0 : 1;

    // This element is the anchor for the Javascript chart
    // The loading image is presented until the Javascript deletes it.
    $modulepath = drupal_get_path('module', 'elife_article_almvis');
    $block->content = '<div id="elife-article-almvis-chart" data-doi="' . $doi . '" data-pdf="TRUE" data-earlyarticle="' . $early_release . '">';
    $block->content .= '<img class="loading" src="' . base_path() . $modulepath . '/images/loading.gif"/>';
    $block->content .= '</div>';
  }
  else {
    $block->content = '';
  }

  return $block;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_almvis_graph_edit($form, &$form_state) {
  return $form;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_almvis_graph_edit_form_submit(&$form, &$form_state) {
  // Nothing.
}
