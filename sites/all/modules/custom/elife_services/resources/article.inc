<?php

/**
 * @file
 * Contains the resource callbacks for articles.
 */

use Drupal\elife_article\ElifeArticle;

// @todo - elife - nlisgo - ensure that when an article is updated/deleted that
// any orphaned nodes and possibly categories/keywords are removed.

// @todo - elife - nlisgo - consider possibility of ingesting multiple p tags in
// referenced simple.

/**
 * Determines an API user's access to retrieve a given article.
 *
 * @param string $article_version_id
 *   Article version id.
 *
 * @return bool
 *   returns TRUE or FALSE
 */
function _elife_services_article_retrieve_access($article_version_id) {
  // @todo - elife - nlisgo - Implement some access control.
  return TRUE;
}

/**
 * Determines an API user's access to create an article.
 *
 * @param array $data
 *   Array of data submitted in the request.
 *
 * @return bool
 *   returns TRUE or FALSE.
 */
function _elife_services_article_create_access($data) {
  return TRUE;
}

/**
 * Determines an API user's access to update a given article.
 *
 * @param string $article_version_id
 *   Article version id.
 *
 * @return bool
 *   returns TRUE or FALSE
 */
function _elife_services_article_update_access($article_version_id) {
  return TRUE;
}

/**
 * Determines an API user's access to delete a given article.
 *
 * @param string $article_version_id
 *   Article version id.
 *
 * @return bool
 *   returns TRUE or FALSE
 */
function _elife_services_article_delete_access($article_version_id) {
  return TRUE;
}

/**
 * Retrieve raw article entity.
 *
 * @param string $id
 *   Article identifier.
 * @param string $bundle
 *   Bundle/content type.
 * @param string $id_field
 *   Id field in database.
 * @param bool $trigger_error
 *   Triggers services_error if set and appropriate.
 *
 * @return mixed
 *   Return article node.
 *
 * @throws ServicesException
 */
function _elife_services_article_retrieve_raw($id, $bundle = 'elife_article_ver', $id_field = 'field_elife_a_article_version_id', $trigger_error = TRUE) {
  $article = ElifeArticle::fromIdentifier($id, TRUE, $bundle, 1, $id_field);
  if ($trigger_error && empty($article->nid)) {
    return services_error(t('Article version id @id not found', array('@id' => $id)), 404);
  }

  return $article;
}

/**
 * Callback function for elife_article_ver retrieve.
 *
 * @param string $article_version_id
 *   Article version id.
 * @param string $bundle
 *   Bundle/content type.
 *
 * @return mixed
 *   Return article node.
 *
 * @throws ServicesException
 */
function _elife_services_article_retrieve($article_version_id, $bundle = 'elife_article_ver') {
  $article = _elife_services_article_retrieve_raw($article_version_id, $bundle);
  return _elife_services_article_prepare_json($article);
}

/**
 * Prepare json for the response.
 *
 * @param object $article
 *   Article data object.
 * @param null|string $article_version_id
 *   Article version id.
 *
 * @return array
 *   Structured article data.
 */
