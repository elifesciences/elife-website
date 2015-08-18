<?php

use Behat\Drupal\Propeople\PropeopleContext;

class IsolatedPropeopleContext extends PropeopleContext {
  public function cleanNodes() {
    $this->nodes = [];
  }

  public function cleanUsers() {
    $this->users = [];
  }

  public function cleanTerms() {
    $this->terms = [];
  }

  public function cleanRoles() {
    $this->roles = [];
  }
}
