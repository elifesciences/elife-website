@api
Feature: Collections
  In order to present compelling content
  As a feature editor
  I need to be able to be able to create collection pages

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

  Scenario: Collection of collections page
    Given I am logged in as a user with the "eLife Editor" permission
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
    Given there are articles:
    """
      [
        {
          "title": "VOR 05614",
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
          "title": "VOR 04901",
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
          "title": "VOR 01633",
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
          "title": "VOR 0477",
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
    When I am viewing an "elife_collection" content:
      | field_elife_c_keyword | early-career |
    Given I am on the homepage
    Then I click Menu
    And I select "COLLECTIONS" from "MENU"
    Then I should be on "/elife/collections"
    Then I should see an "elife-collection__content" element
    Then I should see 2 ".collection-teaser__title" element
    Then I should see 2 ".view-content li:nth-of-type(<n>) .node-elife-collection" element
    Then I should see 2 " img.collection-teaser__image" element


  Scenario: Collections pages created by a user logged in as an eLife Editor
    Given I am logged in as a user with the "eLife Editor" permission
    Given I am on the homepage
    And I click "Content"
    And I click "Add Content"
    And I click "eLife: Collection"
    Then I should see "Create eLife: Collection" in the ".zone-wrapper" element
    Then I should see "Title" in the ".label-wrapper" element
    And I fill in "Title" with "Open Science"
    Then I typed "Dh" in the "Curators" field and chose 1 option from autocomplete variants
    And I click the "#field-elife-c-curators-add-more-wrapper--5 .field-add-more-submit" element
    And I fill in "Title" with "Open Science"
    Then I typed "Mu" in the "Curators" field and chose 3 option from autocomplete variants
    Then I should see "Articles" in the ".field-elife-c-articles-values" element


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