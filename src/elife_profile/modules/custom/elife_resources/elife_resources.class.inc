<?php

/**
 * @file
 * eLife Resources class
 */

class elifeResources {
  const RESOURCES_API = 'http://api.elifesciences.org/';
  const RESOURCES_VERSION = 'v2';
  const RESOURCES_OK = 200;
  const CACHE_ENABLED = TRUE;
  // Cache time in minutes.
  const CACHE_TIME = 60;
  const SECRET_KEY = '';

  var $query = '';
  var $doi = '';
  var $type = '';
  var $urls = array();
  var $responses;
  var $cache_bin = 'cache_elife_resources';

  private function prepareArticleQuery($doi, $type = 'article') {
    $this->doi = $doi;
    $this->type = $type;
    $this->query = self::RESOURCES_VERSION . '/articles/' . $doi . '/pdf/' . $type;
  }

  function getDoi() {
    return $this->doi;
  }

  function setUrl($doi, $type) {
    $urls = $this->prepareUrls();
    if (!empty($urls)) {
      $this->urls[$doi][$type] = $this->prepareUrls();
    }
  }

  function getArticle($doi, $types = array('article', 'figures')) {
    if (!is_array($types)) {
      $types = array($types);
    }
    foreach ($types as $type) {
      $this->prepareArticleQuery($doi, $type);
      $this->execute();
      $this->setUrl($doi, $type);
    }
  }

  function setResponse($response) {
    $this->responses[$this->doi][$this->type] = $response;
  }

  function getLastResponse() {
    return $this->responses[$this->doi][$this->type];
  }

  function execute() {
    $static = &drupal_static(__METHOD__, array());

    if (!isset($static[$this->query])) {
      $this->setResponse($this->requestResponse());
      $static[$this->query] = $this->getLastResponse();
    }
    else {
      $this->setResponse($static[$this->query]);
    }

    return $static;
  }

  function requestResponse() {
    if ($response = $this->getCache()) {
      return $response;
    }
    else {
      $response = drupal_http_request(self::RESOURCES_API . $this->query);
      $this->setCache($response);
    }
    return $response;
  }

  function getCache() {
    if ($this->cacheEnabled()) {
      if ($cache = cache_get($this->getHashKey(), $this->getCacheBin())) {
        if ($cache->expire > REQUEST_TIME && !empty($cache->data)) {
          return $cache->data;
        }

      }
    }

    return FALSE;
  }

  function setCache($data) {
    if ($this->cacheEnabled()) {
      cache_set($this->getHashKey(), $data, $this->getCacheBin(), $this->getCacheExpiry());
    }
  }

  public static function cacheEnabled() {
    return variable_get('elife_resources_cache_enabled', self::CACHE_ENABLED);
  }

  function getHashKey(){
    return base64_encode(hash_hmac('sha1', $this->query, $this->getSecretKey()));
  }

  public static function getSecretKey() {
    return variable_get('elife_resources_secret_key', self::SECRET_KEY);
  }

  function getCacheExpiry() {
    return REQUEST_TIME + ($this->getCacheTime() * 60);
  }

  public static function getCacheTime() {
    return variable_get('elife_resources_cache_time', self::CACHE_TIME);
  }

  function getCacheBin() {
    return $this->cache_bin;
  }

  function getResponse($type = NULL) {
    if (!empty($this->responses) && isset($this->responses[$this->doi][$this->type])) {
      $response = $this->responses[$this->doi][$this->type];
      switch ($type) {
        case 'code':
          return $response->code;
        case 'data':
          return json_decode($response->data);
        default:

      }
      return $response;
    }
  }

  function responseOK() {
    return ($this->getResponse('code') == self::RESOURCES_OK);
  }

  function getResponseData() {
    if ($this->responseOK()) {
      return $this->getResponse('data');
    }
  }

  function prepareUrls() {
    $results = array();
    if ($data = $this->getResponseData()) {
      $results = array();
      foreach ($data->data as $result) {
        $results[] = array(
          'type' => $this->type,
          'url' => $result->url,
          'bytes' => $result->size,
          'size' => $this->formatSizeUnits($result->size),
        );
      }
    }
    return $results;
  }

  function getUrls() {
    if (!empty($this->urls[$this->doi])) {
      $urls = $this->urls[$this->doi];
    }
    else {
      $urls = array();
    }
    return $urls;
  }

  function formatSizeUnits($bytes) {
    if ($bytes >= 1073741824) {
      $bytes = number_format($bytes / 1073741824, 2) . ' GB';
    }
    elseif ($bytes >= 1048576) {
      $bytes = number_format($bytes / 1048576, 2) . ' MB';
    }
    elseif ($bytes >= 1024) {
      $bytes = number_format($bytes / 1024, 2) . ' KB';
    }
    elseif ($bytes > 1) {
      $bytes = $bytes . ' bytes';
    }
    elseif ($bytes == 1) {
      $bytes = $bytes . ' byte';
    }
    else {
      $bytes = '0 bytes';
    }

    return $bytes;
  }
}