function _elife_services_article_prepare_json($article, $article_version_id = NULL) {
  /* @var EntityDrupalWrapper $ewrapper */
  $ewrapper = entity_metadata_wrapper('node', $article);

  if (!$article_version_id) {
    $article_version_id = $ewrapper->field_elife_a_article_version_id->value();
    $article_version_id = (is_array($article_version_id)) ? reset($article_version_id) : $article_version_id;
  }

  $top_level = array(
    'title' => array(
      'field' => 'field_elife_a_full_title',
      'type' => 'string',
    ),
    'impact-statement' => array(
      'field' => 'field_elife_a_author_imp',
      'type' => 'string',
    ),
    'doi' => array(
      'field' => 'field_elife_a_doi',
      'type' => 'string',
    ),
    'volume' => array(
      'field' => 'field_elife_a_volume',
      'type' => 'string',
    ),
    'article-id' => array(
      'field' => 'field_elife_a_article_id',
      'type' => 'string',
    ),
    'version' => array(
      'field' => 'field_elife_a_version',
      'type' => 'string',
    ),
    'article-version-id' => $article_version_id,
    'publish' => array(
      'field' => 'status',
      'type' => 'string',
    ),
    'status' => array(
      'field' => 'field_elife_a_status',
      'type' => 'string',
    ),
    'pub-date' => array(
      'field' => 'field_elife_a_fpubdate',
      'type' => 'date',
    ),
    'path' => array(
      'custom' => 'Drupal\elife_article\ElifeArticle::getPath',
      'type' => 'array',
    ),
    'article-type' => array(
      'field' => 'field_elife_a_article_type',
      'type' => 'string',
    ),
    'categories' => array(
      'custom' => 'Drupal\elife_article\ElifeArticle::getCategories',
      'type' => 'array',
    ),
    'keywords' => array(
      'custom' => 'Drupal\elife_article\ElifeArticle::getKeywords',
      'type' => 'array',
    ),
    'contributors' => array(
      'custom' => 'Drupal\elife_article\ElifeArticle::getContributors',
      'type' => 'array',
    ),
    'referenced' => array(
      'custom' => 'Drupal\elife_article\ElifeArticle::getContributorReferences',
      'type' => 'array',
    ),
    'children' => array(
      'custom' => 'Drupal\elife_article\ElifeArticle::getArticleChildren',
      'type' => 'array',
    ),
    'citations' => array(
      'custom' => 'Drupal\elife_article\ElifeArticle::getCitations',
      'type' => 'array',
    ),
  );

  $json = array();

  foreach ($top_level as $key => $value) {
    $get = NULL;

    if (!is_array($value)) {
      $get = $value;
    }
    else {
      if (isset($value['field'])) {
        $get = $ewrapper->{$value['field']}->value();

        if (is_array($get)) {
          $get = reset($get);
        }
      }
      elseif (isset($value['custom'])) {
        $get = call_user_func_array($value['custom'], array($article_version_id));
      }

      if (isset($value['type'])) {
        switch ($value['type']) {
          case 'date':
            $get = format_date($get, 'medium', 'Y-m-d H:i:s');
            // If time is blank then strip it out.
            $get = preg_replace('/^([0-9]{4}-[0-9]{2}-[0-9]{2}) 00:00:00$/', '$1', $get);
            break;

          case 'string':
            $get = (string) $get;
            break;
        }
      }
    }

    if ($get) {
      $json[$key] = $get;
    }
  }

  return $json;
}

/**
 * Callback function for elife_article_ver create.
 *
 * @param array $data
 *   Article data submitted in the request.
 *
 * @return mixed
 *   Return array to be output as json.
 */
function _elife_services_article_create($data) {
  // If force flag set then update if article-version-id recognised.
  if (!empty($data['force']) && !empty($data['article-version-id']) && !ElifeArticle::uniqueArticleVersionId($data['article-version-id'])) {
    return _elife_services_article_update($data['article-version-id'], $data);
  }
  else {
    $values = array(
      'type' => 'elife_article_ver',
      'uid' => _elife_services_user_uid(),
    );
    /* @var object $article */
    $article = entity_create('node', $values);
    $article = _elife_services_article_update_values($article, $data, TRUE);
    return _elife_services_article_prepare_json($article);
  }
}

function _elife_article_publish($publish = NULL) {
  $cache = &drupal_static(__FUNCTION__, NULL);

  if ($publish !== NULL) {
    $cache = $publish;
  }

  return $cache;
}

/**
 * Callback function for elife_article_ver update.
 *
 * @param string $article_version_id
 *   Article version id.
 * @param array $data
 *   Article data submitted in the request.
 *
 * @return mixed
 *   Return array to be output as json.
 */
function _elife_services_article_update($article_version_id, $data) {
  // @todo - elife - nlisgo - do a better job of not updating if values same.
  $article = _elife_services_article_retrieve_raw($article_version_id);

  $article = _elife_services_article_update_values($article, $data);
  return _elife_services_article_prepare_json($article);
}

/**
 * Callback function for elife_article_ver delete.
 *
 * @param string $article_version_id
 *   Article version id.
 * @param bool $trigger_error
 *   If TRUE then trigger services_error if appropriate.
 *
 * @throws Exception
 */
function _elife_services_article_delete($article_version_id, $trigger_error = TRUE) {
  $article = _elife_services_article_retrieve_raw($article_version_id, 'elife_article_ver', 'field_elife_a_article_version_id', $trigger_error);

  if ($article) {
    /* @var EntityDrupalWrapper $ewrapper */
    $ewrapper = entity_metadata_wrapper('node', $article);

    // Remove article node.
    $ewrapper->delete();
  }
}

/**
 * Updates specific values of an existing elife_article_ver entity.
 *
 * @param object $article
 *   Object of article data prepared by Drupal.
 * @param array $data
 *   Array of values supplied in request.
 * @param bool $new
 *   Flag set to TRUE for new content.
 *
 * @return object
 *   Return the raw article data object.
 *
 * @throws EntityMetadataWrapperException
 * @throws ServicesException
 */
