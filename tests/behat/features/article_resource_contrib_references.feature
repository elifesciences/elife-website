Feature: Article Resource - Contributor references (API)
  In order to maintain article content
  As a production system
  I need to be able to assign contributor references to the article via the resource api

  Scenario: Set contributor references
    Given I set header "Content-Type" with value "application/json"
    And I send a POST request to "api/article.json" with body:
      """
        {
          "title": "VOR 05224",
          "version": "1",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "article-id": "10.7554/eLife.05224",
          "article-version-id": "05224",
          "pub-date": "1979-08-17",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "VOR",
          "publish": "1",
          "referenced": {
            "equal-contrib": {
              "equal-contrib": "These authors contributed equally to this work",
              "equal-contrib2": "These authors contributed equally to this work"
            },
            "email": {
              "cor1": "jon_clardy@hms.harvard.edu",
              "cor2": "nking@berkeley.edu",
              "cor3": "mharrison@elifesciences.org"
            },
            "funding": {
              "par-1": {
                "id": "dx.doi.org/10.13039/100000011",
                "id-type": "FundRef",
                "institution": "Howard Hughes Medical Institute"
              },
              "par-2": {
                "id": "dx.doi.org/10.13039/100000002",
                "id-type": "FundRef",
                "institution": "National Institutes of Health",
                "award-id": "F32 GM086054"
              },
              "par-3": {
                "id": "dx.doi.org/10.13039/100000002",
                "id-type": "FundRef",
                "institution": "National Institutes of Health",
                "award-id": "F32 GM089018"
              },
              "par-4": {
                "id": "dx.doi.org/10.13039/100000002",
                "id-type": "FundRef",
                "institution": "National Institutes of Health",
                "award-id": "R01 GM086258"
              },
              "par-5": {
                "id": "dx.doi.org/10.13039/100000002",
                "id-type": "FundRef",
                "institution": "National Institutes of Health",
                "award-id": "R01 GM099533"
              },
              "par-6": {
                "id": "dx.doi.org/10.13039/100000002",
                "id-type": "FundRef",
                "institution": "National Institutes of Health",
                "award-id": "T32 HG00047"
              },
              "par-7": {
                "institution": "Laura and John Arnold Foundation"
              }
            },
            "competing-interest": {
              "conf1": "JC: Reviewing editor, <italic>eLife</italic>.",
              "conf2": "The author reviewed Goldacre's first book for the BMJ, and is mentioned briefly in Bad Pharma. Over the years he has had some meals paid for by drug companies and spoken at meetings sponsored by drug companies (as has Goldacre), which is hard to avoid if you speak at all as a doctor. 30 years ago he won an award from the Medical Journalists' Association that was sponsored by Eli Lilly, and discovered that the company thought it had bought him. Since then he has avoided prizes awarded by drug companies."
            },
            "contribution": {
              "con1": "RAA, Conception and design, Acquisition of data, Analysis and interpretation of data, Drafting or revising the article",
              "con2": "LWB, Conception and design, Acquisition of data, Analysis and interpretation of data, Drafting or revising the article",
              "con3": "CS, Acquisition of data, Analysis and interpretation of data, Drafting or revising the article",
              "con4": "RKD, Acquisition of data, Analysis and interpretation of data",
              "con5": "RZ, Acquisition of data, Analysis and interpretation of data",
              "con6": "SRF, Acquisition of data, Analysis and interpretation of data",
              "con7": "JC, Conception and design, Analysis and interpretation of data, Drafting or revising the article",
              "con8": "NK, Conception and design, Analysis and interpretation of data, Drafting or revising the article",
              "con9": "NISC Comparative Sequencing Program: JM did X, IM did Y and JB did Z and Y"
            },
            "present-address": {
              "pa1": "Department of Wellcome Trust, Sanger Institute, London, United Kingdom",
              "pa2": "Department of Biological Chemistry and Molecular Pharmacology, Harvard Medical School, Boston, United States",
              "pa3": "eLife Sciences editorial Office, eLife Sciences, Cambridge, United Kingdom"
            },
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
            },
            "related-object": {
              "dataro1": {},
              "dataro2": {}
            }
          }
        }
      """
    And the response code should be 200
    When I send a GET request to "api/article/05224.json"
    Then the response should contain json:
      """
        {
          "title": "VOR 05224",
          "version": "1",
          "doi": "10.7554/eLife.05224",
          "volume": "4",
          "article-id": "10.7554/eLife.05224",
          "article-version-id": "05224",
          "pub-date": "1979-08-17",
          "path": "content/4/e05224",
          "article-type": "research-article",
          "status": "VOR",
          "referenced": {
            "equal-contrib": {
              "equal-contrib": "These authors contributed equally to this work",
              "equal-contrib2": "These authors contributed equally to this work"
            },
            "email": {
              "cor1": "jon_clardy@hms.harvard.edu",
              "cor2": "nking@berkeley.edu",
              "cor3": "mharrison@elifesciences.org"
            },
            "funding": {
              "par-1": {
                "id": "dx.doi.org/10.13039/100000011",
                "id-type": "FundRef",
                "institution": "Howard Hughes Medical Institute",
                "institution-type": "university"
              },
              "par-2": {
                "id": "dx.doi.org/10.13039/100000002",
                "id-type": "FundRef",
                "institution": "National Institutes of Health",
                "institution-type": "university",
                "award-id": "F32 GM086054"
              },
              "par-3": {
                "id": "dx.doi.org/10.13039/100000002",
                "id-type": "FundRef",
                "institution": "National Institutes of Health",
                "institution-type": "university",
                "award-id": "F32 GM089018"
              },
              "par-4": {
                "id": "dx.doi.org/10.13039/100000002",
                "id-type": "FundRef",
                "institution": "National Institutes of Health",
                "institution-type": "university",
                "award-id": "R01 GM086258"
              },
              "par-5": {
                "id": "dx.doi.org/10.13039/100000002",
                "id-type": "FundRef",
                "institution": "National Institutes of Health",
                "institution-type": "university",
                "award-id": "R01 GM099533"
              },
              "par-6": {
                "id": "dx.doi.org/10.13039/100000002",
                "id-type": "FundRef",
                "institution": "National Institutes of Health",
                "institution-type": "university",
                "award-id": "T32 HG00047"
              },
              "par-7": {
                "institution": "Laura and John Arnold Foundation",
                "institution-type": "university"
              }
            },
            "competing-interest": {
              "conf1": "JC: Reviewing editor, <italic>eLife</italic>.",
              "conf2": "The author reviewed Goldacre's first book for the BMJ, and is mentioned briefly in Bad Pharma. Over the years he has had some meals paid for by drug companies and spoken at meetings sponsored by drug companies (as has Goldacre), which is hard to avoid if you speak at all as a doctor. 30 years ago he won an award from the Medical Journalists' Association that was sponsored by Eli Lilly, and discovered that the company thought it had bought him. Since then he has avoided prizes awarded by drug companies."
            },
            "contribution": {
              "con1": "RAA, Conception and design, Acquisition of data, Analysis and interpretation of data, Drafting or revising the article",
              "con2": "LWB, Conception and design, Acquisition of data, Analysis and interpretation of data, Drafting or revising the article",
              "con3": "CS, Acquisition of data, Analysis and interpretation of data, Drafting or revising the article",
              "con4": "RKD, Acquisition of data, Analysis and interpretation of data",
              "con5": "RZ, Acquisition of data, Analysis and interpretation of data",
              "con6": "SRF, Acquisition of data, Analysis and interpretation of data",
              "con7": "JC, Conception and design, Analysis and interpretation of data, Drafting or revising the article",
              "con8": "NK, Conception and design, Analysis and interpretation of data, Drafting or revising the article",
              "con9": "NISC Comparative Sequencing Program: JM did X, IM did Y and JB did Z and Y"
            },
            "present-address": {
              "pa1": "Department of Wellcome Trust, Sanger Institute, London, United Kingdom",
              "pa2": "Department of Biological Chemistry and Molecular Pharmacology, Harvard Medical School, Boston, United States",
              "pa3": "eLife Sciences editorial Office, eLife Sciences, Cambridge, United Kingdom"
            },
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
            },
            "related-object": {
              "dataro1": {},
              "dataro2": {}
            }
          }
        }
      """
