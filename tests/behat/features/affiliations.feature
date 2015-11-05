@develop
Feature: Affiliations
  In Order to be able to see the Institutions the author is associated with
  As a reader
  I should be able to see the list of institutions under the list of authors on the article

  Scenario: List of institutions author is associated with is shown in the tooltip
    Given the markup service is available
    And there is an article:
    """
        {
          "title": "VOR 00288",
          "version": "1",
          "doi": "10.7554/eLife.00288",
          "volume": "2",
          "elocation-id": "e00288",
          "article-id": "10.7554/eLife.00288",
          "article-version-id": "00288.1",
          "pub-date": "2014-10-14",
          "path": "content/2/e00288v1",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1",
          "contributors": [
            {
              "equal-contrib": "yes",
              "type": "author",
              "id": "author-23",
              "surname": "Alegado",
              "given-names": "Boris",
              "references": {
                "affiliation": [
                  "aff1"
                ]
              }
            },
            {
              "equal-contrib": "yes",
              "type": "author",
              "id": "author-24",
              "surname": "Alegado",
              "given-names": "Mary",
              "references": {
                "affiliation": [
                  "aff2"
                ]
              }
            }
          ],
          "referenced": {
            "affiliation": {
              "aff1": {
                "dept": "department",
                "institution": "Fred Hutchinson Cancer Research Center",
                "city": "city",
                "country": "United States"
              },
              "aff2": {
                "dept": "department",
                "institution": "Cancer Research Center",
                "city": "city",
                "country": "United States"
              }
            }
          }
        }
      """
    And I go to "content/2/e00288v1"
    Then I should see "Boris" in the ".given-names" element
    And I should see "Fred Hutchinson Cancer Research Center, United States; Cancer Research Center, United States" in the ".elife-institutions-list" element