function _elife_services_article_update_values($article, $data, $new = FALSE) {
  $required = array();

  if ($new) {
    $required = array(
      'title',
      'article-type',
      'doi',
      'volume',
      'pub-date',
      'version',
      'path',
      'article-version-id',
    );
  }

  foreach ($required as $k => $req) {
    if (!empty($data[$req])) {
      unset($required[$k]);
    }
  }

  if (!empty($required)) {
    return services_error(t('No value provided for required: @fields', array('@fields' => implode(', ', $required))), 406);
  }

  // This ensures that paths will not be automatically generated.
  $article->path['pathauto'] = FALSE;

  /* @var EntityDrupalWrapper $ewrapper */
  $ewrapper = entity_metadata_wrapper('node', $article);

  // Set the title.
  if (isset($data['title'])) {
    $set = array(
      'value' => $data['title'],
      'format' => 'full_html',
    );
    $ewrapper->field_elife_a_full_title->set($set);
    $ewrapper->title->set(ElifeArticle::cleanTitle($set['value']));
  }

  if (isset($data['publish'])) {
    $ewrapper->status->set($data['publish']);
    _elife_article_publish($data['publish']);
  }
  elseif ($new) {
    _elife_article_publish(1);
  }
  else {
    _elife_article_publish($ewrapper->status->value());
  }

  // Set the volume number.
  if (isset($data['volume'])) {
    $ewrapper->field_elife_a_volume->set($data['volume']);
  }

  if (isset($data['article-type'])) {
    $ewrapper->field_elife_a_article_type->set($data['article-type']);
  }

  if (isset($data['categories'])) {
    $categories = array();
    foreach ($data['categories'] as $group => $cats) {
      $fields = array(
        'field_elife_category_type' => $group,
      );
      foreach ($cats as $cat) {
        if ($term = _elife_services_article_prepare_term('elife_categories', $cat, $fields)) {
          $categories[] = $term->tid;
        }
      }
    }
    $ewrapper->field_elife_a_category->set($categories);
  }

  if (isset($data['keywords'])) {
    $keywords = array();
    foreach ($data['keywords'] as $category => $kwds) {
      foreach ($kwds as $kwd) {
        $fields = array(
          'field_elife_a_full_title' => array(
            'value' => $kwd,
            'format' => 'full_html',
          ),
          'field_elife_a_kwd_type' => $category,
        );
        if ($term = _elife_services_article_prepare_term('elife_keywords', $kwd, array(), $fields)) {
          $keywords[] = $term->tid;
        }
      }
    }
    $ewrapper->field_elife_a_keyword->set($keywords);
  }

  // Set the article-version-id if article is new.
  if ($new && !empty($data['article-version-id'])) {
    if (!ElifeArticle::uniqueArticleVersionId($data['article-version-id'])) {
      return services_error(t('Invalid value provided: @field', array('@field' => 'Article version id (must be unique)')), 406);
    }
  }

  if (isset($data['doi'])) {
    if (!ElifeArticle::validateDoi($data['doi'])) {
      return services_error(t('Invalid value provided: @field', array('@field' => 'doi')), 406);
    }
  }

  $field_prefix = 'field_elife_a';
  $mappings = array(
    'article-version-id' => $field_prefix . '_article_version_id',
    'doi' => $field_prefix . '_doi',
    'article-id' => $field_prefix . '_article_id',
    'version' => $field_prefix . '_version',
    'status' => $field_prefix . '_status',
  );
  foreach ($mappings as $k => $field) {
    if (isset($data[$k])) {
      $ewrapper->{$field}->set($data[$k]);
    }
  }

  if (isset($data['pub-date'])) {
    $ewrapper->field_elife_a_fpubdate->set(_elife_services_article_prepare_date($data['pub-date']));
  }

  if (isset($data['update'])) {
    $ewrapper->field_elife_a_update->set(_elife_services_article_prepare_date($data['update']));
  }

  if (isset($data['impact-statement'])) {
    $set = array(
      'value' => $data['impact-statement'],
      'format' => 'full_html',
    );
    $ewrapper->field_elife_a_author_imp->set($set);
  }

  if (isset($data['copyright'])) {
    $set = array(
      'value' => $data['copyright'],
      'format' => 'full_html',
    );
    $ewrapper->field_elife_a_copyright->set($set);
  }

  $ewrapper->save();

  $trigger_save = FALSE;
  $ref_links = array();

  if (isset($data['referenced'])) {
    _elife_services_article_process_referenced($ewrapper, $data['referenced'], $ref_links, $new);
    $trigger_save = TRUE;
  }

  if (!$new && (isset($data['referenced']) || isset($data['contributors']))) {
    if ($existing = $ewrapper->field_elife_a_contributors->raw()) {
      node_delete_multiple($existing);
    }
  }

  if (isset($data['contributors'])) {
    _elife_services_article_process_contributors($ewrapper, $ewrapper->nid->value(), $data['contributors'], $ref_links);
    $trigger_save = TRUE;
  }

  if (isset($data['children'])) {
    $processed_dois = array();
    _elife_services_article_process_children($ewrapper, $ewrapper->nid->value(), $data['children'], $new, $processed_dois);
    $orphaned_dois = ElifeArticle::getArticleChildDois($data['article-version-id'], $processed_dois);
    // @todo - elife - nlisgo - delete nodes that have orphaned dois for this
    // article version.
    $trigger_save = TRUE;
  }

  if (isset($data['citations'])) {
    _elife_services_article_process_citations($ewrapper, $ewrapper->nid->value(), $data['citations']);
    $trigger_save = TRUE;
  }

  if ($trigger_save) {
    $ewrapper->save();
  }

  // Add or amend the content alias.
  if (!empty($data['path'])) {
    $source = 'node/' . $ewrapper->nid->value();
    // Check to see that path is unique.
    if ($new && $path = path_load(array('alias' => $data['path']))) {
      if ($path['source'] != $source) {
        return services_error(t('Path is already in use: @path', array('@path' => $data['path'])), 406);
      }
    }

    _elife_services_create_path($data['path'], $source);
  }

  return $ewrapper->raw();
}

