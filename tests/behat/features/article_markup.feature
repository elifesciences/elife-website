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
          },
          {
            "title": "The genome sequence of the colonial chordate, <italic>Botryllus schlosseri</italic>",
            "version": 1,
            "doi": "10.7554/eLife.03981",
            "volume": 3,
            "elocation-id": "e03981",
            "article-id": "03981",
            "article-version-id": "03981.1",
            "pub-date": "1979-08-17T00:00:00+00:00",
            "path": "content/3/e03981v1",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true,
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
            "title": "Rapid localized spread and immunologic containment define Herpes simplex virus-2 reactivation in the human genital tract",
            "version": 1,
            "doi": "10.7554/eLife.00288",
            "volume": 2,
            "elocation-id": "e00288",
            "article-id": "00288",
            "article-version-id": "00288.1",
            "pub-date": "1979-08-17T00:00:00+00:00",
            "path": "content/2/e00288v1",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true,
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
    Then I visit "content/4/e05224v2"
    Then I should see "diet, kinship, and shared environments" in the "#abstract" element
    And I should see 1 "#abstract" element
    And I should see 1 "#digest" element
    And I should see 1 "#main-text" element
    And I should see 1 "#references" element
    And I should see 1 "#acknowledgements" element
    And I should see 1 "#decision-letter" element
    And I should see 1 "#author-response" element
  
  Scenario: Article does not have author-response and decision letter section
    Then I visit "content/3/e03981v1"
    Then I should see "scientific communities and scientific journals" in the "#abstract" element
    And I should see 1 "#abstract" element
    And I should not see an "#digest" element
    And I should see 1 "#main-text" element
    And I should see 1 "#references" element
    And I should not see an "#acknowledgements" element
    And I should not see an "#decision-letter" element
    And I should not see an "#author-response" element

  Scenario: Article displays appropriate content in main-text
    Then I visit "content/2/e00288v1"
    When the search index is updated
    And I should see "Introduction" in the "#main-text" element
    And I should see "Results" in the "#main-text" element
    And I should see "Discussion" in the "#main-text" element
    And I should see "Materials and methods" in the "#main-text" element
    Then I should see "The model reproduced heterogeneity in shedding episode duration and viral production" in the "#abstract" element
    Then I should see "sampling from blood may reflect true host–pathogen dynamics due to homogeneous mixing of viruses" in the "#main-text" element

  Scenario: Searching articles with text available in abstract section
    When the search index is updated
    Given I am on "/search"
    And I fill in "Search for..." with "scientific communities and scientific journals"
    And I press the Search button
    And I should see "The genome sequence of the colonial chordate,"
    And I fill in "Search for..." with "diet, kinship, and shared environments"
    And I press the Search button
    And I should see "VOR 05224 v2"
    And I should not see "the genome sequence"
    And I fill in "Search for..." with "sampling from blood may reflect true host–pathogen dynamics"
    And I press the Search button
    And I should not see "VOR 05224 v2"
    And I should not see "the genome sequence"
    And I fill in "Search for..." with "££$%^&"
    And I press the Search button
    And I should see "Your search yielded no results."

  Scenario: Searching articles with text available in main section
    When the search index is updated
    Given I am on "/search"
    And I fill in "Search for..." with " dynamics of most chronic viral infections"
    And I press the Search button
    And I should see "Rapid localized spread and immunologic containment define Herpes simplex virus-2 reactivation in the human genital tract"
    And I fill in "Search for..." with "Irreproducible studies that side-track fields"
    And I press the Search button
    And I should see "The genome sequence of the colonial chordate"
    And I should not see "VOR 05224 v2"
    And I fill in "Search for..." with "sampling from blood may reflect true host–pathogen dynamics"
    And I press the Search button
    And I should not see "VOR 05224 v2"
    And I should not see "the genome sequence"
