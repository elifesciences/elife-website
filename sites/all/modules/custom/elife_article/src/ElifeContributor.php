<?php

/**
 * @file
 * Contains \Drupal\elife_article\ElifeContributor.
 */

namespace Drupal\elife_article;

use EntityFieldQuery;

class ElifeContributor {

  public static function fromId($id, $parent_nid, $load = FALSE) {
    $id_query = new EntityFieldQuery();
    $id_query = $id_query
      ->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'elife_contributor')
      ->fieldCondition('field_elife_a_author_id', 'value', $id, '=')
      ->fieldCondition('field_elife_a_parent', 'target_id', $parent_nid);

    $ids = $id_query
      ->execute();

    if (empty($ids['node'])) {
      return FALSE;
    }
    else {
      $nids = array_keys($ids['node']);

      if ($load) {
        $nodes = node_load_multiple($nids);
          return array_shift($nodes);
      }
      else {
        return array_shift($nids);
      }
    }
  }

}