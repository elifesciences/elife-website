Feature: Article Resource - POST (API)
  In order to maintain article content
  As a production system
  I need to be able to post article content via the resource api

  Scenario: Post an article
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05227",
          "version": "1",
          "doi": "10.7554/eLife.05227",
          "volume": "4",
          "article-id": "10.7554/eLife.05227",
          "article-version-id": "05227",
          "pub-date": "1979-08-17",
          "path": "content/4/e05227",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1"
        }
      """
    And the response code should be 200
    And I go to "content/4/e05227"
    Then I should see "VOR 05227" in the "h1" element

  Scenario Outline: Post an article with an invalid doi
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05227",
          "version": "1",
          "doi": "<invalid_doi>",
          "volume": "4",
          "article-id": "10.7554/eLife.05227",
          "article-version-id": "05227",
          "pub-date": "1979-08-17",
          "path": "content/4/e05227",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1"
        }
      """
    Then response code should be 400
    And the response should contain the error message "referenced schema does not match" for the fields "data.doi"

    Examples:
      | invalid_doi |
      | invalid doi |
      | 10.7554/eLife.0522 |

  @api
  Scenario: Post an article with an id that isn't unique
    Given "elife_article_ver" content:
      | field_elife_a_article_version_id | field_elife_a_article_id |
      | 05227.1                          | 05227                    |
    And "elife_article" content:
      | field_elife_a_article_id |
      | 05227                    |
    And I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05227",
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
    Then response code should be 200

  Scenario Outline: Attempt to post an article without all required fields
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          <required_data>
        }
      """
    Then response code should be 400
    And the response should contain the error message "is required" for the fields "<field_errors>"

    Examples:
      | required_data | field_errors |
      |  | title, article-type, doi, volume, pub-date, version, path, article-id, article-version-id, status |
      | {"data.title":"foo","data.doi":"foo","data.path":"foo", "data.status":"foo"} | "data.article-type", "data.volume", "data.pub-date", "data.version", "data.article-id", "data.article-version-id" |

  Scenario: Use POST protocol to update an article
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05227",
          "version": "1",
          "doi": "10.7554/eLife.05227",
          "volume": "4",
          "article-id": "10.7554/eLife.05227",
          "article-version-id": "05227",
          "pub-date": "1979-08-17",
          "path": "content/4/e05227",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1"
        }
      """
    And the response code should be 200
    When I send a POST request to "api/article.json" with body:
      """
        {
          "title": "Updated VOR 05227",
          "version": "1",
          "doi": "10.7554/eLife.05227",
          "volume": "4",
          "article-id": "10.7554/eLife.05227",
          "article-version-id": "05227",
          "pub-date": "1979-08-17",
          "path": "content/4/e05227",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1"
        }
      """
    And the response code should be 200
    Then the response should contain json:
      """
        {
          "title": "Updated VOR 05227"
        }
      """
