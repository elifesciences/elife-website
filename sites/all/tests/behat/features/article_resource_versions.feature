Feature: Article Resource - Versions (API)
  In order to maintain article content
  As a production system
  I need to be able to post versions of article content via the resource api

  @api
  Scenario: Post a new version of an article - test case 1
    Given "elife_article_ver" content:
      | field_elife_a_full_title | field_elife_a_article_version_id | field_elife_a_article_id | field_elife_a_early | field_elife_a_version | field_elife_a_update |
      | Early 05224 v1           | 05224.early.v1                   | 10.7554/eLife.05224      | 1                   | 1                     | 1979-08-15           |
    And "elife_article" content:
      | field_elife_a_article_id | field_elife_a_fpupdate |
      | 10.7554/eLife.05224      | 1979-08-15             |
    And I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05224",
          "version": "1",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "article-id": "10.7554/eLife.05224",
          "article-version-id": "05224",
          "pub-date": "1979-08-15",
          "update": "1979-08-17",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "VOR"
        }
      """
    And the response code should be 200
    Then there should be 2 versions of article "10.7554/eLife.05224"

  @api
  Scenario: Post a new version of an article - test case 2
    Given "elife_article_ver" content:
      | field_elife_a_full_title | field_elife_a_article_version_id | field_elife_a_article_id | field_elife_a_early | field_elife_a_version | field_elife_a_update |
      | Early 05224 v1           | 05224.early.v1                   | 10.7554/eLife.05224      | 1                   | 1                     | 1979-08-15           |
      | Early 05224 v2           | 05224.early.v2                   | 10.7554/eLife.05224      | 1                   | 2                     | 1979-08-16           |
    And "elife_article" content:
      | field_elife_a_article_id | field_elife_a_fpupdate |
      | 10.7554/eLife.05224      | 1979-08-15             |
    And I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05224",
          "version": "1",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "article-id": "10.7554/eLife.05224",
          "article-version-id": "05224",
          "pub-date": "1979-08-15",
          "update": "1979-08-17",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "VOR"
        }
      """
    And the response code should be 200
    Then there should be 3 versions of article "10.7554/eLife.05224"
