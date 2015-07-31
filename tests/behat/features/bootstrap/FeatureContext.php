<?php

use Behat\Mink\Driver\GoutteDriver;
use Behat\Mink\Exception\UnsupportedDriverActionException;
use Drupal\DrupalExtension\Context\RawDrupalContext;
use Behat\Behat\Context\SnippetAcceptingContext;
use Drupal\elife_article\ElifeArticleVersion;
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
   * Keep track of variables so they can be cleaned up.
   *
   * @var array
   */
  protected $variables = array();

  /**
   * Entity types to store and cleanup.
   *
   * @var array
   */
  protected $entity_types = array(
    'node' => 'nid',
    'taxonomy_term' => 'tid',
  );

  /**
   * Keep track of max entity ids so they can be cleaned up.
   *
   * @var array
   */
  protected $entity_max = array();

  /**
   * Initializes context.
   */
  public function __construct() {
  }

  /**
   * @BeforeScenario
   */
  public function resetFollowingRedirects() {
    try {
      $this->canIntercept();
      $this->getSession()->getDriver()->getClient()->followRedirects(true);
    } catch(UnsupportedDriverActionException $e) {
      // Do nothing.
    }
  }

  /**
   * Store max entity ids for later cleanup.
   *
   * @BeforeScenario
   */
  public function storeEntityMaxBeforeScenario() {
    foreach ($this->entity_types as $type => $id) {
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', $type);
      $query->propertyOrderBy($id, 'DESC');
      $query->range(0, 1);
      $entities = $query->execute();
      $this->entity_max[$type] = 0;
      if (!empty($entities[$type])) {
        $ids = array_keys($entities[$type]);
        $this->entity_max[$type] = $ids[0];
      }
    }
  }

  /**
   * Cleanup entities that didn't exist before the scenario.
   *
   * @AfterScenario
   */
  public function clearEntityMaxAfterScenario() {
    $cleanup_rules_config = rules_config_load('rules_elife_cleanup_of_orphaned_article_nodes');
    $cleanup_rules_config_active = FALSE;
    if ($cleanup_rules_config) {
      $cleanup_rules_config_active = $cleanup_rules_config->active;
      $cleanup_rules_config->active = FALSE;
      $cleanup_rules_config->save();
    }
    foreach ($this->entity_types as $type => $id) {
      $query = new EntityFieldQuery();
      // Bypass access controls.
      $query->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');
      $query->entityCondition('entity_type', $type);
      $query->propertyOrderBy($id, 'DESC');
      $query->propertyCondition($id, $this->entity_max[$type], '>');
      $entities = $query->execute();
      if (!empty($entities[$type])) {
        $ids = array_keys($entities[$type]);
        entity_delete_multiple($type, $ids);
      }
    }
    if ($cleanup_rules_config) {
      $cleanup_rules_config->active = $cleanup_rules_config_active;
      $cleanup_rules_config->save();
    }
  }

  /**
   * @Given redirects are not followed
   */
  public function redirectsAreNotFollowed() {
    $this->canIntercept();
    $this->getSession()->getDriver()->getClient()->followRedirects(FALSE);
  }

  // the versions should be ordered "05224,05224.early.v1,05224.early.v2"

  /**
   * Checks that we have the expected versions of an article in order.
   *
   * @param int $expected versions of article
   * @param string $article_id id of article
   *
   * @Then /^the versions should be ordered "([^"]+)" for "([^"]+)"$/
   */
  public function theVersionsShouldBeOrderedFor($expected, $article_id)
  {
    $expected = explode(',', $expected);
    $versions = ElifeArticleVersion::fromId($article_id, FALSE, 'elife_article_ver', ['DANGEROUS_ACCESS_CHECK_OPT_OUT']);
    $actual = [];
    if (!empty($versions)) {
      foreach ($versions as $version) {
        $actual[] = $version->extraFields->field_elife_a_article_version_id_value;
      }
    }
    Assertions::assertSame($expected, $actual);
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
    $versions = ElifeArticleVersion::fromId($article_id, FALSE, 'elife_article_ver', ['DANGEROUS_ACCESS_CHECK_OPT_OUT']);
    $actual = !empty($versions) ? count($versions) : 0;
    Assertions::assertSame($expected, $actual);
  }

  /**
   * Checks that we have the expected published versions of an article.
   *
   * @param int $expected number of published versions of article
   * @param string $article_id id of article
   *
   * @Then /^there should be (\d+) published versions of article "([^"]+)"$/
   */
  public function thereShouldBePublishedVersionsOfArticle($expected, $article_id)
  {
    $expected = intval($expected);
    $versions = ElifeArticleVersion::fromId($article_id, FALSE, 'elife_article_ver', ['DANGEROUS_ACCESS_CHECK_OPT_OUT', ['1', 'status', '=', 'propertyCondition']]);
    $actual = !empty($versions) ? count($versions) : 0;
    Assertions::assertSame($expected, $actual);
  }

  /**
   * Checks that we have the expected unpublished versions of an article.
   *
   * @param int $expected number of unpublished versions of article
   * @param string $article_id id of article
   *
   * @Then /^there should be (\d+) unpublished versions of article "([^"]+)"$/
   */
  public function thereShouldBeUnpublishedVersionsOfArticle($expected, $article_id)
  {
    $expected = intval($expected);
    $versions = ElifeArticleVersion::fromId($article_id, FALSE, 'elife_article_ver', ['DANGEROUS_ACCESS_CHECK_OPT_OUT', ['0', 'status', '=', 'propertyCondition']]);
    $actual = !empty($versions) ? count($versions) : 0;
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
    $actual = $ewrapper->field_elife_a_contributors_pri->count();
    Assertions::assertSame($expected, $actual);
  }

  /**
   * @Then /^there should be (\d+) verified related articles?$/
   */
  public function thereShouldBeVerifiedRelatedArticles($expected)
  {
    $expected = intval($expected);
    $results = ElifeArticleVersion::retrieveRelatedArticles();
    $actual = count($results);
    Assertions::assertSame($expected, $actual);
  }

  /**
   * @Then /^there should be (\d+) unique verified related articles?$/
   */
  public function thereShouldBeUniqueVerifiedRelatedArticles($expected)
  {
    $expected = intval($expected);
    $results = ElifeArticleVersion::retrieveRelatedArticles(NULL, TRUE, TRUE);
    $actual = count($results);
    Assertions::assertSame($expected, $actual);
  }

  /**
   * @Then /^there should be (\d+) unverified related articles?$/
   */
  public function thereShouldBeUnverifiedRelatedArticles($expected)
  {
    $expected = intval($expected);
    $results = ElifeArticleVersion::retrieveRelatedArticles(NULL, FALSE);
    $actual = count($results);
    Assertions::assertSame($expected, $actual);
  }

  /**
   * @Then there should be :expected verified related articles for :article_id
   */
  public function thereShouldBeVerifiedRelatedArticleFor($expected, $article_id)
  {
    $article = ElifeArticleVersion::getArticle($article_id);
    $expected = intval($expected);
    $results = ElifeArticleVersion::retrieveRelatedArticles($article->nid, TRUE);
    $actual = count($results);
    Assertions::assertSame($expected, $actual);
  }

  /**
   * @Then there should be :expected unique verified related articles for :article_id
   */
  public function thereShouldBeUniqueVerifiedRelatedArticleFor($expected, $article_id)
  {
    $article = ElifeArticleVersion::getArticle($article_id);
    $expected = intval($expected);
    $results = ElifeArticleVersion::retrieveRelatedArticles($article->nid, TRUE, TRUE);
    $actual = count($results);
    Assertions::assertSame($expected, $actual);
  }

  /**
   * @Then there should be :expected unverified related articles for :article_id
   */
  public function thereShouldBeUnverifiedRelatedArticlesFor($expected, $article_id)
  {
    $article = ElifeArticleVersion::getArticle($article_id);
    $expected = intval($expected);
    $results = ElifeArticleVersion::retrieveRelatedArticles($article->nid, FALSE);
    $actual = count($results);
    Assertions::assertSame($expected, $actual);
  }

  /**
   * @Then article :article_id should be related to :related_to
   */
  public function articleShouldBeRelatedTo($article_id, $related_to)
  {
    $article = ElifeArticleVersion::getArticle($article_id);
    $related_to = explode(',', $related_to);
    $results = ElifeArticleVersion::retrieveRelatedArticles($article->nid, TRUE, TRUE);
    $actual = [];
    if (!empty($results)) {
      foreach ($results as $result) {
        $actual[] = $result->related_to;
      }
    }
    $diff = array_diff($actual, $related_to);
    Assertions::assertEmpty($diff);
  }

  /**
   * @Then article :article_id should not be related to :related_to
   */
  public function articleShouldNotBeRelatedTo($article_id, $not_related_to)
  {
    $article = ElifeArticleVersion::getArticle($article_id);
    $not_related_to = explode(',', $not_related_to);
    $results = ElifeArticleVersion::retrieveRelatedArticles($article->nid, TRUE, TRUE);
    $actual = [];
    if (!empty($results)) {
      foreach ($results as $result) {
        $actual[] = $result->related_to;
      }
    }
    $intersect = array_intersect($actual, $not_related_to);
    Assertions::assertEmpty($intersect);
  }

  /**
   * @Then article :article_id should have unverified related articles of :related_to
   */
  public function articleShouldHaveUnverifiedRelatedArticles($article_id, $related_to)
  {
    $article = ElifeArticleVersion::getArticle($article_id);
    $related_to = explode(', ', $related_to);
    $results = ElifeArticleVersion::retrieveRelatedArticles($article->nid, FALSE);
    $actual = [];
    if (!empty($results)) {
      if ($fc_items = entity_load('field_collection_item', array_keys($results))) {
        foreach ($fc_items as $fc_item) {
          /* @var EntityDrupalWrapper $fc_wrapper */
          $fc_wrapper = entity_metadata_wrapper('field_collection_item', $fc_item);
          if ($doi = $fc_wrapper->field_elife_a_doi->value()) {
            $actual[] = $doi;
          }
        }
      }
    }
    $diff = array_diff($actual, $related_to);
    Assertions::assertEmpty($diff);
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

  /**
   * @Given I set variable :name to :type :value
   */
  public function iSetVariableToArray($name, $type, $value)
  {
    if (!isset($this->variables[$name])) {
      $this->variables[$name] = variable_get($name, NULL);
    }
    if ($type == 'array') {
      $value = json_decode($value, TRUE);
    }
    variable_set($name, $value);
  }

  /**
   * Cleanup variables.
   *
   * @AfterScenario
   */
  public function cleanVariables() {
    if (!empty($this->variables)) {
      foreach ($this->variables as $name => $value) {
        if (is_null($value)) {
          variable_del($name);
        }
        else {
          variable_set($name, $value);
        }
      }
    }
  }

  /**
   * @Then /^display channels should be arranged "([^"]+)"$/
   */
  public function displayChannelsShouldBeArranged($expected)
  {
    $expected = explode(', ', $expected);
    $actual = array();
    $categories_vocabulary = taxonomy_vocabulary_machine_name_load('elife_categories');
    $efq = new EntityFieldQuery();
    $result = $efq->entityCondition('entity_type', 'taxonomy_term')
      ->propertyCondition('vid', $categories_vocabulary->vid)
      ->fieldCondition('field_elife_category_type', 'value', 'display-channel', '=')
      ->propertyOrderBy('weight')
      ->execute();
    if (!empty($result['taxonomy_term'])) {
      $terms = taxonomy_term_load_multiple(array_keys($result['taxonomy_term']));
      foreach ($terms as $term) {
        $actual[] = $term->name;
      }
    }
    Assertions::assertSame($expected, $actual);
  }

  /**
   * @Given /^the "([^"]*)" hidden field should contain "([^"]*)"$/
   */
  public function theHiddenFieldShouldContain($field, $value) {
    $element = $this->getSession()->getPage()
      ->find("css", 'input[name=' . $field . ']');
    $value_current = $element->getAttribute('value');
    if ($value !== $value_current) {
      throw new Exception('Expected value ' . $value . ' but found ' . $value_current);
    }
  }

  /**
   * @throws UnsupportedDriverActionException
   */
  private function canIntercept() {
    $driver = $this->getSession()->getDriver();
    if (!$driver instanceof GoutteDriver) {
      throw new UnsupportedDriverActionException(
        'Intercepting the redirections is not supported by %s', $driver
      );
    }
  }
    /**
     * @Given /^(?:|I )hover over the author "(?P<author>[^"]*)" in the "(?P<selector>[^"]*)" element$/
     *
     * @param $author
     *   The name of the author to look for
     * @param $selector
     *   The css selector for the items enclosing each author
     *
     * @throws Exception
     */
    public function iHoverOverTheAuthorInElement($author, $selector) {
        $session = $this->getSession();
        if (!$session->getDriver() instanceof Behat\Mink\Driver\Selenium2Driver) {
            throw new Exception('Cannot run hover tests for "' . $author . '" without using Selenium.');
        }
        $auth = $this->findAuthorNode($selector, $author);
        if (empty($auth)) {
            throw new Exception('Cannot find the author "' . $author . '" in the element "' . $selector . '"');
        }
        $html = $auth->getAttribute('data-tooltip-content');
        // Delete initial | in string and add in a wrapper to emulate cluetip.
        $html =
            '<div id="cluetip" style="position: absolute; background-color: papayawhip;">' .
            '<div class="cluetip-outer" style="position: relative; z-index: 97; overflow: visible; height: auto;">' .
            '<h3 class="cluetip-title ui-widget-header ui-cluetip-header" style="display: none;"></h3>' .
            '<div class="cluetip-inner ui-widget-content ui-cluetip-content">' .
            '<div class="cluetip-close"><a href="#">Close</a></div>' .
            substr($html, 1) .
            '</div>' .
            '</div>' .
            '</div>' .
            '</div>';

        $js = <<<'JS'
    (function(selector, newcontent) {
        jQuery(selector).prepend(newcontent);
    })('#section-content', '{{NEWCONTENT}}');
JS;
        $html = str_replace("'", "\\'", $html);
        $js = str_replace('{{NEWCONTENT}}', $html, $js);
        $session->executeScript($js);
        $this->sendJSMouseEnter($auth);
        sleep(4);
    }

    /**
     * @Then /^(?:|I )should see the "(?P<name>[^"]*)" tooltip$/
     *
     * TODO: elife - this implementation is tightly-bound to the cluetip jquery plugin.
     * @throws Exception
     */
    public function iShouldSeeTheCluetip($name) {
        $session = $this->getSession();
        if (!$session->getDriver() instanceof Behat\Mink\Driver\Selenium2Driver) {
            throw new Exception('Cannot run hover tests for "' . $name . '" without using Selenium.');
        }
        sleep(2);
        $element = $session->getPage()->find('css', '#cluetip');
        if (empty($element)) {
            throw new Exception('Cannot find the id=cluetip element.');
        }
        if (!$element->isVisible()) {
            throw new Exception('The "' . $name . '" tooltip is not visible.');
        }
        $this->last_author_element = $element;
    }

    /**
     * Return the element containing an article author given the author-class.
     *
     * The supplied class/selector must be a selector that returns all authors,
     * for example .elife-article-author-item
     *
     * @param $css
     *   The selector which returns all authors.
     * @param $author
     *   The text (no html) of the author's name.
     *
     * @return mixed
     *   The behat element object or null if not found
     */
    function findAuthorNode($css, $author) {
        $elements = $this->getSession()->getPage()->findAll('css', $css);
        foreach ($elements as $auth) {
            if ($auth->getText() == $author) {
                $this->last_author_element = $auth;
                return $auth;
            }
        }
        return null;
    }


    /**
     * Check for a specific image filename in an img tag.
     *
     * @Then /^(?:|I )should see the image "(?P<text>(?:[^"]|\\")*)" in the "(?P<elem>(?:[^"]|\\")*)" element$/
     *
     * @param string $elem
     *   The element's CSS selector.
     * @param string $text
     *   The expected filename in the src attribute.
     *
     * @throws Exception
     */
    public function iShouldSeeTheImageInTheElement($elem, $text) {
        $element = $this->getSession()->getPage()->find("css", $elem);
        if (!$element) {
            throw new Exception('Expected element ' . $elem . ' not found on page.');
        }
        $value_current = $element->getAttribute("src");
        if ($text !== $value_current && $text !== basename($value_current)) {
            throw new Exception('Expected value ' . $text . ' but found ' . $value_current);
        }
    }
}
