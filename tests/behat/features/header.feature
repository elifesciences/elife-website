@api
Feature: Header
  As a something
  I want to something
  So I can something

  Background:
    Given there are articles:
      """
        [
          {
            "title": "VOR 05224",
            "version": 1,
            "doi": "10.7554/eLife.05224",
            "volume": 4,
            "elocation-id": "e05224",
            "article-id": "10.7554/eLife.05224",
            "article-version-id": "05224",
            "pub-date": "1979-08-17T00:00:00+00:00",
            "path": "content/4/e05224",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true,
            "categories": {
              "heading": [
                "Cell biology",
                "Computer science"
              ]
            }
          },
          {
            "title": "VOR 05225",
            "version": 1,
            "doi": "10.7554/eLife.05225",
            "volume": 4,
            "elocation-id": "e05225",
            "article-id": "10.7554/eLife.05225",
            "article-version-id": "05225",
            "pub-date": "1979-08-17T00:00:00+00:00",
            "path": "content/4/e05225",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true,
            "categories": {
              "heading": [
                "Cell biology"
              ]
            }
          }
        ]
      """

  Scenario: Menu contains subject areas
    When I go to the homepage
    Then I should see "Cell biology" in the ".header__list_secondary--category .header__list_secondary_item:nth-of-type(2)" element
    And I should see "Computer science" in the ".header__list_secondary--category .header__list_secondary_item:nth-of-type(3)" element

  Scenario: Menu contains subject areas
    When I go to the homepage
    And I follow "All categories"
    Then I should see "Major subject areas"
    And I should see "Cell biology"
    And I should see "Computer science"
