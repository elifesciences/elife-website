Feature: Article Resource - Keywords (API)
  In order to maintain article content
  As a production system
  I need to be able to assign the content to keywords via the resource api

  Scenario Outline: Set keywords
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05224",
          "version": "1",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "elocation-id": "e05224",
          "article-id": "10.7554/eLife.05224",
          "article-version-id": "05224",
          "pub-date": "1979-08-17",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1",
          "keywords": {
            <keywords>
          }
        }
      """
    And the response code should be 200
    When I send a GET request to "api/article/05224.json"
    Then the response should contain json:
      """
        {
          "title": "VOR 05224",
          "keywords": {
            <keywords>
          }
        }
      """

    Examples:
      | keywords                                                                                                                                          |
      | "author-keywords": ["<italic>Salpingoeca rosetta</italic>", "Algoriphagus"]                                                                       |
      | "author-keywords": ["<italic>Salpingoeca rosetta</italic>", "Algoriphagus"], "research-organism": ["Mouse","<italic>C. elegans</italic>","Other"] |
