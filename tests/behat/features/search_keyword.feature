Feature: Article Search - Keywords
  In order to list articles with keywords
  As a user
  I need to be able to search the content using the keywords

  @api
  Scenario Outline: Set keywords
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
    """
        {
          "title": "VOR 05224",
          "version": "1",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "elocation-id": "e05224",
          "article-id": "10.7554/eLife.05224",
          "article-version-id": "05224",
          "pub-date": "1979-08-17",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1",
          "keywords": {
            <keywords>
          }
        }
      """
    And the response code should be 200
    And I run cron
    Given I am on "/elife/search"
    Then the response status code should be 200
    And I should see "Browse articles" in the "h1.pane-title" element
    And I fill in "Keyword" with "Algoriphagus"
    And I press the Search button
    Then the url should match "/elife/search"
    And I should see an ".view-elife-search .view-content" element
    And I should see 2 ".article-teaser__title" elements

  Examples:
    | keywords                                                                                                                                          |
    | "author-keywords": ["<italic>Salpingoeca rosetta</italic>", "Algoriphagus"]                                                                       |
    | "author-keywords": ["<italic>Salpingoeca rosetta</italic>", "Algoriphagus"], "research-organism": ["Mouse","<italic>C. elegans</italic>","Other"] |
