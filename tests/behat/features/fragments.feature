Feature: Navigate to fragment pages
  In order to see fragment pages
  As a user
  I should be able to use fragment uri to navigate to fragments

  Background:
    Given there is an article:
    """
      {
        "title":"VOR 05224 v2",
        "version":"2",
        "doi":"10.7554/eLife.05224",
        "volume":"4",
        "elocation-id":"e05224",
        "article-id":"05224",
        "article-version-id":"05224.2",
        "pub-date":"1979-08-17",
        "path":"content/4/e05224v2",
        "fragments":[
          {
            "path":"content/4/e05224v2/abstract",
            "doi":"10.7554/eLife.05224.001",
            "type":"abstract"
          },
          {
            "path":"content/4/e05224v2/abstract2",
            "doi":"10.7554/eLife.05224.002",
            "type":"abstract",
            "title":"eLife digest"
          },
          {
            "path":"content/4/e05224v2/figure1",
            "doi":"10.7554/eLife.05224.003",
            "type":"fig",
            "title":"Figure 1."
          },
          {
            "path":"content/4/e05224v2/figure2",
            "doi":"10.7554/eLife.05224.004",
            "type":"fig",
            "title":"Figure 2."
          },
          {
            "path":"content/4/e05224v2/figure3",
            "fragments":[
              {
                "path":"content/4/e05224v2/figure3/figure-supp1",
                "doi":"10.7554/eLife.05224.006",
                "type":"fig",
                "title":"Figure 3\u2014figure supplement 1."
              },
              {
                "path":"content/4/e05224v2/figure3/figure-supp2",
                "doi":"10.7554/eLife.05224.007",
                "type":"fig",
                "title":"Figure 3\u2014figure supplement 2."
              },
              {
                "path":"content/4/e05224v2/figure3/figure-supp3",
                "doi":"10.7554/eLife.05224.008",
                "type":"fig",
                "title":"Figure 3\u2014figure supplement 3."
              }
            ],
            "doi":"10.7554/eLife.05224.005",
            "type":"fig",
            "title":"Figure 3."
          },
          {
            "path":"content/4/e05224v2/figure4",
            "doi":"10.7554/eLife.05224.009",
            "type":"fig",
            "title":"Figure 4."
          },
          {
            "path":"content/4/e05224v2/figure5",
            "doi":"10.7554/eLife.05224.010",
            "type":"fig",
            "title":"Figure 5."
          },
          {
            "path":"content/4/e05224v2/figure6",
            "doi":"10.7554/eLife.05224.011",
            "type":"fig",
            "title":"Figure 6."
          },
          {
            "path": "content/4/e05224v2/supp-material1",
            "doi": "10.7554/eLife.05224.039",
            "type": "supplementary-material",
            "title": "Supplementary file 1."
          },
          {
            "path": "content/4/e05224v2/supp-material3",
            "doi": "10.7554/eLife.05224.040",
            "type": "supplementary-material",
            "title": "Supplementary file 3."
          },
          {
            "path":"content/4/e05224v2/decision",
            "doi":"10.7554/eLife.05224.012",
            "type":"sub-article",
            "contributors":[
              {
                "surname":"Kolter",
                "given-names":"Roberto",
                "role":"Reviewing editor",
                "affiliations":[
                  {
                    "country":"United States",
                    "institution":"Harvard Medical School"
                  }
                ],
                "type":"editor"
              }
            ],
            "title":"Decision letter"
          },
          {
            "path":"content/4/e05224v2/response",
            "doi":"10.7554/eLife.05224.013",
            "type":"sub-article",
            "title":"Author response"
          }
        ],
        "article-type":"research-article",
        "status":"VOR",
        "publish":"1",
        "keywords":{
          "author-keywords":[
            "Algoriphagus"
          ]
        }
      }
    """
  #Scenario outline with examples increases the duration of run so simple scenario is being used here
  Scenario: Fragment uri navigates to fragment pages
    When I go to "content/4/e05224v2/abstract"
    Then the response status code should be 200
    When I go to "content/4/e05224v2/abstract2"
    Then the response status code should be 200
    When I go to "content/4/e05224v2/figure1"
    Then the response status code should be 200
    When I go to "content/4/e05224v2/figure2"
    Then the response status code should be 200
    When I go to "content/4/e05224v2/figure3"
    Then the response status code should be 200
    When I go to "content/4/e05224v2/figure6"
    Then the response status code should be 200
    When I go to "content/4/e05224v2/figure3/figure-supp1"
    Then the response status code should be 200
    When I go to "content/4/e05224v2/figure3/figure-supp3"
    Then the response status code should be 200
    When I go to "content/4/e05224v2/decision"
    Then the response status code should be 200
    When I go to "content/4/e05224v2/response"
    Then the response status code should be 200
    When I go to "content/4/e05224v2/supp-material1"
    Then the response status code should be 200
    When I go to "content/4/e05224v2/supp-material3"
    Then the response status code should be 200

  Scenario: Invalid Fragment uri should return 404
    When I go to "content/4/e05224v2/figure7"
    Then the response status code should be 404
    When I go to "content/4/e05224v1/supp-material3"
    Then the response status code should be 404
