Feature: Contribution
  In order to be able to get credit for my work
  As an author
  I should see my name as contributor to the paper listed

  @hover
  Scenario Outline: Contribution listed in author tooltip
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
    """
        {
   "title":"VOR 03895",
   "version":"1",
   "doi":"10.7554/eLife.03895",
   "volume":"3",
   "elocation-id":"e03895",
   "article-id":"10.7554/eLife.03895",
   "article-version-id":"05227",
   "pub-date":"2014-11-13",
   "path":"content/3/e03895",
   "article-type":"research-article",
   "status":"VOR",
   "publish":"1",
   "contributors":[
      {
         "type":"author",
         "equal-contrib":"yes",
         "id":"author-23",
         "surname":"Kamoun",
         "given-names":"Sophien",
         "suffix":"Jnr",
         "references":{
            "affiliation":[
               "aff1"
            ],
            "equal-contrib":[
               "equal-contrib"
            ],
            "contribution":[
               "con1"
            ]
         }
      },
      {
         "type":"author",
         "equal-contrib":"yes",
         "id":"author-17",
         "surname":"Krause",
         "given-names":"Johannes",
         "references":{
            "affiliation":[
               "aff2"
            ],
            "equal-contrib":[
               "equal-contrib"
            ],
            "contribution":[
               "con2"
            ]
         }
      },
      {
         "type":"author",
         "id":"author-3",
         "surname":"Thines",
         "given-names":"Marco",
         "references":{
            "affiliation":[
               "aff3"
            ],
            "equal-contrib":[
               "equal-contrib"
            ],
            "contribution":[
               "con3"
            ]
         }
      },
      {
         "type":"author",
         "id":"author-4",
         "surname":"Weigel",
         "given-names":"Detlef",
         "references":{
            "affiliation":[
               "aff2"
            ],
            "equal-contrib":[
               "equal-contrib"
            ],
            "contribution":[
               "con3"
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
         },
         "aff2":{
            "dept":"department2",
            "institution":"inst2",
            "city":"city2",
            "country":"Country2"
         },
         "aff3":{
            "dept":"department3",
            "institution":"inst3",
            "city":"city3",
            "country":"Country3"
         }
      },
      "contribution":{
         "con1":"RAA, Conception and design, Acquisition of data, Analysis and interpretation of data, Drafting or revising the article",
         "con2":"RAA, Conception and design, Analysis and interpretation of data, Drafting or revising the article",
         "con3":"RAA, Conception and design, Drafting or revising the article"
      }
   }
}
      """
    And the response code should be 200
    And I go to "content/3/e03895"
    Then I should see "<author>" in the ".author-list-full li:nth-of-type(<n>) .author-tooltip .author-tooltip-name" element
    Then I should see "Contributed equally with:" in the ".author-list-full li:nth-of-type(<n>) .author-tooltip-equal-contrib .author-tooltip-label" element
  Examples:
    | author               | n |
    | Sophien Kamoun Jnr   | 1 |
    | Johannes Krause      | 2 |
    | Marco Thines         | 3 |
    | Detlef Weigel        | 4 |
