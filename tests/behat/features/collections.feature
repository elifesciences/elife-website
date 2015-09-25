Feature: Collections
  In order to present compelling content
  As a feature editor
  I need to be able to be able to create collection pages

  @api
  Scenario: Create collection page
    Given there are articles:
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
            "path": "content/4/e05224v1",
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
            "path": "content/4/e05225v1",
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
            "path": "content/4/e05226v1",
            "article-type": "research-article",
            "status": "VOR",
            "publish": "1"
          }
        ]
      """
    When I am viewing an "elife_collection" content:
      | field_elife_c_articles | 05224: VOR 05224, 05225: VOR 05225 |
    Then I should see text matching "VOR 05224"
    And I should see text matching "VOR 05225"
    And I should not see text matching "VOR 05226"
