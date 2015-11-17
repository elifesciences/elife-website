<?php

namespace eLife\MetricService;

class MockMetricService implements MetricServiceInterface {
  /**
   * @param string $doi
   * @return string
   */
  public function request($doi) {
    return '';
  }
}
