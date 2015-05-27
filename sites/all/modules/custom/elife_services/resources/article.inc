<?php

/**
 * @file
 * Contains the resource callbacks for articles.
 */

use Drupal\elife_article\ElifeArticle;
use Drupal\elife_article\ElifeContributor;

/**
 * Determines an API user's access to retrieve a given article.
 *
 * @param string $article_version_id
 * @return bool
 */
function _elife_services_article_retrieve_access($article_version_id) {
  // @todo - elife - nlisgo - Implement some access control.
  return TRUE;
}

/**
 * Determines an API user's access to create an article.
 *
 * @param array $data
 * @return bool
 */
function _elife_services_article_create_access($data) {
  return TRUE;
}

/**
 * Determines an API user's access to update a given article.
 *
 * @param string $article_version_id
 * @return bool
 */
function _elife_services_article_update_access($article_version_id) {
  return TRUE;
}

/**
 * Determines an API user's access to delete a given article.
 *
 * @param string $article_version_id
 * @return bool
 */
function _elife_services_article_delete_access($article_version_id) {
  return TRUE;
}

/**
 * Retrieve raw article entity.
 *
 * @param string $id
 * @param string $bundle
 * @param string $id_field
 * @param bool $trigger_error
 * @return bool|mixed
 * @throws ServicesException
 */
function _elife_services_article_retrieve_raw($id, $bundle = 'elife_article', $id_field = 'field_elife_a_article_version_id', $trigger_error = TRUE) {
  $article = ElifeArticle::fromIdentifier($id, TRUE, $bundle, 1, $id_field);
  if ($trigger_error && empty($article->nid)) {
    return services_error(t('Article version id @id not found', array('@id' => $id)), 404);
  }

  return $article;
}

/**
 * Callback function for elife_article retrieve.
 *
 * @param string $article_version_id
 * @param string $bundle
 * @return bool|mixed
 * @throws ServicesException
 */
function _elife_services_article_retrieve($article_version_id, $bundle = 'elife_article') {
  $article = _elife_services_article_retrieve_raw($article_version_id, $bundle);
  return _elife_services_article_prepare_json($article);
}

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
    elseif (isset($value['field'])) {
      $get = $ewrapper->{$value['field']}->value();

      if (isset($value['type'])) {
        if ($value['type'] == 'date') {
          $get = format_date($get, 'medium', 'Y-m-d H:i:s');
        }
      }

      if (is_array($get)) {
        $get = reset($get);
      }
    }
    elseif (isset($value['custom'])) {
      $get = call_user_func_array($value['custom'], array($article_version_id));
    }

    if ($get) {
      $json[$key] = $get;
    }
  }

  return $json;
}

/**
 * Callback function for elife_article create.
 *
 * @param $data
 * @return mixed
 */
function _elife_services_article_create($data) {
  // If force flag set then update if article-version-id recognised.
  if (!empty($data['force']) && !empty($data['article-version-id']) && !ElifeArticle::uniqueArticleVersionId($data['article-version-id'])) {
    return _elife_services_article_update($data['article-version-id'], $data);
  }
  else {
    $values = array(
      'type' => 'elife_article',
      'uid' => _elife_services_user_uid(),
    );
    $article = entity_create('node', $values);
    $article = _elife_services_article_update_values($article, $data, TRUE);
    return _elife_services_article_prepare_json($article);
  }
}

/**
 * Callback function for elife_article update.
 *
 * @param $article_version_id
 * @param $data
 * @return mixed
 */
function _elife_services_article_update($article_version_id, $data) {
  $article = _elife_services_article_retrieve_raw($article_version_id);

  $article = _elife_services_article_update_values($article, $data);
  return _elife_services_article_prepare_json($article);
}

/**
 * Callback function for elife_article delete.
 *
 * @param $article_version_id
 * @param bool $trigger_error
 * @throws Exception
 */
function _elife_services_article_delete($article_version_id, $trigger_error = TRUE) {
  $article = _elife_services_article_retrieve_raw($article_version_id, 'elife_article', 'field_elife_a_article_version_id', $trigger_error);

  if ($article) {
    /* @var EntityDrupalWrapper $ewrapper */
    $ewrapper = entity_metadata_wrapper('node', $article);

    // Remove all child nodes.
    $query = new EntityFieldQuery;
    $result = $query->fieldCondition('field_elife_a_parent', 'target_id', $ewrapper->nid->value())
      ->execute();

    if (isset($result['node']) && count($result['node'])) {
      $node_ids = array_keys($result['node']);
      node_delete_multiple($node_ids);
    }

    // Remove article node.
    $ewrapper->delete();
  }
}

