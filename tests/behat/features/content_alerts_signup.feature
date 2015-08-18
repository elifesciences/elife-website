Feature: Content alerts signup
  As a website user
  I want to sign up for content alerts
  So I can be alerted of the latest content

  @api @mink:goutte
  Scenario Outline: Verify that the content alert signup form is available on category pages
    Given I set variable "elife_content_alerts_sign_up_ids" to array '{"category/<category-path>": "<id>"}'
    And I set variable "elife_content_alerts_sign_up_gids" to array '{"category/<category-path>": "<gid>"}'
    And "elife_categories" terms:
      | name | field_elife_category_type |
      | <category> | <type> |
    And redirects are not followed
    When I am on "category/<category-path>"
    And I should see a sign up form with id "<id>" and gid "<gid>"
    And I press the "<button_text>" button
    Then I should be on "http://crm.elifesciences.org/crm/civicrm/profile/create?reset=1&gid=<gid>"

    Examples:
      | category-path | category | type | button_text | gid | id |
      | research-article | Research article | display-channel | SIGN UP | 18 | research_rev141014 |
      | immunology | Immunology | heading | SIGN UP | 18 | immunol_rev141014 |
      | tools-and-resources | Tools and resources | display-channel | SIGN UP | 18 | research_rev141014 |
