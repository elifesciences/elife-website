@happy
Feature: Article Resource - GetUpdate requests (API)
  In order to verify that we get the expected result
  As a production system
  I need to GET and UPDATE an article

  @api
  Scenario: GET and UPDATE an article in sequence
    Given "elife_article_ver" content:
      | field_elife_a_full_title | field_elife_a_article_version_id | field_elife_a_article_id |
      | VOR 05227                | 05227.1                          | 05227                    |
    And "elife_article" content:
      | field_elife_a_article_id |
      | 05227                    |
    And I set header "Content-Type" with value "application/json"
    And I send a GET request to "api/article/05227.1.json"
    Then the response code should be 200
    And the response should contain json:
      """
        {
          "title": "VOR 05227"
        }
      """
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "Updated VOR 05227",
          "version": "1",
          "doi": "10.7554/eLife.05227",
          "volume": "4",
          "article-id": "10.7554/eLife.05227",
          "article-version-id": "05227.1",
          "pub-date": "1979-08-17",
          "path": "content/4/e05227",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1"
        }
      """
    And the response code should be 200
    And I send a GET request to "api/article/05227.1.json"
    And the response code should be 200
    Then the response should contain json:
      """
        {
          "title": "Updated VOR 05227"
        }
      """