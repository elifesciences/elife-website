<?php

use SensioLabs\Behat\PageObjectExtension\Context\PageObjectContext;

class ContentAlertsContext extends PageObjectContext {

  const CIVI_BASEPATH = 'https://crm.elifesciences.org/crm/';

  /**
   * @Given I should see a sign up form with id :id
   */
  public function shouldSeeSignUpFormWithId($id) {
    $this->getElement('Content Alerts Signup Form')->hasId($id);
  }

  /**
   * @Given I should see a sign up form with action :action
   */
  public function shouldSeeSignUpFormWithAction($action) {
    $this->getElement('Content Alerts Signup Form')->hasAction(self::CIVI_BASEPATH . $action);
  }

  /**
   * @Given I should see a sign up form with id :id and action :action
   */
  public function shouldSeeSignUpFormWithIdAndAction($id, $action) {
    $this->getElement('Content Alerts Signup Form')->hasId($id);
    $this->getElement('Content Alerts Signup Form')->hasAction(self::CIVI_BASEPATH . $action);
  }

  /**
   * @Then I should see a sign up form with id :id, action :action and button :button
   */
  public function iShouldSeeASignUpFormWithIdActionAndButton($id, $action, $button) {
    $this->getElement('Content Alerts Signup Form')->hasId($id);
    $this->getElement('Content Alerts Signup Form')->hasButton($button);
    $this->getElement('Content Alerts Signup Form')->hasAction(self::CIVI_BASEPATH . $action);
  }
}
