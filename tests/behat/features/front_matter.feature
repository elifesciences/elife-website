Feature: Front Matter
  As a website editor
  I want to maintain the cover page front matter section
  So I can draw attention to the latest content

  @api
  Scenario: Load cover item to homepage referencing an article
    Given there is an article:
      """
        {
          "title": "VOR 05224 v1",
          "version": "1",
          "doi": "10.7554/eLife.05224.1",
          "volume": "4",
          "elocation-id": "e05224",
          "article-id": "05224",
          "article-version-id": "05224.1",
          "pub-date": "1979-08-17",
          "path": "content/4/e05224v1",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1"
        }
      """
    And "elife_cover" content:
      | title | field_elife_fm_reference |
      | Check out 05224 | 05224: VOR 05224 v1 |
    And I add "elife_cover" with title "Check out 05224" to entityqueue "elife_cover"
    When I am on the homepage
    Then I should see the text "Check out 05224" in the "front_matter_cover" region
    And I follow "Check out 05224" in the "front_matter_cover" region
    And I should be on "content/4/e05224v1"
    And I should see "VOR 05224 v1" in the "h1" element

  Scenario: Sub-paths aren't accessible
    When I go to "/cover/foo"
    Then the response status code should be 404

  @api
  Scenario: Load cover item to homepage referencing a podcast
    Given "elife_podcast" content:
      | title |
      | Podcast 1 |
    And "elife_cover" content:
      | title | field_elife_fm_reference |
      | Podcast 1 | Podcast 1 |
    And I add "elife_cover" with title "Podcast 1" to entityqueue "elife_cover"
    When I am on the homepage
    Then I should see the text "Podcast 1" in the "front_matter_cover" region
    And I follow "Podcast 1" in the "front_matter_cover" region
    And I should be on "content/podcast-1"

  @api
  Scenario: Load front matter items to homepage
    Given "elife_podcast" content:
      | title |
      | Podcast 1 |
    And "elife_collection" content:
      | title |
      | Collection 1 |
    And there are articles:
      """
        [
          {
            "title": "VOR 05224",
            "version": "1",
            "doi": "10.7554/eLife.05224.1",
            "volume": "4",
            "elocation-id": "e05224",
            "article-id": "05224",
            "article-version-id": "05224.1",
            "pub-date": "1979-08-17",
            "path": "content/4/e05224",
            "article-type": "research-article",
            "status": "VOR",
            "publish": "1"
          },
          {
            "title": "VOR 05225",
            "version": "1",
            "doi": "10.7554/eLife.05225.1",
            "volume": "4",
            "elocation-id": "e05225",
            "article-id": "05225",
            "article-version-id": "05225.1",
            "pub-date": "1979-08-17",
            "path": "content/4/e05225",
            "article-type": "research-article",
            "status": "VOR",
            "publish": "1"
          },
          {
            "title": "VOR 05226",
            "version": "1",
            "doi": "10.7554/eLife.05226.1",
            "volume": "4",
            "elocation-id": "e05226",
            "article-id": "05226",
            "article-version-id": "05226.1",
            "pub-date": "1979-08-17",
            "path": "content/4/e05226",
            "article-type": "research-article",
            "status": "VOR",
            "publish": "1"
          },
          {
            "title": "VOR 05227",
            "version": "1",
            "doi": "10.7554/eLife.05227.1",
            "volume": "4",
            "elocation-id": "e05227",
            "article-id": "05227",
            "article-version-id": "05227.1",
            "pub-date": "1979-08-17",
            "path": "content/4/e05227",
            "article-type": "research-article",
            "status": "VOR",
            "publish": "1"
          }
        ]
      """
    And "elife_front_matter" content:
      | title | field_elife_fm_reference |
      | Check out 05224 | 05224: VOR 05224 |
      | Check out 05225 | 05225: VOR 05225 |
      | Check out 05226 | 05226: VOR 05226 |
      | Check out 05227 | 05227: VOR 05227 |
      | Podcast 1 | Podcast 1 |
      | Collection 1 | Collection 1 |
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
