<?php

/**
 * @file
 * Contains the resource callbacks for articles.
 */

use Drupal\elife_article\ElifeArticleVersion;
use eLife\EIF\InvalidJson;
use eLife\EIF\JsonSchemaErrors;

// @todo - elife - nlisgo - ensure that when an article is updated/deleted that
// any orphaned nodes and possibly categories/keywords are removed.

// @todo - elife - nlisgo - consider possibility of ingesting multiple p tags in
// referenced simple.

// @todo - elife - nlisgo - move volume value to article from article version.

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
  $article_version = ElifeArticleVersion::fromIdentifier($id, TRUE, $bundle, 1, $id_field);
  if ($trigger_error && empty($article_version->nid)) {
    return services_error(t('Article version id @id not found', array('@id' => $id)), 404);
  }

  return $article_version;
}

/**
 * Callback function for elife_article_ver retrieve.
 *
 * @param string $article_version_id
 *   Article version id.
 * @param string $bundle
 *   Bundle/content type.
 *
 * @return string
 *   Return JSON.
 *
 * @throws ServicesException
 */
function _elife_services_article_retrieve($article_version_id, $bundle = 'elife_article_ver') {
  $article_version = _elife_services_article_retrieve_raw($article_version_id, $bundle);
  $dto = elife_article_version_to_dto($article_version);

  $json = elife_article_serializer()->serialize($dto);

  try {
    elife_article_validator()->validate($json);
  } catch (JsonSchemaErrors $e) {
    throw new ServicesException(NULL, 500, print_r($e, TRUE));
  } catch (InvalidJson $e) {
    throw new ServicesException(NULL, 500, print_r($e, TRUE));
  }

  return $json;
}

/**
 * Callback function for elife_article_ver create.
 *
 * @param string $data
 *   Article JSON submitted in the request.
 *
 * @return string
 *   Return JSON.
 */
function _elife_services_article_create($data) {
  try {
    elife_article_validator()->validate($data);
  } catch (JsonSchemaErrors $e) {
    $errors = [];
    foreach ($e->getErrors() as $error) {
      $errors[] = [
        'field' => $error->getField(),
        'message' => $error->getMessage(),
        'value' => $error->getValue(),
      ];
    }

    throw new ServicesException(NULL, 400, json_encode($errors));
  } catch (InvalidJson $e) {
    throw new ServicesException(NULL, 400, print_r($e, TRUE));
  }

  $article_version = elife_article_serializer()->deserialize($data);

  $existing = ElifeArticleVersion::fromIdentifier($article_version->getArticleVersionId());

  if ($existing) {
    node_delete($existing->nid);
  }

  $entity = elife_article_version_from_dto($article_version, _elife_services_user_uid());

  $article_entity = elife_article_from_dto($article_version, _elife_services_user_uid());

  $dto = elife_article_version_to_dto($entity);

  $json = elife_article_serializer()->serialize($dto);

  try {
    elife_article_validator()->validate($json);
  } catch (JsonSchemaErrors $e) {
    throw new ServicesException('Doh', 500);
  } catch (InvalidJson $e) {
    throw new ServicesException('Doh', 500);
  }

  return $json;
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
  return _elife_services_article_create($data);
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
  $article_version = _elife_services_article_retrieve_raw($article_version_id, 'elife_article_ver', 'field_elife_a_article_version_id', $trigger_error);

  if ($article_version) {
    /* @var EntityDrupalWrapper $ewrapper */
    $ewrapper = entity_metadata_wrapper('node', $article_version);

    // Remove article node.
    $ewrapper->delete();
  }
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
  $term_name = ElifeArticleVersion::cleanTitle($term_name);
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
