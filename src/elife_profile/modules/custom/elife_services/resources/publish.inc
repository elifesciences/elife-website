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
  $node = ElifeArticleVersion::fromId($article_version_id, TRUE, 'elife_article_ver', ['DANGEROUS_ACCESS_CHECK_OPT_OUT'], 1, 'field_elife_a_article_version_id');
  return empty($node) || node_access('update', $node);
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

    $dto = elife_article_version_to_dto($ewrapper->raw());

    if ($dto->getPubDate()) {
      $response['pub-date'] = $dto->getPubDate()->format('Y-m-d');
    }

    if ($dto->getUpdate()) {
      $response['update'] = $dto->getUpdate()->format('Y-m-d');
    }

    return json_encode($response);
  }
}
