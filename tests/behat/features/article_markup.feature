@markup
Feature: Markup
  In order to easily read the research
  As a reader of the site
  I need to have access to the rendered articles

  @api
  Scenario: Article page displays the appropiate content on the article page
    Given the markup service is available
    And there are articles:
      """
        [
          {
            "title": "VOR 05224",
            "version": "1",
            "doi": "10.7554/eLife.05224",
            "volume": "4",
            "elocation-id": "e05224",
            "article-id": "05224",
            "article-version-id": "05224",
            "pub-date": "1979-08-17",
            "path": "content/4/e05224",
            "article-type": "research-article",
            "status": "VOR",
            "publish": "1",
            "keywords": {
              "author-keywords": [
                "Algoriphagus"
              ]
            }
          }
        ]
      """
    And the search index is updated
    When I visit "content/4/e05224"
    Then I should see "diet, kinship, and shared environments" in the "#abstract" element
    And I should see 1 "#abstract" element
    And I should see 1 "#digest" element
    And I should see 1 "#main-text" element
    And I should see 1 "#references" element
    And I should see 1 "#acknowledgements" element
    And I should see 1 "#decision-letter" element
    And I should see 1 "#author-response" element