/**
 * Create a path alias.
 *
 * @param string $path
 *   Path alias.
 * @param string $source
 *   Source value (e.g. node/1234).
 */
function _elife_services_create_path($path, $source) {
  $content_path = array(
    'alias' => $path,
    'source' => $source,
  );

  $existing = path_load(array('source' => $source));

  if ($existing) {
    $content_path += $existing;
  }

  path_save($content_path);
}

/**
 * Process the citations data from the request.
 *
 * @param \EntityDrupalWrapper $ewrapper
 *   Article object.
 * @param int $parent_nid
 *   Node id of parent.
 * @param array $citations
 *   Array of citation data supplied in request body.
 *
 * @throws \Exception
 */
function _elife_services_article_process_citations(EntityDrupalWrapper &$ewrapper, $parent_nid, $citations) {
  $cits = array();
  if ($existing = $ewrapper->field_elife_a_citations->raw()) {
    node_delete_multiple($existing);
  }
  foreach ($citations as $id => $cit) {
    $cit['parent'] = $parent_nid;
    $cit['article-version-id'] = $ewrapper->field_elife_a_article_version_id->value();
    $citation = _elife_services_article_citation_update_values($id, $cit);
    $cits[] = $citation->nid;
  }
  $ewrapper->field_elife_a_citations->set($cits);
}

/**
 * Create/update the values of an article citation.
 *
 * @param string $id
 *   Identifier for the citation.
 * @param array $data
 *   Citation details.
 *
 * @return mixed
 *   Data object of the citation node.
 *
 * @throws \EntityMetadataWrapperException
 * @throws \Exception
 */
function _elife_services_article_citation_update_values($id, $data) {
  $data['id'] = $id;
  $type = 'elife_citation';

  $values = array(
    'type' => $type,
    'uid' => _elife_services_user_uid(),
    'status' => _elife_article_publish(),
  );

  $citation = entity_create('node', $values);

  /* @var EntityDrupalWrapper $ewrapper */
  $ewrapper = entity_metadata_wrapper('node', $citation);

  $field_prefix = 'field_elife_a';
  $field_cit_prefix = $field_prefix . '_cit';
  $mappings = array(
    'id' => $field_cit_prefix . '_id',
    'parent' => $field_prefix . '_parent',
    'year' => $field_cit_prefix . '_year',
    'title' => $field_cit_prefix . '_title',
    'doi' => $field_cit_prefix . '_doi',
  );
  foreach ($mappings as $k => $field) {
    if (isset($data[$k])) {
      $ewrapper->{$field}->set($data[$k]);
    }
  }

  $title = $data['id'];

  if (isset($data['article-version-id'])) {
    if (empty($title)) {
      $title = $data['article-version-id'];
    }
    else {
      $title .= ' (' . $data['article-version-id'] . ')';
    }
  }
  $ewrapper->title->set($title);

  $ewrapper->save();

  if (isset($data['authors'])) {
    $field_cit_prefix = 'field_elife_a_cit';
    $field_authors = $field_cit_prefix . '_authors';
    $mappings = array(
      'group-type' => $field_cit_prefix . '_author_group',
      'name' => $field_cit_prefix . '_author_name',
    );

    foreach ($data['authors'] as $author) {
      /* @var FieldCollectionItemEntity $fc_item */
      $fc_item = entity_create('field_collection_item', array('field_name' => $field_authors));
      $fc_item->setHostEntity('node', $ewrapper->raw());

      /* @var EntityDrupalWrapper $fc_wrapper */
      $fc_wrapper = entity_metadata_wrapper('field_collection_item', $fc_item);

      foreach ($mappings as $k => $field) {
        if (isset($author[$k])) {
          $fc_wrapper->{$field}->set($author[$k]);
        }
      }
      $fc_wrapper->save();
    }
    $ewrapper->save();
  }

  $ewrapper->save();

  return $ewrapper->raw();
}

