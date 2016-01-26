@api
Feature: Content alerts signup
  As a website user
  I want to sign up for content alerts
  So I can be alerted of the latest content

  Scenario Outline: Verify that the content alert signup form is available on category pages
    Given "elife_categories" terms:
      | field_elife_title | field_elife_category_sign_up_id |
      | <category>        | <id>                            |
    When I go to "category/<category-path>"
    Then I should see a sign up form with id "<expected_id>", gid "<expected_gid>" and button "<button_text>"

    Examples:
      | category-path | category | button_text | expected_gid | id  | expected_id       |
      | foo           | Foo      | SIGN UP     | 18           | baz | baz               |
      | bar           | Bar      | SIGN UP     | 18           |     | article_rev140402 |

  Scenario: Verify that the content alert signup form is available on the home page
    When I go to the homepage
    Then I should see a sign up form with id "homepage_rev140402" and gid "18"

  Scenario: Verify that the content alert signup form is available on the upcoming articles page
    When I go to "/upcoming"
    Then I should see a sign up form with id "poa_rev141013" and gid "24"

  Scenario: Verify that the content alert signup form is available on the news list
    When I go to "/elife-news"
    Then I should see a sign up form with id "elife-news_rev140402" and gid "18"

  Scenario: Verify that the content alert signup form is available on news articles
    When I am viewing an "elife_news_article":
      | field_elife_title | Foo |
    Then I should see a sign up form with id "elife-news_rev140402" and gid "18"
