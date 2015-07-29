@debug1
Feature: Footnote
  In Order to be able to see the Institutions the author is associated with
  As a reader
  I should be able to see the list of institutions in the author rollover

  Scenario Outline: List of institutions author is associated with is shown in the rollover

    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
    """
        {
  "title": "VOR 04046",
  "version": "1",
  "doi": "10.7554/eLife.04046",
  "volume": "3",
  "elocation-id": "e04046",
  "article-id": "10.7554/eLife.04046",
  "article-version-id": "04046",
  "pub-date": "2014-10-14",
  "path": "content/3/e04046",
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
    And I go to "content/4/e04046"
    And print response
    Then I should see "<author>" in the ".author-tooltip-name" element
    Then I should see "<dept>" in the ".dept" element
    Then I should see "<institution>" in the ".institution" element
    Then I should see "<city>" in the ".city" element
    Then I should see "<country>" in the ".country" element

    Examples:
  |id         |  author | dept                                                | institution                | city  | country                           |
  | author-23 | Boris   | Laboratory of Neurophysics and Physiology, UMR 8119 | Paris Descartes University | Paris | France          |
  | author-24 |Rebecca | Laboratory of Neurophysics and Physiology, UMR 8119 | Paris Descartes University | Paris | France          |

