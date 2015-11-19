Feature: Article Resource - DOI Lookup
  In order to avoid a trip to crossref and easily access the latest article version
  As a website user
  The internal doi links should redirect to the latest version of the article

  Background:
    Given redirects are not followed

  Scenario: Internal doi lookup redirects to latest published version of an article
    Given there are articles:
      """
        [
          {
            "title": "05224 POA v1",
            "version": "1",
            "doi": "10.7554/eLife.05224",
            "volume": "4",
            "elocation-id": "e05224",
            "article-id": "05224",
            "article-version-id": "05224.1",
            "pub-date": "1979-08-15",
            "update": "1979-08-15",
            "path": "content/4/e05224v1",
            "article-type": "research-article",
            "status": "POA",
            "publish": "1"
          },
          {
            "title": "05224 VOR v2",
            "version": "2",
            "doi": "10.7554/eLife.05224",
            "volume": "4",
            "elocation-id": "e05224",
            "article-id": "05224",
            "article-version-id": "05224.2",
            "pub-date": "1979-08-15",
            "update": "1979-08-16",
            "path": "content/4/e05224v2",
            "article-type": "research-article",
            "status": "VOR",
            "publish": "1"
          },
          {
            "title": "05224 VOR v3",
            "version": "3",
            "doi": "10.7554/eLife.05224",
            "volume": "4",
            "elocation-id": "e05224",
            "article-id": "05224",
            "article-version-id": "05224.3",
            "pub-date": "1979-08-15",
            "update": "1979-08-17",
            "path": "content/4/e05224v3",
            "article-type": "research-article",
            "status": "VOR",
            "publish": "0"
          }
        ]
      """
    When I go to "lookup/doi/10.7554/eLife.05224"
    Then I should be redirected to "content/4/e05224v2" with a 302

    Given there is an article:
      """
        {
          "title": "05224 VOR v3",
          "version": "3",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "elocation-id": "e05224",
          "article-id": "10.7554/eLife.05224",
          "article-version-id": "05224.3",
          "pub-date": "1979-08-15",
          "update": "1979-08-17",
          "path": "content/4/e05224v3",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1"
        }
      """
    When I go to "lookup/doi/10.7554/eLife.05224"
    Then I should be redirected to "content/4/e05224v3" with a 302
