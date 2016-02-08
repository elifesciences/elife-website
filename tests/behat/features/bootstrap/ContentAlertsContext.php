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
    $this->getElement('Content Alerts Signup Form')->hasAction('https://crm.elifesciences.org/crm/civicrm/profile/create?reset=1&gid=' . $gid);
  }

  /**
   * @Given I should see a sign up form with id :id and gid :gid
   */
  public function shouldSeeSignUpFormWithIdAndGid($id, $gid) {
    $this->getElement('Content Alerts Signup Form')->hasId($id);
    $this->getElement('Content Alerts Signup Form')->hasGid($gid);
    $this->getElement('Content Alerts Signup Form')->hasAction('https://crm.elifesciences.org/crm/civicrm/profile/create?reset=1&gid=' . $gid);
  }

  /**
   * @Then I should see a sign up form with id :id, gid :gid and button :button
   */
  public function iShouldSeeASignUpFormWithIdGidAndButton($id, $gid, $button) {
    $this->getElement('Content Alerts Signup Form')->hasId($id);
    $this->getElement('Content Alerts Signup Form')->hasGid($gid);
    $this->getElement('Content Alerts Signup Form')->hasButton($button);
    $this->getElement('Content Alerts Signup Form')->hasAction('https://crm.elifesciences.org/crm/civicrm/profile/create?reset=1&gid=' . $gid);
  }
}