Feature: Footnote
  In order to be able to close rollover
  As a reader
  I should be able to see the "CLOSE" button in the author rollover

  @debug @javascript
  Scenario: Closing author rollover by close button
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
    """
        {
          "title": "VOR 05003",
          "version": "1",
          "doi": "10.7554/eLife.05003",
          "volume": "4",
          "elocation-id": "e05003",
          "article-id": "10.7554/eLife.05003",
          "article-version-id": "05003",
          "pub-date": "2015-04-02",
          "path": "content/4/e05003",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1"
        }
      """
    And the response code should be 200
    And I go to "content/4/e05003"
    And I should see "Close" in the ".cluetip-close" element
    And I should see "Close" in the ".cluetip-close a" element