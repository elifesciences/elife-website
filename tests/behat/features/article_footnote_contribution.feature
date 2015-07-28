Feature: Contribution
  In order to be able to get credit for my work
  As an author
  I should see my name as contributor to the paper listed

  @javascript @hover
  Scenario Outline: Contribution listed in author rollover
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
    """
        {
          "title": "VOR 03895",
          "version": "1",
          "doi": "10.7554/eLife.03895",
          "volume": "3",
          "article-id": "10.7554/eLife.03895",
          "article-version-id": "05227",
          "pub-date": "2014-11-13",
          "path": "content/3/e03895",
          "article-type": "research-article",
          "status": "VOR"
        }
      """
    And the response code should be 200
    And I go to "content/3/e03895"
    Then I should see "<author>" in the ".author-tooltip" element
    Then I should see "Contribution:" in the ".author-tooltip-contrib .author-tooltip-label" element
    And I should see the text "<author_contribution>"

  Examples:
    | author               | author_contribution                                                                                               |
    | Till F M Andlauer    | Conception and design, Acquisition of data, Analysis and interpretation of data, Drafting or revising the article |
    | Markus C Wahl        | Conception and design, Drafting or revising the article                                                           |
    | Matthew G Holt       | Conception and design, Analysis and interpretation of data                                                        |

