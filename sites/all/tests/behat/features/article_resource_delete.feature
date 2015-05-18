@api
Feature: Article Resource - DELETE (API)
  In order to maintain article content
  As a production system
  I need to be able to delete article content via the resource api

  Scenario: Delete an article
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05224",
          "version": 1,
          "doi": "10.7554/eLife.05224",
          "volume": 4,
          "article-id": "10.7554/eLife.05224",
          "apath": "05224",
          "pdate": "1979-08-17",
          "path": "content/4/e05224",
          "article-type": "research-article"
        }
      """
    And print response
    And the response code should be 200
    And I set header "Content-Type" with value "application/json"
    And I send a DELETE request to "api/article/05224.json"
    And the response code should be 200
    And I send a GET request to "api/article/05224.json"
    Then the response code should be 404

  Scenario: Attempt to delete an article that isn't present
    Given I set header "Content-Type" with value "application/json"
    And I send a DELETE request to "api/article/05224.json"
    Then the response code should be 404
