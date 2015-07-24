<?php

namespace eLife\EIF;

use DateTimeImmutable;
use eLife\EIF\ArticleVersion\BaseFragment;
use eLife\EIF\ArticleVersion\Citation;
use eLife\EIF\ArticleVersion\Contributor;
use eLife\EIF\ArticleVersion\Contributor\CollabContributor;
use eLife\EIF\ArticleVersion\Contributor\PersonContributor\BylineContributor;
use eLife\EIF\ArticleVersion\Referenced;
use eLife\EIF\ArticleVersion\RelatedArticle;
use JMS\Serializer\Annotation as Serializer;

final class ArticleVersion {
  /**
   * @var string
   *
   * @Serializer\Type("string")
   */
  private $title;

  /**
   * @var string|null
   *
   * @Serializer\Type("string")
   * @Serializer\SerializedName("impact-statement")
   */
  private $impact_statement;

  /**
   * @var string
   *
   * @Serializer\Type("string")
   */
  private $version;

  /**
   * @var string
   *
   * @Serializer\Type("string")
   */
  private $doi;

  /**
   * @var string
   *
   * @Serializer\Type("string")
   */
  private $publish;

  /**
   * @var string
   *
   * @Serializer\Type("string")
   */
  private $volume;

  /**
   * @var string
   *
   * @Serializer\Type("string")
   * @Serializer\SerializedName("elocation-id")
   */
  private $elocation_id;

  /**
   * @var string
   *
   * @Serializer\Type("string")
   * @Serializer\SerializedName("article-id")
   */
  private $article_id;

  /**
   * @var string
   *
   * @Serializer\Type("string")
   * @Serializer\SerializedName("article-version-id")
   */
  private $article_version_id;

  /**
   * @var string
   *
   * @Serializer\Type("string")
   * @Serializer\SerializedName("pub-date")
   */
  private $pub_date;

  /**
   * @var string|null
   *
   * @Serializer\Type("string")
   */
  private $update;

  /**
   * @var string
   *
   * @Serializer\Type("string")
   */
  private $path;

  /**
   * @var string
   *
   * @Serializer\Type("string")
   * @Serializer\SerializedName("article-type")
   */
  private $article_type;

  /**
   * @var string
   *
   * @Serializer\Type("string")
   */
  private $status;

  /**
   * @var array
   *
   * @Serializer\Type("array<string,array<string>>")
   */
  private $categories = [];

  /**
   * @var array
   *
   * @Serializer\Type("array<string,array<string>>")
   */
  private $keywords = [];

  /**
   * @var RelatedArticle[]
   *
   * @Serializer\Type("array<eLife\EIF\ArticleVersion\RelatedArticle>")
   * @Serializer\SerializedName("related-articles")
   */
  private $related_articles = [];

  /**
   * @var Contributor[]
   *
   * @Serializer\Type("array<eLife\EIF\ArticleVersion\Contributor>")
   */
  private $contributors = [];

  /**
   * @var Referenced|null
   *
   * @Serializer\Type("eLife\EIF\ArticleVersion\Referenced")
   */
  private $referenced;

  /**
   * @var BaseFragment[]
   *
   * @Serializer\Type("array<eLife\EIF\ArticleVersion\BaseFragment>")
   */
  private $fragments = [];

  /**
   * @var Citation[]
   *
   * @Serializer\Type("array<string,eLife\EIF\ArticleVersion\Citation>")
   */
  private $citations = [];

  /**
   * @param string $title
   * @param string|null $impact_statement
   * @param string $version
   * @param string $doi
   * @param boolean $publish
   * @param integer $volume
   * @param string $elocation_id
   * @param string $article_id
   * @param string $article_version_id
   * @param DateTimeImmutable $pub_date
   * @param DateTimeImmutable|null $update
   * @param string $path
   * @param string $article_type
   * @param string $status
   * @param array $categories
   * @param array $keywords
   * @param RelatedArticle[] $related_articles
   * @param Contributor[] $contributors
   * @param Referenced $referenced
   * @param BaseFragment[] $fragments
   * @param Citation[] $citations
   */
  public function __construct(
    $title,
    $impact_statement,
    $version,
    $doi,
    $publish,
    $volume,
    $elocation_id,
    $article_id,
    $article_version_id,
    DateTimeImmutable $pub_date,
    DateTimeImmutable $update = NULL,
    $path,
    $article_type,
    $status,
    array $categories,
    array $keywords,
    array $related_articles,
    array $contributors,
    Referenced $referenced,
    array $fragments,
    array $citations
  ) {
    $this->title = (string) $title;
    $this->impact_statement = $impact_statement;
    $this->version = (string) $version;
    $this->doi = (string) $doi;
    $this->publish = (string) $publish;
    $this->volume = (string) $volume;
    $this->elocation_id = (string) $elocation_id;
    $this->article_id = (string) $article_id;
    $this->article_version_id = (string) $article_version_id;
    $this->pub_date = $pub_date->format('Y-m-d');
    if ($update) {
      $this->update = $update->format('Y-m-d');
    }
    $this->path = (string) $path;
    $this->article_type = (string) $article_type;
    $this->status = (string) $status;
    $this->categories = $categories;
    $this->keywords = $keywords;
    $this->related_articles = $related_articles;
    $this->contributors = $contributors;
    $this->referenced = $referenced;
    $this->fragments = $fragments;
    $this->citations = $citations;
  }

