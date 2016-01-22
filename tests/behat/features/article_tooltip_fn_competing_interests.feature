Feature: Competing Interests in Footnotes
  In order to be able to see competing interests declared be the author
  As a reader
  I should be able to see the competing interests are declared or not by the author

  Scenario: Author has not declared competing interests
    Given there is an article:
      """
        {
          "title": "VOR 05003",
          "version": 1,
          "doi": "10.7554/eLife.05003",
          "volume": 4,
          "elocation-id": "e05003",
          "article-id": "10.7554/eLife.05003",
          "article-version-id": "05003",
          "pub-date": "2015-04-02T00:00:00+00:00",
          "path": "content/4/e05003",
          "article-type": "research-article",
          "status": "VOR",
          "publish": true,
          "contributors": [
            {
              "equal-contrib": true,
              "type": "author",
              "id": "author-15",
              "surname": "Alegado",
              "given-names": "Rosaine",
              "references": {
                "affiliation": [
                  "aff1"
                ],
                "competing-interest": [
                  "conf1"
                ]
              }
            }
          ],
          "referenced": {
            "affiliation": {
              "aff1": {
                "dept": "dept1",
                "institution": "institution2",
                "city": "city2",
                "country": "country2"
              }
            },
            "competing-interest": {
              "conf1": "Author has declared no competing interests"
            }
          }
        }
      """
    And I go to "content/4/e05003"
    Then I should see "No competing interests declared" in the ".author-tooltip-conflict" element

  Scenario Outline: Author has declared competing interests
    Given there is an article:
    """
      {
        "article-type": "correction",
        "title": "Correction: A novel GTP-binding protein–adaptor protein complex responsible for export of Vangl2 from the <italic>trans</italic> Golgi network",
        "status": "VOR",
        "publish": true,
        "doi": "10.7554/eLife.01328",
        "pub-date": "2013-08-28T00:00:00+00:00",
        "volume": 2,
        "elocation-id": "e01328",
        "path": "content/2/e01328v1",
        "article-id": "01328",
        "categories": {
          "display-channel": [
            "Correction"
          ],
          "heading": [
            "Biochemistry",
            "Cell Biology"
          ]
        },
        "contributors": [
          {
            "type": "author",
            "surname": "Guo",
            "given-names": "Yusong",
            "id": "author-1916",
            "references": {
              "competing-interest": [
                "conf2"
              ]
            }
          },
          {
            "type": "author",
            "surname": "Zanetti",
            "given-names": "Giulia",
            "id": "author-2244",
            "references": {
              "competing-interest": [
                "conf2"
              ]
            }
          },
          {
            "type": "author",
            "surname": "Schekman",
            "given-names": "Randy",
            "id": "author-1032",
            "references": {
              "competing-interest": [
                "conf1"
              ]
            }
          }
        ],
        "referenced": {
          "competing-interest": {
            "conf1": "RS: Editor-in-Chief, <italic>eLife</italic>.",
            "conf2": "The other authors have declared that no competing interests exist."
          }
        },
        "related-articles": [
          {
            "type": "corrected-article",
            "href": "10.7554/eLife.00160"
          }
        ],
        "version": 1,
        "article-version-id": "01328.1"
      }
    """
    And I go to "content/2/e01328v1"
    Then I should see "<author>" in the ".author-list-full li:nth-of-type(<n>) .author-tooltip .author-tooltip-name" element
    Then I should see "<competinginterest>" in the ".author-list-full li:nth-of-type(<n>) .author-tooltip .author-tooltip-conflict" element

    Examples:
      | author          | n | competinginterest                                |
      | Yusong Guo      | 1 | No competing interests declared                  |
      | Giulia Zanetti  | 2 | No competing interests declared                  |
      | Randy Schekman  | 3 | Competing Interests: RS: Editor-in-Chief, eLife. |
