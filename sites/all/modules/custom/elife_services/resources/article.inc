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
function _elife_services_article_retrieve($apath) {
  $article = ElifeArticle::fromApath($apath);
  if (empty($article->nid) || $article->type !== 'elife_article') {
    return services_error(t('Article @apath not found', array('@apath' => $apath)), 404);
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
  // @todo - elife - nlisgo - we will want to delete all figure and subcomponent nodes.
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

  $ewrapper = entity_metadata_wrapper('node', $article);

  // Set the title.
  if (!empty($data['title'])) {
    $set = array(
      'value' => $data['title'],
      'format' => 'full_html',
    );
    $ewrapper->field_elife_a_full_title->set($set);
    $ewrapper->title->set(ElifeArticle::cleanTitle($set['value']));
  }

  // Set the apath if article is new.
  if ($new && !empty($data['apath'])) {
    if (!ElifeArticle::uniqueApath($data['apath'])) {
      return services_error(t('Invalid value provided: @field', array('@field' => 'apath (must be unique)')), 406);
    }

    $ewrapper->field_elife_a_apath->set($data['apath']);
  }

  if (!empty($data['doi'])) {
    if (!ElifeArticle::validateDoi($data['doi'])) {
      return services_error(t('Invalid value provided: @field', array('@field' => 'doi')), 406);
    }

    $ewrapper->field_elife_a_doi->set($data['doi']);
  }

  if (!empty($data['pdate'])) {
    $ewrapper->field_elife_a_fpubdate->set(_elife_services_article_prepare_date($data['pdate']));
  }

  if (!empty($data['update'])) {
    $ewrapper->field_elife_a_update->set(_elife_services_article_prepare_date($data['update']));
  }

  if (isset($data['early'])) {
    $ewrapper->field_elife_a_early->set(!empty($data['early']));
  }

  if (isset($data['impact_statement'])) {
    $set = array(
      'value' => $data['impact_statement'],
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

  if (!empty($data['children'])) {
    _elife_services_article_process_children($ewrapper, $data['children'], $new);
    $ewrapper->save();
  }

  return $ewrapper->raw();
}

function _elife_services_article_process_children(EntityMetadataWrapper &$ewrapper, $children, $new = FALSE) {
  $found = array();
  foreach ($children as $type => $data) {
    switch ($type) {
      case 'decision_letter':
      case 'author_response':
        $child = _elife_services_article_child_update_values($data, $new);
        $found[] = $child->nid;
        break;
    }
  }
  if (!empty($found)) {
    $ewrapper->field_elife_a_children->set($found);
  }
}

function _elife_services_article_child_update_values($data, $new = FALSE) {
  $required = array(
    'apath',
  );

  if ($new) {
    $required = array(
      'title',
      'doi',
      'pdate',
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
    $child = _elife_services_article_retrieve($data['apath']);
  }
  else {
    $values = array(
      'type' => 'elife_article',
      'uid' => _elife_services_user_uid(),
    );

    $child = entity_create('node', $values);
  }

  // Add or amend the content alias.
  if (!empty($data['path'])) {
    // Check to see that path is unique.
    if ($new && $path = path_load(array('alias' => $data['path']))) {
      if (!empty($child->nid) && $path['source'] != 'node/' . $child->nid) {
        return services_error(t('Path is already in use: @path', array('@path' => $data['path'])), 406);
      }
    }

    // If the current node has a url_alias then load the values.
    if (!empty($child->nid) && $path = path_load('node/' . $child->nid)) {
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

  // Set the title.
  if (!empty($data['title'])) {
    $set = array(
      'value' => $data['title'],
      'format' => 'full_html',
    );
    $ewrapper->field_elife_a_full_title->set($set);
    $ewrapper->title->set(ElifeArticle::cleanTitle($set['value']));
  }

  // Set the apath if article is new.
  if ($new && !empty($data['apath'])) {
    if (!ElifeArticle::uniqueApath($data['apath'])) {
      return services_error(t('Invalid value provided: @field', array('@field' => 'apath (must be unique)')), 406);
    }

    $ewrapper->field_elife_a_apath->set($data['apath']);
  }

  if (!empty($data['doi'])) {
    if (!ElifeArticle::validateDoi($data['doi'])) {
      return services_error(t('Invalid value provided: @field', array('@field' => 'doi')), 406);
    }

    $ewrapper->field_elife_a_doi->set($data['doi']);
  }

  if (!empty($data['pdate'])) {
    $ewrapper->field_elife_a_fpubdate->set(_elife_services_article_prepare_date($data['pdate']));
  }

  if (isset($data['subcomponent'])) {
    $ewrapper->field_elife_a_subcomponent->set(!empty($data['subcomponent']));
  }

  $ewrapper->save();

  return $ewrapper->raw();
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
