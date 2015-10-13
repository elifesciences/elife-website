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
              "publish": "1",
              "keywords": {
                "author-keywords": [
                  "Algoriphagus"
                ]
              }
            },
            {
              "title": "Article 2 for Search test",
              "version": "2",
              "doi": "10.7554/eLife.05224.2",
              "volume": "4",
              "elocation-id": "e05224",
              "article-id": "05224",
              "article-version-id": "05224.2",
              "pub-date": "1979-08-17",
              "path": "content/4/e05224v2",
              "article-type": "research-article",
              "status": "VOR",
              "publish": "1",
              "keywords": {
                "author-keywords": [
                  "Algoriphagus"
                ]
              }
            },
            {
              "title": "Article 3 for Search test",
              "version": "1",
              "doi": "10.7554/eLife.05225.1",
              "volume": "4",
              "elocation-id": "e05225",
              "article-id": "05225",
              "article-version-id": "05225.1",
              "pub-date": "1979-08-17",
              "path": "content/4/e05225v1",
              "article-type": "research-article",
              "status": "VOR",
              "publish": "1",
              "keywords": {
                "author-keywords": [
                  "Algoriphagus",
                  "bacterial sulfonolipid"
                ]
              }
            },
            {
              "title": "Article 4 for Search test",
              "version": "1",
              "doi": "10.7554/eLife.05226.1",
              "volume": "4",
              "elocation-id": "e05226",
              "article-id": "05226",
              "article-version-id": "05226.1",
              "pub-date": "1979-08-17",
              "path": "content/4/e05226v1",
              "article-type": "research-article",
              "status": "VOR",
              "publish": "1",
              "keywords": {
                "author-keywords": [
                  "bacterial sulfonolipid"
                ]
              }
            },
            {
              "title": "Article 5 for Search test",
              "version": "1",
              "doi": "10.7554/eLife.05614",
              "volume": "3",
              "elocation-id": "e05614",
              "article-id": "05614",
              "article-version-id": "05614",
              "pub-date": "1979-08-17",
              "path": "content/3/e05614",
              "article-type": "research-article",
              "status": "VOR",
              "publish": "1",
              "keywords": {
              "author-keywords": [
                "early-career"
                        ]
                    }
            },
            {
              "title": "Article 6 for Search test",
              "version": "1",
              "doi": "10.7554/eLife.04901",
              "volume": "3",
              "elocation-id": "e04901",
              "article-id": "04901",
              "article-version-id": "04901",
              "pub-date": "1979-08-17",
              "path": "content/3/e04901",
              "article-type": "research-article",
              "status": "VOR",
              "publish": "1",
              "keywords": {
              "author-keywords": [
                "early-career"
                  ]
                }
            },
            {
              "title": "Article 7 for Search test",
              "version": "1",
              "doi": "10.7554/eLife.01633",
              "volume": "2",
              "elocation-id": "e01633",
              "article-id": "01633",
              "article-version-id": "01633",
              "pub-date": "1979-08-17",
              "path": "content/2/e01633",
              "article-type": "research-article",
              "status": "VOR",
              "publish": "1",
              "keywords": {
                "author-keywords": [
                  "early-career"
                ]
                }
            },
            {
              "title": "Article 8 for Search test",
              "version": "1",
              "doi": "10.7554/eLife.00477",
              "volume": "2",
              "elocation-id": "e00477",
              "article-id": "00477",
              "article-version-id": "00477",
              "pub-date": "1979-08-17",
              "path": "content/2/e00477",
              "article-type": "research-article",
              "status": "VOR",
              "publish": "1",
              "keywords": {
              "author-keywords": [
                "bacterial sulfonolipid"
                ]
              }
            }
          ]
     """

  Scenario: Set keywords
    When I run cron
    Given I am on "/elife/search"
    Then the response status code should be 200
    And I should see "Browse articles" in the "h1.pane-title" element
    And I fill in "Keyword" with "Algoriphagus"
    And I press the Search button
    And I should see 2 ".article-teaser__title" elements

  Scenario: No articles with searched keyword
    Given I am on "/elife/search"
    And I run cron
    Then the response status code should be 200
    And I should see "Browse articles" in the "h1.pane-title" element
    And I fill in "Keyword" with "Applw"
    And I click Search
    And I should not see an ".article-teaser__title" element
    And I fill in "Keyword" with "££$%^&"
    And I click Search
    And I should not see an ".article-teaser__title" element
    And I should see "Your search yielded no results."
    