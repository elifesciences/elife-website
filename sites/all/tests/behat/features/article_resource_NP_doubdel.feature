Feature: Article Resource - GetDelete requests (API)
  In order to verify that we get the expected result
  As a production system
  I need to be able to be able to GET and DELETE an article

  @api
  Scenario: GET and DELETE an article in sequence
    Given "elife_article" content:
      | field_elife_a_full_title | field_elife_a_article_version_id |
      | VOR 05227                | 05227                            |
    And I set header "Content-Type" with value "application/json"
    And I send a GET request to "api/article/05227.json"
    Then the response code should be 200
    And the response should contain json:
    """
        {
          "title": "VOR 05227"
        }
      """
    And I send a DELETE request to "api/article/05227.json"
    Then the response code should be 200
    And I send a DELETE request to "api/article/05227.json"
    Then the response code should be 404