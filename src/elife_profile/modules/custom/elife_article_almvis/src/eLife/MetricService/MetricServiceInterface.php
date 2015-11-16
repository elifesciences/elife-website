<?php

namespace eLife\MetricService;

interface MetricServiceInterface {
  /**
   * @param string $doi
   */
  public function setDoi($doi);

  public function request();
}
