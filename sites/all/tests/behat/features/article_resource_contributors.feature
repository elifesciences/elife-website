Feature: Article Resource - Related (API)
  In order to maintain article content
  As a production system
  I need to be able to post article content with contributors via the resource api

  Scenario: Load an article with contributors
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
          "contributors": [
            {
              "type": "author",
              "equal-contrib": "yes",
              "id": "author-1",
              "surname": "Surname",
              "given-names": "First A"
            },
            {
              "type": "author",
              "id": "author-2",
              "surname": "Surname",
              "given-names": "First B"
            }
          ],
          "status": "VOR"
        }
      """
    Then there should be 2 contributors for "10.7554/eLife.05224"
