<?php

use Behat\Behat\Tester\Exception\PendingException;
use Drupal\DrupalExtension\Context\RawDrupalContext;
use Behat\Behat\Context\SnippetAcceptingContext;
use Drupal\elife_article\ElifeArticle;
use Behat\Behat\Hook\Scope\BeforeStepScope;
use PHPUnit_Framework_Assert as Assertions;

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
   */
  public function __construct() {
  }

  /**
   * Store article ids used to POST new content so we can cleanup later.
   *
   * @BeforeStep
   *
   * @param BeforeStepScope $scope
   */
  public function beforeStepStoreApaths(BeforeStepScope $scope) {
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
   * Delete articles for the store article ids.
   *
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

  /**
   * Checks that we have the expected versions of an article.
   *
   * @param int $expected number of versions of article
   * @param string $article_id id of article
   *
   * @Then /^there should be (\d+) versions of article "([^"]+)"$/
   */
  public function thereShouldBeVersionsOfArticle($expected, $article_id)
  {
    $expected = intval($expected);
    $versions = ElifeArticle::fromId($article_id, FALSE);
    $actual = count($versions);
    Assertions::assertSame($expected, $actual);
  }

  /**
   * Checks that we have the expected related articles.
   *
   * @param int $expected number of related articles
   * @param string $doi doi of article
   *
   * @Then /^there should be (\d+) related article for "([^"]+)"$/
   */
  public function thereShouldBeRelatedArticleFor($expected, $doi)
  {
    $expected = intval($expected);
    $article_nid = ElifeArticle::vorFromDoi($doi, FALSE);
    $related = ElifeArticle::relatedArticles($article_nid);
    $actual = count($related);
    Assertions::assertSame($expected, $actual);
  }
}
