<?php

/**
 * @file
 * Contains \Drupal\elife_article\ElifeArticleVersion.
 */

namespace Drupal\elife_article;

use Database;
use EntityFieldQuery;
use EntityDrupalWrapper;
use EntityFieldQueryExtraFields;
use EntityListWrapper;
use RecursiveArrayIterator;
use RecursiveIteratorIterator;
use stdClass;

class ElifeArticleVersion {

  const DOI_PREFIX = '10.7554/eLife.';

  /**
   * Verify that the article version id string is unique.
   *
   * @param string $article_version_id
   *   Article version id.
   * @param string $bundle
   *   Bundle/content type.
   *
   * @return bool
   *   TRUE if unique.
   */
  public static function uniqueArticleVersionId($article_version_id, $bundle = 'elife_article_ver') {
    $nid = self::fromIdentifier($article_version_id, FALSE, $bundle);

    if (!empty($nid)) {
      return FALSE;
    }

    return TRUE;
  }

  /**
   * Get POA from DOI.
   *
   * This will not return the POA for articles that are now VOR.
   *
   * @param string $doi
   *   Article version DOI.
   * @param bool $load
   *   Flag set to TRUE if we wish to load the article data.
   * @param int $limit
   *   Limit the number of articles returned.
   *
   * @return bool|mixed
   *   Details of the articles that match criteria.
   */
  public static function poaFromDoi($doi, $load = TRUE, $limit = 1) {
    $conditions = array(
      'field_elife_a_status' => 'POA',
    );

    return self::fromId($doi, $load, 'elife_article_ver', $conditions, $limit, 'field_elife_a_doi');
  }

  /**
   * Get the VOR from the DOI.
   *
   * @param string $doi
   *   Article version DOI.
   * @param bool $load
   *   Flag set to TRUE if we wish to load the article data.
   *
   * @return bool|mixed
   *   Details of the articles that match criteria.
   */
  public static function vorFromDoi($doi, $load = TRUE) {
    $conditions = array(
      'field_elife_a_status' => 'VOR',
    );

    return self::fromId($doi, $load, 'elife_article_ver', $conditions, 1, 'field_elife_a_doi');
  }

  /**
   * Get the latest article version from the DOI.
   *
   * @param string $doi
   *   Article version DOI.
   * @param bool $load
   *   Flag set to TRUE if we wish to load the article data.
   *
   * @return bool|mixed
   *   Details of the articles that match criteria.
   */
  public static function latestFromDoi($doi, $load = TRUE) {
    return self::fromId($doi, $load, 'elife_article_ver', array(), 1, 'field_elife_a_doi');
  }

  /**
   * Get POA from article id.
   *
   * This will not return the POA for articles that are now VOR.
   *
   * @param string $article_id
   *   Article ID.
   * @param bool $load
   *   Flag set to TRUE if we wish to load the article data.
   * @param int $limit
   *   Limit the number of articles returned.
   *
   * @return bool|mixed
   *   Details of the articles that match criteria.
   */
  public static function poaFromId($article_id, $load = TRUE, $limit = 1) {
    $conditions = array(
      'field_elife_a_status' => 'POA',
    );

    return self::fromId($article_id, $load, 'elife_article_ver', $conditions, $limit);
  }

  /**
   * Get the vor from the article id.
   *
   * @param string $article_id
   *   Article ID.
   * @param bool $load
   *   Flag set to TRUE if we wish to load the article data.
   *
   * @return bool|mixed
   *   Details of the articles that match criteria.
   */
  public static function vorFromId($article_id, $load = TRUE) {
    $conditions = array(
      'field_elife_a_status' => 'VOR',
    );

    return self::fromId($article_id, $load, 'elife_article_ver', $conditions, 1);
  }