/**
 * Process the contributor references.
 *
 * @param \EntityDrupalWrapper $ewrapper
 *   Article entity.
 * @param array $referenced
 *   Contributor reference data.
 * @param array $ref_links
 *   Array to collect the reference ids and associated node ids.
 * @param bool $new
 *   Flag set to TRUE for new content.
 *
 * @throws \EntityMetadataWrapperException
 * @throws \Exception
 */
function _elife_services_article_process_referenced(EntityDrupalWrapper &$ewrapper, $referenced, &$ref_links = array(), $new = FALSE) {
  $ref_templates = array(
    'basic' => array(
      'expand' => TRUE,
      'field' => 'field_elife_a_basic_ref',
      'mapping_template' => array(
        'type' => '_type',
        'value' => '_value',
      ),
    ),
    'funding' => array(
      'field' => 'field_elife_a_fund_ref',
      'mapping_template' => array(
        'id' => '_id',
        'id-type' => '_id_type',
        'institution' => '_inst',
        'award-id' => '_award_id',
      ),
    ),
    'affiliation' => array(
      'field' => 'field_elife_a_aff_ref',
      'mapping_template' => array(
        'dept' => '_dept',
        'institution' => '_inst',
        'city' => '_city',
        'country' => '_country',
      ),
    ),
    'related-object' => array(
      'field' => 'field_elife_a_rel_ref',
      'mapping_template' => array(),
    ),
  );
  $ref_types = array();

  foreach ($ref_templates as $ref_type => $options) {
    if (empty($options['mapping']) && !empty($options['mapping_template'])) {
      $options['mapping'] = array();
      $prefix = (!empty($options['field'])) ? $options['field'] : '';
      foreach ($options['mapping_template'] as $key => $field_end) {
        $options['mapping'][$key] = $prefix . $field_end;
      }
    }

    // If expand option is set then prepare the ref types from the allowed
    // values of the field. Currently this is just used for basic key-value
    // pairs of references (e.g. email).
    if (!empty($options['expand']) && !empty($options['mapping']['type'])) {
      $field_info = field_info_field($options['mapping']['type']);
      if (!empty($field_info['settings']['allowed_values'])) {
        $expand_ref_types = array_keys($field_info['settings']['allowed_values']);
        foreach ($expand_ref_types as $ert) {
          if (isset($referenced[$ert])) {
            $restructure = array();
            foreach ($referenced[$ert] as $key => $value) {
              $restructure[$key] = array(
                'type' => $ert,
                'value' => $value,
              );
            }
            $referenced[$ert] = $restructure;
            $opts = $options;
            unset($opts['expand']);
            $ref_types[$ert] = $opts;
          }
        }
      }
    }
    else {
      $ref_types[$ref_type] = $options;
    }
  }

  if (!$new) {
    // Delete existing referenced for this article.
    foreach ($ref_templates as $ref_type) {
      $ewrapper->{$ref_type['field']}->set(array());
    }
  }

  $article = $ewrapper->raw();

  $field_ref_key = 'field_elife_a_ref_key';

  // Save all contributor references.
  foreach ($ref_types as $ref_type => $options) {
    if (isset($referenced[$ref_type])) {
      $ref_field = $options['field'];
      $mapping = $options['mapping'];
      foreach ($referenced[$ref_type] as $key => $values) {
        /* @var FieldCollectionItemEntity $fc_item */
        $fc_item = entity_create('field_collection_item', array('field_name' => $ref_field));
        $fc_item->setHostEntity('node', $article);

        /* @var EntityDrupalWrapper $fc_wrapper */
        $fc_wrapper = entity_metadata_wrapper('field_collection_item', $fc_item);
        $fc_wrapper->{$field_ref_key}->set($key);
        if (!empty($mapping)) {
          foreach ($mapping as $k => $field) {
            if (isset($values[$k])) {
              $fc_wrapper->{$field}->set($values[$k]);
            }
          }
        }
        $fc_wrapper->save();
        $ref_links[$ref_type][$key] = $fc_wrapper->item_id->value();
      }
    }
  }
}

