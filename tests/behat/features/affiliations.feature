Feature: Affiliations
  In Order to be able to see the Institutions the author is associated with
  As a reader
  I should be able to see the list of institutions under the list of authors on the article

  Scenario: List of institutions author is associated with is shown in the tooltip
    Given the markup service is available
    And there is an article:
    """
        {
          "title": "VOR 00288",
          "version": 1,
          "doi": "10.7554/eLife.00288",
          "volume": 2,
          "elocation-id": "e00288",
          "article-id": "10.7554/eLife.00288",
          "article-version-id": "00288.1",
          "pub-date": "2014-10-14T00:00:00+00:00",
          "path": "content/2/e00288v1",
          "article-type": "research-article",
          "status": "VOR",
          "publish": true,
          "contributors": [
            {
              "equal-contrib": true,
              "type": "author",
              "id": "author-23",
              "surname": "Alegado",
              "given-names": "Boris",
              "references": {
                "affiliation": [
                  "aff1"
                ]
              }
            },
            {
              "equal-contrib": true,
              "type": "author",
              "id": "author-24",
              "surname": "Alegado",
              "given-names": "Mary",
              "references": {
                "affiliation": [
                  "aff2"
                ]
              }
            }
          ],
          "referenced": {
            "affiliation": {
              "aff1": {
                "dept": "department",
                "institution": "Fred Hutchinson Cancer Research Center",
                "city": "city",
                "country": "United States"
              },
              "aff2": {
                "dept": "department",
                "institution": "Cancer Research Center",
                "city": "city",
                "country": "United States"
              }
            }
          }
        }
      """
    And I go to "content/2/e00288v1"
    Then I should see "Boris" in the ".given-names" element
    And I should see "Fred Hutchinson Cancer Research Center, United States; Cancer Research Center, United States" in the ".elife-institutions-list" element

  Scenario: Duplicate affiliations are avoided in the affiliation list under the list of authors
    Given there is an article:
    """
      {
        "title":"APP interacts with LRP4 and agrin to coordinate the development of the neuromuscular junction in mice",
        "status":"VOR",
        "article-type":"research-article",
        "pub-date":"2013-08-20T00:00:00+00:00",
        "version":1,
        "volume":2,
        "elocation-id":"e00288",
        "doi":"10.7554/eLife.00288",
        "article-id":"10.7554/eLife.00288",
        "article-version-id":"00288.1",
        "pub-date":"2014-10-14T00:00:00+00:00",
        "path":"content/2/e00288v1",
        "article-type":"research-article",
        "status":"VOR",
        "publish":true,
        "contributors":[
          {
            "surname":"Choi",
            "given-names":"Hong Y",
            "references":{
              "affiliation":[
                "aff1"
              ]
            },
            "equal-contrib":true,
            "type":"author",
            "id":"author-2174"
          },
          {
            "surname":"Liu",
            "given-names":"Yun",
            "references":{
              "affiliation":[
                "aff2"
              ]
            },
            "equal-contrib":true,
            "type":"author",
            "id":"author-2175"
          },
          {
            "type":"author",
            "given-names":"Christian",
            "surname":"Tennert",
            "id":"author-2176",
            "references":{
              "affiliation":[
                "aff1"
              ]
            }
          },
          {
            "type":"author",
            "given-names":"Yoshie",
            "surname":"Sugiura",
            "id":"author-2177",
            "references":{
              "affiliation":[
                "aff2"
              ]
            }
          },
          {
            "type":"author",
            "given-names":"Andromachi",
            "surname":"Karakatsani",
            "id":"author-5751",
            "references":{
              "affiliation":[
                "aff3"
              ],
              "contribution":[
                "con6"
              ],
              "competing-interest":[
                "conf1"
              ]
            }
          },
          {
            "type":"author",
            "given-names":"Stephan",
            "surname":"Kr\u00f6ger",
            "id":"author-5752",
            "references":{
              "affiliation":[
                "aff3"
              ]
            }
          },
          {
            "type":"author",
            "given-names":"Eric B",
            "surname":"Johnson",
            "id":"author-6539",
            "references":{
              "affiliation":[
                "aff1"
              ]
            }
          },
          {
            "type":"author",
            "given-names":"Robert E",
            "surname":"Hammer",
            "id":"author-2179",
            "references":{
              "affiliation":[
                "aff4"
              ]
            }
          },
          {
            "surname":"Lin",
            "corresp":true,
            "given-names":"Weichun",
            "references":{
              "affiliation":[
                "aff2"
              ]
            },
            "type":"author",
            "id":"author-2180"
          },
          {
            "surname":"Herz",
            "corresp":true,
            "given-names":"Joachim",
            "references":{
              "affiliation":[
                "aff1",
                "aff2",
                "aff5",
                "aff6"
              ]
            },
            "affiliations":[
              {
                "country":"France",
                "institution":"Institut Pasteur"
              }
            ],
            "type":"author",
            "id":"author-1351"
          },
          {
            "surname":"Buckingham",
            "given-names":"Margaret",
            "role":"Reviewing editor",
            "affiliations":[
              {
                "country":"France",
                "institution":"Institut Pasteur"
              }
            ],
            "type":"editor"
          }
        ],
        "referenced":{
          "affiliation":{
            "aff6":{
              "dept":"Center for Neuroscience",
              "city":"Freiburg",
              "institution":"Albert-Ludwigs-Universit\u00e4t Freiburg",
              "country":"Germany"
            },
            "aff5":{
              "dept":"Department of Neurology and Neurotherapeutics",
              "city":"Dallas",
              "institution":"University of Texas Southwestern Medical Center",
              "country":"United States"
            },
            "aff4":{
              "dept":"Department of Biochemistry",
              "city":"Dallas",
              "institution":"University of Texas Southwestern Medical Center",
              "country":"United States"
            },
            "aff3":{
              "dept":"Department of Physiological Genomics",
              "city":"M\u00fcnchen",
              "institution":"Ludwig-Maximilians-Universit\u00e4t M\u00fcnchen",
              "country":"Germany"
            },
            "aff2":{
              "dept":"Department of Neuroscience",
              "city":"Dallas",
              "institution":"University of Texas Southwestern Medical Center",
              "country":"United States"
            },
            "aff1":{
              "dept":"Department of Molecular Genetics",
              "city":"Dallas",
              "institution":"University of Texas Southwestern Medical Center",
              "country":"United States"
            }
          }
        }
      }
    """
    And I go to "content/2/e00288v1"
    Then I should see 4 ".elife-institution" elements
    Then I should see "University of Texas Southwestern Medical Center, United States; Ludwig-Maximilians-Universität München, Germany; Institut Pasteur, France; Albert-Ludwigs-Universität Freiburg, Germany" in the ".elife-institutions-list" element

  Scenario: Duplicate affiliations are avoided even when afiliations are both referenced and associated directly to author
    Given there is an article:
    """
      {
        "title":"APP interacts with LRP4 and agrin to coordinate the development of the neuromuscular junction in mice",
        "status":"VOR",
        "article-type":"research-article",
        "pub-date":"2013-08-20T00:00:00+00:00",
        "version":1,
        "volume":2,
        "elocation-id":"e00288",
        "doi":"10.7554/eLife.00288",
        "article-id":"10.7554/eLife.00288",
        "article-version-id":"00288.1",
        "pub-date":"2014-10-14T00:00:00+00:00",
        "path":"content/2/e00288v1",
        "article-type":"research-article",
        "status":"VOR",
        "publish":true,
        "contributors":[
          {
            "surname":"Choi",
            "given-names":"Hong Y",
            "references":{
              "affiliation":[
                "aff1"
              ]
            },
            "equal-contrib":true,
            "type":"author",
            "id":"author-2174"
          },
          {
            "surname":"Liu",
            "given-names":"Yun",
            "references":{
              "affiliation":[
                "aff2"
              ]
            },
            "equal-contrib":true,
            "type":"author",
            "id":"author-2175"
          },
          {
            "type":"author",
            "given-names":"Christian",
            "surname":"Tennert",
            "id":"author-2176",
            "references":{
              "affiliation":[
                "aff1"
              ]
            }
          },
          {
            "type":"author",
            "given-names":"Yoshie",
            "surname":"Sugiura",
            "id":"author-2177",
            "references":{
              "affiliation":[
                "aff2"
              ]
            }
          },
          {
            "type":"author",
            "given-names":"Andromachi",
            "surname":"Karakatsani",
            "id":"author-5751",
            "references":{
              "affiliation":[
                "aff3"
              ]
            }
          },
          {
            "type":"author",
            "given-names":"Stephan",
            "surname":"Kr\u00f6ger",
            "id":"author-5752",
            "references":{
              "affiliation":[
                "aff3"
              ]
            }
          },
          {
            "type":"author",
            "given-names":"Eric B",
            "surname":"Johnson",
            "id":"author-6539",
            "references":{
              "affiliation":[
                "aff1"
              ]
            }
          },
          {
            "type":"author",
            "given-names":"Robert E",
            "surname":"Hammer",
            "id":"author-2179",
            "references":{
              "affiliation":[
                "aff4"
              ]
            }
          },
          {
            "surname":"Lin",
            "corresp":true,
            "given-names":"Weichun",
            "references":{
              "affiliation":[
                "aff2"
              ]
            },
            "type":"author",
            "id":"author-2180"
          },
          {
            "surname":"Herz",
            "corresp":true,
            "given-names":"Joachim",
            "references":{
              "affiliation":[
                "aff1",
                "aff2",
                "aff5",
                "aff6"
              ]
            },
            "affiliations":[
              {
                "dept":"Department of Molecular Genetics",
                "city":"Dallas",
                "institution":"University of Texas Southwestern Medical Center",
                "country":"United States"
              }
            ],
            "type":"author",
            "id":"author-1351"
          }
        ],
        "referenced":{
          "affiliation":{
            "aff6":{
              "dept":"Center for Neuroscience",
              "city":"Freiburg",
              "institution":"Albert-Ludwigs-Universit\u00e4t Freiburg",
              "country":"Germany"
            },
            "aff5":{
              "dept":"Department of Neurology and Neurotherapeutics",
              "city":"Dallas",
              "institution":"University of Texas Southwestern Medical Center",
              "country":"United States"
            },
            "aff4":{
              "dept":"Department of Biochemistry",
              "city":"Dallas",
              "institution":"University of Texas Southwestern Medical Center",
              "country":"United States"
            },
            "aff3":{
              "dept":"Department of Physiological Genomics",
              "city":"M\u00fcnchen",
              "institution":"Ludwig-Maximilians-Universit\u00e4t M\u00fcnchen",
              "country":"Germany"
            },
            "aff2":{
              "dept":"Department of Neuroscience",
              "city":"Dallas",
              "institution":"University of Texas Southwestern Medical Center",
              "country":"United States"
            },
            "aff1":{
              "dept":"Department of Molecular Genetics",
              "city":"Dallas",
              "institution":"University of Texas Southwestern Medical Center",
              "country":"United States"
            }
          }
        }
      }
    """
    And I go to "content/2/e00288v1"
    Then I should see 3 ".elife-institution" elements
    Then I should see "University of Texas Southwestern Medical Center, United States; Ludwig-Maximilians-Universität München, Germany; Albert-Ludwigs-Universität Freiburg, Germany" in the ".elife-institutions-list" element

  Scenario: Duplicate affiliations are avoided even when afiliations are not referenced and associated directly to author
    Given there is an article:
    """
     {
      "title":"APP interacts with LRP4 and agrin to coordinate the development of the neuromuscular junction in mice",
      "status":"VOR",
      "article-type":"research-article",
      "pub-date":"2013-08-20T00:00:00+00:00",
      "version":1,
      "volume":2,
      "elocation-id":"e00288",
      "doi":"10.7554/eLife.00288",
      "article-id":"10.7554/eLife.00288",
      "article-version-id":"00288.1",
      "pub-date":"2014-10-14T00:00:00+00:00",
      "path":"content/2/e00288v1",
      "article-type":"research-article",
      "status":"VOR",
      "publish":true,
      "contributors":[
        {
          "surname":"Choi",
          "given-names":"Hong Y",
          "affiliations":[
            {
              "dept":"Department of Molecular Genetics",
              "city":"Dallas",
              "institution":"University of Texas Southwestern Medical Center",
              "country":"United States"
            }
          ],
          "equal-contrib":true,
          "type":"author",
          "id":"author-2174"
        },
        {
          "surname":"Liu",
          "given-names":"Yun",
          "affiliations":[
            {
              "dept":"Department of Molecular Genomics",
              "city":"Dallas",
              "institution":"University of Texas Southwestern Medical Center",
              "country":"United States"
            }
          ],
          "equal-contrib":true,
          "type":"author",
          "id":"author-2175"
        },
        {
          "type":"author",
          "given-names":"Christian",
          "surname":"Tennert",
          "id":"author-2176",
          "affiliations":[
            {
              "dept":"Department of Biology",
              "city":"Dallas",
              "institution":"University of Texas Southwestern Medical Center",
              "country":"United States"
            }
          ]
        },
        {
          "type":"author",
          "given-names":"Yoshie",
          "surname":"Sugiura",
          "id":"author-2177",
          "affiliations":[
            {
              "dept":"Department of Physics",
              "city":"Dallas2",
              "institution":"University of Texas Southwestern Medical Center",
              "country":"United States"
            }
          ]
        },
        {
          "type":"author",
          "given-names":"Andromachi",
          "surname":"Karakatsani",
          "id":"author-5751",
          "affiliations":[
            {
              "dept":"Department of Astronomical Sciences",
              "city":"Dallas",
              "institution":"University of Texas Southwestern Medical Center",
              "country":"United States"
            }
          ]
        },
        {
          "type":"author",
          "given-names":"Stephan",
          "surname":"Kr\u00f6ger",
          "id":"author-5752",
          "affiliations":[
            {
              "dept":"Department of Genetics",
              "city":"Dallas",
              "institution":"University of Texas Southwestern Medical Center",
              "country":"United States"
            }
          ]
        },
        {
          "type":"author",
          "given-names":"Eric B",
          "surname":"Johnson",
          "id":"author-6539",
          "affiliations":[
            {
              "dept":"Department of Molecular Genetics",
              "city":"Dallas",
              "institution":"University of Texas Southwestern Medical Center",
              "country":"United States"
            }
          ]
        },
        {
          "type":"author",
          "given-names":"Robert E",
          "surname":"Hammer",
          "id":"author-2179",
          "affiliations":[
            {
              "dept":"Department of Molecular Genomics",
              "city":"Dallas",
              "institution":"University of Texas Southwestern Medical Center",
              "country":"United States"
            }
          ]
        },
        {
          "surname":"Lin",
          "corresp":true,
          "given-names":"Weichun",
          "affiliations":[
            {
              "dept":"Department of Molecular Genetics",
              "city":"Dallas",
              "institution":"University of Texas Southwestern Medical Center",
              "country":"United States"
            }
          ],
          "type":"author",
          "id":"author-2180"
        },
        {
          "surname":"Herz",
          "corresp":true,
          "given-names":"Joachim",
          "affiliations":[
            {
              "dept":"Department of Molecular Genetics",
              "city":"Dallas",
              "institution":"University of Texas Southwestern Medical Center",
              "country":"United States"
            },
            {
              "dept":"Department of Molecular Genomics",
              "city":"Dallas",
              "institution":"University of Texas Southwestern Medical Center",
              "country":"United States"
            },
            {
              "dept":"Department of Molecular Biology",
              "city":"Dallas",
              "institution":"University of Texas Southwestern Medical Center",
              "country":"United States"
            }
          ],
          "type":"author",
          "id":"author-1351"
        }
      ]
    }
    """
    And I go to "content/2/e00288v1"
    Then I should see an ".elife-institution" element
    Then I should see "University of Texas Southwestern Medical Center, United States" in the ".elife-institutions-list" element

  Scenario: An affiliation should not appear in the listing if there is no institution
    Given there is an article:
      """
        {
          "article-type": "research-article",
          "title": "New opportunities at the wild frontier",
          "status": "VOR",
          "publish": true,
          "doi": "10.7554/eLife.06956",
          "pub-date": "2015-03-25T00:00:00+00:00",
          "volume": 4,
          "elocation-id": "e06956",
          "path": "content/4/e06956v1",
          "article-id": "06956",
          "categories": {
            "display-channel": [
              "Feature Article"
            ]
          },
          "contributors": [
            {
              "type": "author",
              "surname": "Alfred",
              "given-names": "Jane",
              "id": "author-17393",
              "role": "Consultant Editor",
              "corresp": true,
              "orcid": "http://orcid.org/0000-0001-6798-0064",
              "references": {
                "affiliation": [
                  "aff1"
                ]
              }
            },
            {
              "type": "author",
              "surname": "Baldwin",
              "given-names": "Ian T",
              "id": "author-1013",
              "role": "Senior Editor",
              "corresp": true,
              "orcid": "http://orcid.org/0000-0001-5371-2974",
              "references": {
                "affiliation": [
                  "aff2"
                ]
              }
            }
          ],
          "referenced": {
            "affiliation": {
              "aff1": {
                "city": "Cambridge",
                "country": "United Kingdom"
              },
              "aff2": {
                "institution": "Max Planck Institute for Chemical Ecology",
                "city": "Jena",
                "country": "Germany"
              }
            }
          },
          "version": 1,
          "article-version-id": "06956.1"
        }
      """
    And I go to "content/4/e06956v1"
    Then I should see an ".elife-institution" element
    Then I should see "Max Planck Institute for Chemical Ecology, Germany" in the ".elife-institutions-list" element

  Scenario: 'On behalf of' statement should be displayed in the author-list
    Given there is an article:
    """
      {
        "status": "VOR",
        "article-type": "research-article",
        "contributors": [
          {
            "type": "author",
            "given-names": "John",
            "surname": "Blangero",
            "id": "author-18716"
          },
          {
            "type": "author",
            "given-names": "David",
            "surname": "Reich",
            "id": "author-18717"
          },
          {
            "type": "author",
            "given-names": "Molly",
            "surname": "Przeworski",
            "id": "author-1167"
          },
          {
            "type": "on-behalf-of",
            "on-behalf-of": "on behalf of the T2D-GENES Consortium"
          }
        ],
        "pub-date": "2015-03-25T00:00:00Z",
        "title": "Non-crossover gene conversions show strong GC bias and unexpected clustering in humans",
        "elocation-id": "e04637",
        "publish": true,
        "article-version-id": "04637.1",
        "volume": 4,
        "doi": "10.7554/eLife.04637",
        "version": 1,
        "path": "content/4/e04637v1",
        "article-id": "04637",
        "categories": {
          "heading": [
            "Genes and chromosomes",
            "Genomics and evolutionary biology"
          ],
          "display-channel": [
            "Research article"
          ]
        }
      }
    """
    And I go to "content/4/e04637v1"
    Then I should see "John Blangero David Reich Molly Przeworski on behalf of the T2D-GENES Consortium" in the ".author-list" element
