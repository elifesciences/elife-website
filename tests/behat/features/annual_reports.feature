@api
Feature: Annual reports
  As a something
  I want to something
  So I can something

  Scenario: Empty reports list
    When I visit "/annual-reports"
    Then I should see "Annual reports" in the "h1" element
    And I should see "No annual reports are currently available."

  Scenario: Sub-paths aren't accessible
    When I go to "/annual-reports/foo"
    Then the response status code should be 404

  Scenario: Ordered reports list
    Given "elife_annual_report" content:
      | field_elife_ar_year |
      | 2001                |
      | 2000                |
      | 2002                |
    When I visit "/annual-reports"
    Then I should see 3 ".node-teaser" elements
    And I should see "The eLife Sciences 2002 Annual Report" in the ".view-elife-annual-reports .view-content > div:nth-of-type(1)" element
    And I should see "The eLife Sciences 2001 Annual Report" in the ".view-elife-annual-reports .view-content > div:nth-of-type(2)" element
    And I should see "The eLife Sciences 2000 Annual Report" in the ".view-elife-annual-reports .view-content > div:nth-of-type(3)" element

  Scenario: Report links
    Given "elife_annual_report" content:
      | field_elife_ar_year | field_elife_ar_text | field_elife_ar_links                                               |
      | 2000                | Lorem ipsum.        | Foo - http://www.example.com/foo, Bar - http://www.example.com/bar |
    When I visit "/annual-reports"
    Then I should see the url "http://www.example.com/foo" in the "href" attribute of the ".node-teaser h2 a" element
    And I should see "Lorem ipsum" in the ".node-teaser" element
    And I should see "Foo" in the ".node-teaser ul li:nth-of-type(1) a" element
    And I should see the url "http://www.example.com/foo" in the "href" attribute of the ".node-teaser ul li:nth-of-type(1) a" element
    And I should see "Bar" in the ".node-teaser ul li:nth-of-type(2) a" element
    And I should see the url "http://www.example.com/bar" in the "href" attribute of the ".node-teaser ul li:nth-of-type(2) a" element
