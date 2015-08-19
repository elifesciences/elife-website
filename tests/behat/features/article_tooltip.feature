Feature: Footnote
  In order to be able to get information on contributors of an article
  As a reader
  I should see contributor info in author tooltip

  @hover
  Scenario Outline: Information in author tooltip
    Given there is an article:
      """
        {
          "title": "VOR 00013",
          "version": "1",
          "doi": "10.7554/eLife.00013",
          "publish": "1",
          "volume": "3",
          "elocation-id": "e00013",
          "article-id": "10.7554/eLife.00013",
          "article-version-id": "00013.1",
          "pub-date": "2014-02-28",
          "path": "content/3/e00013",
          "article-type": "research-article",
          "status": "VOR",
          "contributors": [
            {
              "type": "author",
              "equal-contrib": "yes",
              "id": "author-23",
              "surname": "Alegado",
              "given-names": "Rosanna A",
              "suffix": "Jnr",
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
              "surname": "Brown",
              "given-names": "Laura W",
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
              "surname": "Cao",
              "given-names": "Shugeng",
              "references": {
                "affiliation": [
                  "aff2"
                ]
              }
            },
            {
              "type": "author",
              "id": "author-4",
              "surname": "Dermenjian",
              "given-names": "Renee Kathryn",
              "references": {
                "contribution": [
                  "con4"
                ],
                "competing-interest": [
                  "conf2"
                ],
                "present-address": [
                  "pa3"
                ]
              }
            },
            {
              "type": "editor",
              "id": "author-10",
              "surname": "Sneden",
              "given-names": "Christopher",
              "role": "Reviewing editor",
              "affiliations": [
                {
                  "institution": "Pediatric Dengue Vaccine Initiative",
                  "country": "United States"
                }
              ]
            },
            {
              "type": "author non-byline",
              "group-author-key": "group-author-id1",
              "surname": "Mullikin",
              "given-names": "Jim",
              "affiliations": [
                {
                  "institution": "Science Exchange, Palo Alto",
                  "city": "California"
                }
              ]
            }
          ],
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
              "par-7": {
                "institution": "Laura and John Arnold Foundation"
              }
            },
            "competing-interest": {
              "conf1": "JC: Reviewing editor, <italic>eLife</italic>.",
              "conf2": "The other authors declare that no competing interests exist."
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
            }
          }
        }
      """
    And I go to "content/3/e00013"
    # Then I should see "author-tooltip-name" in the ".elife-article-author-item" element
    Then I should see "<author>" in the ".author-list-full li:nth-of-type(<n>) .author-tooltip .author-tooltip-name" element

    Examples:
      | author                   | n |
      | Rosanna A Alegado        | 1 |
      | Laura W Brown            | 2 |
      | Shugeng Cao              | 3 |
      | Renee Kathryn Dermenjian | 4 |


