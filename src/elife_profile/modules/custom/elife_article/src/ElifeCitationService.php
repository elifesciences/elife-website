<?php
/**
 * @file
 * Contains \Drupal\elife_article\ElifeCitationService.
 */

namespace Drupal\elife_article;


use eLifeIngestXsl\ConvertXML\XMLString;
use eLifeIngestXsl\ConvertXMLToBibtex;
use eLifeIngestXsl\ConvertXMLToRis;

class ElifeCitationService {
  protected $article_id = '';
  protected $formats = [];

  /**
   * @param string $article_id
   */
  public function setId($article_id) {
    if ($article_id != $this->article_id) {
      $this->article_id = $article_id;
    }
  }

  /**
   * @return string
   */
  public function getId() {
    return $this->article_id;
  }

  public function submitQuery() {
    $xml = $this->getXml($this->article_id);
    $bibtex = new ConvertXMLToBibtex(XMLString::fromString($xml));
    $ris = new ConvertXMLToRis(XMLString::fromString($xml));
    $this->formats = [
      'bibtex' => $bibtex->getOutput(),
      'ris' => $ris->getOutput(),
    ];
  }

  public function getFormats() {
    return $this->formats;
  }

  /**
   * @param string $format
   * @return mixed
   */
  public function getFormat($format) {
    return $this->formats[$format];
  }

  /**
   * @param string $article_id
   * @return string
   */
  protected function getXml($article_id) {
    return file_get_contents(sprintf('https://s3.amazonaws.com/elife-cdn/elife-articles/%s/elife%s.xml', $article_id, $article_id));
  }
}

