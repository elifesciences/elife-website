<?php

namespace Drupal\Driver\Fields\Drupal7;

final class CountryHandler extends AbstractHandler {
  public function expand($values) {
    $return = [];
    foreach ($values as $value) {
      $return[$this->language][] = ['iso2' => $value];
    }
    return $return;
  }
}
