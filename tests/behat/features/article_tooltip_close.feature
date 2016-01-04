@develop
Feature: Footnote
  In order to be able to close tooltip
  As a reader
  I should be able to see the "CLOSE" button in the author tooltip

  @javascript
  Scenario: Closing author tooltip by close button
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
          "publish": true
        }
      """
    And I go to "content/4/e05003"
    Then I should see "Close" in the "#cluetip .cluetip-outer .cluetip-inner .cluetip-close a" element
