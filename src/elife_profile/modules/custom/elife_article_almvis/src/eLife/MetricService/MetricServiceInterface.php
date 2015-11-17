<?php

namespace eLife\MetricService;

interface MetricServiceInterface {
  /**
   * @param string $doi
   */
  public function request($doi);
}
