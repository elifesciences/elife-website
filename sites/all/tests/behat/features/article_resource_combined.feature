Feature: Article Resource - Combined requests (API)
  In order to verify that we get the expected result
  As a production system
  I need to be able to be able to POST, GET, UPDATE and DELETE an article

  Scenario: POST, GET, UPDATE and DELETE an article in sequence
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05227",
          "version": "1",
          "doi": "10.7554/eLife.05227",
          "volume": "4",
          "article-id": "10.7554/eLife.05227",
          "article-version-id": "05227",
          "pub-date": "1979-08-17",
          "path": "content/4/e05227",
          "article-type": "research-article",
          "status": "VOR"
        }
      """
    And the response code should be 200
    And I send a GET request to "api/article/05227.json"
    And the response code should be 200
    And the response should contain json:
      """
        {
          "title": "VOR 05227"
        }
      """
    And I send a PUT request to "api/article/05227.json" with body:
      """
        {
          "title": "Updated VOR 05227"
        }
      """
    And the response code should be 200
    And I send a DELETE request to "api/article/05227.json"
    Then the response code should be 200
