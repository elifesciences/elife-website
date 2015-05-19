Feature: Article Resource - Related (API)
  In order to maintain article content
  As a production system
  I need to be able to post article content with related content via the resource api

  @api
  Scenario: Post an article with related content
    Given "elife_article" content:
      | field_elife_a_full_title | field_elife_a_apath | field_elife_a_doi   | field_elife_a_early | field_elife_a_version | field_elife_a_fpubdate |
      | VOR 05224                | 05224               | 10.7554/eLife.05224 | 0                   | 1                     | 1979-08-17             |
    And I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 06003",
          "version": 1,
          "doi": "10.7554/eLife.06003",
          "volume": 4,
          "article-id": "10.7554/eLife.06003",
          "apath": "06003",
          "pdate": "1979-08-17",
          "path": "content/4/e06003",
          "article-type": "research-article",
          "related-article": [
            {
              "type": "corrected-article",
              "href": "10.7554/eLife.05224",
              "source": "10.7554/eLife.06003"
            }
          ],
          "early": 0
        }
      """
    And the response code should be 200
    Then there should be 1 related article for "10.7554/eLife.06003"
