@citation
Feature: Citation formats
  In order to import the article into third party software
  As a researcher
  I need to have access to the citation formats of the article

  @api
  Scenario: Article page displays links to available citation formats
    Given the citation service is available
    And there are articles:
      """
        [
          {
            "title": "VOR 05224 v2",
            "version": 2,
            "doi": "10.7554/eLife.05224",
            "volume": 4,
            "elocation-id": "e05224",
            "article-id": "05224",
            "article-version-id": "05224.2",
            "pub-date": "1979-08-17T00:00:00+00:00",
            "path": "content/4/e05224v2",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true,
            "keywords": {
              "author-keywords": [
                "Algoriphagus"
              ]
            }
          }
        ]
      """
    When I visit "content/4/e05224v2"
    And I follow "BibTeX"
    Then I should see the header content filename "vor-05224-v2.bib"
    And the response body should contain "title = {Social networks predict gut microbiome composition in wild baboons}"
    When I visit "content/4/e05224v2"
    And I follow "RIS"
    Then I should see the header content filename "vor-05224-v2.ris"
    And the response body should contain "TI  - Social networks predict gut microbiome composition in wild baboons"
