@api
Feature: Article Resource - Versions (API)
  In order to maintain article content
  As a production system
  I need to be able to post versions of article content via the resource api

  Background:
    Given I am logged in as a user with the "eLife Article Publisher" role
    And I am authenticating as the Drupal user

  Scenario: Post a new version of an article - test case 1
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "Early 05224 v1",
          "version": 1,
          "doi": "10.7554/eLife.05224",
          "volume": 4,
          "elocation-id": "e05224",
          "article-id": "10.7554/eLife.05224",
          "article-version-id": "05224.early.v1",
          "pub-date": "1979-08-15T00:00:00+00:00",
          "update": "1979-08-15T00:00:00+00:00",
          "path": "content/4/e05224.early.v1",
          "article-type": "research-article",
          "status": "POA",
          "publish": true
        }
      """
    And the response code should be 200
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05224",
          "version": 2,
          "doi": "10.7554/eLife.05224",
          "volume": 4,
          "elocation-id": "e05224",
          "article-id": "10.7554/eLife.05224",
          "article-version-id": "05224",
          "pub-date": "1979-08-15T00:00:00+00:00",
          "update": "1979-08-16T00:00:00+00:00",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "VOR",
          "publish": true
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
          "version": 1,
          "doi": "10.7554/eLife.05224",
          "volume": 4,
          "elocation-id": "e05224",
          "article-id": "10.7554/eLife.05224",
          "article-version-id": "05224.early.v1",
          "pub-date": "1979-08-15T00:00:00+00:00",
          "update": "1979-08-15T00:00:00+00:00",
          "path": "content/4/e05224.early.v1",
          "article-type": "research-article",
          "status": "POA",
          "publish": true
        }
      """
    And the response code should be 200
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "Early 05224 v2",
          "version": 2,
          "doi": "10.7554/eLife.05224",
          "volume": 4,
          "elocation-id": "e05224",
          "article-id": "10.7554/eLife.05224",
          "article-version-id": "05224.early.v2",
          "pub-date": "1979-08-15T00:00:00+00:00",
          "update": "1979-08-16T00:00:00+00:00",
          "path": "content/4/e05224.early.v2",
          "article-type": "research-article",
          "status": "POA",
          "publish": true
        }
      """
    And the response code should be 200
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05224",
          "version": 3,
          "doi": "10.7554/eLife.05224",
          "volume": 4,
          "elocation-id": "e05224",
          "article-id": "10.7554/eLife.05224",
          "article-version-id": "05224",
          "pub-date": "1979-08-15T00:00:00+00:00",
          "update": "1979-08-17T00:00:00+00:00",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "VOR",
          "publish": true
        }
      """
    And the response code should be 200
    Then there should be 3 versions of article "10.7554/eLife.05224"

  Scenario: Post a new version of an article - correct order with mixture of published and unpublished
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "Early 05224 v1",
          "version": 1,
          "doi": "10.7554/eLife.05224",
          "volume": 4,
          "elocation-id": "e05224",
          "article-id": "10.7554/eLife.05224",
          "article-version-id": "05224.early.v1",
          "pub-date": "1979-08-15T00:00:00+00:00",
          "update": "1979-08-15T00:00:00+00:00",
          "path": "content/4/e05224.early.v1",
          "article-type": "research-article",
          "status": "POA",
          "publish": true
        }
      """
    And the response code should be 200
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "Early 05224 v2",
          "version": 2,
          "doi": "10.7554/eLife.05224",
          "volume": 4,
          "elocation-id": "e05224",
          "article-id": "10.7554/eLife.05224",
          "article-version-id": "05224.early.v2",
          "pub-date": "1979-08-15T00:00:00+00:00",
          "update": "1979-08-16T00:00:00+00:00",
          "path": "content/4/e05224.early.v2",
          "article-type": "research-article",
          "status": "POA",
          "publish": false
        }
      """
    And the response code should be 200
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05224",
          "version": 3,
          "doi": "10.7554/eLife.05224",
          "volume": 4,
          "elocation-id": "e05224",
          "article-id": "10.7554/eLife.05224",
          "article-version-id": "05224",
          "pub-date": "1979-08-15T00:00:00+00:00",
          "update": "1979-08-17T00:00:00+00:00",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "VOR",
          "publish": true
        }
      """
    And the response code should be 200
    Then there should be 2 published versions of article "10.7554/eLife.05224"
    And there should be 1 unpublished versions of article "10.7554/eLife.05224"
    And the versions should be ordered "05224,05224.early.v1,05224.early.v2" for "10.7554/eLife.05224"

  Scenario: Overwrite unpublished versions of an article
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "05224",
          "version": 1,
          "doi": "10.7554/eLife.05224",
          "volume": 4,
          "elocation-id": "e05224",
          "article-id": "05224",
          "article-version-id": "05224.1",
          "pub-date": "1979-08-15T00:00:00+00:00",
          "update": "1979-08-15T00:00:00+00:00",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "POA",
          "publish": false
        }
      """
    And the response code should be 200
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "05224",
          "version": 1,
          "doi": "10.7554/eLife.05224",
          "volume": 4,
          "elocation-id": "e05224",
          "article-id": "05224",
          "article-version-id": "05224.1",
          "pub-date": "1979-08-15T00:00:00+00:00",
          "update": "1979-08-15T00:00:00+00:00",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "POA",
          "publish": false
        }
      """
    And the response code should be 200
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "05224",
          "version": 1,
          "doi": "10.7554/eLife.05224",
          "volume": 4,
          "elocation-id": "e05224",
          "article-id": "05224",
          "article-version-id": "05224.1",
          "pub-date": "1979-08-15T00:00:00+00:00",
          "update": "1979-08-15T00:00:00+00:00",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "POA",
          "publish": true
        }
      """
    Then there should be 1 versions of article "05224"

  Scenario: Test posting unpublished version of an article
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "05224",
          "version": 1,
          "doi": "10.7554/eLife.05224",
          "volume": 4,
          "elocation-id": "e05224",
          "article-id": "05224",
          "article-version-id": "05224.1",
          "pub-date": "1979-08-15T00:00:00+00:00",
          "update": "1979-08-15T00:00:00+00:00",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "POA",
          "publish": false
        }
      """
    When the response code should be 200
    Then there should be 1 versions of article "05224"
    And there should be 0 published versions of article "05224"
    And there should be 1 unpublished versions of article "05224"
