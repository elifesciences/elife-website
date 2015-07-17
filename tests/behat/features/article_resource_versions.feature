Feature: Article Resource - Versions (API)
  In order to maintain article content
  As a production system
  I need to be able to post versions of article content via the resource api

  Scenario: Post a new version of an article - test case 1
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "Early 05224 v1",
          "version": "1",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "article-id": "10.7554/eLife.05224",
          "article-version-id": "05224.early.v1",
          "pub-date": "1979-08-15",
          "update": "1979-08-15",
          "path": "content/4/e05224.early.v1",
          "article-type": "research-article",
          "status": "POA",
          "publish": "1"
        }
      """
    And the response code should be 200
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05224",
          "version": "2",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "article-id": "10.7554/eLife.05224",
          "article-version-id": "05224",
          "pub-date": "1979-08-15",
          "update": "1979-08-16",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1"
        }
      """
    And the response code should be 200
    Then there should be 2 versions of article "10.7554/eLife.05224"

  Scenario: Post a new version of an article - test case 2
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "Early 05224 v1",
          "version": "1",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "article-id": "10.7554/eLife.05224",
          "article-version-id": "05224.early.v1",
          "pub-date": "1979-08-15",
          "update": "1979-08-15",
          "path": "content/4/e05224.early.v1",
          "article-type": "research-article",
          "status": "POA",
          "publish": "1"
        }
      """
    And the response code should be 200
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "Early 05224 v2",
          "version": "2",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "article-id": "10.7554/eLife.05224",
          "article-version-id": "05224.early.v2",
          "pub-date": "1979-08-15",
          "update": "1979-08-16",
          "path": "content/4/e05224.early.v2",
          "article-type": "research-article",
          "status": "POA",
          "publish": "1"
        }
      """
    And the response code should be 200
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05224",
          "version": "3",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "article-id": "10.7554/eLife.05224",
          "article-version-id": "05224",
          "pub-date": "1979-08-15",
          "update": "1979-08-17",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1"
        }
      """
    And the response code should be 200
    Then there should be 3 versions of article "10.7554/eLife.05224"

  Scenario: Overwrite unpublished versions of an article
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "05224",
          "version": "1",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "article-id": "05224",
          "article-version-id": "05224.1",
          "pub-date": "1979-08-15",
          "update": "1979-08-15",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "POA",
          "publish": "0"
        }
      """
    And the response code should be 200
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "05224",
          "version": "1",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "article-id": "05224",
          "article-version-id": "05224.1",
          "pub-date": "1979-08-15",
          "update": "1979-08-15",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "POA",
          "publish": "0"
        }
      """
    And the response code should be 200
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "05224",
          "version": "1",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "article-id": "05224",
          "article-version-id": "05224.1",
          "pub-date": "1979-08-15",
          "update": "1979-08-15",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "POA",
          "publish": "1"
        }
      """
    Then there should be 1 versions of article "05224"

  Scenario: Test posting unpublished version of an article
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "05224",
          "version": "1",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "article-id": "05224",
          "article-version-id": "05224.1",
          "pub-date": "1979-08-15",
          "update": "1979-08-15",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "POA",
          "publish": "0"
        }
      """
    When the response code should be 200
    Then there should be 1 versions of article "05224"
    And there should be 0 published versions of article "05224"
    And there should be 1 unpublished versions of article "05224"

