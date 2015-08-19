Feature: Collections
  In order to present compelling content
  As a feature editor
  I need to be able to be able to create collection pages

  @api
  Scenario: Create collection page for Algoriphagus
    Given there are articles:
      """
        [
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
            "publish": "1",
            "keywords": {
              "author-keywords": [
                "Algoriphagus"
              ]
            }
          },
          {
            "title": "VOR 05224 v2",
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
            "title": "VOR 05225 v1",
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
            "title": "VOR 05226 v1",
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
          }
        ]
      """
    When I am viewing an "elife_collection" content:
      | field_elife_c_keyword | Algoriphagus |
    Then I should see text matching "VOR 05224 v2"
    And I should see text matching "VOR 05225 v1"
    And I should not see text matching "VOR 05224 v1"
    And I should not see text matching "VOR 05226 v1"
