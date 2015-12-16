@api
Feature: Article Resource - Authenticate (API)
  In order to ensure only authorised users create article content
  As a production system
  I need to be able to implement basic authentication on API calls

  Background:
    Given there are articles:
      """
        [
          {
            "title": "VOR 05224 v1",
            "version": "1",
            "doi": "10.7554/eLife.05224.1",
            "volume": "4",
            "elocation-id": "e05224",
            "article-id": "05224",
            "article-version-id": "05224.1",
            "pub-date": "1979-08-17",
            "path": "content/4/e05224v1",
            "article-type": "research-article",
            "status": "VOR",
            "publish": "1"
          },
          {
            "title": "VOR 05224 v2",
            "version": "2",
            "doi": "10.7554/eLife.05224.2",
            "volume": "4",
            "elocation-id": "e05224",
            "article-id": "05224",
            "article-version-id": "05224.2",
            "pub-date": "1979-08-17",
            "path": "content/4/e05224v2",
            "article-type": "research-article",
            "status": "VOR",
            "publish": "0"
          }
        ]
      """

  Scenario: Anonymous users can retrieve published content via API
    Given I am an anonymous user
    And I set header "Content-Type" with value "application/json"
    When I send a GET request to "api/article/05224.1.json"
    Then the response code should be 200
    When I send a GET request to "api/article/05224.2.json"
    Then the response code should be 403

    When I send a PUT request to "api/publish/05224.2.json" with body:
      """
        {
          "publish": "1"
        }
      """
    Then the response code should be 403

    When I send a DELETE request to "api/article/05224.2.json"
    Then the response code should be 403

    When I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05224 v2",
          "version": "2",
          "doi": "10.7554/eLife.05224.2",
          "volume": "4",
          "elocation-id": "e05224",
          "article-id": "05224",
          "article-version-id": "05224.2",
          "pub-date": "1979-08-17",
          "path": "content/4/e05224v2",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1"
        }
      """
    Then the response code should be 403

  Scenario: Users with the appropriate permissions can perform all API operations
    Given I am logged in as a user with the "eLife Article Publisher" role
    And I am authenticating as the Drupal user
    And I set header "Content-Type" with value "application/json"
    When I send a GET request to "api/article/05224.1.json"
    Then the response code should be 200
    When I send a GET request to "api/article/05224.2.json"
    Then the response code should be 200

    When I send a PUT request to "api/publish/05224.2.json" with body:
      """
        {
          "publish": "1"
        }
      """
    Then the response code should be 200

    When I send a DELETE request to "api/article/05224.2.json"
    Then the response code should be 200
    When I send a GET request to "api/article/05224.2.json"
    Then the response code should be 404

    When I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05224 v2",
          "version": "2",
          "doi": "10.7554/eLife.05224.2",
          "volume": "4",
          "elocation-id": "e05224",
          "article-id": "05224",
          "article-version-id": "05224.2",
          "pub-date": "1979-08-17",
          "path": "content/4/e05224v2",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1"
        }
      """
    Then the response code should be 200
    When I send a GET request to "api/article/05224.2.json"
    Then the response code should be 200
