Feature: Display channel types
  As a website editor
  I want to maintain the display channel types
  So I can present content of interest to the user

  @api
  Scenario: Add a display channel description
    Given "elife_categories" terms:
      | field_elife_title | description                     |
      | Research article  | Description of research article |
    When I go to "/category/research-article"
    Then I should see "Description of research article"

  @api
  Scenario: Add a display channel plural
    Given "elife_categories" terms:
      | field_elife_title | field_elife_category_plural |
      | Donut             | Donuts                      |
      | Sheep             |                             |
    When I go to "/category/donut"
    And I should see "Donuts" in the "h1" element
    When I go to "/category/sheep"
    And I should see "Sheep" in the "h1" element
