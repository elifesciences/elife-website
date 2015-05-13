<?php

use Behat\Behat\Tester\Exception\PendingException;
use Drupal\DrupalExtension\Context\RawDrupalContext;
use Behat\Behat\Context\SnippetAcceptingContext;
use Behat\Gherkin\Node\PyStringNode;
use Behat\Gherkin\Node\TableNode;
use Behat\WebApiExtension\Context\WebApiContext;

/**
 * Defines application features from the specific context.
 */
class FeatureContext extends RawDrupalContext implements SnippetAcceptingContext {

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
   * @Then I should cleanup articles :articles
   */
  public function iShouldCleanupArticles($articles)
  {
    $articles = explode(',', $articles);
    $this->getDriver();
    module_load_include('inc', 'elife_services', 'resources/article');
    foreach ($articles as $article_id) {
      _elife_services_article_delete($article_id);
    }
  }
}
