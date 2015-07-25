Feature: Article Resource - Contributors (API)
  In order to maintain article content
  As a production system
  I need to be able to post article content with contributors via the resource api

  Scenario: Load an article with contributors
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05224",
          "version": "1",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "elocation-id": "e05224",
          "article-id": "10.7554/eLife.05224",
          "article-version-id": "05224",
          "pub-date": "1979-08-17",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1",
          "contributors": [
            {
              "type": "author",
              "equal-contrib": "yes",
              "id": "author-1",
              "surname": "Surname",
              "given-names": "First A"
            },
            {
              "type": "author",
              "id": "author-2",
              "surname": "Surname",
              "given-names": "First B"
            }
          ]
        }
      """
    Then there should be 2 contributors for "05224"

  Scenario: Load an article with contributors and contributor references
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05224",
          "version": "1",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "elocation-id": "e05224",
          "article-id": "10.7554/eLife.05224",
          "article-version-id": "05224",
          "pub-date": "1979-08-17",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1",
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
                ],
                "foot-note": [
                  "fn1",
                  "fn2"
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
                ],
                "foot-note": [
                  "fn2"
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
                "institution": "Howard Hughes Medical Institute",
                "institution-type": "university"
              },
              "par-2": {
                "id": "dx.doi.org/10.13039/100000002",
                "id-type": "FundRef",
                "institution": "National Institutes of Health",
                "institution-type": "university",
                "award-id": "F32 GM086054"
              },
              "par-3": {
                "id": "dx.doi.org/10.13039/100000002",
                "id-type": "FundRef",
                "institution": "National Institutes of Health",
                "institution-type": "university",
                "award-id": "F32 GM089018"
              },
              "par-4": {
                "id": "dx.doi.org/10.13039/100000002",
                "id-type": "FundRef",
                "institution": "National Institutes of Health",
                "institution-type": "university",
                "award-id": "R01 GM086258"
              },
              "par-5": {
                "id": "dx.doi.org/10.13039/100000002",
                "id-type": "FundRef",
                "institution": "National Institutes of Health",
                "institution-type": "university",
                "award-id": "R01 GM099533"
              },
              "par-6": {
                "id": "dx.doi.org/10.13039/100000002",
                "id-type": "FundRef",
                "institution": "National Institutes of Health",
                "institution-type": "university",
                "award-id": "T32 HG00047"
              },
              "par-7": {
                "institution": "Laura and John Arnold Foundation",
                "institution-type": "university"
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
            },
            "foot-note": {
              "fn1": {
                "type": "deceased",
                "value": "Deceased"
              },
              "fn2": {
                "type": "other",
                "value": "These authors are listed in alphabetical order"
              }
            }
          }
        }
      """
    When I send a GET request to "api/article/05224.json"
    Then the response should contain json:
      """
        {
          "title": "VOR 05224",
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
                ],
                "foot-note": [
                  "fn1",
                  "fn2"
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
                ],
                "foot-note": [
                  "fn2"
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
                "institution": "Howard Hughes Medical Institute",
                "institution-type": "university"
              },
              "par-2": {
                "id": "dx.doi.org/10.13039/100000002",
                "id-type": "FundRef",
                "institution": "National Institutes of Health",
                "institution-type": "university",
                "award-id": "F32 GM086054"
              },
              "par-3": {
                "id": "dx.doi.org/10.13039/100000002",
                "id-type": "FundRef",
                "institution": "National Institutes of Health",
                "institution-type": "university",
                "award-id": "F32 GM089018"
              },
              "par-4": {
                "id": "dx.doi.org/10.13039/100000002",
                "id-type": "FundRef",
                "institution": "National Institutes of Health",
                "institution-type": "university",
                "award-id": "R01 GM086258"
              },
              "par-5": {
                "id": "dx.doi.org/10.13039/100000002",
                "id-type": "FundRef",
                "institution": "National Institutes of Health",
                "institution-type": "university",
                "award-id": "R01 GM099533"
              },
              "par-6": {
                "id": "dx.doi.org/10.13039/100000002",
                "id-type": "FundRef",
                "institution": "National Institutes of Health",
                "institution-type": "university",
                "award-id": "T32 HG00047"
              },
              "par-7": {
                "institution": "Laura and John Arnold Foundation",
                "institution-type": "university"
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
            },
            "foot-note": {
              "fn1": {
                "type": "deceased",
                "value": "Deceased"
              },
              "fn2": {
                "type": "other",
                "value": "These authors are listed in alphabetical order"
              }
            }
          }
        }
      """

  Scenario: Load an article with contributor references first then contributors
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05224",
          "version": "1",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "elocation-id": "e05224",
          "article-id": "10.7554/eLife.05224",
          "article-version-id": "05224",
          "pub-date": "1979-08-17",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1",
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
                "institution": "Howard Hughes Medical Institute",
                "institution-type": "university"
              },
              "par-2": {
                "id": "dx.doi.org/10.13039/100000002",
                "id-type": "FundRef",
                "institution": "National Institutes of Health",
                "institution-type": "university",
                "award-id": "F32 GM086054"
              },
              "par-3": {
                "id": "dx.doi.org/10.13039/100000002",
                "id-type": "FundRef",
                "institution": "National Institutes of Health",
                "institution-type": "university",
                "award-id": "F32 GM089018"
              },
              "par-4": {
                "id": "dx.doi.org/10.13039/100000002",
                "id-type": "FundRef",
                "institution": "National Institutes of Health",
                "institution-type": "university",
                "award-id": "R01 GM086258"
              },
              "par-5": {
                "id": "dx.doi.org/10.13039/100000002",
                "id-type": "FundRef",
                "institution": "National Institutes of Health",
                "institution-type": "university",
                "award-id": "R01 GM099533"
              },
              "par-6": {
                "id": "dx.doi.org/10.13039/100000002",
                "id-type": "FundRef",
                "institution": "National Institutes of Health",
                "institution-type": "university",
                "award-id": "T32 HG00047"
              },
              "par-7": {
                "institution": "Laura and John Arnold Foundation",
                "institution-type": "university"
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
          }
        }
      """
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05224",
          "version": "1",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "elocation-id": "e05224",
          "article-id": "10.7554/eLife.05224",
          "article-version-id": "05224",
          "pub-date": "1979-08-17",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1",
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
          }
        }
      """
    When I send a GET request to "api/article/05224.json"
    Then the response should contain json:
      """
        {
          "title": "VOR 05224",
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
                "institution": "Howard Hughes Medical Institute",
                "institution-type": "university"
              },
              "par-2": {
                "id": "dx.doi.org/10.13039/100000002",
                "id-type": "FundRef",
                "institution": "National Institutes of Health",
                "institution-type": "university",
                "award-id": "F32 GM086054"
              },
              "par-3": {
                "id": "dx.doi.org/10.13039/100000002",
                "id-type": "FundRef",
                "institution": "National Institutes of Health",
                "institution-type": "university",
                "award-id": "F32 GM089018"
              },
              "par-4": {
                "id": "dx.doi.org/10.13039/100000002",
                "id-type": "FundRef",
                "institution": "National Institutes of Health",
                "institution-type": "university",
                "award-id": "R01 GM086258"
              },
              "par-5": {
                "id": "dx.doi.org/10.13039/100000002",
                "id-type": "FundRef",
                "institution": "National Institutes of Health",
                "institution-type": "university",
                "award-id": "R01 GM099533"
              },
              "par-6": {
                "id": "dx.doi.org/10.13039/100000002",
                "id-type": "FundRef",
                "institution": "National Institutes of Health",
                "institution-type": "university",
                "award-id": "T32 HG00047"
              },
              "par-7": {
                "institution": "Laura and John Arnold Foundation",
                "institution-type": "university"
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
          }
        }
      """
