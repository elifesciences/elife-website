<?php

namespace eLife\MetricService;

class MockMetricService implements MetricServiceInterface {
  /**
   * @var string
   */
  private $doi;

  /**
   * @param string $doi
   */
  public function setDoi($doi) {
    $this->doi = trim($doi, '/');
  }

  /**
   * @return string
   */
  public function request() {
    return '';
  }
}
