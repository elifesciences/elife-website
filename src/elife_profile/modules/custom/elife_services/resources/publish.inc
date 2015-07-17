<?php

/**
 * @file
 * Contains the resource callbacks for articles.
 */

use Drupal\elife_article\ElifeArticleVersion;

/**
 * Determines an API user's access to publish a given article.
 *
 * @param string $article_version_id
 *   Article version id.
 *
 * @return bool
 *   returns TRUE or FALSE
 */
function _elife_services_publish_access($article_version_id) {
  // @todo - elife - nlisgo - Implement some access control.
  return TRUE;
}

/**
 * Callback function for elife_article_ver publish.
 *
 * @param string $article_version_id
 *   Article version id.
 * @param array $data
 *   Article data submitted in the request.
 *
 * @return mixed
 *   Return array to be output as json.
 */
function _elife_services_publish($article_version_id, $data) {
  $article_version = ElifeArticleVersion::fromIdentifier($article_version_id, TRUE, 'elife_article_ver', 1, 'field_elife_a_article_version_id', TRUE);
  if (empty($article_version->nid)) {
    return services_error(t('Article version id @id not found', array('@id' => $article_version_id)), 404);
  }

  $json = json_decode($data, TRUE);
  if (isset($json['publish'])) {
    /* @var EntityDrupalWrapper $ewrapper */
    $ewrapper = entity_metadata_wrapper('node', $article_version);

    // Set publish state of entity.
    $ewrapper->status->set((int) $json['publish']);
    $ewrapper->save();
    $response = [
      'publish' => (string) $ewrapper->status->value(),
    ];

    return json_encode($response);
  }
}