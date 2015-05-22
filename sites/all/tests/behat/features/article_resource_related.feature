Feature: Article Resource - Related (API)
  In order to maintain article content
  As a production system
  I need to be able to post article content with contributors via the resource api

  Scenario: Load an article with related articles
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
          "related-article": [
            {
              "type": "corrected-article",
              "href": "10.7554/eLife.05224",
              "source": "10.7554/eLife.06003"
            },
            {
              "type": "article-reference",
              "href": "10.7554/eLife.06956",
              "source": "10.7554/eLife.05224"
            },
            {
              "type": "article-reference",
              "href": "10.7554/eLife.05224",
              "source": "10.7554/eLife.06956"
            }
          ],
          "status": "VOR"
        }
      """
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 06003",
          "version": "1",
          "doi": "10.7554/eLife.06003",
          "volume": "4",
          "article-id": "10.7554/eLife.06003",
          "article-version-id": "06003",
          "pub-date": "1979-08-17",
          "path": "content/4/e06003",
          "article-type": "research-article",
          "related-article": [
            {
              "type": "corrected-article",
              "href": "10.7554/eLife.05224",
              "source": "10.7554/eLife.06003"
            }
          ],
          "status": "VOR"
        }
      """
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 06956",
          "version": "1",
          "doi": "10.7554/eLife.06956",
          "volume": "4",
          "article-id": "10.7554/eLife.06956",
          "article-version-id": "06956",
          "pub-date": "1979-08-17",
          "path": "content/4/e06956",
          "article-type": "research-article",
          "related-article": [
            {
              "type": "article-reference",
              "href": "10.7554/eLife.06956",
              "source": "10.7554/eLife.05224"
            },
            {
              "type": "article-reference",
              "href": "10.7554/eLife.05224",
              "source": "10.7554/eLife.06956"
            }
          ],
          "status": "VOR"
        }
      """
    Then there should be 2 related article for "10.7554/eLife.05224"
    And there should be 1 related article for "10.7554/eLife.06003"
    And there should be 1 related article for "10.7554/eLife.06956"
