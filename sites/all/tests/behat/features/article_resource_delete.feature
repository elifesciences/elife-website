Feature: Article Resource - DELETE (API)
  In order to maintain article content
  As a production system
  I need to be able to delete article content via the resource api

  @api
  Scenario: Delete an article
    Given "elife_article" content:
      | field_elife_a_article_version_id |
      | 05224                            |
    And I set header "Content-Type" with value "application/json"
    And I send a DELETE request to "api/article/05224.json"
    And the response code should be 200
    And I send a GET request to "api/article/05224.json"
    Then the response code should be 404

  Scenario: Attempt to delete an article that isn't present
    Given I set header "Content-Type" with value "application/json"
    And I send a DELETE request to "api/article/05224.json"
    Then the response code should be 404
