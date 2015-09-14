Feature: Article Search - Keywords
  In order to list articles with keywords
  As a user
  I need to be able to search the content using the keywords

  @api
  Scenario: Set keywords
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
    """
        {
          "title": "VOR 04565",
          "version": "1",
          "doi": "10.7554/eLife.04565",
          "volume": "3",
          "elocation-id": "e04565",
          "article-id": "04565",
          "article-version-id": "04565",
          "pub-date": "2014-09-19",
          "path": "content/3/e04565",
          "article-type": "article-commentary",
          "status": "VOR",
          "publish": "1",
          "keywords": {
            "author-keywords": [
              "Algoriphagus"
            ]
          }
        }
      """
    And the response code should be 200
    And I run cron
    Given I am on "/elife/search"
    Then the response status code should be 200
    And I should see "Browse articles" in the "h1.pane-title" element
    And I fill in "Keyword" with "Algoriphagus"
    And I click Search
    And I should see 1 ".article-teaser__title" elements
