Feature: Footnote
  In order to be able to get related information on contributors of an article
  As a reader
  I should see contributor info as footnote in author rollover

  @hover
  Scenario: Footnote in author rollover
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
    """
        {
          "title": "Bacterial regulation of colony development in the closest living relatives of animals",
          "impact-statement": "The chemical nature of RIF-1 may reveal a new class of bacterial signaling molecules.",
          "version": "1",
          "doi": "10.7554/eLife.00013",
          "publish": "1",
          "volume": "3",
          "article-id": "10.7554/eLife.00013",
          "article-version-id": "00013.1",
          "pub-date": "2014-02-28",
          "path": "content/3/e00013",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1",
          "categories": {
            "display-channel": [
              "Research article"
            ],
            "heading": [
              "Cell biology",
              "Computer science"
            ]
          },
          "keywords": {
            "author-keywords": [
              "<italic>Salpingoeca rosetta</italic>",
              "Algoriphagus",
              "bacterial sulfonolipid",
              "multicellular development"
            ],
            "research-organism": [
              "Mouse",
              "<italic>C. elegans</italic>",
              "Other"
            ]
          },
          "related-articles": [
            {
              "type": "commentary",
              "href": "10.7554/eLife.00013"
            }
          ],
          "contributors": [
            {
              "type": "author",
              "equal-contrib": "yes",
              "id": "author-23",
              "surname": "Alegado",
              "given-names": "Rosanna A",
              "suffix": "Jnr",
              "references": {
                "affiliation": [
                  "aff1",
                  "aff2"
                ],
                "equal-contrib": [
                  "equal-contrib"
                ],
                "funding": [
                  "par-1",
                  "par-2"
                ],
                "contribution": [
                  "con1"
                ],
                "competing-interest": [
                  "conf2"
                ],
                "present-address": [
                  "pa1"
                ],
                "related-object": [
                  "dataro1",
                  "dataro2"
                ]
              }
            },
            {
              "type": "author",
              "equal-contrib": "yes",
              "id": "author-17",
              "surname": "Brown",
              "given-names": "Laura W",
              "orcid": "http://orcid.org/0000-0002-7361-560X",
              "references": {
                "affiliation": [
                  "aff2"
                ],
                "equal-contrib": [
                  "equal-contrib"
                ],
                "funding": [
                  "par-1",
                  "par-3"
                ],
                "contribution": [
                  "con2"
                ],
                "competing-interest": [
                  "conf2"
                ],
                "present-address": [
                  "pa2"
                ]
              }
            },
            {
              "type": "author",
              "id": "author-3",
              "surname": "Cao",
              "given-names": "Shugeng",
              "references": {
                "affiliation": [
                  "aff2"
                ],
                "equal-contrib": [
                  "equal-contrib2"
                ],
                "contribution": [
                  "con3"
                ],
                "competing-interest": [
                  "conf2"
                ]
              }
            },
            {
              "type": "author",
              "id": "author-4",
              "surname": "Dermenjian",
              "given-names": "Renee Kathryn",
              "references": {
                "affiliation": [
                  "aff2"
                ],
                "equal-contrib": [
                  "equal-contrib2"
                ],
                "contribution": [
                  "con4"
                ],
                "competing-interest": [
                  "conf2"
                ],
                "present-address": [
                  "pa3"
                ]
              }
            },
            {
              "type": "author",
              "deceased": "yes",
              "id": "author-5",
              "surname": "Zuzow",
              "given-names": "Richard",
              "references": {
                "affiliation": [
                  "aff3"
                ],
                "contribution": [
                  "con5"
                ],
                "competing-interest": [
                  "conf2"
                ]
              }
            },
            {
              "type": "author",
              "id": "author-6",
              "surname": "Fairclough",
              "given-names": "Stephen R",
              "references": {
                "affiliation": [
                  "aff1"
                ],
                "funding": [
                  "par-6"
                ],
                "contribution": [
                  "con6"
                ],
                "competing-interest": [
                  "conf2"
                ]
              }
            },
            {
              "type": "author",
              "corresp": "yes",
              "id": "author-7",
              "surname": "Clardy",
              "given-names": "Jon",
              "references": {
                "affiliation": [
                  "aff2"
                ],
                "email": [
                  "cor1"
                ],
                "funding": [
                  "par-4",
                  "par-5"
                ],
                "contribution": [
                  "con7"
                ],
                "competing-interest": [
                  "conf1"
                ]
              }
            },
            {
              "type": "author",
              "corresp": "yes",
              "id": "author-8",
              "surname": "King",
              "given-names": "Nicole",
              "references": {
                "affiliation": [
                  "aff1"
                ],
                "email": [
                  "cor2"
                ],
                "funding": [
                  "par-1",
                  "par-2",
                  "par-3",
                  "par-4",
                  "par-5"
                ],
                "contribution": [
                  "con8"
                ],
                "competing-interest": [
                  "conf2"
                ]
              }
            },
            {
              "type": "author",
              "corresp": "yes",
              "group-author-key": "group-author-id1",
              "collab": "NISC Comparative Sequencing Program",
              "references": {
                "affiliation": [
                  "aff3"
                ],
                "email": [
                  "cor3"
                ],
                "funding": [
                  "par-7"
                ],
                "contribution": [
                  "con9"
                ],
                "competing-interest": [
                  "conf2"
                ]
              }
            },
            {
              "type": "author",
              "corresp": "yes",
              "group-author-key": "group-author-id2",
              "collab": "eLife staff group"
            },
            {
              "type": "editor",
              "id": "author-10",
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
              "type": "author non-byline",
              "group-author-key": "group-author-id1",
              "surname": "Mullikin",
              "given-names": "Jim",
              "affiliations": [
                {
                  "institution": "Science Exchange, Palo Alto",
                  "city": "California"
                }
              ]
            },
            {
              "type": "author non-byline",
              "group-author-key": "group-author-id1",
              "surname": "Mulvany",
              "given-names": "Ian"
            },
            {
              "type": "author non-byline",
              "group-author-key": "group-author-id1",
              "surname": "Bloggs",
              "given-names": "J"
            },
            {
              "type": "author non-byline",
              "group-author-key": "group-author-id2",
              "surname": "Dodd",
              "given-names": "Melissa"
            },
            {
              "type": "author non-byline",
              "group-author-key": "group-author-id2",
              "surname": "Rogers",
              "given-names": "Fran"
            },
            {
              "type": "author non-byline",
              "group-author-key": "group-author-id2",
              "surname": "Patterson",
              "given-names": "Mark"
            },
            {
              "type": "author non-byline",
              "group-author-key": "group-author-id2",
              "surname": "Harrison",
              "given-names": "Melissa"
            }
          ],
          "referenced": {
            "equal-contrib": {
              "equal-contrib": "These authors contributed equally to this work",
              "equal-contrib2": "These authors contributed equally to this work"
            },
            "email": {
              "cor1": "jon_clardy@hms.harvard.edu",
              "cor2": "nking@berkeley.edu",
              "cor3": "mharrison@elifesciences.org"
            },
            "funding": {
              "par-1": {
                "id": "dx.doi.org/10.13039/100000011",
                "id-type": "FundRef",
                "institution": "Howard Hughes Medical Institute"
              },
              "par-2": {
                "id": "dx.doi.org/10.13039/100000002",
                "id-type": "FundRef",
                "institution": "National Institutes of Health",
                "award-id": "F32 GM086054"
              },
              "par-3": {
                "id": "dx.doi.org/10.13039/100000002",
                "id-type": "FundRef",
                "institution": "National Institutes of Health",
                "award-id": "F32 GM089018"
              },
              "par-4": {
                "id": "dx.doi.org/10.13039/100000002",
                "id-type": "FundRef",
                "institution": "National Institutes of Health",
                "award-id": "R01 GM086258"
              },
              "par-5": {
                "id": "dx.doi.org/10.13039/100000002",
                "id-type": "FundRef",
                "institution": "National Institutes of Health",
                "award-id": "R01 GM099533"
              },
              "par-6": {
                "id": "dx.doi.org/10.13039/100000002",
                "id-type": "FundRef",
                "institution": "National Institutes of Health",
                "award-id": "T32 HG00047"
              },
              "par-7": {
                "institution": "Laura and John Arnold Foundation"
              }
            },
            "competing-interest": {
              "conf1": "JC: Reviewing editor, <italic>eLife</italic>.",
              "conf2": "The other authors declare that no competing interests exist."
            },
            "contribution": {
              "con1": "RAA, Conception and design, Acquisition of data, Analysis and interpretation of data, Drafting or revising the article",
              "con2": "LWB, Conception and design, Acquisition of data, Analysis and interpretation of data, Drafting or revising the article",
              "con3": "CS, Acquisition of data, Analysis and interpretation of data, Drafting or revising the article",
              "con4": "RKD, Acquisition of data, Analysis and interpretation of data",
              "con5": "RZ, Acquisition of data, Analysis and interpretation of data",
              "con6": "SRF, Acquisition of data, Analysis and interpretation of data",
              "con7": "JC, Conception and design, Analysis and interpretation of data, Drafting or revising the article",
              "con8": "NK, Conception and design, Analysis and interpretation of data, Drafting or revising the article",
              "con9": "NISC Comparative Sequencing Program: JM did X, IM did Y and JB did Z and Y"
            },
            "present-address": {
              "pa1": "Department of Wellcome Trust, Sanger Institute, London, United Kingdom",
              "pa2": "Department of Biological Chemistry and Molecular Pharmacology, Harvard Medical School, Boston, United States",
              "pa3": "eLife Sciences editorial Office, eLife Sciences, Cambridge, United Kingdom"
            },
            "affiliation": {
              "aff1": {
                "dept": "Department of Molecular and Cell Biology",
                "institution": "University of California, Berkeley",
                "city": "Berkeley",
                "country": "United States"
              },
              "aff2": {
                "dept": "Department of Biological Chemistry and Molecular Pharmacology",
                "institution": "Harvard Medical School",
                "city": "Boston",
                "country": "United States"
              },
              "aff3": {
                "dept": "Department of Biochemistry",
                "institution": "Stanford University School of Medicine",
                "city": "Stanford",
                "country": "United States"
              }
            },
            "related-object": {
              "dataro1": {},
              "dataro2": {}
            }
          },
          "related-articles": [
            {
              "type": "commentary",
              "href": "10.7554/eLife.00013"
            }
          ],
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
          ],
          "citations": {
            "bib1": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Agosta",
                  "given-names": "WC"
                }
              ],
              "year": "1992",
              "source": "Chemical Communication"
            },
            "bib2": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Ahmed",
                  "given-names": "I"
                },
                {
                  "group-type": "author",
                  "surname": "Yokota",
                  "given-names": "A"
                },
                {
                  "group-type": "author",
                  "surname": "Fujiwara",
                  "given-names": "T"
                }
              ],
              "year": "2007",
              "title": "Chimaereicella boritolerans sp nov., a boron-tolerant and alkaliphilic bacterium of the family Flavobacteriaceae isolated from soil",
              "source": "International journal of systematic and evolutionary microbiology",
              "doi": "10.1099/ijs.0.64728-0"
            },
            "bib3": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Alegado",
                  "given-names": "RA"
                },
                {
                  "group-type": "author",
                  "surname": "Grabenstatter",
                  "given-names": "JD"
                },
                {
                  "group-type": "author",
                  "surname": "Zuzow",
                  "given-names": "R"
                },
                {
                  "group-type": "author",
                  "surname": "Morris",
                  "given-names": "A"
                },
                {
                  "group-type": "author",
                  "surname": "Huang",
                  "given-names": "SY"
                },
                {
                  "group-type": "author",
                  "surname": "Summons",
                  "given-names": "RE"
                }
              ],
              "year": "2012",
              "title": "Algoriphagus machipongonensis sp. nov. co-isolated with a colonial choanoflagellate",
              "source": "International journal of systematic and evolutionary microbiology",
              "doi": "10.1099/ijs.0.038646-0"
            },
            "bib4": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "An",
                  "given-names": "D"
                },
                {
                  "group-type": "author",
                  "surname": "Na",
                  "given-names": "C"
                },
                {
                  "group-type": "author",
                  "surname": "Bielawski",
                  "given-names": "J"
                },
                {
                  "group-type": "author",
                  "surname": "Hannun",
                  "given-names": "YA"
                },
                {
                  "group-type": "author",
                  "surname": "Kasper",
                  "given-names": "DL"
                }
              ],
              "year": "2011",
              "title": "Membrane sphingolipids as essential molecular signals for bacteroides survival in the intestine",
              "source": "Proceedings of the National Academy of Sciences of the United States of America",
              "doi": "10.1073/pnas.1001501107"
            },
            "bib5": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Anton",
                  "given-names": "J"
                },
                {
                  "group-type": "author",
                  "surname": "Oren",
                  "given-names": "A"
                },
                {
                  "group-type": "author",
                  "surname": "Benlloch",
                  "given-names": "S"
                },
                {
                  "group-type": "author",
                  "surname": "Rodriguez-Valera",
                  "given-names": "F"
                },
                {
                  "group-type": "author",
                  "surname": "Amann",
                  "given-names": "R"
                },
                {
                  "group-type": "author",
                  "surname": "Rossello-Mora",
                  "given-names": "R"
                }
              ],
              "year": "2002",
              "title": "Salinibacter ruber gen. nov., sp nov., a novel, extremely halophilic member of the bacteria from saltern crystallizer ponds",
              "source": "International journal of systematic and evolutionary microbiology"
            },
            "bib6": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Apicella",
                  "given-names": "MA"
                }
              ],
              "year": "2008",
              "title": "Isolation and characterization of lipopolysaccharides",
              "source": "Methods in molecular biology"
            },
            "bib7": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Atlas",
                  "given-names": "RM"
                }
              ],
              "year": "2004",
              "source": "Handbook of microbiological media"
            },
            "bib8": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Barbeyron",
                  "given-names": "T"
                },
                {
                  "group-type": "author",
                  "surname": "L&#x2019;Haridon",
                  "given-names": "S"
                },
                {
                  "group-type": "author",
                  "surname": "Corre",
                  "given-names": "E"
                },
                {
                  "group-type": "author",
                  "surname": "Kloareg",
                  "given-names": "B"
                },
                {
                  "group-type": "author",
                  "surname": "Potin",
                  "given-names": "P"
                }
              ],
              "year": "2001",
              "title": "Zobellia galactanovorans gen. nov., sp. nov., a marine species of Flavobacteriaceae isolated from a red alga, and classification of [Cytophaga] uliginosa (ZoBell and Upham 1944) Reichenbach 1989 as Zobellia uliginosa gen. nov., comb. nov",
              "source": "International journal of systematic and evolutionary microbiology",
              "doi": "10.1099/00207713-51-3-985"
            },
            "bib9": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Bernardet",
                  "given-names": "J"
                },
                {
                  "group-type": "author",
                  "surname": "Segers",
                  "given-names": "P"
                },
                {
                  "group-type": "author",
                  "surname": "Vancanneyt",
                  "given-names": "M"
                },
                {
                  "group-type": "author",
                  "surname": "Berthe",
                  "given-names": "F"
                },
                {
                  "group-type": "author",
                  "surname": "Kersters",
                  "given-names": "K"
                },
                {
                  "group-type": "author",
                  "surname": "Vandamme",
                  "given-names": "P"
                }
              ],
              "year": "1996",
              "title": "Cutting a gordian knot: Emended classification and description of the genus Flavobacterium, emended description of the family Flavobacteriaceae, and proposal of Flavobacterium hydatis nom nov (basonym, Cytophaga aquatilis Strohl and Tait 1978)",
              "source": "International journal of systematic bacteriology",
              "doi": "10.1099/00207713-46-1-128"
            },
            "bib10": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Blattner",
                  "given-names": "FR"
                },
                {
                  "group-type": "author",
                  "surname": "Plankett",
                  "given-names": "G",
                  "suffix": "III"
                },
                {
                  "group-type": "author",
                  "surname": "Bloch",
                  "given-names": "CA"
                },
                {
                  "group-type": "author",
                  "surname": "Perna",
                  "given-names": "N"
                },
                {
                  "group-type": "author",
                  "surname": "Burland",
                  "given-names": "V"
                },
                {
                  "group-type": "author",
                  "surname": "Riley",
                  "given-names": "M"
                },
                {
                  "group-type": "author",
                  "surname": "Collado-Vides",
                  "given-names": "J"
                },
                {
                  "group-type": "author",
                  "surname": "Glasner",
                  "given-names": "JD"
                },
                {
                  "group-type": "author",
                  "surname": "Rode",
                  "given-names": "CK"
                },
                {
                  "group-type": "author",
                  "surname": "Mayhew",
                  "given-names": "GF"
                },
                {
                  "group-type": "author",
                  "surname": "Gregor",
                  "given-names": "J"
                },
                {
                  "group-type": "author",
                  "surname": "Davis",
                  "given-names": "NW"
                },
                {
                  "group-type": "author",
                  "surname": "Kirkpatrick",
                  "given-names": "HA"
                },
                {
                  "group-type": "author",
                  "surname": "Goeden",
                  "given-names": "MA"
                },
                {
                  "group-type": "author",
                  "surname": "Rose",
                  "given-names": "DJ"
                },
                {
                  "group-type": "author",
                  "surname": "Mau",
                  "given-names": "B"
                },
                {
                  "group-type": "author",
                  "surname": "Shao",
                  "given-names": "Y"
                }
              ],
              "year": "1997",
              "title": "The complete genome sequence of <italic>Escherichia coli</italic> K-12",
              "source": "Science",
              "doi": "10.1126/science.277.5331.1453"
            },
            "bib11": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Bligh",
                  "given-names": "EG"
                },
                {
                  "group-type": "author",
                  "surname": "Dyer",
                  "given-names": "WJ"
                }
              ],
              "year": "1959",
              "title": "A rapid method of total lipid extraction and purification",
              "source": "Canadian journal of biochemistry and physiology",
              "doi": "10.1139/o59-099"
            },
            "bib12": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Bowman",
                  "given-names": "JP"
                },
                {
                  "group-type": "author",
                  "surname": "Nichols",
                  "given-names": "CM"
                },
                {
                  "group-type": "author",
                  "surname": "Gibson",
                  "given-names": "JAE"
                }
              ],
              "year": "2003",
              "title": "Algoriphagus ratkowskyi gen. nov., sp. nov., Brumimicrobium glaciale gen. nov., sp. nov., Cryomorpha ignava gen. nov., sp. nov. and Crocinitomix catalasitica gen. nov., sp. nov., novel flavobacteria isolated from various polar habitats",
              "source": "International journal of systematic and evolutionary microbiology",
              "doi": "10.1099/ijs.0.02553-0"
            },
            "bib13": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Bradley",
                  "given-names": "RK"
                },
                {
                  "group-type": "author",
                  "surname": "Roberts",
                  "given-names": "A"
                },
                {
                  "group-type": "author",
                  "surname": "Smoot",
                  "given-names": "M"
                },
                {
                  "group-type": "author",
                  "surname": "Juvekar",
                  "given-names": "S"
                },
                {
                  "group-type": "author",
                  "surname": "Do",
                  "given-names": "J"
                },
                {
                  "group-type": "author",
                  "surname": "Dewey",
                  "given-names": "C"
                },
                {
                  "group-type": "author",
                  "surname": "Holmes",
                  "given-names": "I"
                },
                {
                  "group-type": "author",
                  "surname": "Pachter",
                  "given-names": "L"
                }
              ],
              "year": "2009",
              "title": "Fast statistical alignment",
              "source": "Public Library of Science International Society for Computational Biology",
              "doi": "10.1371/journal.pcbi.1000392"
            },
            "bib14": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Brettar",
                  "given-names": "I"
                },
                {
                  "group-type": "author",
                  "surname": "Christen",
                  "given-names": "R"
                },
                {
                  "group-type": "author",
                  "surname": "Hofle",
                  "given-names": "M"
                }
              ],
              "year": "2004a",
              "title": "Aquiflexum balticum gen. nov., sp nov., a novel marine bacterium of the Cytophaga-Flavobacterium-Bacteroides group isolated from surface water of the central Baltic Sea",
              "source": "International journal of systematic and evolutionary microbiology",
              "doi": "10.1099/ijs.0.63255-0"
            },
            "bib15": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Brettar",
                  "given-names": "I"
                },
                {
                  "group-type": "author",
                  "surname": "Christen",
                  "given-names": "R"
                },
                {
                  "group-type": "author",
                  "surname": "Hofle",
                  "given-names": "MG"
                }
              ],
              "year": "2004b",
              "title": "Belliella baltica gen. nov., sp. nov., a novel marine bacterium of the Cytophaga-Flavobacterium-Bacteroides group isolated from surface water of the central Baltic Sea",
              "source": "International journal of systematic and evolutionary microbiology",
              "doi": "10.1099/ijs.0.02752-0"
            },
            "bib16": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Butenandt",
                  "given-names": "A"
                },
                {
                  "group-type": "author",
                  "surname": "Beckmann",
                  "given-names": "R"
                },
                {
                  "group-type": "author",
                  "surname": "Hecker",
                  "given-names": "E"
                }
              ],
              "year": "1961",
              "title": "On the sex attractant of silk-moths. I. The biological test and the isolation of the pure sex-attractant bombykol",
              "source": "Hoppe-Seyler&#x2019;s Zeitschrift f&#xfc;r physiologische Chemie",
              "doi": "10.1515/bchm2.1961.324.1.71"
            },
            "bib17": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Carlucci",
                  "given-names": "AF"
                },
                {
                  "group-type": "author",
                  "surname": "Pramer",
                  "given-names": "D"
                }
              ],
              "year": "1957",
              "title": "Factors influencing the plate method for determining abundance of bacteria in sea water",
              "source": "Proceedings of the Society for Experimental Biology and Medicine",
              "doi": "10.3181/00379727-96-23487"
            },
            "bib18": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Carr",
                  "given-names": "M"
                },
                {
                  "group-type": "author",
                  "surname": "Leadbeater",
                  "given-names": "BSC"
                },
                {
                  "group-type": "author",
                  "surname": "Hassan",
                  "given-names": "R"
                },
                {
                  "group-type": "author",
                  "surname": "Nelson",
                  "given-names": "M"
                },
                {
                  "group-type": "author",
                  "surname": "Baldauf",
                  "given-names": "SL"
                }
              ],
              "year": "2008",
              "title": "Molecular phylogeny of choanoflagellates, the sister group to Metazoa",
              "source": "Proceedings of the National Academy of Sciences of the United States of America",
              "doi": "10.1073/pnas.0801667105"
            },
            "bib19": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Castresana",
                  "given-names": "J"
                }
              ],
              "year": "2000",
              "title": "Selection of conserved blocks from multiple alignments for their use in phylogenetic analysis",
              "source": "Molecular biology and evolution",
              "doi": "10.1093/oxfordjournals.molbev.a026334"
            },
            "bib20": {
              "authors": [
                {
                  "group-type": "editor",
                  "surname": "Blakely",
                  "given-names": "GW"
                }
              ],
              "year": "2005",
              "title": "Extensive DNA Inversions in the B. fragilis Genome Control Variable Gene Expression",
              "source": "Science",
              "doi": "10.1126/science.1107008"
            },
            "bib21": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Chelius",
                  "given-names": "M"
                },
                {
                  "group-type": "author",
                  "surname": "Triplett",
                  "given-names": "E"
                }
              ],
              "year": "2000",
              "title": "Dyadobacter fermentans gen. nov., sp nov., a novel Gram-negative bacterium isolated from surface-sterilized Zea mays stems",
              "source": "International journal of systematic and evolutionary microbiology",
              "doi": "10.1099/00207713-50-2-751"
            },
            "bib22": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Cho",
                  "given-names": "J-C"
                },
                {
                  "group-type": "author",
                  "surname": "Giovannoni",
                  "given-names": "SJ"
                }
              ],
              "year": "2003",
              "title": "Croceibacter atlanticus gen. nov., sp. nov., a novel marine bacterium in the family Flavobacteriaceae",
              "source": "Systematic and applied microbiology",
              "doi": "10.1078/072320203322337344"
            },
            "bib23": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Cho",
                  "given-names": "J-C"
                },
                {
                  "group-type": "author",
                  "surname": "Giovannoni",
                  "given-names": "SJ"
                }
              ],
              "year": "2004",
              "title": "Robiginitalea biformata gen. nov., sp. nov., a novel marine bacterium in the family Flavobacteriaceae with a higher G&#x2b;C content",
              "source": "International journal of systematic and evolutionary microbiology",
              "doi": "10.1099/ijs.0.03023-0"
            },
            "bib24": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Cohn",
                  "given-names": "ZA"
                },
                {
                  "group-type": "author",
                  "surname": "Morse",
                  "given-names": "SI"
                }
              ],
              "year": "1960",
              "title": "Functional and metabolic properties of polymorphonuclear leucocytes. II. The influence of a lipopolysaccharide endotoxin",
              "source": "The Journal of experimental medicine",
              "doi": "10.1084/jem.111.5.689"
            },
            "bib25": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Dayel",
                  "given-names": "MJ"
                },
                {
                  "group-type": "author",
                  "surname": "Alegado",
                  "given-names": "RA"
                },
                {
                  "group-type": "author",
                  "surname": "Fairclough",
                  "given-names": "SR"
                },
                {
                  "group-type": "author",
                  "surname": "Levin",
                  "given-names": "TC"
                },
                {
                  "group-type": "author",
                  "surname": "Nichols",
                  "given-names": "SA"
                },
                {
                  "group-type": "author",
                  "surname": "McDonald",
                  "given-names": "K"
                },
                {
                  "group-type": "author",
                  "surname": "King",
                  "given-names": "N"
                }
              ],
              "year": "2011",
              "title": "Cell differentiation and morphogenesis in the colony-forming choanoflagellate Salpingoeca rosetta",
              "source": "Developmental biology",
              "doi": "10.1016/j.ydbio.2011.06.003"
            },
            "bib26": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "de Jonge",
                  "given-names": "BL"
                },
                {
                  "group-type": "author",
                  "surname": "Chang",
                  "given-names": "YS"
                },
                {
                  "group-type": "author",
                  "surname": "Gage",
                  "given-names": "D"
                },
                {
                  "group-type": "author",
                  "surname": "Tomasz",
                  "given-names": "A"
                }
              ],
              "year": "1992",
              "title": "Peptidoglycan composition in heterogeneous Tn551 mutants of a methicillin-resistant Staphylococcus aureus strain",
              "source": "The Journal of biological chemistry"
            },
            "bib27": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "DeSantis",
                  "given-names": "TZ"
                },
                {
                  "group-type": "author",
                  "surname": "Hugenholtz",
                  "given-names": "P"
                },
                {
                  "group-type": "author",
                  "surname": "Larsen",
                  "given-names": "N"
                },
                {
                  "group-type": "author",
                  "surname": "Rojas",
                  "given-names": "M"
                },
                {
                  "group-type": "author",
                  "surname": "Brodie",
                  "given-names": "EL"
                },
                {
                  "group-type": "author",
                  "surname": "Keller",
                  "given-names": "K"
                },
                {
                  "group-type": "author",
                  "surname": "Huber",
                  "given-names": "T"
                },
                {
                  "group-type": "author",
                  "surname": "Dalevi",
                  "given-names": "D"
                },
                {
                  "group-type": "author",
                  "surname": "Hu",
                  "given-names": "P"
                },
                {
                  "group-type": "author",
                  "surname": "Andersen",
                  "given-names": "GL"
                }
              ],
              "year": "2006",
              "title": "Greengenes, a chimera-checked 16S rRNA gene database and workbench compatible with ARB",
              "source": "Applied and environmental microbiology",
              "doi": "10.1128/AEM.03006-05"
            },
            "bib28": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Desbrosses",
                  "given-names": "GJ"
                },
                {
                  "group-type": "author",
                  "surname": "Stougaard",
                  "given-names": "J"
                }
              ],
              "year": "2011",
              "title": "Root nodulation: a paradigm for how plant-microbe symbiosis influences host developmental pathways",
              "source": "Cell host and microbe",
              "doi": "10.1016/j.chom.2011.09.005"
            },
            "bib29": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Drijber",
                  "given-names": "R"
                },
                {
                  "group-type": "author",
                  "surname": "McGill",
                  "given-names": "W"
                }
              ],
              "year": "1994",
              "title": "Sulfonolipid content of Cytophaga and Flexibacter species isolated from soil and cultured under different Nutrient andtemperature regimes",
              "source": "Canadian Journal of Microbiology",
              "doi": "10.1139/m94-021"
            },
            "bib30": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Edman",
                  "given-names": "DC"
                },
                {
                  "group-type": "author",
                  "surname": "Pollock",
                  "given-names": "MB"
                },
                {
                  "group-type": "author",
                  "surname": "Hall",
                  "given-names": "ER"
                }
              ],
              "year": "1968",
              "title": "Listeria monocytogenes L forms. I. Induction maintenance, and biological characteristics",
              "source": "Journal of bacteriology"
            },
            "bib31": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Fairclough",
                  "given-names": "SR"
                },
                {
                  "group-type": "author",
                  "surname": "Dayel",
                  "given-names": "MJ"
                },
                {
                  "group-type": "author",
                  "surname": "King",
                  "given-names": "N"
                }
              ],
              "year": "2010",
              "title": "Multicellular development in a choanoflagellate",
              "source": "Current biology : CB",
              "doi": "10.1016/j.cub.2010.09.014"
            },
            "bib32": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Falenstein",
                  "given-names": "J"
                }
              ],
              "year": "1989",
              "title": "Phylip- phylogeny inference packages (Version 3.2)",
              "source": "Cladistics"
            },
            "bib33": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Falke",
                  "given-names": "JJ"
                },
                {
                  "group-type": "author",
                  "surname": "Bass",
                  "given-names": "RB"
                },
                {
                  "group-type": "author",
                  "surname": "Butler",
                  "given-names": "SL"
                },
                {
                  "group-type": "author",
                  "surname": "Chervitz",
                  "given-names": "SA"
                },
                {
                  "group-type": "author",
                  "surname": "Danielson",
                  "given-names": "MA"
                }
              ],
              "year": "1997",
              "title": "The two-component signaling pathway of bacterial chemotaxis: a molecular view of signal transduction by receptors, kinases, and adaptation enzymes",
              "source": "Annual review of cell and developmental biology",
              "doi": "10.1146/annurev.cellbio.13.1.457"
            },
            "bib34": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Falkow",
                  "given-names": "S"
                }
              ],
              "year": "2006",
              "title": "Is persistent bacterial infection good for your health?",
              "source": "Cell",
              "doi": "10.1016/j.cell.2006.02.004"
            },
            "bib35": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Garrity",
                  "given-names": "GM"
                }
              ],
              "year": "2010",
              "source": "Bergey&#x2019;s manual of systematic bacteriology: Bacteroidetes, spirochetes, tenericutes (mollicutes), acidobacteria, fibrobacteres, fusobacteria, dictyoglomi, gemmatimonadetes, lentisphaerae, verrucomicrobia, chlamydiae, and planctomycetes"
            },
            "bib36": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Godchaux",
                  "given-names": "W"
                },
                {
                  "group-type": "author",
                  "surname": "Leadbetter",
                  "given-names": "ER"
                }
              ],
              "year": "1980",
              "title": "Capnocytophaga spp. contain sulfonolipids that are novel in procaryotes",
              "source": "Journal of bacteriology"
            },
            "bib37": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Godchaux",
                  "given-names": "W"
                },
                {
                  "group-type": "author",
                  "surname": "Leadbetter",
                  "given-names": "ER"
                }
              ],
              "year": "1983",
              "title": "Unusual sulfonolipids are characteristic of the Cytophaga-Flexibacter group",
              "source": "Journal of bacteriology"
            },
            "bib38": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Godchaux",
                  "given-names": "W"
                },
                {
                  "group-type": "author",
                  "surname": "Leadbetter",
                  "given-names": "ER"
                }
              ],
              "year": "1984",
              "title": "Sulfonolipids of gliding bacteria. Structure of the N-acylaminosulfonates",
              "source": "The Journal of biological chemistry"
            },
            "bib39": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Godchaux",
                  "given-names": "W"
                },
                {
                  "group-type": "author",
                  "surname": "Leadbetter",
                  "given-names": "E"
                }
              ],
              "year": "1988",
              "title": "Sulfonolipids are localized in the outer membrane of the gliding bacterium Cytophaga johnsonae",
              "source": "Archives of microbiology"
            },
            "bib40": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Hall",
                  "given-names": "D"
                },
                {
                  "group-type": "author",
                  "surname": "Jeter",
                  "given-names": "J"
                },
                {
                  "group-type": "author",
                  "surname": "Iyer",
                  "given-names": "N"
                },
                {
                  "group-type": "author",
                  "surname": "Fetter",
                  "given-names": "D"
                },
                {
                  "group-type": "author",
                  "surname": "Hausenfluck",
                  "given-names": "JH"
                },
                {
                  "group-type": "author",
                  "surname": "Peng",
                  "given-names": "H"
                },
                {
                  "group-type": "author",
                  "surname": "Trautman",
                  "given-names": "ET"
                },
                {
                  "group-type": "author",
                  "surname": "Svirskas",
                  "given-names": "RR"
                },
                {
                  "group-type": "author",
                  "surname": "Myers",
                  "given-names": "EW"
                },
                {
                  "group-type": "author",
                  "surname": "Iwinski",
                  "given-names": "ZR"
                },
                {
                  "group-type": "author",
                  "surname": "Aso",
                  "given-names": "Y"
                },
                {
                  "group-type": "author",
                  "surname": "DePasquale",
                  "given-names": "GM"
                },
                {
                  "group-type": "author",
                  "surname": "Enos",
                  "given-names": "A"
                },
                {
                  "group-type": "author",
                  "surname": "Hulamm",
                  "given-names": "P"
                },
                {
                  "group-type": "author",
                  "surname": "Lam",
                  "given-names": "SC"
                },
                {
                  "group-type": "author",
                  "surname": "Li",
                  "given-names": "HH"
                },
                {
                  "group-type": "author",
                  "surname": "Laverty",
                  "given-names": "TR"
                },
                {
                  "group-type": "author",
                  "surname": "Long",
                  "given-names": "F"
                },
                {
                  "group-type": "author",
                  "surname": "Qu",
                  "given-names": "L"
                },
                {
                  "group-type": "author",
                  "surname": "Murphy",
                  "given-names": "SD"
                },
                {
                  "group-type": "author",
                  "surname": "Rokicki",
                  "given-names": "K"
                },
                {
                  "group-type": "author",
                  "surname": "Safford",
                  "given-names": "T"
                },
                {
                  "group-type": "author",
                  "surname": "Shaw",
                  "given-names": "K"
                },
                {
                  "group-type": "author",
                  "surname": "Simpson",
                  "given-names": "JH"
                },
                {
                  "group-type": "author",
                  "surname": "Sowell",
                  "given-names": "A"
                },
                {
                  "group-type": "author",
                  "surname": "Tae",
                  "given-names": "S"
                },
                {
                  "group-type": "author",
                  "surname": "Yu",
                  "given-names": "Y"
                },
                {
                  "group-type": "author",
                  "surname": "Zugates",
                  "given-names": "CT"
                }
              ],
              "year": "2012",
              "title": "A GAL4-driver line resource for Drosophila neurobiology",
              "source": "Cell reports",
              "doi": "10.1016/j.celrep.2012.09.011"
            },
            "bib41": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Hannun",
                  "given-names": "YA"
                },
                {
                  "group-type": "author",
                  "surname": "Luberto",
                  "given-names": "C"
                },
                {
                  "group-type": "author",
                  "surname": "Argraves",
                  "given-names": "KM"
                }
              ],
              "year": "2001",
              "title": "Enzymes of sphingolipid metabolism: from modular to integrative signaling",
              "source": "Biochemistry",
              "doi": "10.1021/bi002836k"
            },
            "bib42": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Herr",
                  "given-names": "DR"
                },
                {
                  "group-type": "author",
                  "surname": "Fyrst",
                  "given-names": "H"
                },
                {
                  "group-type": "author",
                  "surname": "Phan",
                  "given-names": "V"
                },
                {
                  "group-type": "author",
                  "surname": "Heinecke",
                  "given-names": "K"
                },
                {
                  "group-type": "author",
                  "surname": "Georges",
                  "given-names": "R"
                },
                {
                  "group-type": "author",
                  "surname": "Harris",
                  "given-names": "GL"
                },
                {
                  "group-type": "author",
                  "surname": "Saba",
                  "given-names": "JD"
                }
              ],
              "year": "2003",
              "title": "Sply regulation of sphingolipid signaling molecules is essential for Drosophila development",
              "source": "Development",
              "doi": "10.1242/dev.00456"
            },
            "bib43": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Hibberd",
                  "given-names": "DJ"
                }
              ],
              "year": "1975",
              "title": "Observations on the ultrastructure of the choanoflagellate Codosiga botrytis (Ehr.) Saville-Kent with special reference to the flagellar apparatus",
              "source": "Journal of cell science"
            },
            "bib44": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Hoffmann",
                  "given-names": "JA"
                },
                {
                  "group-type": "author",
                  "surname": "Kafatos",
                  "given-names": "FC"
                },
                {
                  "group-type": "author",
                  "surname": "Janeway",
                  "given-names": "CA"
                },
                {
                  "group-type": "author",
                  "surname": "Ezekowitz",
                  "given-names": "RA"
                }
              ],
              "year": "1999",
              "title": "Phylogenetic perspectives in innate immunity",
              "source": "Science",
              "doi": "10.1126/science.284.5418.1313"
            },
            "bib45": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Hughes",
                  "given-names": "DT"
                },
                {
                  "group-type": "author",
                  "surname": "Sperandio",
                  "given-names": "V"
                }
              ],
              "year": "2008",
              "title": "Inter-kingdom signalling: communication between bacteria and their hosts",
              "source": "Nature reviews. Microbiology",
              "doi": "10.1038/nrmicro1836"
            },
            "bib46": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "James-Clark",
                  "given-names": "H"
                }
              ],
              "year": "1868",
              "source": "On the spongiae ciliatae as infusoria flagellata; or observations on the structure, animality, and relationship of Leucosolenia botryoides"
            },
            "bib47": {
              "authors": [
                {
                  "group-type": "author",
                  "surname": "Kamiyama",
                  "given-names": "T"
                },
                {
                  "group-type": "author",
                  "surname": "Umino",
                  "given-names": "T"
                },
                {
                  "group-type": "author",
                  "surname": "Itezono",
                  "given-names": "Y"
                },
                {
                  "group-type": "author",
                  "surname": "Nakamura",
                  "given-names": "Y"
                },
                {
                  "group-type": "author",
                  "surname": "Satoh",
                  "given-names": "T"
                },
                {
                  "group-type": "author",
                  "surname": "Yokose",
                  "given-names": "K"
                }
              ],
              "year": "1995a",
              "title": "Sulfobacins A and B, novel von Willebrand factor receptor antagonists. II. Structural elucidation",
              "source": "The Journal of antibiotics",
              "doi": "10.7164/antibiotics.48.929"
            }
          }
        }
      """

    And the response code should be 200
    And I go to "content/4/e05227"
    Then I should see "author-tooltip-name" in the ".elife-article-author-item" element


