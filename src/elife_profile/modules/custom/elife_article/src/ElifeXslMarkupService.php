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

  /**
   * @param string $article_id
   * @param string $section
   * @param string $value
   */
  private function addQuery($article_id, $section, $value = NULL) {
    $query_id = [$article_id, $section];
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
      $this->addQuery($article_id, $section);
    }
  }

  /**
   * @param string $article_id
   * @param string $doi
   */
  public function addDoiQuery($article_id, $doi) {
    $this->addQuery($article_id, 'doi', $doi);
  }

  public function submitQuery() {
    $queries = $this->getQuery();
    $this->htmls = [];
    $this->results = [];
    foreach ($queries as $article_id => $article_queries) {
      $html = $this->retrieveHtml($article_id);
      foreach ($article_queries as $article_query) {
        $query_id = array_merge([array_search($article_query['method'], $this->methods)], $article_query['params']);
        $query_id = implode('::', $query_id);

        $res = call_user_func_array([$html, $article_query['method']], $article_query['params']);
        $this->results[$article_id][$query_id] = [];
        if (!empty($res)) {
          $this->results[$article_id][$query_id][] = $this->postQueryProcess($res);
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
   * @param string $article_id
   * @return ConvertXMLToHtml
   */
  public function retrieveHtml($article_id) {
    $xml = $this->retrieveXml($article_id);
    if (!empty($xml)) {
      $convert_xml_to_html = $this->retrieveHtmlCache($article_id);
      if (!empty($convert_xml_to_html[$article_id])) {
        return $convert_xml_to_html[$article_id];
      }
    }
  }

  /**
   * @param string $article_id
   * @return ConvertXMLToHtml[]
   */
  public function retrieveHtmlCache($article_id) {
    $cache = &drupal_static(__FUNCTION__, []);

    if (!isset($cache[$article_id])) {
      $xml = $this->retrieveXml($article_id);
      if (!empty($xml)) {
        $convert_xml_to_html = new ConvertXMLToHtml(XMLString::fromString($xml));
        $cache[$article_id] = $convert_xml_to_html;
      }
    }

    return $cache;
  }

  public function retrieveXml($article_id) {
    $xml = $this->retrieveXmlCache($article_id);
    if (!empty($xml[$article_id])) {
      return $xml[$article_id];
    }
  }

  private function retrieveXmlCache($article_id) {
    $cache = &drupal_static(__FUNCTION__, []);

    if (!isset($cache[$article_id])) {
      $xml = $this->getXml($article_id);
      $cache[$article_id] = $xml;
    }

    return $cache;
  }

  protected function getXml($article_id) {
    return file_get_contents(sprintf('https://s3.amazonaws.com/elife-cdn/elife-articles/%s/elife%s.xml', $article_id, $article_id));
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
    $results = $this->getResults();
    $output = '';
    foreach ($results as $article_queries) {
      foreach ($article_queries as $data) {
        $output .= implode("\n", $data);
      }
    }

    return $output;
  }
}

