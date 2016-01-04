@api
Feature: Front Matter
  As a website editor
  I want to maintain the cover page front matter section
  So I can draw attention to the latest content

  Scenario: Load cover item to homepage referencing an article
    Given there is an article:
      """
        {
          "title": "VOR 05224 v1",
          "version": 1,
          "doi": "10.7554/eLife.05224.1",
          "volume": 4,
          "elocation-id": "e05224",
          "article-id": "05224",
          "article-version-id": "05224.1",
          "pub-date": "1979-08-17T00:00:00+00:00",
          "path": "content/4/e05224v1",
          "article-type": "research-article",
          "status": "VOR",
          "publish": true
        }
      """
    And "elife_cover" content:
      | field_elife_title      | field_elife_fm_reference |
      | Check out <i>05224</i> | 05224: VOR 05224 v1      |
    And I add "elife_cover" with title "Check out 05224" to entityqueue "elife_cover"
    When I am on the homepage
    Then I should see the text "Check out 05224" in the "front_matter_cover" region
    And I should see "05224" in the ".headline-first__title_link i" element
    And I follow "Check out 05224" in the "front_matter_cover" region
    And I should be on "content/4/e05224v1"
    And I should see "VOR 05224 v1" in the "h1" element

  Scenario: Sub-paths aren't accessible
    When I go to "/cover/foo"
    Then the response status code should be 404

  Scenario: Load cover item to homepage referencing a podcast
    Given "elife_podcast" content:
      | field_elife_p_episode_number | field_elife_p_title |
      | 1                            | Podcast 1           |
    And "elife_cover" content:
      | field_elife_title | field_elife_fm_reference |
      | Podcast 1         | Episode 1: Podcast 1     |
    And I add "elife_cover" with title "Podcast 1" to entityqueue "elife_cover"
    When I am on the homepage
    Then I should see the text "Podcast 1" in the "front_matter_cover" region
    And I follow "Podcast 1" in the "front_matter_cover" region
    And I should be on "podcast/episode1"

  Scenario: Load front matter items to homepage
    Given "elife_podcast" content:
      | field_elife_p_episode_number | field_elife_p_title |
      | 1                            | Podcast 1           |
    And "elife_collection" content:
      | field_elife_c_title |
      | Collection 1        |
    And there are articles:
      """
        [
          {
            "title": "VOR 05224",
            "version": 1,
            "doi": "10.7554/eLife.05224.1",
            "volume": 4,
            "elocation-id": "e05224",
            "article-id": "05224",
            "article-version-id": "05224.1",
            "pub-date": "1979-08-17T00:00:00+00:00",
            "path": "content/4/e05224",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true
          },
          {
            "title": "VOR 05225",
            "version": 1,
            "doi": "10.7554/eLife.05225.1",
            "volume": 4,
            "elocation-id": "e05225",
            "article-id": "05225",
            "article-version-id": "05225.1",
            "pub-date": "1979-08-17T00:00:00+00:00",
            "path": "content/4/e05225",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true
          },
          {
            "title": "VOR 05226",
            "version": 1,
            "doi": "10.7554/eLife.05226.1",
            "volume": 4,
            "elocation-id": "e05226",
            "article-id": "05226",
            "article-version-id": "05226.1",
            "pub-date": "1979-08-17T00:00:00+00:00",
            "path": "content/4/e05226",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true
          },
          {
            "title": "VOR 05227",
            "version": 1,
            "doi": "10.7554/eLife.05227.1",
            "volume": 4,
            "elocation-id": "e05227",
            "article-id": "05227",
            "article-version-id": "05227.1",
            "pub-date": "1979-08-17T00:00:00+00:00",
            "path": "content/4/e05227",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true
          }
        ]
      """
    And "elife_front_matter" content:
      | field_elife_title      | field_elife_fm_reference |
      | Check out <i>05224</i> | 05224: VOR 05224         |
      | Check out 05225        | 05225: VOR 05225         |
      | Check out 05226        | 05226: VOR 05226         |
      | Check out 05227        | 05227: VOR 05227         |
      | Podcast 1              | Episode 1: Podcast 1     |
      | Collection 1           | Collection 1             |
    And "elife_cover" content:
      | field_elife_title | field_elife_fm_reference |
      | Check out 05224   | 05224: VOR 05224         |
    And I add "elife_front_matter" with title "Check out 05224" to entityqueue "elife_front_matter_col_1"
    And I add "elife_front_matter" with title "Check out 05225" to entityqueue "elife_front_matter_col_1"
    And I add "elife_front_matter" with title "Podcast 1" to entityqueue "elife_front_matter_col_1"
    And I add "elife_front_matter" with title "Check out 05226" to entityqueue "elife_front_matter_col_2"
    And I add "elife_front_matter" with title "Check out 05227" to entityqueue "elife_front_matter_col_2"
    And I add "elife_front_matter" with title "Collection 1" to entityqueue "elife_front_matter_col_2"
    And I add "elife_cover" with title "Check out 05224" to entityqueue "elife_cover"
    When I am on the homepage
    Then I should see the text "Check out 05224" in the "front_matter_col_1" region
    And I should see "05224" in the ".headlines-secondary__item_title i" element
    And I should see the text "Check out 05225" in the "front_matter_col_1" region
    And I should see the text "Podcast 1" in the "front_matter_col_1" region
    And I should see the text "Check out 05226" in the "front_matter_col_2" region
    And I should see the text "Check out 05227" in the "front_matter_col_2" region
    And I should see the text "Collection 1" in the "front_matter_col_2" region
    And I follow "Check out 05226" in the "front_matter_col_2" region
    And I should be on "content/4/e05226"
    And I should see "VOR 05226" in the "h1" element

  Scenario: Latest research list on the homepage
    Given there are articles:
      """
        [
          {
            "title": "VOR 05224",
            "version": 1,
            "doi": "10.7554/eLife.05224.1",
            "volume": 4,
            "elocation-id": "e05224",
            "article-id": "05224",
            "article-version-id": "05224.1",
            "pub-date": "2000-01-01T00:00:00+00:00",
            "path": "content/4/e05224",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true,
            "categories": {
              "display-channel": [
                "Research article"
              ]
            }
          },
          {
            "title": "VOR <italic>05225</italic>",
            "version": 1,
            "doi": "10.7554/eLife.05225.1",
            "volume": 4,
            "elocation-id": "e05225",
            "article-id": "05225",
            "article-version-id": "05225.1",
            "pub-date": "2001-01-01T00:00:00+00:00",
            "path": "content/4/e05225",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true,
            "categories": {
              "display-channel": [
                "Research article"
              ]
            }
          },
          {
            "title": "VOR 05226",
            "version": 1,
            "doi": "10.7554/eLife.05226.1",
            "volume": 4,
            "elocation-id": "e05226",
            "article-id": "05226",
            "article-version-id": "05226.1",
            "pub-date": "1999-01-01T00:00:00+00:00",
            "path": "content/4/e05226",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true,
            "categories": {
              "display-channel": [
                "Research article"
              ]
            }
          },
          {
            "title": "VOR 05227",
            "version": 1,
            "doi": "10.7554/eLife.05227.1",
            "volume": 4,
            "elocation-id": "e05227",
            "article-id": "05227",
            "article-version-id": "05227.1",
            "pub-date": "2000-01-01T00:00:00+00:00",
            "path": "content/4/e05227",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true,
            "categories": {
              "display-channel": [
                "Something else"
              ]
            }
          }
        ]
      """
    When I go to the homepage
    Then I should see "VOR 05225" in the ".home-article-listing__list-item:nth-child(1)" element
    And I should see "05225" in the ".home-article-listing__list-item:nth-child(1) i" element
    Then I should see "VOR 05224" in the ".home-article-listing__list-item:nth-child(2)" element
    Then I should see "VOR 05226" in the ".home-article-listing__list-item:nth-child(3)" element

  Scenario: Updated date is not shown when it's the same as the publish date
    Given there is an article:
      """
        {
          "title": "VOR 05224v1",
          "version": 1,
          "doi": "10.7554/eLife.05224.1",
          "volume": 4,
          "elocation-id": "e05224",
          "article-id": "05224",
          "article-version-id": "05224.1",
          "pub-date": "2000-01-01T00:00:00+00:00",
          "update": "2000-01-01T00:00:00+00:00",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "VOR",
          "publish": true,
          "categories": {
            "display-channel": [
              "Research article"
            ]
          }
        }
      """
    When I go to the homepage
    Then I should see "Published on January 1, 2000" in the ".home-article-listing__list-item" element
    And I should not see "Updated on" in the ".home-article-listing__list-item" element

  Scenario: Updated data is shown when it's different to the publish date
    Given there is an article:
      """
        {
          "title": "VOR 05224v1",
          "version": 1,
          "doi": "10.7554/eLife.05224.1",
          "volume": 4,
          "elocation-id": "e05224",
          "article-id": "05224",
          "article-version-id": "05224.1",
          "pub-date": "2000-01-01T00:00:00+00:00",
          "update": "2001-01-01T00:00:00+00:00",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "VOR",
          "publish": true,
          "categories": {
            "display-channel": [
              "Research article"
            ]
          }
        }
      """
    When I go to the homepage
    Then I should see "Published on January 1, 2000" in the ".home-article-listing__list-item" element
    And I should see "Updated on January 1, 2001" in the ".home-article-listing__list-item" element

  Scenario: Unpublished covers don't appear when their referenced content isn't published
    Given "elife_podcast" content:
      | field_elife_p_episode_number | field_elife_p_title | status |
      | 1                            | Podcast 1           | 0      |
    And "elife_cover" content:
      | field_elife_title | field_elife_fm_reference |
      | Cover             | Episode 1: Podcast 1     |
    And I add "elife_cover" with title "Cover" to entityqueue "elife_cover"
    When I go to the homepage
    Then I should not see the "front_matter_cover" region

  Scenario: Unpublished front matters don't appear when their referenced content isn't published
    Given "elife_podcast" content:
      | field_elife_p_episode_number | field_elife_p_title | status |
      | 1                            | Podcast 1           | 1      |
      | 2                            | Podcast 2           | 0      |
    And "elife_cover" content:
      | field_elife_title | field_elife_fm_reference |
      | Cover             | Episode 1: Podcast 1     |
    And "elife_front_matter" content:
      | field_elife_title | field_elife_fm_reference |
      | Front Matter      | Episode 2: Podcast 2     |
    And I add "elife_cover" with title "Cover" to entityqueue "elife_cover"
    And I add "elife_front_matter" with title "Front Matter" to entityqueue "elife_front_matter_col_1"
    When I go to the homepage
    Then I should see the text "Cover" in the "front_matter_cover" region
    And I should not see the "front_matter_col_1" region

  Scenario: Deleting items removes covers/front matters
    Given "elife_podcast" content:
      | field_elife_p_episode_number | field_elife_p_title |
      | 1                            | Podcast 1           |
    And "elife_cover" content:
      | field_elife_title | field_elife_fm_reference |
      | Cover             | Episode 1: Podcast 1     |
    And "elife_front_matter" content:
      | field_elife_title | field_elife_fm_reference |
      | Front Matter      | Episode 1: Podcast 1     |
    And I add "elife_cover" with title "Cover" to entityqueue "elife_cover"
    And I add "elife_front_matter" with title "Front Matter" to entityqueue "elife_front_matter_col_1"
    When I go to the homepage
    Then I should see the text "Cover" in the "front_matter_cover" region
    And I should see the text "Front Matter" in the "front_matter_col_1" region
    When I delete the "elife_podcast" with title "Episode 1: Podcast 1"
    And I go to the homepage
    Then I should not see the "front_matter_cover" region
    And I should not see the "front_matter_col_1" region
