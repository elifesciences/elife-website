<?php
/**
 * @file
 * plugins/content_types/elife_coverpage_nav.inc
 */

$plugin = array(
  'title' => t('Home - Navigation Area'),
  'single' => TRUE,
  'category' => array('eLife'),
  'edit form' => 'elife_homepage_nav_edit',
  'render callback' => 'elife_homepage_nav_render',
);

/**
 * Compare two objects by their property 'name' for sorting.
 *
 * @param object $obja
 *   object a for comparison
 * @param object $objb
 *   object b for comparison
 *
 * @return int
 *   integer to indicate the status of comparison
 */
function _elife_homepage_termcomp($obja, $objb) {
  if ($obja->name == $objb->name) {
    return 0;
  }
  return ($obja->name < $objb->name) ? -1 : 1;
}

/**
 * Run-time rendering of the body of the block (content type).
 *
 * @see ctools_plugin_examples()
 */
function _elife_homepage_subjects() {
  $vocab = taxonomy_vocabulary_machine_name_load('elife_headings');

  $terms = taxonomy_get_tree($vocab->vid);

  $ol_classes = array('class' => array('home-subject-listing__list'));
  $li_classes = array('home-subject-listing__list_item');
  $a_classes = array('class' => array('home-subject-listing__link'));

  // Repro project wants a fake 'Cancer Biology' entry.
  $cellbio_term = new stdClass();
  $cellbio_term->tid = '0';
  $cellbio_term->name = 'Cancer biology';
  $cellbio_term->link = 'collections/reproducibility-project-cancer-biology';
  $terms[] = $cellbio_term;

  // Repro items are not wanted in the homepage nav list.
  $hidden_terms = array(
    'Replication study',
    'Registered report',
  );

  // Sort by name.
  uasort($terms, '_elife_homepage_termcomp');

  // Make into renderable array.
  $items = array();
  foreach ($terms as $term) {
    if (!in_array($term->name, $hidden_terms)) {
      if (!empty($term->link)) {
        $link = $term->link;
      }
      else {
        $link = 'taxonomy/term/' . $term->tid;
      }

      $items[] = array(
        'data' => l($term->name, $link, array('attributes' => $a_classes)),
        'class' => $li_classes,
      );
    }
  }

  // Provide renderable list for them.
  $render = array(
    'heading' => array(
      '#markup' => '<h3 class="home-subject-listing__heading">' . t('Subjects') . '</h3>',
    ),
    'list' => array(
      '#theme' => 'item_list',
      '#type' => 'ol',
      '#items' => $items,
      '#attributes' => $ol_classes,
    ),
  );
  return $render;
}

/**
 * Run-time rendering of the body of the block (content type).
 *
 * @see ctools_plugin_examples()
 */
function elife_homepage_nav_render($subtype, $conf, $args, $context) {

  // Get renderable arrays for the two elements needed in the nav:
  // the archive links and the subject headings.
  $s = _elife_homepage_subjects();
  $a = _elife_archive_short();

  // Make a new Block with a list whose elements are the two elements above.
  $block = new stdClass();
  $block->content = array(
    'list' => array(
      '#theme' => 'item_list',
      '#type' => 'ul',
      '#items' => array(
        // #item_list can't cope with render arrays included
        // so render them beforehand.
        // @see http://drupal.org/node/891112
        array('data' => render($s), 'class' => array('home-subject-listing')),
        array('data' => render($a), 'class' => array('home-archive-listing')),
      ),
    ),
  );

  return $block;
}

/**
 * Edit form callback for the content type.
 */
function elife_homepage_nav_edit($form, &$form_state) {
  return $form;
}

/**
 * Edit form callback for the content type.
 */
function elife_homepage_nav_edit_form_submit(&$form, &$form_state) {
  // Nothing.
}
