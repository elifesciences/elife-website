@api
Feature: All paths are lowercase

  Scenario: Core pages use lowercase
    When I go to "/User"
    Then I should be on "/user"
    And I should see "Log in"

  Scenario: Pages use lowercase
    When I go to "/eLife-News"
    Then I should be on "/elife-news"
    And I should see "eLife News"

  Scenario: Terms use lowercase
    Given "elife_n_category" terms:
      | field_elife_title |
      | Foo               |
    When I go to "/elife-news/Foo"
    Then I should be on "/elife-news/foo"
    And I should see "Foo"

  Scenario: Nodes use lowercase
    Given "elife_news_article" content:
      | field_elife_title |
      | Foo               |
    When I go to "/elife-news/Foo"
    Then I should be on "/elife-news/foo"
    And I should see "Foo"
