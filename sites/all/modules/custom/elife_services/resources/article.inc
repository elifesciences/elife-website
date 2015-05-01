<?php

/**
 * @file
 * Contains the resource callbacks for articles.
 */

use Drupal\elife_article\ElifeArticle;

/**
 * Determines an API user's access to retrieve a given article.
 *
 * @param string $apath
 * @return bool
 */
function _elife_services_article_retrieve_access($apath) {
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
 * @param string $apath
 * @return bool
 */
function _elife_services_article_update_access($apath) {
  return TRUE;
}

/**
 * Determines an API user's access to delete a given article.
 *
 * @param string $apath
 * @return bool
 */
function _elife_services_article_delete_access($apath) {
  return TRUE;
}

/**
 * Callback function for elife_article retrieve.
 *
 * @param $apath
 * @return array
 */
function _elife_services_article_retrieve($apath, $bundle = 'elife_article') {
  $article = ElifeArticle::fromApath($apath, TRUE, $bundle);
  if (empty($article->nid)) {
    return services_error(t('Apath @apath not found', array('@apath' => $apath)), 404);
  }

  return $article;
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
  return _elife_services_article_update_values($article, $data, TRUE);
}

/**
 * Callback function for elife_article update.
 *
 * @param $apath
 * @param $data
 * @return mixed
 */
function _elife_services_article_update($apath, $data) {
  $article = _elife_services_article_retrieve($apath);

  return _elife_services_article_update_values($article, $data);
}

/**
 * Callback function for elife_article delete.
 *
 * @param $apath
 */
function _elife_services_article_delete($apath) {
  $article = _elife_services_article_retrieve($apath);
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
      'pdate',
      'path',
      'apath',
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

  // Add or amend the content alias.
  if (!empty($data['path'])) {
    // Check to see that path is unique.
    if ($new && $path = path_load(array('alias' => $data['path']))) {
      if (!empty($article->nid) && $path['source'] != 'node/' . $article->nid) {
        return services_error(t('Path is already in use: @path', array('@path' => $data['path'])), 406);
      }
    }

    // If the current node has a url_alias then load the values.
    if (!empty($article->nid) && $path = path_load('node/' . $article->nid)) {
      $article_path = $path;
    }
    else {
      $article_path = array();
    }

    $article_path['alias'] = $data['path'];
    $article_path['pathauto'] = FALSE;
    $article->path = $article_path;
  }

  // We must do this here until nlmfield has a property callback.
  if (isset($data['contributors'])) {
    // @todo - elife - nlisgo - remove this after https://www.drupal.org/node/2480791
    nlmfield_load_library();
    $contributors = array();
    foreach ($data['contributors'] as $contributor) {
      $contributor = array('xml' => $contributor);
      $contributors[] = nlmfield_compute_values($contributor, 'nlmfield_contributor');
    }
    $article->field_elife_a_contributors[LANGUAGE_NONE] = $contributors;
  }

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
    foreach ($data['keywords'] as $keyword) {
      $fields = array(
        'field_elife_a_full_title' => array(
          'value' => $keyword,
          'format' => 'full_html',
        ),
      );
      if ($term = _elife_services_article_prepare_term('elife_keywords', $keyword, array(), $fields)) {
        $keywords[] = $term->tid;
      }
    }
    $ewrapper->field_elife_a_keyword->set($keywords);
  }

  // Set the apath if article is new.
  if ($new && !empty($data['apath'])) {
    if (!ElifeArticle::uniqueApath($data['apath'])) {
      return services_error(t('Invalid value provided: @field', array('@field' => 'apath (must be unique)')), 406);
    }

    $ewrapper->field_elife_a_apath->set($data['apath']);
  }

  if (isset($data['doi'])) {
    if (!ElifeArticle::validateDoi($data['doi'])) {
      return services_error(t('Invalid value provided: @field', array('@field' => 'doi')), 406);
    }

    $ewrapper->field_elife_a_doi->set($data['doi']);
  }

  if (isset($data['pdate'])) {
    $ewrapper->field_elife_a_fpubdate->set(_elife_services_article_prepare_date($data['pdate']));
  }

  if (isset($data['update'])) {
    $ewrapper->field_elife_a_update->set(_elife_services_article_prepare_date($data['update']));
  }

  if (isset($data['early'])) {
    $ewrapper->field_elife_a_early->set(!empty($data['early']));
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

  if (isset($data['children'])) {
    _elife_services_article_process_children($ewrapper, $ewrapper->nid->value(), $data['children'], $new);
    $ewrapper->save();
  }

  return $ewrapper->raw();
}

function _elife_services_article_process_children(EntityMetadataWrapper &$ewrapper, $parent_nid, $children, $new = FALSE) {
  $found = array();
  foreach ($children as $type => $pieces) {
    switch ($type) {
      case 'subcomponent':
        $subcomponent = TRUE;
        foreach ($pieces as $piece) {
          $piece['parent'] = $parent_nid;
          $child = _elife_services_article_child_update_values($piece, 'elife_article', $subcomponent, $new);
          $found[] = $child->nid;
        }
        break;
      case 'figure':
        $subcomponent = ($ewrapper->value()->type == 'elife_article') ? FALSE : TRUE;
        foreach ($pieces as $piece) {
          $piece['parent'] = $parent_nid;
          $child = _elife_services_article_child_update_values($piece, 'elife_fragment', $subcomponent, $new);
          $found[] = $child->nid;
        }
    }
  }
  $ewrapper->field_elife_a_children->set($found);
}

function _elife_services_article_child_update_values($data, $type, $subcomponent = FALSE, $new = FALSE) {
  $required = array(
    'apath',
  );

  if ($new) {
    $required = array(
      'title',
      'doi',
      'path',
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

  if (!$new) {
    $child = _elife_services_article_retrieve($data['apath'], $type);
  }
  else {
    $values = array(
      'type' => $type,
      'uid' => _elife_services_user_uid(),
    );

    $child = entity_create('node', $values);
  }

  // Add or amend the content alias.
  if (isset($data['path'])) {
    // Check to see that path is unique.
    if ($new && $path = path_load(array('alias' => $data['path']))) {
      if (!empty($child->nid) && $path['source'] != 'node/' . $child->nid) {
        return services_error(t('Path is already in use: @path', array('@path' => $data['path'])), 406);
      }
    }

    // If the current node has a url_alias then load the values.
    if (isset($child->nid) && $path = path_load('node/' . $child->nid)) {
      $child_path = $path;
    }
    else {
      $child_path = array();
    }

    $child_path['alias'] = $data['path'];
    $child_path['pathauto'] = FALSE;
    $child->path = $child_path;
  }

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

  // Set the apath if article is new.
  if ($new && isset($data['apath'])) {
    if (!ElifeArticle::uniqueApath($data['apath'])) {
      return services_error(t('Invalid value provided: @field', array('@field' => 'apath (must be unique)')), 406);
    }

    $ewrapper->field_elife_a_apath->set($data['apath']);
  }

  if (isset($data['doi'])) {
    if (!ElifeArticle::validateDoi($data['doi'])) {
      return services_error(t('Invalid value provided: @field', array('@field' => 'doi')), 406);
    }

    $ewrapper->field_elife_a_doi->set($data['doi']);
  }

  if (isset($data['pdate'])) {
    $ewrapper->field_elife_a_fpubdate->set(_elife_services_article_prepare_date($data['pdate']));
  }

  $ewrapper->field_elife_a_subcomponent->set($subcomponent);

  $ewrapper->save();

  if (!$subcomponent && isset($data['children'])) {
    _elife_services_article_process_children($ewrapper, $data['parent'], $data['children'], $new);
    $ewrapper->save();
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
