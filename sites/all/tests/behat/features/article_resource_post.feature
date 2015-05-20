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
          "version": 1,
          "doi": "10.7554/eLife.05227",
          "volume": 4,
          "article-id": "10.7554/eLife.05227",
          "apath": "05227",
          "pub-date": "1979-08-17",
          "path": "content/4/e05227",
          "article-type": "research-article",
          "early": 0
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
          "version": 1,
          "doi": "<invalid_doi>",
          "volume": 4,
          "article-id": "10.7554/eLife.05227",
          "apath": "05227",
          "pub-date": "1979-08-17",
          "path": "content/4/e05227",
          "article-type": "research-article",
          "early": 0
        }
      """
    Then response code should be 406
    And response should contain "Invalid value provided: doi"

    Examples:
      | invalid_doi |
      | invalid doi |
      | 10.7554/eLife.0522 |

  @api
  Scenario: Post an article with an id that isn't unique
    Given "elife_article" content:
      | field_elife_a_apath |
      | 05227               |
    And I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05227",
          "version": 1,
          "doi": "10.7554/eLife.05227",
          "volume": 4,
          "article-id": "10.7554/eLife.05227",
          "apath": "05227",
          "pub-date": "1979-08-17",
          "path": "content/4/e05227",
          "article-type": "research-article",
          "early": 0
        }
      """
    Then response code should be 406
    And response should contain "Invalid value provided: apath (must be unique)"

  Scenario Outline: Attempt to post an article without all required fields
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          <required_data>
        }
      """
    Then response code should be 406
    And response should contain "No value provided for required: <field_errors>"

    Examples:
      | required_data | field_errors |
      |  | title, article-type, doi, volume, pub-date, version, path, apath |
      | "title":"Title" | article-type, doi, volume, pub-date, version, path, apath |
      | "title":"Title","doi":"DOI","path":"content/4/e05224" | article-type, volume, pub-date, version, apath |
