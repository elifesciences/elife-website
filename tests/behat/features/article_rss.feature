@api @wip
Feature: Article RSS
  As a something
  I want to something
  So I can something

  Scenario: No published articles
    When I send a GET request to "/rss/recent.xml"
    Then the response should be XML:
      """
        <?xml version="1.0" encoding="utf-8" ?>
        <rss version="2.0" xml:base="%BASE_URL%/" xmlns:atom="http://www.w3.org/2005/Atom">
        <channel>
        <title>eLife</title>
        <description>Articles published in eLife</description>
        <link>%BASE_URL%/</link>
        <atom:link rel="self" href="%BASE_URL%/rss/recent.xml" />
        <language>en</language>
        </channel>
        </rss>
      """

  Scenario: Complete article
    Given the markup service is available
    And there is an article:
      """
        {
          "title": "VOR 05224 <italic>v2</italic>",
          "version": 2,
          "doi": "10.7554/eLife.05224",
          "volume": 4,
          "elocation-id": "e05224",
          "article-id": "05224",
          "article-version-id": "05224.2",
          "pub-date": "1979-08-17T00:00:00Z",
          "path": "content/4/e05224v2",
          "article-type": "research-article",
          "status": "VOR",
          "publish": true,
          "categories": {
            "display-channel": [
              "Research article"
            ],
            "heading": [
              "Ecology",
              "Genomics and evolutionary biology"
            ]
          },
          "keywords": {
            "author-keywords": [
              "<italic>Papio cynocephalus<\/italic>",
              "social behavior"
            ]
          },
          "contributors": [
            {
              "type": "author",
              "equal-contrib": true,
              "id": "author-23",
              "surname": "Alegado",
              "given-names": "Rosanna A",
              "suffix": "Jnr",
              "references": {
                "email": [
                  "cor1"
                ]
              }
            },
            {
              "type": "author",
              "equal-contrib": true,
              "id": "author-17",
              "surname": "Brown",
              "given-names": "Laura W",
              "orcid": "http://orcid.org/0000-0002-7361-560X",
              "references": {
                "email": [
                  "cor2"
                ]
              }
            }
          ],
          "referenced": {
            "email": {
              "cor1": "foo@example.com",
              "cor2": "bar@example.com"
            }
          }
        }
      """
    When I send a GET request to "/rss/recent.xml"
    Then the response should be XML:
      """
        <?xml version="1.0" encoding="utf-8" ?>
        <rss version="2.0" xml:base="%BASE_URL%/" xmlns:atom="http://www.w3.org/2005/Atom">
        <channel>
        <title>eLife</title>
        <description>Articles published in eLife</description>
        <link>%BASE_URL%/</link>
        <atom:link rel="self" href="%BASE_URL%/rss/recent.xml" />
        <language>en</language>
        <item>
        <title>VOR 05224 v2</title>
        <link>%BASE_URL%/content/4/e05224v2</link>
        <description>&lt;p&gt;Social relationships have profound effects on health in humans and other primates, but the mechanisms that explain this relationship are not well understood. Using shotgun metagenomic data from wild baboons, we found that social group membership and social network relationships predicted both the taxonomic structure of the gut microbiome and the structure of genes encoded by gut microbial species. Rates of interaction directly explained variation in the gut microbiome, even after controlling for diet, kinship, and shared environments. They therefore strongly implicate direct physical contact among social partners in the transmission of gut microbial species. We identified 51 socially structured taxa, which were significantly enriched for anaerobic and non-spore-forming lifestyles. Our results argue that social interactions are an important determinant of gut microbiome composition in natural animal populations&#x2014;a relationship with important ramifications for understanding how social relationships influence health, as well as the evolution of group living.&lt;/p&gt;
&lt;p&gt;&lt;strong&gt;DOI:&lt;/strong&gt; &lt;a href="%BASE_URL%/lookup/doi/10.7554/eLife.05224.001"&gt;http://dx.doi.org/10.7554/eLife.05224.001&lt;/a&gt;&lt;/p&gt;</description>
        <author>foo@example.com</author>
        <category>Ecology</category>
        <category>Genomics and evolutionary biology</category>
        <category>Papio cynocephalus</category>
        <category>social behavior</category>
        <guid isPermaLink="true">http://dx.doi.org/10.7554/eLife.05224</guid>
        <pubDate>Fri, 17 Aug 1979 00:00:00 +0000</pubDate>
        <source url="%BASE_URL%/rss/recent.xml">eLife</source>
        </item>
        </channel>
        </rss>
      """

  Scenario: Multiple published articles
    Given there are articles:
      """
        [
          {
            "title": "VOR 05224 v1",
            "version": 1,
            "doi": "10.7554/eLife.05224",
            "volume": 4,
            "elocation-id": "e05224",
            "article-id": "10.7554/eLife.05224",
            "article-version-id": "05224.v1",
            "pub-date": "2000-01-01T00:00:00Z",
            "update": "2001-01-01T00:00:00Z",
            "path": "content/4/e05224v1",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true
          },
          {
            "title": "VOR 05225 v1",
            "version": 1,
            "doi": "10.7554/eLife.05225",
            "volume": 4,
            "elocation-id": "e05225",
            "article-id": "10.7554/eLife.05225",
            "article-version-id": "05225.v1",
            "pub-date": "1999-01-01T00:00:00Z",
            "update": "1999-01-01T00:00:00Z",
            "path": "content/4/e05225v1",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true
          },
          {
            "title": "VOR 05225 v2",
            "version": 1,
            "doi": "10.7554/eLife.05225",
            "volume": 4,
            "elocation-id": "e05225",
            "article-id": "10.7554/eLife.05225",
            "article-version-id": "05225.v2",
            "pub-date": "1999-01-01T00:00:00Z",
            "update": "1999-01-01T00:00:00Z",
            "path": "content/4/e05225v2",
            "article-type": "research-article",
            "status": "VOR",
            "publish": true
          },
          {
            "title": "VOR 05226 v1",
            "version": 1,
            "doi": "10.7554/eLife.05226",
            "volume": 4,
            "elocation-id": "e05226",
            "article-id": "10.7554/eLife.05226",
            "article-version-id": "05226.v1",
            "pub-date": "1999-01-01T00:00:00Z",
            "update": "1999-01-01T00:00:00Z",
            "path": "content/4/e05226v1",
            "article-type": "research-article",
            "status": "VOR",
            "publish": false
          }
        ]
      """
    When I send a GET request to "/rss/recent.xml"
    Then the response should be XML:
      """
        <?xml version="1.0" encoding="utf-8" ?>
        <rss version="2.0" xml:base="%BASE_URL%/" xmlns:atom="http://www.w3.org/2005/Atom">
        <channel>
        <title>eLife</title>
        <description>Articles published in eLife</description>
        <link>%BASE_URL%/</link>
        <atom:link rel="self" href="%BASE_URL%/rss/recent.xml" />
        <language>en</language>
        <item>
        <title>VOR 05224 v1</title>
        <link>%BASE_URL%/content/4/e05224v1</link>
        <guid isPermaLink="true">http://dx.doi.org/10.7554/eLife.05224</guid>
        <pubDate>Sat, 01 Jan 2000 00:00:00 +0000</pubDate>
        <source url="%BASE_URL%/rss/recent.xml">eLife</source>
        </item>
        <item>
        <title>VOR 05225 v2</title>
        <link>%BASE_URL%/content/4/e05225v2</link>
        <guid isPermaLink="true">http://dx.doi.org/10.7554/eLife.05225</guid>
        <pubDate>Fri, 01 Jan 1999 00:00:00 +0000</pubDate>
        <source url="%BASE_URL%/rss/recent.xml">eLife</source>
        </item>
        </channel>
        </rss>
      """

  Scenario: No upcoming articles
    When I send a GET request to "/rss/ahead.xml"
    Then the response should be XML:
      """
        <?xml version="1.0" encoding="utf-8" ?>
        <rss version="2.0" xml:base="%BASE_URL%/" xmlns:atom="http://www.w3.org/2005/Atom">
        <channel>
        <title>eLife</title>
        <description>eLife PAP articles</description>
        <link>%BASE_URL%/</link>
        <atom:link rel="self" href="%BASE_URL%/rss/ahead.xml" />
        <language>en</language>
        </channel>
        </rss>
      """

  Scenario: Multiple upcoming articles
    Given there are articles:
      """
        [
          {
            "title": "Early 05224 v1",
            "version": 1,
            "doi": "10.7554/eLife.05224",
            "volume": 4,
            "elocation-id": "e05224",
            "article-id": "10.7554/eLife.05224",
            "article-version-id": "05224.early.v1",
            "pub-date": "2000-01-01T00:00:00Z",
            "update": "2001-01-01T00:00:00Z",
            "path": "content/4/e05224.early.v1",
            "article-type": "research-article",
            "status": "POA",
            "publish": true
          },
          {
            "title": "Early 05225 v1",
            "version": 1,
            "doi": "10.7554/eLife.05225",
            "volume": 4,
            "elocation-id": "e05225",
            "article-id": "10.7554/eLife.05225",
            "article-version-id": "05225.early.v1",
            "pub-date": "1999-01-01T00:00:00Z",
            "update": "1999-01-01T00:00:00Z",
            "path": "content/4/e05225.early.v1",
            "article-type": "research-article",
            "status": "POA",
            "publish": true
          },
          {
            "title": "Early 05225 v2",
            "version": 1,
            "doi": "10.7554/eLife.05225",
            "volume": 4,
            "elocation-id": "e05225",
            "article-id": "10.7554/eLife.05225",
            "article-version-id": "05225.early.v2",
            "pub-date": "1999-01-01T00:00:00Z",
            "update": "1999-01-01T00:00:00Z",
            "path": "content/4/e05225.early.v2",
            "article-type": "research-article",
            "status": "POA",
            "publish": true
          },
          {
            "title": "Early 05226 v1",
            "version": 1,
            "doi": "10.7554/eLife.05226",
            "volume": 4,
            "elocation-id": "e05226",
            "article-id": "10.7554/eLife.05226",
            "article-version-id": "05226.early.v1",
            "pub-date": "1999-01-01T00:00:00Z",
            "update": "1999-01-01T00:00:00Z",
            "path": "content/4/e05226.early.v1",
            "article-type": "research-article",
            "status": "POA",
            "publish": false
          }
        ]
      """
    When I send a GET request to "/rss/ahead.xml"
    Then the response should be XML:
      """
        <?xml version="1.0" encoding="utf-8" ?>
        <rss version="2.0" xml:base="%BASE_URL%/" xmlns:atom="http://www.w3.org/2005/Atom">
        <channel>
        <title>eLife</title>
        <description>eLife PAP articles</description>
        <link>%BASE_URL%/</link>
        <atom:link rel="self" href="%BASE_URL%/rss/ahead.xml" />
        <language>en</language>
        <item>
        <title>Early 05224 v1</title>
        <link>%BASE_URL%/content/4/e05224.early.v1</link>
        <guid isPermaLink="true">http://dx.doi.org/10.7554/eLife.05224</guid>
        <pubDate>Sat, 01 Jan 2000 00:00:00 +0000</pubDate>
        <source url="%BASE_URL%/rss/ahead.xml">eLife</source>
        </item>
        <item>
        <title>Early 05225 v2</title>
        <link>%BASE_URL%/content/4/e05225.early.v2</link>
        <guid isPermaLink="true">http://dx.doi.org/10.7554/eLife.05225</guid>
        <pubDate>Fri, 01 Jan 1999 00:00:00 +0000</pubDate>
        <source url="%BASE_URL%/rss/ahead.xml">eLife</source>
        </item>
        </channel>
        </rss>
      """
