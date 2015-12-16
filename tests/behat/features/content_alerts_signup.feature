@api
Feature: Content alerts signup
  As a website user
  I want to sign up for content alerts
  So I can be alerted of the latest content

  @mink:goutte
  Scenario Outline: Verify that the content alert signup form is available on category pages
    Given I set variable "elife_content_alerts_sign_up_ids" to array '{"category/<category-path>": "<id>"}'
    And I set variable "elife_content_alerts_sign_up_gids" to array '{"category/<category-path>": "<gid>"}'
    And "elife_categories" terms:
      | field_elife_title | field_elife_category_type |
      | <category> | <type> |
    When I go to "category/<category-path>"
    Then I should see a sign up form with id "<id>" and gid "<gid>"
    When I press the "<button_text>" button
    Then I should be on "http://crm.elifesciences.org/crm/civicrm/profile/create?reset=1&gid=<gid>"

    Examples:
      | category-path | category | type | button_text | gid | id |
      | research-article | Research article | display-channel | SIGN UP | 18 | research_rev141014 |
      | immunology | Immunology | heading | SIGN UP | 18 | immunol_rev141014 |
      | tools-and-resources | Tools and resources | display-channel | SIGN UP | 18 | research_rev141014 |

  @mink:goutte
  Scenario: Verify that the content alert signup form is available on the home page
    When I go to the homepage
    Then I should see a sign up form with id "homepage_rev140402" and gid "18"
    When I press the "Sign up" button
    Then I should be on "http://crm.elifesciences.org/crm/civicrm/profile/create?reset=1&gid=18"
