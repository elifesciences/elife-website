@api
Feature: Article references
  As a something
  I want to something
  So I can something

  Scenario: Article references are unpublished when there's no article
    Given "elife_article_reference" content:
      | field_elife_a_title | field_elife_a_article_id |
      | foo                 | 05224                    |
    Then the "elife_article_reference" with the "field_elife_a_article_id" of "05224" should be like:
      | field_elife_a_title:value | status |
      | foo                       | 0      |

  Scenario: Article references become published and have their title updated
    Given "elife_article_reference" content:
      | field_elife_a_title | field_elife_a_article_id | status |
      | foo                 | 05224                    | 0      |
    When an article is submitted:
      """
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
          "publish": "1"
        }
      """
    Then the "elife_article_reference" with the "field_elife_a_article_id" of "05224" should be like:
      | field_elife_a_title:value | status |
      | VOR 05224 v2              | 1      |

  Scenario: New articles create an article reference
    Given there is an article:
      """
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
          "publish": "1"
        }
      """
    Then the "elife_article_reference" with the "field_elife_a_article_id" of "05224" should be like:
      | field_elife_a_title:value | status |
      | VOR 05224 v2              | 1      |

  @develop
  Scenario: Article references follow the article in becoming unpublished
    Given there is an article:
      """
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
          "publish": "1"
        }
      """
    When the article "05224.2" is unpublished
    Then the "elife_article_reference" with the "field_elife_a_article_id" of "05224" should be like:
      | field_elife_a_title:value | status |
      | VOR 05224 v2              | 0      |

  Scenario: Article references become unpublished when the article is deleted
    Given there is an article:
      """
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
          "publish": "1"
        }
      """
    When the article "05224.2" is deleted
    Then the "elife_article_reference" with the "field_elife_a_article_id" of "05224" should be like:
      | field_elife_a_title:value | status |
      | VOR 05224 v2              | 0      |
