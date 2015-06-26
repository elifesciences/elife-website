<?php

use SensioLabs\Behat\PageObjectExtension\Context\PageObjectContext;

class ContentAlertsContext extends PageObjectContext {

  /**
   * @Given I should see a sign up form with id :id
   */
  public function shouldSeeSignUpFormWithId($id) {
    $this->getElement('Content Alerts Signup Form')->hasId($id);
  }

  /**
   * @Given I should see a sign up form with gid :gid
   */
  public function shouldSeeSignUpFormWithGid($gid) {
    $this->getElement('Content Alerts Signup Form')->hasGid($gid);
  }

  /**
   * @Given I should see a sign up form with id :id and gid :gid
   */
  public function shouldSeeSignUpFormWithIdAndGid($id, $gid) {
    $this->getElement('Content Alerts Signup Form')->hasId($id);
    $this->getElement('Content Alerts Signup Form')->hasGid($gid);
  }

  /**
   * @Given the CiviCRM form should have the id :id
   */
  public function civiCrmFormShouldHaveId($id) {
    $this->getElement('Civi Crm Signup Form')->hasId($id);
  }
}