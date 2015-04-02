<?php

/**
 * @file
 * Contains the resource callbacks for articles.
 */

/**
 * Determines an API user's access to retrieve a given article.
 *
 * @param string $short_doi
 * @return bool
 */
function _elife_services_article_retrieve_access($short_doi) {
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
function _elife_services_article_update_access($short_doi) {
  return TRUE;
}

/**
 * Determines an API user's access to delete a given article.
 *
 * @param string $short_doi
 * @return bool
 */
function _elife_services_article_delete_access($short_doi) {
  return TRUE;
}

/**
 * Callback function for elife_article retrieve.
 *
 * @param $short_doi
 * @return array
 */
function _elife_services_article_retrieve($short_doi) {
  $doi = _elife_services_doi_add_prefix($short_doi);
  $article = elife_article_from_doi($doi);
  if (empty($article->nid) || $article->type !== 'elife_article') {
    return services_error(t('Article @doi not found', array('@doi' => $doi)), 404);
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
 * @param $short_doi
 * @param $data
 * @return mixed
 */
function _elife_services_article_update($short_doi, $data) {
  $article = _elife_services_article_retrieve($short_doi);

  return _elife_services_article_update_values($article, $data);
}

/**
 * Callback function for elife_article delete.
 *
 * @param $short_doi
 */
function _elife_services_article_delete($short_doi) {
  $article = _elife_services_article_retrieve($short_doi);

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
  $required = array(
    'title',
  );

  if ($new) {
    $required[] = 'doi';
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
  if (!empty($data['title'])) {
    $ewrapper->title->set($data['title']);
  }
  if ($new && !empty($data['doi'])) {
    if (!elife_article_validate_doi($data['doi'], TRUE)) {
      return services_error(t('Invalid value provided : @field', array('@field' => 'doi')), 406);
    }

    $ewrapper->field_elife_a_doi->set($data['doi']);
  }


  $ewrapper->save();

  return $ewrapper->raw();
}

/**
 * Convert the short doi to the standard doi string.
 *
 * @param $short_doi
 * @return string
 */
function _elife_services_doi_add_prefix($short_doi) {
  return ELIFE_ARTICLE_DOI_PREFIX . $short_doi;
}
