Feature: Competing Interests in Footnotes
  In order to be able to see competing interests declared be the author
  As a reader
  I should be able to see the competing interests are declared or not by the author

  @hover
  Scenario: Author has not declared competing interests
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
    """
        {
          "title": "VOR 05003",
          "version": "1",
          "doi": "10.7554/eLife.05003",
          "volume": "4",
          "article-id": "10.7554/eLife.05003",
          "article-version-id": "05003",
          "pub-date": "2015-04-02",
          "path": "content/4/e05003",
          "article-type": "research-article",
          "status": "VOR"
        }
      """
    And the response code should be 200
    And I go to "content/4/e05003"
    Then I should see "No competing interests declared" in the ".author-tooltip-conflict" element
    And I should see "No competing interests declared" in the ".author-info-title" element


  @javascript @hover
  Scenario Outline: Author has declared competing interests
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
    """
        {
          "title": "VOR 00007",
          "version": "1",
          "doi": "10.7554/eLife.00007",
          "volume": "1",
          "article-id": "10.7554/eLife.00007",
          "article-version-id": "00007",
          "pub-date": "2012-10-15",
          "path": "content/1/e00007",
          "article-type": "research-article",
          "status": "VOR"
        }
      """
    And the response code should be 200
    And I go to "content/1/e00007"
    Then I should see "Ian T" in the ".author-tooltip-name" element
    And I should see "Competing Interests:" in the ".author-tooltip-conflict" element
    And I should see "Competing Interests" in the ".author-info-title" element


