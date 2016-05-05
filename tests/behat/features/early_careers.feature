Feature: Navigate to editorial board
  In order to make it easier to navigate to our editorial board
  As a reader of the site
  I need easy navigation to the editorial board

  @javascript @api
  Scenario: Biographies are shown
    Given "elife_person_profile" content:
      | field_elife_pp_first_name | field_elife_pp_last_name | field_elife_pp_type          | field_elife_pp_profile     |
      | Foo                       | Bar                      | Early Careers Advisory Group | Lorem ipsum dolor sit amet |
    When I go to "/careers"
    And I click the ".person-profile__link:contains(Foo Bar)" element
    Then I should see "Lorem ipsum dolor sit amet" in the ".person-profile__biog" element

  @api
  Scenario: Other types of profiles are excluded
    Given "elife_person_profile" content:
      | field_elife_pp_first_name | field_elife_pp_last_name | field_elife_pp_type |
      | First Name 1              | Last Name 1              | Editor-in-Chief     |
      | First Name 2              | Last Name 2              | Deputy Editor       |
      | First Name 3              | Last Name 3              | Senior Editor       |
      | First Name 4              | Last Name 4              | Reviewing Editor    |
      | First Name 6              | Last Name 6              | Board of Directors  |
      | First Name 7              | Last Name 7              | Executive Staff     |
    When I go to "/careers"
    Then I should not see a ".ec-profiles__people" element

  Scenario: No spotlights
    When I go to "/careers"
    Then I should not see a ".ec-section--latest" element

  @api
  Scenario: Article spotlights
    Given there are articles:
      """
        [
          {
            "title": "VOR 05224",
            "version": 1,
            "doi": "10.7554/eLife.05224",
            "volume": 4,
            "elocation-id": "e05224",
            "article-id": "05224",
            "article-version-id": "05224",
            "pub-date": "1979-08-17T00:00:00+00:00",
            "path": "content/4/e05224",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true,
            "categories": {
              "display-channel": [
                "Channel 1"
              ]
            }
          },
          {
            "title": "VOR 05225",
            "version": 2,
            "doi": "10.7554/eLife.05225",
            "volume": 4,
            "elocation-id": "e05225",
            "article-id": "05225",
            "article-version-id": "05225",
            "pub-date": "1979-08-17T00:00:00+00:00",
            "path": "content/4/e05225",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true,
            "categories": {
              "display-channel": [
                "Channel 2"
              ]
            }
          }
        ]
      """
    And "elife_early_careers_spotlight" content:
      | field_elife_title | field_elife_s_reference | field_elife_s_text |
      | VOR 05224         | 05224: VOR 05224        | Foo bar.           |
      | VOR 05225         | 05225: VOR 05225        | Baz qux.           |
    When I go to "/careers"
    Then I should see 2 ".ec-section--latest__item" elements
    And I should see "Channel 1" in the ".ec-section--latest__item:nth-of-type(1) .ec-section__heading" element
    And I should see "VOR 05224" in the ".ec-section--latest__item:nth-of-type(1) .ec-section--latest__item-title" element
    And I should see "Foo bar." in the ".ec-section--latest__item:nth-of-type(1) .ec-section--latest__item-text" element
    And I should see "Channel 2" in the ".ec-section--latest__item:nth-of-type(2) .ec-section__heading" element
    And I should see "VOR 05225" in the ".ec-section--latest__item:nth-of-type(2) .ec-section--latest__item-title" element
    And I should see "Baz qux." in the ".ec-section--latest__item:nth-of-type(2) .ec-section--latest__item-text" element
    And I should not see a ".ec-section--latest__more-link" element

  @api
  Scenario: Article links to the most recent version
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
            "pub-date": "1979-08-17T00:00:00+00:00",
            "path": "content/4/e05224v1",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true,
            "categories": {
              "display-channel": [
                "Channel 1"
              ]
            }
          },
          {
            "title": "VOR 05224",
            "version": 2,
            "doi": "10.7554/eLife.05224.2",
            "volume": 4,
            "elocation-id": "e05224",
            "article-id": "05224",
            "article-version-id": "05224.2",
            "pub-date": "1979-08-17T00:00:00+00:00",
            "path": "content/4/e05224v2",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true,
            "categories": {
              "display-channel": [
                "Channel 2"
              ]
            }
          }
        ]
      """
    And "elife_early_careers_spotlight" content:
      | field_elife_title | field_elife_s_reference |
      | VOR 05224         | 05224: VOR 05224        |
    When I go to "/careers"
    And I follow "VOR 05224"
    Then I should be on "/content/4/e05224"

  @api
  Scenario: Collection spotlight
    Given "elife_collection" content:
      | field_elife_c_title | field_elife_c_sub_title |
      | Foo                 | Bar                     |
    And "elife_early_careers_spotlight" content:
      | field_elife_title | field_elife_s_reference |
      | Baz Qux           | Foo: Bar                |
    When I go to "/careers"
    Then I should see "Collections" in the ".ec-section--latest__item .ec-section__heading" element
    And I should see "Baz Qux" in the ".ec-section--latest__item .ec-section--latest__item-title" element
    And I should see "View more collections" in the ".ec-section--latest__item .ec-section--latest__more-link" element
    When I follow "Baz Qux"
    Then I should be on "/collections/foo"

  @api
  Scenario: Interview spotlight
    Given "elife_i_series" terms:
      | field_elife_is_title | name   |
      | Series               | Series |
    And "elife_early_careers_interview" content:
      | field_elife_i_first_name | field_elife_i_last_name | field_elife_i_title | field_elife_i_series |
      | Foo                      | Bar                     | Baz <i>Qux</i>      | Series               |
    And "elife_early_careers_spotlight" content:
      | field_elife_title | field_elife_s_reference            |
      | One Two           | Baz Qux: an interview with Foo Bar |
    When I go to "/careers"
    Then I should see "Interviews" in the ".ec-section--latest__item .ec-section__heading" element
    And I should see "One Two" in the ".ec-section--latest__item .ec-section--latest__item-title" element
    And I should see "View more interviews" in the ".ec-section--latest__item .ec-section--latest__more-link" element
    When I follow "One Two"
    Then I should be on "/interviews/series/foo-bar"
    When I move backward one page
    And I follow "View more interviews"
    Then I should be on "/interviews/series"

  @api
  Scenario: Event spotlight
    Given "elife_event" content:
      | field_elife_title | field_elife_e_date  |
      | Foo               | 2000-01-01T00:00:00 |
    And "elife_early_careers_spotlight" content:
      | field_elife_title | field_elife_s_reference |
      | Bar               | Foo                     |
    When I go to "/careers"
    Then I should see "Events" in the ".ec-section--latest__item .ec-section__heading" element
    And I should see "Bar" in the ".ec-section--latest__item .ec-section--latest__item-title" element
    And I should see "View more events" in the ".ec-section--latest__item .ec-section--latest__more-link" element
    When I follow "Bar"
    Then I should be on "/events/foo"

  @api
  Scenario: News article spotlight
    Given "elife_news_article" content:
      | field_elife_title |
      | Foo               |
    And "elife_early_careers_spotlight" content:
      | field_elife_title | field_elife_s_reference |
      | Bar               | Foo                     |
    When I go to "/careers"
    Then I should see "News" in the ".ec-section--latest__item .ec-section__heading" element
    And I should see "Bar" in the ".ec-section--latest__item .ec-section--latest__item-title" element
    And I should see "View more news" in the ".ec-section--latest__item .ec-section--latest__more-link" element
    When I follow "Bar"
    Then I should be on "/elife-news/foo"

  @api
  Scenario: Podcast spotlight
    Given "elife_podcast" content:
      | field_elife_p_episode_number | field_elife_p_title |
      | 1                            | Foo                 |
    And "elife_early_careers_spotlight" content:
      | field_elife_title | field_elife_s_reference |
      | Bar               | Episode 1: Foo          |
    When I go to "/careers"
    Then I should see "Podcasts" in the ".ec-section--latest__item .ec-section__heading" element
    And I should see "Bar" in the ".ec-section--latest__item .ec-section--latest__item-title" element
    And I should see "View more podcasts" in the ".ec-section--latest__item .ec-section--latest__more-link" element
    When I follow "Bar"
    Then I should be on "/podcast/episode1"
