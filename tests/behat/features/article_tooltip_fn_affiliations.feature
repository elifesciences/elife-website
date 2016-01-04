Feature: Footnote
  In Order to be able to see the Institutions the author is associated with
  As a reader
  I should be able to see the list of institutions in the author tooltip

  Scenario Outline: List of institutions author is associated with is shown in the tooltip
    Given the markup service is available
    And there is an article:
      """
        {
          "title": "VOR <eloc>",
          "version": 1,
          "doi": "10.7554/eLife.<eloc>",
          "volume": <volume>,
          "elocation-id": "e<eloc>",
          "article-id": "10.7554/eLife.<eloc>",
          "article-version-id": "<eloc>.1",
          "pub-date": "2014-10-14T00:00:00+00:00",
          "path": "content/<volume>/e<eloc>v1",
          "article-type": "research-article",
          "status": "VOR",
          "publish": true,
          "contributors": [
            {
              "equal-contrib": true,
              "type": "author",
              "id": "<id>",
              "surname": "Alegado",
              "given-names": "<author>"
            }
          ]
        }
      """
    And I go to "content/<volume>/e<eloc>v1"
    Then I should see "<author>" in the ".author-tooltip-name" element
    And I should see "<aff>" in the ".author-list-full" element

    Examples:
      | eloc  | volume | id        | author  | aff                                                                                                                                                                                                                                                                                                                                                                                                      |
      | 00288 | 2      | author-24 | Rebecca | Vaccine and Infectious Diseases Division, Fred Hutchinson Cancer Research Center, Seattle, United States; Department of Medicine, University of Washington, Seattle, United States                                                                                                                                                                                                                                                                                                                                 |
      | 03981 | 3      | author-25 | Sean    | Sean J Morrison is an Investigator of the Howard Hughes Medical Institute, and Director of the Children’s Research Institute at the University of Texas Southwestern Medical Center, Dallas, USA. He is also the Mary McDermott Cook Chair in Pediatric Genetics and Director of the Hamon Laboratory for Stem Cells and Cancer at UTSW, and a Cancer Prevention and Research Institute of Texas Scholar |
