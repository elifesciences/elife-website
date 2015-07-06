Feature: Article Resource - Citations (API)
  In order to maintain article content
  As a production system
  I need to be able to assign citations to the article via the resource api

  Scenario: POST an article with citations
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
    And the response code should be 200
    When I send a GET request to "api/article/05224.json"
    Then the response should contain json:
      """
        {
          "title": "VOR 05224",
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