/**
 * Process the contributors.
 *
 * @param \EntityDrupalWrapper $ewrapper
 *   Article entity.
 * @param int $parent_nid
 *   Node id of the parent.
 * @param array $contributors
 *   Array of contributor data.
 * @param array $ref_links
 *   Array of reference data to link.
 */
function _elife_services_article_process_contributors(EntityDrupalWrapper &$ewrapper, $parent_nid, $contributors, $ref_links) {
  $contribs = array();
  foreach ($contributors as $contributor) {
    $contributor['parent'] = $parent_nid;
    $contrib = _elife_services_article_contributor_update_values($contributor, $ref_links);
    $contribs[] = $contrib->nid;
  }
  $ewrapper->field_elife_a_contributors->set($contribs);
}

/**
 * Update the values of a contributor to the article.
 *
 * @param array $data
 *   Contributor details.
 * @param array $ref_links
 *   Array of reference data to link.
 *
 * @return mixed
 *   The contributor entity.
 *
 * @throws \EntityMetadataWrapperException
 */
function _elife_services_article_contributor_update_values($data, $ref_links) {
  $either = array(
    'id',
    'group-author-key',
  );

  $id_found = FALSE;
  foreach ($either as $k => $req) {
    if (!empty($data[$req])) {
      unset($either[$k]);
      $id_found = $req;
      break;
    }
  }

  $type = 'elife_contributor';

  $values = array(
    'type' => $type,
    'uid' => _elife_services_user_uid(),
    'status' => _elife_article_publish(),
  );

  $contributor = entity_create('node', $values);

  /* @var EntityDrupalWrapper $ewrapper */
  $ewrapper = entity_metadata_wrapper('node', $contributor);

  $field_prefix = 'field_elife_a';
  $mappings = array(
    'type' => $field_prefix . '_contrib_type',
    'parent' => $field_prefix . '_parent',
    'id' => $field_prefix . '_author_id',
    'surname' => $field_prefix . '_surname',
    'given-names' => $field_prefix . '_fnames',
    'suffix' => $field_prefix . '_author_suffix',
    'orcid' => $field_prefix . '_orcid_id',
    'role' => $field_prefix . '_author_role',
    'group-author-key' => $field_prefix . '_group_author_key',
    'collab' => $field_prefix . '_collab',
  );
  foreach ($mappings as $k => $field) {
    if (isset($data[$k])) {
      $ewrapper->{$field}->set($data[$k]);
    }
  }

  if (isset($data['equal-contrib'])) {
    $ewrapper->field_elife_a_equal_contrib->set(($data['equal-contrib'] == 'yes'));
  }

  if (isset($data['corresp'])) {
    $ewrapper->field_elife_a_corresp->set(($data['corresp'] == 'yes'));
  }

  if (isset($data['deceased'])) {
    $ewrapper->field_elife_a_deceased->set(($data['deceased'] == 'yes'));
  }

  if (isset($data['affiliation'])) {
    $mappings = array(
      'dept' => $field_prefix . '_aff_dept',
      'institution' => $field_prefix . '_aff_inst',
      'city' => $field_prefix . '_aff_city',
      'country' => $field_prefix . '_aff_country',
    );
    foreach ($mappings as $k => $field) {
      if (isset($data['affiliation'][$k])) {
        $ewrapper->{$field}->set($data['affiliation'][$k]);
      }
    }
  }

  $title = ($id_found) ? $data[$id_found] : '';
  $extend = array(
    'given-names',
    'surname',
    'suffix',
    'collab',
  );
  $title_ext = array();
  foreach ($extend as $ext) {
    if (!empty($data[$ext])) {
      $title_ext[] = $data[$ext];
    }
  }

  if (!empty($title_ext)) {
    $title_ext = implode(' ', $title_ext);
    if (empty($title)) {
      $title = $title_ext;
    }
    else {
      $title .= ' (' . $title_ext . ')';
    }
  }

  $ewrapper->title->set($title);

  $field_info = field_info_field('field_elife_a_basic_ref_type');
  $refs = array();
  $basic_found = FALSE;
  if (!empty($field_info['settings']['allowed_values'])) {
    $basic_ref_types = array_keys($field_info['settings']['allowed_values']);
    foreach ($basic_ref_types as $brt) {
      if (isset($data['references'][$brt])) {
        $basic_found = TRUE;
        foreach ($data['references'][$brt] as $ref) {
          if (!empty($ref_links[$brt][$ref])) {
            $refs[] = $ref_links[$brt][$ref];
          }
        }
      }
    }
  }
  if ($basic_found) {
    $ewrapper->field_elife_a_basic_ref_links->set($refs);
  }

  $other_refs = array(
    'funding' => 'field_elife_a_fund_ref_links',
    'affiliation' => 'field_elife_a_aff_ref_links',
    'related-object' => 'field_elife_a_rel_ref_links',
  );

  foreach ($other_refs as $type => $field) {
    if (isset($data['references'][$type])) {
      $refs = array();
      foreach ($data['references'][$type] as $ref) {
        if (!empty($ref_links[$type][$ref])) {
          $refs[] = $ref_links[$type][$ref];
        }
      }
      $ewrapper->{$field}->set($refs);
    }
  }

  $ewrapper->save();

  return $ewrapper->raw();

}

