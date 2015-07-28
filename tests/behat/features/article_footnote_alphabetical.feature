Feature: Alphabetical
In order to ensure that my contribution to the paper is not tied to my position in the author list
As an author
I should be listed in alphabetical order with other authors

  Scenario: View alphabetical listing of authors when there is more than one contributor
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 00731",
          "version": "1",
          "doi": "10.7554/eLife.00731",
          "volume": "4",
          "article-id": "10.7554/eLife.00731",
          "article-version-id": "00731",
          "pub-date": "2013-05-28",
          "path": "content/2/e00731",
          "article-type": "research-article",
          "status": "VOR"
        }
      """
And the response code should be 200
And I go to "content/4/e05003"
Then I should see "<author>" in the ".author-tooltip-name" element
And I should see "Listed in alphabetical order with:" in the ".author-tooltip-label" element
And I should see "<author_list>" in the ".author-tooltip-label" element
And I should not see "<bad_author_list>" in the ".author-tooltip-label" element


Examples:
| author         | author_list                                  | bad_author_list                                              |
| Sophien Kamoun | Johannes Krause, Marco Thines, Detlef Weigel | Sophien Kamoun, Johannes Krause, Marco Thines, Detlef Weigel |

  Scenario: No alphabetical listing of authors when there are no co-contributor
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
    """
        {
          "title": "VOR 00731",
          "version": "1",
          "doi": "10.7554/eLife.00731",
          "volume": "2",
          "article-id": "10.7554/eLife.00731",
          "article-version-id": "00731",
          "pub-date": "2013-05-28",
          "path": "content/2/e00731",
          "article-type": "research-article",
          "status": "VOR"
        }
      """
    And the response code should be 200
    And I go to "content/4/e05003"
    Then I should see "Frank N Martin" in the ".author-tooltip-name" element
    And I should not see "Listed in alphabetical order with:" in the ".author-tooltip-label" element
