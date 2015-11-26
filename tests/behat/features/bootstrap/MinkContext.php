<?php

use Drupal\DrupalExtension\Context\MinkContext as BaseMinkContext;

class MinkContext extends BaseMinkContext {
  /**
   * @Then I should not see the :region region
   */
  public function iShouldNotSeeTheRegion($region) {
    try {
      $this->getRegion($region);
    } catch (Exception $e) {
      return;
    }

    throw new Exception('Region ' . $region . ' found, when it should not be');
  }
}
