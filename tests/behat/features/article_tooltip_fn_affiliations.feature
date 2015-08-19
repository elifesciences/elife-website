Feature: Footnote
  In Order to be able to see the Institutions the author is associated with
  As a reader
  I should be able to see the list of institutions in the author tooltip

  Scenario Outline: List of institutions author is associated with is shown in the tooltip
    Given there is an article:
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
    And I go to "content/3/e04046"
    Then I should see "<author>" in the ".author-tooltip-name" element
    And I should see "<dept>" in the ".dept" element
    And I should see "<institution>" in the ".institution" element
    And I should see "<city>" in the ".city" element
    And I should see "<country>" in the ".country" element

    Examples:
      | id        | author  | dept                                                | institution                | city  | country |
      | author-23 | Boris   | Laboratory of Neurophysics and Physiology, UMR 8119 | Paris Descartes University | Paris | France  |
      | author-24 | Rebecca | Laboratory of Neurophysics and Physiology, UMR 8119 | Paris Descartes University | Paris | France  |
