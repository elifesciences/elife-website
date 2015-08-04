Feature: Deceased
  In order to be notified of the deceased
  As a reader
  I should see the label Deceased in the deceased author's tooltip

  @hover
  Scenario: Author is deceased
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
    """
        {
   "title":"VOR 01861",
   "version":"1",
   "doi":"10.7554/eLife.01861",
   "volume":"3",
   "elocation-id":"e01861",
   "article-id":"10.7554/eLife.01861",
   "article-version-id":"01861",
   "pub-date":"2014-04-15",
   "path":"content/3/e01861",
   "article-type":"research-article",
   "status":"VOR",
   "publish":"1",
   "contributors":[
      {
         "type":"author",
         "equal-contrib":"yes",
         "id":"author-23",
         "deceased":"yes",
         "surname":"Widom",
         "given-names":"Jonathan",
         "references":{
            "affiliation":[
               "aff1"
            ],
            "foot-note":[
               "fn1"
            ]
         }
      }
   ],
   "referenced":{
      "affiliation":{
         "aff1":{
            "dept":"department1",
            "institution":"inst1",
            "city":"city1",
            "country":"Country1"
         }
      },
      "foot-note":{
         "fn1":{
            "type":"deceased",
            "value":"Deceased"
         }
      }
   }
}
"""
    And the response code should be 200
    And I go to "content/3/e01861"
    Then I should see "Jonathan Widom" in the ".elife-article-author-item" element
    And I should see "Deceased" in the ".author-tooltip" element

  Scenario: Author is not deceased
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
    """
        {
   "title":"VOR 01861",
   "version":"1",
   "doi":"10.7554/eLife.01861",
   "volume":"3",
   "elocation-id":"e01861",
   "article-id":"10.7554/eLife.01861",
   "article-version-id":"01861",
   "pub-date":"2014-04-15",
   "path":"content/3/e01861",
   "article-type":"research-article",
   "status":"VOR",
   "publish":"1",
   "contributors":[
      {
         "type":"author",
         "equal-contrib":"yes",
         "id":"author-23",
         "surname":"Widom",
         "given-names":"Jonathan",
         "references":{
            "affiliation":[
               "aff1"
            ]
         }
      }
   ],
   "referenced":{
      "affiliation":{
         "aff1":{
            "dept":"department1",
            "institution":"inst1",
            "city":"city1",
            "country":"Country1"
         }
      },
      "foot-note":{
         "fn1":{
            "type":"deceased",
            "value":"Deceased"
         }
      }
   }
}
"""
    And the response code should be 200
    And I go to "content/3/e01861"
    Then I should see "Jonathan Widom" in the ".elife-article-author-item" element
    And I should not see "Deceased" in the ".author-tooltip" element




