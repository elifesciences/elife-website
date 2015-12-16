@api
Feature: Podcast
  As a website user
  I want to easily find the latest podcast
  So I can review the latest research when I am away from my computer

  Scenario: Podcast contains chapters
    Given there is an article:
      """
        {
          "title": "VOR 05224",
          "version": "1",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "elocation-id": "e05224",
          "article-id": "05224",
          "article-version-id": "05224.1",
          "pub-date": "1979-08-17",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1"
        }
      """
    And "elife_podcast_chapter" content:
      | field_elife_pc_title | field_elife_pc_text | field_elife_pc_text_inverse | field_elife_pc_subject |
      | Chapter <i>One</i>   | Foo bar.            | Baz Qux                     | 05224: VOR 05224       |
    When I am viewing a "elife_podcast" content:
      | field_elife_p_episode_number | 1                             |
      | field_elife_p_title          | <i>Podcast</i> One            |
      | field_elife_p_chapters       | Episode  Chapter: Chapter One |
    Then I should see "Podcast One" in the ".hero-block__title" element
    Then I should see "Podcast" in the ".hero-block__title i" element
    And I should see "Episode 1" in the ".hero-block__sub_title" element
    And I should see "Chapter One" in the ".pane-node-field-elife-p-chapters" element
    And I should see "One" in the ".pane-node-field-elife-p-chapters i" element

  Scenario: Podcast can autoplay
    Given "elife_podcast" content:
      | field_elife_p_episode_number | field_elife_p_title | field_elife_p_url                              |
      | 1                            | Podcast One         | Fake Title - http://localhost/path/to/some.mp3 |
    When I go to "/podcast/episode1?autoplay=1"
    Then the ".player__player" element should have the "autoplay" attribute

  Scenario: List of podcasts
    Given "elife_podcast" content:
      | field_elife_p_episode_number | field_elife_p_title  |
      | 1                            | Podcast One          |
      | 3                            | Podcast <i>Three</i> |
      | 2                            | Podcast Two          |
    When I go to "/podcast"
    Then I should see "Episode 3: Podcast Three" in the ".view-elife-podcasts ol > li:nth-child(1)" element
    And I should see "Three" in the ".view-elife-podcasts ol > li:nth-child(1) i" element
    And I should see "Episode 2: Podcast Two" in the ".view-elife-podcasts ol > li:nth-child(2)" element
    And I should see "Episode 1: Podcast One" in the ".view-elife-podcasts ol > li:nth-child(3)" element

  Scenario: Sub-paths aren't accessible
    When I go to "/podcast/foo"
    Then the response status code should be 404

  Scenario: Podcast action links
    Given "elife_podcast" content:
      | field_elife_p_episode_number | field_elife_p_title | field_elife_p_url                              |
      | 1                            | Podcast One         | Fake Title - http://localhost/path/to/some.mp3 |
    When I go to "/podcast"
    Then I should see the url "/podcast/episode1?autoplay=1" in the "href" attribute of the "a:contains('Listen')" element
    And I should see the url "http://localhost/path/to/some.mp3" in the "href" attribute of the "a:contains('Download')" element
    And the "a:contains('Download')" element should have the "download" attribute
    And I should see the url "http://www.thenakedscientists.com/rss/eLife_podcast.xml" in the "href" attribute of the "a:contains('Subscribe')" element

  Scenario: Article page lists chapters
    Given there is an article:
      """
        {
          "title": "VOR 05224",
          "version": "1",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "elocation-id": "e05224",
          "article-id": "05224",
          "article-version-id": "05224.1",
          "pub-date": "1979-08-17",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1"
        }
      """
    And "elife_podcast_chapter" content:
      | field_elife_pc_title | field_elife_pc_text | field_elife_pc_text_inverse | field_elife_pc_subject |
      | Chapter One          | One Two             | Three <i>Four</i>           | 05224: VOR 05224       |
    And "elife_podcast" content:
      | field_elife_p_episode_number | field_elife_p_title | field_elife_p_chapters        |
      | 1                            | Podcast One         | Episode  Chapter: Chapter One |
    When I go to "/content/4/e05224"
    Then I should see "Multimedia" in the ".pane-elife-subject-podcasts-panel-pane-1 .pane-title" element
    And I should see "Three Four" in the ".podcast-teaser" element
    And I should see "Four" in the ".podcast-teaser i" element
    When I click "Three Four"
    Then I should be on "/podcast/episode1"

  Scenario: Article page doesn't list chapters when there's no text
    Given there is an article:
      """
        {
          "title": "VOR 05224",
          "version": "1",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "elocation-id": "e05224",
          "article-id": "05224",
          "article-version-id": "05224.1",
          "pub-date": "1979-08-17",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1"
        }
      """
    And "elife_podcast_chapter" content:
      | field_elife_pc_title | field_elife_pc_text | field_elife_pc_text_inverse | field_elife_pc_subject |
      | Chapter One          | One Two             |                             | 05224: VOR 05224       |
    And "elife_podcast" content:
      | field_elife_p_episode_number | field_elife_p_title | field_elife_p_chapters        |
      | 1                            | Podcast One         | Episode  Chapter: Chapter One |
    When I go to "/content/4/e05224"
    Then I should not see "Multimedia"
