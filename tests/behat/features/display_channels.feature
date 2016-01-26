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
  Scenario Outline: Add a display channel plural
    Given I am viewing an "elife_categories" term with the name "<singular>"
    And I should see "<singular>" in the "h1" element
    And I set variable "elife_article_category_plural" to array '{"<singular>": "<plural>"}'
    When I am viewing an "elife_categories" term with the name "<singular>"
    Then I should see "<plural>" in the "h1" element

    Examples:
      | singular | plural    |
      | Donut    | Donuts    |
      | Sheep    | Sheep     |
      | Triangle | Triangles |
