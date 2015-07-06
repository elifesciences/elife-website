Feature: Article Resource - Categories (API)
  In order to maintain article content
  As a production system
  I need to be able to assign the content to a display-channel and headings via the resource api

  Scenario Outline: Set a display channel
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05224",
          "version": "1",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "article-id": "10.7554/eLife.05224",
          "article-version-id": "05224",
          "pub-date": "1979-08-17",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1",
          "categories": {
            "display-channel": [
              "<display_channel>"
            ],
            "heading": [
              "Cell biology",
              "Computer science"
            ]
          }
        }
      """
    And the response code should be 200
    When I send a GET request to "api/article/05224.json"
    Then the response should contain json:
      """
        {
          "title": "VOR 05224",
          "categories": {
            "display-channel": [
              "<display_channel>"
            ],
            "heading": [
              "Cell biology",
              "Computer science"
            ]
          }
        }
      """

    Examples:
      | display_channel  |
      | Research article |
      | Insight          |

  Scenario Outline: Set a sub-display channel
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05224",
          "version": "1",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "article-id": "10.7554/eLife.05224",
          "article-version-id": "05224",
          "pub-date": "1979-08-17",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1",
          "categories": {
            "sub-display-channel": [
              "<sub_display_channel>"
            ],
            "display-channel": [
              "Research article"
            ],
            "heading": [
              "Cell biology",
              "Computer science"
            ]
          }
        }
      """
    And the response code should be 200
    When I send a GET request to "api/article/05224.json"
    Then the response should contain json:
      """
        {
          "title": "VOR 05224",
          "categories": {
            "sub-display-channel": [
              "<sub_display_channel>"
            ],
            "display-channel": [
              "Research article"
            ],
            "heading": [
              "Cell biology",
              "Computer science"
            ]
          }
        }
      """

    Examples:
      | sub_display_channel |
      | Living science      |
      | Research            |
      | DNA helicases       |

  Scenario Outline: Set headings
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05224",
          "version": "1",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "article-id": "10.7554/eLife.05224",
          "article-version-id": "05224",
          "pub-date": "1979-08-17",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1",
          "categories": {
            "display-channel": [
              "Research article"
            ],
            "heading": [
              <heading>
            ]
          }
        }
      """
    And the response code should be 200
    When I send a GET request to "api/article/05224.json"
    Then the response should contain json:
      """
        {
          "title": "VOR 05224",
          "categories": {
            "display-channel": [
              "Research article"
            ],
            "heading": [
              <heading>
            ]
          }
        }
      """

    Examples:
      | heading                                           |
      | "Cell biology","Computer science"                  |
      | "Immunology","Microbiology and infectious disease" |
