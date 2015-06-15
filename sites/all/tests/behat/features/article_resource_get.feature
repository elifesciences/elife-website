Feature: Article Resource - GET (API)
  In order to access article content
  As a production system
  I need to be able to retrieve article content via the resource api

  @api
  Scenario: Get an article
    Given "elife_article_ver" content:
      | field_elife_a_full_title | field_elife_a_article_version_id | field_elife_a_article_id |
      | VOR 05224                | 05224.1                          | 05224                    |
    And "elife_article" content:
      | field_elife_a_article_id |
      | 05224                    |
    And I set header "Content-Type" with value "application/json"
    And I send a GET request to "api/article/05224.1.json"
    Then the response code should be 200
    And the response should contain json:
      """
        {
          "title": "VOR 05224"
        }
      """

  Scenario: Request an article that is not available
    Given I set header "Content-Type" with value "application/json"
    And I send a GET request to "api/article/05224.1.json"
    Then the response code should be 404
