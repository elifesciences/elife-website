Feature: Article Resource (API)
  In order to maintain article content
  As a production system
  I need to have access to an article resource api

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

  @api
  Scenario: Delete an article
    Given "elife_article" content:
      | title     | status | field_elife_a_apath |
      | VOR 05224 | 1      | 05224               |
    And I set header "Content-Type" with value "application/json"
    And I send a DELETE request to "api/article/05224.json"
    And the response code should be 200
    And I send a GET request to "api/article/05224.json"
    And the response code should be 404

  Scenario: Post an article
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
      {
        "title": "VOR 05227",
        "version": 1,
        "doi": "10.7554/eLife.05227",
        "article-id": "10.7554/eLife.05227",
        "apath": "05227",
        "pdate": "1979-08-17",
        "path": "content/4/e05227",
        "article-type": "research-article",
        "early": 0
      }
      """
    And the response code should be 200
    And I go to "content/4/e05227"
    Then I should see "VOR 05227" in the "h1" element
    And I should cleanup articles "05227"
