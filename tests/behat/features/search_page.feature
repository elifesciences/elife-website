@api
Feature: Search
  In order to search articles posted in the journal
  As a website user
  I need a search link that redirects to search page

  Scenario: Display Search link on Home page
    Given I am on the homepage
    Then the response status code should be 200
    Then I should see "Search" in the ".header__list" element
    Then I should see the url "/elife/search" in the "href" attribute of the ".header__list li a.header__list_link.header__list_link--search" element
    When I click the ".header__list li a.header__list_link.header__list_link--search" element
    Then the url should match "/elife/search"

  Scenario: Sub-paths aren't accessible
    When I go to "/elife/search/foo"
    Then the response status code should be 404

  Scenario: Appropriate title and input box for the Search page
    Given I am on "/elife/search"
    Then the response status code should be 200
    And I should see "Browse articles" in the "h1.pane-title" element
    And I fill in "Search for..." with "Algoriphagus"
    And I press the Search button
    And I should see "Your search yielded no results."

  Scenario: Default Search page when the journal has no articles
    Given I am on "/elife/search"
    Then the response status code should be 200
    And I should not see an "div.view-content" element
    And I should see an ".view-empty" element
    And I should see "Your search yielded no results."

  Scenario: Default Search page has a default list of all articles of the eLife journal
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
            "keywords": {
              "author-keywords": [
                "Algoriphagus"
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
            "keywords": {
              "author-keywords": [
                "Algoriphagus"
              ]
            }
          },
          {
            "title": "VOR 05226",
            "version": 1,
            "doi": "10.7554/eLife.05226",
            "volume": 4,
            "elocation-id": "e05226",
            "article-id": "05226",
            "article-version-id": "05226",
            "pub-date": "1979-08-17T00:00:00+00:00",
            "path": "content/4/e05226",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true,
            "keywords": {
              "author-keywords": [
                "Algoriphagus",
                "bacterial sulfonolipid"
              ]
            }
          },
          {
            "title": "VOR 05229",
            "version": 1,
            "doi": "10.7554/eLife.05229",
            "volume": 4,
            "elocation-id": "e05229",
            "article-id": "05229",
            "article-version-id": "05229",
            "pub-date": "1979-08-17T00:00:00+00:00",
            "path": "content/4/e05229",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true,
            "keywords": {
              "author-keywords": [
                "bacterial sulfonolipid"
              ]
            }
          }
        ]
      """
    And the search index is updated
    Given I am on "/elife/search"
    Then the response status code should be 200
    And I should see an "div.view-content" element
    And I should see "VOR 05224"
    And I should see "VOR 05225"
    And I should see "VOR 05226"
    And I should see "VOR 05229"
    And I should see "Browse articles" in the "h1.pane-title" element
    And I fill in "Search for..." with "Algoriphagus"
    And I press the Search button
    And I should see "VOR 05224"
    And I should see "VOR 05225"
    And I should see "VOR 05226"
    And I should not see "VOR 05229"

  Scenario: Lens link for VOR articles
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
            "publish": true
          },
          {
            "title": "POA 05225",
            "version": 1,
            "doi": "10.7554/eLife.05225",
            "volume": 4,
            "elocation-id": "e05225",
            "article-id": "05225",
            "article-version-id": "05225",
            "pub-date": "1979-08-17T00:00:00+00:00",
            "path": "content/4/e05225",
            "article-type": "research-article",
            "status": "POA",
            "publish": true
          }
        ]
      """
    And the search index is updated
    Given I am on "/elife/search"
    Then the response status code should be 200
    And I should see "View in eLife Lens" in the ".article-teaser:contains('VOR 05224')" element
    And I should see the url "http://lens.elifesciences.org/05224/index.html" in the "href" attribute of the ".article-teaser:contains('VOR 05224') .article-teaser__lens_link a" element
    And I should not see "View in eLife Lens" in the ".article-teaser:contains('POA 05225')" element

  Scenario: Status text for POA articles
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
            "publish": true
          },
          {
            "title": "POA 05225",
            "version": 1,
            "doi": "10.7554/eLife.05225",
            "volume": 4,
            "elocation-id": "e05225",
            "article-id": "05225",
            "article-version-id": "05225",
            "pub-date": "1979-08-17T00:00:00+00:00",
            "path": "content/4/e05225",
            "article-type": "research-article",
            "status": "POA",
            "publish": true
          }
        ]
      """
    And the search index is updated
    Given I am on "/elife/search"
    Then the response status code should be 200
    And I should not see a ".article-teaser:contains('VOR 05224') .article-teaser__status_text" element
    And I should see "Accepted manuscript" in the ".article-teaser:contains('POA 05225') .article-teaser__status_text" element

  Scenario: Content types are ordered
    Given "elife_categories" terms:
      | field_elife_title | weight |
      | Bar               | 0      |
      | Foo               | 1      |
      | Baz               | 2      |
    And there are articles:
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
            "keywords": {
              "author-keywords": [
                "Algoriphagus"
              ]
            },
            "categories": {
              "display-channel": [
                "Foo"
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
            "keywords": {
              "author-keywords": [
                "Algoriphagus"
              ]
            },
            "categories": {
              "display-channel": [
                "Bar"
              ]
            }
          },
          {
            "title": "VOR 05226",
            "version": 1,
            "doi": "10.7554/eLife.05226",
            "volume": 4,
            "elocation-id": "e05226",
            "article-id": "05226",
            "article-version-id": "05226",
            "pub-date": "1979-08-17T00:00:00+00:00",
            "path": "content/4/e05226",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true,
            "keywords": {
              "author-keywords": [
                "Algoriphagus",
                "bacterial sulfonolipid"
              ]
            },
            "categories": {
              "display-channel": [
                "Foo"
              ]
            }
          },
          {
            "title": "VOR 05227",
            "version": 1,
            "doi": "10.7554/eLife.05227",
            "volume": 4,
            "elocation-id": "e05227",
            "article-id": "05227",
            "article-version-id": "05227",
            "pub-date": "1979-08-17T00:00:00+00:00",
            "path": "content/4/e05227",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true,
            "keywords": {
              "author-keywords": [
                "Algoriphagus",
                "bacterial sulfonolipid"
              ]
            },
            "categories": {
              "display-channel": [
                "Baz"
              ],
              "sub-display-channel": [
                "Qux"
              ]
            }
          }
        ]
      """
    And the search index is updated
    When I go to "/elife/search"
    Then I should see 3 ".sidebar-wrapper h2:contains('Filter by content type') + div li" elements
    And I should see "Bar (1)" in the ".sidebar-wrapper h2:contains('Filter by content type') + div li:nth-child(1)" element
    And I should see "Foo (2)" in the ".sidebar-wrapper h2:contains('Filter by content type') + div li:nth-child(2)" element
    And I should see "Baz (1)" in the ".sidebar-wrapper h2:contains('Filter by content type') + div li:nth-child(3)" element

  Scenario: Browse redirects
    When I go to "/browse"
    Then I should be on "/elife/search"
