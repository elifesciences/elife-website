<?php

namespace eLife\MarkupService;

use DOMDocument;
use DOMXPath;
use eLife\HttpClient\HttpClient;
use GuzzleHttp\Psr7\Request;

final class ExeterMarkupService implements MarkupService {
  private $queries = [];
  private $results = [];
  private $xpaths = [
    'doi' => "//*[@data-doi='%s']",
    'main-text' => "//*[contains(concat(' ', @class, ' '), ' section ')]",
    'abstract' => "//*[@id='abstract']",
    'digest' => "//*[@id='elife-digest']",
    'references' => "//*[@id='references']",
    'acknowledgements' => "//*[@id='ack-1']",
    'decision-letter' => "//*[@id='decision-letter']",
    'author-response' => "//*[@id='author-response']",
  ];

  /**
   * @var HttpClient
   */
  private $httpClient;

  /**
   * @var string
   */
  private $uri;

  /**
   * @param HttpClient $httpClient
   * @param string $uri
   */
  public function __construct(HttpClient $httpClient, $uri) {
    $this->httpClient = $httpClient;
    $this->uri = $uri;
  }

  /**
   * @param string $article_id
   * @param string $section
   * @param string $value
   */
  private function addQuery($article_id, $section, $value = NULL) {
    $xpath = $this->xpaths[$section];
    if ($value) {
      $xpath = sprintf($xpath, $value);
    }
    if (!isset($this->queries[$article_id]) || !in_array($xpath, $this->queries[$article_id])) {
      $this->queries[$article_id][] = $xpath;
    }
  }

  /**
   * @param string $article_id
   * @param string $section
   */
  public function addSectionQuery($article_id, $section) {
    $this->addQuery($article_id, $section);
  }

  /**
   * @param string $article_id
   * @param string $doi
   */
  public function addDoiQuery($article_id, $doi) {
    $this->addQuery($article_id, 'doi', $doi);
  }

  private function prepareQuery() {
    $content = '';
    foreach ($this->queries as $article_id => $article_queries) {
      $content .= '<article id="' . $article_id . '">';
      foreach ($article_queries as $article_query) {
        $content .= '<query xpath="' . $article_query . '" ></query>';
      }
      $content .= '</article>';
    }

    if (!empty($content)) {
      return '<xmltohtml>' . $content . '</xmltohtml>';
    }
  }

  public function submitQuery() {
    if (!empty($this->queries)) {
      $request = new Request(
        'POST',
        $this->uri,
        [
          'content' => $this->prepareQuery(),
        ]
      );

      $response = $this->httpClient->request($request);
      $this->processResponse((string) $response->getBody());
    }
  }

  public function processResponse($response) {
    $xml = new DOMDocument();
    $xml->preserveWhiteSpace = FALSE;
    $xml->loadXML($response);
    $xpath = new DOMXPath($xml);

    $results = [];
    foreach ($xpath->query('//article') as $article) {
      $article_id = $article->getAttribute('id');
      foreach ($xpath->query('./query', $article) as $query) {
        $xpath_value = $query->getAttribute('xpath');
        $results[$article_id][$xpath_value] = [];
        foreach ($xpath->query('./data/*', $query) as $data) {
          $results[$article_id][$xpath_value][] = $xml->saveXML($data, LIBXML_NOEMPTYTAG);
        }
      }
    }
    $this->results = $results;
  }

  /**
   * @return string
   *   HTML output from markup query.
   */
  public function output() {
    $output = '';
    foreach ($this->results as $article_queries) {
      foreach ($article_queries as $data) {
        $output .= implode("\n", $data);
      }
    }

    return $output;
  }
}

