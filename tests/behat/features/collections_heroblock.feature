@api
Feature: In order to represent 'Collections'
    I can create a Heroblock to present content matter and related images for collections page

  Background:
    Given there are articles:
    """
          [
            {
              "title": "Article 1 for Collections test",
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
              "title": "Article 2 for Collections test",
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
              "title": "Article 3 for Collections test",
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
              "title": "Article 4 for Collections test",
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
              "title": "Article 5 for Collections test",
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
              "title": "Article 6 for Collections test",
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
              "title": "Article 7 for Collections test",
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
              "title": "Article 8 for Collections test",
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

  Scenario: Creating and verifying Heroblock only
    Given I am logged in as a user with the "access administration menu,access content,create elife_hero_block content,bypass rh_node" permissions
    And I am on "/node/add/elife-hero-block"
    Then I should see "Create eLife Hero Block"
    Then I fill in "Title" with "Hero block - Algoriphagus"
    Then I fill in "edit-field-elife-h-sub-title-und-0-value" with "Sub-title for Algoriphagus"
    Then I fill in "Appears on" with "collections/algoriphagus"
    When I attach the file "test.jpg" to "edit-field-elife-h-image-und-0-upload"
    Then I select the radio button "Dark" with the id "edit-field-elife-h-image-colour-und-dark"
    And I press "Save"
    And I should see "Hero block - Algoriphagus"
    And I should see "Sub-title for Algoriphagus"
    And I am on "/collections/algoriphagus"
    And I should see "Hero block - Algoriphagus"
    And I should see "Sub-title for Algoriphagus"

  Scenario: Verify Heroblock on a collections page
    Given I am logged in as a user with the "access administration menu,access content,create elife_hero_block content" permissions
    When "elife_person_profile" content:
      | field_elife_p_first_name | field_elife_p_last_name | field_elife_p_type |
      | FName                    | LName                   | Executive Staff    |
    When "elife_collection" content:
      | title        | field_elife_c_articles                                                       | field_elife_c_curators               |
      | Algoriphagus | 05224: Article 2 for Collections test, 05225: Article 3 for Collections test | FirstName LastName (Executive Staff) |
    And I am on "/node/add/elife-hero-block"
    Then I should see "Create eLife Hero Block"
    Then I fill in "Title" with "Hero block - Algoriphagus"
    Then I fill in "edit-field-elife-h-sub-title-und-0-value" with "Sub-title for Algoriphagus"
    Then I fill in "Appears on" with "collections/algoriphagus"
    When I attach the file "test.jpg" to "edit-field-elife-h-image-und-0-upload"
    Then I select the radio button "Dark" with the id "edit-field-elife-h-image-colour-und-dark"
    And I press "Save"
    And I am on "/collections/algoriphagus"
    And I should see "Hero block - Algoriphagus"
    And I should see "Sub-title for Algoriphagus"
    Then I should see text matching "Article 2 for Collections test"
    Then I should see text matching "Article 3 for Collections test"

  Scenario: Hero block for collection of collections page
    Given I am logged in as a user with the "access administration menu,access content,create elife_hero_block content" permissions
    When "elife_person_profile" content:
      | field_elife_p_first_name | field_elife_p_last_name | field_elife_p_type |
      | FirstName                | LastName                | Executive Staff    |
    When "elife_collection" content:
      | title        | field_elife_c_articles                                                       | field_elife_c_curators               |
      | Algoriphagus | 05224: Article 2 for Collections test, 05225: Article 3 for Collections test | FirstName LastName (Executive Staff) |
    When "elife_collection" content:
      | title        | field_elife_c_articles                                                       | field_elife_c_curators               |
      | early-career | 01633: Article 7 for Collections test, 04901: Article 6 for Collections test | FirstName LastName (Executive Staff) |
    And I am on "/node/add/elife-hero-block"
    Then I should see "Create eLife Hero Block"
    Then I fill in "Title" with "Hero block - Collections Page"
    Then I fill in "edit-field-elife-h-sub-title-und-0-value" with "Collection of collections"
    Then I fill in "Appears on" with "collections"
    When I attach the file "test.jpg" to "edit-field-elife-h-image-und-0-upload"
    Then I select the radio button "Dark" with the id "edit-field-elife-h-image-colour-und-dark"
    And I press "Save"
    And I am on "/collections"
    And I should see "Hero block - Collections Page"
    And I should see "Collection of collections"
    Then I should see text matching "Algoriphagus"
    Then I should see text matching "early-career"

  Scenario: Collections without articles
    Given I am logged in as a user with the "administrator" role
    When "elife_person_profile" content:
      | field_elife_p_first_name | field_elife_p_last_name | field_elife_p_type |
      | FirstName                | LastName                | Executive Staff    |
    And I am on "/node/add/elife-hero-block"
    Then I should see "Create eLife Hero Block"
    Then I fill in "Title" with "Hero block - Algoriphagus"
    Then I fill in "edit-field-elife-h-sub-title-und-0-value" with "Collection with no articles"
    Then I fill in "Appears on" with "collections/algoriphags2"
    When I attach the file "test.jpg" to "edit-field-elife-h-image-und-0-upload"
    And I press "Upload"
    Then I select the radio button "Dark" with the id "edit-field-elife-h-image-colour-und-dark"
    And I press "Save"
    When "elife_collection" content:
      | title        | field_elife_c_articles                                                       | field_elife_c_curators               |
      | Algoriphags2 | 05204: Article 11 for Collections test, 05205: Article 13 for Collections test | FirstName LastName (Executive Staff) |

    And I am on "/collections/algoriphags2"
    And I should see "Hero block - Algoriphagus"
    And I should see "Collection with no articles"
    Then I should not see text matching "Article 11 for Collections test"
    Then I should not see text matching "Article 13 for Collections test"
    Then I should see text matching "Algoriphags2"

  @develop
  Scenario: Creating heroblock before respective collection
    Given I am logged in as a user with the "administrator" role
    And I am on "/node/add/elife-hero-block"
    And the response status code should be 200
    And print current URL
    Then I should see "Create eLife Hero Block"
    Then I fill in "Title" with "Hero block - Algoriphagus"
    Then I fill in "edit-field-elife-h-sub-title-und-0-value" with "Sub-title for Algoriphagus"
    Then I fill in "Appears on" with "collections/algoriphagus"
    When I attach the file "test.jpg" to "edit-field-elife-h-image-und-0-upload"
    And I press "Upload"
    Then I select the radio button "Dark" with the id "edit-field-elife-h-image-colour-und-dark"
    And I press "Save"
    When "elife_person_profile" content:
      | field_elife_p_first_name | field_elife_p_last_name | field_elife_p_type |
      | FName                    | LName                   | Executive Staff    |
    When "elife_collection" content:
      | title        | field_elife_c_articles                                                       | field_elife_c_curators               |
      | Algoriphagus | 05224: Article 2 for Collections test, 05225: Article 3 for Collections test | FirstName LastName (Executive Staff) |
    And I am on "/collections/algoriphagus"
    And I should see "Hero block - Algoriphagus"
    And I should see "Sub-title for Algoriphagus"
    Then I should see text matching "Article 2 for Collections test"
    Then I should see text matching "Article 3 for Collections test"
