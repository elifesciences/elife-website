Feature: Archive
  In order to review previous articles posted in the journal
  As a website user
  I need an archive section

  Scenario: Display general archive listing
    Given I am on "/archive"
    Then the response status code should be 200
    And I should see "Article archive" in the "h1" element

  Scenario: No yearly overview
    Given there is an article:
      """
        {
          "title": "Article 01/10/2012",
          "version": "1",
          "doi": "10.7554/eLife.00001",
          "volume": "1",
          "elocation-id": "e00001",
          "article-id": "00001",
          "article-version-id": "00001.1",
          "pub-date": "2012-10-01",
          "path": "content/1/00001",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1",
          "categories": {
            "display-channel": [
              "Research article"
            ]
          }
        }
      """
    When I am on "/archive/2012"
    Then the response status code should be 404
    When I am on "/archive/2013"
    Then the response status code should be 404

  Scenario Outline: Appropriate heading set for archive listing
    Given there is an article:
      """
        {
          "title": "Article <pubdate>",
          "version": "1",
          "doi": "10.7554/eLife.00001",
          "volume": "1",
          "elocation-id": "e00001",
          "article-id": "00001",
          "article-version-id": "00001.1",
          "pub-date": "<pubdate>",
          "path": "content/1/00001",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1",
          "categories": {
            "display-channel": [
              "Research article"
            ]
          }
        }
      """
    When I am on "/archive/<url>"
    Then I should see "Article archive, <date>" in the "h1" element

    Examples:
      | pubdate | url | date |
      | 2012-10-01 | 2012/10 | October 2012 |
      | 2013-05-01 | 2013/05 | May 2013 |

  Scenario Outline: Use the archive jump to dropdown
    Given there is an article:
      """
        {
          "title": "Article <pubdate>",
          "version": "1",
          "doi": "10.7554/eLife.00001",
          "volume": "1",
          "elocation-id": "e00001",
          "article-id": "00001",
          "article-version-id": "00001.1",
          "pub-date": "<pubdate>",
          "path": "content/1/00001",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1",
          "categories": {
            "display-channel": [
              "Research article"
            ]
          }
        }
      """
    And I am on "/archive"
    When I select "<option>" from "jump"
    And I press "Go"
    Then the url should match "/archive/<dest_url>"

    Examples:
      | pubdate | option | dest_url |
      | 2013-02-01 | February 2013 | 2013/02 |
      | 2012-11-01 | November 2012 | 2012/11 |

  @javascript
  Scenario Outline: Use the archive jump to dropdown (javascript)
    Given there is an article:
      """
        {
          "title": "Article <pubdate>",
          "version": "1",
          "doi": "10.7554/eLife.00001",
          "volume": "1",
          "elocation-id": "e00001",
          "article-id": "00001",
          "article-version-id": "00001.1",
          "pub-date": "<pubdate>",
          "path": "content/1/00001",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1",
          "categories": {
            "display-channel": [
              "Research article"
            ]
          }
        }
      """
    And I am on "/archive"
    When I select "<option>" from "jump"
    Then the url should match "/archive/<dest_url>"

    Examples:
      | pubdate | option | dest_url |
      | 2013-02-01 | February 2013 | 2013/02 |
      | 2012-11-01 | November 2012 | 2012/11 |

  Scenario Outline: Correct number of articles for month
    Given there are articles:
      """
        [
          {
            "title": "Article 2013-02-01",
            "version": "1",
            "doi": "10.7554/eLife.00001",
            "volume": "1",
            "elocation-id": "e00001",
            "article-id": "00001",
            "article-version-id": "00001.1",
            "pub-date": "2013-02-01",
            "path": "content/1/00001",
            "article-type": "research-article",
            "status": "VOR",
            "publish": "1",
            "categories": {
              "display-channel": [
                "Research article"
              ]
            }
          },
          {
            "title": "Article 2013-02-02",
            "version": "1",
            "doi": "10.7554/eLife.00002",
            "volume": "1",
            "elocation-id": "e00002",
            "article-id": "00002",
            "article-version-id": "00002.1",
            "pub-date": "2013-02-02",
            "path": "content/1/00002",
            "article-type": "research-article",
            "status": "VOR",
            "publish": "1",
            "categories": {
              "display-channel": [
                "Research article"
              ]
            }
          },
          {
            "title": "Article 2013-02-03",
            "version": "1",
            "doi": "10.7554/eLife.00003",
            "volume": "1",
            "elocation-id": "e00003",
            "article-id": "00003",
            "article-version-id": "00003.1",
            "pub-date": "2013-02-03",
            "path": "content/1/00003",
            "article-type": "research-article",
            "status": "VOR",
            "publish": "1",
            "categories": {
              "display-channel": [
                "Research article"
              ]
            }
          },
          {
            "title": "Article 2013-02-04",
            "version": "1",
            "doi": "10.7554/eLife.00004",
            "volume": "1",
            "elocation-id": "e00004",
            "article-id": "00004",
            "article-version-id": "00004.1",
            "pub-date": "2013-02-04",
            "path": "content/1/00004",
            "article-type": "research-article",
            "status": "VOR",
            "publish": "1",
            "categories": {
              "display-channel": [
                "Research article"
              ]
            }
          },
          {
            "title": "Article 2013-02-05",
            "version": "1",
            "doi": "10.7554/eLife.00005",
            "volume": "1",
            "elocation-id": "e00005",
            "article-id": "00005",
            "article-version-id": "00005.1",
            "pub-date": "2013-02-05",
            "path": "content/1/00005",
            "article-type": "research-article",
            "status": "VOR",
            "publish": "1",
            "categories": {
              "display-channel": [
                "Research article"
              ]
            }
          },
          {
            "title": "Article 2013-01-01",
            "version": "1",
            "doi": "10.7554/eLife.00011",
            "volume": "1",
            "elocation-id": "e00011",
            "article-id": "00011",
            "article-version-id": "00011.1",
            "pub-date": "2013-01-01",
            "path": "content/1/00011",
            "article-type": "research-article",
            "status": "VOR",
            "publish": "1",
            "categories": {
              "display-channel": [
                "Research article"
              ]
            }
          },
          {
            "title": "Article 2013-01-02",
            "version": "1",
            "doi": "10.7554/eLife.00012",
            "volume": "1",
            "elocation-id": "e00012",
            "article-id": "00012",
            "article-version-id": "00012.1",
            "pub-date": "2013-01-02",
            "path": "content/1/00012",
            "article-type": "research-article",
            "status": "VOR",
            "publish": "1",
            "categories": {
              "display-channel": [
                "Research article"
              ]
            }
          },
          {
            "title": "Article 2013-01-03",
            "version": "1",
            "doi": "10.7554/eLife.00013",
            "volume": "1",
            "elocation-id": "e00013",
            "article-id": "00013",
            "article-version-id": "00013.1",
            "pub-date": "2013-01-03",
            "path": "content/1/00013",
            "article-type": "research-article",
            "status": "VOR",
            "publish": "1",
            "categories": {
              "display-channel": [
                "Research article"
              ]
            }
          },
          {
            "title": "Article 2013-01-04",
            "version": "1",
            "doi": "10.7554/eLife.00014",
            "volume": "1",
            "elocation-id": "e00014",
            "article-id": "00014",
            "article-version-id": "00014.1",
            "pub-date": "2013-01-04",
            "path": "content/1/00014",
            "article-type": "research-article",
            "status": "VOR",
            "publish": "1",
            "categories": {
              "display-channel": [
                "Research article"
              ]
            }
          },
          {
            "title": "Article 2013-01-05",
            "version": "1",
            "doi": "10.7554/eLife.00015",
            "volume": "1",
            "elocation-id": "e00015",
            "article-id": "00015",
            "article-version-id": "00015.1",
            "pub-date": "2013-01-05",
            "path": "content/1/00015",
            "article-type": "research-article",
            "status": "VOR",
            "publish": "1",
            "categories": {
              "display-channel": [
                "Research article"
              ]
            }
          },
          {
            "title": "Article 2013-01-06",
            "version": "1",
            "doi": "10.7554/eLife.00016",
            "volume": "1",
            "elocation-id": "e00016",
            "article-id": "00016",
            "article-version-id": "00016.1",
            "pub-date": "2013-01-06",
            "path": "content/1/00016",
            "article-type": "research-article",
            "status": "VOR",
            "publish": "1",
            "categories": {
              "display-channel": [
                "Research article"
              ]
            }
          }
        ]
      """
    When I am on "/archive/<url>"
    Then I should see <num> ".article-teaser" elements

    Examples:
      | url | num |
      | 2013/02 | 5 |
      | 2013/01 | 6 |

  Scenario Outline: Redirect if month does not have leading zero in url
    Given there is an article:
      """
        {
          "title": "Article <pubdate>",
          "version": "1",
          "doi": "10.7554/eLife.00001",
          "volume": "1",
          "elocation-id": "e00001",
          "article-id": "00001",
          "article-version-id": "00001.1",
          "pub-date": "<pubdate>",
          "path": "content/1/00001",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1",
          "categories": {
            "display-channel": [
              "Research article"
            ]
          }
        }
      """
    When I am on "/archive/<url>"
    Then the url should match "/archive/<new_url>"

    Examples:
      | pubdate | url | new_url |
      | 2013-09-01 | 2013/9 | 2013/09 |
      | 2013-01-01 | 2013/1 | 2013/01 |
      | 2012-10-01 | 2012/10 | 2012/10 |

  Scenario: Correct set of article types in the archive listing
    Given I set variable "elife_category_reference_weight" to array '["Editorial", "Feature article", "Insight", "Research article", "Short report", "Tools and resources", "Research advance", "Registered report"]'
    And there are articles:
      """
        [
          {
            "title": "Article 2015-03-01",
            "version": "1",
            "doi": "10.7554/eLife.00001",
            "volume": "1",
            "elocation-id": "e00001",
            "article-id": "00001",
            "article-version-id": "00001.1",
            "pub-date": "2015-03-01",
            "path": "content/1/00001",
            "article-type": "research-article",
            "status": "VOR",
            "publish": "1",
            "categories": {
              "display-channel": [
                "Tools and resources"
              ]
            }
          },
          {
            "title": "Article 2015-03-02",
            "version": "1",
            "doi": "10.7554/eLife.00002",
            "volume": "1",
            "elocation-id": "e00002",
            "article-id": "00002",
            "article-version-id": "00002.1",
            "pub-date": "2015-03-02",
            "path": "content/1/00002",
            "article-type": "research-article",
            "status": "VOR",
            "publish": "1",
            "categories": {
              "display-channel": [
                "Registered report"
              ]
            }
          },
          {
            "title": "Article 2015-03-03",
            "version": "1",
            "doi": "10.7554/eLife.00003",
            "volume": "1",
            "elocation-id": "e00003",
            "article-id": "00003",
            "article-version-id": "00003.1",
            "pub-date": "2015-03-03",
            "path": "content/1/00003",
            "article-type": "research-article",
            "status": "VOR",
            "publish": "1",
            "categories": {
              "display-channel": [
                "Research advance"
              ]
            }
          },
          {
            "title": "Article 2015-03-04",
            "version": "1",
            "doi": "10.7554/eLife.00004",
            "volume": "1",
            "elocation-id": "e00004",
            "article-id": "00004",
            "article-version-id": "00004.1",
            "pub-date": "2015-03-04",
            "path": "content/1/00004",
            "article-type": "research-article",
            "status": "VOR",
            "publish": "1",
            "categories": {
              "display-channel": [
                "Insight"
              ]
            }
          },
          {
            "title": "Article 2015-03-05",
            "version": "1",
            "doi": "10.7554/eLife.00005",
            "volume": "1",
            "elocation-id": "e00005",
            "article-id": "00005",
            "article-version-id": "00005.1",
            "pub-date": "2015-03-05",
            "path": "content/1/00005",
            "article-type": "research-article",
            "status": "VOR",
            "publish": "1",
            "categories": {
              "display-channel": [
                "Research article"
              ]
            }
          },
          {
            "title": "Article 2015-03-06",
            "version": "1",
            "doi": "10.7554/eLife.00006",
            "volume": "1",
            "elocation-id": "e00006",
            "article-id": "00006",
            "article-version-id": "00006.1",
            "pub-date": "2015-03-06",
            "path": "content/1/00006",
            "article-type": "research-article",
            "status": "VOR",
            "publish": "1",
            "categories": {
              "display-channel": [
                "Feature article"
              ]
            }
          },
          {
            "title": "Article 2015-03-07",
            "version": "1",
            "doi": "10.7554/eLife.00007",
            "volume": "1",
            "elocation-id": "e00007",
            "article-id": "00007",
            "article-version-id": "00007.1",
            "pub-date": "2015-03-07",
            "path": "content/1/00007",
            "article-type": "research-article",
            "status": "VOR",
            "publish": "1",
            "categories": {
              "display-channel": [
                "Short report"
              ]
            }
          },
          {
            "title": "Article 2015-03-08",
            "version": "1",
            "doi": "10.7554/eLife.00008",
            "volume": "1",
            "elocation-id": "e00008",
            "article-id": "00008",
            "article-version-id": "00008.1",
            "pub-date": "2015-03-08",
            "path": "content/1/00008",
            "article-type": "research-article",
            "status": "VOR",
            "publish": "1",
            "categories": {
              "display-channel": [
                "Editorial"
              ]
            }
          }
        ]
      """
    When I am on "/archive/2015/03"
    Then I should see "Editorial" in the ".view-elife-archive-by-month h3:nth-of-type(1)" element
    Then I should see "Feature article" in the ".view-elife-archive-by-month h3:nth-of-type(2)" element
    Then I should see "Insight" in the ".view-elife-archive-by-month h3:nth-of-type(3)" element
    Then I should see "Research article" in the ".view-elife-archive-by-month h3:nth-of-type(4)" element
    Then I should see "Short report" in the ".view-elife-archive-by-month h3:nth-of-type(5)" element
    Then I should see "Tools and resources" in the ".view-elife-archive-by-month h3:nth-of-type(6)" element
    Then I should see "Research advance" in the ".view-elife-archive-by-month h3:nth-of-type(7)" element
    Then I should see "Registered report" in the ".view-elife-archive-by-month h3:nth-of-type(8)" element
    And the response status code should be 200
