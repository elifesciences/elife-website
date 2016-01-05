@api
Feature: Article Search - Keywords
  In order to list articles with keywords
  As a user
  I need to be able to search the content using the keywords

  Background:
    Given there are articles:
    """
          [
            {
              "title": "Article 1 for Search test",
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
              "keywords": {
                "author-keywords": [
                  "Algoriphagus"
                ]
              }
            },
            {
              "title": "Article 2 for Search test",
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
              "keywords": {
                "author-keywords": [
                  "Algoriphagus"
                ]
              },
              "contributors": [
                {
                  "type": "author",
                  "id": "author-1",
                  "surname": "Surname",
                  "given-names": "First A"
                }
              ]
            },
            {
              "title": "Article 3 for Search test",
              "version": 1,
              "doi": "10.7554/eLife.05225.1",
              "volume": 4,
              "elocation-id": "e05225",
              "article-id": "05225",
              "article-version-id": "05225.1",
              "pub-date": "1979-08-17T00:00:00+00:00",
              "path": "content/4/e05225v1",
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
              "title": "Article 4 for Search test",
              "version": 1,
              "doi": "10.7554/eLife.05226.1",
              "volume": 4,
              "elocation-id": "e05226",
              "article-id": "05226",
              "article-version-id": "05226.1",
              "pub-date": "1979-08-17T00:00:00+00:00",
              "path": "content/4/e05226v1",
              "article-type": "research-article",
              "status": "VOR",
              "publish": true,
              "keywords": {
                "author-keywords": [
                  "bacterial sulfonolipid"
                ]
              }
            },
            {
              "title": "Article 5 for Search test",
              "version": 1,
              "doi": "10.7554/eLife.05614",
              "volume": 3,
              "elocation-id": "e05614",
              "article-id": "05614",
              "article-version-id": "05614",
              "pub-date": "1979-08-17T00:00:00+00:00",
              "path": "content/3/e05614",
              "article-type": "research-article",
              "status": "VOR",
              "publish": true,
              "keywords": {
              "author-keywords": [
                "early-career"
                        ]
                    }
            },
            {
              "title": "Article 6 for Search test",
              "version": 1,
              "doi": "10.7554/eLife.04901",
              "volume": 3,
              "elocation-id": "e04901",
              "article-id": "04901",
              "article-version-id": "04901",
              "pub-date": "1979-08-17T00:00:00+00:00",
              "path": "content/3/e04901",
              "article-type": "research-article",
              "status": "VOR",
              "publish": true,
              "keywords": {
              "author-keywords": [
                "early-career"
                  ]
                }
            },
            {
              "title": "Article 7 for Search test",
              "version": 1,
              "doi": "10.7554/eLife.01633",
              "volume": 2,
              "elocation-id": "e01633",
              "article-id": "01633",
              "article-version-id": "01633",
              "pub-date": "1979-08-17T00:00:00+00:00",
              "path": "content/2/e01633",
              "article-type": "research-article",
              "status": "VOR",
              "publish": true,
              "keywords": {
                "author-keywords": [
                  "early-career"
                ]
                }
            },
            {
              "title": "Article 8 for Search test",
              "version": 1,
              "doi": "10.7554/eLife.00477",
              "volume": 2,
              "elocation-id": "e00477",
              "article-id": "00477",
              "article-version-id": "00477",
              "pub-date": "1979-08-17T00:00:00+00:00",
              "path": "content/2/e00477",
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
    
  Scenario: Set keywords
    When the search index is updated
    Given I am on "/elife/search"
    Then the response status code should be 200
    And I should see "Browse articles" in the "h1.pane-title" element
    And I fill in "Search for..." with "Algoriphagus"
    And I press the Search button
    And I should see 2 ".article-teaser__title" elements
    And I should see "Article 2 for Search test"
    And I should see "Article 3 for Search test"
    And I should not see "Article 8 for Search test"
    And I should not see "Article 7 for Search test"

  Scenario: Contributor names are indexed
    Given the search index is updated
    When I go to "/elife/search"
    And I fill in "Search for..." with "surname"
    And I press the Search button
    Then I should see 1 ".article-teaser__title" elements
    And I should see "Article 2 for Search test"

  Scenario: No articles with searched keyword
    When the search index is updated
    Given I am on "/elife/search"
    Then the response status code should be 200
    And I should see "Browse articles" in the "h1.pane-title" element
    And I fill in "Search for..." with "Applw"
    And I press the Search button
    And I should see "Your search yielded no results."
    And I fill in "Search for..." with "££$%^&"
    And I press the Search button
    And I should not see an ".article-teaser__title" element
    And I should see "Your search yielded no results."

  Scenario: Filter search results on category
    Given there are articles:
    """
        [
          {
            "title": "VOR 04565",
            "version": 1,
            "doi": "10.7554/eLife.04565",
            "volume": 3,
            "elocation-id": "e04565",
            "article-id": "04565",
            "article-version-id": "04565",
            "pub-date": "2014-09-19T00:00:00+00:00",
            "path": "content/3/e04565",
            "article-type": "article-commentary",
            "status": "VOR",
            "publish": true,
            "keywords": {
              "author-keywords": [
                "Ebola"
              ]
            },
            "categories": {
              "display-channel": [
                "Insight"
              ]
            }
          },
          {
            "title": "VOR 04395",
            "version": 1,
            "doi": "10.7554/eLife.04395",
            "volume": 3,
            "elocation-id": "e04395",
            "article-id": "04395",
            "article-version-id": "04395",
            "pub-date": "2014-09-08T00:00:00+00:00",
            "path": "content/3/e04395",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true,
            "keywords": {
              "author-keywords": [
                "Ebola"
              ]
            },
            "categories": {
              "display-channel": [
                "Research article"
              ]
            }
          },
          {
            "title": "VOR 03908",
            "version": 1,
            "doi": "10.7554/eLife.03908",
            "volume": 3,
            "elocation-id": "e03908",
            "article-id": "03908",
            "article-version-id": "03908",
            "pub-date": "2014-09-12T00:00:00+00:00",
            "path": "content/3/e03908",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true,
            "keywords": {
              "author-keywords": [
                "Ebola",
                "bacterial sulfonolipid"
              ]
            },
            "categories": {
              "display-channel": [
                "Research article"
              ]
            }
          },
          {
            "title": "VOR 05564",
            "version": 1,
            "doi": "10.7554/eLife.05564",
            "volume": 4,
            "elocation-id": "e05564",
            "article-id": "05564",
            "article-version-id": "05564",
            "pub-date": "2015-02-19T00:00:00+00:00",
            "path": "content/4/e05564",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true,
            "keywords": {
              "author-keywords": [
              "bacterial sulfonolipid",
              "Ebola"
              ]
            },
            "categories": {
              "display-channel": [
                "Research article"
              ]
            }
          }
        ]
      """
    And the search index is updated
    Given I am on "/elife/search"
    Then the response status code should be 200
    And I should see "Browse articles" in the "h1.pane-title" element
    And I fill in "Search for..." with "Ebola"
    And I press the Search button
    And I should see " Showing results 1–4 of 4 " in the ".main-wrapper" element
    And I should see 4 ".article-teaser__title" elements
    And I should see "Filter by content type" in the ".sidebar-wrapper" element
    Then I should see " Apply Research article filter" in the ".sidebar-wrapper" element
    Then I click "Research article (3)"
    And I should see 3 ".article-teaser__title" elements
    Then I should see " Apply Insight filter" in the ".sidebar-wrapper" element
    Then I click "Insight (1)"
    And I should see 1 ".article-teaser__title" element
