Feature: Front Matter
  As a website editor
  I want to maintain the cover page front matter section
  So I can draw attention to the latest content

  @api
  Scenario: Load cover item to homepage referencing an article
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
          "status": "VOR",
          "publish": "1"
        }
      """
    And the response code should be 200
    And "elife_cover" content:
      | title | field_elife_fm_reference | field_elife_fm_reference_type |
      | Check out 05224 | 05224 | Article |
    And I add "elife_cover" with title "Check out 05224" to entityqueue "elife_cover"
    When I am on the homepage
    Then I should see the text "Check out 05224" in the "front_matter_cover" region
    And I follow "Check out 05224" in the "front_matter_cover" region
    And I should be on "content/4/e05224v1"
    And I should see "VOR 05224 v1" in the "h1" element

  @api
  Scenario: Load front matter items to homepage
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05224",
          "version": "1",
          "doi": "10.7554/eLife.05224.1",
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
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05225",
          "version": "1",
          "doi": "10.7554/eLife.05225.1",
          "volume": "4",
          "article-id": "05225",
          "article-version-id": "05225.1",
          "pub-date": "1979-08-17",
          "path": "content/4/e05225",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1"
        }
      """
    And the response code should be 200
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05226",
          "version": "1",
          "doi": "10.7554/eLife.05226.1",
          "volume": "4",
          "article-id": "05226",
          "article-version-id": "05226.1",
          "pub-date": "1979-08-17",
          "path": "content/4/e05226",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1"
        }
      """
    And the response code should be 200
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05227",
          "version": "1",
          "doi": "10.7554/eLife.05227.1",
          "volume": "4",
          "article-id": "05227",
          "article-version-id": "05227.1",
          "pub-date": "1979-08-17",
          "path": "content/4/e05227",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1"
        }
      """
    And the response code should be 200
    And "elife_front_matter" content:
      | title | field_elife_fm_reference | field_elife_fm_reference_type |
      | Check out 05224 | 05224 | Article |
      | Check out 05225 | 05225 | Article |
      | Check out 05226 | 05226 | Article |
      | Check out 05227 | 05227 | Article |
      | Podcast 1 | podcast/1 | Url |
      | Collection 1 | collection/1 | Url |
    And I add "elife_front_matter" with title "Check out 05224" to entityqueue "elife_front_matter_col_1"
    And I add "elife_front_matter" with title "Check out 05225" to entityqueue "elife_front_matter_col_1"
    And I add "elife_front_matter" with title "Podcast 1" to entityqueue "elife_front_matter_col_1"
    And I add "elife_front_matter" with title "Check out 05226" to entityqueue "elife_front_matter_col_2"
    And I add "elife_front_matter" with title "Check out 05227" to entityqueue "elife_front_matter_col_2"
    And I add "elife_front_matter" with title "Collection 1" to entityqueue "elife_front_matter_col_2"
    When I am on the homepage
    Then I should see the text "Check out 05224" in the "front_matter_col_1" region
    And I should see the text "Check out 05225" in the "front_matter_col_1" region
    And I should see the text "Podcast 1" in the "front_matter_col_1" region
    And I should see the text "Check out 05226" in the "front_matter_col_2" region
    And I should see the text "Check out 05227" in the "front_matter_col_2" region
    And I should see the text "Collection 1" in the "front_matter_col_2" region
    And I follow "Check out 05226" in the "front_matter_col_2" region
    And I should be on "content/4/e05226"
    And I should see "VOR 05226" in the "h1" element