  /**
   * Retrieve the article node or node id from the article id.
   *
   * @param string $article_id
   *   Article ID.
   * @param bool $load
   *   Flag set to TRUE if we wish to load the article data.
   * @param string $bundle
   *   Bundle/content type.
   * @param array $conditions
   *   Array of conditions for sql query.
   * @param int $limit
   *   Limit the number of articles returned.
   * @param string $id_field
   *   Field of the identifier.
   * @param bool $access_opt_out
   *   Set if we want to bypass content access controls.
   *
   * @return bool|mixed
   *   Details of the articles that match criteria.
   */
  public static function fromId($article_id, $load = TRUE, $bundle = 'elife_article_ver', $conditions = array(), $limit = 0, $id_field = 'field_elife_a_article_id', $access_opt_out = FALSE) {
    $id_query = new EntityFieldQueryExtraFields();
    $id_query->entityCondition('entity_type', 'node');
    $id_query->entityCondition('bundle', $bundle);
    $id_query->fieldCondition($id_field, 'value', $article_id, '=');
    $id_query->propertyOrderBy('status', 'DESC');
    $id_query->fieldOrderBy('field_elife_a_status', 'value', 'DESC');
    $id_query->fieldOrderBy('field_elife_a_version', 'value', 'DESC');
    $id_query->fieldOrderBy('field_elife_a_update', 'value', 'DESC');
    $id_query->addExtraField('field_elife_a_status', 'value', 'status');
    $id_query->addExtraField('field_elife_a_version', 'value', 'version');
    $id_query->addExtraField('field_elife_a_article_version_id', 'value', 'value');

    // Need to retrieve unpublished content.
    if ($access_opt_out) {
      $id_query->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');
    }

    if (!empty($conditions)) {
      foreach ($conditions as $field => $value) {
        $column = 'value';
        $operator = '=';
        $type = 'fieldCondition';
        if (is_array($value)) {
          $assert = $value[0];

          if (!empty($value[1])) {
            $column = $value[1];
          }
          if (!empty($value[2])) {
            $operator = $value[2];
          }
          if (!empty($value[3])) {
            $type = $value[3];
          }
        }
        else {
          $assert = $value;
          if (is_numeric($field)) {
            $id_query->addTag($assert);
            continue;
          }
        }

        if ($type == 'fieldCondition') {
          $id_query->fieldCondition($field, $column, $assert, $operator);
        }
        elseif ($type == 'propertyCondition') {
          $id_query->propertyCondition($column, $assert, $operator);
        }
      }
    }

    if (!empty($limit)) {
      $id_query->range(0, $limit);
    }

    $ids = $id_query->execute();

    if (empty($ids['node'])) {
      return FALSE;
    }
    else {
      if ($load) {
        $nodes = node_load_multiple(array_keys($ids['node']));
        if ($limit === 1) {
          return array_shift($nodes);
        }
        else {
          return $nodes;
        }
      }
      elseif ($limit === 1) {
        return array_shift($ids['node']);
      }
      else {
        return $ids['node'];
      }
    }
  }

