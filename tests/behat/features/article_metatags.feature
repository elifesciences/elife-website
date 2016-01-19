@markup
Feature: Article Metatags
  In order to enhance google search on the article
  As a developer
  I should be able to output expected Metadata on article page for eLife Journal site

  Background:
    Given the markup service is available
    And there is an article:
    """
    {
      "status": "VOR",
      "article-type": "research-article",
      "contributors": [
        {
          "surname": "Schiffer",
          "corresp": true,
          "given-names": "Joshua T",
          "references": {
            "affiliation": [
              "aff1",
              "aff2"
            ],
            "contribution": [
              "con1"
            ],
            "funding": [
              "par-1",
              "par-4",
              "par-7"
            ],
            "email": [
              "cor1"
            ]
          },
          "type": "author",
          "id": "author-1921"
        },
        {
          "type": "author",
          "given-names": "David",
          "surname": "Swan",
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
          "given-names": "Ramzi",
          "surname": "Al Sallaq",
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
          "given-names": "Amalia",
          "surname": "Magaret",
          "id": "author-2468",
          "references": {
            "affiliation": [
              "aff1",
              "aff3"
            ],
            "contribution": [
              "con4"
            ],
            "funding": [
              "par-1"
            ]
          }
        },
        {
          "type": "author",
          "given-names": "Christine",
          "surname": "Johnston",
          "id": "author-2469",
          "references": {
            "affiliation": [
              "aff1",
              "aff4"
            ],
            "contribution": [
              "con5"
            ],
            "funding": [
              "par-1",
              "par-5"
            ]
          }
        },
        {
          "type": "author",
          "given-names": "Karen E",
          "surname": "Mark",
          "id": "author-2470",
          "references": {
            "affiliation": [
              "aff4"
            ],
            "contribution": [
              "con6"
            ],
            "funding": [
              "par-1",
              "par-6"
            ],
            "present-address": [
              "pa2"
            ]
          }
        },
        {
          "type": "author",
          "given-names": "Stacy",
          "surname": "Selke",
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
          "given-names": "Negusse",
          "surname": "Ocbamichael",
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
          "given-names": "Steve",
          "surname": "Kuntz",
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
          "given-names": "Jia",
          "surname": "Zhu",
          "id": "author-2474",
          "references": {
            "affiliation": [
              "aff1",
              "aff3"
            ],
            "contribution": [
              "con10"
            ],
            "funding": [
              "par-1",
              "par-2"
            ]
          }
        },
        {
          "type": "author",
          "given-names": "Barry",
          "surname": "Robinson",
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
          "given-names": "Meei-Li",
          "surname": "Huang",
          "id": "author-2476",
          "references": {
            "affiliation": [
              "aff3"
            ],
            "contribution": [
              "con12"
            ],
            "funding": [
              "par-1"
            ]
          }
        },
        {
          "type": "author",
          "given-names": "Keith R",
          "surname": "Jerome",
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
          "given-names": "Anna",
          "surname": "Wald",
          "id": "author-2478",
          "references": {
            "affiliation": [
              "aff1",
              "aff3",
              "aff4",
              "aff5"
            ],
            "contribution": [
              "con14"
            ],
            "funding": [
              "par-1",
              "par-3"
            ]
          }
        },
        {
          "type": "author",
          "given-names": "Lawrence",
          "surname": "Corey",
          "id": "author-2479",
          "references": {
            "affiliation": [
              "aff1",
              "aff3",
              "aff4"
            ],
            "contribution": [
              "con15"
            ],
            "funding": [
              "par-1",
              "par-2"
            ]
          }
        },
        {
          "surname": "Sgaier",
          "given-names": "Sema",
          "role": "Reviewing editor",
          "affiliations": [
            {
              "country": "India",
              "institution": "Bill & Melinda Gates Foundation"
            }
          ],
          "type": "editor"
        }
      ],
      "pub-date": "2013-04-16T00:00:00Z",
      "title": "Rapid localized spread and immunologic containment define Herpes simplex virus-2 reactivation in the human genital tract",
      "impact-statement": "A combination of detailed sampling and mathematical modeling suggests that the response of immune cells to reactivation of herpes simplex virus 2 is extremely rapid and effective within microscopic areas of genital skin.",
      "elocation-id": "e00288",
      "publish": true,
      "article-version-id": "00288.1",
      "volume": 2,
      "keywords": {
        "author-keywords": [
          "Herpes simplex",
          "Mucosal immunity",
          "Mathematical modeling"
        ],
        "research-organism": [
          "Human",
          "Viruses",
          "Other"
        ]
      },
      "doi": "10.7554/eLife.00288",
      "version": 1,
      "referenced": {
        "present-address": {
          "pa1": "College of Nursing Global, New York University, New York, United States",
          "pa2": "The Office of AIDS, California Department of Public Health, Sacramento, United States"
        },
        "competing-interest": {
          "conf1": "The authors declare that no competing interests exist."
        },
        "funding": {
          "par-7": {
            "award-id": "UL1TR000423",
            "institution": "National Center For Advancing Translational Sciences of the National Institutes of Health"
          },
          "par-6": {
            "award-id": "K23 AI071257",
            "institution": "National Institutes of Health"
          },
          "par-5": {
            "award-id": "K23 AI079394",
            "institution": "National Institutes of Health"
          },
          "par-4": {
            "award-id": "K23 AI087206",
            "institution": "National Institutes of Health"
          },
          "par-3": {
            "award-id": "K24 AI07113",
            "institution": "National Institutes of Health"
          },
          "par-2": {
            "award-id": "R37 AI042528",
            "institution": "National Institutes of Health"
          },
          "par-1": {
            "award-id": "P01 AI030731",
            "institution": "National Institutes of Health"
          }
        },
        "affiliation": {
          "aff5": {
            "dept": "Department of Epidemiology",
            "city": "Seattle",
            "institution": "University of Washington",
            "country": "United States"
          },
          "aff4": {
            "dept": "Department of Medicine",
            "city": "Seattle",
            "institution": "University of Washington",
            "country": "United States"
          },
          "aff3": {
            "dept": "Department of Laboratory Medicine",
            "city": "Seattle",
            "institution": "University of Washington",
            "country": "United States"
          },
          "aff2": {
            "dept": "Department of Medicine",
            "city": "Seattle",
            "institution": "University of Washington",
            "country": "United States"
          },
          "aff1": {
            "dept": "Vaccine and Infectious Diseases Division",
            "city": "Seattle",
            "institution": "Fred Hutchinson Cancer Research Center",
            "country": "United States"
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
          "con12": "M-LH, Acquisition of data, Analysis and interpretation of data",
          "con13": "KRJ, Conception and design, Drafting or revising the article",
          "con10": "JZ, Acquisition of data, Analysis and interpretation of data",
          "con11": "BR, Acquisition of data, Analysis and interpretation of data",
          "con14": "AW, Conception and design, Drafting or revising the article",
          "con15": "LC, Conception and design, Drafting or revising the article"
        },
        "email": {
          "cor1": "jschiffe@fhcrc.org"
        }
      },
      "path": "content/2/e00288v1",
      "fragments": [
        {
          "path": "content/2/e00288v1/abstract",
          "doi": "10.7554/eLife.00288.001",
          "type": "abstract"
        },
        {
          "path": "content/2/e00288v1/abstract2",
          "doi": "10.7554/eLife.00288.002",
          "type": "abstract",
          "title": "eLife digest"
        },
        {
          "path": "content/2/e00288v1/table1",
          "doi": "10.7554/eLife.00288.003",
          "type": "table-wrap",
          "title": "Table 1."
        },
        {
          "path": "content/2/e00288v1/box1",
          "doi": "10.7554/eLife.00288.004",
          "type": "boxed-text",
          "title": "Box 1."
        },
        {
          "path": "content/2/e00288v1/box2",
          "doi": "10.7554/eLife.00288.005",
          "type": "boxed-text",
          "title": "Box 2."
        },
        {
          "path": "content/2/e00288v1/box3",
          "doi": "10.7554/eLife.00288.006",
          "type": "boxed-text",
          "title": "Box 3."
        },
        {
          "path": "content/2/e00288v1/figure1",
          "fragments": [
            {
              "path": "content/2/e00288v1/figure1/supp-material1",
              "doi": "10.7554/eLife.00288.008",
              "type": "supplementary-material",
              "title": "Figure 1\u2014source data 1."
            },
            {
              "path": "content/2/e00288v1/figure1/figure-supp1",
              "doi": "10.7554/eLife.00288.009",
              "type": "fig",
              "title": "Figure 1\u2014figure supplement 1."
            },
            {
              "path": "content/2/e00288v1/figure1/figure-supp2",
              "doi": "10.7554/eLife.00288.010",
              "type": "fig",
              "title": "Figure 1\u2014figure supplement 2."
            },
            {
              "path": "content/2/e00288v1/figure1/figure-supp3",
              "doi": "10.7554/eLife.00288.011",
              "type": "fig",
              "title": "Figure 1\u2014figure supplement 3."
            }
          ],
          "doi": "10.7554/eLife.00288.007",
          "type": "fig",
          "title": "Figure 1."
        },
        {
          "path": "content/2/e00288v1/box4",
          "doi": "10.7554/eLife.00288.012",
          "type": "boxed-text",
          "title": "Box 4."
        },
        {
          "path": "content/2/e00288v1/figure2",
          "fragments": [
            {
              "path": "content/2/e00288v1/figure2/supp-material1",
              "doi": "10.7554/eLife.00288.014",
              "type": "supplementary-material",
              "title": "Figure 2\u2014source data 1."
            },
            {
              "path": "content/2/e00288v1/figure2/figure-supp1",
              "doi": "10.7554/eLife.00288.015",
              "type": "fig",
              "title": "Figure 2\u2014figure supplement 1."
            },
            {
              "path": "content/2/e00288v1/figure2/figure-supp2",
              "doi": "10.7554/eLife.00288.016",
              "type": "fig",
              "title": "Figure 2\u2014figure supplement 2."
            },
            {
              "path": "content/2/e00288v1/figure2/figure-supp3",
              "doi": "10.7554/eLife.00288.017",
              "type": "fig",
              "title": "Figure 2\u2014figure supplement 3."
            }
          ],
          "doi": "10.7554/eLife.00288.013",
          "type": "fig",
          "title": "Figure 2."
        },
        {
          "path": "content/2/e00288v1/box5",
          "doi": "10.7554/eLife.00288.018",
          "type": "boxed-text",
          "title": "Box 5."
        },
        {
          "path": "content/2/e00288v1/figure3",
          "fragments": [
            {
              "path": "content/2/e00288v1/figure3/figure-supp1",
              "doi": "10.7554/eLife.00288.020",
              "type": "fig",
              "title": "Figure 3\u2014figure supplement 1."
            }
          ],
          "doi": "10.7554/eLife.00288.019",
          "type": "fig",
          "title": "Figure 3."
        },
        {
          "path": "content/2/e00288v1/figure4",
          "fragments": [
            {
              "path": "content/2/e00288v1/figure4/supp-material1",
              "doi": "10.7554/eLife.00288.022",
              "type": "supplementary-material",
              "title": "Figure 4\u2014source data 1."
            },
            {
              "path": "content/2/e00288v1/figure4/figure-supp1",
              "doi": "10.7554/eLife.00288.023",
              "type": "fig",
              "title": "Figure 4\u2014figure supplement 1."
            }
          ],
          "doi": "10.7554/eLife.00288.021",
          "type": "fig",
          "title": "Figure 4."
        },
        {
          "path": "content/2/e00288v1/table2",
          "doi": "10.7554/eLife.00288.024",
          "type": "table-wrap",
          "title": "Table 2."
        },
        {
          "path": "content/2/e00288v1/media1",
          "doi": "10.7554/eLife.00288.025",
          "type": "media",
          "title": "Video 1."
        },
        {
          "path": "content/2/e00288v1/figure5",
          "doi": "10.7554/eLife.00288.026",
          "type": "fig",
          "title": "Figure 5."
        },
        {
          "path": "content/2/e00288v1/media2",
          "doi": "10.7554/eLife.00288.027",
          "type": "media",
          "title": "Video 2."
        },
        {
          "path": "content/2/e00288v1/media3",
          "doi": "10.7554/eLife.00288.028",
          "type": "media",
          "title": "Video 3."
        },
        {
          "path": "content/2/e00288v1/media4",
          "doi": "10.7554/eLife.00288.029",
          "type": "media",
          "title": "Video 4."
        },
        {
          "path": "content/2/e00288v1/media5",
          "doi": "10.7554/eLife.00288.030",
          "type": "media",
          "title": "Video 5."
        },
        {
          "path": "content/2/e00288v1/table3",
          "doi": "10.7554/eLife.00288.031",
          "type": "table-wrap",
          "title": "Table 3."
        },
        {
          "path": "content/2/e00288v1/media6",
          "doi": "10.7554/eLife.00288.032",
          "type": "media",
          "title": "Video 6."
        },
        {
          "path": "content/2/e00288v1/media7",
          "doi": "10.7554/eLife.00288.033",
          "type": "media",
          "title": "Video 7."
        },
        {
          "path": "content/2/e00288v1/media8",
          "doi": "10.7554/eLife.00288.034",
          "type": "media",
          "title": "Video 8."
        },
        {
          "path": "content/2/e00288v1/media9",
          "doi": "10.7554/eLife.00288.035",
          "type": "media",
          "title": "Video 9."
        },
        {
          "path": "content/2/e00288v1/figure6",
          "fragments": [
            {
              "path": "content/2/e00288v1/figure6/figure-supp1",
              "doi": "10.7554/eLife.00288.037",
              "type": "fig",
              "title": "Figure 6\u2014figure supplement 1."
            },
            {
              "path": "content/2/e00288v1/figure6/figure-supp2",
              "doi": "10.7554/eLife.00288.038",
              "type": "fig",
              "title": "Figure 6\u2014figure supplement 2."
            }
          ],
          "doi": "10.7554/eLife.00288.036",
          "type": "fig",
          "title": "Figure 6."
        },
        {
          "path": "content/2/e00288v1/table4",
          "doi": "10.7554/eLife.00288.039",
          "type": "table-wrap",
          "title": "Table 4."
        },
        {
          "path": "content/2/e00288v1/table5",
          "doi": "10.7554/eLife.00288.040",
          "type": "table-wrap",
          "title": "Table 5."
        },
        {
          "path": "content/2/e00288v1/table6",
          "doi": "10.7554/eLife.00288.041",
          "type": "table-wrap",
          "title": "Table 6."
        },
        {
          "path": "content/2/e00288v1/decision",
          "doi": "10.7554/eLife.00288.042",
          "type": "sub-article",
          "contributors": [
            {
              "surname": "Sgaier",
              "given-names": "Sema",
              "role": "Reviewing editor",
              "affiliations": [
                {
                  "country": "India",
                  "institution": "Bill & Melinda Gates Foundation"
                }
              ],
              "type": "editor"
            }
          ],
          "title": "Decision letter"
        },
        {
          "path": "content/2/e00288v1/response",
          "doi": "10.7554/eLife.00288.043",
          "type": "sub-article",
          "title": "Author response"
        }
      ],
      "article-id": "00288",
      "categories": {
        "heading": [
          "Immunology",
          "Microbiology and infectious disease"
        ],
        "display-channel": [
          "Research article"
        ]
      }
    }
    """

  Scenario: Verify eLife article meta tags
    Given I go to "content/2/e00288v1"
    Then I should see "text/html" in the "content" attribute of the "meta[name='DC.Format']" element
    Then I should see "en" in the "content" attribute of the "meta[name='DC.Language']" element
    Then I should see "Rapid localized spread and immunologic containment define Herpes simplex virus-2 reactivation in the human genital tract" in the "content" attribute of the "meta[name='DC.Title']" element
    Then I should see "10.7554/eLife.00288" in the "content" attribute of the "meta[name='DC.Identifier']" element
    Then I should see "2013-04-16" in the "content" attribute of the "meta[name='DC.Date']" element
    Then I should see "eLife Sciences Publications Limited" in the "content" attribute of the "meta[name='DC.Publisher']" element
    Then I should see "© 2013, Schiffer et al. This article is distributed under the terms of the Creative Commons Attribution License, which permits unrestricted use and redistribution provided that the original author and source are credited." in the "content" attribute of the "meta[name='DC.Rights']" element
 #   Then I should see "Viruses infect organisms as diverse as unicellular bacteria, plants, and animals. Two well-known human viral infections are herpes simplex virus 1, which is responsible for most cold sores, and herpes simplex virus 2 (HSV-2), which causes most cases of genital herpes. The first signs of HSV-2 infection are genital lesions, which usually heal relatively quickly. However, the virus can also enter nerve cells, where it hides from the immune system and survives for the lifetime of the infected host. In a process that is not fully understood, the dormant viruses inside nerve cells periodically reactivate and are transported back to the genital tract where they can cause recurrent genital sores. HSV-2 also commonly replicates in genital skin when lesions are not present, and is efficiently transmitted to other individuals at these times. Most studies of viral infection rely on the examination of blood to determine viral load and characterize the immune response. However, the true battle between HSV-2 and its host occurs within genital tissues. HSV-2 lesions are clearly visible and it is therefore possible to precisely follow the number of viruses and the intensity of the host immune response as a function of time and position. Schiffer et al. follow this approach by examining the levels of HSV-2 DNA in the genital tracts of over 600 individuals, who were sampled at different time intervals and at multiple sites. Dramatic differences in the viral load and the density of CD8+ T cells, which are critical for controlling HSV-2, are observed across several millimeters of the skin. Viral load also varies dramatically over a few hours. These data are used to develop a mathematical model that characterizes the spatial dynamics of HSV-2 reactivation and suggests how the host immune system responds to reactivation. Historically, it was thought that host immune cells, including CD8+ T cells, required many days to contain an HSV-2 reactivation, allowing prolonged symptoms. However, the model developed by Schiffer et al. indicates that although viral infection can spread from a single skin cell to thousands of cells in 12 hr or so, the host immune cells typically clear all infected skin cells in under 24 hr. Episodes of viral shedding lasting &gt;3 days are predicted to occur due to viral seeding of adjacent regions of genital skin. Schiffer et al. predict that the complex episodic nature of HSV-2 reactivation is heavily influenced by the spatial distribution and density of immune cells within the genital tract, which means that new lesions occur in regions where immune cell density is low. The rapid onset and localized clearance pattern suggests that viral elimination by skin-resident CD8+ T cells is actually highly effective within single genital ulcers. This hypothesis represents an area of intense current investigation for clinicians, virologists, mathematical modelers, and immunologists." in the "content" attribute of the "meta[name='DC.Description']" element

  Scenario: Verify eLife article meta tag "DC.Contributor"
    Given I go to "content/2/e00288v1"
    Then the metatag attribute "DC.Contributor" in position "1" should have the value "Joshua T Schiffer"
    Then the metatag attribute "DC.Contributor" in position "2" should have the value "David Swan"
    Then the metatag attribute "DC.Contributor" in position "3" should have the value "Ramzi Al Sallaq"
    Then the metatag attribute "DC.Contributor" in position "4" should have the value "Amalia Magaret"
    Then the metatag attribute "DC.Contributor" in position "5" should have the value "Christine Johnston"
    Then the metatag attribute "DC.Contributor" in position "6" should have the value "Karen E Mark"
    Then the metatag attribute "DC.Contributor" in position "7" should have the value "Stacy Selke"
    Then the metatag attribute "DC.Contributor" in position "8" should have the value "Negusse Ocbamichael"
    Then the metatag attribute "DC.Contributor" in position "9" should have the value "Steve Kuntz"
    Then the metatag attribute "DC.Contributor" in position "10" should have the value "Jia Zhu"
    Then the metatag attribute "DC.Contributor" in position "11" should have the value "Barry Robinson"
    Then the metatag attribute "DC.Contributor" in position "12" should have the value "Meei-Li Huang"
    Then the metatag attribute "DC.Contributor" in position "13" should have the value "Keith R Jerome"
    Then the metatag attribute "DC.Contributor" in position "14" should have the value "Anna Wald"
    Then the metatag attribute "DC.Contributor" in position "15" should have the value "Lawrence Corey"
    Then the metatag attribute "DC.Contributor" in position "16" should have the value "Sema Sgaier"

  Scenario: Verify eLife article unique citation meta tags
    Given I go to "content/2/e00288v1"
    Then the metatag attribute "citation_keywords" should have the value "Herpes simplex, Mucosal immunity, Mathematical modeling, Human, Viruses"
    Then the metatag attribute "citation_journal_title" should have the value "eLife"
    Then the metatag attribute "citation_publisher" should have the value "eLife Sciences Publications Limited"
    Then the metatag attribute "citation_title" should have the value "Rapid localized spread and immunologic containment define Herpes simplex virus-2 reactivation in the human genital tract"
    Then the metatag attribute "citation_publication_date" should have the value "2013/04/16"
    Then the metatag attribute "citation_id" should have the value "2/0/e00288"
    Then the metatag attribute "citation_public_url" should have the value "http://127.0.0.1:80/content/2/e00288v1"
    Then the metatag attribute "citation_pdf_url" should have the value "http://parallel-elife-publishing-cdn.s3.amazonaws.com/00288/elife-00288-v1.pdf"
    Then the metatag attribute "citation_issn" should have the value "2050-084X"
    Then the metatag attribute "citation_journal_abbrev" should have the value "eLife Sciences"
    Then the metatag attribute "citation_doi" should have the value "10.7554/eLife.00288"
    Then the metatag attribute "citation_pmid" should have the value "23606943"
    Then the metatag attribute "citation_volume" should have the value "2"
    Then the metatag attribute "citation_section" should have the value "Immunology, Microbiology and infectious disease"
    Then the metatag attribute "citation_firstpage" should have the value "e00288"
    Then the metatag attribute "citation_xml_url" should have the value "http://parallel-elife-publishing-cdn.s3.amazonaws.com/00288/elife-00288-v1.xml"


   Scenario: Verify eLife article meta tag "citation_reference"
    Given I go to "content/2/e00288v1"
    Then the metatag attribute "citation_reference" in position "1" should have the value "citation_journal_title=Inf Sci (Ny);citation_author=AL. Bauer;citation_author=CA. Beauchemin;citation_author=AS. Perelson;citation_title=Agent-based modeling of host-pathogen systems: the successes and challenges;citation_pages=1379-1389;citation_volume=179;citation_year=2009;citation_doi=10.1016/j.ins.2008.11.012"
    Then the metatag attribute "citation_reference" in position "2" should have the value "citation_journal_title=J Theor Biol;citation_author=SM. Ciupe;citation_author=RM. Ribeiro;citation_author=PW. Nelson;citation_author=AS. Perelson;citation_title=Modeling the mechanisms of acute hepatitis B virus infection;citation_pages=23-35;citation_volume=247;citation_year=2007;citation_doi=10.1016/j.jtbi.2007.02.017"
    Then the metatag attribute "citation_reference" in position "3" should have the value "citation_journal_title=J Virol;citation_author=WJ. Collins;citation_author=DC. Johnson;citation_title=Herpes simplex virus gE/gI expressed in epithelial cells interferes with cell-to-cell spread;citation_pages=2686-2695;citation_volume=77;citation_year=2003;citation_doi=10.1128/JVI.77.4.2686-2695.2003"
    Then the metatag attribute "citation_reference" in position "4" should have the value "citation_journal_title=Ann Intern Med;citation_author=L. Corey;citation_author=HG. Adams;citation_author=ZA. Brown;citation_author=KK. Holmes;citation_title=Genital herpes simplex virus infections: clinical manifestations, course, and complications;citation_pages=958-972;citation_volume=98;citation_year=1983"
    Then the metatag attribute "citation_reference" in position "5" should have the value "citation_journal_title=Sex Transm Infect;citation_author=C. Crespi;citation_author=W. Cumberland;citation_author=A. Wald;citation_author=L. Corey;citation_author=S. Blower;citation_title=Longitudinal study of herpes simplex virus type 2 infection using viral dynamic modelling;citation_pages=359-364;citation_volume=83;citation_year=2007;citation_doi=10.1136/sti.2006.022020"
    Then the metatag attribute "citation_reference" in position "6" should have the value "citation_journal_title=J Clin Invest;citation_author=AL. Cunningham;citation_author=RR. Turner;citation_author=AC. Miller;citation_author=MF. Para;citation_author=TC. Merigan;citation_title=Evolution of recurrent herpes simplex lesions. An immunohistologic study;citation_pages=226-233;citation_volume=75;citation_year=1985;citation_doi=10.1172/JCI111678"
    Then the metatag attribute "citation_reference" in position "7" should have the value "citation_journal_title=J Immunol;citation_author=RJ. De Boer;citation_author=D. Homann;citation_author=AS. Perelson;citation_title=Different dynamics of CD4+ and CD8+ T cell responses during and after acute lymphocytic choriomeningitis virus infection;citation_pages=3928-3935;citation_volume=171;citation_year=2003"
    Then the metatag attribute "citation_reference" in position "8" should have the value "citation_journal_title=Science;citation_author=V. Doceul;citation_author=M. Hollinshead;citation_author=L. van der Linden;citation_author=GL. Smith;citation_title=Repulsion of superinfecting virions: a mechanism for rapid virus spread;citation_pages=873-876;citation_volume=327;citation_year=2010;citation_doi=10.1126/science.1183173"
    Then the metatag attribute "citation_reference" in position "9" should have the value "citation_journal_title=J Virol;citation_author=A. Farnsworth;citation_author=DC. Johnson;citation_title=Herpes simplex virus gE/gI must accumulate in the trans-Golgi network at early times and then redistribute to cell junctions to promote cell-cell spread;citation_pages=3167-3179;citation_volume=80;citation_year=2006;citation_doi=10.1128/JVI.80.7.3167-3179.2006"
    Then the metatag attribute "citation_reference" in position "10" should have the value "citation_journal_title=Proc Natl Acad Sci USA;citation_author=C. Fraser;citation_author=S. Riley;citation_author=RM. Anderson;citation_author=NM. Ferguson;citation_title=Factors that make an infectious disease outbreak controllable;citation_pages=6146-6151;citation_volume=101;citation_year=2004;citation_doi=10.1073/pnas.0307506101"
    Then the metatag attribute "citation_reference" in position "11" should have the value "citation_journal_title=Nat Immunol;citation_author=T. Gebhardt;citation_author=LM. Wakim;citation_author=L. Eidsmo;citation_author=PC. Reading;citation_author=WR. Heath;citation_author=FR. Carbone;citation_title=Memory T cells in nonlymphoid tissue that provide enhanced local immunity during infection with herpes simplex virus;citation_pages=524-530;citation_volume=10;citation_year=2009;citation_doi=10.1038/ni.1718"
    Then the metatag attribute "citation_reference" in position "12" should have the value "citation_journal_title=Proc Natl Acad Sci USA;citation_author=EL. Ionides;citation_author=C. Breto;citation_author=AA. King;citation_title=Inference for nonlinear dynamical systems;citation_pages=18438-18443;citation_volume=103;citation_year=2006;citation_doi=10.1073/pnas.0603181103"
    Then the metatag attribute "citation_reference" in position "13" should have the value "citation_journal_title=J Clin Microbiol;citation_author=KR. Jerome;citation_author=ML. Huang;citation_author=A. Wald;citation_author=S. Selke;citation_author=L. Corey;citation_title=Quantitative stability of DNA after extended storage of clinical specimens as determined by real-time PCR;citation_pages=2609-2611;citation_volume=40;citation_year=2002;citation_doi=10.1128/JCM.40.7.2609-2611.2002"
    Then the metatag attribute "citation_reference" in position "14" should have the value "citation_journal_title=J Virol;citation_author=C. Jiang;citation_author=YT. Hwang;citation_author=JC. Randell;citation_author=DM. Coen;citation_author=CB. Hwang;citation_title=Mutations that decrease DNA binding of the processivity factor of the herpes simplex virus DNA polymerase reduce viral yield, alter the kinetics of viral DNA replication, and decrease the fidelity of DNA replication;citation_pages=3495-3502;citation_volume=81;citation_year=2007a;citation_doi=10.1128/JVI.02359-06"
    Then the metatag attribute "citation_reference" in position "15" should have the value "citation_journal_title=J Virol;citation_author=C. Jiang;citation_author=YT. Hwang;citation_author=G. Wang;citation_author=JC. Randell;citation_author=DM. Coen;citation_title=Herpes simplex virus mutants with multiple substitutions affecting DNA binding of UL42 are impaired for viral replication and DNA synthesis;citation_pages=12077-12079;citation_volume=81;citation_year=2007b;citation_doi=10.1128/JVI.01133-07"
    Then the metatag attribute "citation_reference" in position "16" should have the value "citation_journal_title=J Clin Microbiol;citation_author=A. Magaret;citation_author=A. Wald;citation_author=M. Huang;citation_author=S. Selke;citation_author=L. Corey;citation_title=Optimizing PCR positivity criterion for detection of herpes simplex virus DNA on skin and mucosa;citation_pages=1618-1620;citation_volume=45;citation_year=2007;citation_doi=10.1128/JCM.01405-06"
    Then the metatag attribute "citation_reference" in position "17" should have the value "citation_journal_title=J Theor Biol;citation_author=S. Marino;citation_author=IB. Hogue;citation_author=CJ. Ray;citation_author=DE. Kirschner;citation_title=A methodology for performing global uncertainty and sensitivity analysis in systems biology;citation_pages=178-196;citation_volume=254;citation_year=2008;citation_doi=10.1016/j.jtbi.2008.04.011"
    Then the metatag attribute "citation_reference" in position "18" should have the value "citation_journal_title=J Infect Dis;citation_author=KE. Mark;citation_author=A. Wald;citation_author=AS. Magaret;citation_author=S. Selke;citation_author=L. Olin;citation_author=ML. Huang;citation_title=Rapidly cleared episodes of herpes simplex virus reactivation in immunocompetent adults;citation_pages=1141-1149;citation_volume=198;citation_year=2008;citation_doi=10.1086/591913"
    Then the metatag attribute "citation_reference" in position "19" should have the value "citation_journal_title=Sex Transm Dis;citation_author=GJ. Mertz;citation_author=O. Schmidt;citation_author=JL. Jourden;citation_author=ME. Guinan;citation_author=ML. Remington;citation_author=A. Fahnlander;citation_title=Frequency of acquisition of first-episode genital infection with herpes simplex virus from symptomatic and asymptomatic source contacts;citation_pages=33-39;citation_volume=12;citation_year=1985;citation_doi=10.1097/00007435-198501000-00007"
    Then the metatag attribute "citation_reference" in position "20" should have the value "citation_journal_title=J Infect Dis;citation_author=GJ. Mertz;citation_author=RW. Coombs;citation_author=R. Ashley;citation_author=J. Jourden;citation_author=M. Remington;citation_author=C. Winter;citation_title=Transmission of genital herpes in couples with one symptomatic and one asymptomatic partner: a prospective study;citation_pages=1169-1177;citation_volume=157;citation_year=1988;citation_doi=10.1093/infdis/157.6.1169"
    Then the metatag attribute "citation_reference" in position "21" should have the value "citation_journal_title=Science;citation_author=A. Perelson;citation_author=A. Neumann;citation_author=M. Markowitz;citation_author=J. Leonard;citation_author=D. Ho;citation_title=HIV-1 dynamics in vivo: virion clearance rate, infected cell life-span, and viral generation time;citation_pages=1582-1586;citation_volume=271;citation_year=1996;citation_doi=10.1126/science.271.5255.1582"
    Then the metatag attribute "citation_reference" in position "22" should have the value "citation_journal_title=J Virol;citation_author=RM. Ribeiro;citation_author=L. Qin;citation_author=LL. Chavez;citation_author=D. Li;citation_author=SG. Self;citation_author=AS. Perelson;citation_title=Estimation of the initial viral growth rate and basic reproductive number during acute HIV-1 infection;citation_pages=6096-6102;citation_volume=84;citation_year=2010;citation_doi=10.1128/JVI.00127-10"
    Then the metatag attribute "citation_reference" in position "23" should have the value "citation_author=BKD. Roizman;citation_title=Herpes simplex viruses and their replication;citation_title=Fields Virology;citation_year=2007"
    Then the metatag attribute "citation_reference" in position "24" should have the value "citation_journal_title=J Virol;citation_author=WR. Sacks;citation_author=PA. Schaffer;citation_title=Deletion mutants in the gene encoding the herpes simplex virus type 1 immediate-early protein ICP0 exhibit impaired growth in cell culture;citation_pages=829-839;citation_volume=61;citation_year=1987"

  Scenario: Verify eLife article property meta tags (facebook)
    Given I go to "content/2/e00288v1"
    Then the metatag attribute "fb:app_id" should have the value "1471000156467630"
    Then the metatag attribute "og:site_name" should have the value "eLife"
    Then the metatag attribute "og:url" should have the value "http://127.0.0.1:80/content/2/e00288v1"
    Then the metatag attribute "og:title" should have the value "Rapid localized spread and immunologic containment define Herpes simplex virus-2 reactivation in the human genital tract"
    Then the metatag attribute "og:image" should have the value "http://cdn.elifesciences.org/images/elife_final_logo_rgb.jpg"
    Then the metatag attribute "og:type" should have the value "article"

  Scenario: Verify eLife article citation multiple meta tags
    Given I go to "content/2/e00288v1"
    Then the metatag attribute "citation_editor_institution" in position "1" should have the value "Bill & Melinda Gates Foundation"
    Then the metatag attribute "citation_funding_source" in position "1" should have the value "citation_funder=National Institutes of Health;citation_grant_number=P01 AI030731;citation_grant_recipient=Joshua T Schiffer"
    Then the metatag attribute "citation_funding_source" in position "2" should have the value "citation_funder=National Institutes of Health;citation_grant_number=R37 AI042528;citation_grant_recipient=Jia Zhu"
    Then the metatag attribute "citation_funding_source" in position "3" should have the value "citation_funder=National Institutes of Health;citation_grant_number=K24 AI07113;citation_grant_recipient=Anna Wald"
    Then the metatag attribute "citation_funding_source" in position "4" should have the value "citation_funder=National Institutes of Health;citation_grant_number=K23 AI087206;citation_grant_recipient=Joshua T Schiffer"
    Then the metatag attribute "citation_funding_source" in position "5" should have the value "citation_funder=National Institutes of Health;citation_grant_number=K23 AI079394;citation_grant_recipient=Christine Johnston"
    Then the metatag attribute "citation_funding_source" in position "6" should have the value "citation_funder=National Institutes of Health;citation_grant_number=K23 AI071257;citation_grant_recipient=Karen E Mark"
    Then the metatag attribute "citation_funding_source" in position "7" should have the value "citation_funder=National Center For Advancing Translational Sciences of the National Institutes of Health;citation_grant_number=UL1TR000423;citation_grant_recipient=Joshua T Schiffer"
    Then the metatag attribute "citation_author" in position "1" should have the value "Joshua T Schiffer"
    Then the metatag attribute "citation_author_institution" in position "1" should have the value "Vaccine and Infectious Diseases Division"
    Then the metatag attribute "citation_author_institution" in position "2" should have the value "Fred Hutchinson Cancer Research Center"
    Then the metatag attribute "citation_author_institution" in position "3" should have the value "Department of Medicine"
    Then the metatag attribute "citation_author_institution" in position "4" should have the value "University of Washington"
    Then the metatag attribute "citation_author_email" in position "1" should have the value "jschiffe@fhcrc.org"
    Then the metatag attribute "citation_author" in position "2" should have the value "David Swan"
    Then the metatag attribute "citation_author_institution" in position "5" should have the value "Vaccine and Infectious Diseases Division"
    Then the metatag attribute "citation_author_institution" in position "6" should have the value "Fred Hutchinson Cancer Research Center"
    Then the metatag attribute "citation_author" in position "3" should have the value "Ramzi Al Sallaq"
    Then the metatag attribute "citation_author_institution" in position "7" should have the value "Vaccine and Infectious Diseases Division"
    Then the metatag attribute "citation_author_institution" in position "8" should have the value "Fred Hutchinson Cancer Research Center"
    Then the metatag attribute "citation_author" in position "4" should have the value "Amalia Magaret"
    Then the metatag attribute "citation_author_institution" in position "9" should have the value "Vaccine and Infectious Diseases Division"
    Then the metatag attribute "citation_author_institution" in position "10" should have the value "Fred Hutchinson Cancer Research Center"
    Then the metatag attribute "citation_author_institution" in position "11" should have the value "Department of Laboratory Medicine"
    Then the metatag attribute "citation_author_institution" in position "12" should have the value "University of Washington"
    Then the metatag attribute "citation_author" in position "5" should have the value "Christine Johnston"
    Then the metatag attribute "citation_author_institution" in position "13" should have the value "Vaccine and Infectious Diseases Division"
    Then the metatag attribute "citation_author_institution" in position "14" should have the value "Fred Hutchinson Cancer Research Center"
    Then the metatag attribute "citation_author_institution" in position "15" should have the value "Department of Medicine"
    Then the metatag attribute "citation_author_institution" in position "16" should have the value "University of Washington"
    Then the metatag attribute "citation_author" in position "6" should have the value "Karen E Mark"
    Then the metatag attribute "citation_author_institution" in position "17" should have the value "Department of Medicine"
    Then the metatag attribute "citation_author_institution" in position "18" should have the value "University of Washington"
    Then the metatag attribute "citation_author" in position "7" should have the value "Stacy Selke"
    Then the metatag attribute "citation_author_institution" in position "19" should have the value "Department of Laboratory Medicine"
    Then the metatag attribute "citation_author_institution" in position "20" should have the value "University of Washington"
    Then the metatag attribute "citation_author" in position "8" should have the value "Negusse Ocbamichael"
    Then the metatag attribute "citation_author_institution" in position "21" should have the value "Department of Laboratory Medicine"
    Then the metatag attribute "citation_author_institution" in position "22" should have the value "University of Washington"
    Then the metatag attribute "citation_author" in position "9" should have the value "Steve Kuntz"
    Then the metatag attribute "citation_author_institution" in position "23" should have the value "Department of Laboratory Medicine"
    Then the metatag attribute "citation_author_institution" in position "24" should have the value "University of Washington"
    Then the metatag attribute "citation_author" in position "10" should have the value "Jia Zhu"
    Then the metatag attribute "citation_author_institution" in position "25" should have the value "Vaccine and Infectious Diseases Division"
    Then the metatag attribute "citation_author_institution" in position "26" should have the value "Fred Hutchinson Cancer Research Center"
    Then the metatag attribute "citation_author_institution" in position "27" should have the value "Department of Laboratory Medicine"
    Then the metatag attribute "citation_author_institution" in position "28" should have the value "University of Washington"
    Then the metatag attribute "citation_author" in position "11" should have the value "Barry Robinson"
    Then the metatag attribute "citation_author_institution" in position "29" should have the value "Department of Laboratory Medicine"
    Then the metatag attribute "citation_author_institution" in position "30" should have the value "University of Washington"
    Then the metatag attribute "citation_author" in position "12" should have the value "Meei-Li Huang"
    Then the metatag attribute "citation_author_institution" in position "31" should have the value "Department of Laboratory Medicine"
    Then the metatag attribute "citation_author_institution" in position "32" should have the value "University of Washington"
    Then the metatag attribute "citation_author" in position "13" should have the value "Keith R Jerome"
    Then the metatag attribute "citation_author_institution" in position "33" should have the value "Department of Laboratory Medicine"
    Then the metatag attribute "citation_author_institution" in position "34" should have the value "University of Washington"
    Then the metatag attribute "citation_author" in position "14" should have the value "Anna Wald"
    Then the metatag attribute "citation_author_institution" in position "35" should have the value "Vaccine and Infectious Diseases Division"
    Then the metatag attribute "citation_author_institution" in position "36" should have the value "Fred Hutchinson Cancer Research Center"
    Then the metatag attribute "citation_author_institution" in position "37" should have the value "Department of Laboratory Medicine"
    Then the metatag attribute "citation_author_institution" in position "38" should have the value "University of Washington"
    Then the metatag attribute "citation_author_institution" in position "39" should have the value "Department of Medicine"
    Then the metatag attribute "citation_author_institution" in position "40" should have the value "University of Washington"
    Then the metatag attribute "citation_author_institution" in position "41" should have the value "Department of Epidemiology"
    Then the metatag attribute "citation_author_institution" in position "42" should have the value "University of Washington"
    Then the metatag attribute "citation_author" in position "15" should have the value "Lawrence Corey"
    Then the metatag attribute "citation_author_institution" in position "43" should have the value "Vaccine and Infectious Diseases Division"
    Then the metatag attribute "citation_author_institution" in position "44" should have the value "Fred Hutchinson Cancer Research Center"
    Then the metatag attribute "citation_author_institution" in position "45" should have the value "Department of Laboratory Medicine"
    Then the metatag attribute "citation_author_institution" in position "46" should have the value "University of Washington"
    Then the metatag attribute "citation_author_institution" in position "47" should have the value "Department of Medicine"
    Then the metatag attribute "citation_author_institution" in position "48" should have the value "University of Washington"
    Then the metatag attribute "citation_editor" in position "1" should have the value "Sema Sgaier"
