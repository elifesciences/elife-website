<?php

use Behat\Gherkin\Node\PyStringNode;
use Behat\Gherkin\Node\TableNode;
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
  public function cleanNodes() {
    $this->nodes = [];
  }

  public function cleanUsers() {
    $this->users = [];
  }

  public function cleanTerms() {
    $this->terms = [];
  }

  public function cleanRoles() {
    $this->roles = [];
  }

  /**
   * @BeforeScenario
   */
  public function SetDefaultMockMarkupService() {
    variable_set('elife_article_markup_service_factory', '_elife_article_mock_markup_service');
  }

  /**
   * @BeforeScenario
   */
  public function SetDefaultMockCitationService() {
    variable_set('elife_article_citation_service_factory', '_elife_article_mock_citation_service_disabled');
  }

  /**
   * @BeforeScenario
   */
  public function SetDefaultMockMetricService() {
    variable_set('elife_article_almvis_metric_service_factory', '_elife_article_almvis_mock_metric_service');
  }

  /**
   * @BeforeScenario
   */
  public function resetFollowingRedirects() {
    try {
      $this->canIntercept();
      $this->getSession()->getDriver()->getClient()->followRedirects(TRUE);
    } catch (UnsupportedDriverActionException $e) {
      // Do nothing.
    }
  }

  /**
   * @Given redirects are not followed
   */
  public function redirectsAreNotFollowed() {
    $this->canIntercept();
    $this->getSession()->getDriver()->getClient()->followRedirects(FALSE);
  }

  /**
   * @Then /^I should be redirected to "(?P<page>[^"]+)"(?: with a (?P<status>\d+))?$/
   */
  public function redirectionShouldPointTo($page, $status = NULL) {
    $location = $this->getSession()->getResponseHeader('Location');

    if (empty($location)) {
      throw new \RuntimeException('The response should contain a "Location" header');
    }

    Assertions::assertEquals($location, $this->locatePath($page), 'The "Location" header points to the correct URI');

    if ($status !== NULL) {
      $this->assertSession()->statusCodeEquals($status);
    }
  }

  /**
   * Set up an article.
   *
   * @param PyStringNode $string
   *   JSON article.
   *
   * @Given /^there is an article:$/
   * @When /^an article is submitted:$/
   */
  public function thereIsAnArticle(PyStringNode $string) {
    module_load_include('inc', 'elife_services', 'resources/article');

    _elife_services_article_create($string->getRaw());

    _elife_article_prepare_main_text();
  }

  /**
   * Sets up a number of articles.
   *
   * @param PyStringNode $string
   *   JSON array of articles.
   *
   * @Given /^there are articles:$/
   */
  public function thereAreArticles(PyStringNode $string) {
    module_load_include('inc', 'elife_services', 'resources/article');

    $json = @json_decode($string, TRUE);

    if (FALSE === is_array($json)) {
      throw new LogicException('Invalid JSON');
    }

    foreach ($json as $article_json) {
      _elife_services_article_create(json_encode($article_json));
    }

    _elife_article_prepare_main_text();
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
  public function theVersionsShouldBeOrderedFor($expected, $article_id) {
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
  public function thereShouldBeVersionsOfArticle($expected, $article_id) {
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
  public function thereShouldBePublishedVersionsOfArticle($expected, $article_id) {
    $expected = intval($expected);
    $versions = ElifeArticleVersion::fromId($article_id, FALSE, 'elife_article_ver', [
      'DANGEROUS_ACCESS_CHECK_OPT_OUT',
      ['1', 'status', '=', 'propertyCondition']
    ]);
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
  public function thereShouldBeUnpublishedVersionsOfArticle($expected, $article_id) {
    $expected = intval($expected);
    $versions = ElifeArticleVersion::fromId($article_id, FALSE, 'elife_article_ver', [
      'DANGEROUS_ACCESS_CHECK_OPT_OUT',
      ['0', 'status', '=', 'propertyCondition']
    ]);
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
  public function thereShouldBeContributorsFor($expected, $article_version_id) {
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
  public function thereShouldBeVerifiedRelatedArticles($expected) {
    $expected = intval($expected);
    $results = ElifeArticleVersion::retrieveRelatedArticles();
    $actual = count($results);
    Assertions::assertSame($expected, $actual);
  }

  /**
   * @Then /^there should be (\d+) unique verified related articles?$/
   */
  public function thereShouldBeUniqueVerifiedRelatedArticles($expected) {
    $expected = intval($expected);
    $results = ElifeArticleVersion::retrieveRelatedArticles(NULL, TRUE, TRUE);
    $actual = count($results);
    Assertions::assertSame($expected, $actual);
  }

  /**
   * @Then /^there should be (\d+) unverified related articles?$/
   */
  public function thereShouldBeUnverifiedRelatedArticles($expected) {
    $expected = intval($expected);
    $results = ElifeArticleVersion::retrieveRelatedArticles(NULL, FALSE);
    $actual = count($results);
    Assertions::assertSame($expected, $actual);
  }

  /**
   * @Then there should be :expected verified related articles for :article_id
   */
  public function thereShouldBeVerifiedRelatedArticleFor($expected, $article_id) {
    $article = ElifeArticleVersion::getArticle($article_id);
    $expected = intval($expected);
    $results = ElifeArticleVersion::retrieveRelatedArticles($article->nid, TRUE);
    $actual = count($results);
    Assertions::assertSame($expected, $actual);
  }

  /**
   * @Then there should be :expected unique verified related articles for :article_id
   */
  public function thereShouldBeUniqueVerifiedRelatedArticleFor($expected, $article_id) {
    $article = ElifeArticleVersion::getArticle($article_id);
    $expected = intval($expected);
    $results = ElifeArticleVersion::retrieveRelatedArticles($article->nid, TRUE, TRUE);
    $actual = count($results);
    Assertions::assertSame($expected, $actual);
  }

  /**
   * @Then there should be :expected unverified related articles for :article_id
   */
  public function thereShouldBeUnverifiedRelatedArticlesFor($expected, $article_id) {
    $article = ElifeArticleVersion::getArticle($article_id);
    $expected = intval($expected);
    $results = ElifeArticleVersion::retrieveRelatedArticles($article->nid, FALSE);
    $actual = count($results);
    Assertions::assertSame($expected, $actual);
  }

  /**
   * @Then article :article_id should be related to :related_to
   */
  public function articleShouldBeRelatedTo($article_id, $related_to) {
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
  public function articleShouldNotBeRelatedTo($article_id, $not_related_to) {
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
  public function articleShouldHaveUnverifiedRelatedArticles($article_id, $related_to) {
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
  public function iAddToEntityqueue($type, $title, $queue) {
    Assertions::assertTrue(module_exists('entityqueue'), 'Entityqueue module is enabled');
    $node = $this->getEntityByTypeAndProperty('node', $type, 'title', $title);
    $subqueue = entityqueue_subqueue_load($queue);
    Assertions::assertNotNull($subqueue, 'Entityqueue with supplied title not found');
    $eq_node = array(array('target_id' => $node->nid));
    if (!empty($subqueue->eq_node)) {
      $eq_node = array_merge($eq_node, $subqueue->eq_node[LANGUAGE_NONE]);
    }
    $subqueue->eq_node[LANGUAGE_NONE] = $eq_node;
    entityqueue_subqueue_save($subqueue);
  }

  /**
   * @When I delete the :type with title :title
   */
  public function iDeleteTheNodeWithTitle($type, $title) {
    node_delete($this->getEntityByTypeAndProperty('node', $type, 'title', $title)->nid);
  }

  /**
   * @Given I set variable :name to :type :value
   */
  public function iSetVariableToArray($name, $type, $value) {
    if ($type == 'array') {
      $value = json_decode($value, TRUE);
    }
    variable_set($name, $value);
  }

  /**
   * Clicks element with specified id|title|alt|text.
   *
   * @When /^(?:|I )click the "(?P<element>[^"]*)" element$/
   */
  public function iClickOn($element) {
    $this->assertSession()->elementExists('css', $element)->click();
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
    return NULL;
  }

  /**
   * Check the URL value of a specific attribute of a tag.
   *
   * @Then /^(?:|I )should see the url "(?P<url>(?:[^"]|\\")*)" in the "(?P<attr>(?:[^"]|\\")*)" attribute of the "(?P<elem>(?:[^"]|\\")*)" element$/
   */
  public function iShouldSeeURLInTheAttributeOfTheElement($elem, $attr, $url) {
    $current_url = $this->returnValueOfAttribute($elem, $attr, TRUE);
    $url = $this->locatePath($url);
    if ($url !== $current_url) {
      throw new Exception('Expected url "' . $url . '" but found "' . $current_url . '"');
    }
  }

  /**
   * General check on the value of a specific attribute of a tag.
   *
   * @Then /^(?:|I )should see "(?P<text>(?:[^"]|\\")*)" in the "(?P<attr>(?:[^"]|\\")*)" attribute of the "(?P<elem>(?:[^"]|\\")*)" element$/
   *
   * @param string $elem
   *   The element's CSS selector.
   * @param string $attr
   *   The attribute name to examine.
   * @param string $text
   *   The expected text in the attribute.
   *
   * @throws Exception
   */
  public function iShouldSeeInTheAttributeOfTheElement($elem, $attr, $text) {
    $value_current = $this->returnValueOfAttribute($elem, $attr);
    if ($text !== $value_current) {
      throw new Exception('Expected value "' . $text . '" but found "' . $value_current . '"');
    }
  }

  /**
   * Check that an element has an attribute.
   *
   * This can be used for value-less attributes, such as 'download'.
   *
   * @Then /^the "(?P<elem>(?:[^"]|\\")*)" element should have the "(?P<attr>(?:[^"]|\\")*)" attribute$/
   */
  public function theElementShouldHaveTheAttribute($elem, $attr) {
    $this->returnValueOfAttribute($elem, $attr);
  }

  /**
   * Check for the value of a metatag.
   *
   * @Then /^the metatag attribute "(?P<attribute>[^"]*)" should have the value "(?P<value>[^"]*)"$/
   *
   * @throws Exception
   *   If region or link within it cannot be found.
   */
  public function assertMetaRegion($metatag, $value) {
    return $this->assertMetaRegionInPosition($metatag, 0, $value);
  }

  /**
   * Check for the value of a metatag.
   *
   * @Then /^the metatag attribute "(?P<attribute>[^"]*)" in position "(?P<position>[^"]*)" should have the value "(?P<value>[^"]*)"$/
   *
   * @throws Exception
   *   If region or link within it cannot be found.
   */
  public function assertMetaRegionInPosition($metatag, $position, $value) {
    $types = array(
      'name',
      'property',
    );
    $element_found = FALSE;

    $xpath_query = "/head/meta[@%s='" . $metatag . "']";

    if ($position > 0) {
      $xpath_query .= '[' . $position . ']';
    }

    foreach ($types as $type) {
      $xpath = sprintf($xpath_query, $type);
      $element = $this->getSession()
        ->getPage()
        ->find('xpath', $xpath . '/@content');
      if (!empty($element)) {
        $element_found = TRUE;
      }

      $element = $this->getSession()
        ->getPage()
        ->find('xpath', $xpath . "[@content='" . $value . "']");

      if (!empty($element)) {
        return TRUE;
      }
    }

    $attribute = $metatag;

    if ($position > 0) {
      $attribute .= ' [' . $position . ']';
    }

    if ($element_found) {
      throw new Exception(sprintf('No value match for the metatag attribute "%s" found on the page %s', $attribute, $this->getSession()->getCurrentUrl()));
    }
    else {
      throw new Exception(sprintf('No metatag attribute "%s" found on the page %s', $attribute, $this->getSession()->getCurrentUrl()));
    }
  }

  /**
   * Return value of attribute in element.
   *
   * @param string $elem
   *   Element that we wish to inspect.
   * @param string $attr
   *   Attribute of the element that we wish to inspect.
   * @param bool $url_flag
   *   Set TRUE if value is a url. FALSE is default.
   *
   * @return mixed|null|string
   *   Return value of attribute in element or throw exception.
   * @throws Exception
   */
  private function returnValueOfAttribute($elem, $attr, $url_flag = FALSE) {
    $element = $this->getSession()->getPage()->find("css", $elem);
    if (!$element) {
      throw new Exception('Expected element ' . $elem . ' not found on page.');
    }
    if (!$element->hasAttribute($attr)) {
      throw new Exception('Expected element ' . $elem . ' to have attribute ' . $attr . ', but it does not.');
    }

    $current_value = $element->getAttribute($attr);

    if ($url_flag) {
      $current_value = $this->locatePath($current_value);
    }

    return $current_value;
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

  /**
   * @Then /^the "([^"]*)" with the "([^"]*)" of "([^"]*)" should be like:$/
   */
  public function theWithTheOfShouldBeLike($bundle, $field, $article_id, TableNode $table) {
    $reference = $this->getEntityByTypeAndField('node', $bundle, $field, 'value', $article_id);

    /* @var EntityDrupalWrapper $entity */
    $reference = entity_metadata_wrapper('node', $reference);

    foreach ($table as $row) {
      foreach ($row as $column => $value) {
        $column = explode(':', $column, 2);

        if (isset($column[1])) {
          $expected_value = $reference->{$column[0]}->value()[$column[1]];
        }
        else {
          $expected_value = $reference->{$column[0]}->value();
        }

        if ($expected_value !== $value) {
          throw new Exception('Expected value ' . $value . ' but found ' . $expected_value);
        }
      }
    }
  }

  /**
   * @When /^the article "([^"]*)" is unpublished$/
   */
  public function theArticleIsUnpublished($article_version_id) {
    module_load_include('inc', 'elife_services', 'resources/publish');

    _elife_services_publish($article_version_id, json_encode(['publish' => FALSE]));
  }

  /**
   * @When /^the article "([^"]*)" is deleted$/
   */
  public function theArticleIsDeleted($article_version_id) {
    module_load_include('inc', 'elife_services', 'resources/article');

    _elife_services_article_delete($article_version_id);
  }

  /**
   * Returns fixed step argument (with \\" replaced back to ").
   *
   * @param string $argument
   *
   * @return string
   */
  protected function fixStepArgument($argument) {
    return str_replace('\\"', '"', $argument);
  }

  /**
   * @Given the search index is updated
   */
  public function searchIndexIsUpdated() {
    $this->getDrushDriver()->drush('elysia-cron');
  }

  /**
   * @return \Drupal\Driver\DrushDriver
   */
  public function getDrushDriver()
  {
    return $this->getDriver('drush');
  }

  /**
   * @Given the markup service is available
   */
  public function markupServiceAvailable() {
    // @todo - elife - nlisgo - We need the step until we can apply it automatically when the @markup tag is used.
    variable_set('elife_article_markup_service_factory', '_elife_article_mock_xsl_markup_service');
  }

  /**
   * @Given the citation service is available
   */
  public function citationServiceAvailable() {
    // @todo - elife - nlisgo - We need the step until we can apply it automatically when the @citation tag is used.
    variable_set('elife_article_citation_service_factory', '_elife_article_mock_citation_service');
  }

  /**
   * Look for Content disposition header with the supplied text.
   *
   * @Then /^(?:|I )should see the header content filename "([^"]*)"$/
   *
   * @param string $filename
   *   The particular filename to look for in the header.
   *
   * @throws Exception
   */
  public function iShouldSeeTheHeaderContentFilename($filename) {
    $head = "Content-Disposition";
    $pat = "#(.*); filename=\"$filename\"$#";
    $driver = $this->getSession()->getDriver();
    $headers = $driver->getResponseHeaders();
    if (array_key_exists($head, $headers)) {
      foreach ($headers[$head] as $k => $v) {
        if (preg_match($pat, $v)) {
          return;
        }
      }
      $val = $headers[$head];
      if (is_array($val)) {
        $val = implode(" //", $val);
      }
      throw new Exception("Did not see \"$head: $filename\" in the headers, but found: \"$head: $val\".");
    }
    else {
      throw new Exception("Did not see \"$head: $filename\" in the headers.");
    }
  }

  /**
   * @Then /^the response body should contain "([^"]*)"$/
   */
  public function responseBodyShouldContain($text) {
    $expectedRegexp = '/' . preg_quote($text) . '/i';
    $actual = (string) $this->getSession()->getPage()->getContent();
    Assertions::assertRegExp($expectedRegexp, $actual);
  }

  /**
   * Get an entity by a property value.
   *
   * @param string $entity_type
   * @param string $bundle
   * @param string $property
   * @param string $value
   *
   * @return object|bool
   *   Entity, or FALSE.
   */
  protected function getEntityByTypeAndProperty($entity_type, $bundle, $property, $value) {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', $entity_type);
    $query->propertyCondition('type', $bundle);
    $query->propertyCondition($property, $value);
    $entities = $query->execute();
    Assertions::assertTrue(isset($entities['node']), 'node not found');
    Assertions::assertCount(1, $entities['node'], 'more than one node found');

    return node_load(key($entities['node']));
  }

  /**
   * Get an entity by a field value.
   *
   * @param string $entity_type
   * @param string $bundle
   * @param string $field
   * @param string $column
   * @param string $value
   *
   * @return object|bool
   *   Entity, or FALSE.
   */
  protected function getEntityByTypeAndField($entity_type, $bundle, $field, $column, $value) {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', $entity_type);
    $query->propertyCondition('type', $bundle);
    $query->fieldCondition($field, $column, $value);
    $entities = $query->execute();
    Assertions::assertTrue(isset($entities['node']), 'node not found');
    Assertions::assertCount(1, $entities['node'], 'more than one node found');

    return node_load(key($entities['node']));
  }
}
