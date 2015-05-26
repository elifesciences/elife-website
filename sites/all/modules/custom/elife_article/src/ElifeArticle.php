<?php

/**
 * @file
 * Contains \Drupal\elife_article\ElifeArticle.
 */

namespace Drupal\elife_article;

use EntityFieldQuery;
use EntityDrupalWrapper;
use RelationQuery;

class ElifeArticle {

  const DOI_PREFIX = '10.7554/eLife.';

  /**
   * Verify that the article version id string is unique.
   *
   * @param string $article_version_id
   * @param string $bundle
   * @return bool
   */
  public static function uniqueArticleVersionId($article_version_id, $bundle = 'elife_article') {
    $nid = self::fromIdentifier($article_version_id, FALSE, $bundle);

    if (!empty($nid)) {
      return FALSE;
    }

    return TRUE;
  }

  /**
   * Get poa from doi.
   *
   * This will not return the POA for articles that are now VOR.
   *
   * @param string $doi
   * @param bool $load
   * @param int $limit
   * @return bool|mixed
   */
  public static function poaFromDoi($doi, $load = TRUE, $limit = 1) {
    $conditions = array(
      'field_elife_a_status' => 'POA',
    );

    return self::fromId($doi, $load, 'elife_article', $conditions, $limit, 'field_elife_a_doi');
  }

  /**
   * Get the vor from the doi.
   *
   * @param string $doi
   * @param bool $load
   * @return bool|mixed
   */
  public static function vorFromDoi($doi, $load = TRUE) {
    $conditions = array(
      'field_elife_a_status' => 'VOR',
    );

    return self::fromId($doi, $load, 'elife_article', $conditions, 1, 'field_elife_a_doi');
  }

  /**
   * Get poa from article id.
   *
   * This will not return the POA for articles that are now VOR.
   *
   * @param string $article_id
   * @param bool $load
   * @param int $limit
   * @return bool|mixed
   */
  public static function poaFromId($article_id, $load = TRUE, $limit = 1) {
    $conditions = array(
      'field_elife_a_status' => 'POA',
    );

    return self::fromId($article_id, $load, 'elife_article', $conditions, $limit);
  }

  /**
   * Get the vor from the article id.
   *
   * @param string $article_id
   * @param bool $load
   * @return bool|mixed
   */
  public static function vorFromId($article_id, $load = TRUE) {
    $conditions = array(
      'field_elife_a_status' => 'VOR',
    );

    return self::fromId($article_id, $load, 'elife_article', $conditions, 1);
  }

  /**
   * Retrieve the article node or node id from the article id.
   *
   * @param string $article_id
   * @param bool $load
   * @param string $bundle
   * @param array $conditions
   * @param int $limit
   * @param string $id_field
   * @return bool|mixed
   */
  public static function fromId($article_id, $load = TRUE, $bundle = 'elife_article', $conditions = array(), $limit = 0, $id_field = 'field_elife_a_article_id') {
    $id_query = new EntityFieldQuery();
    $id_query = $id_query
      ->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', $bundle)
      ->fieldCondition($id_field, 'value', $article_id, '=')
      ->fieldOrderBy('field_elife_a_status', 'value', 'DESC')
      ->fieldOrderBy('field_elife_a_version', 'value', 'DESC')
      ->fieldOrderBy('field_elife_a_fpubdate', 'value', 'DESC');

    if (!empty($conditions)) {
      foreach ($conditions as $field => $value) {
        $column = 'value';
        $operator = '=';
        if (is_array($value)) {
          $assert = $value[0];

          if (!empty($value[1])) {
            $column = $value[1];
          }
          if (!empty($value[2])) {
            $operator = $value[2];
          }
        }
        else {
          $assert = $value;
        }
        $id_query = $id_query
          ->fieldCondition($field, $column, $assert, $operator);
      }
    }

    if (!empty($limit)) {
      $id_query = $id_query
        ->range(0, $limit);
    }

    $ids = $id_query
      ->execute();

    if (empty($ids['node'])) {
      return FALSE;
    }
    else {
      $nids = array_keys($ids['node']);

      if ($load) {
        $nodes = node_load_multiple($nids);
        if ($limit === 1) {
          return array_shift($nodes);
        }
        else {
          return $nodes;
        }
      }
      elseif ($limit === 1) {
        return array_shift($nids);
      }
      else {
        return $nids;
      }
    }
  }

