Feature: Simple pages
  As a user
  I want to see pages
  So I can find out information

  Scenario Outline: Visit simple pages
    When I go to "<path>"
    Then I should see "<text>"

    Examples:
      | path                        | text                         |
      | terms-and-conditions-of-use | Welcome and Consent to Terms |
      | privacy-policy              | If you have questions about  |
      | contact                     | Questions? Comments?         |
      | alerts-and-feeds            | Stay up-to-date on new paper |
      | received-thanks             | Thanks for subscribing to    |
      | who-we-work-with            | We are pleased to work with  |

  Scenario: Sub-paths don't resolve
    When I go to "terms-and-conditions-of-use/foo"
    Then the response status code should be 404
