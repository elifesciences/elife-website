Feature: Article Resource - Legacy Redirects
  In order to route users to the latest pdf or xml
  As a website visitor
  We must honour the old format of links to the full pdf or xml

  Background:
    Given redirects are not followed

  Scenario: Old style PDF urls redirect to latest version of an article's pdf
    Given there are articles:
      """
        [
          {
            "title": "05224 POA v1",
            "version": 1,
            "doi": "10.7554/eLife.05224",
            "volume": 4,
            "elocation-id": "e05224",
            "article-id": "05224",
            "article-version-id": "05224.1",
            "pub-date": "1979-08-15T00:00:00+00:00",
            "update": "1979-08-15T00:00:00+00:00",
            "path": "content/4/e05224v1",
            "article-type": "research-article",
            "status": "POA",
            "publish": true
          },
          {
            "title": "05224 VOR v2",
            "version": 2,
            "doi": "10.7554/eLife.05224",
            "volume": 4,
            "elocation-id": "e05224",
            "article-id": "05224",
            "article-version-id": "05224.2",
            "pub-date": "1979-08-15T00:00:00+00:00",
            "update": "1979-08-16T00:00:00+00:00",
            "path": "content/4/e05224v2",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true
          },
          {
            "title": "05224 VOR v3",
            "version": 3,
            "doi": "10.7554/eLife.05224",
            "volume": 4,
            "elocation-id": "e05224",
            "article-id": "05224",
            "article-version-id": "05224.3",
            "pub-date": "1979-08-15T00:00:00+00:00",
            "update": "1979-08-17T00:00:00+00:00",
            "path": "content/4/e05224v3",
            "article-type": "research-article",
            "status": "VOR",
            "publish": false
          }
        ]
      """
    When I go to "content/4/e05224.full.pdf"
    Then I should be redirected to "content/4/e05224.pdf" with a 301

    Given there is an article:
      """
        {
          "title": "05224 VOR v3",
          "version": 3,
          "doi": "10.7554/eLife.05224",
          "volume": 4,
          "elocation-id": "e05224",
          "article-id": "05224",
          "article-version-id": "05224.3",
          "pub-date": "1979-08-15T00:00:00+00:00",
          "update": "1979-08-17T00:00:00+00:00",
          "path": "content/4/e05224v3",
          "article-type": "research-article",
          "status": "VOR",
          "publish": true
        }
      """
    When I go to "content/4/e05224.full.pdf"
    Then I should be redirected to "content/4/e05224.pdf" with a 301

  Scenario: Old style XML urls redirect to latest version of an article's xml
    Given there are articles:
      """
        [
          {
            "title": "05224 POA v1",
            "version": 1,
            "doi": "10.7554/eLife.05224",
            "volume": 4,
            "elocation-id": "e05224",
            "article-id": "05224",
            "article-version-id": "05224.1",
            "pub-date": "1979-08-15T00:00:00+00:00",
            "update": "1979-08-15T00:00:00+00:00",
            "path": "content/4/e05224v1",
            "article-type": "research-article",
            "status": "POA",
            "publish": true
          },
          {
            "title": "05224 VOR v2",
            "version": 2,
            "doi": "10.7554/eLife.05224",
            "volume": 4,
            "elocation-id": "e05224",
            "article-id": "05224",
            "article-version-id": "05224.2",
            "pub-date": "1979-08-15T00:00:00+00:00",
            "update": "1979-08-16T00:00:00+00:00",
            "path": "content/4/e05224v2",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true
          },
          {
            "title": "05224 VOR v3",
            "version": 3,
            "doi": "10.7554/eLife.05224",
            "volume": 4,
            "elocation-id": "e05224",
            "article-id": "05224",
            "article-version-id": "05224.3",
            "pub-date": "1979-08-15T00:00:00+00:00",
            "update": "1979-08-17T00:00:00+00:00",
            "path": "content/4/e05224v3",
            "article-type": "research-article",
            "status": "VOR",
            "publish": false
          }
        ]
      """
    When I go to "content/4/e05224.source.xml"
    Then I should be redirected to "http://parallel-elife-publishing-cdn.s3.amazonaws.com/05224/elife-05224-v2.xml" with a 302

    Given there is an article:
      """
        {
          "title": "05224 VOR v3",
          "version": 3,
          "doi": "10.7554/eLife.05224",
          "volume": 4,
          "elocation-id": "e05224",
          "article-id": "05224",
          "article-version-id": "05224.3",
          "pub-date": "1979-08-15T00:00:00+00:00",
          "update": "1979-08-17T00:00:00+00:00",
          "path": "content/4/e05224v3",
          "article-type": "research-article",
          "status": "VOR",
          "publish": true
        }
      """
    When I go to "content/4/e05224.source.xml"
    Then I should be redirected to "http://parallel-elife-publishing-cdn.s3.amazonaws.com/05224/elife-05224-v3.xml" with a 302
