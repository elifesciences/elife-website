@debug
Feature: Front Matter
  As a website editor
  I want to maintain the cover page front matter section
  So I can draw attention to the latest content

  @api
  Scenario: Load cover item to homepage
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05224 v1",
          "version": "1",
          "doi": "10.7554/eLife.05224.1",
          "volume": "4",
          "article-id": "05224",
          "article-version-id": "05224.1",
          "pub-date": "1979-08-17",
          "path": "content/4/e05224v1",
          "article-type": "research-article",
          "status": "VOR"
        }
      """
    And the response code should be 200
    And "elife_cover" content:
      | title | field_elife_fm_reference | field_elife_fm_reference_type |
      | Check out 05224 | 05224 | Article |
    And I add "elife_cover" with title "Check out 05224" to entityqueue "elife_cover"
    When I am on the homepage
    Then I should see the text "Check out 05224" in the "front_matter" region
