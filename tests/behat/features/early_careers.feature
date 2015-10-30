Feature: Navigate to editorial board
  In order to make it easier to navigate to our editorial board
  As a reader of the site
  I need easy navigation to the editorial board

  @javascript @api
  Scenario: Biographies are shown
    Given "elife_person_profile" content:
      | field_elife_pp_first_name | field_elife_pp_last_name | field_elife_pp_type          | field_elife_pp_profile     |
      | Foo                       | Bar                      | Early Careers Advisory Group | Lorem ipsum dolor sit amet |
    When I go to "/careers"
    And I click the ".person-profile__link:contains(Foo Bar)" element
    Then I should see "Lorem ipsum dolor sit amet" in the ".person-profile__biog" element

  @api
  Scenario: Other types of profiles are excluded
    Given "elife_person_profile" content:
      | field_elife_pp_first_name | field_elife_pp_last_name | field_elife_pp_type |
      | First Name 1              | Last Name 1              | Editor-in-Chief     |
      | First Name 2              | Last Name 2              | Deputy Editor       |
      | First Name 3              | Last Name 3              | Senior Editor       |
      | First Name 4              | Last Name 4              | Reviewing Editor    |
      | First Name 6              | Last Name 6              | Board of Directors  |
      | First Name 7              | Last Name 7              | Executive Staff     |
    When I go to "/careers"
    Then I should not see a ".ec-profiles__people" element
