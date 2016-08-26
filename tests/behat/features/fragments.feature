Feature: Navigate to fragment pages
  In order to see fragment pages
  As a user
  I should be able to use fragment uri to navigate to fragments

  Background:
    Given there is an article:
    """
      {
        "title":"Social networks predict gut microbiome composition in wild baboons",
        "version":2,
        "doi":"10.7554/eLife.05224",
        "volume":4,
        "elocation-id":"e05224",
        "article-id":"05224",
        "article-version-id":"05224.2",
        "pub-date":"1979-08-17T00:00:00+00:00",
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
            "doi": "10.7554/eLife.05224.014",
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
            "fragments":[
              {
                "path":"content/4/e05224v2/response/figure-supp1",
                "doi":"10.7554/eLife.05224.014",
                "type":"fig",
                "title":"Response - figure supplement 1."
              }
              ],
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
    
  Scenario: Research articles-Fragment pages should have article title
    When I go to "content/4/e05224v2/abstract"
    Then I should see "Social networks predict gut microbiome composition in wild baboons" in the ".page-title" element
    Then I should see "Abstract"
    When I go to "content/4/e05224v2/figure1"
    Then I should see "Social networks predict gut microbiome composition in wild baboons" in the ".page-title" element
    Then I should see "Figure 1."
    When I go to "content/4/e05224v2/supp-material1"
    Then I should see "Social networks predict gut microbiome composition in wild baboons" in the ".page-title" element
    Then I should see "Supplementary file 1."
    When I go to "content/4/e05224v2/figure3/figure-supp1"
    Then I should see "Social networks predict gut microbiome composition in wild baboons" in the ".page-title" element
    Then I should see "Figure 3—figure supplement 1."
    When I go to "content/4/e05224v2/figure3/figure-supp3"
    Then I should see "Social networks predict gut microbiome composition in wild baboons" in the ".page-title" element
    Then I should see "Figure 3—figure supplement 3."
    When I go to "content/4/e05224v2/response/figure-supp1"
    Then I should see "Social networks predict gut microbiome composition in wild baboons" in the ".page-title" element
    Then I should see "Response - figure supplement 1."

  Scenario: Sub-articles fragment pages should have article title
    When I go to "content/4/e05224v2/response"
    Then I should see "Social networks predict gut microbiome composition in wild baboons" in the ".page-title" element
    Then I should see "Author response"
    When I go to "content/4/e05224v2/decision"
    Then I should see "Social networks predict gut microbiome composition in wild baboons" in the ".page-title" element
    Then I should see "Decision letter"

  Scenario: File extension with number
    Given the markup service is available
    When I go to "content/4/e05224v2/supp-material1"
    Then I should see "[supplementary-file-1.media-1.x1sx]" in the ".inline-linked-media-wrapper" element
    And I should see "http://parallel-elife-publishing-cdn.s3.amazonaws.com/05224/elife-05224-supp1-v2-download.x1sx" in the "href" attribute of the ".inline-linked-media-wrapper a" element

  Scenario: Fragment pages in editorial
    Given there is an article:
    """
      {
        "status": "VOR",
        "article-type": "editorial",
        "contributors": [
          {
            "surname": "Schekman",
            "given-names": "Randy",
            "role": "Editor-in-Chief",
            "references": {
              "competing-interest": [
                "conf1"
              ]
            },
            "type": "author",
            "id": "author-1032"
          },
          {
            "surname": "Patterson",
            "corresp": true,
            "id": "author-1002",
            "given-names": "Mark",
            "role": "Executive Director",
            "references": {
              "competing-interest": [
                "conf1"
              ]
            },
            "type": "author",
            "email": "editorial@elifesciences.org"
          }
        ],
        "pub-date": "2013-05-16T00:00:00+00:00",
        "title": "Reforming research assessment",
        "elocation-id": "e00855",
        "publish": true,
        "article-version-id": "00855.1",
        "volume": 2,
        "keywords": {
          "author-keywords": [
            "research assessment",
            "science policy",
            "scientific publishing",
            "publishing",
            "eLife"
          ]
        },
        "doi": "10.7554/eLife.00855",
        "version": 1,
        "referenced": {
          "competing-interest": {
            "conf1": "RS and MP attended the initial meeting at the ASCB annual meeting in San Francisco that led to the creation of the Declaration on Research Assessment and participated in its drafting."
          }
        },
        "path": "content/2/e00855v1",
        "fragments":[
          {
            "path":"content/4/e00855v1/abstract",
            "doi":"10.7554/eLife.00855.001",
            "type":"abstract"
          }
          ],
        "article-id": "00855",
        "categories": {
          "sub-display-channel": [
            "Science policy"
          ],
          "display-channel": [
            "Editorial"
          ]
        }
      }
    """
    When I go to "content/4/e00855v1/abstract"
    Then I should see "Reforming research assessment"
    Then I should see "Abstract"

  Scenario: Fragments in Short Reports
    Given there is an article:
    """
      {
      "status": "VOR",
      "article-type": "research-article",
      "contributors": [
        {
          "surname": "Descostes",
          "given-names": "Nicolas",
          "equal-contrib": true,
          "type": "author",
          "id": "author-9814"
        },
        {
          "surname": "Heidemann",
          "given-names": "Martin",
          "equal-contrib": true,
          "type": "author",
          "id": "author-9994"
        },
        {
          "type": "author",
          "given-names": "Lionel",
          "surname": "Spinelli",
          "id": "author-9995"
        },
        {
          "type": "author",
          "given-names": "Roland",
          "surname": "Sch\u00fcller",
          "id": "author-10007"
        }
      ],
      "pub-date": "2014-05-09T00:00:00+00:00",
      "title": "Tyrosine phosphorylation of RNA polymerase II CTD is associated with antisense promoter transcription and active enhancers in mammalian cells",
      "elocation-id": "e02105",
      "publish": true,
      "article-version-id": "02105.1",
      "volume": 3,
      "keywords": {
        "author-keywords": [
          "RNA polymerase II",
          "carboxyl terminal domain",
          "antisense transcription",
          "enhancers",
          "initiation",
          "transcription"
        ],
        "research-organism": [
          "human"
        ]
      },
      "doi": "10.7554/eLife.02105",
      "version": 1,
      "path": "content/3/e02105v1",
      "fragments": [
        {
          "path": "content/3/e02105v1/abstract",
          "doi": "10.7554/eLife.02105.001",
          "type": "abstract"
        },
        {
          "path": "content/3/e02105v1/abstract2",
          "doi": "10.7554/eLife.02105.002",
          "type": "abstract",
          "title": "eLife digest"
        },
        {
          "path": "content/3/e02105v1/figure1",
          "fragments": [
            {
              "path": "content/3/e02105v1/figure1/figure-supp1",
              "doi": "10.7554/eLife.02105.004",
              "type": "fig",
              "title": "Figure 1\u2014figure supplement 1."
            }
          ],
          "doi": "10.7554/eLife.02105.003",
          "type": "fig",
          "title": "Figure 1."
        },
        {
          "path": "content/3/e02105v1/table1",
          "doi": "10.7554/eLife.02105.021",
          "type": "table-wrap",
          "title": "Table 1."
        }
      ],
      "article-id": "02105",
      "categories": {
        "heading": [
            "Genes and chromosomes",
            "Genomics and evolutionary biology"
          ],
        "display-channel": [
            "Short report"
        ]
      }
      }
    """
    When I go to "content/3/e02105v1/abstract"
    Then I should see "Tyrosine phosphorylation of RNA polymerase II CTD is associated with antisense promoter transcription and active enhancers in mammalian cells"
    Then I should see "Abstract"
    When I go to "content/3/e02105v1/abstract2"
    Then I should see "Tyrosine phosphorylation of RNA polymerase II CTD is associated with antisense promoter transcription and active enhancers in mammalian cells"
    Then I should see "eLife digest"
    When I go to "content/3/e02105v1/figure1"
    Then I should see "Tyrosine phosphorylation of RNA polymerase II CTD is associated with antisense promoter transcription and active enhancers in mammalian cells"
    Then I should see "Figure 1."
    When I go to "content/3/e02105v1/table1"
    Then I should see "Tyrosine phosphorylation of RNA polymerase II CTD is associated with antisense promoter transcription and active enhancers in mammalian cells"
    Then I should see "Table 1."
    
  Scenario: Fragment pages in Insight
    Given there is an article:
    """
      {
      "status": "VOR",
      "article-type": "article-commentary",
      "pub-date": "2013-08-08T00:00:00+00:00",
      "title": "Caught in the act",
      "impact-statement": "",
      "elocation-id": "e01127",
      "publish": true,
      "article-version-id": "01127.1",
      "volume": 2,
      "doi": "10.7554/eLife.01127",
      "version": 1,
      "path": "content/2/e01127v1",
      "fragments": [
        {
          "path": "content/2/e01127v1/abstract",
          "doi": "10.7554/eLife.01127.001",
          "type": "abstract"
        }
        ],
      "article-id": "01127",
      "categories": {
        "heading": [
            "Genes and chromosomes",
            "Genomics and evolutionary biology"
          ],
        "display-channel": [
            "Insight"
        ]
      }
      }
    """
    When I go to "content/2/e01127v1/abstract"
    Then I should see "Caught in the act" in the ".page-title" element
    Then I should see "Abstract"

  Scenario: Fragment pages in feature articles
    Given there is an article:
    """
      {
      "status": "VOR",
      "article-type": "article-commentary",
      "pub-date": "2013-08-08T00:00:00+00:00",
      "title": "Caught in the act",
      "impact-statement": "",
      "elocation-id": "e01128",
      "publish": true,
      "article-version-id": "01128.1",
      "volume": 2,
      "doi": "10.7554/eLife.01128",
      "version": 1,
      "path": "content/2/e01128v1",
      "fragments": [
        {
          "path": "content/2/e01128v1/abstract",
          "doi": "10.7554/eLife.01128.001",
          "type": "abstract"
        }
        ],
      "article-id": "01128",
      "categories": {
        "heading": [
            "Genes and chromosomes",
            "Genomics and evolutionary biology"
          ],
        "display-channel": [
            "feature-article"
        ]
      }
      }
    """
    When I go to "content/2/e01128v1/abstract"
    Then I should see "Caught in the act" in the ".page-title" element
    Then I should see "Abstract"

  Scenario: Fragments in Tools and resources
    Given there is an article:
    """
    {
      "status": "VOR",
      "article-type": "research-article",
      "contributors": [
        {
          "surname": "Jonas",
          "corresp": true,
          "given-names": "Eric",
          "type": "author",
          "id": "author-17193"
        },
        {
          "type": "author",
          "given-names": "Konrad",
          "surname": "Kording",
          "id": "author-17688"
        },
        {
          "surname": "Skinner",
          "affiliations": [
            {
              "country": "Canada",
              "institution": "University Health Network, and University of Toronto"
            }
          ],
          "given-names": "Frances K",
          "role": "Reviewing editor",
          "type": "editor",
          "id": "author-14764"
        }
      ],
      "pub-date": "2015-04-30T00:00:00+00:00",
      "title": "Automatic discovery of cell types and microcircuitry from neural connectomics",
      "elocation-id": "e04250",
      "publish": true,
      "article-version-id": "04250.1",
      "volume": 4,
      "doi": "10.7554/eLife.04250",
      "version": 1,
      "path": "content/4/e04250v1",
      "fragments": [
        {
          "path": "content/4/e04250v1/abstract",
          "doi": "10.7554/eLife.04250.001",
          "type": "abstract"
        },
        {
          "path": "content/4/e04250v1/abstract2",
          "doi": "10.7554/eLife.04250.002",
          "type": "abstract",
          "title": "eLife digest"
        },
        {
          "path": "content/4/e04250v1/figure1",
          "doi": "10.7554/eLife.04250.010",
          "type": "fig",
          "title": "Figure 1."
        },
        {
          "path": "content/4/e04250v1/figure2",
          "doi": "10.7554/eLife.04250.003",
          "type": "fig",
          "title": "Figure 2."
        },
        {
          "path": "content/4/e04250v1/decision",
          "doi": "10.7554/eLife.04250.014",
          "type": "sub-article",
          "contributors": [
            {
              "surname": "Skinner",
              "given-names": "Frances K",
              "role": "Reviewing editor",
              "affiliations": [
                {
                  "country": "Canada",
                  "institution": "University Health Network, and University of Toronto"
                }
              ],
              "type": "editor"
            }
          ],
          "title": "Decision letter"
        },
        {
          "path": "content/4/e04250v1/response",
          "doi": "10.7554/eLife.04250.015",
          "type": "sub-article",
          "title": "Author response"
        }
      ],
      "article-id": "04250",
      "categories": {
        "heading": [
            "Genes and chromosomes",
            "Genomics and evolutionary biology"
          ],
        "display-channel": [
            "Tools and resources"
        ]
      }
    }
    """
    When I go to "content/4/e04250v1/abstract"
    Then I should see "Automatic discovery of cell types and microcircuitry from neural connectomics"
    Then I should see "Abstract"
    When I go to "content/4/e04250v1/abstract2"
    Then I should see "Automatic discovery of cell types and microcircuitry from neural connectomics"
    Then I should see "eLife digest"
    When I go to "content/4/e04250v1/figure1"
    Then I should see "Automatic discovery of cell types and microcircuitry from neural connectomics"
    Then I should see "Figure 1."
    When I go to "content/4/e04250v1/response"
    Then I should see "Automatic discovery of cell types and microcircuitry from neural connectomics"
    Then I should see "Author response"
    When I go to "content/4/e04250v1/decision"
    Then I should see "Automatic discovery of cell types and microcircuitry from neural connectomics"
    Then I should see "Decision letter"

  Scenario: Fragments in Research advance
    Given there is an article:
    """
      {
        "status": "VOR",
        "article-type": "research-article",
        "contributors": [
          {
            "type": "author",
            "given-names": "Liang",
            "surname": "Ge",
            "id": "author-5338"
          },
          {
            "type": "author",
            "given-names": "Min",
            "surname": "Zhang",
            "id": "author-5521"
          },
          {
            "surname": "Schekman",
            "corresp": true,
            "given-names": "Randy",
            "type": "author",
            "id": "author-1032"
          },
          {
            "surname": "Mizushima",
            "given-names": "Noboru",
            "role": "Reviewing editor",
            "type": "editor"
          }
        ],
        "pub-date": "2014-11-28T00:00:00+00:00",
        "title": "Phosphatidylinositol 3-kinase and COPII generate LC3 lipidation vesicles from the ER-Golgi intermediate compartment",
        "elocation-id": "e04135",
        "publish": true,
        "article-version-id": "04135.1",
        "volume": 3,
        "doi": "10.7554/eLife.04135",
        "version": 1,
        "path": "content/3/e04135v1",
        "fragments": [
          {
            "path": "content/3/e04135v1/abstract",
            "doi": "10.7554/eLife.04135.001",
            "type": "abstract"
          },
          {
            "path": "content/3/e04135v1/media1",
            "doi": "10.7554/eLife.04135.016",
            "type": "media",
            "title": "Video 1."
          },
          {
            "path": "content/3/e04135v1/decision",
            "doi": "10.7554/eLife.04135.017",
            "type": "sub-article",
            "contributors": [
              {
                "surname": "Mizushima",
                "given-names": "Noboru",
                "role": "Reviewing editor",
                "affiliations": [
                  {
                    "country": "Japan",
                    "institution": "The University of Tokyo"
                  }
                ],
                "type": "editor"
              }
            ],
            "title": "Decision letter"
          },
          {
            "path": "content/3/e04135v1/response",
            "doi": "10.7554/eLife.04135.018",
            "type": "sub-article",
            "title": "Author response"
          }
        ],
      "article-id": "04135"
    }
    """
    When I go to "content/3/e04135v1/abstract"
    Then I should see "Phosphatidylinositol 3-kinase and COPII generate LC3 lipidation vesicles from the ER-Golgi intermediate compartment"
    Then I should see "Abstract"
    When I go to "content/3/e04135v1/media1"
    Then I should see "Phosphatidylinositol 3-kinase and COPII generate LC3 lipidation vesicles from the ER-Golgi intermediate compartment"
    Then I should see "Video 1."
    When I go to "content/3/e04135v1/response"
    Then I should see "Phosphatidylinositol 3-kinase and COPII generate LC3 lipidation vesicles from the ER-Golgi intermediate compartment"
    Then I should see "Author response"
    When I go to "content/3/e04135v1/decision"
    Then I should see "Phosphatidylinositol 3-kinase and COPII generate LC3 lipidation vesicles from the ER-Golgi intermediate compartment"
    Then I should see "Decision letter"
