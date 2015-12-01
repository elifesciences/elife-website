@xml @pdf
Feature: Article Version Source Assets
  So that we can easily change provider
  As a developer
  I need to the able to amend the path to the source xml and pdf

  @api
  Scenario Outline: Article page displays the appropriate content on the article page
    Given there are articles:
      """
        [
          {
            "title": "<manuscript_id>",
            "version": "<version_no>",
            "doi": "10.7554/eLife.<manuscript_id>",
            "volume": "1",
            "elocation-id": "e<manuscript_id>",
            "article-id": "<manuscript_id>",
            "article-version-id": "<manuscript_id>.<version_no>",
            "pub-date": "1979-08-17",
            "path": "content/1/e<manuscript_id>",
            "article-type": "research-article",
            "status": "VOR",
            "publish": "1"
          }
        ]
      """
    And I am logged in as a user with the "access administration menu,administer elife_article assets source" permissions
    When I am on "admin/config/services/elife-article-assets-source"
    And I fill in "Source assets base path" with "<source_assets_base_path>"
    And I fill in "Source XML file pattern" with "<source_xml_file_pattern>"
    And I fill in "Source PDF file pattern" with "<source_pdf_file_pattern>"
    And I press the "Save configuration" button
    Then I should see "<source_xml_location>"
    Then I should see "<source_pdf_location>"

    Examples:
      | manuscript_id | version_no | source_assets_base_path                 | source_xml_file_pattern                                                | source_xml_location                                        | source_pdf_file_pattern                                                | source_pdf_location                                        |
      | 05224         | 1          | http://cdn-site.elifesciences.org/      | [node:manuscript_id]/elife-[node:manuscript_id]-v[node:version_no].xml | http://cdn-site.elifesciences.org/05224/elife-05224-v1.xml | [node:manuscript_id]/elife-[node:manuscript_id]-v[node:version_no].pdf | http://cdn-site.elifesciences.org/05224/elife-05224-v1.pdf |
      | 00288         | 2          | http://cdn-site.elifesciences.org/      | [node:manuscript_id]/elife-[node:manuscript_id]-v[node:version_no].xml | http://cdn-site.elifesciences.org/00288/elife-00288-v2.xml | [node:manuscript_id]/elife-[node:manuscript_id]-v[node:version_no].pdf | http://cdn-site.elifesciences.org/00288/elife-00288-v2.pdf |
      | 00731         | 4          | http://cdn-site2.elifesciences.org/xml/ | [node:eloc_id]-v[node:version_no].xml                                  | http://cdn-site2.elifesciences.org/xml/e00731-v4.xml       | [node:eloc_id]-v[node:version_no].pdf                                  | http://cdn-site2.elifesciences.org/xml/e00731-v4.pdf       |
