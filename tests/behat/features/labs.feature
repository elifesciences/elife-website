@api
Feature: Labs
  As a something
  I want to something
  So I can something

  Scenario: Empty labs list
    When I visit "/labs"
    Then I should see "eLife Labs" in the ".content .pane-title" element
    And I should see "There are no labs experiments currently running." in the ".content" element

  Scenario: Labs list metadata
    When I go to "/labs"
    Then the metatag attribute "description" should have the value "eLife - Open access to the most promising advances in science"

  Scenario: Sub-paths aren't accessible
    When I go to "/labs/foo"
    Then the response status code should be 404

  Scenario: Ordered entries
    Given "elife_labs_entry" content:
      | field_elife_title | created    |
      | Foo               | 1451923009 |
      | Bar               | 1451922991 |
    When I visit "/labs"
    Then I should see "Bar" in the ".elife-labs-tile:nth-of-type(1)" element
    And I should see "Foo" in the ".elife-labs-tile:nth-of-type(2)" element

  Scenario: Linked entries
    Given "elife_labs_entry" content:
      | field_elife_title | field_elife_l_url                    |
      | Internal          | Fake Title - foo                     |
      | External          | Fake Title - http://www.example.com/ |
    When I visit "/labs"
    Then I should see the url "/foo" in the "href" attribute of the ".elife-labs-tile:contains('Internal') .elife-labs-tile__link" element
    And I should see the url "http://www.example.com/" in the "href" attribute of the ".elife-labs-tile:contains('External') .elife-labs-tile__link" element
