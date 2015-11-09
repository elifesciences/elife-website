@api @markup
Feature: Markup
  In order to easily read the research
  As a reader of the site
  I need to have access to the rendered articles

  Background:
    Given the markup service is available
    And there are articles:
    """
        [
          {
            "title": "VOR 05224 v2",
            "version": "2",
            "doi": "10.7554/eLife.05224",
            "volume": "4",
            "elocation-id": "e05224",
            "article-id": "05224",
            "article-version-id": "05224.2",
            "pub-date": "1979-08-17",
            "path": "content/4/e05224v2",
            "article-type": "research-article",
            "status": "VOR",
            "publish": "1",
            "keywords": {
              "author-keywords": [
                "Algoriphagus"
              ]
            }
          },
          {
            "title": "The genome sequence of the colonial chordate, <italic>Botryllus schlosseri</italic>",
            "version": "1",
            "doi": "10.7554/eLife.00569",
            "volume": "2",
            "elocation-id": "e00569",
            "article-id": "00569",
            "article-version-id": "00569",
            "pub-date": "1979-08-17",
            "path": "content/2/e00569",
            "article-type": "research-article",
            "status": "VOR",
            "publish": "1",
            "keywords": {
              "author-keywords": [
                "social behavior",
                "gut microbiome",
                "metagenomics",
                "transmission",
                "social network"
                ]
              }
            }
            ,
            {
            "title": "Mitotic spindle scaling during <italic>Xenopus</italic> development by kif2a and importin α",
            "version": "1",
            "doi": "10.7554/eLife.00290",
            "volume": "2",
            "elocation-id": "e00290",
            "article-id": "00290",
            "article-version-id": "00290",
            "pub-date": "1979-08-17",
            "path": "content/2/e00290",
            "article-type": "research-article",
            "status": "VOR",
            "publish": "1",
            "keywords": {
              "author-keywords": [
                "Xenopus",
                "embryogenesis"
                                 ]
                         }
            }
        ]
      """

  Scenario: Article page displays the appropriate content on the article page
    When the search index is updated
    Then I visit "content/4/e05224"
    Then I should see "diet, kinship, and shared environments" in the "#abstract" element
    And I should see 1 "#abstract" element
    And I should see 1 "#digest" element
    And I should see 1 "#main-text" element
    And I should see 1 "#references" element
    And I should see 1 "#acknowledgements" element
    And I should see 1 "#decision-letter" element
    And I should see 1 "#author-response" element

  Scenario: Article does not have author-response and decision letter section
    Then I visit "content/2/e00569"
    Then I should see "evolution of vertebrates and lymphoid-mediated" in the "#abstract" element
    And I should see 1 "#abstract" element
    And I should see 1 "#digest" element
    And I should see 1 "#main-text" element
    And I should see 1 "#references" element
    And I should see 1 "#acknowledgements" element
    And I should not see an "#decision-letter" element
    And I should not see an "#author-response" element

  Scenario: Article displays appropriate content in main-text
    Then I visit "content/2/e00290"
    When the search index is updated
    And I should see "Introduction" in the "#main-text" element
    And I should see "Results" in the "#main-text" element
    And I should see "Discussion" in the "#main-text" element
    And I should see "Materials and methods" in the "#main-text" element
    Then I should see "mechanisms that scale the spindle during Xenopus laevis embryogenesis" in the "#abstract" element
    Then I should see "must adjust to cell size to segregate chromosomes" in the "#main-text" element

  Scenario: Searching articles with text available in abstract section
    When the search index is updated
    Given I am on "/elife/search"
    And I fill in "Keyword" with "evolution of vertebrates and lymphoid-mediated"
    And I press the Search button
    And I should see "The genome sequence of the colonial chordate,"
    And I fill in "Keyword" with "diet, kinship, and shared environments"
    And I press the Search button
    And I should see "VOR 05224"
    And I should not see "the genome sequence"
    And I fill in "Keyword" with "must adjust to cell size to segregate chromosomes"
    And I press the Search button
    And I should not see "VOR 05224"
    And I should not see "the genome sequence"
    And I fill in "Keyword" with "££$%^&"
    And I press the Search button
    And I should see "Your search yielded no results."