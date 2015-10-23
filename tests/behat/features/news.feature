@api
Feature: News
  As a something
  I want to something
  So I can something

  Scenario: Empty news list
    When I visit "/elife-news"
    Then I should see "eLife News" in the ".content .main-wrapper h1" element
    And I should see "No news articles are currently available." in the ".content .main-wrapper" element
    And I should not see a ".content .sidebar-wrapper" element

  Scenario: News article without any categories
    Given "elife_news_article" content:
      | title | field_elife_n_text |
      | Foo   | One                |
    When I visit "/elife-news"
    Then I should see "eLife News" in the ".content .main-wrapper h1" element
    And I should see "Foo" in the ".content .main-wrapper" element
    And I should not see a ".content .sidebar-wrapper" element

  Scenario: News article with categories
    Given "elife_n_category" terms:
      | name |
      | foo  |
    And "elife_news_article" content:
      | title | field_elife_n_text | field_elife_n_category |
      | Bar   | One                | foo                    |
    When I visit "/elife-news"
    Then I should see "eLife News" in the ".content .main-wrapper h1" element
    And I should see "Bar" in the ".content .main-wrapper" element
    And I should see "Categories" in the ".content .sidebar-wrapper" element
    And I should see "foo" in the ".content .sidebar-wrapper" element

  Scenario: Follow category sidebar link
    Given "elife_n_category" terms:
      | name |
      | foo  |
    And "elife_news_article" content:
      | title | field_elife_n_text | field_elife_n_category |
      | Bar   | One                | foo                    |
    When I visit "/elife-news"
    And I follow "foo"
    Then I should be on "/elife-news/foo"

  Scenario: Category list
    Given "elife_n_category" terms:
      | name |
      | foo  |
      | bar  |
    And "elife_news_article" content:
      | title | field_elife_n_text | field_elife_n_category |
      | Baz   | One                | foo                    |
      | Qux   | Two                | bar                    |
    When I visit "/elife-news/foo"
    Then I should see "eLife News: foo" in the ".content .main-wrapper h1" element
    And I should see "Baz" in the ".content .main-wrapper" element
    And I should not see "Qux" in the ".content .main-wrapper" element
    And I should see "Categories" in the ".content .sidebar-wrapper" element
    And I should see "foo" in the ".content .sidebar-wrapper" element
    And I should see "bar" in the ".content .sidebar-wrapper" element
