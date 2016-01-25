@api
Feature: News
  As a something
  I want to something
  So I can something

  Scenario: Empty news list
    When I visit "/elife-news"
    Then I should see "eLife News" in the ".content .main-wrapper h1" element
    And I should see "No news articles are currently available." in the ".content .main-wrapper" element
    And I should not see "Categories" in the ".content .sidebar-wrapper" element

  Scenario: News list metadata
    When I go to "/elife-news"
    Then the metatag attribute "description" should have the value "eLife - Open access to the most promising advances in science"

  Scenario: Sub-paths aren't accessible
    When I go to "/elife-news/foo"
    Then the response status code should be 404

  Scenario: News article without any categories
    Given "elife_news_article" content:
      | field_elife_title | field_elife_n_text |
      | Foo <i>Bar</i>    | One                |
    When I visit "/elife-news"
    Then I should see "eLife News" in the ".content .main-wrapper h1" element
    And I should see "Foo Bar" in the ".content .main-wrapper" element
    And I should see "Bar" in the ".content .main-wrapper i" element
    And I should not see "Categories" in the ".content .sidebar-wrapper" element

  Scenario: News article with categories
    Given "elife_n_category" terms:
      | field_elife_title |
      | foo               |
    And "elife_news_article" content:
      | field_elife_title | field_elife_n_text | field_elife_n_category |
      | Bar               | One                | foo                    |
    When I visit "/elife-news"
    Then I should see "eLife News" in the ".content .main-wrapper h1" element
    And I should see "Bar" in the ".content .main-wrapper" element
    And I should see "Categories" in the ".content .sidebar-wrapper" element
    And I should see "foo" in the ".content .sidebar-wrapper" element

  Scenario: News article metadata
    When I am viewing an "elife_news_article":
      | field_elife_title  | Foo            |
      | field_elife_n_text | One Two Three. |
    Then the metatag attribute "description" should have the value "One Two Three."

  Scenario: Follow category sidebar link
    Given "elife_n_category" terms:
      | field_elife_title |
      | foo               |
    And "elife_news_article" content:
      | field_elife_title | field_elife_n_text | field_elife_n_category |
      | Bar               | One                | foo                    |
    When I visit "/elife-news"
    And I follow "foo"
    Then I should be on "/elife-news/foo"

  Scenario: Category list
    Given "elife_n_category" terms:
      | field_elife_title |
      | foo <i>bar</i>    |
      | baz               |
    And "elife_news_article" content:
      | field_elife_title | field_elife_n_text | field_elife_n_category |
      | Qux               | One                | foo bar                |
      | Quux              | Two                | baz                    |
    When I visit "/elife-news/foo-bar"
    Then I should see "eLife News: foo bar" in the ".content .main-wrapper h1" element
    And I should see "bar" in the ".content .main-wrapper h1 i" element
    And I should see "Qux" in the ".content .main-wrapper" element
    And I should not see "Quux" in the ".content .main-wrapper" element
    And I should see "Categories" in the ".content .sidebar-wrapper" element
    And I should see "foo bar" in the ".content .sidebar-wrapper" element
    And I should see "bar" in the ".content .sidebar-wrapper i" element
    And I should see "baz" in the ".content .sidebar-wrapper" element
