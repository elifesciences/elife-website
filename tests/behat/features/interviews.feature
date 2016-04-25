@api
Feature: Interviews
  As a something
  I want to something
  So I can something

  Background:
    Given "elife_i_series" terms:
      | field_elife_is_title | field_elife_is_sub_title |
      | Series 1             | Sub-title                |

  Scenario: Empty interview series list
    When I visit "/interviews/series-1"
    Then I should see "Series 1" in the ".hero-block__title" element
    And I should see "Sub-title" in the ".hero-block__sub_title" element
    And I should see "No interviews are currently available." in the ".elife-collection__content" element

  Scenario: Sub-paths aren't accessible
    When I go to "/interviews/series-1/foo"
    Then the response status code should be 404

  Scenario: Interviews ordered by date
    Given "elife_i_series" terms:
      | field_elife_is_title |
      | Series 2             |
    And "elife_early_careers_interview" content:
      | field_elife_i_first_name | field_elife_i_last_name | field_elife_i_title | field_elife_i_series | created    |
      | Foo                      | Bar                     | Baz <i>Qux</i>      | Series 1: Sub-title  | 1451923009 |
      | One                      | Two                     | Three               | Series 1: Sub-title  | 1451922991 |
      | Four                     | Five                    | Six                 | Series 2             | 1451922991 |
    When I visit "/interviews/series-1"
    And I should see 2 ".view-elife-early-careers-interviews li" elements
    And I should see "Baz Qux: an interview with Foo Bar" in the ".view-elife-early-careers-interviews li:nth-child(1)" element
    And I should see "Qux" in the ".view-elife-early-careers-interviews li:nth-child(1) i" element
    And I should see "Three: an interview with One Two" in the ".view-elife-early-careers-interviews li:nth-child(2)" element

  Scenario: Individual interviews
    Given "elife_early_careers_interview" content:
      | field_elife_i_first_name | field_elife_i_last_name | field_elife_i_title | field_elife_i_series | field_elife_i_text |
      | Foo                      | Bar                     | Baz <i>Qux</i>      | Series 1: Sub-title  | Lorem ipsum.       |
    When I visit "/interviews/series-1/foo-bar"
    Then I should see "This interview is part of Series 1: Sub-title."
    And I should see "Baz Qux: an interview with Foo Bar" in the ".content .main-wrapper h2" element
    And I should see "Qux" in the ".content .main-wrapper h2 i" element
    And I should see "Lorem ipsum." in the ".content .main-wrapper" element

  Scenario: Interview metadata
    When I am viewing an "elife_early_careers_interview":
      | field_elife_i_first_name | Foo                 |
      | field_elife_i_last_name  | Bar                 |
      | field_elife_i_title      | Baz <i>Qux</i>      |
      | field_elife_i_series     | Series 1: Sub-title |
      | field_elife_i_text       | Lorem ipsum.        |
    Then the metatag attribute "description" should have the value "Lorem ipsum."
