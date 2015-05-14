<?php

use Behat\Behat\Tester\Exception\PendingException;
use Drupal\DrupalExtension\Context\RawDrupalContext;
use Behat\Behat\Context\SnippetAcceptingContext;
use Drupal\elife_article\ElifeArticle;
use Behat\Behat\Hook\Scope\BeforeStepScope;

/**
 * Defines application features from the specific context.
 */
class FeatureContext extends RawDrupalContext implements SnippetAcceptingContext {

  /**
   * Keep track of apaths so they can be cleaned up.
   *
   * @var array
   */
  protected $apaths = array();

  /**
   * Initializes context.
   *
   * Every scenario gets its own context instance.
   * You can also pass arbitrary arguments to the
   * context constructor through behat.yml.
   */
  public function __construct() {
  }

  /**
   * @BeforeStep
   *
   * @param BeforeStepScope $scope
   */
  public function beforeStepCleanupApaths(BeforeStepScope $scope) {
    $text = $scope->getStep()->getText();
    if (preg_match('/send a POST request to "[^\"]+" with body\:$/i', $text)) {
      $strings = $scope->getStep()->getArguments();
      /* @var $string \Behat\Gherkin\Node\PyStringNode */
      foreach ($strings as $string) {
        $json = json_decode($string->getRaw());
        if (!empty($json->apath)) {
          $this->apaths[] = $json->apath;
        }
      }
    }
  }

  /**
   * @AfterScenario
   */
  public function cleanApaths() {
    if (!empty($this->apaths)) {
      module_load_include('inc', 'elife_services', 'resources/article');
      foreach ($this->apaths as $article_id) {
        _elife_services_article_delete($article_id, FALSE);
      }
    }
  }
}