  /**
   * Retrieve the article node or node id from the id (default is article version id).
   *
   * @param string $id
   * @param bool $load
   * @param string $bundle
   * @param int $limit
   * @param string $id_field
   * @return bool|mixed
   */
  public static function fromIdentifier($id, $load = TRUE, $bundle = 'elife_article', $limit = 1, $id_field = 'field_elife_a_article_version_id') {
    $id_query = new EntityFieldQuery();
    $id_query = $id_query
      ->entityCondition('entity_type', 'node')
      ->fieldCondition($id_field, 'value', $id, '=');

    if (!empty($bundle)) {
      $id_query = $id_query
        ->entityCondition('bundle', $bundle);
    }

    if (!empty($limit)) {
      $id_query = $id_query
        ->range(0, $limit);
    }

    $ids = $id_query
      ->execute();

    if (empty($ids['node'])) {
      return FALSE;
    }
    else {
      $nids = array_keys($ids['node']);

      if ($load) {
        $nodes = node_load_multiple($nids);
        if ($limit === 1) {
          return array_shift($nodes);
        }
        else {
          return $nodes;
        }
      }
      elseif ($limit === 1) {
        return array_shift($nids);
      }
      else {
        return $nids;
      }
    }
  }

  /**
   * Get path for supplied article version id.
   *
   * @param string $article_version_id
   * @return string
   */
  public static function getPath($article_version_id) {
    $article_nid = self::fromIdentifier($article_version_id, FALSE);
    return drupal_get_path_alias('node/' . $article_nid);
  }

  /**
   * Get categories for supplied article version id.
   *
   * @param string $article_version_id
   * @return string
   */
  public static function getCategories($article_version_id) {
    $article = self::fromIdentifier($article_version_id);
    $categories = array();

    /* @var EntityDrupalWrapper $ewrapper */
    if ($ewrapper = entity_metadata_wrapper('node', $article)) {
      /* @var EntityDrupalWrapper $category */
      foreach ($ewrapper->field_elife_a_category as $category) {
        $categories[$category->field_elife_category_type->value()][] = $category->name->value();
      }
    }

    return $categories;
  }

  /**
   * Get keywords for supplied article version id.
   *
   * @param string $article_version_id
   * @return string
   */
  public static function getKeywords($article_version_id) {
    $article = self::fromIdentifier($article_version_id);
    $keywords = array();

    /* @var EntityDrupalWrapper $ewrapper */
    if ($ewrapper = entity_metadata_wrapper('node', $article)) {
      /* @var EntityDrupalWrapper $keyword */
      foreach ($ewrapper->field_elife_a_keyword as $keyword) {
        $value = $keyword->field_elife_a_full_title->value();
        $keywords[$keyword->field_elife_a_kwd_type->value()][] = $value['value'];
      }
    }

    return $keywords;
  }

  /**
   * Validate the doi string.
   *
   * @param string $doi
   * @return bool
   */
  public static function validateDoi($doi) {
    $pattern = '/^' . preg_quote(self::DOI_PREFIX, '/') . '[0-9]{5}(\.[0-9]+)?$/';
    $match = preg_match($pattern, $doi);
    if (empty($match)) {
      return FALSE;
    }

    return TRUE;
  }

  /**
   * Clean the title.
   *
   * @param string $title
   * @return string
   */
  public static function cleanTitle($title) {
    $title = self::unicodeFix($title, 'replace');

    $title = trim($title);
    $title = strip_tags($title);
    $title = htmlspecialchars_decode($title);

    $title = str_replace("\n", ' ', $title);
    $title = str_replace("  ", ' ', $title);

    if (mb_strlen($title) > 255) {
      //TODO: Trim on word boundary
      $title = mb_substr($title, 0, 254) . '…';
    }
    return $title;
  }

