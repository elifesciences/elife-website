<?php

final class eLifeServicesStringParser implements ServicesParserInterface {
  public function parse(ServicesContextInterface $context) {
    return $context->getRequestBody();
  }
}

final class eLifeServicesStringFormatter implements ServicesFormatterInterface {
  public function render($data) {
    return $data;
  }
}