  /**
   * Retrieve the article node or node id from the id.
   *
   * (default is article version id).
   *
   * @param string $id
   *   Identifier.
   * @param bool $load
   *   Flag set to TRUE if we wish to load the article data.
   * @param string $bundle
   *   Bundle/content type.
   * @param int $limit
   *   Limit the number of articles returned.
   * @param string $id_field
   *   Field of the identifier.
   * @param bool $access_opt_out
   *   Set if we want to bypass content access controls.
   *
   * @return bool|mixed
   *   Details of the articles that match criteria.
   */
  public static function fromIdentifier($id, $load = TRUE, $bundle = 'elife_article_ver', $limit = 1, $id_field = 'field_elife_a_article_version_id', $access_opt_out = FALSE) {
    $id_query = new EntityFieldQuery();

    // Need to retrieve unpublished content.
    if ($access_opt_out) {
      $id_query->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');
    }

    $id_query->entityCondition('entity_type', 'node');
    $id_query->fieldCondition($id_field, 'value', $id, '=');

    if (!empty($bundle)) {
      $id_query->entityCondition('bundle', $bundle);
    }

    if (!empty($limit)) {
      $id_query->range(0, $limit);
    }

    $ids = $id_query->execute();

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
   * Retrieve the article collection node from the article-id.
   *
   * @param string $article_id
   *   Article Id.
   * @param bool $load
   *   Flag set to TRUE if we wish to load the article data.
   * @param bool $access_opt_out
   *   Set if we want to bypass content access controls.
   *
   * @return bool|mixed
   *   Details of the article collection entity.
   */
  public static function getArticle($article_id, $load = TRUE, $access_opt_out = FALSE) {
    return self::fromIdentifier($article_id, $load, 'elife_article', 1, 'field_elife_a_article_id', $access_opt_out);
  }

  /**
   * Get path for supplied article version id.
   *
   * @param string $article_version_id
   *   Article version id.
   *
   * @return string
   *   Content alias from article.
   */
  public static function getPath($article_version_id) {
    $article_nid = self::fromIdentifier($article_version_id, FALSE);
    return drupal_get_path_alias('node/' . $article_nid);
  }

  /**
   * Get categories for supplied article version id.
   *
   * @param string $article_version_id
   *   Article version id.
   *
   * @return array
   *   Categories.
   */
  public static function getCategories($article_version_id) {
    $article = self::fromIdentifier($article_version_id);
    $categories = array();

    /* @var EntityDrupalWrapper $ewrapper */
    if ($ewrapper = entity_metadata_wrapper('node', $article)) {
      /* @var EntityDrupalWrapper $category */
      foreach ($ewrapper->field_elife_a_category as $category) {
        $categories[$category->field_elife_category_type->value()][] = $category->field_elife_title->value()['value'];
      }
    }

    return $categories;
  }

  /**
   * Get keywords for supplied article version id.
   *
   * @param string $article_version_id
   *   Article version id.
   *
   * @return array
   *   Keywords.
   */
  public static function getKeywords($article_version_id) {
    $article = self::fromIdentifier($article_version_id);
    $keywords = array();

    /* @var EntityDrupalWrapper $ewrapper */
    if ($ewrapper = entity_metadata_wrapper('node', $article)) {
      /* @var EntityDrupalWrapper $keyword */
      foreach ($ewrapper->field_elife_a_keyword as $keyword) {
        $value = $keyword->field_elife_title->value();
        $keywords[$keyword->field_elife_a_kwd_type->value()][] = $value;
      }
    }

    return $keywords;
  }

  /**
   * Validate the doi string.
   *
   * @param string $doi
   *   DOI.
   *
   * @return bool
   *   TRUE if valid.
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
   *   Title to clean.
   *
   * @return string
   *   Clean title.
   */
  public static function cleanTitle($title) {
    $title = self::unicodeFix($title, 'replace');

    $title = trim($title);
    $title = htmlspecialchars_decode($title);

    $title = str_replace("\n", ' ', $title);
    $title = str_replace("  ", ' ', $title);

    if (mb_strlen($title) > 255) {
      // @todo - elife - nlisgo - Trim on word boundary.
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
   * because the load will crash because the title field encoding is utf8. For
   * a
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
    $pattern_2byte = '/[\x00-\x08\x10\x0B\x0C\x0E-\x19\x7F]|[\x00-\x7F][\x80-\xBF]+|([\xC0\xC1]|[\xF0-\xFF])[\x80-\xBF]*|[\xC2-\xDF]((?![\x80-\xBF])|[\x80-\xBF]{2,})|[\xE0-\xEF](([\x80-\xBF](?![\x80-\xBF]))|(?![\x80-\xBF]{2})|[\x80-\xBF]{3,})/S';

    $pattern_3byte = '/\xE0[\x80-\x9F][\x80-\xBF]|\xED[\xA0-\xBF][\x80-\xBF]/S';

    switch ($action) {
      case 'check':
        // Check for overly long 2 byte sequences, as well as characters above
        // U+10000.
        $two_byte = preg_match($pattern_2byte, $string);

        // Reject overly long 3 byte sequences and UTF-16 surrogates.
        $three_byte = preg_match($pattern_3byte, $string);

        $has_replacement = FALSE;
        if ($two_byte == 1 || $three_byte == 1) {
          $has_replacement = TRUE;
        }
        $output = $has_replacement;
        break;

      default:
        // Check for overly long 2 byte sequences, as well as characters above
        // U+10000 and replace with ?.
        $string = preg_replace($pattern_2byte, '?', $string);

        // Reject overly long 3 byte sequences and UTF-16 surrogates and replace
        // with ?.
        $output = preg_replace($pattern_3byte, '?', $string);
        break;
    }

    return $output;
  }

  /**
   * Retrieve related articles.
   *
   * @param string $doi
   *   DOI of article.
   * @param bool $verified
   *   Flag set to TRUE if we want verified only, FALSE if we want unverified.
   * @param bool $unique
   *   If TRUE only return unique relations.
   * @param int|NULL $status
   *   0 for unpublished, 1 for published and NULL for permission specific.
   * @param int|NULL $critical
   *   0 for non-critical, 1 for critical and NULL for either.
   *
   * @return array
   *   Results of query
   */
  public static function retrieveRelatedArticles($doi = NULL, $verified = TRUE, $unique = FALSE, $status = NULL, $critical = NULL) {
    $results = self::retrieveRelatedArticlesQuery($doi, $verified, $unique);

    if (is_null($status)) {
      $status = (user_access('view any unpublished elife_article_ver content') || user_access('view any unpublished content')) ? NULL : 1;
    }

    foreach ($results as $k => $result) {
      if (
        $verified &&
        (($status === 1 && ($result->node_status_1 == 0 || $result->node_status_2 == 0)) ||
        ($status === 0 && $result->node_status_1 == 1 && $result->node_status_2 == 1) ||
        ($critical && empty($result->criticalrelation_type)) ||
        (!$critical && !empty($result->criticalrelation_type)))
      ) {
        unset($results[$k]);
      }
    }

    return $results;
  }

  /**
   * Query the related articles.
   *
   * @param string $doi
   *   DOI of article.
   * @param bool $verified
   *   Flag set to TRUE if we want verified only, FALSE if we want unverified.
   * @param bool $unique
   *   If TRUE only return unique relations.
   *
   * @return array
   *   Results of query
   */
  public static function retrieveRelatedArticlesQuery($doi = NULL, $verified = TRUE, $unique = FALSE) {
    $key = self::retrieveRelatedArticlesQueryKey($doi, $verified, $unique);
    $cache = self::retrieveRelatedArticlesQueryCache($doi, $verified, $unique);
    return $cache[$key];
  }

  /**
   * Generate key for related articles query.
   *
   * @param string $doi
   *   DOI of article.
   * @param bool $verified
   *   Flag set to TRUE if we want verified only, FALSE if we want unverified.
   * @param bool $unique
   *   If TRUE only return unique relations.
   *
   * @return string
   *   String to be used to retrieve related article data.
   */
  public static function retrieveRelatedArticlesQueryKey($doi = NULL, $verified = TRUE, $unique = FALSE) {
    $key = [
      is_null($doi) ? 'NULL' : $doi,
      $verified ? '1' : '0',
      $unique ? '1' : '0',
    ];

    return implode('|', $key);
  }

  /**
   * Cached queries for the related articles.
   *
   * @param string $doi
   *   DOI of article.
   * @param bool $verified
   *   Flag set to TRUE if we want verified only, FALSE if we want unverified.
   * @param bool $unique
   *   If TRUE only return unique relations.
   *
   * @return array
   *   Results of query
   */
  public static function retrieveRelatedArticlesQueryCache($doi = NULL, $verified = TRUE, $unique = FALSE) {
    $cache = &drupal_static(__FUNCTION__, []);
    $key = self::retrieveRelatedArticlesQueryKey($doi, $verified, $unique);

    if (!isset($cache[$key])) {
      $output = [];
      if ('sqlite' === Database::getConnection()->databaseType()) {
        $greatest = 'MAX';
        $least = 'MIN';
      }
      else {
        $greatest = 'GREATEST';
        $least = 'LEAST';
      }

      if (!is_null($doi)) {
        $args = [':doi' => $doi];
      }
      else {
        $args = [];
      }

      $query = db_select('elife_related_articles', 'era');

      if (!is_null($doi)) {
        $db_or = db_or();
        $db_or->condition('era.source_doi', $doi);
        $db_or->condition('era.dest_doi', $doi);
        $query->condition($db_or);
        $source_expression = ':doi';
        $dest_expression = 'IF(era.dest_doi != :doi, era.dest_doi, era.source_doi)';
        $query->addExpression('IF(era.dest_doi != :doi, 1, 0)', 'endpoints_flag', $args);
      }
      else {
        $source_expression = 'era.source_doi';
        $dest_expression = 'era.dest_doi';
      }
      $query->addExpression($source_expression, 'doi_source', $args);
      $query->addExpression($dest_expression, 'doi_dest', $args);
      $query->addField('era', 'description', 'article_type');

      $verify_join = ($verified) ? 'innerJoin' : 'leftJoin';
      $query->{$verify_join}('field_data_field_elife_a_doi', 'doi_1', "doi_1.field_elife_a_doi_value = " . $source_expression . " AND doi_1.entity_type = 'node'", $args);
      $query->{$verify_join}('field_data_field_elife_a_doi', 'doi_2', "doi_2.field_elife_a_doi_value = " . $dest_expression . " AND doi_2.entity_type = 'node'", $args);
      $query->{$verify_join}('field_data_field_elife_a_versions', 'vrs_1', "vrs_1.field_elife_a_versions_target_id = doi_1.entity_id AND vrs_1.entity_type = doi_1.entity_type AND vrs_1.delta = 0");
      $query->{$verify_join}('field_data_field_elife_a_versions', 'vrs_2', "vrs_2.field_elife_a_versions_target_id = doi_2.entity_id AND vrs_2.entity_type = doi_2.entity_type AND vrs_2.delta = 0");
      $query->{$verify_join}('field_data_field_elife_a_article_id', 'aid', 'aid.entity_id = doi_2.entity_id AND aid.entity_type = doi_2.entity_type');
      $group_by = FALSE;

      if ($verified) {
        $query->addField('aid', 'field_elife_a_article_id_value', 'related_to');
        $query->innerJoin('node', 'node_1', 'node_1.nid = doi_1.entity_id');
        $query->innerJoin('node', 'node_2', 'node_2.nid = doi_2.entity_id');
        $query->addField('node_1', 'nid', 'article_ver_nid_1');
        $query->addField('node_2', 'nid', 'article_ver_nid_2');

        $query->addField('node_1', 'status', 'node_status_1');
        $query->addField('node_2', 'status', 'node_status_2');

        $query->leftJoin('field_data_field_elife_a_category', 'cat_1', 'cat_1.entity_id = node_1.nid');
        $query->leftJoin('field_data_field_elife_a_category', 'cat_2', 'cat_2.entity_id = node_2.nid');
        $query->leftJoin('taxonomy_term_data', 'td_1', 'td_1.tid = cat_1.field_elife_a_category_target_id');
        $query->leftJoin('taxonomy_term_data', 'td_2', 'td_2.tid = cat_2.field_elife_a_category_target_id');
        $query->leftJoin('field_data_field_elife_category_type', 'cat_type_1', 'cat_type_1.entity_id = td_1.tid');
        $query->leftJoin('field_data_field_elife_category_type', 'cat_type_2', 'cat_type_2.entity_id = td_2.tid');
        $query->condition('cat_type_1.field_elife_category_type_value', 'display-channel', '=');
        $query->condition('cat_type_2.field_elife_category_type_value', 'display-channel', '=');
        $query->addField('td_1', 'name', 'endpoint_1_display_channel');
        $query->addField('td_2', 'name', 'endpoint_2_display_channel');
        $query->addExpression("CONCAT($least(td_1.name, td_2.name), '|', $greatest(td_1.name, td_2.name))", 'relation_ordered');
      }
      else {
        $db_or = db_or();
        $db_or->isNull('doi_1.field_elife_a_doi_value');
        $db_or->isNull('doi_2.field_elife_a_doi_value');
        $query->condition($db_or);
        $group_by = "CONCAT(doi_source, '|', doi_dest)";
      }

      if ($unique) {
        if (!is_null($doi)) {
          $group_by = 'doi_dest';
        }
        else {
          $group_by = "CONCAT($least(doi_source, doi_dest), '|', $greatest(doi_source, doi_dest))";
        }
      }

      if ($group_by) {
        $query->groupBy($group_by);
      }

      if ($results = $query->execute()) {
        foreach ($results as $prepare_output) {
          if (!empty($prepare_output->relation_ordered)) {
            $prepare_output->endpoint_types = explode('|', $prepare_output->relation_ordered);
          }

          $criticals = [
            'builds' => [
              'research advance|research article',
              'research advance|tools and resources',
              'research advance|short report',
            ],
            'replicates' => [
              'registered report|replication study',
            ],
          ];

          if (!empty($prepare_output->relation_ordered)) {
            $critical_found = FALSE;
            foreach ($criticals as $type => $ords) {
              if (in_array(strtolower($prepare_output->relation_ordered), $ords)) {
                $critical_found = $type;
                break;
              }
            }
            if ($critical_found) {
              $prepare_output->criticalrelation_type = $critical_found;
            }
          }

          $related_to = [];
          if (isset($prepare_output->article_ver_nid_2)) {
            $related_to['article_ver_nid'] = $prepare_output->article_ver_nid_2;
          }
          if (isset($prepare_output->endpoint_2_display_channel)) {
            $related_to['display_channel'] = $prepare_output->endpoint_2_display_channel;
          }
          if (!empty($related_to)) {
            $prepare_output->endpoints = new stdClass();
            $prepare_output->endpoints->related_to = json_decode(json_encode($related_to));
          }
          $output[] = $prepare_output;
        }
      }

      $cache[$key] = $output;
    }

    return $cache;
  }

  /**
   * Get the section for the supplied node.
   *
   * @param stdClass $node
   *   Node.
   *
   * @return string
   *   Section code.
   */
  public static function getSectionCode(stdClass $node) {
    $available_sections = self::availableSections();
    $section_code = NULL;
    $section_name = NULL;
    $reference_path = NULL;

    if ('elife_article_reference' === $node->type) {
      $article_ver = elife_article_reference_get_article_version($node);

      /* @var EntityDrupalWrapper $art_wrapper */
      $node_wrapper = entity_metadata_wrapper('node', $article_ver);
      $categories = self::getCategories($node_wrapper->field_elife_a_article_version_id->value());
      if (!empty($categories) && !empty($categories['display-channel'])) {
        $section_title = $categories['display-channel'][0];
        if ($key = array_search(strtolower($section_title), array_map('strtolower', $available_sections))) {
          return $key;
        }
      }
    }
    elseif (array_key_exists($type = preg_replace('/^elife_/', '', $node->type), $available_sections)) {
      return $type;
    }

    return 'other';
  }

  /**
   * Get the list of approved section codes and names.
   *
   * @return array
   *   Array of available sections.
   */
  public static function availableSections() {
    $cache = &drupal_static(__FUNCTION__, FALSE);

    if ($cache === FALSE) {
      $default = array(
        'feature' => 'Feature Article',
        'insight' => 'Insight',
        'editorial' => 'Editorial',
        'research' => 'Research Article',
        'advance' => 'Research Advance',
        'replication-study' => 'Replication Study',
        'registered-report' => 'Registered Report',
        'tools' => 'Tools and resources',
        'short' => 'Short Report',
        'correction' => 'Correction',
        'retraction' => 'Retraction',
        'news_article' => 'eLife News',
        'podcast' => 'Podcast',
        'event' => 'Event',
        'early_careers_interview' => 'Early-career researchers',
        'collection' => 'Collection',
        'other' => 'Supplementary',
      );

      $cache = variable_get('elife_article_sections_available', $default);
    }

    return $cache;
  }

  /**
   * Get section name for a code.
   *
   * @param string $section
   *   Section code.
   *
   * @return string
   *   Section name.
   */
  public static function getSection($section) {
    $sections = self::availableSections();

    if (isset($sections[$section])) {
      return $sections[$section];
    }

    return $sections['other'];
  }
}
