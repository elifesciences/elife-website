Feature: Article Resource - UPDATE (API)
  In order to maintain article content
  As a production system
  I need to be able to update article content via the resource api

  @api
  Scenario: Update an article
    Given "elife_article_ver" content:
      | field_elife_a_full_title | field_elife_a_article_version_id | field_elife_a_article_id |
      | VOR 05224                | 05224.1                          | 05224                    |
    And "elife_article" content:
      | field_elife_a_article_id |
      | 05224                    |
    And I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "Updated VOR 05224",
          "version": "1",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "article-id": "05224",
          "article-version-id": "05224.1",
          "pub-date": "1979-08-17",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1"
        }
      """
    And the response code should be 200
    And I send a GET request to "api/article/05224.1.json"
    And the response code should be 200
    Then the response should contain json:
      """
        {
          "title": "Updated VOR 05224"
        }
      """