/**
 * Process the block of child fragments and subarticles.
 *
 * @param \EntityDrupalWrapper $ewrapper
 *   Parent entity.
 * @param int $parent_nid
 *   Parent node id.
 * @param array $children
 *   Array of child data.
 * @param bool $new
 *   Flag set to TRUE for new content.
 * @param array $processed_dois
 *   Array to store list of processed dois.
 * @param bool $subarticle
 *   Flag set to TRUE for sub-articles and child fragments of sub-articles.
 */
function _elife_services_article_process_children(EntityDrupalWrapper &$ewrapper, $parent_nid, $children, $new = FALSE, &$processed_dois = array(), $subarticle = FALSE) {
  $found = array();
  foreach ($children as $type => $pieces) {
    switch ($type) {
      case 'fragment':
        foreach ($pieces as $piece) {
          $set_subarticle = $subarticle;
          $piece['parent'] = $parent_nid;
          if (isset($piece['type']) && $piece['type'] == 'sub-article') {
            $set_subarticle = TRUE;
            unset($piece['type']);
            $type = 'elife_article_ver';
          }
          else {
            $type = 'elife_fragment';
          }
          $child = _elife_services_article_child_update_values($piece, $type, $set_subarticle, $new, $processed_dois);
          $found[] = $child->nid;
        }
        break;

    }
  }
  $ewrapper->field_elife_a_children->set($found);
}

/**
 * Update the values of the child fragments.
 *
 * @param array $data
 *   Data associated with child fragment.
 * @param string $type
 *   Bundle/content type.
 * @param bool $subarticle
 *   TRUE if this is a subarticle or child of subarticle.
 * @param bool $new
 *   Flag set to TRUE for new content.
 * @param array $processed_dois
 *   Array to store list of processed dois.
 *
 * @return mixed
 *   Child entity object.
 *
 * @throws \EntityMetadataWrapperException
 * @throws \Exception
 * @throws \ServicesException
 */
