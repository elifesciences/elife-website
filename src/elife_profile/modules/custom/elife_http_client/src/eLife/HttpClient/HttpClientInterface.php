<?php

namespace eLife\HttpClient;

use Psr\Http\Message\RequestInterface as Request;
use Psr\Http\Message\ResponseInterface as Response;

interface HttpClientInterface {
  /**
   * @param Request $request
   *
   * @return Response
   *
   * @throws HttpException
   */
  public function request(Request $request);
}
