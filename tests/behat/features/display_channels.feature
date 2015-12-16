Feature: Display channel types
  As a website editor
  I want to maintain the display channel types
  So I can present content of interest to the user

  @api
  Scenario: Determine order of display channels
    Given I set variable "elife_category_reference_weight" to array '["Correction", "Research article"]'
    And "elife_categories" terms:
      | field_elife_title | field_elife_category_type |
      | Insight | display-channel |
      | Research article | display-channel |
      | Correction | display-channel |
    Then display channels should be arranged "Correction, Research article, Insight"
    And I set variable "elife_category_reference_weight" to array '["Research article", "Insight", "Correction", "Research advance"]'
    And "elife_categories" terms:
      | field_elife_title | field_elife_category_type |
      | Editorial | display-channel |
    And display channels should be arranged "Research article, Insight, Correction, Editorial"

  @api
  Scenario: Add a display channel description
    Given "elife_term_reference" content:
      | title | field_elife_ta_term | field_elife_ta_body |
      | Research article | Research article | Description of research article |
    When I am viewing an "elife_categories" term with the name "Research article"
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
