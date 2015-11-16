<?php

namespace eLife\MetricService;

use eLife\HttpClient\HttpClientInterface;
use GuzzleHttp\Psr7\Request;
use Psr\Http\Message\ResponseInterface as Response;

class ElifeMetricService implements MetricServiceInterface {
  /**
   * @var HttpClientInterface
   */
  private $httpClient;

  /**
   * @var string
   */
  private $uri;

  /**
   * @var string
   */
  private $doi;

  /**
   * @var string
   */
  private $lastDoi;

  /**
   * @var Response
   */
  private $response;

  /**
   * @var bool
   */
  private $flush = FALSE;

  /**
   * @param HttpClientInterface $httpClient
   * @param string $uri
   */
  public function __construct(HttpClientInterface $httpClient, $uri) {
    $this->httpClient = $httpClient;
    $this->uri = rtrim($uri, '/') . '/';
  }

  /**
   * @param bool|TRUE $flush
   */
  public function setFlush($flush = TRUE) {
    $this->flush = $flush;
  }

  /**
   * @param string $doi
   */
  public function setDoi($doi) {
    $this->doi = trim($doi, '/');
  }

  /**
   * @return \Psr\Http\Message\StreamInterface
   */
  public function request() {
    $request = new Request(
      'GET',
      // @todo - elife - nlisgo - we seem to be unable to handle 301 redirects.
      // To trigger remove the trailing '/'.
      $this->uri . $this->doi . '/'
    );

    if (empty($this->response) || $this->flush || $this->doi != $this->lastDoi) {
      $this->response = $this->httpClient->request($request);
      $this->lastDoi = $this->doi;
    }

    return (string) $this->response->getBody();
  }
}
