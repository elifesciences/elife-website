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
          "status": "VOR"
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
          "status": "VOR"
        }
      """
    And the response code should be 200
    And I go to "content/4/e07091"
    Then I should see "Miguel Abal" in the ".author-tooltip-name" element
    And I should not see "For Correspondence" in the ".author-tooltip-label" element

