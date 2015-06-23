<?php

use Behat\Behat\Tester\Exception\PendingException;
use Drupal\DrupalExtension\Context\RawDrupalContext;
use Behat\Behat\Context\SnippetAcceptingContext;
use Drupal\elife_article\ElifeArticleVersion;
use Behat\Behat\Hook\Scope\BeforeStepScope;
use PHPUnit_Framework_Assert as Assertions;

/**
 * Defines application features from the specific context.
 */
class FeatureContext extends RawDrupalContext implements SnippetAcceptingContext {

  /**
   * Keep track of subqueues so they can be cleaned up.
   *
   * @var array
   */
  protected $subqueues = array();

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
    $versions = ElifeArticleVersion::fromId($article_id, FALSE);
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
    $article = ElifeArticleVersion::fromIdentifier($article_version_id);
    /* @var EntityDrupalWrapper $ewrapper */
    $ewrapper = entity_metadata_wrapper('node', $article);
    $actual = $ewrapper->field_elife_a_contributors->count();
    Assertions::assertSame($expected, $actual);
  }

  /**
   * @Then /^there should be (\d+) verified related articles?$/
   */
  public function thereShouldBeVerifiedRelatedArticle($expected)
  {
    $expected = intval($expected);
    $results = ElifeArticleVersion::retrieveRelatedArticles();
    $actual = count($results);
    Assertions::assertSame($expected, $actual);
  }

  /**
   * @Then /^there should be (\d+) unverified related articles?$/
   */
  public function thereShouldBeUnverifiedRelatedArticles($expected)
  {
    $expected = intval($expected);
    $results = ElifeArticleVersion::retrieveRelatedArticles(FALSE);
    $actual = count($results);
    Assertions::assertSame($expected, $actual);
  }

  /**
   * @When /^I add "([^"]+)" with title "([^"]+)" to entityqueue "([^"]+)"$/
   */
  public function iAddToEntityqueue($type, $title, $queue)
  {
    Assertions::assertTrue(module_exists('entityqueue'), 'Entityqueue module is enabled');
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node');
    $query->propertyCondition('type', $type);
    $query->propertyCondition('title', $title);
    $query->propertyCondition('status', 1);
    $query->range(0, 1);
    $entities = $query->execute();
    Assertions::assertNotEmpty($entities['node'], 'node with type and title found');
    $nodes = array_keys($entities['node']);
    $node = node_load(array_shift($nodes));
    $subqueue = entityqueue_subqueue_load($queue);
    Assertions::assertNotNull($subqueue, 'Entityqueue with supplied title not found');
    if (!isset($this->subqueues[$queue])) {
      $this->subqueues[$queue] = $subqueue->eq_node;
    }
    $eq_node = array(array('target_id' => $node->nid));
    if (!empty($subqueue->eq_node)) {
      $eq_node = array_merge($eq_node, $subqueue->eq_node[LANGUAGE_NONE]);
    }
    $subqueue->eq_node[LANGUAGE_NONE] = $eq_node;
    entityqueue_subqueue_save($subqueue);
  }

  /**
   * Cleanup subqueues.
   *
   * @AfterScenario
   */
  public function cleanSubqueues() {
    if (!empty($this->subqueues)) {
      foreach ($this->subqueues as $queue => $eq_node) {
        $subqueue = entityqueue_subqueue_load($queue);
        $subqueue->eq_node = $eq_node;
        entityqueue_subqueue_save($subqueue);
      }
    }
  }
}