/**
 * Updates specific values of an existing elife_article entity.
 *
 * @param $article
 * @param $data
 * @param bool $new
 * @return mixed
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

  // Set as published or unpublished.
  if (isset($data['publish'])) {
    $ewrapper->status->set($data['publish']);
    // @todo - elife - nlisgo - ensure that access to child nodes is dependant on parent node being published.
    // @todo - elife - nlisgo - if this is VOR and there is a POA version of this article then if publish is 1 then we should set the updated date.
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
    // @todo - elife - nlisgo - we need to store the category appropriately.
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

  // @todo - elife - nlisgo - move this into own function
  if (isset($data['referenced'])) {
    $field_basic_ref = 'field_elife_a_basic_ref';
    $field_fund_ref = 'field_elife_a_fund_ref';
    $field_aff_ref = 'field_elife_a_aff_ref';
    $field_rel_ref = 'field_elife_a_rel_ref';
    if (!$new) {
      // Delete existing referenced for this article.
      $ewrapper->{$field_basic_ref}->set();
      $ewrapper->{$field_fund_ref}->set();
      $ewrapper->{$field_aff_ref}->set();
      $ewrapper->{$field_rel_ref}->set();
      $trigger_save = TRUE;
    }

    $field_ref_key = 'field_elife_a_ref_key';

    // Save basic references.
    $field_info = field_info_field($field_basic_ref . '_type');
    if (!empty($field_info['settings']['allowed_values'])) {
      $basic_ref_types = array_keys($field_info['settings']['allowed_values']);
      foreach ($basic_ref_types as $brt) {
        if (isset($data['referenced'][$brt])) {
          foreach ($data['referenced'][$brt] as $key => $value) {
            /* @var FieldCollectionItemEntity $fc_item */
            $fc_item = entity_create('field_collection_item', array('field_name' => $field_basic_ref));
            $fc_item->setHostEntity('node', $ewrapper->raw());

            /* @var EntityDrupalWrapper $fc_wrapper */
            $fc_wrapper = entity_metadata_wrapper('field_collection_item', $fc_item);
            $fc_wrapper->{$field_basic_ref . '_type'}->set($brt);
            $fc_wrapper->{$field_ref_key}->set($key);
            $fc_wrapper->{$field_basic_ref . '_value'}->set($value);
            $fc_wrapper->save();
            $ref_links[$brt][$key] = $fc_wrapper->item_id->value();
            $trigger_save = TRUE;
          }
        }
      }
    }

    // Save funding references.
    if (isset($data['referenced']['funding'])) {
      $mappings = array(
        'id' => $field_fund_ref . '_id',
        'id-type' => $field_fund_ref . '_id_type',
        'institution' => $field_fund_ref . '_inst',
        'institution-type' => $field_fund_ref . '_inst_type',
        'award-id' => $field_fund_ref . '_award_id',
      );
      foreach ($data['referenced']['funding'] as $key => $values) {
        /* @var FieldCollectionItemEntity $fc_item */
        $fc_item = entity_create('field_collection_item', array('field_name' => $field_fund_ref));
        $fc_item->setHostEntity('node', $ewrapper->raw());

        /* @var EntityDrupalWrapper $fc_wrapper */
        $fc_wrapper = entity_metadata_wrapper('field_collection_item', $fc_item);
        $fc_wrapper->{$field_ref_key}->set($key);
        foreach ($mappings as $k => $field) {
          if (isset($values[$k])) {
            $fc_wrapper->{$field}->set($values[$k]);
          }
        }
        $fc_wrapper->save();
        $ref_links['funding'][$key] = $fc_wrapper->item_id->value();
        $trigger_save = TRUE;
      }
    }

    // Save affiliation references.
    if (isset($data['referenced']['affiliation'])) {
      $mappings = array(
        'label' => $field_aff_ref . '_label',
        'dept' => $field_aff_ref . '_dept',
        'institution' => $field_aff_ref . '_inst',
        'city' => $field_aff_ref . '_city',
        'country' => $field_aff_ref . '_country',
      );
      foreach ($data['referenced']['affiliation'] as $key => $values) {
        /* @var FieldCollectionItemEntity $fc_item */
        $fc_item = entity_create('field_collection_item', array('field_name' => $field_aff_ref));
        $fc_item->setHostEntity('node', $ewrapper->raw());

        /* @var EntityDrupalWrapper $fc_wrapper */
        $fc_wrapper = entity_metadata_wrapper('field_collection_item', $fc_item);
        $fc_wrapper->{$field_ref_key}->set($key);
        foreach ($mappings as $k => $field) {
          if (isset($values[$k])) {
            $fc_wrapper->{$field}->set($values[$k]);
          }
        }
        $fc_wrapper->save();
        $ref_links['affiliation'][$key] = $fc_wrapper->item_id->value();
        $trigger_save = TRUE;
      }
    }

    // Save related object references.
    if (isset($data['referenced']['related-object'])) {
      $mappings = array(
        'type' => $field_rel_ref . '_type',
        'source-id' => $field_rel_ref . '_src_id',
        'source-id-type' => $field_rel_ref . '_src_id_typ',
        'year' => $field_rel_ref . '_year',
        'source' => $field_rel_ref . '_src',
        'comment' => $field_rel_ref . '_comment',
      );
      foreach ($data['referenced']['related-object'] as $key => $values) {
        /* @var FieldCollectionItemEntity $fc_item */
        $fc_item = entity_create('field_collection_item', array('field_name' => $field_rel_ref));
        $fc_item->setHostEntity('node', $ewrapper->raw());

        /* @var EntityDrupalWrapper $fc_wrapper */
        $fc_wrapper = entity_metadata_wrapper('field_collection_item', $fc_item);
        $fc_wrapper->{$field_ref_key}->set($key);
        foreach ($mappings as $k => $field) {
          if (isset($values[$k])) {
            $fc_wrapper->{$field}->set($values[$k]);
          }
        }
        $fc_wrapper->save();
        $ref_links['related-object'][$key] = $fc_wrapper->item_id->value();
        $trigger_save = TRUE;
      }
    }
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
    _elife_services_article_process_children($ewrapper, $ewrapper->nid->value(), $data['children'], $new);
    $trigger_save = TRUE;
  }

  if (isset($data['citations'])) {
    _elife_services_article_process_citations($ewrapper, $ewrapper->nid->value(), $data['citations']);
    $trigger_save = TRUE;
  }

  if ($trigger_save) {
    $ewrapper->save();
  }

  if (isset($data['related-article'])) {
    _elife_services_article_process_related($ewrapper->field_elife_a_doi->value(), $ewrapper->nid->value(), $data['related-article']);
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

function _elife_services_article_process_related($doi, $source_nid, $related, $dest_nid = NULL) {
  // @todo - elife - nlisgo - related articles will need to have an endpoint for all versions of an article.
  ElifeArticle::removeRelated($source_nid, 0, $dest_nid);

  $dest_nids = array();

  $relation_bundle = 'elife_relation';

  foreach ($related as $rel) {
    if ($rel['source'] == $doi) {
      if ($dest_nid = ElifeArticle::vorFromDoi($rel['href'], FALSE)) {
        $endpoints = array(
          array(
            'entity_type' => 'node',
            'entity_id' => $source_nid,
          ),
          array(
            'entity_type' => 'node',
            'entity_id' => $dest_nid,
          ),
        );
        $new_relation = relation_create($relation_bundle, $endpoints);
        if (!empty($rel['type'])) {
          $new_relation->field_elife_r_type = array(LANGUAGE_NONE => array(array('value' => $rel['type'])));
        }
        $new_relation->field_elife_r_destination = array(LANGUAGE_NONE => array(array('value' => $rel['href'])));
        if ($rid = relation_save($new_relation)) {
          $dest_nids[] = $dest_nid;
        }
      }
    }
    elseif ($src_nid = ElifeArticle::vorFromDoi($rel['source'], FALSE)) {
      $src_nids = _elife_services_article_process_related($rel['source'], $src_nid, array($rel), $source_nid);
      if (!empty($src_nids)) {
        $dest_nids = array_merge($dest_nids, $src_nids);
      }
    }
  }

  return $dest_nids;
}

function _elife_services_article_process_citations(EntityDrupalWrapper &$ewrapper, $parent_nid, $citations) {
  $cits = array();
  if ($existing = $ewrapper->field_elife_a_citations->raw()) {
    node_delete_multiple($existing);
  }
  foreach ($citations as $cit) {
    $cit['parent'] = $parent_nid;
    $cit['article-version-id'] = $ewrapper->field_elife_a_article_version_id->value();
    $citation = _elife_services_article_citation_update_values($cit);
    $cits[] = $citation->nid;
  }
  $ewrapper->field_elife_a_citations->set($cits);
}

function _elife_services_article_citation_update_values($data) {
  $required = array(
    'id',
  );

  foreach ($required as $k => $req) {
    if (!empty($data[$req])) {
      unset($required[$k]);
    }
  }

  if (!empty($required)) {
    return services_error(t('No value provided for required: @fields', array('@fields' => implode(', ', $required))), 406);
  }

  $type = 'elife_citation';

  $values = array(
    'type' => $type,
    'uid' => _elife_services_user_uid(),
  );

  $citation = entity_create('node', $values);

  /* @var EntityDrupalWrapper $ewrapper */
  $ewrapper = entity_metadata_wrapper('node', $citation);

  $field_prefix = 'field_elife_a';
  $field_cit_prefix = $field_prefix . '_cit';
  $mappings = array(
    'id' => $field_cit_prefix . '_id',
    'parent' => $field_prefix . '_parent',
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
  foreach ($mappings as $k => $field) {
    if (isset($data[$k])) {
      $ewrapper->{$field}->set($data[$k]);
    }
  }

  $title = '';
  if (isset($data['id'])) {
    $title = $data['id'];
  }

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

function _elife_services_article_process_contributors(EntityDrupalWrapper &$ewrapper, $parent_nid, $contributors, $ref_links) {
  $contribs = array();
  foreach ($contributors as $contributor) {
    $contributor['parent'] = $parent_nid;
    $contrib = _elife_services_article_contributor_update_values($contributor, $ref_links);
    $contribs[] = $contrib->nid;
  }
  $ewrapper->field_elife_a_contributors->set($contribs);
}

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

function _elife_services_article_process_children(EntityDrupalWrapper &$ewrapper, $parent_nid, $children, $new = FALSE) {
  $found = array();
  foreach ($children as $type => $pieces) {
    switch ($type) {
      case 'sub-article':
        $subarticle = TRUE;
        foreach ($pieces as $piece) {
          $piece['parent'] = $parent_nid;
          $child = _elife_services_article_child_update_values($piece, 'elife_article', $subarticle, $new);
          $found[] = $child->nid;
        }
        break;
      case 'fragment':
        $subarticle = ($ewrapper->value()->type == 'elife_article') ? FALSE : TRUE;
        foreach ($pieces as $piece) {
          $piece['parent'] = $parent_nid;
          $child = _elife_services_article_child_update_values($piece, 'elife_fragment', $subarticle, $new);
          $found[] = $child->nid;
        }
    }
  }
  $ewrapper->field_elife_a_children->set($found);
}

function _elife_services_article_child_update_values($data, $type, $subarticle = FALSE, $new = FALSE) {
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

  if (!$new) {
    $child = _elife_services_article_retrieve_raw($data['doi'], $type, 'field_elife_a_doi');
  }
  else {
    $values = array(
      'type' => $type,
      'uid' => _elife_services_user_uid(),
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
    _elife_services_article_process_contributors($ewrapper, $data['parent'], $data['contributors'], array());
    $trigger_save = TRUE;
  }

  if (isset($data['children'])) {
    _elife_services_article_process_children($ewrapper, $data['parent'], $data['children'], $new);
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

function _elife_services_article_prepare_term($vocabulary, $term_name, $conditions = array(), $fields = array()) {
  $term_name = ElifeArticle::cleanTitle($term_name);
  $vocabulary = taxonomy_vocabulary_machine_name_load($vocabulary);
  $query = new EntityFieldQuery();
  $query = $query
    ->entityCondition('entity_type', 'taxonomy_term')
    ->propertyCondition('name', $term_name)
    ->propertyCondition('vid', $vocabulary->vid);

  if (!empty($conditions)) {
    foreach($conditions as $field => $value) {
      $query = $query
        ->fieldCondition($field, 'value', $value);
    }
  }

  $result = $query
    ->execute();

  if(!empty($result)) {
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
 * @param $date
 * @return int
 */
function _elife_services_article_prepare_date($date) {
  // If the $date value is numeric then we will assume it is in unix time.
  if (!is_numeric($date)) {
    // Convert date string to unix time.
    $date = strtotime($date);
  }

  return $date;
}
