Feature: Alphabetical
  In order to ensure that my contribution to the paper is not tied to my position in the author list
  As an author
  I should be listed in alphabetical order with other authors

  Scenario Outline: View alphabetical listing of authors when there is more than one contributor
    Given there is an article:
      """
        {
          "title": "VOR 00731",
          "version": 1,
          "doi": "10.7554/eLife.00731",
          "volume": 2,
          "elocation-id": "e00731",
          "article-id": "10.7554/eLife.00731",
          "article-version-id": "00731",
          "pub-date": "2013-05-28T00:00:00+00:00",
          "path": "content/2/e00731",
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
                ],
                "foot-note": [
                  "fn1"
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
                ],
                "foot-note": [
                  "fn1"
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
                  "equal-contrib2"
                ],
                "contribution": [
                  "con3"
                ],
                "foot-note": [
                  "fn1"
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
                  "equal-contrib2"
                ],
                "contribution": [
                  "con3"
                ],
                "foot-note": [
                  "fn1"
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
            "foot-note": {
              "fn1": {
                "type": "other",
                "value": "Listed in Alphabetical order with: Sophien Kamoun, Johannes Krause, Marco Thines, Detlef Weigel"
              }
            }
          }
        }
      """
    And I go to "content/2/e00731"
    Then I should see "<author>" in the ".author-list-full li:nth-of-type(<n>) .author-tooltip .author-tooltip-name" element
    And I should see "Listed in alphabetical order with: Sophien Kamoun, Johannes Krause, Marco Thines, Detlef Weigel"

    Examples:
      | author          | n |
      | Sophien Kamoun  | 1 |
      | Johannes Krause | 2 |
      | Marco Thines    | 3 |

  Scenario: No alphabetical listing of authors when there are no equal co-contributors
    Given there is an article:
      """
        {
          "title": "VOR 00731",
          "version": 1,
          "doi": "10.7554/eLife.00731",
          "volume": 2,
          "elocation-id": "e00731",
          "article-id": "10.7554/eLife.00731",
          "article-version-id": "00731",
          "pub-date": "2013-05-28T00:00:00+00:00",
          "path": "content/2/e00731",
          "article-type": "research-article",
          "status": "VOR",
          "publish": true,
          "contributors": [
            {
              "type": "author",
              "equal-contrib": false,
              "id": "author-23",
              "surname": "Martin",
              "given-names": "Frank N",
              "suffix": "Jnr",
              "references": {
                "affiliation": [
                  "aff1"
                ],
                "contribution": [
                  "con1"
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
    And I go to "content/2/e00731"
    Then I should see "Frank N Martin" in the ".author-tooltip-name" element
    And I should not see "Listed in alphabetical order with:" in the ".author-tooltip-label" element
