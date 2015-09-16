@develop
Feature: As a developer
  I should be able to output expected Metadata on article page for eLife Journal site

  Scenario Outline: Verify eLife article meta tags
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
    """
      {
        "title": "VOR 07939",
        "version": "1",
        "doi": "10.7554/eLife.07939",
        "publish": "1",
        "volume": "4",
        "elocation-id": "e07939",
        "article-id": "10.7554/eLife.07939",
        "article-version-id": "07939",
        "pub-date": "2015-07-24",
        "path": "content/4/e07939",
        "article-type": "research-article",
        "status": "VOR",
        "contributors": [
          {
            "type": "author",
            "equal-contrib": "yes",
            "id": "author-23",
            "surname": "Visweswaraiah",
            "given-names": "Jyothsna",
            "references": {
              "affiliation": [
                "aff1"
              ]
            }
          },
          {
            "type": "author",
            "equal-contrib": "yes",
            "id": "author-17",
            "surname": "Pittman",
            "given-names": "Yvette",
            "orcid": "http://orcid.org/0000-0002-7361-560X",
            "references": {
              "affiliation": [
                "aff2"
              ]
            }
          },
          {
            "type": "author",
            "id": "author-3",
            "surname": "Dever",
            "given-names": "Thomas E",
            "references": {
              "affiliation": [
                "aff2"
              ]
            }
          },
          {
            "type": "author",
            "id": "author-4",
            "surname": "Hinnebusch",
            "given-names": "Alan G",
            "references": {
              "contribution": [
                "con4"
              ]
            }
          },
          {
            "type": "editor",
            "id": "author-10",
            "surname": "Sonenberg",
            "given-names": "Nahum ",
            "role": "Reviewing editor",
            "affiliations": [
              {
                "institution": "Pediatric Dengue Vaccine Initiative",
                "country": "United States"
              }
            ]
          }
        ],
        "referenced": {
          "affiliation": {
            "aff1": {
              "dept": "Department of Molecular and Cell Biology",
              "institution": "University of California, Berkeley",
              "city": "Berkeley",
              "country": "United States"
            },
            "aff2": {
              "dept": "Department of Biological Chemistry and Molecular Pharmacology",
              "institution": "Harvard Medical School",
              "city": "Boston",
              "country": "United States"
            },
            "aff3": {
              "dept": "Department of Biochemistry",
              "institution": "Stanford University School of Medicine",
              "city": "Stanford",
              "country": "United States"
            }
          }
        }
      }
    """
    And the response code should be 200
    And I go to "content/4/e07939"
    Then the metatag attribute "<name>" should have the value "<content>"
    And I should see "<content>" in the "content" attribute of the "meta[name='<name>']" element

    Examples:
      | name        | content|
      | generator   | Drupal 7 (http://drupal.org)|
      |DC.Format    | text/html|
      |DC.Language  | en       |
      |DC.Title     | VOR 07939|
      |DC.Identifier| 10.7554/eLife.07939 |
      |DC.Date      |2015-07-24           |
      |DC.Publisher |eLife Sciences Publications Limited|
      |DC.Rights    |©  . This is an open-access article, free of all copyright, and may be freely reproduced, distributed, transmitted, modified, built upon, or otherwise used by anyone for any lawful purpose. The work is made available under the Creative Commons CC0 public domain dedication|
      |DC.Description|To make a protein, the DNA sequence of a gene is first copied to make an mRNA molecule, which is then translated into a protein by a molecular machine called the ribosome. The first step                                                                                     |

  Scenario Outline: Verify eLife article meta tag "DC.Contributor"
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
     """
      {
        "title": "VOR 07939",
        "version": "1",
        "doi": "10.7554/eLife.07939",
        "publish": "1",
        "volume": "4",
        "elocation-id": "e07939",
        "article-id": "10.7554/eLife.07939",
        "article-version-id": "07939",
        "pub-date": "2015-07-24",
        "path": "content/4/e07939",
        "article-type": "research-article",
        "status": "VOR",
        "contributors": [
          {
            "type": "author",
            "equal-contrib": "yes",
            "id": "author-23",
            "surname": "Visweswaraiah",
            "given-names": "Jyothsna",
            "references": {
              "affiliation": [
                "aff1"
              ]
            }
          },
          {
            "type": "author",
            "equal-contrib": "yes",
            "id": "author-17",
            "surname": "Pittman",
            "given-names": "Yvette",
            "orcid": "http://orcid.org/0000-0002-7361-560X",
            "references": {
              "affiliation": [
                "aff2"
              ]
            }
          },
          {
            "type": "author",
            "id": "author-3",
            "surname": "Dever",
            "given-names": "Thomas E",
            "references": {
              "affiliation": [
                "aff2"
              ]
            }
          },
          {
            "type": "author",
            "id": "author-4",
            "surname": "Hinnebusch",
            "given-names": "Alan G",
            "references": {
              "contribution": [
                "con4"
              ]
            }
          },
          {
            "type": "editor",
            "id": "author-10",
            "surname": "Sonenberg",
            "given-names": "Nahum ",
            "role": "Reviewing editor",
            "affiliations": [
              {
                "institution": "Pediatric Dengue Vaccine Initiative",
                "country": "United States"
              }
            ]
          }
        ],
        "referenced": {
          "affiliation": {
            "aff1": {
              "dept": "Department of Molecular and Cell Biology",
              "institution": "University of California, Berkeley",
              "city": "Berkeley",
              "country": "United States"
            },
            "aff2": {
              "dept": "Department of Biological Chemistry and Molecular Pharmacology",
              "institution": "Harvard Medical School",
              "city": "Boston",
              "country": "United States"
            },
            "aff3": {
              "dept": "Department of Biochemistry",
              "institution": "Stanford University School of Medicine",
              "city": "Stanford",
              "country": "United States"
            }
          }
        }
      }
     """

    And the response code should be 200
    And I go to "content/4/e07939"
    Then the metatag attribute "DC.Contributor" in position "<n>" should have the value "<content>"

    Examples:
      |n | content|
      |1 | Jyothsna Visweswaraiah  |
      |2 |Yvette Pittman           |
      |3 |Thomas E Dever|
      |4 |Alan G Hinnebusch      |
      |5 |Nahum Sonenberg|

  Scenario Outline: Verify eLife article citation meta tags
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
    """
      {
        "title": "VOR 07939",
        "version": "1",
        "doi": "10.7554/eLife.07939",
        "publish": "1",
        "volume": "4",
        "elocation-id": "e07939",
        "article-id": "10.7554/eLife.07939",
        "article-version-id": "07939",
        "pub-date": "2015-07-24",
        "path": "content/4/e07939",
        "article-type": "research-article",
        "status": "VOR",
        "contributors": [
          {
            "type": "author",
            "equal-contrib": "yes",
            "id": "author-23",
            "surname": "Visweswaraiah",
            "given-names": "Jyothsna",
            "references": {
              "affiliation": [
                "aff1"
              ]
            }
          },
          {
            "type": "author",
            "equal-contrib": "yes",
            "id": "author-17",
            "surname": "Pittman",
            "given-names": "Yvette",
            "orcid": "http://orcid.org/0000-0002-7361-560X",
            "references": {
              "affiliation": [
                "aff2"
              ]
            }
          },
          {
            "type": "author",
            "id": "author-3",
            "surname": "Dever",
            "given-names": "Thomas E",
            "references": {
              "affiliation": [
                "aff2"
              ]
            }
          },
          {
            "type": "author",
            "id": "author-4",
            "surname": "Hinnebusch",
            "given-names": "Alan G",
            "references": {
              "contribution": [
                "con4"
              ]
            }
          },
          {
            "type": "editor",
            "id": "author-10",
            "surname": "Sonenberg",
            "given-names": "Nahum ",
            "role": "Reviewing editor",
            "affiliations": [
              {
                "institution": "Pediatric Dengue Vaccine Initiative",
                "country": "United States"
              }
            ]
          }
        ],
        "referenced": {
          "affiliation": {
            "aff1": {
              "dept": "Department of Molecular and Cell Biology",
              "institution": "University of California, Berkeley",
              "city": "Berkeley",
              "country": "United States"
            },
            "aff2": {
              "dept": "Department of Biological Chemistry and Molecular Pharmacology",
              "institution": "Harvard Medical School",
              "city": "Boston",
              "country": "United States"
            },
            "aff3": {
              "dept": "Department of Biochemistry",
              "institution": "Stanford University School of Medicine",
              "city": "Stanford",
              "country": "United States"
            }
          }
        }
      }
    """
    And the response code should be 200
    And I go to "content/4/e07939"
    Then the metatag attribute "<name>" should have the value "<content>"
    And I should see "<content>" in the "content" attribute of the "meta[name='<name>']" element

    Examples:
    | name        | content|
    |citation_funding_source   | citation_funder=National Institutes of Health (NIH);citation_funder_id=http://dx.doi.org/10.13039/100000002;citation_grant_number=Intramural Program;citation_grant_recipient=Alan G Hinnebusch|
    |citation_keywords    | translation, initiation, regulation, Rps5/uS7, ribosome, yeast, S. cerevisiae|
    |article:published_time  | 2015-07-24       |
    |article:section     | Genes and chromosomes|
    |citation_journal_title| eLife |
    |citation_publisher      |eLife Sciences Publications Limited           |
    |citation_title |The β-hairpin of 40S exit channel protein Rps5/uS7 promotes efficient and accurate translation initiation in vivo|
    |citation_publication_date    |2015/07/24|
    |citation_mjid|elife;4/0/e07939|
    |citation_id| 4/0/e07939       |
    |citation_public_url|http://elifesciences.org/content/4/e07939 |
    |citation_abstract_html_url|http://elifesciences.org/content/4/e07939.abstract|
    |citation_full_html_url|http://elifesciences.org/content/4/e07939.full        |
    |citation_pdf_url|http://elifesciences.org/content/elife/4/e07939.full.pdf|
    |citation_issn   |2050-084X                                               |
    |citation_journal_abbrev|eLife Sciences                                   |
    |citation_doi           |10.7554/eLife.07939                              |
    |citation_pmid          |26203003                                         |
    |citation_volume        |4                                                |
    |citation_section       |Genes and chromosomes                            |
    |citation_firstpage     |e07939                                           |
