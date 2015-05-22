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
      'type' => 'int',
    ),
    'article-id' => array(
      'field' => 'field_elife_a_article_id',
      'type' => 'string',
    ),
    'version' => array(
      'field' => 'field_elife_a_version',
      'type' => 'int',
    ),
    'article-version-id' => $article_version_id,
    'publish' => array(
      'field' => 'status',
      'type' => 'int',
    ),
    'status' => array(
      'field' => 'field_elife_a_status',
      'type' => 'string',
    ),
    'path' => array(
      'custom' => 'Drupal\elife_article\ElifeArticle::getPath',
    ),
    'article-type' => array(
      'field' => 'field_elife_a_article_type',
      'type' => 'string',
    ),
  );

  $json = array();

  foreach ($top_level as $key => $value) {
    $get = NULL;
    if (isset($value['field'])) {
      $get = $ewrapper->{$value['field']}->value();

      if (is_array($get)) {
        $get = reset($get);
      }
    }
    elseif (isset($value['custom'])) {
      $get = call_user_func_array($value['custom'], array($article_version_id));
    }
    else {
      $get = $value;
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
  $values = array(
    'type' => 'elife_article',
    'uid' => _elife_services_user_uid(),
  );

  $article = entity_create('node', $values);
  $article = _elife_services_article_update_values($article, $data, TRUE);
  return _elife_services_article_prepare_json($article);
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

    $ewrapper->field_elife_a_article_version_id->set($data['article-version-id']);
  }

  if (isset($data['doi'])) {
    if (!ElifeArticle::validateDoi($data['doi'])) {
      return services_error(t('Invalid value provided: @field', array('@field' => 'doi')), 406);
    }

    $ewrapper->field_elife_a_doi->set($data['doi']);
  }

  if (isset($data['article-id'])) {
    $ewrapper->field_elife_a_article_id->set($data['article-id']);
  }

  if (isset($data['version'])) {
    $ewrapper->field_elife_a_version->set($data['version']);
  }

  if (isset($data['pub-date'])) {
    $ewrapper->field_elife_a_fpubdate->set(_elife_services_article_prepare_date($data['pub-date']));
  }

  if (isset($data['update'])) {
    $ewrapper->field_elife_a_update->set(_elife_services_article_prepare_date($data['update']));
  }

  if (isset($data['status'])) {
    $ewrapper->field_elife_a_status->set($data['status']);
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
  // @todo - elife - nlisgo - move this into own function
  if (isset($data['referenced'])) {
    if (!$new) {
      // Delete existing referenced for this article.
      $referenced = ElifeArticle::getReferences($ewrapper->nid->value());
      foreach ($referenced as $type => $refs) {
        foreach ($refs as $ref) {
          field_collection_item_delete($ref);
        }
      }
      $ewrapper->{$field_basic_ref}->set();
      $trigger_save = TRUE;
    }

    // Save basic references.
    $field_basic_ref = 'field_elife_a_basic_ref';
    $field_info = field_info_field($field_basic_ref . '_type');
    if (!empty($field_info['settings']['allowed_values'])) {
      $basic_ref_types = array_keys($field_info['settings']['allowed_values']);
      foreach ($basic_ref_types as $brt) {
        if (isset($data['referenced'][$brt])) {
          foreach ($data['referenced'][$brt] as $key => $value) {
            $fc_item = entity_create('field_collection_item', array('field_name' => $field_basic_ref));
            $fc_item->setHostEntity('node', $ewrapper->raw());

            /* @var EntityDrupalWrapper $fc_wrapper */
            $fc_wrapper = entity_metadata_wrapper('field_collection_item', $fc_item);
            $fc_wrapper->{$field_basic_ref . '_type'}->set($brt);
            $fc_wrapper->{$field_basic_ref . '_key'}->set($key);
            $fc_wrapper->{$field_basic_ref . '_value'}->set($value);
            $fc_wrapper->save();
            $trigger_save = TRUE;
          }
        }
      }
    }

    // Save funding references.
    if (isset($data['referenced']['fundings'])) {
      $field_fund_ref = 'field_elife_a_fund_ref';
      foreach ($data['referenced']['fundings'] as $key => $values) {
        $fc_item = entity_create('field_collection_item', array('field_name' => $field_fund_ref));
        $fc_item->setHostEntity('node', $ewrapper->raw());

        /* @var EntityDrupalWrapper $fc_wrapper */
        $fc_wrapper = entity_metadata_wrapper('field_collection_item', $fc_item);
        $fc_wrapper->{$field_fund_ref . '_key'}->set($key);
        $mappings = array(
          'id' => $field_fund_ref . '_id',
          'id-type' => $field_fund_ref . '_id_type',
          'institution' => $field_fund_ref . '_inst',
          'institution-type' => $field_fund_ref . '_inst_type',
          'award-id' => $field_fund_ref . '_award_id',
        );
        foreach ($mappings as $k => $field) {
          if (isset($values[$k])) {
            $fc_wrapper->{$field}->set($values[$k]);
          }
        }
        $fc_wrapper->save();
        $trigger_save = TRUE;
      }
    }

    // Save affiliation references.
    if (isset($data['referenced']['affiliations'])) {
      $field_aff_ref = 'field_elife_a_aff_ref';
      foreach ($data['referenced']['affiliations'] as $key => $values) {
        $fc_item = entity_create('field_collection_item', array('field_name' => $field_aff_ref));
        $fc_item->setHostEntity('node', $ewrapper->raw());

        /* @var EntityDrupalWrapper $fc_wrapper */
        $fc_wrapper = entity_metadata_wrapper('field_collection_item', $fc_item);
        $fc_wrapper->{$field_aff_ref . '_key'}->set($key);
        $mappings = array(
          'label' => $field_aff_ref . '_label',
          'dept' => $field_aff_ref . '_dept',
          'institution' => $field_aff_ref . '_inst',
          'city' => $field_aff_ref . '_city',
          'country' => $field_aff_ref . '_country',
        );
        foreach ($mappings as $k => $field) {
          if (isset($values[$k])) {
            $fc_wrapper->{$field}->set($values[$k]);
          }
        }
        $fc_wrapper->save();
        $trigger_save = TRUE;
      }
    }

    // Save related object references.
    if (isset($data['referenced']['related-objects'])) {
      $field_rel_ref = 'field_elife_a_rel_ref';
      foreach ($data['referenced']['related-objects'] as $key => $values) {
        $fc_item = entity_create('field_collection_item', array('field_name' => $field_rel_ref));
        $fc_item->setHostEntity('node', $ewrapper->raw());

        /* @var EntityDrupalWrapper $fc_wrapper */
        $fc_wrapper = entity_metadata_wrapper('field_collection_item', $fc_item);
        $fc_wrapper->{$field_rel_ref . '_key'}->set($key);
        $mappings = array(
          'type' => $field_rel_ref . '_type',
          'source-id' => $field_rel_ref . '_src_id',
          'source-id-type' => $field_rel_ref . '_src_id_typ',
          'year' => $field_rel_ref . '_year',
          'src' => $field_rel_ref . '_src',
          'comment' => $field_rel_ref . '_comment',
        );
        foreach ($mappings as $k => $field) {
          if (isset($values[$k])) {
            $fc_wrapper->{$field}->set($values[$k]);
          }
        }
        $fc_wrapper->save();
        $trigger_save = TRUE;
      }
    }
  }

  if (isset($data['contributors'])) {
    _elife_services_article_process_contributors($ewrapper, $data['contributors'], $new);
    $trigger_save = TRUE;
  }

  if (isset($data['children'])) {
    _elife_services_article_process_children($ewrapper, $ewrapper->nid->value(), $data['children'], $new);
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

function _elife_services_article_process_contributors(EntityMetadataWrapper &$ewrapper, $contributors, $new = FALSE) {
  $contribs = array();
  if (!$new) {
    if ($existing = $ewrapper->field_elife_a_contributors->raw()) {
      node_delete_multiple($existing);
    }
  }
  foreach ($contributors as $contributor) {
    $contributor['parent'] = $ewrapper->nid->value();
    $contrib = _elife_services_article_contributor_update_values($contributor, $new);
    $contribs[] = $contrib->nid;
  }
  $ewrapper->field_elife_a_contributors->set($contribs);
}

function _elife_services_article_contributor_update_values($data, $new = FALSE) {
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

  if (!empty($either) && !$id_found) {
    return services_error(t('No value provided for required: @fields', array('@fields' => implode(' or ', $either))), 406);
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

  $title = $data[$id_found];
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
    $title .= ' (' . implode(' ', $title_ext) . ')';
  }

  $ewrapper->title->set($title);

  $ewrapper->save();

  return $ewrapper->raw();

}

function _elife_services_article_process_children(EntityMetadataWrapper &$ewrapper, $parent_nid, $children, $new = FALSE) {
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
      'title',
      'doi',
      'path',
    );

    if ($data['type'] == 'abstract' && empty($data['title'])) {
      $data['title'] = t('Abstract');
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

  $ewrapper->save();

  if (isset($data['children'])) {
    _elife_services_article_process_children($ewrapper, $data['parent'], $data['children'], $new);
    // @todo - elife - nlisgo - saving again causes duplicate entry in url_alias
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
