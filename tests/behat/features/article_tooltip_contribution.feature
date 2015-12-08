Feature: Contribution
  In order to be able to get credit for my work
  As an author
  I should see my name as contributor to the paper listed

  @hover
  Scenario Outline: Contribution listed in author tooltip
    Given there is an article:
      """
        {
          "title": "VOR 03895",
          "version": 1,
          "doi": "10.7554/eLife.03895",
          "volume": 3,
          "elocation-id": "e03895",
          "article-id": "10.7554/eLife.03895",
          "article-version-id": "05227",
          "pub-date": "2014-11-13T00:00:00+00:00",
          "path": "content/3/e03895",
          "article-type": "research-article",
          "status": "VOR",
          "publish": true,
          "contributors": [
            {
              "type": "author",
              "equal-contrib": true,
              "id": "author-23",
              "surname": "Kamoun",
              "given-names": "Sophien",
              "suffix": "Jnr",
              "references": {
                "affiliation": [
                  "aff1"
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
              "equal-contrib": true,
              "id": "author-17",
              "surname": "Krause",
              "given-names": "Johannes",
              "references": {
                "affiliation": [
                  "aff2"
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
            }
          }
        }
      """
    And I go to "content/3/e03895"
    Then I should see "<author>" in the ".author-list-full li:nth-of-type(<n>) .author-tooltip .author-tooltip-name" element
    Then I should see "Contributed equally with:" in the ".author-list-full li:nth-of-type(<n>) .author-tooltip-equal-contrib .author-tooltip-label" element

    Examples:
      | author             | n |
      | Sophien Kamoun Jnr | 1 |
      | Johannes Krause    | 2 |
      | Marco Thines       | 3 |
      | Detlef Weigel      | 4 |

  Scenario Outline: Contribution should be displayed without prefix (text before first colon or comma, if no colon detected, should be deleted)
    Given there is an article:
      """
        {
          "article-type": "research-article",
          "title": "Non-canonical TAF complexes regulate active promoters in human embryonic stem cells",
          "status": "VOR",
          "publish": true,
          "doi": "10.7554/eLife.00068",
          "pub-date": "2012-11-13T00:00:00+00:00",
          "volume": 1,
          "elocation-id": "e00068",
          "path": "content/1/e00068v1",
          "article-id": "00068",
          "categories": {
            "display-channel": [
              "Research Article"
            ]
          },
          "contributors": [
            {
              "type": "author",
              "surname": "Maston",
              "given-names": "Glenn A",
              "id": "author-1629",
              "references": {
                "contribution": [
                  "con1"
                ]
              }
            },
            {
              "type": "author",
              "surname": "Zhu",
              "given-names": "Lihua Julie",
              "id": "author-1630",
              "references": {
                "contribution": [
                  "con2"
                ]
              }
            },
            {
              "type": "author",
              "surname": "Chamberlain",
              "given-names": "Lynn",
              "id": "author-1631",
              "references": {
                "contribution": [
                  "con3"
                ]
              }
            },
            {
              "type": "author",
              "surname": "Lin",
              "given-names": "Ling",
              "id": "author-1632",
              "references": {
                "contribution": [
                  "con3"
                ]
              }
            },
            {
              "type": "author",
              "surname": "Fang",
              "given-names": "Minggang",
              "id": "author-2034",
              "references": {
                "contribution": [
                  "con3"
                ]
              }
            },
            {
              "type": "author",
              "surname": "Green",
              "given-names": "Michael R",
              "id": "author-1519",
              "corresp": true,
              "references": {
                "contribution": [
                  "con4"
                ]
              }
            }
          ],
          "referenced": {
            "contribution": {
              "con1": "GAM: Conception and design, Acquisition of data, Analysis and interpretation of data, Drafting or revising the article",
              "con2": "LJZ: Analysis and interpretation of data",
              "con3": "LC, LL, MF: Acquisition of data",
              "con4": "MRG, Conception and design, Analysis and interpretation of data, Drafting or revising the article"
            }
          },
          "version": 1,
          "article-version-id": "00068.1"
        }
      """
    When I am on "content/1/e00068v1"
    Then I should see "Contribution: <contribution>" in the ".author-list-full li:nth-of-type(<n>) .author-tooltip-contrib" element

    Examples:
      | n | contribution                                                                                                      |
      | 1 | Conception and design, Acquisition of data, Analysis and interpretation of data, Drafting or revising the article |
      | 4 | Acquisition of data                                                                                               |
      | 6 | Conception and design, Analysis and interpretation of data, Drafting or revising the article                      |