function _elife_services_article_child_update_values($data, $type, $subarticle = FALSE, $new = FALSE, &$processed_dois = array()) {
  $required = array(
    'doi',
  );

  if ($new) {
    $required = array(
      'doi',
      'path',
    );

    if ($type == 'elife_fragment') {
      $required[] = 'type';
    }
  }

  foreach ($required as $k => $req) {
    if (!empty($data[$req])) {
      unset($required[$k]);
    }
  }

  if (!empty($required)) {
    return services_error(t('No value provided for required: @fields', array('@fields' => implode(', ', $required))), 406);
  }

  $child = NULL;

  if (!$new) {
    $child = _elife_services_article_retrieve_raw($data['doi'], $type, 'field_elife_a_doi', FALSE);
  }

  if (!$child) {
    $new = TRUE;
    $values = array(
      'type' => $type,
      'uid' => _elife_services_user_uid(),
      'status' => _elife_article_publish(),
    );

    $child = entity_create('node', $values);
  }

  // This ensures that paths will not be automatically generated.
  $child->path['pathauto'] = FALSE;

  /* @var EntityDrupalWrapper $ewrapper */
  $ewrapper = entity_metadata_wrapper('node', $child);

  if (isset($data['parent'])) {
    $ewrapper->field_elife_a_parent->set($data['parent']);
  }

  if (isset($data['type']) && isset($data[$data['type'] . '-type'])) {
    $data['sub-type'] = $data[$data['type'] . '-type'];
  }

  if (isset($data['type']) && $data['type'] == 'abstract' && empty($data['title'])) {
    if (isset($data['sub-type']) && $data['sub-type'] == 'executive-summary') {
      $data['title'] = t('eLife digest');
    }
    else {
      $data['title'] = t('Abstract');
    }
  }

  // Set the title.
  if (isset($data['title'])) {
    $set = array(
      'value' => $data['title'],
      'format' => 'full_html',
    );
    $ewrapper->field_elife_a_full_title->set($set);
    $ewrapper->title->set(ElifeArticle::cleanTitle($set['value']));
  }

  if (isset($data['doi'])) {
    if (!ElifeArticle::validateDoi($data['doi'])) {
      return services_error(t('Invalid value provided: @field', array('@field' => 'doi')), 406);
    }

    $ewrapper->field_elife_a_doi->set($data['doi']);
  }

  if (isset($data['pub-date'])) {
    $ewrapper->field_elife_a_fpubdate->set(_elife_services_article_prepare_date($data['pub-date']));
  }

  $ewrapper->field_elife_a_subarticle->set($subarticle);

  if (isset($data['type'])) {
    $ewrapper->field_elife_a_frag_type->set($data['type']);
  }

  if (isset($data['sub-type'])) {
    $ewrapper->field_elife_a_sub_type->set($data['sub-type']);
  }

  $ewrapper->save();

  $trigger_save = FALSE;

  if (isset($data['contributors'])) {
    if ($existing = $ewrapper->field_elife_a_contributors->raw()) {
      node_delete_multiple($existing);
    }
    _elife_services_article_process_contributors($ewrapper, $data['parent'], $data['contributors'], array());
    $trigger_save = TRUE;
  }

  if (isset($data['children'])) {
    _elife_services_article_process_children($ewrapper, $data['parent'], $data['children'], $new, $processed_dois, $subarticle);
    $trigger_save = TRUE;
  }

  if ($trigger_save) {
    $ewrapper->save();
  }

  // Add or amend the content alias.
  if (!empty($data['path'])) {
    $source = 'node/' . $ewrapper->nid->value();
    // Check to see that path is unique.
    if ($new && $path = path_load(array('alias' => $data['path']))) {
      if ($path['source'] != $source) {
        return services_error(t('Path is already in use: @path', array('@path' => $data['path'])), 406);
      }
    }

    _elife_services_create_path($data['path'], $source);
  }

  return $ewrapper->raw();
}

/**
 * Prepare category or keyword term.
 *
 * @param string $vocabulary
 *   Vocabulary.
 * @param string $term_name
 *   Term name.
 * @param array $conditions
 *   Conditions on query for existing term.
 * @param array $fields
 *   Fields and values to assign to those fields.
 *
 * @return bool|mixed
 *   Created or existing term.
 */
function _elife_services_article_prepare_term($vocabulary, $term_name, $conditions = array(), $fields = array()) {
  $term_name = ElifeArticle::cleanTitle($term_name);
  $vocabulary = taxonomy_vocabulary_machine_name_load($vocabulary);
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'taxonomy_term');
  $query->propertyCondition('name', $term_name);
  $query->propertyCondition('vid', $vocabulary->vid);

  if (!empty($conditions)) {
    foreach ($conditions as $field => $value) {
      $query->fieldCondition($field, 'value', $value);
    }
  }

  $result = $query->execute();

  if (!empty($result)) {
    $term = array_pop($result['taxonomy_term']);
    $term = taxonomy_term_load($term->tid);
  }
  else {
    $values = array(
      'vid' => $vocabulary->vid,
      'name' => $term_name,
    );

    $term = entity_create('taxonomy_term', $values);
    // I had some issues when I tried to save values using
    // entity_metadata_wrapper.

    if (!empty($conditions)) {
      foreach ($conditions as $field => $value) {
        $term->{$field}[LANGUAGE_NONE] = array(array('value' => $value));
      }
    }
  }

  if (!empty($fields)) {
    foreach ($fields as $field => $value) {
      $value = !is_array($value) ? array('value' => $value) : $value;
      $term->{$field}[LANGUAGE_NONE] = array($value);
    }
  }

  entity_save('taxonomy_term', $term);

  return $term;
}

/**
 * Prepare the date value for storing in date fields.
 *
 * @param string $date
 *   Date provided as a string.
 *
 * @return int
 *   Date in unix time.
 */
function _elife_services_article_prepare_date($date) {
  // If the $date value is numeric then we will assume it is in unix time.
  if (!is_numeric($date)) {
    // Convert date string to unix time.
    $date = strtotime($date);
  }

  return $date;
}
