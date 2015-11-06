<?php
/**
 * @file
 * Contains \Drupal\elife_article\ElifeMarkupServiceInterface.
 */

namespace Drupal\elife_article;

interface ElifeMarkupServiceInterface {
  /**
   * @param string $article_id
   * @param string $section
   */
  public function addSectionQuery($article_id, $section);

  /**
   * @param string $article_id
   * @param string $doi
   */
  public function addDoiQuery($article_id, $doi);

  /**
   * @param string $article_id
   * @param string $aff_id
   */
  public function addAffiliationQuery($article_id, $aff_id);

  /**
   * @param string $article_id
   * @param int $author_pos
   */
  public function addAuthorAffiliationQuery($article_id, $author_pos);

  public function getQuery();

  public function submitQuery();

  public function preloadReplacements();

  public function processResponse();

  public function getResponse();

  public function getError();

  /**
   * @return array
   */
  public function getResults();

  /**
   * @param string $article_id
   * @return array
   */
  public function getResult($article_id);

  /**
   * @return string
   */
  public function output();
}

