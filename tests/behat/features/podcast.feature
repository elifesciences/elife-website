Feature: Podcast
  As a website user
  I want to easily find the latest podcast
  So I can review the latest research when I am away from my computer

  @api
  Scenario: Find podcast link on a Research article page
    Given "elife_podcast" content:
      | title      | field_elife_p_articles |
      | Podcast 13 | 05224                  |
    And I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05224",
          "version": "1",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "elocation-id": "e05224",
          "article-id": "05224",
          "article-version-id": "05224.1",
          "pub-date": "1979-08-17",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1"
        }
      """
    And the response code should be 200
    When I am on "content/4/e05224"
    Then I should see the link "Podcast 13" in the "sidebar" region

  @api
  Scenario: Only display podcast link on appropriate page
    Given "elife_podcast" content:
      | title      | field_elife_p_articles |
      | Podcast 13 | 05224, 05226           |
    And I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05224",
          "version": "1",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "elocation-id": "e05224",
          "article-id": "05224",
          "article-version-id": "05224.1",
          "pub-date": "1979-08-17",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1"
        }
      """
    And the response code should be 200
    And I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05225",
          "version": "1",
          "doi": "10.7554/eLife.05225",
          "volume": "4",
          "elocation-id": "e05225",
          "article-id": "05225",
          "article-version-id": "05225.1",
          "pub-date": "1979-08-18",
          "path": "content/4/e05225",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1"
        }
      """
    And the response code should be 200
    And I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05226",
          "version": "1",
          "doi": "10.7554/eLife.05226",
          "volume": "4",
          "elocation-id": "e05226",
          "article-id": "05226",
          "article-version-id": "05226.1",
          "pub-date": "1979-08-19",
          "path": "content/4/e05226",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1"
        }
      """
    And the response code should be 200
    Then I am on "content/4/e05224"
    And I should see the link "Podcast 13" in the "sidebar" region
    And I am on "content/4/e05225"
    And I should not see the link "Podcast 13"
    And I am on "content/4/e05226"
    And I should see the link "Podcast 13" in the "sidebar" region
