<?php

use Drupal\DrupalExtension\Context\DrupalContext;

class IsolatedDrupalContext extends DrupalContext {
  /**
   * @BeforeScenario
   */
  public function isolate() {
    drupal_static_reset();
    drupal_path_alias_whitelist_rebuild();
  }

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

  public function assertCron() {
    /** @var \Drupal\Driver\DrushDriver $driver */
    $driver = $this->getDriver('drush');
    $driver->drush('elysia-cron');
  }
}
