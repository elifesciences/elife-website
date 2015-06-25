Feature: Display channel types
  As a website editor
  I want to maintain the display channel types
  So I can present content of interest to the user

  Background:
    Given I set variable "pathauto_taxonomy_term_elife_categories_pattern" to string "new-category/[term:name]"

  @api
  Scenario: Determine order of display channels
    Given I set variable "elife_category_assets_weight" to array '["Correction", "Research article"]'
    And "elife_categories" terms:
      | name | field_elife_category_type |
      | Insight | display-channel |
      | Research article | display-channel |
      | Correction | display-channel |
    Then display channels should be arranged "Correction, Research article, Insight"
    And I set variable "elife_category_assets_weight" to array '["Research article", "Insight", "Correction", "Research advance"]'
    And "elife_categories" terms:
      | name | field_elife_category_type |
      | Editorial | display-channel |
    And display channels should be arranged "Research article, Insight, Correction, Editorial"

  @api
  Scenario: Add a display channel description
    Given "elife_category_assets" content:
      | title | field_elife_ca_category | body |
      | Research article | Research article | Description of research article |
    When "elife_categories" terms:
      | name | field_elife_category_type |
      | Research article | display-channel |
    And I am on "new-category/research-article"
    Then I should see "Description of research article"
