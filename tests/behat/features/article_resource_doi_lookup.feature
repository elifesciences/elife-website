Feature: Article Resource - DOI Lookup
  In order to avoid a trip to crossref and easily access the latest article version
  As a website user
  The internal doi links should redirect to the latest version of the article

  Background:
    Given redirects are not followed

  Scenario: Internal doi lookup redirects to latest published version of an article
    Given there are articles:
      """
        [
          {
            "title": "05224 POA v1",
            "version": 1,
            "doi": "10.7554/eLife.05224",
            "volume": 4,
            "elocation-id": "e05224",
            "article-id": "05224",
            "article-version-id": "05224.1",
            "pub-date": "1979-08-15T00:00:00+00:00",
            "update": "1979-08-15T00:00:00+00:00",
            "path": "content/4/e05224v1",
            "article-type": "research-article",
            "status": "POA",
            "publish": true
          },
          {
            "title": "05224 VOR v2",
            "version": 2,
            "doi": "10.7554/eLife.05224",
            "volume": 4,
            "elocation-id": "e05224",
            "article-id": "05224",
            "article-version-id": "05224.2",
            "pub-date": "1979-08-15T00:00:00+00:00",
            "update": "1979-08-16T00:00:00+00:00",
            "path": "content/4/e05224v2",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true
          },
          {
            "title": "05224 VOR v3",
            "version": 3,
            "doi": "10.7554/eLife.05224",
            "volume": 4,
            "elocation-id": "e05224",
            "article-id": "05224",
            "article-version-id": "05224.3",
            "pub-date": "1979-08-15T00:00:00+00:00",
            "update": "1979-08-17T00:00:00+00:00",
            "path": "content/4/e05224v3",
            "article-type": "research-article",
            "status": "VOR",
            "publish": false
          }
        ]
      """
    When I go to "lookup/doi/10.7554/eLife.05224"
    Then I should be redirected to "content/4/e05224v2" with a 302

    Given there is an article:
      """
        {
          "title": "05224 VOR v3",
          "version": 3,
          "doi": "10.7554/eLife.05224",
          "volume": 4,
          "elocation-id": "e05224",
          "article-id": "10.7554/eLife.05224",
          "article-version-id": "05224.3",
          "pub-date": "1979-08-15T00:00:00+00:00",
          "update": "1979-08-17T00:00:00+00:00",
          "path": "content/4/e05224v3",
          "article-type": "research-article",
          "status": "VOR",
          "publish": true
        }
      """
    When I go to "lookup/doi/10.7554/eLife.05224"
    Then I should be redirected to "content/4/e05224v3" with a 302

  Scenario: Internal doi lookup of fragments redirects to fragments of latest published version of an article
    Given there are articles:
    """
      [
        {
          "title":"VOR 05224 v1",
          "version":1,
          "doi":"10.7554/eLife.05224",
          "volume":4,
          "elocation-id":"e05224",
          "article-id":"05224",
          "article-version-id":"05224.1",
          "pub-date":"1979-08-17T00:00:00+00:00",
          "path":"content/4/e05224v1",
          "publish": true,
          "fragments":[
            {
              "path":"content/4/e05224v1/abstract",
              "doi":"10.7554/eLife.05224.001",
              "type":"abstract"
            },
            {
              "path":"content/4/e05224v1/abstract2",
              "doi":"10.7554/eLife.05224.002",
              "type":"abstract",
              "title":"eLife digest"
            },
            {
              "path":"content/4/e05224v1/figure1",
              "doi":"10.7554/eLife.05224.003",
              "type":"fig",
              "title":"Figure 1."
            },
            {
              "path":"content/4/e05224v1/figure2",
              "doi":"10.7554/eLife.05224.004",
              "type":"fig",
              "title":"Figure 2."
            },
            {
              "path":"content/4/e05224v1/figure3",
              "fragments":[
                {
                  "path":"content/4/e05224v1/figure3/figure-supp1",
                  "doi":"10.7554/eLife.05224.006",
                  "type":"fig",
                  "title":"Figure 3\u2014figure supplement 1."
                },
                {
                  "path":"content/4/e05224v1/figure3/figure-supp2",
                  "doi":"10.7554/eLife.05224.007",
                  "type":"fig",
                  "title":"Figure 3\u2014figure supplement 2."
                },
                {
                  "path":"content/4/e05224v1/figure3/figure-supp3",
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
              "path":"content/4/e05224v1/figure4",
              "doi":"10.7554/eLife.05224.009",
              "type":"fig",
              "title":"Figure 4."
            },
            {
              "path":"content/4/e05224v1/figure5",
              "doi":"10.7554/eLife.05224.010",
              "type":"fig",
              "title":"Figure 5."
            },
            {
              "path":"content/4/e05224v1/figure6",
              "doi":"10.7554/eLife.05224.011",
              "type":"fig",
              "title":"Figure 6."
            },
            {
              "path": "content/4/e05224v1/supp-material1",
              "doi": "10.7554/eLife.05224.039",
              "type": "supplementary-material",
              "title": "Supplementary file 1."
            },
            {
              "path": "content/4/e05224v1/supp-material3",
              "doi": "10.7554/eLife.05224.040",
              "type": "supplementary-material",
              "title": "Supplementary file 3."
            },
            {
              "path":"content/4/e05224v1/decision",
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
              "path":"content/4/e05224v1/response",
              "doi":"10.7554/eLife.05224.013",
              "type":"sub-article",
              "title":"Author response"
            }
          ],
          "article-type":"research-article",
          "status":"VOR",
          "publish":true,
          "keywords":{
            "author-keywords":[
              "Algoriphagus"
            ]
          }
        },
        {
          "title":"VOR 05224 v2",
          "version":2,
          "doi":"10.7554/eLife.05224",
          "volume":4,
          "elocation-id":"e05224",
          "article-id":"05224",
          "article-version-id":"05224.2",
          "pub-date":"1979-08-17T00:00:00+00:00",
          "path":"content/4/e05224v2",
          "publish": true,
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
          "publish":true,
          "keywords":{
            "author-keywords":[
              "Algoriphagus"
            ]
          }
        },
        {
          "title":"VOR 05224 v3",
          "version":3,
          "doi":"10.7554/eLife.05224v3",
          "volume":4,
          "elocation-id":"e05224",
          "article-id":"05224",
          "article-version-id":"05224.3",
          "pub-date":"1979-08-17T00:00:00+00:00",
          "path":"content/4/e05224v3",
          "publish": false,
          "fragments":[
            {
              "path":"content/4/e05224v3/abstract",
              "doi":"10.7554/eLife.05224.001",
              "type":"abstract"
            },
            {
              "path":"content/4/e05224v3/abstract2",
              "doi":"10.7554/eLife.05224.002",
              "type":"abstract",
              "title":"eLife digest"
            },
            {
              "path":"content/4/e05224v3/figure1",
              "doi":"10.7554/eLife.05224.003",
              "type":"fig",
              "title":"Figure 1."
            },
            {
              "path":"content/4/e05224v3/figure2",
              "doi":"10.7554/eLife.05224.004",
              "type":"fig",
              "title":"Figure 2."
            },
            {
              "path":"content/4/e05224v3/figure3",
              "fragments":[
                {
                  "path":"content/4/e05224v3/figure3/figure-supp1",
                  "doi":"10.7554/eLife.05224.006",
                  "type":"fig",
                  "title":"Figure 3\u2014figure supplement 1."
                },
                {
                  "path":"content/4/e05224v3/figure3/figure-supp2",
                  "doi":"10.7554/eLife.05224.007",
                  "type":"fig",
                  "title":"Figure 3\u2014figure supplement 2."
                },
                {
                  "path":"content/4/e05224v3/figure3/figure-supp3",
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
              "path":"content/4/e05224v3/figure4",
              "doi":"10.7554/eLife.05224.009",
              "type":"fig",
              "title":"Figure 4."
            },
            {
              "path":"content/4/e05224v3/figure5",
              "doi":"10.7554/eLife.05224.010",
              "type":"fig",
              "title":"Figure 5."
            },
            {
              "path":"content/4/e05224v3/figure6",
              "doi":"10.7554/eLife.05224.011",
              "type":"fig",
              "title":"Figure 6."
            },
            {
              "path": "content/4/e05224v3/supp-material1",
              "doi": "10.7554/eLife.05224.039",
              "type": "supplementary-material",
              "title": "Supplementary file 1."
            },
            {
              "path": "content/4/e05224v3/supp-material3",
              "doi": "10.7554/eLife.05224.040",
              "type": "supplementary-material",
              "title": "Supplementary file 3."
            },
            {
              "path":"content/4/e05224v3/decision",
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
              "path":"content/4/e05224v3/response",
              "doi":"10.7554/eLife.05224.013",
              "type":"sub-article",
              "title":"Author response"
            }
          ],
          "article-type":"research-article",
          "status":"VOR",
          "publish":true,
          "keywords":{
            "author-keywords":[
              "Algoriphagus"
            ]
          }
        }
       ]
    """
    When I go to "lookup/doi/10.7554/eLife.05224.001"
    Then I should be redirected to "content/4/e05224v2/abstract" with a 302
    When I go to "lookup/doi/10.7554/eLife.05224.002"
    Then I should be redirected to "content/4/e05224v2/abstract2" with a 302
    When I go to "lookup/doi/10.7554/eLife.05224.003"
    Then I should be redirected to "content/4/e05224v2/figure1" with a 302
    When I go to "lookup/doi/10.7554/eLife.05224.004"
    Then I should be redirected to "content/4/e05224v2/figure2" with a 302
    When I go to "lookup/doi/10.7554/eLife.05224.005"
    Then I should be redirected to "content/4/e05224v2/figure3" with a 302
    When I go to "lookup/doi/10.7554/eLife.05224.006"
    Then I should be redirected to "content/4/e05224v2/figure3/figure-supp1" with a 302
    When I go to "lookup/doi/10.7554/eLife.05224.007"
    Then I should be redirected to "content/4/e05224v2/figure3/figure-supp2" with a 302
    When I go to "lookup/doi/10.7554/eLife.05224.039"
    Then I should be redirected to "content/4/e05224v2/supp-material1" with a 302
    When I go to "lookup/doi/10.7554/eLife.05224.012"
    Then I should be redirected to "content/4/e05224v2/decision" with a 302
    When I go to "lookup/doi/10.7554/eLife.05224.013"
    Then I should be redirected to "content/4/e05224v2/response" with a 302
