Feature: In order to sort article references
  As a user
  I need to have sorting options for references.

  Scenario: Sorting options under references
    Given there is an article:
    """
      {
        "title": "VOR 05224",
        "version": 1,
        "doi": "10.7554/eLife.05224",
        "volume": 4,
        "elocation-id": "e05224",
        "article-id": "10.7554/eLife.05224",
        "article-version-id": "05224",
        "pub-date": "1979-08-17T00:00:00+00:00",
        "path": "content/4/e05224",
        "article-type": "research-article",
        "status": "VOR",
        "publish": true,
        "citations": {
          "bib1": {
            "authors": [
              {
                "group-type": "author",
                "surname": "Agosta",
                "given-names": "WC"
              }
            ],
            "year": "1992",
            "source": "Chemical Communication"
          },
          "bib2": {
            "authors": [
              {
                "group-type": "author",
                "surname": "Ahmed",
                "given-names": "I"
              },
              {
                "group-type": "author",
                "surname": "Yokota",
                "given-names": "A"
              },
              {
                "group-type": "author",
                "surname": "Fujiwara",
                "given-names": "T"
              }
            ],
            "year": "2007",
            "title": "Chimaereicella boritolerans sp nov., a boron-tolerant and alkaliphilic bacterium of the family Flavobacteriaceae isolated from soil",
            "source": "International journal of systematic and evolutionary microbiology",
            "doi": "10.1099/ijs.0.64728-0"
          },
          "bib54": {
            "authors": [
              {
                "group-type": "author",
                "surname": "King",
                "given-names": "N"
              },
              {
                "group-type": "author",
                "surname": "Young",
                "given-names": "SL"
              },
              {
                "group-type": "author",
                "surname": "Abedin",
                "given-names": "M"
              },
              {
                "group-type": "author",
                "surname": "Carr",
                "given-names": "M"
              },
              {
                "group-type": "author",
                "surname": "Leadbeater",
                "given-names": "BSC"
              }
            ],
            "year": "2009",
            "title": "Starting and maintaining Monosiga brevicollis cultures",
            "source": "Cold Spring Harbor protocols",
            "comment": "pdb.prot5148"
          },
          "bib96": {
            "authors": [
              {
                "group-type": "author",
                "collab": "WHO"
              }
            ],
            "year": "2011",
            "title": "FlyBase 101-the basics of navigating FlyBase",
            "source": "Nucleic acids research"
          }
        }
      }
    """
    Then I go to "content/4/e05224"
    Then I should see an ".elife-reflinks-sortby" element
    Then I should see "Sort by:" in the ".elife-reflinks-sortby-label" element
    Then I should see "original order" in the ".elife-reflinks-sortby" element
    Then I should see "author" in the ".elife-reflinks-sortby" element
    Then I should see "title" in the ".elife-reflinks-sortby" element
    Then I should see "year" in the ".elife-reflinks-sortby" element
    Then I should see "cited in paper" in the ".elife-reflinks-sortby" element