  /**
   * Evaluates whether a string needs unicode replacement.
   *
   * This is useful for drupal titles, which can't store html.
   *
   * Some titles have 4 byte unicode chars. Need to make sure those get removed
   * because the load will crash because the title field encoding is utf8. For a
   * thorough explanation see below link.
   *
   * @see https://drupal.org/node/1314214
   * @see http://magp.ie/2011/01/06/remove-non-utf8-characters-from-string-with-php/
   *
   * @param string $string
   *   the text to evaluate
   * @param string $action
   *   whether to return a replaced string or just check if needed
   *
   * @return boolean/string
   *   returns either TRUE/FALSE on 'check' or modified string on 'replace'
   */
  public static function unicodeFix($string, $action = 'replace') {
    switch ($action) {
      case 'check':
        // Check for overly long 2 byte sequences, as well as characters above
        // U+10000 and replace with ?.
        $two_byte = preg_match('/[\x00-\x08\x10\x0B\x0C\x0E-\x19\x7F]' .
          '|[\x00-\x7F][\x80-\xBF]+' .
          '|([\xC0\xC1]|[\xF0-\xFF])[\x80-\xBF]*' .
          '|[\xC2-\xDF]((?![\x80-\xBF])|[\x80-\xBF]{2,})' .
          '|[\xE0-\xEF](([\x80-\xBF](?![\x80-\xBF]))|(?![\x80-\xBF]{2})|[\x80-\xBF]{3,})/S',
          $string);

        // Reject overly long 3 byte sequences and UTF-16 surrogates and replace
        // with ?.
        $three_byte = preg_match('/\xE0[\x80-\x9F][\x80-\xBF]' .
          '|\xED[\xA0-\xBF][\x80-\xBF]/S', '?', $string);

        $has_replacement = FALSE;
        if ($two_byte == 1 || $three_byte == 1) {
          $has_replacement = TRUE;
        }
        return $has_replacement;

      case 'replace':
        // Reject overly long 2 byte sequences, as well as characters above
        // U+10000 and replace with ?.
        $string = preg_replace('/[\x00-\x08\x10\x0B\x0C\x0E-\x19\x7F]' .
          '|[\x00-\x7F][\x80-\xBF]+' .
          '|([\xC0\xC1]|[\xF0-\xFF])[\x80-\xBF]*' .
          '|[\xC2-\xDF]((?![\x80-\xBF])|[\x80-\xBF]{2,})' .
          '|[\xE0-\xEF](([\x80-\xBF](?![\x80-\xBF]))|(?![\x80-\xBF]{2})|[\x80-\xBF]{3,})/S',
          '?', $string);

        // Reject overly long 3 byte sequences and UTF-16 surrogates and replace
        // with ?.
        $string = preg_replace('/\xE0[\x80-\x9F][\x80-\xBF]' .
          '|\xED[\xA0-\xBF][\x80-\xBF]/S', '?', $string);

        return $string;
    }
  }

  /**
   * Delete the stored values for related articles.
   *
   * @param $source_nid
   * @param int $index
   * @param int $dest_nid
   */
  public static function removeRelated($source_nid, $index = 0, $dest_nid = NULL) {
    $relations = self::relatedArticles($source_nid, $index, NULL, FALSE, $dest_nid);
    $rel_query = new RelationQuery('node', $source_nid, $index);
    if ($dest_nid) {
      $rel_query = $rel_query->related('node', $dest_nid);
    }
    $rel_query->entityCondition('bundle', 'elife_relation');
    $relations = $rel_query->execute();
    if (!empty($relations)) {
      relation_delete_multiple(array_keys($relations));
    }
  }

  /**
   * Retrieve the related articles.
   *
   * @param $source_nid
   * @param null $index
   * @param null $relation_type
   * @param bool $load
   * @return array
   */
  public static function relatedArticles($source_nid, $index = NULL, $relation_type = NULL, $load = FALSE) {
    $rel_query = new RelationQuery('node', $source_nid, $index);
    $rel_query->entityCondition('bundle', 'elife_relation');
    if ($relation_type) {
      $rel_query->fieldCondition('field_elife_r_type', 'value', $relation_type);
    }
    $results = $rel_query->execute();
    if (!empty($results)) {
      $relations = relation_load_multiple(array_keys($results));
      $excludes = array(
        $source_nid,
      );
      $related_nids = array();
      foreach ($relations as $rid => $relation) {
        if (!empty($relation->endpoints)) {
          foreach ($relation->endpoints[LANGUAGE_NONE] as $i => $item) {
            if (!in_array($item['entity_id'], $excludes)) {
              $related_nids[$item['entity_id']] = array(
                'index' => $i,
                'type' => (!empty($relation->field_elife_r_type)) ? $relation->field_elife_r_type[LANGUAGE_NONE][0]['value'] : NULL,
              );
              if ($load) {
                $related_nids[$item['entity_id']]['data'] = node_load($item['entity_id']);
              }
            }
          }
        }
      }
      return $related_nids;
    }
  }

  public static function getReferences($article_nid, $type = NULL, $key = NULL, $load = FALSE) {
    $results = array();
    $field_basic_ref = 'field_elife_a_basic_ref';
    $query = db_select('field_collection_item', 'fci');
    $query->fields('fci', array('item_id'));
    $query->innerJoin('field_data_' . $field_basic_ref, 'br', 'br.' . $field_basic_ref . '_value = fci.item_id');
    $query->condition('br.entity_id', $article_nid);
    if ($type) {
      $query->innerJoin('field_data_' . $field_basic_ref . '_type', 'brt', 'brt.entity_id = fci.item_id');
      $query->condition('brt.' . $field_basic_ref . '_type_value', $type);
    }
    if ($key) {
      $query->innerJoin('field_data_' . $field_basic_ref . '_key', 'brk', 'brk.entity_id = fci.item_id');
      $query->condition('brk.' . $field_basic_ref . '_key_value', $key);
    }

    $result = $query->execute()->fetchCol();
    if (!empty($result)) {
      if ($load) {
        $result = field_collection_item_load_multiple($result);
      }
      $results['basic'] = $result;
    }

    return $results;
  }
}
