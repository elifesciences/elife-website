<?php

namespace eLife\HttpClient;

use GuzzleHttp\ClientInterface as GuzzleClient;
use GuzzleHttp\Exception\ConnectException;
use GuzzleHttp\Message\Request as Guzzle5Request;
use GuzzleHttp\Psr7\Response;
use GuzzleHttp\Stream\Stream;
use Psr\Http\Message\RequestInterface as Request;

/**
 * Guzzle5 HTTP Client.
 *
 * This should be upgraded to 6+ when the Drupal site can have separate Composer
 * dependencies to the Behat suite/the Behat suite can use 6+.
 */
final class Guzzle5HttpClient implements HttpClientInterface {
  /**
   * @var GuzzleClient
   */
  private $guzzle;

  /**
   * @param GuzzleClient $guzzle
   */
  public function __construct(GuzzleClient $guzzle) {
    $this->guzzle = $guzzle;
  }

  public function request(Request $request) {
    $guzzle5Request = new Guzzle5Request(
      $request->getMethod(),
      $request->getUri(),
      $request->getHeaders(),
      Stream::factory($request->getBody()->detach())
    );
    $guzzle5Request->setUrl($request->getUri()); // avoid duplicate Host header

    try {
      $guzzle5Response = $this->guzzle->send($guzzle5Request);
    } catch (ConnectException $e) {
      throw new HttpException($e->getMessage(), 0, $e);
    }

    return new Response(
      $guzzle5Response->getStatusCode(),
      $guzzle5Response->getHeaders(),
      Stream::factory($guzzle5Response->getBody()->detach()),
      $guzzle5Response->getProtocolVersion(),
      $guzzle5Response->getReasonPhrase()
    );
  }
}
