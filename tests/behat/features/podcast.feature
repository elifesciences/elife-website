Feature: Podcast
  As a website user
  I want to easily find the latest podcast
  So I can review the latest research when I am away from my computer

  @api
  Scenario: Find podcast link on a Research article page
    Given "elife_podcast" content:
      | title      | field_elife_p_articles |
      | Podcast 13 | 05224                  |
    When I am viewing an elife_article_ver content:
      | field_elife_a_subarticle   | 0                |
      | field_elife_a_article_type | research-article |
      | field_elife_a_article_id   | 05224            |
    Then I should see text matching "Podcast 13"

  @api
  Scenario: Only display podcast link on appropriate page
    Given "elife_podcast" content:
      | title      | field_elife_p_articles |
      | Podcast 13 | 05224, 05226           |
    Then I am viewing an elife_article_ver content:
      | field_elife_a_subarticle   | 0                |
      | field_elife_a_article_type | research-article |
      | field_elife_a_article_id   | 05224            |
    And I should see text matching "Podcast 13"
    And I am viewing an elife_article_ver content:
      | field_elife_a_subarticle   | 0                |
      | field_elife_a_article_type | research-article |
      | field_elife_a_article_id   | 05225            |
    And I should not see text matching "Podcast 13"
    And I am viewing an elife_article_ver content:
      | field_elife_a_subarticle   | 0                |
      | field_elife_a_article_type | research-article |
      | field_elife_a_article_id   | 05226            |
    And I should see text matching "Podcast 13"
