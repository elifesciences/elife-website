Feature: Deceased
  In order to be notified of the deceased
  As a reader
  I should see the label Deceased in the deceased author's tooltip

  @hover
  Scenario: Author is deceased
    Given there is an article:
      """
        {
          "title": "VOR 01861",
          "version": 1,
          "doi": "10.7554/eLife.01861",
          "volume": 3,
          "elocation-id": "e01861",
          "article-id": "10.7554/eLife.01861",
          "article-version-id": "01861",
          "pub-date": "2014-04-15T00:00:00+00:00",
          "path": "content/3/e01861",
          "article-type": "research-article",
          "status": "VOR",
          "publish": true,
          "contributors": [
            {
              "type": "author",
              "equal-contrib": true,
              "id": "author-23",
              "deceased": true,
              "surname": "Widom",
              "given-names": "Jonathan",
              "references": {
                "affiliation": [
                  "aff1"
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
              }
            },
            "foot-note": {
              "fn1": {
                "type": "deceased",
                "value": "Deceased"
              }
            }
          }
        }
      """
    And I go to "content/3/e01861"
    Then I should see "Jonathan Widom" in the ".elife-article-author-item" element
    And I should see "Deceased" in the ".author-tooltip" element

  Scenario: Author is not deceased
    Given there is an article:
      """
        {
          "title": "VOR 01861",
          "version": 1,
          "doi": "10.7554/eLife.01861",
          "volume": 3,
          "elocation-id": "e01861",
          "article-id": "10.7554/eLife.01861",
          "article-version-id": "01861",
          "pub-date": "2014-04-15T00:00:00+00:00",
          "path": "content/3/e01861",
          "article-type": "research-article",
          "status": "VOR",
          "publish": true,
          "contributors": [
            {
              "type": "author",
              "equal-contrib": true,
              "id": "author-23",
              "surname": "Widom",
              "given-names": "Jonathan",
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
                "dept": "department1",
                "institution": "inst1",
                "city": "city1",
                "country": "Country1"
              }
            },
            "foot-note": {
              "fn1": {
                "type": "deceased",
                "value": "Deceased"
              }
            }
          }
        }
      """
    And I go to "content/3/e01861"
    Then I should see "Jonathan Widom" in the ".elife-article-author-item" element
    And I should not see "Deceased" in the ".author-tooltip" element
