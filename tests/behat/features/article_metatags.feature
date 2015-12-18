Feature: Article Metatags
  In order to enhance google search on the article
  As a developer
  I should be able to output expected Metadata on article page for eLife Journal site

  Background:
    Given the markup service is available
    And there is an article:
     """
      {
        "article-type": "research-article",
        "title": "Rapid localized spread and immunologic containment define Herpes simplex virus-2 reactivation in the human genital tract",
        "status": "VOR",
        "publish": true,
        "doi": "10.7554/eLife.00288",
        "pub-date": "2013-04-16T00:00:00+00:00",
        "volume": 2,
        "elocation-id": "e00288",
        "path": "content/2/e00288v1",
        "article-id": "00288",
        "impact-statement": "A combination of detailed sampling and mathematical modeling suggests that the response of immune cells to reactivation of herpes simplex virus 2 is extremely rapid and effective within microscopic areas of genital skin.",
        "keywords": {
          "author-keywords": [
            "Herpes simplex",
            "Mucosal immunity",
            "Mathematical modeling"
          ],
          "research-organism": [
            "Human",
            "Virus",
            "Other"
          ]
        },
        "categories": {
          "display-channel": [
            "Research Article"
          ],
          "heading": [
            "Immunology",
            "Microbiology and Infectious Disease"
          ]
        },
        "contributors": [
          {
            "type": "author",
            "surname": "Schiffer",
            "given-names": "Joshua T",
            "id": "author-1921",
            "corresp": true,
            "references": {
              "affiliation": [
                "aff1",
                "aff2"
              ],
              "email": [
                "cor1"
              ],
              "funding": [
                "par-1",
                "par-4",
                "par-7"
              ],
              "contribution": [
                "con1"
              ]
            }
          },
          {
            "type": "author",
            "surname": "Swan",
            "given-names": "David",
            "id": "author-2466",
            "references": {
              "affiliation": [
                "aff1"
              ],
              "contribution": [
                "con2"
              ]
            }
          },
          {
            "type": "author",
            "surname": "Al Sallaq",
            "given-names": "Ramzi",
            "id": "author-2467",
            "references": {
              "affiliation": [
                "aff1"
              ],
              "contribution": [
                "con3"
              ],
              "present-address": [
                "pa1"
              ]
            }
          },
          {
            "type": "author",
            "surname": "Magaret",
            "given-names": "Amalia",
            "id": "author-2468",
            "references": {
              "affiliation": [
                "aff1",
                "aff3"
              ],
              "funding": [
                "par-1"
              ],
              "contribution": [
                "con4"
              ]
            }
          },
          {
            "type": "author",
            "surname": "Johnston",
            "given-names": "Christine",
            "id": "author-2469",
            "references": {
              "affiliation": [
                "aff1",
                "aff4"
              ],
              "funding": [
                "par-1",
                "par-5"
              ],
              "contribution": [
                "con5"
              ]
            }
          },
          {
            "type": "author",
            "surname": "Mark",
            "given-names": "Karen E",
            "id": "author-2470",
            "references": {
              "affiliation": [
                "aff4"
              ],
              "funding": [
                "par-1",
                "par-6"
              ],
              "contribution": [
                "con6"
              ],
              "present-address": [
                "pa2"
              ]
            }
          },
          {
            "type": "author",
            "surname": "Selke",
            "given-names": "Stacy",
            "id": "author-2471",
            "references": {
              "affiliation": [
                "aff3"
              ],
              "contribution": [
                "con7"
              ]
            }
          },
          {
            "type": "author",
            "surname": "Ocbamichael",
            "given-names": "Negusse",
            "id": "author-2472",
            "references": {
              "affiliation": [
                "aff3"
              ],
              "contribution": [
                "con8"
              ]
            }
          },
          {
            "type": "author",
            "surname": "Kuntz",
            "given-names": "Steve",
            "id": "author-2473",
            "references": {
              "affiliation": [
                "aff3"
              ],
              "contribution": [
                "con9"
              ]
            }
          },
          {
            "type": "author",
            "surname": "Zhu",
            "given-names": "Jia",
            "id": "author-2474",
            "references": {
              "affiliation": [
                "aff1",
                "aff3"
              ],
              "funding": [
                "par-1",
                "par-2"
              ],
              "contribution": [
                "con10"
              ]
            }
          },
          {
            "type": "author",
            "surname": "Robinson",
            "given-names": "Barry",
            "id": "author-2475",
            "references": {
              "affiliation": [
                "aff3"
              ],
              "contribution": [
                "con11"
              ]
            }
          },
          {
            "type": "author",
            "surname": "Huang",
            "given-names": "Meei-Li",
            "id": "author-2476",
            "references": {
              "affiliation": [
                "aff3"
              ],
              "funding": [
                "par-1"
              ],
              "contribution": [
                "con12"
              ]
            }
          },
          {
            "type": "author",
            "surname": "Jerome",
            "given-names": "Keith R",
            "id": "author-2477",
            "references": {
              "affiliation": [
                "aff3"
              ],
              "contribution": [
                "con13"
              ]
            }
          },
          {
            "type": "author",
            "surname": "Wald",
            "given-names": "Anna",
            "id": "author-2478",
            "references": {
              "affiliation": [
                "aff1",
                "aff3",
                "aff4",
                "aff5"
              ],
              "funding": [
                "par-1",
                "par-3"
              ],
              "contribution": [
                "con14"
              ]
            }
          },
          {
            "type": "author",
            "surname": "Corey",
            "given-names": "Lawrence",
            "id": "author-2479",
            "references": {
              "affiliation": [
                "aff1",
                "aff3",
                "aff4"
              ],
              "funding": [
                "par-1",
                "par-2"
              ],
              "contribution": [
                "con15"
              ]
            }
          },
          {
            "type": "editor",
            "surname": "Sgaier",
            "given-names": "Sema",
            "role": "Reviewing editor",
            "affiliations": [
              {
                "institution": "Bill & Melinda Gates Foundation",
                "country": "India"
              }
            ]
          }
        ],
        "referenced": {
          "affiliation": {
            "aff1": {
              "dept": "Vaccine and Infectious Diseases Division",
              "institution": "Fred Hutchinson Cancer Research Center",
              "city": "Seattle",
              "country": "United States"
            },
            "aff2": {
              "dept": "Department of Medicine",
              "institution": "University of Washington",
              "city": "Seattle",
              "country": "United States"
            },
            "aff3": {
              "dept": "Department of Laboratory Medicine",
              "institution": "University of Washington",
              "city": "Seattle",
              "country": "United States"
            },
            "aff4": {
              "dept": "Department of Medicine",
              "institution": "University of Washington",
              "city": "Seattle",
              "country": "United States"
            },
            "aff5": {
              "dept": "Department of Epidemiology",
              "institution": "University of Washington",
              "city": "Seattle",
              "country": "United States"
            }
          },
          "email": {
            "cor1": "jschiffe@fhcrc.org"
          },
          "funding": {
            "par-1": {
              "institution": "National Institutes of Health",
              "award-id": "P01 AI030731"
            },
            "par-2": {
              "institution": "National Institutes of Health",
              "award-id": "R37 AI042528"
            },
            "par-3": {
              "institution": "National Institutes of Health",
              "award-id": "K24 AI07113"
            },
            "par-4": {
              "institution": "National Institutes of Health",
              "award-id": "K23 AI087206"
            },
            "par-5": {
              "institution": "National Institutes of Health",
              "award-id": "K23 AI079394"
            },
            "par-6": {
              "institution": "National Institutes of Health",
              "award-id": "K23 AI071257"
            },
            "par-7": {
              "institution": "National Center For Advancing Translational Sciences of the National Institutes of Health",
              "award-id": "UL1TR000423"
            }
          },
          "contribution": {
            "con1": "JTS, Conception and design, Acquisition of data, Analysis and interpretation of data, Drafting or revising the article, Contributed unpublished essential data or reagents",
            "con2": "DS, Conception and design, Analysis and interpretation of data",
            "con3": "RAS, Conception and design, Analysis and interpretation of data",
            "con4": "AM, Analysis and interpretation of data, Drafting or revising the article",
            "con5": "CJ, Conception and design, Acquisition of data, Analysis and interpretation of data, Drafting or revising the article",
            "con6": "KEM, Conception and design, Acquisition of data",
            "con7": "SS, Conception and design, Acquisition of data",
            "con8": "NO, Conception and design, Acquisition of data",
            "con9": "SK, Conception and design, Acquisition of data",
            "con10": "JZ, Acquisition of data, Analysis and interpretation of data",
            "con11": "BR, Acquisition of data, Analysis and interpretation of data",
            "con12": "M-LH, Acquisition of data, Analysis and interpretation of data",
            "con13": "KRJ, Conception and design, Drafting or revising the article",
            "con14": "AW, Conception and design, Drafting or revising the article",
            "con15": "LC, Conception and design, Drafting or revising the article"
          },
          "competing-interest": {
            "conf1": "The authors declare that no competing interests exist."
          },
          "present-address": {
            "pa1": "College of Nursing Global, New York University, New York, United States",
            "pa2": "The Office of AIDS, California Department of Public Health, Sacramento, United States"
          }
        },
        "fragments": [
          {
            "type": "abstract",
            "doi": "10.7554/eLife.00288.001",
            "path": "content/2/e00288v1/abstract"
          },
          {
            "type": "abstract",
            "doi": "10.7554/eLife.00288.002",
            "title": "eLife digest",
            "path": "content/2/e00288v1/abstract2"
          },
          {
            "type": "table-wrap",
            "doi": "10.7554/eLife.00288.003",
            "title": "Table 1.",
            "path": "content/2/e00288v1/table1"
          },
          {
            "type": "boxed-text",
            "doi": "10.7554/eLife.00288.004",
            "title": "Box 1.",
            "path": "content/2/e00288v1/box1"
          },
          {
            "type": "boxed-text",
            "doi": "10.7554/eLife.00288.005",
            "title": "Box 2.",
            "path": "content/2/e00288v1/box2"
          },
          {
            "type": "boxed-text",
            "doi": "10.7554/eLife.00288.006",
            "title": "Box 3.",
            "path": "content/2/e00288v1/box3"
          },
          {
            "type": "fig",
            "doi": "10.7554/eLife.00288.007",
            "title": "Figure 1.",
            "fragments": [
              {
                "type": "supplementary-material",
                "doi": "10.7554/eLife.00288.008",
                "title": "Figure 1—source data 1.",
                "path": "content/2/e00288v1/figure1/supp-material1"
              },
              {
                "type": "fig",
                "doi": "10.7554/eLife.00288.009",
                "title": "Figure 1—figure supplement 1.",
                "path": "content/2/e00288v1/figure1/figure-supp1"
              },
              {
                "type": "fig",
                "doi": "10.7554/eLife.00288.010",
                "title": "Figure 1—figure supplement 2.",
                "path": "content/2/e00288v1/figure1/figure-supp2"
              },
              {
                "type": "fig",
                "doi": "10.7554/eLife.00288.011",
                "title": "Figure 1—figure supplement 3.",
                "path": "content/2/e00288v1/figure1/figure-supp3"
              }
            ],
            "path": "content/2/e00288v1/figure1"
          },
          {
            "type": "boxed-text",
            "doi": "10.7554/eLife.00288.012",
            "title": "Box 4.",
            "path": "content/2/e00288v1/box4"
          },
          {
            "type": "fig",
            "doi": "10.7554/eLife.00288.013",
            "title": "Figure 2.",
            "fragments": [
              {
                "type": "supplementary-material",
                "doi": "10.7554/eLife.00288.014",
                "title": "Figure 2—source data 1.",
                "path": "content/2/e00288v1/figure2/supp-material1"
              },
              {
                "type": "fig",
                "doi": "10.7554/eLife.00288.015",
                "title": "Figure 2—figure supplement 1.",
                "path": "content/2/e00288v1/figure2/figure-supp1"
              },
              {
                "type": "fig",
                "doi": "10.7554/eLife.00288.016",
                "title": "Figure 2—figure supplement 2.",
                "path": "content/2/e00288v1/figure2/figure-supp2"
              },
              {
                "type": "fig",
                "doi": "10.7554/eLife.00288.017",
                "title": "Figure 2—figure supplement 3.",
                "path": "content/2/e00288v1/figure2/figure-supp3"
              }
            ],
            "path": "content/2/e00288v1/figure2"
          },
          {
            "type": "boxed-text",
            "doi": "10.7554/eLife.00288.018",
            "title": "Box 5.",
            "path": "content/2/e00288v1/box5"
          },
          {
            "type": "fig",
            "doi": "10.7554/eLife.00288.019",
            "title": "Figure 3.",
            "fragments": [
              {
                "type": "fig",
                "doi": "10.7554/eLife.00288.020",
                "title": "Figure 3—figure supplement 1.",
                "path": "content/2/e00288v1/figure3/figure-supp1"
              }
            ],
            "path": "content/2/e00288v1/figure3"
          },
          {
            "type": "fig",
            "doi": "10.7554/eLife.00288.021",
            "title": "Figure 4.",
            "fragments": [
              {
                "type": "supplementary-material",
                "doi": "10.7554/eLife.00288.022",
                "title": "Figure 4—source data 1.",
                "path": "content/2/e00288v1/figure4/supp-material1"
              },
              {
                "type": "fig",
                "doi": "10.7554/eLife.00288.023",
                "title": "Figure 4—figure supplement 1.",
                "path": "content/2/e00288v1/figure4/figure-supp1"
              }
            ],
            "path": "content/2/e00288v1/figure4"
          },
          {
            "type": "table-wrap",
            "doi": "10.7554/eLife.00288.024",
            "title": "Table 2.",
            "path": "content/2/e00288v1/table2"
          },
          {
            "type": "media",
            "doi": "10.7554/eLife.00288.025",
            "title": "Video 1.",
            "path": "content/2/e00288v1/media1"
          },
          {
            "type": "fig",
            "doi": "10.7554/eLife.00288.026",
            "title": "Figure 5.",
            "path": "content/2/e00288v1/figure5"
          },
          {
            "type": "media",
            "doi": "10.7554/eLife.00288.027",
            "title": "Video 2.",
            "path": "content/2/e00288v1/media2"
          },
          {
            "type": "media",
            "doi": "10.7554/eLife.00288.028",
            "title": "Video 3.",
            "path": "content/2/e00288v1/media3"
          },
          {
            "type": "media",
            "doi": "10.7554/eLife.00288.029",
            "title": "Video 4.",
            "path": "content/2/e00288v1/media4"
          },
          {
            "type": "media",
            "doi": "10.7554/eLife.00288.030",
            "title": "Video 5.",
            "path": "content/2/e00288v1/media5"
          },
          {
            "type": "table-wrap",
            "doi": "10.7554/eLife.00288.031",
            "title": "Table 3.",
            "path": "content/2/e00288v1/table3"
          },
          {
            "type": "media",
            "doi": "10.7554/eLife.00288.032",
            "title": "Video 6.",
            "path": "content/2/e00288v1/media6"
          },
          {
            "type": "media",
            "doi": "10.7554/eLife.00288.033",
            "title": "Video 7.",
            "path": "content/2/e00288v1/media7"
          },
          {
            "type": "media",
            "doi": "10.7554/eLife.00288.034",
            "title": "Video 8.",
            "path": "content/2/e00288v1/media8"
          },
          {
            "type": "media",
            "doi": "10.7554/eLife.00288.035",
            "title": "Video 9.",
            "path": "content/2/e00288v1/media9"
          },
          {
            "type": "fig",
            "doi": "10.7554/eLife.00288.036",
            "title": "Figure 6.",
            "fragments": [
              {
                "type": "fig",
                "doi": "10.7554/eLife.00288.037",
                "title": "Figure 6—figure supplement 1.",
                "path": "content/2/e00288v1/figure6/figure-supp1"
              },
              {
                "type": "fig",
                "doi": "10.7554/eLife.00288.038",
                "title": "Figure 6—figure supplement 2.",
                "path": "content/2/e00288v1/figure6/figure-supp2"
              }
            ],
            "path": "content/2/e00288v1/figure6"
          },
          {
            "type": "table-wrap",
            "doi": "10.7554/eLife.00288.039",
            "title": "Table 4.",
            "path": "content/2/e00288v1/table4"
          },
          {
            "type": "table-wrap",
            "doi": "10.7554/eLife.00288.040",
            "title": "Table 5.",
            "path": "content/2/e00288v1/table5"
          },
          {
            "type": "table-wrap",
            "doi": "10.7554/eLife.00288.041",
            "title": "Table 6.",
            "path": "content/2/e00288v1/table6"
          },
          {
            "type": "sub-article",
            "doi": "10.7554/eLife.00288.042",
            "title": "Decision letter",
            "contributors": [
              {
                "type": "editor",
                "surname": "Sgaier",
                "given-names": "Sema",
                "role": "Reviewing editor",
                "affiliations": [
                  {
                    "institution": "Bill & Melinda Gates Foundation",
                    "country": "India"
                  }
                ]
              }
            ],
            "path": "content/2/e00288v1/decision"
          },
          {
            "type": "sub-article",
            "doi": "10.7554/eLife.00288.043",
            "title": "Author response",
            "path": "content/2/e00288v1/response"
          }
        ],
        "version": 1,
        "article-version-id": "00288.1"
      }
    """

  Scenario Outline: Verify eLife article meta tags
    Given I go to "content/2/e00288v1"
    And I should see "<content>" in the "content" attribute of the "meta[name='<name>']" element

    Examples:
      | name           | content                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
      | DC.Format      | text/html                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
      | DC.Language    | en                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
      | DC.Title       | Rapid localized spread and immunologic containment define Herpes simplex virus-2 reactivation in the human genital tract                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
      | DC.Identifier  | 10.7554/eLife.00288                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
      | DC.Date        | 2013-04-16                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
      | DC.Publisher   | eLife Sciences Publications Limited                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
      | DC.Rights      | © 2013, Schiffer et al. This article is distributed under the terms of the Creative Commons Attribution License, which permits unrestricted use and redistribution provided that the original author and source are credited.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
      | DC.Description | Viruses infect organisms as diverse as unicellular bacteria, plants, and animals. Two well-known human viral infections are herpes simplex virus 1, which is responsible for most cold sores, and herpes simplex virus 2 (HSV-2), which causes most cases of genital herpes. The first signs of HSV-2 infection are genital lesions, which usually heal relatively quickly. However, the virus can also enter nerve cells, where it hides from the immune system and survives for the lifetime of the infected host. In a process that is not fully understood, the dormant viruses inside nerve cells periodically reactivate and are transported back to the genital tract where they can cause recurrent genital sores. HSV-2 also commonly replicates in genital skin when lesions are not present, and is efficiently transmitted to other individuals at these times. Most studies of viral infection rely on the examination of blood to determine viral load and characterize the immune response. However, the true battle between HSV-2 and its host occurs within genital tissues. HSV-2 lesions are clearly visible and it is therefore possible to precisely follow the number of viruses and the intensity of the host immune response as a function of time and position. Schiffer et al. follow this approach by examining the levels of HSV-2 DNA in the genital tracts of over 600 individuals, who were sampled at different time intervals and at multiple sites. Dramatic differences in the viral load and the density of CD8+ T cells, which are critical for controlling HSV-2, are observed across several millimeters of the skin. Viral load also varies dramatically over a few hours. These data are used to develop a mathematical model that characterizes the spatial dynamics of HSV-2 reactivation and suggests how the host immune system responds to reactivation. Historically, it was thought that host immune cells, including CD8+ T cells, required many days to contain an HSV-2 reactivation, allowing prolonged symptoms. However, the model developed by Schiffer et al. indicates that although viral infection can spread from a single skin cell to thousands of cells in 12 hr or so, the host immune cells typically clear all infected skin cells in under 24 hr. Episodes of viral shedding lasting &gt;3 days are predicted to occur due to viral seeding of adjacent regions of genital skin. Schiffer et al. predict that the complex episodic nature of HSV-2 reactivation is heavily influenced by the spatial distribution and density of immune cells within the genital tract, which means that new lesions occur in regions where immune cell density is low. The rapid onset and localized clearance pattern suggests that viral elimination by skin-resident CD8+ T cells is actually highly effective within single genital ulcers. This hypothesis represents an area of intense current investigation for clinicians, virologists, mathematical modelers, and immunologists. |

  Scenario Outline: Verify eLife article meta tag "DC.Contributor"
    Given I go to "content/2/e00288v1"
    Then the metatag attribute "DC.Contributor" in position "<n>" should have the value "<content>"

    Examples:
      | n  | content             |
      | 1  | Joshua T Schiffer   |
      | 2  | David Swan          |
      | 3  | Ramzi Al Sallaq     |
      | 4  | Amalia Magaret      |
      | 5  | Christine Johnston  |
      | 6  | Karen E Mark        |
      | 7  | Stacy Selke         |
      | 8  | Negusse Ocbamichael |
      | 9  | Steve Kuntz         |
      | 10 | Jia Zhu             |
      | 11 | Barry Robinson      |
      | 12 | Meei-Li Huang       |
      | 13 | Keith R Jerome      |
      | 14 | Anna Wald           |
      | 15 | Lawrence Corey      |
      | 16 | Sema Sgaier         |

  Scenario Outline: Verify eLife article unique citation meta tags
    Given I go to "content/2/e00288v1"
    Then the metatag attribute "<name>" should have the value "<content>"
    And I should see "<content>" in the "content" attribute of the "meta[name='<name>']" element

    Examples:
      | name                      | content                                                                                                                  |
      | citation_keywords         | Herpes simplex, Mucosal immunity, Mathematical modeling, Human, Virus                                                    |
      | citation_journal_title    | eLife                                                                                                                    |
      | citation_publisher        | eLife Sciences Publications Limited                                                                                      |
      | citation_title            | Rapid localized spread and immunologic containment define Herpes simplex virus-2 reactivation in the human genital tract |
      | citation_publication_date | 2013/04/16                                                                                                               |
      | citation_id               | 2/0/e00288                                                                                                               |
      | citation_public_url       | http://127.0.0.1:80/content/2/e00288v1                                                                                   |
      | citation_pdf_url          | http://nlisgo-backup-exp-elife-publishing-cdn.s3.amazonaws.com/00288/elife-00288-v1.pdf                                  |
      | citation_issn             | 2050-084X                                                                                                                |
      | citation_journal_abbrev   | eLife Sciences                                                                                                           |
      | citation_doi              | 10.7554/eLife.00288                                                                                                      |
      | citation_pmid             | 23606943                                                                                                                 |
      | citation_volume           | 2                                                                                                                        |
      | citation_section          | Immunology, Microbiology and Infectious Disease                                                                          |
      | citation_firstpage        | e00288                                                                                                                   |
      | citation_xml_url          | http://nlisgo-backup-exp-elife-publishing-cdn.s3.amazonaws.com/00288/elife-00288-v1.xml                                  |

  Scenario Outline: Verify eLife article meta tag "citation_reference"
    Given I go to "content/2/e00288v1"
    Then the metatag attribute "citation_reference" in position "<n>" should have the value "<content>"

    Examples:
      | n  | content                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |
      | 1  | citation_journal_title=Inf Sci (Ny);citation_author=AL. Bauer;citation_author=CA. Beauchemin;citation_author=AS. Perelson;citation_title=Agent-based modeling of host-pathogen systems: the successes and challenges;citation_pages=1379-1389;citation_volume=179;citation_year=2009;citation_doi=10.1016/j.ins.2008.11.012                                                                                                                                                                               |
      | 2  | citation_journal_title=J Theor Biol;citation_author=SM. Ciupe;citation_author=RM. Ribeiro;citation_author=PW. Nelson;citation_author=AS. Perelson;citation_title=Modeling the mechanisms of acute hepatitis B virus infection;citation_pages=23-35;citation_volume=247;citation_year=2007;citation_doi=10.1016/j.jtbi.2007.02.017                                                                                                                                                                         |
      | 3  | citation_journal_title=J Virol;citation_author=WJ. Collins;citation_author=DC. Johnson;citation_title=Herpes simplex virus gE/gI expressed in epithelial cells interferes with cell-to-cell spread;citation_pages=2686-2695;citation_volume=77;citation_year=2003;citation_doi=10.1128/JVI.77.4.2686-2695.2003                                                                                                                                                                                            |
      | 4  | citation_journal_title=Ann Intern Med;citation_author=L. Corey;citation_author=HG. Adams;citation_author=ZA. Brown;citation_author=KK. Holmes;citation_title=Genital herpes simplex virus infections: clinical manifestations, course, and complications;citation_pages=958-972;citation_volume=98;citation_year=1983                                                                                                                                                                                     |
      | 5  | citation_journal_title=Sex Transm Infect;citation_author=C. Crespi;citation_author=W. Cumberland;citation_author=A. Wald;citation_author=L. Corey;citation_author=S. Blower;citation_title=Longitudinal study of herpes simplex virus type 2 infection using viral dynamic modelling;citation_pages=359-364;citation_volume=83;citation_year=2007;citation_doi=10.1136/sti.2006.022020                                                                                                                    |
      | 6  | citation_journal_title=J Clin Invest;citation_author=AL. Cunningham;citation_author=RR. Turner;citation_author=AC. Miller;citation_author=MF. Para;citation_author=TC. Merigan;citation_title=Evolution of recurrent herpes simplex lesions. An immunohistologic study;citation_pages=226-233;citation_volume=75;citation_year=1985;citation_doi=10.1172/JCI111678                                                                                                                                        |
      | 7  | citation_journal_title=J Immunol;citation_author=RJ. De Boer;citation_author=D. Homann;citation_author=AS. Perelson;citation_title=Different dynamics of CD4+ and CD8+ T cell responses during and after acute lymphocytic choriomeningitis virus infection;citation_pages=3928-3935;citation_volume=171;citation_year=2003                                                                                                                                                                               |
      | 8  | citation_journal_title=Science;citation_author=V. Doceul;citation_author=M. Hollinshead;citation_author=L. van der Linden;citation_author=GL. Smith;citation_title=Repulsion of superinfecting virions: a mechanism for rapid virus spread;citation_pages=873-876;citation_volume=327;citation_year=2010;citation_doi=10.1126/science.1183173                                                                                                                                                             |
      | 9  | citation_journal_title=J Virol;citation_author=A. Farnsworth;citation_author=DC. Johnson;citation_title=Herpes simplex virus gE/gI must accumulate in the trans-Golgi network at early times and then redistribute to cell junctions to promote cell-cell spread;citation_pages=3167-3179;citation_volume=80;citation_year=2006;citation_doi=10.1128/JVI.80.7.3167-3179.2006                                                                                                                              |
      | 10 | citation_journal_title=Proc Natl Acad Sci USA;citation_author=C. Fraser;citation_author=S. Riley;citation_author=RM. Anderson;citation_author=NM. Ferguson;citation_title=Factors that make an infectious disease outbreak controllable;citation_pages=6146-6151;citation_volume=101;citation_year=2004;citation_doi=10.1073/pnas.0307506101                                                                                                                                                              |
      | 11 | citation_journal_title=Nat Immunol;citation_author=T. Gebhardt;citation_author=LM. Wakim;citation_author=L. Eidsmo;citation_author=PC. Reading;citation_author=WR. Heath;citation_author=FR. Carbone;citation_title=Memory T cells in nonlymphoid tissue that provide enhanced local immunity during infection with herpes simplex virus;citation_pages=524-530;citation_volume=10;citation_year=2009;citation_doi=10.1038/ni.1718                                                                        |
      | 12 | citation_journal_title=Proc Natl Acad Sci USA;citation_author=EL. Ionides;citation_author=C. Breto;citation_author=AA. King;citation_title=Inference for nonlinear dynamical systems;citation_pages=18438-18443;citation_volume=103;citation_year=2006;citation_doi=10.1073/pnas.0603181103                                                                                                                                                                                                               |
      | 13 | citation_journal_title=J Clin Microbiol;citation_author=KR. Jerome;citation_author=ML. Huang;citation_author=A. Wald;citation_author=S. Selke;citation_author=L. Corey;citation_title=Quantitative stability of DNA after extended storage of clinical specimens as determined by real-time PCR;citation_pages=2609-2611;citation_volume=40;citation_year=2002;citation_doi=10.1128/JCM.40.7.2609-2611.2002                                                                                               |
      | 14 | citation_journal_title=J Virol;citation_author=C. Jiang;citation_author=YT. Hwang;citation_author=JC. Randell;citation_author=DM. Coen;citation_author=CB. Hwang;citation_title=Mutations that decrease DNA binding of the processivity factor of the herpes simplex virus DNA polymerase reduce viral yield, alter the kinetics of viral DNA replication, and decrease the fidelity of DNA replication;citation_pages=3495-3502;citation_volume=81;citation_year=2007a;citation_doi=10.1128/JVI.02359-06 |
      | 15 | citation_journal_title=J Virol;citation_author=C. Jiang;citation_author=YT. Hwang;citation_author=G. Wang;citation_author=JC. Randell;citation_author=DM. Coen;citation_title=Herpes simplex virus mutants with multiple substitutions affecting DNA binding of UL42 are impaired for viral replication and DNA synthesis;citation_pages=12077-12079;citation_volume=81;citation_year=2007b;citation_doi=10.1128/JVI.01133-07                                                                             |
      | 16 | citation_journal_title=J Clin Microbiol;citation_author=A. Magaret;citation_author=A. Wald;citation_author=M. Huang;citation_author=S. Selke;citation_author=L. Corey;citation_title=Optimizing PCR positivity criterion for detection of herpes simplex virus DNA on skin and mucosa;citation_pages=1618-1620;citation_volume=45;citation_year=2007;citation_doi=10.1128/JCM.01405-06                                                                                                                    |
      | 17 | citation_journal_title=J Theor Biol;citation_author=S. Marino;citation_author=IB. Hogue;citation_author=CJ. Ray;citation_author=DE. Kirschner;citation_title=A methodology for performing global uncertainty and sensitivity analysis in systems biology;citation_pages=178-196;citation_volume=254;citation_year=2008;citation_doi=10.1016/j.jtbi.2008.04.011                                                                                                                                            |
      | 18 | citation_journal_title=J Infect Dis;citation_author=KE. Mark;citation_author=A. Wald;citation_author=AS. Magaret;citation_author=S. Selke;citation_author=L. Olin;citation_author=ML. Huang;citation_title=Rapidly cleared episodes of herpes simplex virus reactivation in immunocompetent adults;citation_pages=1141-1149;citation_volume=198;citation_year=2008;citation_doi=10.1086/591913                                                                                                            |
      | 19 | citation_journal_title=Sex Transm Dis;citation_author=GJ. Mertz;citation_author=O. Schmidt;citation_author=JL. Jourden;citation_author=ME. Guinan;citation_author=ML. Remington;citation_author=A. Fahnlander;citation_title=Frequency of acquisition of first-episode genital infection with herpes simplex virus from symptomatic and asymptomatic source contacts;citation_pages=33-39;citation_volume=12;citation_year=1985;citation_doi=10.1097/00007435-198501000-00007                             |
      | 20 | citation_journal_title=J Infect Dis;citation_author=GJ. Mertz;citation_author=RW. Coombs;citation_author=R. Ashley;citation_author=J. Jourden;citation_author=M. Remington;citation_author=C. Winter;citation_title=Transmission of genital herpes in couples with one symptomatic and one asymptomatic partner: a prospective study;citation_pages=1169-1177;citation_volume=157;citation_year=1988;citation_doi=10.1093/infdis/157.6.1169                                                               |
      | 21 | citation_journal_title=Science;citation_author=A. Perelson;citation_author=A. Neumann;citation_author=M. Markowitz;citation_author=J. Leonard;citation_author=D. Ho;citation_title=HIV-1 dynamics in vivo: virion clearance rate, infected cell life-span, and viral generation time;citation_pages=1582-1586;citation_volume=271;citation_year=1996;citation_doi=10.1126/science.271.5255.1582                                                                                                           |
      | 22 | citation_journal_title=J Virol;citation_author=RM. Ribeiro;citation_author=L. Qin;citation_author=LL. Chavez;citation_author=D. Li;citation_author=SG. Self;citation_author=AS. Perelson;citation_title=Estimation of the initial viral growth rate and basic reproductive number during acute HIV-1 infection;citation_pages=6096-6102;citation_volume=84;citation_year=2010;citation_doi=10.1128/JVI.00127-10                                                                                           |
      | 23 | citation_author=BKD. Roizman;citation_title=Herpes simplex viruses and their replication;citation_title=Fields Virology;citation_year=2007                                                                                                                                                                                                                                                                                                                                                                |
      | 24 | citation_journal_title=J Virol;citation_author=WR. Sacks;citation_author=PA. Schaffer;citation_title=Deletion mutants in the gene encoding the herpes simplex virus type 1 immediate-early protein ICP0 exhibit impaired growth in cell culture;citation_pages=829-839;citation_volume=61;citation_year=1987                                                                                                                                                                                              |
    
  Scenario Outline: Verify eLife article property meta tags (facebook)
    Given I go to "content/2/e00288v1"
    Then the metatag attribute "<property>" should have the value "<content>"

    Examples:
      | property     | content                                                                                                                  |
      | fb:app_id    | 1471000156467630                                                                                                         |
      | og:site_name | eLife                                                                                                                    |
      | og:url       | http://127.0.0.1:80/content/2/e00288v1                                                                                   |
      | og:title     | Rapid localized spread and immunologic containment define Herpes simplex virus-2 reactivation in the human genital tract |
      | og:image     | http://cdn.elifesciences.org/images/elife_final_logo_rgb.jpg                                                             |
      | og:type      | article                                                                                                                  |

  Scenario Outline: Verify eLife article citation multiple meta tags
    Given I go to "content/2/e00288v1"
    Then the metatag attribute "<name>" in position "<n>" should have the value "<content>"

    Examples:
      | n  | name                        | content                                                                                                                                                                                |
      | 1  | citation_editor_institution | Bill & Melinda Gates Foundation                                                                                                                                                        |
      | 1  | citation_funding_source     | citation_funder=National Institutes of Health;citation_grant_number=P01 AI030731;citation_grant_recipient=Joshua T Schiffer                                                            |
      | 2  | citation_funding_source     | citation_funder=National Institutes of Health;citation_grant_number=R37 AI042528;citation_grant_recipient=Jia Zhu                                                                      |
      | 3  | citation_funding_source     | citation_funder=National Institutes of Health;citation_grant_number=K24 AI07113;citation_grant_recipient=Anna Wald                                                                     |
      | 4  | citation_funding_source     | citation_funder=National Institutes of Health;citation_grant_number=K23 AI087206;citation_grant_recipient=Joshua T Schiffer                                                            |
      | 5  | citation_funding_source     | citation_funder=National Institutes of Health;citation_grant_number=K23 AI079394;citation_grant_recipient=Christine Johnston                                                           |
      | 6  | citation_funding_source     | citation_funder=National Institutes of Health;citation_grant_number=K23 AI071257;citation_grant_recipient=Karen E Mark                                                                 |
      | 7  | citation_funding_source     | citation_funder=National Center For Advancing Translational Sciences of the National Institutes of Health;citation_grant_number=UL1TR000423;citation_grant_recipient=Joshua T Schiffer |
      | 1  | citation_author             | Joshua T Schiffer                                                                                                                                                                      |
      | 1  | citation_author_institution | Vaccine and Infectious Diseases Division                                                                                                                                               |
      | 2  | citation_author_institution | Fred Hutchinson Cancer Research Center                                                                                                                                                 |
      | 3  | citation_author_institution | Department of Medicine                                                                                                                                                                 |
      | 4  | citation_author_institution | University of Washington                                                                                                                                                               |
      | 1  | citation_author_email       | jschiffe@fhcrc.org                                                                                                                                                                     |
      | 2  | citation_author             | David Swan                                                                                                                                                                             |
      | 5  | citation_author_institution | Vaccine and Infectious Diseases Division                                                                                                                                               |
      | 6  | citation_author_institution | Fred Hutchinson Cancer Research Center                                                                                                                                                 |
      | 3  | citation_author             | Ramzi Al Sallaq                                                                                                                                                                        |
      | 7  | citation_author_institution | Vaccine and Infectious Diseases Division                                                                                                                                               |
      | 8  | citation_author_institution | Fred Hutchinson Cancer Research Center                                                                                                                                                 |
      | 4  | citation_author             | Amalia Magaret                                                                                                                                                                         |
      | 9  | citation_author_institution | Vaccine and Infectious Diseases Division                                                                                                                                               |
      | 10 | citation_author_institution | Fred Hutchinson Cancer Research Center                                                                                                                                                 |
      | 11 | citation_author_institution | Department of Laboratory Medicine                                                                                                                                                      |
      | 12 | citation_author_institution | University of Washington                                                                                                                                                               |
      | 5  | citation_author             | Christine Johnston                                                                                                                                                                     |
      | 13 | citation_author_institution | Vaccine and Infectious Diseases Division                                                                                                                                               |
      | 14 | citation_author_institution | Fred Hutchinson Cancer Research Center                                                                                                                                                 |
      | 15 | citation_author_institution | Department of Medicine                                                                                                                                                                 |
      | 16 | citation_author_institution | University of Washington                                                                                                                                                               |
      | 6  | citation_author             | Karen E Mark                                                                                                                                                                           |
      | 17 | citation_author_institution | Department of Medicine                                                                                                                                                                 |
      | 18 | citation_author_institution | University of Washington                                                                                                                                                               |
      | 7  | citation_author             | Stacy Selke                                                                                                                                                                            |
      | 19 | citation_author_institution | Department of Laboratory Medicine                                                                                                                                                      |
      | 20 | citation_author_institution | University of Washington                                                                                                                                                               |
      | 8  | citation_author             | Negusse Ocbamichael                                                                                                                                                                    |
      | 21 | citation_author_institution | Department of Laboratory Medicine                                                                                                                                                      |
      | 22 | citation_author_institution | University of Washington                                                                                                                                                               |
      | 9  | citation_author             | Steve Kuntz                                                                                                                                                                            |
      | 23 | citation_author_institution | Department of Laboratory Medicine                                                                                                                                                      |
      | 24 | citation_author_institution | University of Washington                                                                                                                                                               |
      | 10 | citation_author             | Jia Zhu                                                                                                                                                                                |
      | 25 | citation_author_institution | Vaccine and Infectious Diseases Division                                                                                                                                               |
      | 26 | citation_author_institution | Fred Hutchinson Cancer Research Center                                                                                                                                                 |
      | 27 | citation_author_institution | Department of Laboratory Medicine                                                                                                                                                      |
      | 28 | citation_author_institution | University of Washington                                                                                                                                                               |
      | 11 | citation_author             | Barry Robinson                                                                                                                                                                         |
      | 29 | citation_author_institution | Department of Laboratory Medicine                                                                                                                                                      |
      | 30 | citation_author_institution | University of Washington                                                                                                                                                               |
      | 12 | citation_author             | Meei-Li Huang                                                                                                                                                                          |
      | 31 | citation_author_institution | Department of Laboratory Medicine                                                                                                                                                      |
      | 32 | citation_author_institution | University of Washington                                                                                                                                                               |
      | 13 | citation_author             | Keith R Jerome                                                                                                                                                                         |
      | 33 | citation_author_institution | Department of Laboratory Medicine                                                                                                                                                      |
      | 34 | citation_author_institution | University of Washington                                                                                                                                                               |
      | 14 | citation_author             | Anna Wald                                                                                                                                                                              |
      | 35 | citation_author_institution | Vaccine and Infectious Diseases Division                                                                                                                                               |
      | 36 | citation_author_institution | Fred Hutchinson Cancer Research Center                                                                                                                                                 |
      | 37 | citation_author_institution | Department of Laboratory Medicine                                                                                                                                                      |
      | 38 | citation_author_institution | University of Washington                                                                                                                                                               |
      | 39 | citation_author_institution | Department of Medicine                                                                                                                                                                 |
      | 40 | citation_author_institution | University of Washington                                                                                                                                                               |
      | 41 | citation_author_institution | Department of Epidemiology                                                                                                                                                             |
      | 42 | citation_author_institution | University of Washington                                                                                                                                                               |
      | 15 | citation_author             | Lawrence Corey                                                                                                                                                                         |
      | 43 | citation_author_institution | Vaccine and Infectious Diseases Division                                                                                                                                               |
      | 44 | citation_author_institution | Fred Hutchinson Cancer Research Center                                                                                                                                                 |
      | 45 | citation_author_institution | Department of Laboratory Medicine                                                                                                                                                      |
      | 46 | citation_author_institution | University of Washington                                                                                                                                                               |
      | 47 | citation_author_institution | Department of Medicine                                                                                                                                                                 |
      | 48 | citation_author_institution | University of Washington                                                                                                                                                               |
      | 1  | citation_editor             | Sema Sgaier                                                                                                                                                                            |
