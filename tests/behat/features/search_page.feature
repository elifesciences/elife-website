Feature: Search
  In order to search articles posted in the journal
  As a website user
  I need a search link that redirects to search page

  Scenario: Display Search link on Home page
    Given I am on the homepage
    Then the response status code should be 200
    Then I should see "Search" in the ".header__list" element
    Then I should see the url "/elife/search" in the "href" attribute of the ".header__list li a.header__list_link.header__list_link--search" element
    When I click the ".header__list li a.header__list_link.header__list_link--search" element
    Then the url should match "/elife/search"

  Scenario: Appropriate title and input box for the Search page
    Given I am on "/elife/search"
    Then the response status code should be 200
    And I should see "Browse articles" in the "h1.pane-title" element
    And I fill in "Keyword" with "Algoriphagus"
    And I click "Search"

  Scenario: Search page has a default list of all articles of the eLife journal
    Given I am on "/elife/search"
    Then the response status code should be 200
    And I should see an ".elife-searchlist-results" element
    And I should see an "div.site-footer" element
