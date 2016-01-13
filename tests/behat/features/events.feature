@api
Feature: Events
  As a something
  I want to something
  So I can something

  Scenario: Empty list
    When I visit "/events"
    Then I should see "Events" in the ".content .main-wrapper h1" element
    And I should see "No events are currently available." in the ".content .main-wrapper" element
    And I should not see a ".content .sidebar-wrapper" element

  Scenario: Sub-paths aren't accessible
    When I go to "/events/foo"
    Then the response status code should be 404

  Scenario: Event
    Given "elife_event" content:
      | field_elife_title | field_elife_e_text | field_elife_e_date  |
      | Foo <i>Bar</i>    | One                | 2000-01-01T00:00:00 |
    When I visit "/events"
    Then I should see "Events" in the ".content .main-wrapper h1" element
    And I should see "Foo Bar" in the ".content .main-wrapper" element
    And I should see "Bar" in the ".content .main-wrapper i" element

  Scenario: Category list
    Given "elife_event" content:
      | field_elife_title | field_elife_e_text | field_elife_e_date  |
      | Foo <i>Bar</i>    | One                | 2000-01-01T00:00:00 |
    When I visit "/events/foo-bar"
    Then I should see "Foo Bar" in the ".content .main-wrapper h2" element
    And I should see "Saturday, January 1, 2000 - 00:00" in the ".content .main-wrapper" element
    And I should see "One" in the ".content .main-wrapper" element
