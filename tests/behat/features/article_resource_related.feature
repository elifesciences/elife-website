Feature: Article Resource - Related articles (API)
  In order to maintain article content
  As a production system
  I need to be able to post versions of article content via the resource api

  @api
  Scenario: Set related articles
    Given I am logged in as a user with the "eLife Article Publisher" role
    And I am authenticating as the Drupal user
    And I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05224",
          "version": 1,
          "doi": "10.7554/eLife.05224",
          "volume": 4,
          "elocation-id": "e05224",
          "article-id": "05224",
          "article-version-id": "05224.1",
          "pub-date": "1979-08-17T00:00:00+00:00",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "VOR",
          "publish": true,
          "categories": {
            "display-channel": [
              "Research article"
            ]
          },
          "related-articles": [
            {
              "type": "commentary",
              "href": "10.7554/eLife.05224"
            },
            {
              "type": "commentary-article",
              "href": "10.7554/eLife.05225"
            },
            {
              "type": "article-reference",
              "href": "10.7554/eLife.05226"
            }
          ]
        }
      """
    Then the response code should be 200
    And the response should contain json:
      """
        {
          "related-articles": [
            {
              "type": "commentary",
              "href": "10.7554/eLife.05224"
            },
            {
              "type": "commentary-article",
              "href": "10.7554/eLife.05225"
            },
            {
              "type": "article-reference",
              "href": "10.7554/eLife.05226"
            }
          ]
        }
      """
    And there should be 1 verified related article
    And there should be 2 unverified related articles
    And I am on "content/4/e05224"
    And I should see 1 ".elife-related-articles-list > li" elements
    And I should see "VOR 05224" in the ".sidebar-wrapper .elife-related-articles-list" element

  Scenario: Check correct number of articles related
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
            "article-version-id": "05224.1",
            "pub-date": "1979-08-17T00:00:00+00:00",
            "path": "content/4/e05224",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true,
            "categories": {
              "display-channel": [
                "Research article"
              ]
            },
            "related-articles": [
              {
                "type": "commentary",
                "href": "10.7554/eLife.05224"
              },
              {
                "type": "commentary-article",
                "href": "10.7554/eLife.05225"
              },
              {
                "type": "article-reference",
                "href": "10.7554/eLife.05226"
              },
              {
                "type": "article-reference",
                "href": "10.7554/eLife.05227"
              }
            ]
          },
          {
            "title": "VOR 05227",
            "version": 1,
            "doi": "10.7554/eLife.05227",
            "volume": 4,
            "elocation-id": "e05227",
            "article-id": "05227",
            "article-version-id": "05227.1",
            "pub-date": "1979-08-17T00:00:00+00:00",
            "path": "content/4/e05227",
            "article-type": "correction",
            "status": "VOR",
            "publish": true,
            "categories": {
              "display-channel": [
                "Research article"
              ]
            },
            "related-articles": [
              {
                "type": "article-reference",
                "href": "10.7554/eLife.05224"
              }
            ]
          }
        ]
      """
    And there should be 3 verified related articles
    And there should be 3 verified related articles for "10.7554/eLife.05224"
    And there should be 2 verified related articles for "10.7554/eLife.05227"
    And there should be 2 unique verified related articles
    And there should be 2 unique verified related articles for "10.7554/eLife.05224"
    And there should be 1 unique verified related articles for "10.7554/eLife.05227"
    And there should be 2 unverified related articles
    And there should be 2 unverified related articles for "10.7554/eLife.05224"
    And there should be 0 unverified related articles for "10.7554/eLife.05227"
    And article "10.7554/eLife.05224" should be related to "10.7554/eLife.05224,10.7554/eLife.05227"
    And article "10.7554/eLife.05227" should be related to "10.7554/eLife.05224"
    And article "10.7554/eLife.05224" should have unverified related articles of "10.7554/eLife.05225,10.7554/eLife.05226"
    And I am on "content/4/e05224"
    And I should see 2 ".elife-related-articles-list > li" elements
    And I should see "VOR 05224" in the ".sidebar-wrapper .elife-related-articles-list" element
    And I should see "VOR 05227" in the ".sidebar-wrapper .elife-related-articles-list" element
    And I am on "content/4/e05227"
    And I should see 1 ".elife-related-articles-list > li" elements
    And I should see "VOR 05224" in the ".sidebar-wrapper .elife-related-articles-list" element

  Scenario: Check correct number of articles related when multiple versions of the article available with the same DOIs
    Given there are articles:
      """
        [
          {
            "title": "VOR 05224v2",
            "version": 2,
            "doi": "10.7554/eLife.05224",
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
                "Research article"
              ]
            },
            "related-articles": [
              {
                "type": "commentary",
                "href": "10.7554/eLife.05224"
              },
              {
                "type": "commentary-article",
                "href": "10.7554/eLife.05225"
              }
            ]
          },
          {
            "title": "VOR 05224v1",
            "version": 1,
            "doi": "10.7554/eLife.05224",
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
                "Research article"
              ]
            },
            "related-articles": [
              {
                "type": "commentary",
                "href": "10.7554/eLife.05224"
              },
              {
                "type": "commentary-article",
                "href": "10.7554/eLife.05225"
              },
              {
                "type": "article-reference",
                "href": "10.7554/eLife.05226"
              },
              {
                "type": "article-reference",
                "href": "10.7554/eLife.05227"
              }
            ]
          },
          {
            "title": "VOR 05227v1",
            "version": 1,
            "doi": "10.7554/eLife.05227",
            "volume": 4,
            "elocation-id": "e05227",
            "article-id": "05227",
            "article-version-id": "05227.1",
            "pub-date": "1979-08-17T00:00:00+00:00",
            "path": "content/4/e05227v1",
            "article-type": "correction",
            "status": "VOR",
            "publish": true,
            "categories": {
              "display-channel": [
                "Research article"
              ]
            },
            "related-articles": [
              {
                "type": "article-reference",
                "href": "10.7554/eLife.05224"
              }
            ]
          },
          {
            "title": "VOR 05227v2",
            "version": 2,
            "doi": "10.7554/eLife.05227",
            "volume": 4,
            "elocation-id": "e05227",
            "article-id": "05227",
            "article-version-id": "05227.2",
            "pub-date": "1979-08-17T00:00:00+00:00",
            "path": "content/4/e05227v2",
            "article-type": "correction",
            "status": "VOR",
            "publish": true,
            "categories": {
              "display-channel": [
                "Research article"
              ]
            },
            "related-articles": [
              {
                "type": "article-reference",
                "href": "10.7554/eLife.05224"
              }
            ]
          }
        ]
      """
    Then there should be 2 verified related articles
    And there should be 2 verified related articles for "10.7554/eLife.05224"
    And there should be 1 verified related articles for "10.7554/eLife.05227"
    And there should be 2 unique verified related articles
    And there should be 2 unique verified related articles for "10.7554/eLife.05224"
    And there should be 1 unique verified related articles for "10.7554/eLife.05227"
    And there should be 1 unverified related articles
    And there should be 1 unverified related articles for "10.7554/eLife.05224"
    And there should be 0 unverified related articles for "10.7554/eLife.05227"
    And article "10.7554/eLife.05224" should be related to "10.7554/eLife.05224,10.7554/eLife.05227"
    And article "10.7554/eLife.05227" should be related to "10.7554/eLife.05224"
    And article "10.7554/eLife.05224" should have unverified related articles of "10.7554/eLife.05225"
    And I am on "content/4/e05224v1"
    And I should see 2 ".elife-related-articles-list > li" elements
    And I should see "VOR 05227v2" in the ".sidebar-wrapper .elife-related-articles-list" element
    And I am on "content/4/e05224v2"
    And I should see 2 ".elife-related-articles-list > li" elements
    And I should see "VOR 05227v2" in the ".sidebar-wrapper .elife-related-articles-list" element
    And I am on "content/4/e05227v1"
    And I should see 1 ".elife-related-articles-list > li" elements
    And I should see "VOR 05224v2" in the ".sidebar-wrapper .elife-related-articles-list" element
    And I am on "content/4/e05227v2"
    And I should see 1 ".elife-related-articles-list > li" elements
    And I should see "VOR 05224v2" in the ".sidebar-wrapper .elife-related-articles-list" element

  Scenario: Related articles of previous versions are purged
    Given there are articles:
      """
        [
          {
            "title": "VOR 05224v1",
            "version": 1,
            "doi": "10.7554/eLife.05224",
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
                "Research article"
              ]
            },
            "related-articles": [
              {
                "type": "commentary",
                "href": "10.7554/eLife.05224"
              },
              {
                "type": "article-reference",
                "href": "10.7554/eLife.05227"
              }
            ]
          },
          {
            "title": "VOR 05224v2",
            "version": 2,
            "doi": "10.7554/eLife.05224",
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
                "Research article"
              ]
            },
            "related-articles": [
              {
                "type": "commentary",
                "href": "10.7554/eLife.05224"
              },
              {
                "type": "article-reference",
                "href": "10.7554/eLife.05225"
              }
            ]
          },
          {
            "title": "VOR 05227v1",
            "version": 1,
            "doi": "10.7554/eLife.05227",
            "volume": 4,
            "elocation-id": "e05227",
            "article-id": "05227",
            "article-version-id": "05227.1",
            "pub-date": "1979-08-17T00:00:00+00:00",
            "path": "content/4/e05227v1",
            "article-type": "correction",
            "status": "VOR",
            "publish": true,
            "categories": {
              "display-channel": [
                "Research article"
              ]
            }
          }
        ]
      """
    Then there should be 1 verified related articles
    And there should be 1 verified related articles for "10.7554/eLife.05224"
    And there should be 0 verified related articles for "10.7554/eLife.05227"
    And there should be 1 unique verified related articles
    And there should be 1 unique verified related articles for "10.7554/eLife.05224"
    And there should be 0 unique verified related articles for "10.7554/eLife.05227"
    And there should be 1 unverified related articles
    And there should be 1 unverified related articles for "10.7554/eLife.05224"
    And there should be 0 unverified related articles for "10.7554/eLife.05227"
    And article "10.7554/eLife.05224" should be related to "10.7554/eLife.05224"
    And article "10.7554/eLife.05227" should not be related to "10.7554/eLife.05224"
    And article "10.7554/eLife.05224" should have unverified related articles of "10.7554/eLife.05225"

  Scenario Outline: Make it easy to find the correction/retraction from the corrected/retracted article
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
            "article-version-id": "05224.1",
            "pub-date": "1979-08-17T00:00:00+00:00",
            "path": "content/4/e05224",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true,
            "categories": {
              "display-channel": [
                "<display_channel1>"
              ]
            }
          },
          {
            "title": "Correction VOR 05226",
            "version": 1,
            "doi": "10.7554/eLife.05226",
            "volume": 4,
            "elocation-id": "e05226",
            "article-id": "05226",
            "article-version-id": "05226.1",
            "pub-date": "1979-08-17T00:00:00+00:00",
            "path": "content/4/e05226",
            "article-type": "correction",
            "status": "VOR",
            "publish": true,
            "categories": {
              "display-channel": [
                "<display_channel2>"
              ]
            },
            "related-articles": [
              {
                "type": "corrected-article",
                "href": "10.7554/eLife.05224"
              }
            ]
          }
        ]
      """
    When I am on "content/4/e05224"
    And I follow "<correction_link>"
    And I should be on "content/4/e05226"
    And I follow "<corrected_link>"
    Then I should be on "content/4/e05224"

    Examples:
      | display_channel1 | display_channel2 | correction_link                 | corrected_link             |
      | Research article | Correction       | This article has been corrected | View the corrected article |
      | Research article | Retraction       | This article has been retracted | View the retracted article |

  Scenario Outline: Present critical relation in the main content region
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
            "article-version-id": "05224.1",
            "pub-date": "1979-08-17T00:00:00+00:00",
            "path": "content/4/e05224",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true,
            "categories": {
              "display-channel": [
                "<display_channel1>"
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
            "article-version-id": "05226.1",
            "pub-date": "1979-08-17T00:00:00+00:00",
            "path": "content/4/e05226",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true,
            "categories": {
              "display-channel": [
                "<display_channel2>"
              ]
            },
            "related-articles": [
              {
                "type": "article-reference",
                "href": "10.7554/eLife.05224"
              }
            ]
          }
        ]
      """
    When I am on "content/4/e05224"
    And I should see "<critical_relation_title1>" in the ".pane-elife-article-criticalrelation" element
    And I follow "VOR 05226"
    And I should be on "content/4/e05226"
    And I should see "<critical_relation_title2>" in the ".pane-elife-article-criticalrelation" element
    And I follow "VOR 05224"
    Then I should be on "content/4/e05224"

    Examples:
      | display_channel1    | display_channel2  | critical_relation_title1 | critical_relation_title2 |
      | Research article    | Research advance  | Built upon by            | Builds upon              |
      | Tools and resources | Research advance  | Built upon by            | Builds upon              |
      | Short report        | Research advance  | Built upon by            | Builds upon              |
      | Registered report   | Replication study | Replication study        | Registered report        |

  Scenario: Present multiple critical relations
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
            "article-version-id": "05224.1",
            "pub-date": "1979-08-17T00:00:00+00:00",
            "path": "content/4/e05224",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true,
            "categories": {
              "display-channel": [
                "Registered report"
              ]
            }
          },
          {
            "title": "VOR 05225",
            "version": 1,
            "doi": "10.7554/eLife.05225",
            "volume": 4,
            "elocation-id": "e05225",
            "article-id": "05225",
            "article-version-id": "05225.1",
            "pub-date": "1979-08-17T00:00:00+00:00",
            "path": "content/4/e05225",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true,
            "categories": {
              "display-channel": [
                "Replication study"
              ]
            },
            "related-articles": [
              {
                "type": "article-reference",
                "href": "10.7554/eLife.05224"
              }
            ]
          },
          {
            "title": "VOR 05226",
            "version": 1,
            "doi": "10.7554/eLife.05226",
            "volume": 4,
            "elocation-id": "e05226",
            "article-id": "05226",
            "article-version-id": "05226.1",
            "pub-date": "1979-08-17T00:00:00+00:00",
            "path": "content/4/e05226",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true,
            "categories": {
              "display-channel": [
                "Research advance"
              ]
            },
            "related-articles": [
              {
                "type": "article-reference",
                "href": "10.7554/eLife.05224"
              }
            ]
          },
          {
            "title": "VOR 05227",
            "version": 1,
            "doi": "10.7554/eLife.05227",
            "volume": 4,
            "elocation-id": "e05227",
            "article-id": "05227",
            "article-version-id": "05227.1",
            "pub-date": "1979-08-17T00:00:00+00:00",
            "path": "content/4/e05227",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true,
            "categories": {
              "display-channel": [
                "Tools and resources"
              ]
            }
          },
          {
            "title": "VOR 05228",
            "version": 1,
            "doi": "10.7554/eLife.05228",
            "volume": 4,
            "elocation-id": "e05228",
            "article-id": "05228",
            "article-version-id": "05228.1",
            "pub-date": "1979-08-17T00:00:00+00:00",
            "path": "content/4/e05228",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true,
            "categories": {
              "display-channel": [
                "Research advance"
              ]
            },
            "related-articles": [
              {
                "type": "article-reference",
                "href": "10.7554/eLife.05224"
              },
              {
                "type": "article-reference",
                "href": "10.7554/eLife.05227"
              }
            ]
          }
        ]
      """
    When I am on "content/4/e05224"
    Then I should see "Replication study" in the ".pane-elife-article-criticalrelation" element
    And I should see 1 "#replicationStudy h3" elements
    And I should see "VOR 05225" in the "#replicationStudy" element
    And I should see 0 "#researchAdvance" elements
    When I am on "content/4/e05228"
    Then I should see "Builds upon" in the ".pane-elife-article-criticalrelation" element
    And I should see 1 "#researchArticle h3" elements
    And I should see 1 ".elife-related-articles-list > li" elements
