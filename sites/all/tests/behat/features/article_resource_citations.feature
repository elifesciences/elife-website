Feature: Article Resource - Kitchen sink (API)
  In order to maintain article content
  As a production system
  I need to be able to load the kitchen sink article via the resource api

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
              "year": "1992",
              "title": "Chimaereicella boritolerans sp nov., a boron-tolerant and alkaliphilic bacterium of the family Flavobacteriaceae isolated from soil",
              "source": "International journal of systematic and evolutionary microbiology",
              "doi": "10.1099/ijs.0.64728-0"
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
              "year": "1992",
              "title": "Chimaereicella boritolerans sp nov., a boron-tolerant and alkaliphilic bacterium of the family Flavobacteriaceae isolated from soil",
              "source": "International journal of systematic and evolutionary microbiology",
              "doi": "10.1099/ijs.0.64728-0"
            }
          }
        }
      """
