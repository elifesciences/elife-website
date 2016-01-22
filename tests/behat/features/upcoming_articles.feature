@api
Feature: Upcoming articles
  As a something
  I want to something
  So I can something

  Scenario: No upcoming articles
    When I visit "/upcoming"
    Then I should see "Upcoming" in the "h1" element
    And I should see "There are currently no upcoming articles." in the ".content" element

  Scenario: Sub-paths aren't accessible
    When I go to "/upcoming/foo"
    Then the response status code should be 404

  Scenario: Shows upcoming articles
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
            "publish": true
          },
          {
            "title": "POA <italic>05225</italic>",
            "version": 1,
            "doi": "10.7554/eLife.05225.1",
            "volume": 4,
            "elocation-id": "e05225",
            "article-id": "05225",
            "article-version-id": "05225.1",
            "pub-date": "2000-01-01T00:00:00+00:00",
            "path": "content/4/e05225",
            "article-type": "research-article",
            "status": "POA",
            "publish": true
          },
          {
            "title": "POA 05226",
            "version": 1,
            "doi": "10.7554/eLife.05226.1",
            "volume": 4,
            "elocation-id": "e05226",
            "article-id": "05226",
            "article-version-id": "05226.1",
            "pub-date": "1999-01-01T00:00:00+00:00",
            "path": "content/4/e05226",
            "article-type": "research-article",
            "status": "POA",
            "publish": true
          },
          {
            "title": "POA 05227",
            "version": 1,
            "doi": "10.7554/eLife.05227.1",
            "volume": 4,
            "elocation-id": "e05227",
            "article-id": "05227",
            "article-version-id": "05227.1",
            "pub-date": "2000-01-01T20:00:00+00:00",
            "path": "content/4/e05227",
            "article-type": "research-article",
            "status": "POA",
            "publish": true
          }
        ]
      """
    When I go to "/upcoming"
    Then I should see 3 ".article-teaser" elements
    And I should see 2 ".view-content h3" elements
    And I should see "January 01, 2000" in the ".view-content h3:nth-of-type(1)" element
    And I should see "POA 05227" in the ".view-content h3:nth-of-type(1) + div" element
    And I should see "POA 05225" in the ".view-content h3:nth-of-type(1) + div + div" element
    And I should see "05225" in the ".view-content h3:nth-of-type(1) + div + div i" element
    And I should see "January 01, 1999" in the ".view-content h3:nth-of-type(2)" element
    And I should see "POA 05226" in the ".view-content h3:nth-of-type(2) + div" element
    And I should not see "VOR 05224"