  private function getFragmentDois() {
    static $dois = [];

    // We only need to gather the dois once.
    if (empty($dois)) {
      /* @param BaseFragment[] $fragments */
      $closure = function(array $fragments) use (&$dois, &$closure) {
        foreach ($fragments as $fragment) {
          $dois[$fragment->getDoi()] = $fragment;
          $closure($fragment->getFragments());
        }
      };
      $closure($this->fragments);
    }

    return $dois;
  }

  /**
   * @param string $doi
   * @return BaseFragment|null
   */
  public function getFragment($doi) {
    $dois = $this->getFragmentDois();
    return isset($dois[$doi]) ? $dois[$doi] : NULL;
  }

  public function getTitle() {
    return $this->title;
  }

  public function getImpactStatement() {
    return $this->impact_statement;
  }

  public function getVersion() {
    return $this->version;
  }

  public function getDoi() {
    return $this->doi;
  }

  public function getDoiUrl() {
    return 'http://dx.doi.org/' . $this->doi;
  }

  public function getPublish() {
    return (bool) $this->publish;
  }

  public function getVolume() {
    return (int) $this->volume;
  }

  public function getElocationId() {
    return $this->elocation_id;
  }

  public function getArticleId() {
    return $this->article_id;
  }

  public function getArticleVersionId() {
    return $this->article_version_id;
  }

  public function getPubDate() {
    return DateTimeImmutable::createFromFormat('Y-m-d H:i:s', $this->pub_date . ' 00:00:00');
  }

  public function getUpdate() {
    if (NULL === $this->update) {
      return NULL;
    }

    return DateTimeImmutable::createFromFormat('Y-m-d H:i:s', $this->update . ' 00:00:00');
  }

  public function getPath() {
    return $this->path;
  }

  public function getArticleType() {
    return $this->article_type;
  }

  public function getStatus() {
    return $this->status;
  }

  public function getCategories() {
    return $this->categories;
  }

  public function getCategoriesOfType($type) {
    return (isset($this->categories[$type])) ? $this->categories[$type] : [];
  }

  public function getDisplayChannels() {
    return $this->getCategoriesOfType('display-channel');
  }

  public function getHeadings() {
    return $this->getCategoriesOfType('heading');
  }

  public function getKeywords() {
    return $this->keywords;
  }

  public function getRelatedArticles() {
    return $this->related_articles;
  }

  public function getContributors() {
    return $this->contributors;
  }

  public function getReferenced() {
    if (NULL === $this->referenced) {
      return new Referenced([], [], [], [], [], [], [], [], []);
    }

    return $this->referenced;
  }

  public function getFragments() {
    return $this->fragments;
  }

  public function getCitations() {
    return $this->citations;
  }

  public function getCiteAs() {
    $cite_as = $this->getPubDate()->format('Y');
    if ($this->getStatus() == 'POA') {
      $cite_as .= ';' . $this->getDoi();
    }
    else {
      $cite_as .= ';' . $this->getVolume() . ':' . $this->getElocationId();
    }

    return $cite_as;
  }

  public function getSimpleAuthorList() {
    $authors = [];
    foreach ($this->getContributors() as $contributor) {
      $name = [];
      if ($contributor instanceof BylineContributor) {
        if ($contributor->getType() != 'author') {
          continue;
        }
        if ($given_names = $contributor->getGivenNames()) {
          $name['given-names'] = $given_names;
        }
        if ($surname = $contributor->getSurname()) {
          $name['surname'] = $surname;
        }
        if ($suffix = $contributor->getSuffix()) {
          $name['suffix'] = $suffix;
        }
      }
      elseif ($contributor instanceof CollabContributor) {
        if ($collab = $contributor->getCollab()) {
          $name['collab'] = $collab;
        }
      }
      if (!empty($name)) {
        $authors[] = implode(' ', $name);
      }
    }

    return $authors;
  }
}
