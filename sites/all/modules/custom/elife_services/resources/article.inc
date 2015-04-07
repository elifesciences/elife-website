<?php

/**
 * @file
 * Contains the resource callbacks for articles.
 */

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
 * @param string $short_doi
 * @return bool
 */
function _elife_services_article_update_access($apath) {
  return TRUE;
}

/**
 * Determines an API user's access to delete a given article.
 *
 * @param string $short_doi
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
  $article = elife_article_from_apath($apath);
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
    );

    if (empty($data['auto'])) {
      $required[] = 'apath';
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

  $ewrapper = entity_metadata_wrapper('node', $article);

  // Set the title.
  if (!empty($data['title'])) {
    $ewrapper->title->set($data['title']);
  }

  // Set the apath if article is new.
  if ($new && !empty($data['apath']) && empty($data['auto'])) {
    if (!elife_article_unique_apath($data['apath'])) {
      return services_error(t('Invalid value provided: @field', array('@field' => 'apath')), 406);
    }

    $ewrapper->field_elife_a_apath->set($data['apath']);
  }

  if (!empty($data['doi'])) {
    if (!elife_article_validate_doi($data['doi'])) {
      return services_error(t('Invalid value provided: @field', array('@field' => 'doi')), 406);
    }

    $ewrapper->field_elife_a_doi->set($data['doi']);
  }

  $ewrapper->save();

  // Set apath if it is to be set automatically.
  if ($new && !empty($data['auto'])) {
    $ewrapper->field_elife_a_apath->set('id_' . $ewrapper->nid->value());
    $ewrapper->save();
  }

  return $ewrapper->raw();
}
