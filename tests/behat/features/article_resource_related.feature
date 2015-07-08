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

  Scenario: Check correct number of articles related
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
            },
            {
              "type": "article-reference",
              "href": "10.7554/eLife.05227"
            }
          ]
        }
      """
    Then the response code should be 200
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05227",
          "version": "1",
          "doi": "10.7554/eLife.05227",
          "volume": "4",
          "article-id": "05227",
          "article-version-id": "05227.1",
          "pub-date": "1979-08-17",
          "path": "content/4/e05227",
          "article-type": "correction",
          "status": "VOR",
          "publish": "1",
          "related-articles": [
            {
              "type": "article-reference",
              "href": "10.7554/eLife.05224"
            }
          ]
        }
      """
    Then the response code should be 200
    And there should be 3 verified related articles
    And there should be 3 verified related articles for "05224"
    And there should be 2 verified related articles for "05227"
    And there should be 2 unique verified related articles
    And there should be 2 unique verified related articles for "05224"
    And there should be 1 unique verified related articles for "05227"
    And there should be 2 unverified related articles
    And there should be 2 unverified related articles for "05224"
    And there should be 0 unverified related articles for "05227"
    And article "05224" should be related to "05224, 05227"
    And article "05227" should be related to "05224"
    And article "05224" should have unverified related articles of "10.7554/eLife.05225, 10.7554/eLife.05226"

  Scenario: Check correct number of articles related when multiple versions of the article available with the same DOIs
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05224v2",
          "version": "2",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "article-id": "05224",
          "article-version-id": "05224.2",
          "pub-date": "1979-08-17",
          "path": "content/4/e05224v2",
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
            }
          ]
        }
      """
    Then the response code should be 200
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05224v1",
          "version": "1",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "article-id": "05224",
          "article-version-id": "05224.1",
          "pub-date": "1979-08-17",
          "path": "content/4/e05224v1",
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
            },
            {
              "type": "article-reference",
              "href": "10.7554/eLife.05227"
            }
          ]
        }
      """
    Then the response code should be 200
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05227v1",
          "version": "1",
          "doi": "10.7554/eLife.05227",
          "volume": "4",
          "article-id": "05227",
          "article-version-id": "05227.1",
          "pub-date": "1979-08-17",
          "path": "content/4/e05227v1",
          "article-type": "correction",
          "status": "VOR",
          "publish": "1",
          "related-articles": [
            {
              "type": "article-reference",
              "href": "10.7554/eLife.05224"
            }
          ]
        }
      """
    Then the response code should be 200
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05227v2",
          "version": "2",
          "doi": "10.7554/eLife.05227",
          "volume": "4",
          "article-id": "05227",
          "article-version-id": "05227.2",
          "pub-date": "1979-08-17",
          "path": "content/4/e05227v2",
          "article-type": "correction",
          "status": "VOR",
          "publish": "1",
          "related-articles": [
            {
              "type": "article-reference",
              "href": "10.7554/eLife.05224"
            }
          ]
        }
      """
    Then the response code should be 200
    And there should be 2 verified related articles
    And there should be 2 verified related articles for "05224"
    And there should be 1 verified related articles for "05227"
    And there should be 2 unique verified related articles
    And there should be 2 unique verified related articles for "05224"
    And there should be 1 unique verified related articles for "05227"
    And there should be 1 unverified related articles
    And there should be 1 unverified related articles for "05224"
    And there should be 0 unverified related articles for "05227"
    And article "05224" should be related to "05224, 05227"
    And article "05227" should be related to "05224"
    And article "05224" should have unverified related articles of "10.7554/eLife.05225"

  Scenario: Check correct number of articles related when multiple version of the article available with different DOIs
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
    """
        {
          "title": "VOR 05224v2",
          "version": "2",
          "doi": "10.7554/eLife.05224v2",
          "volume": "4",
          "article-id": "05224",
          "article-version-id": "05224.2",
          "pub-date": "1979-08-17",
          "path": "content/4/e05224v2",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1",
          "related-articles": [
            {
              "type": "commentary",
              "href": "10.7554/eLife.05224v1"
            },
            {
              "type": "commentary-article",
              "href": "10.7554/eLife.05225v1"
            }
          ]
        }
      """
    Then the response code should be 200
    And I send a POST request to "api/article.json" with body:
    """
        {
          "title": "VOR 05224v1",
          "version": "1",
          "doi": "10.7554/eLife.05224v1",
          "volume": "4",
          "article-id": "05224",
          "article-version-id": "05224.1",
          "pub-date": "1979-08-17",
          "path": "content/4/e05224v1",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1",
          "related-articles": [
            {
              "type": "commentary-article",
              "href": "10.7554/eLife.05225v1"
            },
            {
              "type": "article-reference",
              "href": "10.7554/eLife.05226v1"
            },
            {
              "type": "article-reference",
              "href": "10.7554/eLife.05227v2"
            }
          ]
        }
      """
    Then the response code should be 200
    And I send a POST request to "api/article.json" with body:
    """
        {
          "title": "VOR 05227v1",
          "version": "1",
          "doi": "10.7554/eLife.05227v1",
          "volume": "4",
          "article-id": "05227",
          "article-version-id": "05227.1",
          "pub-date": "1979-08-17",
          "path": "content/4/e05227v1",
          "article-type": "correction",
          "status": "VOR",
          "publish": "1",
          "related-articles": [
            {
              "type": "article-reference",
              "href": "10.7554/eLife.05224v1"
            }
          ]
        }
      """
    Then the response code should be 200
    And I send a POST request to "api/article.json" with body:
    """
        {
          "title": "VOR 05227v2",
          "version": "2",
          "doi": "10.7554/eLife.05227v2",
          "volume": "4",
          "article-id": "05227",
          "article-version-id": "05227.2",
          "pub-date": "1979-08-17",
          "path": "content/4/e05227v2",
          "article-type": "correction",
          "status": "VOR",
          "publish": "1",
          "related-articles": [
            {
              "type": "article-reference",
              "href": "10.7554/eLife.05224v2"
            }
          ]
        }
      """
    Then the response code should be 200
    And there should be 2 verified related articles
    And there should be 2 verified related articles for "05224"
    And there should be 1 verified related articles for "05227"
    And there should be 2 unique verified related articles
    And there should be 2 unique verified related articles for "05224"
    And there should be 1 unique verified related articles for "05227"
    And there should be 1 unverified related articles
    And there should be 1 unverified related articles for "05224"
    And there should be 0 unverified related articles for "05227"
    And article "05224" should be related to "05224, 05227"
    And article "05227" should be related to "05224"
    And article "05224" should have unverified related articles of "10.7554/eLife.05225v1"
