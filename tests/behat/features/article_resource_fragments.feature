Feature: Article Resource - Fragments (API)
  In order to maintain article content
  As a production system
  I need to be able to post article content with fragments via the resource api

  Scenario: Load an article with child fragments and sub-articles
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05224",
          "version": "1",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "article-id": "10.7554/eLife.05224",
          "article-version-id": "05224",
          "pub-date": "1979-08-17",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1",
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
              "path": "content/3/e00013/F1",
              "fragments": [
                {
                  "type": "supplementary-material",
                  "title": "Figure 1—source data 1.",
                  "doi": "10.7554/eLife.00013.004",
                  "path": "content/3/e00013/F1/DC1"
                },
                {
                  "type": "fig",
                  "title": "Figure 1—figure supplement 1.",
                  "doi": "10.7554/eLife.00013.005",
                  "path": "content/3/e00013/F1/F2"
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
              "path": "content/3/e00013/T1",
              "fragments": [
                {
                  "type": "supplementary-material",
                  "title": "Table 1—source data 1.",
                  "doi": "10.7554/eLife.00013.008",
                  "path": "content/3/e00013/T1/DC2"
                }
              ]
            },
            {
              "type": "boxed-text",
              "title": "Box 1.",
              "doi": "10.7554/eLife.00013.009",
              "path": "content/3/e00013/B1"
            },
            {
              "type": "fig",
              "title": "Figure 2.",
              "doi": "10.7554/eLife.00013.010",
              "path": "content/3/e00013/F3"
            },
            {
              "type": "table-wrap",
              "title": "Table 2.",
              "doi": "10.7554/eLife.00013.011",
              "path": "content/3/e00013/T2"
            },
            {
              "type": "fig",
              "title": "Figure 3.",
              "doi": "10.7554/eLife.00013.012",
              "path": "content/3/e00013/F4",
              "fragments": [
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 1.",
                  "doi": "10.7554/eLife.00013.013",
                  "path": "content/3/e00013/F4/F5"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 2.",
                  "doi": "10.7554/eLife.00013.014",
                  "path": "content/3/e00013/F4/F6"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 3.",
                  "doi": "10.7554/eLife.00013.015",
                  "path": "content/3/e00013/F4/F7"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 4.",
                  "doi": "10.7554/eLife.00013.016",
                  "path": "content/3/e00013/F4/F8"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 5.",
                  "doi": "10.7554/eLife.00013.017",
                  "path": "content/3/e00013/F4/F9"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 6.",
                  "doi": "10.7554/eLife.00013.018",
                  "path": "content/3/e00013/F4/F10"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 7.",
                  "doi": "10.7554/eLife.00013.019",
                  "path": "content/3/e00013/F4/F11"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 8.",
                  "doi": "10.7554/eLife.00013.020",
                  "path": "content/3/e00013/F4/F12"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 9.",
                  "doi": "10.7554/eLife.00013.021",
                  "path": "content/3/e00013/F4/F13"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 10.",
                  "doi": "10.7554/eLife.00013.022",
                  "path": "content/3/e00013/F4/F14"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 11.",
                  "doi": "10.7554/eLife.00013.023",
                  "path": "content/3/e00013/F4/F15"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 12.",
                  "doi": "10.7554/eLife.00013.024",
                  "path": "content/3/e00013/F4/F16"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 13.",
                  "doi": "10.7554/eLife.00013.025",
                  "path": "content/3/e00013/F4/F17"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 14.",
                  "doi": "10.7554/eLife.00013.026",
                  "path": "content/3/e00013/F4/F18"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 15.",
                  "doi": "10.7554/eLife.00013.027",
                  "path": "content/3/e00013/F4/F19"
                }
              ]
            },
            {
              "type": "table-wrap",
              "title": "Table 3.",
              "doi": "10.7554/eLife.00013.028",
              "path": "content/3/e00013/T3"
            },
            {
              "type": "fig",
              "title": "Figure 4.",
              "doi": "10.7554/eLife.00013.029",
              "path": "content/3/e00013/F20",
              "fragments": [
                {
                  "type": "fig",
                  "title": "Figure 4—figure supplement 1.",
                  "doi": "10.7554/eLife.00013.030",
                  "path": "content/3/e00013/F20/F21"
                }
              ]
            },
            {
              "type": "supplementary-material",
              "title": "Supplementary file 1.",
              "doi": "10.7554/eLife.00013.031",
              "path": "content/3/e00013/DC3"
            },
            {
              "type": "supplementary-material",
              "title": "Supplementary file 2.",
              "doi": "10.7554/eLife.00013.032",
              "path": "content/3/e00013/DC4"
            },
            {
              "type": "supplementary-material",
              "title": "Supplementary file 3.",
              "doi": "10.7554/eLife.00013.033",
              "path": "content/3/e00013/DC5"
            },
            {
              "type": "fig",
              "title": "Appendix 1 Figure 1 8.",
              "doi": "10.7554/eLife.00013.034",
              "path": "content/3/e00013/F22"
            },
            {
              "type": "fig",
              "title": "Appendix 2 Figure 1",
              "doi": "10.7554/eLife.00013.035",
              "path": "content/3/e00013/F23"
            },
            {
              "type": "fig",
              "title": "Appendix 2 Figure 2",
              "doi": "10.7554/eLife.00013.036",
              "path": "content/3/e00013/F24"
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
                  "path": "content/3/e00013/2/F25"
                },
                {
                  "type": "table-wrap",
                  "title": "Author response table 1.",
                  "doi": "10.7554/eLife.00013.039",
                  "path": "content/3/e00013/2/T4"
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
              "path": "content/3/e00013/F1",
              "fragments": [
                {
                  "type": "supplementary-material",
                  "title": "Figure 1—source data 1.",
                  "doi": "10.7554/eLife.00013.004",
                  "path": "content/3/e00013/F1/DC1"
                },
                {
                  "type": "fig",
                  "title": "Figure 1—figure supplement 1.",
                  "doi": "10.7554/eLife.00013.005",
                  "path": "content/3/e00013/F1/F2"
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
              "path": "content/3/e00013/T1",
              "fragments": [
                {
                  "type": "supplementary-material",
                  "title": "Table 1—source data 1.",
                  "doi": "10.7554/eLife.00013.008",
                  "path": "content/3/e00013/T1/DC2"
                }
              ]
            },
            {
              "type": "boxed-text",
              "title": "Box 1.",
              "doi": "10.7554/eLife.00013.009",
              "path": "content/3/e00013/B1"
            },
            {
              "type": "fig",
              "title": "Figure 2.",
              "doi": "10.7554/eLife.00013.010",
              "path": "content/3/e00013/F3"
            },
            {
              "type": "table-wrap",
              "title": "Table 2.",
              "doi": "10.7554/eLife.00013.011",
              "path": "content/3/e00013/T2"
            },
            {
              "type": "fig",
              "title": "Figure 3.",
              "doi": "10.7554/eLife.00013.012",
              "path": "content/3/e00013/F4",
              "fragments": [
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 1.",
                  "doi": "10.7554/eLife.00013.013",
                  "path": "content/3/e00013/F4/F5"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 2.",
                  "doi": "10.7554/eLife.00013.014",
                  "path": "content/3/e00013/F4/F6"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 3.",
                  "doi": "10.7554/eLife.00013.015",
                  "path": "content/3/e00013/F4/F7"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 4.",
                  "doi": "10.7554/eLife.00013.016",
                  "path": "content/3/e00013/F4/F8"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 5.",
                  "doi": "10.7554/eLife.00013.017",
                  "path": "content/3/e00013/F4/F9"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 6.",
                  "doi": "10.7554/eLife.00013.018",
                  "path": "content/3/e00013/F4/F10"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 7.",
                  "doi": "10.7554/eLife.00013.019",
                  "path": "content/3/e00013/F4/F11"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 8.",
                  "doi": "10.7554/eLife.00013.020",
                  "path": "content/3/e00013/F4/F12"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 9.",
                  "doi": "10.7554/eLife.00013.021",
                  "path": "content/3/e00013/F4/F13"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 10.",
                  "doi": "10.7554/eLife.00013.022",
                  "path": "content/3/e00013/F4/F14"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 11.",
                  "doi": "10.7554/eLife.00013.023",
                  "path": "content/3/e00013/F4/F15"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 12.",
                  "doi": "10.7554/eLife.00013.024",
                  "path": "content/3/e00013/F4/F16"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 13.",
                  "doi": "10.7554/eLife.00013.025",
                  "path": "content/3/e00013/F4/F17"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 14.",
                  "doi": "10.7554/eLife.00013.026",
                  "path": "content/3/e00013/F4/F18"
                },
                {
                  "type": "fig",
                  "title": "Figure 3—figure supplement 15.",
                  "doi": "10.7554/eLife.00013.027",
                  "path": "content/3/e00013/F4/F19"
                }
              ]
            },
            {
              "type": "table-wrap",
              "title": "Table 3.",
              "doi": "10.7554/eLife.00013.028",
              "path": "content/3/e00013/T3"
            },
            {
              "type": "fig",
              "title": "Figure 4.",
              "doi": "10.7554/eLife.00013.029",
              "path": "content/3/e00013/F20",
              "fragments": [
                {
                  "type": "fig",
                  "title": "Figure 4—figure supplement 1.",
                  "doi": "10.7554/eLife.00013.030",
                  "path": "content/3/e00013/F20/F21"
                }
              ]
            },
            {
              "type": "supplementary-material",
              "title": "Supplementary file 1.",
              "doi": "10.7554/eLife.00013.031",
              "path": "content/3/e00013/DC3"
            },
            {
              "type": "supplementary-material",
              "title": "Supplementary file 2.",
              "doi": "10.7554/eLife.00013.032",
              "path": "content/3/e00013/DC4"
            },
            {
              "type": "supplementary-material",
              "title": "Supplementary file 3.",
              "doi": "10.7554/eLife.00013.033",
              "path": "content/3/e00013/DC5"
            },
            {
              "type": "fig",
              "title": "Appendix 1 Figure 1 8.",
              "doi": "10.7554/eLife.00013.034",
              "path": "content/3/e00013/F22"
            },
            {
              "type": "fig",
              "title": "Appendix 2 Figure 1",
              "doi": "10.7554/eLife.00013.035",
              "path": "content/3/e00013/F23"
            },
            {
              "type": "fig",
              "title": "Appendix 2 Figure 2",
              "doi": "10.7554/eLife.00013.036",
              "path": "content/3/e00013/F24"
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
                  "path": "content/3/e00013/2/F25"
                },
                {
                  "type": "table-wrap",
                  "title": "Author response table 1.",
                  "doi": "10.7554/eLife.00013.039",
                  "path": "content/3/e00013/2/T4"
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
          "version": "1",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "article-id": "10.7554/eLife.05224",
          "article-version-id": "05224",
          "pub-date": "1979-08-17",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1",
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
            }
          ]
        }
      """
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05224",
          "version": "1",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "article-id": "10.7554/eLife.05224",
          "article-version-id": "05224",
          "pub-date": "1979-08-17",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1",
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
            }
          ]
        }
      """

  Scenario: Load an article with fragments with no title
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05224",
          "version": "1",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "article-id": "10.7554/eLife.05224",
          "article-version-id": "05224",
          "pub-date": "1979-08-17",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1",
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
              "doi": "10.7554/eLife.00013.003",
              "path": "content/3/e00013/F1"
            }
          ]
        }
      """
    And the response code should be 200
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
              "title": "Figure",
              "doi": "10.7554/eLife.00013.003",
              "path": "content/3/e00013/F1"
            }
          ]
        }
      """
