Feature: Article Header
  In order to view an article's content
  As a website user
  I need an appropriate header section

  Scenario Outline: Article header should have Article tabs
    Given there is an article:
      """
        {
          "title": "VOR 00013",
          "version": "1",
          "doi": "10.7554/eLife.00013",
          "publish": "1",
          "volume": "3",
          "elocation-id": "e00013",
          "article-id": "10.7554/eLife.00013",
          "article-version-id": "00013.1",
          "pub-date": "2014-02-28",
          "path": "content/3/e00013",
          "article-type": "research-article",
          "status": "VOR",
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
                  "aff1"
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
                ]
              }
            },
            {
              "type": "author",
              "id": "author-4",
              "surname": "Dermenjian",
              "given-names": "Renee Kathryn",
              "references": {
                "contribution": [
                  "con4"
                ]
              }
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
              "par-7": {
                "institution": "Laura and John Arnold Foundation"
              }
            },
            "competing-interest": {
              "conf1": "JC: Reviewing editor, <italic>eLife</italic>.",
              "conf2": "The other authors declare that no competing interests exist."
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
            }
          }
        }
      """
    And the response code should be 200
    And I go to "content/3/e00013"
    Then I should see "<title>" in the ".pane-content .page-title" element
    Then I should see "<item>" in the ".pane-content .item-list li:nth-of-type(<n>) a" element
    Then I should see the url "<url>" in the "href" attribute of the ".pane-content .item-list li:nth-of-type(<n>) a" element

    Examples:
      | item                  | n | url                            | title     |
      | Article               | 1 | /content/3/e00013              | VOR 00013 |
      | Figures & data        | 2 | /content/3/e00013/article-data | VOR 00013 |
      | Article & author info | 3 | /content/3/e00013/article-info | VOR 00013 |

  Scenario Outline: Authors should be listed under the article title
    Given there is an article:
      """
        {
          "title": "VOR 07091",
          "version": "1",
          "doi": "10.7554/eLife.07091",
          "volume": "4",
          "elocation-id": "e07091",
          "article-id": "10.7554/eLife.07091",
          "article-version-id": "07091",
          "pub-date": "2015-06-30",
          "path": "content/4/e07091",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1",
          "contributors": [
            {
              "type": "author",
              "equal-contrib": "yes",
              "id": "author-23",
              "corresp": "yes",
              "surname": "Garcia-Marcos",
              "given-names": "Mikel",
              "references": {
                "affiliation": [
                  "aff1"
                ],
                "email": [
                  "cor1"
                ],
                "equal-contrib": [
                  "equal-contrib"
                ],
                "contribution": [
                  "con1"
                ]
              }
            },
            {
              "type": "author",
              "equal-contrib": "yes",
              "id": "author-17",
              "corresp": "yes",
              "surname": "Ghosh",
              "given-names": "Pradipta",
              "references": {
                "affiliation": [
                  "aff2"
                ],
                "email": [
                  "cor2"
                ],
                "equal-contrib": [
                  "equal-contrib"
                ],
                "contribution": [
                  "con2"
                ]
              }
            },
            {
              "type": "author",
              "id": "author-3",
              "surname": "Thines",
              "given-names": "Marco",
              "references": {
                "affiliation": [
                  "aff3"
                ],
                "equal-contrib": [
                  "equal-contrib"
                ],
                "contribution": [
                  "con3"
                ]
              }
            },
            {
              "type": "author",
              "id": "author-4",
              "surname": "Weigel",
              "given-names": "Detlef",
              "references": {
                "affiliation": [
                  "aff2"
                ],
                "equal-contrib": [
                  "equal-contrib"
                ],
                "contribution": [
                  "con3"
                ]
              }
            }
          ],
          "referenced": {
            "affiliation": {
              "aff1": {
                "dept": "department1",
                "institution": "inst1",
                "city": "city1",
                "country": "Country1"
              },
              "aff2": {
                "dept": "department2",
                "institution": "inst2",
                "city": "city2",
                "country": "Country2"
              },
              "aff3": {
                "dept": "department3",
                "institution": "inst3",
                "city": "city3",
                "country": "Country3"
              }
            },
            "contribution": {
              "con1": "RAA, Conception and design, Acquisition of data, Analysis and interpretation of data, Drafting or revising the article",
              "con2": "RAA, Conception and design, Analysis and interpretation of data, Drafting or revising the article",
              "con3": "RAA, Conception and design, Drafting or revising the article"
            },
            "email": {
              "cor1": "mgm1@bu.edu",
              "cor2": "prghosh@ucsd.edu"
            }
          }
        }
      """
    And the response code should be 200
    And I go to "content/4/e07091"
    Then I should see "<given-name>" in the ".author-list li:nth-of-type(<n>) .given-names" element
    Then I should see "<surname>" in the ".author-list li:nth-of-type(<n>) .surname" element
    Then I should see 2 ".author-list li .corresp-icon" elements

    Examples:
      | given-name | surname       | n |
      | Mikel      | Garcia-Marcos | 1 |
      | Pradipta   | Ghosh         | 2 |
      | Marco      | Thines        | 3 |
      | Detlef     | Weigel        | 4 |

@develop
  Scenario: Verifying article Doi information is listed correctly
    Given there is an article:
    """
      {
        "title": "VOR 05224 v2",
        "version": "2",
        "doi": "10.7554/eLife.05224",
        "volume": "4",
        "elocation-id": "e05224",
        "article-id": "05224",
        "article-version-id": "05224.2",
        "pub-date": "2015-08-17",
        "path": "content/4/e05224v2",
        "article-type": "research-article",
        "status": "VOR",
        "publish": "1",
        "keywords": {
        "author-keywords": [
        "Algoriphagus"
          ]
        }
      }
    """
    Given I am on "content/4/e05224v2"
    Then I should see "eLife 2015;4:e05224" in the ".elife-doi-cite-as" element
