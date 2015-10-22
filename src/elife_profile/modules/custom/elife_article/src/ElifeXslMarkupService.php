<?php
/**
 * @file
 * Contains \Drupal\elife_article\ElifeXslMarkupService.
 */

namespace Drupal\elife_article;

use eLifeIngestXsl\ConvertXML\XMLString;
use eLifeIngestXsl\ConvertXMLToHtml;
use Exception;

class ElifeXslMarkupService extends ElifeMarkupService {
  private $queries = [];
  private $arrange_queries = [];
  private $response = 'response';
  private $error = 'error';
  private $results = [];
  private $methods = [
    'aff' => 'getAffiliation',
    'doi' => 'getDoi',
    'main-text' => 'getMainText',
    'abstract' => 'getAbstract',
    'digest' => 'getDigest',
    'references' => 'getReferences',
    'acknowledgements' => 'getAcknowledgements',
    'decision-letter' => 'getDecisionLetter',
    'author-response' => 'getAuthorResponse',
    'datasets' => 'getDatasets',
  ];
  private $htmls = [];
  private $xmls = [];

  /**
   * @param string $article_version_id
   * @param string $section
   * @param string $value
   */
  private function addQuery($article_version_id, $section, $value = NULL) {
    $query_id = [$article_version_id, $section];
    $method = $this->methods[$section];

    $query = ['method' => $method, 'params' => []];

    if ($value) {
      $query['params'] = [$value];
      $query_id[] = $value;
    }

    $this->queries[implode('::', $query_id)] = $query;
  }

  private function arrangeQuery() {
    $this->arrange_queries = [];
    foreach ($this->queries as $query_id => $query) {
      list($article_version_id) = explode('::', $query_id);
      $this->arrange_queries[$article_version_id][$query_id] = $query;
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
   * @param string $article_version_id
   * @param string|array $section
   */
  public function addSectionQuery($article_version_id, $section) {
    $sections = (!is_array($section)) ? [$section] : $section;
    foreach ($sections as $section) {
      $this->addQuery($article_version_id, $section);
    }
  }

  /**
   * @param string $article_version_id
   * @param string $doi
   */
  public function addDoiQuery($article_version_id, $doi) {
    $this->addQuery($article_version_id, 'doi', $doi);
  }

  /**
   * @param string $article_version_id
   * @param string $aff_id
   */
  public function addAffiliationQuery($article_version_id, $aff_id) {
    $this->addQuery($article_version_id, 'aff', $aff_id);
  }

  public function submitQuery() {
    $queries = $this->getQuery();
    $this->htmls = [];
    $this->results = [];
    foreach ($queries as $article_version_id => $article_ver_queries) {
      $html = $this->retrieveHtml($article_version_id);
      foreach ($article_ver_queries as $article_ver_query) {
        $query_id = array_merge([array_search($article_ver_query['method'], $this->methods)], $article_ver_query['params']);
        $query_id = implode('::', $query_id);

        $res = call_user_func_array([$html, $article_ver_query['method']], $article_ver_query['params']);
        $this->results[$article_version_id][$query_id] = [];
        if (!empty($res)) {
          $this->results[$article_version_id][$query_id][] = $this->postQueryProcess($res);
        }
      }
    }
  }

  /**
   * @param string $markup
   * @return string mixed
   */
  protected function postQueryProcess($markup) {
    // @todo - elife - nlisgo - Introduce post process steps here.
    // For example substitute paths to files.
    return $markup;
  }

  /**
   * @param string $article_version_id
   * @return ConvertXMLToHtml
   */
  public function retrieveHtml($article_version_id) {
    $xml = $this->retrieveXml($article_version_id);
    if (!empty($xml)) {
      $convert_xml_to_html = $this->retrieveHtmlCache($article_version_id);
      if (!empty($convert_xml_to_html[$article_version_id])) {
        return $convert_xml_to_html[$article_version_id];
      }
    }
  }

  /**
   * @param string $article_version__id
   * @return ConvertXMLToHtml[]
   */
  public function retrieveHtmlCache($article_version_id) {
    $cache = &drupal_static(__FUNCTION__, []);

    if (!isset($cache[$article_version_id])) {
      $xml = $this->retrieveXml($article_version_id);
      if (!empty($xml)) {
        $convert_xml_to_html = new ConvertXMLToHtml(XMLString::fromString($xml));
        $cache[$article_version_id] = $convert_xml_to_html;
      }
    }

    return $cache;
  }

  public function retrieveXml($article_version_id) {
    $xml = $this->retrieveXmlCache($article_version_id);
    if (!empty($xml[$article_version_id])) {
      return $xml[$article_version_id];
    }
  }

  private function retrieveXmlCache($article_version_id) {
    $cache = &drupal_static(__FUNCTION__, []);

    if (!isset($cache[$article_version_id])) {
      $xml = $this->getXml($article_version_id);
      $cache[$article_version_id] = $xml;
    }

    return $cache;
  }

  public function setXml($article_version_id, $xml = NULL) {
    if (!isset($this->xmls[$article_version_id])) {
      if (empty($xml)) {
        $xml = elife_article_version_source_xml_path($article_version_id);
      }
      $this->xmls[$article_version_id] = file_get_contents($xml);
    }
  }

  protected function getXml($article_version_id) {
    if (!isset($this->xmls[$article_version_id])) {
      $this->setXml($article_version_id);
    }
    return $this->xmls[$article_version_id];
  }

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
   * @param string $article_version_id
   *   Article id.
   *
   * @return array
   *   Array of results.
   * @throws \Exception
   */
  public function getResult($article_version_id) {
    if (empty($this->results)) {
      $this->processResponse();
    }
    $results = (isset($this->results[$article_version_id])) ? $this->results[$article_version_id] : [];

    return $results;
  }

  /**
   * @return string
   *   HTML output from markup query.
   */
  public function output() {
    $results = $this->getResults();
    $output = '';
    foreach ($results as $article_ver_queries) {
      foreach ($article_ver_queries as $data) {
        $output .= implode("\n", $data);
      }
    }

    return $output;
  }
}

