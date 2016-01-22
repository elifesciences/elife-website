Feature: OA & CC logo
  In order to establish that the article belongs to Open Access and No copyright domain
  As a website user
  I need to see respective logos with the article title

  Scenario: OA and CC logos are displayed
    Given there is an article:
    """
        {
          "title": "VOR 00007",
          "version": 1,
          "doi": "10.7554/eLife.00007",
          "volume": 1,
          "elocation-id": "e00007",
          "article-id": "10.7554/eLife.00007",
          "article-version-id": "00007",
          "pub-date": "2012-10-15T00:00:00+00:00",
          "path": "content/1/e00007",
          "article-type": "research-article",
          "status": "VOR",
          "publish": true
        }
      """
    And I visit "content/1/e00007"
    Then I should see an ".elife-article-indicators" element
    Then I should see the url "http://en.wikipedia.org/wiki/Open_access" in the "href" attribute of the ".elife-article-indicators a:first-child" element
    Then I should see the image "http://127.0.0.1:80/profiles/elife_profile/modules/custom/elife_templates/images/oa.png" in the ".elife-article-indicators a:first-child img" element
    Then I should see "Open access" in the "title" attribute of the ".elife-article-indicators a:first-child img" element
    Then I should see the url "http://127.0.0.1:80/cc-link" in the "href" attribute of the ".elife-article-indicators a:nth-child(2)" element
    Then I should see the image "http://127.0.0.1:80/profiles/elife_profile/modules/custom/elife_templates/images/cc.png" in the ".elife-article-indicators a:nth-child(2) img" element
    Then I should see "Copyright info" in the "title" attribute of the ".elife-article-indicators a:nth-child(2) img" element
