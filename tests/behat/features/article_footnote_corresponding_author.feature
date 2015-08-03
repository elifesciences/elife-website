Feature: Footnote
  In Order to be able to contact a corresponding author
  As a reader
  I should be able to see the email id in the author rollover

  @hover
  Scenario Outline: Author has provided email id
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
    """
        {
          "title": "VOR 07091",
          "version": "1",
          "doi": "10.7554/eLife.07091",
          "volume": "4",
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
            "equal-contrib": "yes",
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
              "aff3":{
                "dept": "department3",
                "institution": "inst3",
                "city": "city3",
                "country": "Country3"
              }
            },
          "contribution":
          {
            "con1": "RAA, Conception and design, Acquisition of data, Analysis and interpretation of data, Drafting or revising the article",
            "con2": "RAA, Conception and design, Analysis and interpretation of data, Drafting or revising the article",
            "con3": "RAA, Conception and design, Drafting or revising the article"
          }
        }
        }
      """
    And the response code should be 200
    And I go to "content/4/e07091"
    Then I should see "<author>" in the ".author-tooltip-name" element
    And I should see "<author_email>" in the ".author-tooltip-text a"
    And I should see "For Correspondence" in the ".author-tooltip-label" element

  Examples:
    | author                  |  author_email   |
    | Mikel Garcia-Marcos     | mgm1@bu.edu     |
    | Pradipta Ghosh          | prghosh@ucsd.edu|


  Scenario: Author has not provided email id
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
    """
        {
          "title": "VOR 07091",
          "version": "1",
          "doi": "10.7554/eLife.07091",
          "volume": "4",
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
              "id": "<id>",
              "surname": "Alegado",
              "given-names": "<author>",
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
    And the response code should be 200
    And I go to "content/4/e07091"
    Then I should see "Miguel Abal" in the ".author-tooltip-name" element
    And I should not see "For Correspondence" in the ".author-tooltip-label" element

