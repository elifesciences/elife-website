  Feature: Article Publish Resource (API)
  In order to maintain article content
  As a production system
  I need to be able to easily publish or unpublish content

  Scenario: Post content to site for preview only - anonymous user
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05224",
          "version": "1",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "article-id": "10.7554/eLife.05224",
          "article-version-id": "05224",
          "pub-date": "1979-08-17",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "0",
          "categories": {
            "display-channel": [
              "Research article"
            ],
            "heading": [
              "Cell biology",
              "Computer science"
            ]
          }
        }
      """
    And the response code should be 200
    And I am on "content/4/e05224"
    Then I should get a 404 HTTP response
