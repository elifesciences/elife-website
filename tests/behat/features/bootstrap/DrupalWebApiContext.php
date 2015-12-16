<?php

use Behat\Testwork\Hook\HookDispatcher;
use Behat\WebApiExtension\Context\WebApiContext;
use Drupal\DrupalDriverManager;
use Drupal\DrupalExtension\Context\DrupalAwareInterface;
use Drupal\DrupalExtension\Hook\Scope\EntityScope;

class DrupalWebApiContext extends WebApiContext implements DrupalAwareInterface {

  /**
   * Drupal driver manager.
   *
   * @var \Drupal\DrupalDriverManager
   */
  private $drupal;

  /**
   * Test parameters.
   *
   * @var array
   */
  private $drupalParameters;

  /**
   * Event dispatcher object.
   *
   * @var \Behat\Testwork\Hook\HookDispatcher
   */
  protected $dispatcher;

  /**
   * Current authenticated user.
   *
   * A value of FALSE denotes an anonymous user.
   *
   * @var stdClass|bool
   */
  public $user = FALSE;

  /**
   * Keep track of all users that are created so they can easily be removed.
   *
   * @var array
   */
  protected $users = array();

  /**
   * @var string
   */
  private $authorization;

  /**
   * {@inheritDoc}
   */
  public function setDrupal(DrupalDriverManager $drupal) {
    $this->drupal = $drupal;
  }

  /**
   * {@inheritDoc}
   */
  public function getDrupal() {
    return $this->drupal;
  }

  /**
   * {@inheritDoc}
   */
  public function setDispatcher(HookDispatcher $dispatcher) {
    $this->dispatcher = $dispatcher;
  }

  /**
   * Set parameters provided for Drupal.
   */
  public function setDrupalParameters(array $parameters) {
    $this->drupalParameters = $parameters;
  }

  /**
   * @afterUserCreate
   */
  public function afterUserCreate(EntityScope $scope) {
    $user = $scope->getEntity();
    $this->users[$user->name] = $this->user = $user;
  }

  /**
   * Adds Basic Authentication header to next request.
   *
   * @Given /^I am authenticating as the Drupal user$/
   */
  public function iAmAuthenticatingAsDrupalUser()
  {
    $this->removeHeader('Authorization');
    $this->authorization = base64_encode($this->user->name . ':' . $this->user->pass);
    $this->addHeader('Authorization', 'Basic ' . $this->authorization);
  }
}
