Feature: Article Resource - GET (API)
  In order to access article content
  As a production system
  I need to be able to retrieve article content via the resource api

  @api
  Scenario: Get an article
    Given "elife_article" content:
      | title     | status | field_elife_a_apath |
      | VOR 05224 | 1      | 05224               |
    And I set header "Content-Type" with value "application/json"
    And I send a GET request to "api/article/05224.json"
    And the response code should be 200
    Then the response should contain json:
      """
        {
          "title": "VOR 05224"
        }
      """

  Scenario: Request an article that is not available
    Given I set header "Content-Type" with value "application/json"
    And I send a GET request to "api/article/05224.json"
    Then the response code should be 404
