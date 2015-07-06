Feature: Article Resource - GET (API)
  In order to access article content
  As a production system
  I need to be able to retrieve article content via the resource api

  Scenario: Get an article
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05224",
          "version": "1",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "article-id": "10.7554/eLife.05224",
          "article-version-id": "05224.1",
          "pub-date": "1979-08-17",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1"
        }
      """
    And I send a GET request to "api/article/05224.1.json"
    Then the response code should be 200
    And the response should contain json:
      """
        {
          "title": "VOR 05224"
        }
      """

  Scenario: Request an article that is not available
    Given I set header "Content-Type" with value "application/json"
    When I send a GET request to "api/article/05224.1.json"
    Then the response code should be 404
