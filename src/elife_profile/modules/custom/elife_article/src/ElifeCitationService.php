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
  protected $article_version_id = '';
  protected $formats = [];
  protected $xmls = [];

  /**
   * @param string $article_version_id
   */
  public function setId($article_version_id) {
    if ($article_version_id != $this->article_version_id) {
      $this->article_version_id = $article_version_id;
    }
  }

  /**
   * @return string
   */
  public function getId() {
    return $this->article_version_id;
  }

  public function submitQuery() {
    $xml = $this->getXml($this->article_version_id);
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

  public function setXml($article_version_id, $xml = NULL) {
    if (!isset($this->xmls[$article_version_id])) {
      if (empty($xml)) {
        $xml = elife_article_version_source_xml_path($article_version_id);
      }

      $this->xmls[$article_version_id] = file_get_contents($xml);
    }
  }

  /**
   * @param string $article_version_id
   * @return string
   */
  protected function getXml($article_version_id) {
    if (!isset($this->xmls[$article_version_id])) {
      $this->setXml($article_version_id);
    }
    return $this->xmls[$article_version_id];
  }
}

