Feature: Article Resource - Related articles (API)
  In order to maintain article content
  As a production system
  I need to be able to post versions of article content via the resource api

  Scenario: Set related articles
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05224",
          "version": "1",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "article-id": "05224",
          "article-version-id": "05224.1",
          "pub-date": "1979-08-17",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1",
          "related-articles": [
            {
              "type": "commentary",
              "href": "10.7554/eLife.05224"
            },
            {
              "type": "commentary-article",
              "href": "10.7554/eLife.05225"
            },
            {
              "type": "article-reference",
              "href": "10.7554/eLife.05226"
            }
          ]
        }
      """
    Then the response code should be 200
    And the response should contain json:
      """
        {
          "related-articles": [
            {
              "type": "commentary",
              "href": "10.7554/eLife.05224"
            },
            {
              "type": "commentary-article",
              "href": "10.7554/eLife.05225"
            },
            {
              "type": "article-reference",
              "href": "10.7554/eLife.05226"
            }
          ]
        }
      """
    And there should be 1 verified related article
    And there should be 2 unverified related articles
