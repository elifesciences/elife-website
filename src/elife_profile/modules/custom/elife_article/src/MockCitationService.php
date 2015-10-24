<?php
/**
 * @file
 * Contains \Drupal\elife_article\MockCitationService.
 */

namespace Drupal\elife_article;

final class MockCitationService extends ElifeCitationService {
  private $disable = FALSE;

  public function disableQuery() {
    $this->disable = TRUE;
  }

  public function submitQuery() {
    if (!$this->disable) {
      parent::submitQuery();
    }
    else {
      $this->formats = [
        'bibtex' => 'Bibtext output',
        'ris' => 'Ris output',
      ];
    }
  }

  /**
   * @param string $article_version_id
   * @return string
   */
  protected function getXml($article_version_id) {
    $realpath = realpath(dirname(__FILE__) . '/../../../../../../tests/behat/resources');
    $xml = file_get_contents($realpath . sprintf('/%s.xml', $article_version_id));
    return $xml;
  }
}

