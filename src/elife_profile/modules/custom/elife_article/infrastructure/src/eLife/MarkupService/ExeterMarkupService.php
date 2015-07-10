<?php

namespace eLife\MarkupService;

use DOMDocument;
use DOMXPath;
use eLife\HttpClient\HttpClient;
use GuzzleHttp\Psr7\Request;

final class ExeterMarkupService implements MarkupService {
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

  public function query(Query $query) {
    if (empty($query)) {
      return '';
    }

    $request = new Request(
      'POST',
      $this->uri,
      [
        'content' => $query->getValue(),
      ]
    );

    $response = $this->httpClient->request($request);
    $processed = $this->processResponse((string) $response->getBody());
    return $this->output($processed);
  }

  private function processResponse($response) {
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
    return $results;
  }

  /**
   * @param array $results
   *
   * @return string HTML output from markup query.
   * HTML output from markup query.
   */
  private function output(array $results) {
    $output = '';
    foreach ($results as $article_queries) {
      foreach ($article_queries as $data) {
        $output .= implode("\n", $data);
      }
    }

    return $output;
  }
}
