Feature: Footnote
  In order to notify user of deceased authors
  As a publisher
  I should display to see deceased in the deceased author's rollover

  @hover
  Scenario: Author has not provided email id
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
    """
        {
          "title": "VOR 05227",
          "version": "1",
          "doi": "10.7554/eLife.05227",
          "volume": "4",
          "article-id": "10.7554/eLife.05227",
          "article-version-id": "05227",
          "pub-date": "1979-08-17",
          "path": "content/4/e05227",
          "article-type": "research-article",
          "status": "VOR"
        }
      """
    And the response code should be 200
    And I go to "content/4/e05227"
    And I hover over the author "<author>" in the ".elife-article-author-item" element
    Then I should see the "author-info" tooltip