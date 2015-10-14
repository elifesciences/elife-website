<?php
/**
 * @file
 * Contains \Drupal\elife_article\MockXslMarkupService.
 */

namespace Drupal\elife_article;

final class MockXslMarkupService extends ElifeXslMarkupService {
  protected function getXml($article_id) {
    $realpath = realpath(dirname(__FILE__) . '/../../../../../../tests/behat/resources');
    $xml = file_get_contents($realpath . sprintf('/%s.xml', $article_id));
    return $xml;
  }
}

