<?php
/**
 * @file
 * Contains \Drupal\elife_article\ExeterMarkupService.
 */

namespace Drupal\elife_article;

use DOMDocument;
use DOMXPath;
use Exception;

final class ExeterMarkupService extends ElifeMarkupService {
  private $queries = [];
  private $arrange_queries = [];
  private $response;
  private $error;
  private $results = [];
  private $xpaths = [
    'doi' => "//*[@data-doi='%s']",
    'main-text' => "//*[@id='main-text']",
    'abstract' => "//*[@id='abstract']",
    'digest' => "//*[@id='elife-digest']",
    'references' => "//*[@id='references']",
    'acknowledgements' => "//*[@id='ack-1']",
    'decision-letter' => "//*[@id='decision-letter']",
    'author-response' => "//*[@id='author-response']",
  ];

  /**
   * @param string $article_id
   * @param string $section
   * @param string $value
   */
  private function addQuery($article_id, $section, $value = NULL) {
    $query_id = [$article_id, $section];
    $xpath = $this->xpaths[$section];

    if ($value) {
      $xpath = sprintf($xpath, $value);
      $query_id[] = $value;
    }
    $this->queries[implode('::', $query_id)] = $xpath;
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

  private function prepareQuery() {
    $content = '';
    $queries = $this->getQuery();
    foreach ($queries as $article_id => $article_queries) {
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
      try {
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

        $this->response = curl_exec($curl);
        $this->error = curl_error($curl);

        curl_close($curl);
      }
      catch (Exception $e) {
        throw $e;
      }
    }
    else {
      throw new Exception('No queries have been added yet.');
    }
  }

  public function processResponse() {
    if (empty($this->response)) {
      // throw new Exception('The query needs to be submitted first.');
    }

    $response = $this->response;
    $xml = new DOMDocument();
    $xml->preserveWhiteSpace = FALSE;
    $xml->loadXML($response);
    $xpath = new DOMXPath($xml);

    $results = [];
    foreach ($xpath->query('//article') as $article) {
      $article_id = $article->getAttribute('id');
      foreach ($xpath->query('./query', $article) as $query) {
        $html = [];
        foreach ($xpath->query('./data/*', $query) as $data) {
          // @todo - elife - nlisgo - should this be being stripped in markup service
          if ($front = $data->getElementsByTagName('front')->item(0)) {
            $front->parentNode->removeChild($front);
          }
          $html[] = $xml->saveXML($data, LIBXML_NOEMPTYTAG);
        }
        $query_id = explode('::', array_search($query->getAttribute('xpath'), $this->queries));
        array_shift($query_id);
        $results[$article_id][implode('::', $query_id)] = $html;
      }
    }
    $this->results = $results;
  }

  /**
   * @return string
   *   Return response string.
   */
  public function getResponse() {
    if (empty($this->response)) {
      throw new Exception('The query needs to be submitted first.');
    }

    return $this->response;
  }

  /**
   * @return string
   *   Return error string.
   */
  public function getError() {
    if (empty($this->response)) {
      throw new Exception('The query needs to be submitted first.');
    }

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

