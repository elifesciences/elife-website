<?php

namespace eLife\EIF;

use DateTimeImmutable;
use eLife\EIF\ArticleVersion\BaseFragment;
use eLife\EIF\ArticleVersion\Citation;
use eLife\EIF\ArticleVersion\Contributor;
use eLife\EIF\ArticleVersion\Referenced;
use eLife\EIF\ArticleVersion\RelatedArticle;
use JMS\Serializer\Annotation as Serializer;
use JMS\Serializer\Annotation\ExclusionPolicy;
use JMS\Serializer\Annotation\Exclude;

/**
 * @ExclusionPolicy("none")
 */
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
   * @var BaseFragment[]
   *
   * @Exclude
   */
  private $fragment_dois = [];

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

    $this->setFragmentDOIs($fragments);
  }

  /**
   * @param BaseFragment[] $fragments
   */
  private function setFragmentDOIs(array $fragments) {
    foreach ($fragments as $fragment) {
      $this->fragment_dois[$fragment->getDoi()] = $fragment;
      $this->setFragmentDOIs($fragment->getFragments());
    }
  }

  /**
   * @param string $doi
   * @return BaseFragment|null
   */
  public function getFragment($doi) {
    return isset($this->fragment_dois[$doi]) ? $this->fragment_dois[$doi] : NULL;
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

  public function getPublish() {
    return (bool) $this->publish;
  }

  public function getVolume() {
    return (int) $this->volume;
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
      return new Referenced([], [], [], [], [], [], [], []);
    }

    return $this->referenced;
  }

  public function getFragments() {
    return $this->fragments;
  }

  public function getCitations() {
    return $this->citations;
  }
}
