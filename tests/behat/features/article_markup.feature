@api @markup
Feature: Markup
  In order to easily read the research
  As a reader of the site
  I need to have access to the rendered articles

  Background:
    Given the markup service is available
    And there are articles:
    """
        [
          {
            "title": "VOR 05224 v2",
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
            "keywords": {
              "author-keywords": [
                "Algoriphagus"
              ]
            }
          },
          {
            "title": "The genome sequence of the colonial chordate, <italic>Botryllus schlosseri</italic>",
            "version": 1,
            "doi": "10.7554/eLife.03981",
            "volume": 3,
            "elocation-id": "e03981",
            "article-id": "03981",
            "article-version-id": "03981.1",
            "pub-date": "1979-08-17T00:00:00+00:00",
            "path": "content/3/e03981v1",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true,
            "keywords": {
              "author-keywords": [
                "social behavior",
                "gut microbiome",
                "metagenomics",
                "transmission",
                "social network"
                ]
              }
            }
            ,
            {
            "title": "Rapid localized spread and immunologic containment define Herpes simplex virus-2 reactivation in the human genital tract",
            "version": 1,
            "doi": "10.7554/eLife.00288",
            "volume": 2,
            "elocation-id": "e00288",
            "article-id": "00288",
            "article-version-id": "00288.1",
            "pub-date": "1979-08-17T00:00:00+00:00",
            "path": "content/2/e00288v1",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true,
            "keywords": {
              "author-keywords": [
                "Xenopus",
                "embryogenesis"
                                 ]
                         }
            }
        ]
      """

  Scenario: Article page displays the appropriate content on the article page
    When the search index is updated
    Then I visit "content/4/e05224v2"
    Then I should see "diet, kinship, and shared environments" in the "#abstract" element
    And I should see 1 "#abstract" element
    And I should see 1 "#digest" element
    And I should see 1 "#main-text" element
    And I should see 1 "#references" element
    And I should see 1 "#acknowledgements" element
    And I should see 1 "#decision-letter" element
    And I should see 1 "#author-response" element
  
  Scenario: Article does not have author-response and decision letter section
    Then I visit "content/3/e03981v1"
    Then I should see "scientific communities and scientific journals" in the "#abstract" element
    And I should see 1 "#abstract" element
    And I should not see an "#digest" element
    And I should see 1 "#main-text" element
    And I should see 1 "#references" element
    And I should not see an "#acknowledgements" element
    And I should not see an "#decision-letter" element
    And I should not see an "#author-response" element

  Scenario: Article displays appropriate content in main-text
    Then I visit "content/2/e00288v1"
    When the search index is updated
    And I should see "Introduction" in the "#main-text" element
    And I should see "Results" in the "#main-text" element
    And I should see "Discussion" in the "#main-text" element
    And I should see "Materials and methods" in the "#main-text" element
    Then I should see "The model reproduced heterogeneity in shedding episode duration and viral production" in the "#abstract" element
    Then I should see "sampling from blood may reflect true host–pathogen dynamics due to homogeneous mixing of viruses" in the "#main-text" element

  Scenario: Searching articles with text available in abstract section
    When the search index is updated
    Given I am on "/search"
    And I fill in "Search for..." with "scientific communities and scientific journals"
    And I press the Search button
    And I should see "The genome sequence of the colonial chordate,"
    And I fill in "Search for..." with "diet, kinship, and shared environments"
    And I press the Search button
    And I should see "VOR 05224 v2"
    And I should not see "the genome sequence"
    And I fill in "Search for..." with "sampling from blood may reflect true host–pathogen dynamics"
    And I press the Search button
    And I should not see "VOR 05224 v2"
    And I should not see "the genome sequence"
    And I fill in "Search for..." with "££$%^&"
    And I press the Search button
    And I should see "Your search yielded no results."

  Scenario: Searching articles with text available in main section
    When the search index is updated
    Given I am on "/search"
    And I fill in "Search for..." with " dynamics of most chronic viral infections"
    And I press the Search button
    And I should see "Rapid localized spread and immunologic containment define Herpes simplex virus-2 reactivation in the human genital tract"
    And I fill in "Search for..." with "Irreproducible studies that side-track fields"
    And I press the Search button
    And I should see "The genome sequence of the colonial chordate"
    And I should not see "VOR 05224 v2"
    And I fill in "Search for..." with "sampling from blood may reflect true host–pathogen dynamics"
    And I press the Search button
    And I should not see "VOR 05224 v2"
    And I should not see "the genome sequence"

  @javascript
  Scenario: Fragment tables should be collapsed by default
    Given there is an article:
      """
        {
          "article-type": "research-article",
          "title": "Global, quantitative and dynamic mapping of protein subcellular localization",
          "status": "VOR",
          "publish": true,
          "doi": "10.7554/eLife.16950",
          "pub-date": "2016-06-09T00:00:00+00:00",
          "volume": 5,
          "elocation-id": "e16950",
          "path": "content/5/e16950v3",
          "article-id": "16950",
          "impact-statement": "A spatial proteomics method can capture physiological protein subcellular localization changes in response to a stimulus, resolving all major organelles.",
          "keywords": {
            "author-keywords": [
              "spatial proteomics",
              "organellar proteomics",
              "EGF signalling",
              "map of the cell",
              "subcellular localization",
              "protein translocations"
            ],
            "research-organism": [
              "Human"
            ]
          },
          "categories": {
            "display-channel": [
              "Tools and Resources"
            ],
            "heading": [
              "Cell Biology",
              "Computational and Systems Biology"
            ]
          },
          "contributors": [
            {
              "type": "author",
              "surname": "Itzhak",
              "given-names": "Daniel N",
              "id": "author-56297",
              "references": {
                "affiliation": [
                  "aff1"
                ],
                "funding": [
                  "par-2",
                  "par-3"
                ],
                "contribution": [
                  "con1"
                ],
                "competing-interest": [
                  "conf1"
                ]
              }
            },
            {
              "type": "author",
              "surname": "Tyanova",
              "given-names": "Stefka",
              "id": "author-56298",
              "references": {
                "affiliation": [
                  "aff1"
                ],
                "funding": [
                  "par-3"
                ],
                "contribution": [
                  "con2"
                ],
                "competing-interest": [
                  "conf1"
                ]
              }
            },
            {
              "type": "author",
              "surname": "Cox",
              "given-names": "Jürgen",
              "id": "author-56299",
              "references": {
                "affiliation": [
                  "aff1"
                ],
                "funding": [
                  "par-3"
                ],
                "contribution": [
                  "con3"
                ],
                "competing-interest": [
                  "conf1"
                ]
              }
            },
            {
              "type": "author",
              "surname": "Borner",
              "given-names": "Georg HH",
              "id": "author-55412",
              "corresp": true,
              "orcid": "http://orcid.org/0000-0002-3166-3435",
              "references": {
                "affiliation": [
                  "aff1"
                ],
                "email": [
                  "cor1"
                ],
                "funding": [
                  "par-1",
                  "par-3"
                ],
                "contribution": [
                  "con4"
                ],
                "competing-interest": [
                  "conf1"
                ]
              }
            },
            {
              "type": "editor",
              "surname": "Hegde",
              "given-names": "Ramanujan S",
              "affiliations": [
                {
                  "institution": "MRC Laboratory of Molecular Biology",
                  "country": "United Kingdom"
                }
              ]
            }
          ],
          "referenced": {
            "affiliation": {
              "aff1": {
                "dept": "Department of Proteomics and Signal Transduction",
                "institution": "Max Planck Institute of Biochemistry",
                "city": "Martinsried",
                "country": "Germany"
              },
              "aff2": {
                "institution": "MRC Laboratory of Molecular Biology",
                "country": "United Kingdom"
              },
              "aff3": {
                "institution": "MRC Laboratory of Molecular Biology",
                "country": "United Kingdom"
              }
            },
            "email": {
              "cor1": "borner@biochem.mpg.de"
            },
            "funding": {
              "par-1": {
                "id": "http://dx.doi.org/10.13039/501100001659",
                "id-type": "FundRef",
                "institution": "Deutsche Forschungsgemeinschaft",
                "award-id": "Gottfried Wilhelm Leibniz Preis"
              },
              "par-2": {
                "id": "http://dx.doi.org/10.13039/501100001706",
                "id-type": "FundRef",
                "institution": "Louis-Jeantet Foundation"
              },
              "par-3": {
                "id": "http://dx.doi.org/10.13039/501100004189",
                "id-type": "FundRef",
                "institution": "Max-Planck-Gesellschaft"
              }
            },
            "contribution": {
              "con1": "DNI, Conceptualization, Methodology, Experiments, Writing, Visualization, Investigation",
              "con2": "ST, Software, Website",
              "con3": "JC, Software",
              "con4": "GHHB, Conceptualization, Methodology, Formal Analysis, Writing, Supervision"
            },
            "competing-interest": {
              "conf1": "The authors declare that no competing interests exist."
            }
          },
          "fragments": [
            {
              "type": "abstract",
              "doi": "10.7554/eLife.16950.001",
              "path": "content/5/e16950v3/abstract"
            },
            {
              "type": "abstract",
              "doi": "10.7554/eLife.16950.002",
              "title": "eLife digest",
              "path": "content/5/e16950v3/abstract2"
            },
            {
              "type": "fig",
              "doi": "10.7554/eLife.16950.003",
              "title": "Figure 1.",
              "fragments": [
                {
                  "type": "fig",
                  "doi": "10.7554/eLife.16950.004",
                  "title": "Figure 1—figure supplement 1.",
                  "path": "content/5/e16950v3/figure1/figure-supp1"
                }
              ],
              "path": "content/5/e16950v3/figure1"
            },
            {
              "type": "fig",
              "doi": "10.7554/eLife.16950.005",
              "title": "Figure 2.",
              "fragments": [
                {
                  "type": "fig",
                  "doi": "10.7554/eLife.16950.006",
                  "title": "Figure 2—figure supplement 1.",
                  "path": "content/5/e16950v3/figure2/figure-supp1"
                },
                {
                  "type": "fig",
                  "doi": "10.7554/eLife.16950.007",
                  "title": "Figure 2—figure supplement 2.",
                  "path": "content/5/e16950v3/figure2/figure-supp2"
                }
              ],
              "path": "content/5/e16950v3/figure2"
            },
            {
              "type": "table-wrap",
              "doi": "10.7554/eLife.16950.008",
              "title": "Table 1.",
              "path": "content/5/e16950v3/table1"
            },
            {
              "type": "fig",
              "doi": "10.7554/eLife.16950.009",
              "title": "Figure 3.",
              "path": "content/5/e16950v3/figure3"
            },
            {
              "type": "fig",
              "doi": "10.7554/eLife.16950.010",
              "title": "Figure 4.",
              "fragments": [
                {
                  "type": "fig",
                  "doi": "10.7554/eLife.16950.011",
                  "title": "Figure 4—figure supplement 1.",
                  "path": "content/5/e16950v3/figure4/figure-supp1"
                },
                {
                  "type": "fig",
                  "doi": "10.7554/eLife.16950.012",
                  "title": "Figure 4—figure supplement 2.",
                  "path": "content/5/e16950v3/figure4/figure-supp2"
                },
                {
                  "type": "fig",
                  "doi": "10.7554/eLife.16950.013",
                  "title": "Figure 4—figure supplement 3.",
                  "path": "content/5/e16950v3/figure4/figure-supp3"
                }
              ],
              "path": "content/5/e16950v3/figure4"
            },
            {
              "type": "fig",
              "doi": "10.7554/eLife.16950.014",
              "title": "Figure 5.",
              "path": "content/5/e16950v3/figure5"
            },
            {
              "type": "supplementary-material",
              "doi": "10.7554/eLife.16950.015",
              "title": "Supplementary file 1.",
              "path": "content/5/e16950v3/supp-material1"
            },
            {
              "type": "supplementary-material",
              "doi": "10.7554/eLife.16950.016",
              "title": "Supplementary file 2.",
              "path": "content/5/e16950v3/supp-material2"
            },
            {
              "type": "supplementary-material",
              "doi": "10.7554/eLife.16950.017",
              "title": "Supplementary file 3.",
              "path": "content/5/e16950v3/supp-material3"
            },
            {
              "type": "supplementary-material",
              "doi": "10.7554/eLife.16950.018",
              "title": "Supplementary file 4.",
              "path": "content/5/e16950v3/supp-material4"
            },
            {
              "type": "supplementary-material",
              "doi": "10.7554/eLife.16950.019",
              "title": "Supplementary file 5.",
              "path": "content/5/e16950v3/supp-material5"
            },
            {
              "type": "supplementary-material",
              "doi": "10.7554/eLife.16950.020",
              "title": "Supplementary file 6.",
              "path": "content/5/e16950v3/supp-material6"
            },
            {
              "type": "supplementary-material",
              "doi": "10.7554/eLife.16950.021",
              "title": "Supplementary file 7.",
              "path": "content/5/e16950v3/supp-material7"
            },
            {
              "type": "supplementary-material",
              "doi": "10.7554/eLife.16950.022",
              "title": "Supplementary file 8.",
              "path": "content/5/e16950v3/supp-material8"
            },
            {
              "type": "supplementary-material",
              "doi": "10.7554/eLife.16950.023",
              "title": "Supplementary file 9.",
              "path": "content/5/e16950v3/supp-material9"
            },
            {
              "type": "supplementary-material",
              "doi": "10.7554/eLife.16950.024",
              "title": "Supplementary file 10.",
              "path": "content/5/e16950v3/supp-material10"
            },
            {
              "type": "sub-article",
              "doi": "10.7554/eLife.16950.025",
              "title": "Decision letter",
              "contributors": [
                {
                  "type": "editor",
                  "surname": "Hegde",
                  "given-names": "Ramanujan S",
                  "affiliations": [
                    {
                      "institution": "MRC Laboratory of Molecular Biology",
                      "country": "United Kingdom"
                    }
                  ]
                }
              ],
              "path": "content/5/e16950v3/decision"
            },
            {
              "type": "sub-article",
              "doi": "10.7554/eLife.16950.026",
              "title": "Author response",
              "path": "content/5/e16950v3/response"
            }
          ],
          "version": 3,
          "article-version-id": "16950.3"
        }
      """
    When I visit "content/5/e16950v3"
    Then I should see "Starting material: SILAC heavy and light labelled HeLa cells"
    And I should not see "All proteins predicted in this compartment"
