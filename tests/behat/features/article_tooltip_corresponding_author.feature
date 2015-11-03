Feature: Footnote
  In Order to be able to contact a corresponding author
  As a reader
  I should be able to see the email id in the author tooltip

  @hover
  Scenario Outline: Author has provided email id
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
              "id": "author-4",
              "surname": "Weigel",
              "given-names": "Detlef",
              "affiliations": [
                {
                  "email": "detlef.weigel@email.com"
                }
              ],
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
            },
            {
              "type": "author",
              "id": "author-5",
              "surname": "Lisgo",
              "given-names": "Nathan",
              "email": "n.lisgo@elifesciences.org",
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
    And I go to "content/4/e07091"
    Then I should see "<author>" in the ".author-list-full li:nth-of-type(<n>) .author-tooltip .author-tooltip-name" element
    Then I should see the url "<author_email>" in the "href" attribute of the ".author-list-full li:nth-of-type(<n>) .author-tooltip .author-tooltip-corresp .author-tooltip-text a" element
    Then I should see "<email>" in the ".author-list-full li:nth-of-type(<n>) .author-tooltip .author-tooltip-corresp .author-tooltip-text" element
    Then I should see "For Correspondence:" in the ".author-list-full li:nth-of-type(<n>) .author-tooltip .author-tooltip-corresp .author-tooltip-label" element

    Examples:
      | author              | author_email                     | n | email                     |
      | Mikel Garcia-Marcos | mailto:mgm1@bu.edu               | 1 | mgm1@bu.edu               |
      | Pradipta Ghosh      | mailto:prghosh@ucsd.edu          | 2 | prghosh@ucsd.edu          |
      | Detlef Weigel       | mailto:detlef.weigel@email.com   | 3 | detlef.weigel@email.com   |
      | Nathan Lisgo        | mailto:n.lisgo@elifesciences.org | 4 | n.lisgo@elifesciences.org |

  Scenario Outline: Author has not provided email id
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
              "equal-contrib": "yes",
              "type": "author",
              "id": "author-14",
              "surname": "Abal",
              "given-names": "Miguel",
              "references": {
                "affiliation": [
                  "aff1"
                ]
              }
            }
          ],
          "referenced": {
            "affiliation": {
              "aff1": {
                "dept": "<dept>",
                "institution": "<institution>",
                "city": "<city>",
                "country": "<country>"
              }
            }
          }
        }
      """
    And I go to "content/4/e07091"
    Then I should see "Miguel Abal" in the ".author-list-full li:nth-of-type(<n>) .author-tooltip .author-tooltip-name" element
    And I should not see "For Correspondence" in the ".author-list-full li:nth-of-type(<n>) .author-tooltip" element

    Examples:
      | n |
      | 1 |

    Scenario: Support corresponding email address directly in affiliation block
      Given the markup service is available
      And there are articles:
        """
          [
            {
              "status": "VOR",
              "article-type": "editorial",
              "force": "1",
              "contributors": [
                {
                  "surname": "Morrison",
                  "corresp": "yes",
                  "given-names": "Sean J",
                  "role": " Senior Editor",
                  "references": {
                    "affiliation": [
                      "aff1"
                    ],
                    "competing-interest": [
                      "conf1"
                    ]
                  },
                  "type": "author",
                  "id": "author-1146"
                }
              ],
              "pub-date": "2014-12-10",
              "title": "Time to do something about reproducibility",
              "elocation-id": "e03981",
              "publish": "1",
              "article-version-id": "03981.1",
              "volume": "3",
              "keywords": {
                "author-keywords": [
                  "reproducibility project: cancer biology",
                  "methodology",
                  "open science",
                  "reproducibility",
                  "replication",
                  "blood stem cells"
                ]
              },
              "doi": "10.7554/eLife.03981",
              "version": "1",
              "referenced": {
                "competing-interest": {
                  "conf1": "The author declares that no competing interests exist."
                },
                "affiliation": {
                  "aff1": {
                    "email": "sean.morrison@utsouthwestern.edu",
                    "city": "Dallas",
                    "institution": " Children’s Research Institute at the University of Texas Southwestern Medical Center",
                    "country": "USA"
                  }
                }
              },
              "path": "content/3/e03981v1",
              "fragments": [],
              "article-id": "10.7554/eLife.03981",
              "categories": {
                "sub-display-channel": [
                  "Reproducibility Project: Cancer Biology"
                ],
                "heading": [
                  "Human biology and medicine"
                ],
                "display-channel": [
                  "Editorial"
                ]
              }
            }
          ]
        """
      When I visit "content/3/e03981v1"
      Then I should see "sean.morrison@utsouthwestern.edu" in the ".author-list-full li:nth-of-type(1) .author-tooltip .author-tooltip-corresp .author-tooltip-text" element
