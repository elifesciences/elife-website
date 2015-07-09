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


  public function submitQuery();

  /**
   * @param string $response
   */
  public function processResponse($response);

  /**
   * @return string
   */
  public function output();
}

