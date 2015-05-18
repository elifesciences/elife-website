Feature: Article Resource - PUT (API)
  In order to maintain article content
  As a production system
  I need to be able to update article content via the resource api

  @api
  Scenario: Update an article
    Given "elife_article" content:
      | title     | status | field_elife_a_apath |
      | VOR 05224 | 1      | 05224               |
    And I set header "Content-Type" with value "application/json"
    And I send a PUT request to "api/article/05224.json" with body:
      """
        {
          "title": "Updated VOR 05224"
        }
      """
    And the response code should be 200
    And I send a GET request to "api/article/05224.json"
    And the response code should be 200
    Then the response should contain json:
      """
        {
          "title": "Updated VOR 05224"
        }
      """

  Scenario: Attempt to update an article that is not available
    Given I set header "Content-Type" with value "application/json"
    And I send a PUT request to "api/article/05224.json" with body:
      """
        {
          "title": "Updated VOR 05224"
        }
      """
    Then the response code should be 404
