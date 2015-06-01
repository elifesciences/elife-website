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
   * Keep track of article-version-id's so they can be cleaned up.
   *
   * @var array
   */
  protected $article_version_ids = array();

  /**
   * Initializes context.
   */
  public function __construct() {
  }

  /**
   * Store article version ids used to POST new content so we can cleanup later.
   *
   * @BeforeStep
   *
   * @param BeforeStepScope $scope
   */
  public function beforeStepStoreArticleVersionIds(BeforeStepScope $scope) {
    $text = $scope->getStep()->getText();
    if (preg_match('/send a POST request to "[^\"]+" with body\:$/i', $text)) {
      $strings = $scope->getStep()->getArguments();
      /* @var $string \Behat\Gherkin\Node\PyStringNode */
      foreach ($strings as $string) {
        $json = json_decode($string->getRaw());
        if (!empty($json->{'article-version-id'})) {
          $this->article_version_ids[] = $json->{'article-version-id'};
        }
      }
    }
  }

  /**
   * Delete articles for the stored article version ids.
   *
   * @AfterScenario
   */
  public function cleanArticleVersionIds() {
    if (!empty($this->article_version_ids)) {
      module_load_include('inc', 'elife_services', 'resources/article');
      foreach ($this->article_version_ids as $article_version_id) {
        _elife_services_article_delete($article_version_id, FALSE);
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
   * Checks that we have the expected contributors.
   *
   * @param int $expected number of contributors
   * @param string $article_version_id
   *
   * @Then /^there should be (\d+) contributors for "([^"]+)"$/
   */
  public function thereShouldBeContributorsFor($expected, $article_version_id)
  {
    $expected = intval($expected);
    $article = ElifeArticle::fromIdentifier($article_version_id);
    /* @var EntityDrupalWrapper $ewrapper */
    $ewrapper = entity_metadata_wrapper('node', $article);
    $actual = $ewrapper->field_elife_a_contributors->count();
    Assertions::assertSame($expected, $actual);
  }
}
