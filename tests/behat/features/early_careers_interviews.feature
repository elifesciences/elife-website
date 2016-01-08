@api
Feature: Early Careers Interviews
  As a something
  I want to something
  So I can something

  Scenario: Empty interviews list
    When I visit "/early-careers-interviews"
    Then I should see "Early-career researchers" in the ".hero-block__title" element
    And I should see "No interviews are currently available." in the ".elife-collection__content" element

  Scenario: Sub-paths aren't accessible
    When I go to "/early-careers-interviews/foo"
    Then the response status code should be 404

  Scenario: Interviews ordered by date
    Given "elife_early_careers_interview" content:
      | field_elife_i_first_name | field_elife_i_last_name | field_elife_i_title | created    |
      | Foo                      | Bar                     | Baz <i>Qux</i>      | 1451923009 |
      | One                      | Two                     | Three               | 1451922991 |
    When I visit "/early-careers-interviews"
    And I should see "Baz Qux: an interview with Foo Bar" in the ".view-elife-early-careers-interviews li:nth-child(1)" element
    And I should see "Qux" in the ".view-elife-early-careers-interviews li:nth-child(1) i" element
    And I should see "Three: an interview with One Two" in the ".view-elife-early-careers-interviews li:nth-child(2)" element

  Scenario: Individual interviews
    Given "elife_early_careers_interview" content:
      | field_elife_i_first_name | field_elife_i_last_name | field_elife_i_title | field_elife_i_text |
      | Foo                      | Bar                     | Baz <i>Qux</i>      | Lorem ipsum.       |
    When I visit "/early-careers-interviews/foo-bar"
    And I should see "Baz Qux: an interview with Foo Bar" in the ".content .main-wrapper h2" element
    And I should see "Qux" in the ".content .main-wrapper h2 i" element
    And I should see "Lorem ipsum." in the ".content .main-wrapper" element

  Scenario: Interview metadata
    When I am viewing an "elife_early_careers_interview":
      | field_elife_i_first_name | Foo            |
      | field_elife_i_last_name  | Bar            |
      | field_elife_i_title      | Baz <i>Qux</i> |
      | field_elife_i_text       | Lorem ipsum.   |
    Then the metatag attribute "description" should have the value "Lorem ipsum."
