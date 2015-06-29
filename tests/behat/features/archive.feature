Feature: Archive
  In order to review previous articles posted in the journal
  As a website user
  I need an archive section

  Scenario: Display general archive listing
    Given I am on "/archive"
    Then the response status code should be 200
    And I should see "Article archive" in the "h1" element

  @api
  Scenario Outline: Access a yearly overview
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
    """
        {
          "title": "<display_channel> <pubdate>",
          "version": "1",
          "doi": "10.7554/eLife.<id>",
          "volume": "1",
          "article-id": "<id>",
          "article-version-id": "<id>.1",
          "pub-date": "<pubdate>",
          "path": "content/1/<id>",
          "article-type": "research-article",
          "status": "VOR",
          "categories": {
            "display-channel": [
              "<display_channel>"
            ]
          }
        }
      """
    And the response code should be 200
    When I am on "/archive/<year>"
    Then the response status code should be <status_code>

    Examples:
      | id | display_channel | pubdate | year | status_code |
      | 00001 | Research article | 2012-01-01 | 2012 | 200 |
      | 00002 | Insight | 2013-02-01 | 2013 | 200 |
      | 00003 | Editorial | 2014-04-01 | 2014 | 200 |
      | 00004 | Feature article | 2015-09-01 | 2015 | 200 |
      | 00001 | Registered report | 2012-01-01 | 1979 | 404 |
      | 00001 | Correction | 2011-01-01 | 2011 | 404 |
      | 00001 | Research article | 2012-01-01 | 2032 | 404 |

  @api
  Scenario: Click on month from yearly archive
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "Article 01/10/2012",
          "version": "1",
          "doi": "10.7554/eLife.00001",
          "volume": "1",
          "article-id": "00001",
          "article-version-id": "00001.1",
          "pub-date": "2012-10-01",
          "path": "content/1/00001",
          "article-type": "research-article",
          "status": "VOR",
          "categories": {
            "display-channel": [
              "Research article"
            ]
          }
        }
      """
    And the response code should be 200
    And I am on "/archive/2012"
    When I follow "October 2012"
    Then the response status code should be 200
    And the url should match "/archive/2012/10"
    And I should see text matching "Article archive, October 2012"
    And I should see text matching "Article 01/10/2012"

  @api
  Scenario Outline: Appropriate heading set for archive listing
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "Article <pubdate>",
          "version": "1",
          "doi": "10.7554/eLife.00001",
          "volume": "1",
          "article-id": "00001",
          "article-version-id": "00001.1",
          "pub-date": "<pubdate>",
          "path": "content/1/00001",
          "article-type": "research-article",
          "status": "VOR",
          "categories": {
            "display-channel": [
              "Research article"
            ]
          }
        }
      """
    And the response code should be 200
    When I am on "/archive/<url>"
    Then I should see "Article archive, <date>" in the "h1" element

    Examples:
      | pubdate | url | date |
      | 2012-10-01 | 2012 | 2012 |
      | 2012-10-01 | 2012/10 | October 2012 |
      | 2013-05-01 | 2013/05 | May 2013 |

  @api
  Scenario Outline: Use the archive jump to dropdown
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "Article <pubdate>",
          "version": "1",
          "doi": "10.7554/eLife.00001",
          "volume": "1",
          "article-id": "00001",
          "article-version-id": "00001.1",
          "pub-date": "<pubdate>",
          "path": "content/1/00001",
          "article-type": "research-article",
          "status": "VOR",
          "categories": {
            "display-channel": [
              "Research article"
            ]
          }
        }
      """
    And the response code should be 200
    And I am on "/archive/<start_url>"
    When I select "<option>" from "elife_archive_month"
    And I press "Go"
    Then the url should match "/archive/<dest_url>"

    Examples:
      | pubdate | option | start_url | dest_url |
      | 2013-02-01 | February 2013 | 2012 | 2013/02 |
      | 2012-11-01 | November 2012 | 2013 | 2012/11 |

  @api @javascript
  Scenario Outline: Use the archive jump to dropdown (javascript)
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "Article <pubdate>",
          "version": "1",
          "doi": "10.7554/eLife.00001",
          "volume": "1",
          "article-id": "00001",
          "article-version-id": "00001.1",
          "pub-date": "<pubdate>",
          "path": "content/1/00001",
          "article-type": "research-article",
          "status": "VOR",
          "categories": {
            "display-channel": [
              "Research article"
            ]
          }
        }
      """
    And the response code should be 200
    And I am on "/archive/<start_url>"
    When I select "<option>" from "elife_archive_month"
    Then the url should match "/archive/<dest_url>"

    Examples:
      | pubdate | option | start_url | dest_url |
      | 2013-02-01 | February 2013 | 2012 | 2013/02 |
      | 2012-11-01 | November 2012 | 2013 | 2012/11 |

  @api
  Scenario Outline: Correct number of articles for month
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "Article 2013-02-01",
          "version": "1",
          "doi": "10.7554/eLife.00001",
          "volume": "1",
          "article-id": "00001",
          "article-version-id": "00001.1",
          "pub-date": "2013-02-01",
          "path": "content/1/00001",
          "article-type": "research-article",
          "status": "VOR",
          "categories": {
            "display-channel": [
              "Research article"
            ]
          }
        }
      """
    And the response code should be 200
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "Article 2013-02-02",
          "version": "1",
          "doi": "10.7554/eLife.00002",
          "volume": "1",
          "article-id": "00002",
          "article-version-id": "00002.1",
          "pub-date": "2013-02-02",
          "path": "content/1/00002",
          "article-type": "research-article",
          "status": "VOR",
          "categories": {
            "display-channel": [
              "Research article"
            ]
          }
        }
      """
    And the response code should be 200
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "Article 2013-02-03",
          "version": "1",
          "doi": "10.7554/eLife.00003",
          "volume": "1",
          "article-id": "00003",
          "article-version-id": "00003.1",
          "pub-date": "2013-02-03",
          "path": "content/1/00003",
          "article-type": "research-article",
          "status": "VOR",
          "categories": {
            "display-channel": [
              "Research article"
            ]
          }
        }
      """
    And the response code should be 200
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "Article 2013-02-04",
          "version": "1",
          "doi": "10.7554/eLife.00004",
          "volume": "1",
          "article-id": "00004",
          "article-version-id": "00004.1",
          "pub-date": "2013-02-04",
          "path": "content/1/00004",
          "article-type": "research-article",
          "status": "VOR",
          "categories": {
            "display-channel": [
              "Research article"
            ]
          }
        }
      """
    And the response code should be 200
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "Article 2013-02-05",
          "version": "1",
          "doi": "10.7554/eLife.00005",
          "volume": "1",
          "article-id": "00005",
          "article-version-id": "00005.1",
          "pub-date": "2013-02-05",
          "path": "content/1/00005",
          "article-type": "research-article",
          "status": "VOR",
          "categories": {
            "display-channel": [
              "Research article"
            ]
          }
        }
      """
    And the response code should be 200
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "Article 2013-01-01",
          "version": "1",
          "doi": "10.7554/eLife.00011",
          "volume": "1",
          "article-id": "00011",
          "article-version-id": "00011.1",
          "pub-date": "2013-01-01",
          "path": "content/1/00011",
          "article-type": "research-article",
          "status": "VOR",
          "categories": {
            "display-channel": [
              "Research article"
            ]
          }
        }
      """
    And the response code should be 200
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "Article 2013-01-02",
          "version": "1",
          "doi": "10.7554/eLife.00012",
          "volume": "1",
          "article-id": "00012",
          "article-version-id": "00012.1",
          "pub-date": "2013-01-02",
          "path": "content/1/00012",
          "article-type": "research-article",
          "status": "VOR",
          "categories": {
            "display-channel": [
              "Research article"
            ]
          }
        }
      """
    And the response code should be 200
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "Article 2013-01-03",
          "version": "1",
          "doi": "10.7554/eLife.00013",
          "volume": "1",
          "article-id": "00013",
          "article-version-id": "00013.1",
          "pub-date": "2013-01-03",
          "path": "content/1/00013",
          "article-type": "research-article",
          "status": "VOR",
          "categories": {
            "display-channel": [
              "Research article"
            ]
          }
        }
      """
    And the response code should be 200
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "Article 2013-01-04",
          "version": "1",
          "doi": "10.7554/eLife.00014",
          "volume": "1",
          "article-id": "00014",
          "article-version-id": "00014.1",
          "pub-date": "2013-01-04",
          "path": "content/1/00014",
          "article-type": "research-article",
          "status": "VOR",
          "categories": {
            "display-channel": [
              "Research article"
            ]
          }
        }
      """
    And the response code should be 200
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "Article 2013-01-05",
          "version": "1",
          "doi": "10.7554/eLife.00015",
          "volume": "1",
          "article-id": "00015",
          "article-version-id": "00015.1",
          "pub-date": "2013-01-05",
          "path": "content/1/00015",
          "article-type": "research-article",
          "status": "VOR",
          "categories": {
            "display-channel": [
              "Research article"
            ]
          }
        }
      """
    And the response code should be 200
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "Article 2013-01-06",
          "version": "1",
          "doi": "10.7554/eLife.00016",
          "volume": "1",
          "article-id": "00016",
          "article-version-id": "00016.1",
          "pub-date": "2013-01-06",
          "path": "content/1/00016",
          "article-type": "research-article",
          "status": "VOR",
          "categories": {
            "display-channel": [
              "Research article"
            ]
          }
        }
      """
    And the response code should be 200
    When I am on "/archive/<url>"
    Then I should see <num> "article" elements

    Examples:
      | url | num |
      | 2013/02 | 5 |
      | 2013/01 | 6 |

  @api
  Scenario Outline: Redirect if month does not have leading zero in url
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "Article <pubdate>",
          "version": "1",
          "doi": "10.7554/eLife.00001",
          "volume": "1",
          "article-id": "00001",
          "article-version-id": "00001.1",
          "pub-date": "<pubdate>",
          "path": "content/1/00001",
          "article-type": "research-article",
          "status": "VOR",
          "categories": {
            "display-channel": [
              "Research article"
            ]
          }
        }
      """
    And the response code should be 200
    When I am on "/archive/<url>"
    Then the url should match "/archive/<new_url>"

    Examples:
      | pubdate | url | new_url |
      | 2013-09-01 | 2013/9 | 2013/09 |
      | 2013-01-01 | 2013/1 | 2013/01 |
      | 2012-10-01 | 2012/10 | 2012/10 |
