<?php

/**
 * @file
 * Contains \Drupal\elife_article\ElifeArticle.
 */

namespace Drupal\elife_article;

use EntityFieldQuery;
use EntityDrupalWrapper;
use EntityListWrapper;
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
   * @return array
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
   * @return array
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
   * Get article children for supplied article version id.
   *
   * @param string $article_version_id
   * @return array
   */
  public static function getArticleChildren($article_version_id) {
    $children = array();

    $fragments = self::getArticleFragments($article_version_id);
    if (!empty($fragments)) {
      $children['fragment'] = $fragments;
    }

    $subarticles = self::getArticleSubarticles($article_version_id);
    if (!empty($subarticles)) {
      $children['sub-article'] = $subarticles;
    }

    return $children;
  }

  /**
   * Get article fragments for supplied article version id.
   *
   * @param string $article_version_id
   * @return array
   */
  public static function getArticleFragments($article_version_id) {
    $article = self::fromIdentifier($article_version_id);
    $fragments = array();

    /* @var EntityDrupalWrapper $ewrapper */
    if ($ewrapper = entity_metadata_wrapper('node', $article)) {
      if ($ewrapper->field_elife_a_children->value()) {
        $fragments = self::getChildFragments($ewrapper->field_elife_a_children);
      }
    }

    return $fragments;
  }

  /**
   * Get sub articles for supplied article version id.
   *
   * @param string $article_version_id
   * @return array
   */
  public static function getArticleSubarticles($article_version_id) {
    $article = self::fromIdentifier($article_version_id);
    $subarticles = array();

    /* @var EntityDrupalWrapper $ewrapper */
    if ($ewrapper = entity_metadata_wrapper('node', $article)) {
      if ($ewrapper->field_elife_a_children->value()) {

        $field_prefix = 'field_elife_a';
        $mappings = array(
          'title' => 'title',
          'doi' => $field_prefix . '_doi',
        );
        /* @var EntityDrupalWrapper $sub_wrapper */
        foreach ($ewrapper->field_elife_a_children as $sub_wrapper) {
          if ($sub_wrapper->getBundle() == 'elife_article') {
            $subarticle = array();
            foreach ($mappings as $k => $field) {
              if ($value = $sub_wrapper->{$field}->value()) {
                $subarticle[$k] = $value;
              }
            }
            if ($path = drupal_get_path_alias('node/' . $sub_wrapper->nid->value())) {
              $subarticle['path'] = $path;
            }
            if ($sub_wrapper->field_elife_a_children->value()) {
              $subarticle['children']['fragment'] = self::getChildFragments($sub_wrapper->field_elife_a_children);
            }
            if ($sub_wrapper->field_elife_a_contributors->value()) {
              $subarticle['contributors'] = self::getChildContributors($sub_wrapper->field_elife_a_contributors);
            }
            if (!empty($subarticle)) {
              $subarticles[] = $subarticle;
            }
          }
        }
      }
    }

    return $subarticles;
  }

  /**
   * Get child fragments for supplied entity.
   *
   * @param EntityListWrapper $frag_list
   * @return array
   */
  public static function getChildFragments(EntityListWrapper $frag_list) {
    $fragments = array();

    $field_prefix = 'field_elife_a';
    $mappings = array(
      'type' => $field_prefix . '_frag_type',
      'title' => 'title',
      'doi' => $field_prefix . '_doi',
    );
    /* @var EntityDrupalWrapper $frag_wrapper */
    foreach ($frag_list as $frag_wrapper) {
      if ($frag_wrapper->getBundle() == 'elife_fragment') {
        $fragment = array();
        foreach ($mappings as $k => $field) {
          if ($value = $frag_wrapper->{$field}->value()) {
            $fragment[$k] = $value;
          }
        }
        if (isset($fragment['type']) && $value = $frag_wrapper->field_elife_a_sub_type->value()) {
          $fragment[$fragment['type'] . '-type'] = $value;
        }
        if ($path = drupal_get_path_alias('node/' . $frag_wrapper->nid->value())) {
          $fragment['path'] = $path;
        }
        if ($frag_wrapper->field_elife_a_children->value()) {
          $fragment['children']['fragment'] = self::getChildFragments($frag_wrapper->field_elife_a_children);
        }
        if (!empty($fragment)) {
          $fragments[] = $fragment;
        }
      }
    }

    return $fragments;
  }

  /**
   * Get contributors for supplied article version id.
   *
   * @param string $article_version_id
   * @return array
   */
  public static function getContributors($article_version_id) {
    $article = self::fromIdentifier($article_version_id);
    $contributors = array();

    /* @var EntityDrupalWrapper $ewrapper */
    if ($ewrapper = entity_metadata_wrapper('node', $article)) {
      if ($ewrapper->field_elife_a_contributors->value()) {
        $contributors = self::getChildContributors($ewrapper->field_elife_a_contributors);
      }
    }

    return $contributors;
  }

  /**
   * Get child fragments for supplied entity.
   *
   * @param EntityListWrapper $contrib_list
   * @return array
   */
  public static function getChildContributors(EntityListWrapper $contrib_list) {
    $contributors = array();
    $field_prefix = 'field_elife_a';
    $mappings = array(
      'type' => $field_prefix . '_contrib_type',
      'id' => $field_prefix . '_author_id',
      'surname' => $field_prefix . '_surname',
      'given-names' => $field_prefix . '_fnames',
      'suffix' => $field_prefix . '_author_suffix',
      'orcid' => $field_prefix . '_orcid_id',
      'role' => $field_prefix . '_author_role',
      'group-author-key' => $field_prefix . '_group_author_key',
      'collab' => $field_prefix . '_collab',
    );
    /* @var EntityDrupalWrapper $contrib_wrapper */
    foreach ($contrib_list as $contrib_wrapper) {
      $contributor = array();
      $references = array();
      foreach ($mappings as $k => $field) {
        if ($value = $contrib_wrapper->{$field}->value()) {
          $contributor[$k] = $value;
        }
      }

      if ($value = $contrib_wrapper->{$field_prefix . '_equal_contrib'}->value()) {
        if (!empty($value)) {
          $contributor['equal-contrib'] = 'yes';
        }
      }

      if ($value = $contrib_wrapper->{$field_prefix . '_corresp'}->value()) {
        if (!empty($value)) {
          $contributor['corresp'] = 'yes';
        }
      }

      if ($value = $contrib_wrapper->{$field_prefix . '_deceased'}->value()) {
        if (!empty($value)) {
          $contributor['deceased'] = 'yes';
        }
      }

      $types = array(
        'basic' => $field_prefix . '_basic_ref_type',
        'fund' => 'funding',
        'aff' => 'affiliation',
        'rel' => 'related-object',
      );
      foreach ($types as $k => $t) {
        $field = 'field_elife_a_' . $k . '_ref_links';
        $type = $t;
        /* @var EntityDrupalWrapper $fc_wrapper */
        foreach ($contrib_wrapper->{$field} as $fc_wrapper) {
          if ($k == 'basic') {
            $type = $fc_wrapper->{$t}->value();
          }
          $references[$type][] = $fc_wrapper->field_elife_a_ref_key->value();
        }
      }
      $aff_mappings = array(
        'affiliation' => array(
          'dept' => $field_prefix . '_aff_dept',
          'institution' => $field_prefix . '_aff_inst',
          'city' => $field_prefix . '_aff_city',
          'country' => $field_prefix . '_aff_country',
        ),
      );
      foreach ($aff_mappings as $group => $fields) {
        foreach ($fields as $k => $field) {
          if ($value = $contrib_wrapper->{$field}->value()) {
            $contributor[$group][$k] = $value;
          }
        }
      }
      if (!empty($contributor)) {
        if (!empty($references)) {
          $contributor['references'] = $references;
        }
        $contributors[] = $contributor;
      }
    }

    return $contributors;
  }

  /**
   * Get contributor references for supplied article version id.
   *
   * @param string $article_version_id
   * @return array
   */
  public static function getContributorReferences($article_version_id) {
    $article = self::fromIdentifier($article_version_id);
    $references = array();

    /* @var EntityDrupalWrapper $ewrapper */
    if ($ewrapper = entity_metadata_wrapper('node', $article)) {
      $field_ref_key = 'field_elife_a_ref_key';

      $field_basic_ref = 'field_elife_a_basic_ref';
      /* @var EntityDrupalWrapper $fc_wrapper */
      foreach ($ewrapper->{$field_basic_ref} as $fc_wrapper) {
        $key = $fc_wrapper->{$field_ref_key}->value();
        $references[$fc_wrapper->{$field_basic_ref . '_type'}->value()][$key] = $fc_wrapper->{$field_basic_ref . '_value'}->value();
      }

      $field_fund_ref = 'field_elife_a_fund_ref';
      $type = 'funding';
      $mappings = array(
        'id' => $field_fund_ref . '_id',
        'id-type' => $field_fund_ref . '_id_type',
        'institution' => $field_fund_ref . '_inst',
        'institution-type' => $field_fund_ref . '_inst_type',
        'award-id' => $field_fund_ref . '_award_id',
      );
      /* @var EntityDrupalWrapper $fc_wrapper */
      foreach ($ewrapper->{$field_fund_ref} as $fc_wrapper) {
        $key = $fc_wrapper->{$field_ref_key}->value();
        $references[$type][$key] = array();
        foreach ($mappings as $k => $field) {
          if ($value = $fc_wrapper->{$field}->value()) {
            $references[$type][$key][$k] = $value;
          }
        }
      }

      $field_aff_ref = 'field_elife_a_aff_ref';
      $type = 'affiliation';
      $mappings = array(
        'label' => $field_aff_ref . '_label',
        'dept' => $field_aff_ref . '_dept',
        'institution' => $field_aff_ref . '_inst',
        'city' => $field_aff_ref . '_city',
        'country' => $field_aff_ref . '_country',
      );
      /* @var EntityDrupalWrapper $fc_wrapper */
      foreach ($ewrapper->{$field_aff_ref} as $fc_wrapper) {
        $key = $fc_wrapper->{$field_ref_key}->value();
        $references[$type][$key] = array();
        foreach ($mappings as $k => $field) {
          if ($value = $fc_wrapper->{$field}->value()) {
            $references[$type][$key][$k] = $value;
          }
        }
      }

      $field_rel_ref = 'field_elife_a_rel_ref';
      $type = 'related-object';
      $mappings = array(
        'type' => $field_rel_ref . '_type',
        'source-id' => $field_rel_ref . '_src_id',
        'source-id-type' => $field_rel_ref . '_src_id_typ',
        'year' => $field_rel_ref . '_year',
        'source' => $field_rel_ref . '_src',
        'comment' => $field_rel_ref . '_comment',
      );
      /* @var EntityDrupalWrapper $fc_wrapper */
      foreach ($ewrapper->{$field_rel_ref} as $fc_wrapper) {
        $key = $fc_wrapper->{$field_ref_key}->value();
        $references[$type][$key] = array();
        foreach ($mappings as $k => $field) {
          if ($value = $fc_wrapper->{$field}->value()) {
            $references[$type][$key][$k] = $value;
          }
        }
      }
    }

    return $references;
  }

  /**
   * Get citations for supplied article version id.
   *
   * @param string $article_version_id
   * @return array
   */
  public static function getCitations($article_version_id) {
    $article = self::fromIdentifier($article_version_id);
    $citations = array();

    /* @var EntityDrupalWrapper $ewrapper */
    if ($ewrapper = entity_metadata_wrapper('node', $article)) {
      $field_citations = 'field_elife_a_citations';
      $field_cit_prefix = 'field_elife_a_cit';
      $mappings = array(
        'id' => $field_cit_prefix . '_id',
        'publication-type' => $field_cit_prefix . '_pub_type',
        'year' => $field_cit_prefix . '_year',
        'title' => $field_cit_prefix . '_title',
        'source' => $field_cit_prefix . '_source',
        'edition' => $field_cit_prefix . '_edition',
        'volume' => $field_cit_prefix . '_volume',
        'fpage' => $field_cit_prefix . '_fpage',
        'lpage' => $field_cit_prefix . '_lpage',
        'doi' => $field_cit_prefix . '_doi',
        'publisher-loc' => $field_cit_prefix . '_pub_loc',
        'publisher-name' => $field_cit_prefix . '_pub_name',
      );
      /* @var EntityDrupalWrapper $cit_wrapper */
      foreach ($ewrapper->{$field_citations} as $cit_wrapper) {
        $citation = array();
        foreach ($mappings as $k => $field) {
          if ($value = $cit_wrapper->{$field}->value()) {
            $citation[$k] = $value;
          }
        }

        $author_mappings = array(
          'group-type' => $field_cit_prefix . '_author_group',
          'name' => $field_cit_prefix . '_author_name',
        );
        // @todo - elife - nlisgo - this is taking too long!!
        /* @var EntityDrupalWrapper $fc_wrapper */
        foreach ($cit_wrapper->{$field_cit_prefix . '_authors'} as $fc_wrapper) {
          $author = array();
          foreach ($author_mappings as $k => $field) {
            if ($value = $fc_wrapper->{$field}->value()) {
              $author[$k] = $value;
            }
          }
          if (!empty($author)) {
            $citation['authors'][] = $author;
          }
        }
        if (!empty($citation['id'])) {
          $id = $citation['id'];
          unset($citation['id']);
          $citations[$id] = $citation;
        }
      }
    }

    return $citations;
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
}
