@api
Feature: Article Resource - Fragments (API)
  In order to maintain article content
  As a production system
  I need to be able to post article content with fragments via the resource api

  Background:
    Given I am logged in as a user with the "eLife Article Publisher" role
    And I am authenticating as the Drupal user

  Scenario: Load an article with child fragments and sub-articles
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
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
          "fragments": [
            {
              "type": "abstract",
              "doi": "10.7554/eLife.00013.001",
              "path": "content/3/e00013/abstract-1"
            },
            {
              "type": "abstract",
              "title": "eLife digest",
              "doi": "10.7554/eLife.00013.002",
              "path": "content/3/e00013/abstract-2"
            },
            {
              "type": "fig",
              "title": "Figure 1.",
              "doi": "10.7554/eLife.00013.003",
              "path": "content/3/e00013/f1",
              "fragments": [
                {
                  "type": "supplementary-material",
                  "title": "Figure 1—source data 1.",
                  "doi": "10.7554/eLife.00013.004",
                  "path": "content/3/e00013/f1/dc1"
                },
                {
                  "type": "fig",
                  "title": "Figure 1—figure supplement 1.",
                  "doi": "10.7554/eLife.00013.005",
                  "path": "content/3/e00013/f1/f2"
                }
              ]
            },
            {
              "type": "media",
              "title": "Video 1.",
              "doi": "10.7554/eLife.00013.006",
              "path": "content/3/e00013/media-1"
            },
            {
              "type": "table-wrap",
              "title": "Table 1.",
              "doi": "10.7554/eLife.00013.007",
              "path": "content/3/e00013/t1",
              "fragments": [
                {
                  "type": "supplementary-material",
                  "title": "Table 1—source data 1.",
                  "doi": "10.7554/eLife.00013.008",
                  "path": "content/3/e00013/t1/dc2"
                }
              ]
            },
            {
              "type": "boxed-text",
              "title": "Box 1.",
              "doi": "10.7554/eLife.00013.009",
              "path": "content/3/e00013/b1"
            },
            {
              "type": "fig",
              "title": "Figure 2.",
              "doi": "10.7554/eLife.00013.010",
              "path": "content/3/e00013/f3"
            },
            {
              "type": "table-wrap",
              "title": "Table 2.",
              "doi": "10.7554/eLife.00013.011",
              "path": "content/3/e00013/t2"
            },
            {
              "type": "fig",
              "title": "Figure 3.",
              "doi": "10.7554/eLife.00013.012",
              "path": "content/3/e00013/f4",
              "fragments": [
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 1.",
                  "doi": "10.7554/eLife.00013.013",
                  "path": "content/3/e00013/f4/f5"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 2.",
                  "doi": "10.7554/eLife.00013.014",
                  "path": "content/3/e00013/f4/f6"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 3.",
                  "doi": "10.7554/eLife.00013.015",
                  "path": "content/3/e00013/f4/f7"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 4.",
                  "doi": "10.7554/eLife.00013.016",
                  "path": "content/3/e00013/f4/f8"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 5.",
                  "doi": "10.7554/eLife.00013.017",
                  "path": "content/3/e00013/f4/f9"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 6.",
                  "doi": "10.7554/eLife.00013.018",
                  "path": "content/3/e00013/f4/f10"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 7.",
                  "doi": "10.7554/eLife.00013.019",
                  "path": "content/3/e00013/f4/f11"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 8.",
                  "doi": "10.7554/eLife.00013.020",
                  "path": "content/3/e00013/f4/f12"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 9.",
                  "doi": "10.7554/eLife.00013.021",
                  "path": "content/3/e00013/f4/f13"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 10.",
                  "doi": "10.7554/eLife.00013.022",
                  "path": "content/3/e00013/f4/f14"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 11.",
                  "doi": "10.7554/eLife.00013.023",
                  "path": "content/3/e00013/f4/f15"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 12.",
                  "doi": "10.7554/eLife.00013.024",
                  "path": "content/3/e00013/f4/f16"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 13.",
                  "doi": "10.7554/eLife.00013.025",
                  "path": "content/3/e00013/f4/f17"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 14.",
                  "doi": "10.7554/eLife.00013.026",
                  "path": "content/3/e00013/f4/f18"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 15.",
                  "doi": "10.7554/eLife.00013.027",
                  "path": "content/3/e00013/f4/f19"
                }
              ]
            },
            {
              "type": "table-wrap",
              "title": "Table 3.",
              "doi": "10.7554/eLife.00013.028",
              "path": "content/3/e00013/t3"
            },
            {
              "type": "fig",
              "title": "Figure 4.",
              "doi": "10.7554/eLife.00013.029",
              "path": "content/3/e00013/f20",
              "fragments": [
                {
                  "type": "fig",
                  "title": "Figure 4—figure supplement 1.",
                  "doi": "10.7554/eLife.00013.030",
                  "path": "content/3/e00013/f20/f21"
                }
              ]
            },
            {
              "type": "supplementary-material",
              "title": "Supplementary file 1.",
              "doi": "10.7554/eLife.00013.031",
              "path": "content/3/e00013/dc3"
            },
            {
              "type": "supplementary-material",
              "title": "Supplementary file 2.",
              "doi": "10.7554/eLife.00013.032",
              "path": "content/3/e00013/dc4"
            },
            {
              "type": "supplementary-material",
              "title": "Supplementary file 3.",
              "doi": "10.7554/eLife.00013.033",
              "path": "content/3/e00013/dc5"
            },
            {
              "type": "fig",
              "title": "Appendix 1 Figure 1 8.",
              "doi": "10.7554/eLife.00013.034",
              "path": "content/3/e00013/f22"
            },
            {
              "type": "fig",
              "title": "Appendix 2 Figure 1",
              "doi": "10.7554/eLife.00013.035",
              "path": "content/3/e00013/f23"
            },
            {
              "type": "fig",
              "title": "Appendix 2 Figure 2",
              "doi": "10.7554/eLife.00013.036",
              "path": "content/3/e00013/f24"
            },
            {
              "type": "sub-article",
              "title": "Decision letter",
              "doi": "10.7554/eLife.00013.037",
              "path": "content/3/e00013/1",
              "contributors": [
                {
                  "type": "editor",
                  "surname": "Sneden",
                  "given-names": "Christopher",
                  "role": "Reviewing editor",
                  "affiliations": [
                    {
                      "institution": "Pediatric Dengue Vaccine Initiative",
                      "country": "United States"
                    }
                  ]
                },
                {
                  "type": "reviewer",
                  "id": "author-34",
                  "surname": "Harrison",
                  "given-names": "Melissa",
                  "role": "Reviewer",
                  "affiliations": [
                    {
                      "institution": "Pediatric Dengue Vaccine Initiative",
                      "country": "United States"
                    }
                  ]
                },
                {
                  "type": "reviewer",
                  "id": "author-35",
                  "surname": "Roderick",
                  "given-names": "Sian",
                  "role": "Reviewer",
                  "affiliations": [
                    {
                      "institution": "Pediatric Dengue Vaccine Initiative",
                      "country": "United States"
                    }
                  ]
                }
              ]
            },
            {
              "type": "sub-article",
              "title": "Author response",
              "doi": "10.7554/eLife.00013.037",
              "path": "content/3/e00013/2",
              "fragments": [
                {
                  "type": "fig",
                  "title": "Author response image 1",
                  "doi": "10.7554/eLife.00013.038",
                  "path": "content/3/e00013/2/f25"
                },
                {
                  "type": "table-wrap",
                  "title": "Author response table 1.",
                  "doi": "10.7554/eLife.00013.039",
                  "path": "content/3/e00013/2/t4"
                }
              ]
            }
          ]
        }
      """
    When I send a GET request to "api/article/05224.json"
    Then the response should contain json:
      """
        {
          "title": "VOR 05224",
          "fragments": [
            {
              "type": "abstract",
              "title": "Abstract",
              "doi": "10.7554/eLife.00013.001",
              "path": "content/3/e00013/abstract-1"
            },
            {
              "type": "abstract",
              "title": "eLife digest",
              "doi": "10.7554/eLife.00013.002",
              "path": "content/3/e00013/abstract-2"
            },
            {
              "type": "fig",
              "title": "Figure 1.",
              "doi": "10.7554/eLife.00013.003",
              "path": "content/3/e00013/f1",
              "fragments": [
                {
                  "type": "supplementary-material",
                  "title": "Figure 1—source data 1.",
                  "doi": "10.7554/eLife.00013.004",
                  "path": "content/3/e00013/f1/dc1"
                },
                {
                  "type": "fig",
                  "title": "Figure 1—figure supplement 1.",
                  "doi": "10.7554/eLife.00013.005",
                  "path": "content/3/e00013/f1/f2"
                }
              ]
            },
            {
              "type": "media",
              "title": "Video 1.",
              "doi": "10.7554/eLife.00013.006",
              "path": "content/3/e00013/media-1"
            },
            {
              "type": "table-wrap",
              "title": "Table 1.",
              "doi": "10.7554/eLife.00013.007",
              "path": "content/3/e00013/t1",
              "fragments": [
                {
                  "type": "supplementary-material",
                  "title": "Table 1—source data 1.",
                  "doi": "10.7554/eLife.00013.008",
                  "path": "content/3/e00013/t1/dc2"
                }
              ]
            },
            {
              "type": "boxed-text",
              "title": "Box 1.",
              "doi": "10.7554/eLife.00013.009",
              "path": "content/3/e00013/b1"
            },
            {
              "type": "fig",
              "title": "Figure 2.",
              "doi": "10.7554/eLife.00013.010",
              "path": "content/3/e00013/f3"
            },
            {
              "type": "table-wrap",
              "title": "Table 2.",
              "doi": "10.7554/eLife.00013.011",
              "path": "content/3/e00013/t2"
            },
            {
              "type": "fig",
              "title": "Figure 3.",
              "doi": "10.7554/eLife.00013.012",
              "path": "content/3/e00013/f4",
              "fragments": [
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 1.",
                  "doi": "10.7554/eLife.00013.013",
                  "path": "content/3/e00013/f4/f5"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 2.",
                  "doi": "10.7554/eLife.00013.014",
                  "path": "content/3/e00013/f4/f6"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 3.",
                  "doi": "10.7554/eLife.00013.015",
                  "path": "content/3/e00013/f4/f7"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 4.",
                  "doi": "10.7554/eLife.00013.016",
                  "path": "content/3/e00013/f4/f8"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 5.",
                  "doi": "10.7554/eLife.00013.017",
                  "path": "content/3/e00013/f4/f9"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 6.",
                  "doi": "10.7554/eLife.00013.018",
                  "path": "content/3/e00013/f4/f10"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 7.",
                  "doi": "10.7554/eLife.00013.019",
                  "path": "content/3/e00013/f4/f11"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 8.",
                  "doi": "10.7554/eLife.00013.020",
                  "path": "content/3/e00013/f4/f12"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 9.",
                  "doi": "10.7554/eLife.00013.021",
                  "path": "content/3/e00013/f4/f13"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 10.",
                  "doi": "10.7554/eLife.00013.022",
                  "path": "content/3/e00013/f4/f14"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 11.",
                  "doi": "10.7554/eLife.00013.023",
                  "path": "content/3/e00013/f4/f15"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 12.",
                  "doi": "10.7554/eLife.00013.024",
                  "path": "content/3/e00013/f4/f16"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 13.",
                  "doi": "10.7554/eLife.00013.025",
                  "path": "content/3/e00013/f4/f17"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 14.",
                  "doi": "10.7554/eLife.00013.026",
                  "path": "content/3/e00013/f4/f18"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 15.",
                  "doi": "10.7554/eLife.00013.027",
                  "path": "content/3/e00013/f4/f19"
                }
              ]
            },
            {
              "type": "table-wrap",
              "title": "Table 3.",
              "doi": "10.7554/eLife.00013.028",
              "path": "content/3/e00013/t3"
            },
            {
              "type": "fig",
              "title": "Figure 4.",
              "doi": "10.7554/eLife.00013.029",
              "path": "content/3/e00013/f20",
              "fragments": [
                {
                  "type": "fig",
                  "title": "Figure 4—figure supplement 1.",
                  "doi": "10.7554/eLife.00013.030",
                  "path": "content/3/e00013/f20/f21"
                }
              ]
            },
            {
              "type": "supplementary-material",
              "title": "Supplementary file 1.",
              "doi": "10.7554/eLife.00013.031",
              "path": "content/3/e00013/dc3"
            },
            {
              "type": "supplementary-material",
              "title": "Supplementary file 2.",
              "doi": "10.7554/eLife.00013.032",
              "path": "content/3/e00013/dc4"
            },
            {
              "type": "supplementary-material",
              "title": "Supplementary file 3.",
              "doi": "10.7554/eLife.00013.033",
              "path": "content/3/e00013/dc5"
            },
            {
              "type": "fig",
              "title": "Appendix 1 Figure 1 8.",
              "doi": "10.7554/eLife.00013.034",
              "path": "content/3/e00013/f22"
            },
            {
              "type": "fig",
              "title": "Appendix 2 Figure 1",
              "doi": "10.7554/eLife.00013.035",
              "path": "content/3/e00013/f23"
            },
            {
              "type": "fig",
              "title": "Appendix 2 Figure 2",
              "doi": "10.7554/eLife.00013.036",
              "path": "content/3/e00013/f24"
            },
            {
              "type": "sub-article",
              "title": "Decision letter",
              "doi": "10.7554/eLife.00013.037",
              "path": "content/3/e00013/1",
              "contributors": [
                {
                  "type": "editor",
                  "surname": "Sneden",
                  "given-names": "Christopher",
                  "role": "Reviewing editor",
                  "affiliations": [
                    {
                      "institution": "Pediatric Dengue Vaccine Initiative",
                      "country": "United States"
                    }
                  ]
                },
                {
                  "type": "reviewer",
                  "id": "author-34",
                  "surname": "Harrison",
                  "given-names": "Melissa",
                  "role": "Reviewer",
                  "affiliations": [
                    {
                      "institution": "Pediatric Dengue Vaccine Initiative",
                      "country": "United States"
                    }
                  ]
                },
                {
                  "type": "reviewer",
                  "id": "author-35",
                  "surname": "Roderick",
                  "given-names": "Sian",
                  "role": "Reviewer",
                  "affiliations": [
                    {
                      "institution": "Pediatric Dengue Vaccine Initiative",
                      "country": "United States"
                    }
                  ]
                }
              ]
            },
            {
              "type": "sub-article",
              "title": "Author response",
              "doi": "10.7554/eLife.00013.037",
              "path": "content/3/e00013/2",
              "fragments": [
                {
                  "type": "fig",
                  "title": "Author response image 1",
                  "doi": "10.7554/eLife.00013.038",
                  "path": "content/3/e00013/2/f25"
                },
                {
                  "type": "table-wrap",
                  "title": "Author response table 1.",
                  "doi": "10.7554/eLife.00013.039",
                  "path": "content/3/e00013/2/t4"
                }
              ]
            }
          ]
        }
      """

  Scenario: Load and update an article with child fragments and sub-articles
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
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
          "fragments": [
            {
              "type": "abstract",
              "title": "Abstract",
              "doi": "10.7554/eLife.00013.001",
              "path": "content/4/e05224/abstract-1"
            },
            {
              "type": "abstract",
              "title": "eLife digest",
              "doi": "10.7554/eLife.00013.002",
              "path": "content/4/e05224/abstract-2"
            }
          ]
        }
      """
    And I send a POST request to "api/article.json" with body:
      """
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
          "fragments": [
            {
              "type": "abstract",
              "doi": "10.7554/eLife.00013.001",
              "path": "content/4/e05224/abstract-1"
            },
            {
              "type": "abstract",
              "title": "eLife digest",
              "doi": "10.7554/eLife.00013.002",
              "path": "content/4/e05224/abstract-2"
            }
          ]
        }
      """
    When I send a GET request to "api/article/05224.json"
    Then the response should contain json:
      """
        {
          "title": "VOR 05224",
          "fragments": [
            {
              "type": "abstract",
              "title": "Abstract",
              "doi": "10.7554/eLife.00013.001",
              "path": "content/4/e05224/abstract-1"
            },
            {
              "type": "abstract",
              "title": "eLife digest",
              "doi": "10.7554/eLife.00013.002",
              "path": "content/4/e05224/abstract-2"
            }
          ]
        }
      """

  Scenario: Attempt to load an article with fragments with no title
    Given I set header "Content-Type" with value "application/json"
    When I send a POST request to "api/article.json" with body:
      """
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
          "fragments": [
            {
              "type": "abstract",
              "doi": "10.7554/eLife.00013.001",
              "path": "content/3/e00013/abstract-1"
            },
            {
              "type": "abstract",
              "title": "eLife digest",
              "doi": "10.7554/eLife.00013.002",
              "path": "content/3/e00013/abstract-2"
            },
            {
              "type": "fig",
              "doi": "10.7554/eLife.00013.003",
              "path": "content/3/e00013/f1"
            }
          ]
        }
      """
    Then response code should be 400
    And the response should contain json:
      """
        [
          {
            "field": "data.fragments.2",
            "message": "referenced schema does not match",
            "value": {
              "type": "fig",
              "doi": "10.7554/eLife.00013.003",
              "path": "content/3/e00013/f1"
            }
          }
        ]
      """
