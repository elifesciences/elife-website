<?php
/**
 * @file
 * Contains \Drupal\elife_article\ElifeMarkupService.
 */


namespace Drupal\elife_article;

use DOMDocument;
use DOMXPath;

final class ElifeMarkupService {
  private $queries = [];
  private $results = [];

  /**
   * @param string $article_id
   * @param string $xpath
   */
  public function addQuery($article_id, $xpath) {
    if (!isset($this->queries[$article_id]) || !in_array($xpath, $this->queries[$article_id])) {
      $this->queries[$article_id][] = $xpath;
    }
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
      $curl = curl_init();

      curl_setopt_array($curl, array(
        CURLOPT_URL => 'http://api.exetercs.com/job.api/xmltohtml?apiKey=6c8e740baa82f222c5e63b39ffac2613&accountKey=1',
        CURLOPT_RETURNTRANSFER => TRUE,
        CURLOPT_ENCODING => '',
        CURLOPT_MAXREDIRS => 10,
        CURLOPT_TIMEOUT => 30,
        CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
        CURLOPT_CUSTOMREQUEST => 'POST',
        CURLOPT_HTTPHEADER => array(
          'content: ' . $this->prepareQuery(),
        ),
      ));

      $response = curl_exec($curl);
      $err = curl_error($curl);

      curl_close($curl);

      if (!$err) {
        $this->processResponse($response);
      }
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

