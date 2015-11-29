<?php
/**
 * @file
 * Contains \Drupal\elife_article\MockMarkupService.
 */

namespace Drupal\elife_article;

use Exception;

final class MockMarkupService extends ElifeMarkupService {
  private $queries = [];
  private $arrange_queries = [];
  private $response = 'response';
  private $error = 'error';
  private $results = [];

  /**
   * @param string $article_id
   * @param string $section
   * @param string $value
   */
  private function addQuery($article_id, $section, $value = NULL) {
    $query_id = [$article_id, $section];
    $this->queries[implode('::', $query_id)] = (!is_null($value)) ? $value : $section;
  }

  private function arrangeQuery() {
    $this->arrange_queries = [];
    foreach ($this->queries as $query_id => $query) {
      list($article_id) = explode('::', $query_id);
      $this->arrange_queries[$article_id][$query_id] = $query;
    }
  }

  /**
   * @return array
   *   Array of arranged queries.
   */
  public function getQuery() {
    $this->arrangeQuery();
    return $this->arrange_queries;
  }

  /**
   * @param string $article_id
   * @param string|array $section
   */
  public function addSectionQuery($article_id, $section) {
    $sections = (!is_array($section)) ? [$section] : $section;
    foreach ($sections as $section) {
      $value = (in_array($section, ['metatags', 'original-article'])) ? '' : NULL;
      $this->addQuery($article_id, $section, $value);
    }
  }

  /**
   * @param string $article_id
   * @param string $doi
   */
  public function addDoiQuery($article_id, $doi) {
    $this->addQuery($article_id, 'doi', $doi);
  }

  /**
   * @param string $article_id
   * @param string|null $doi
   */
  public function addDcDescriptionQuery($article_id, $doi = NULL) {
    $this->addQuery($article_id, 'doi', $doi);
  }

  /**
   * @param string $article_id
   * @param string $aff_id
   */
  public function addAffiliationQuery($article_id, $aff_id) {
    $this->addQuery($article_id, 'aff', $aff_id);
  }

  /**
   * @param string $article_id
   * @param string $author_pos
   */
  public function addAuthorAffiliationQuery($article_id, $author_pos) {
    $this->addQuery($article_id, 'author-aff', $author_pos);
  }

  public function submitQuery() {}

  public function processResponse() {
    $this->results = $this->queries;
  }

  /**
   * @return string
   *   Return response string.
   */
  public function getResponse() {
    return $this->response;
  }

  /**
   * @return string
   *   Return error string.
   */
  public function getError() {
    return $this->error;
  }

  /**
   * @return array
   *   Return error string.
   */
  public function getResults() {
    if (empty($this->results)) {
      $this->processResponse();
    }

    return $this->results;
  }

  /**
   * @return array
   *   Return error string.
   */

  /**
   * @param string $article_id
   *   Article id.
   *
   * @return array
   *   Array of results.
   * @throws \Exception
   */
  public function getResult($article_id) {
    if (empty($this->results)) {
      $this->processResponse();
    }
    $results = (isset($this->results[$article_id])) ? $this->results[$article_id] : [];

    return $results;
  }

  /**
   * @return string
   *   HTML output from markup query.
   */
  public function output() {
    return implode("\n", array_values($this->getResults()));
  }
}

