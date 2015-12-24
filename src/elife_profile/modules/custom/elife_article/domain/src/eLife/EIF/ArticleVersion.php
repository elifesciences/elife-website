<?php

namespace eLife\EIF;

use DateTime;
use DateTimeImmutable;
use DateTimeZone;
use eLife\EIF\ArticleVersion\BaseContributor;
use eLife\EIF\ArticleVersion\BaseFragment;
use eLife\EIF\ArticleVersion\Citation;
use eLife\EIF\ArticleVersion\Contributor;
use eLife\EIF\ArticleVersion\Contributor\CollabContributor;
use eLife\EIF\ArticleVersion\Contributor\OnBehalfOfContributor;
use eLife\EIF\ArticleVersion\Contributor\PersonContributor\BylineContributor;
use eLife\EIF\ArticleVersion\Fragment;
use eLife\EIF\ArticleVersion\Referenced;
use eLife\EIF\ArticleVersion\RelatedArticle;
use eLife\EIF\ArticleVersion\SubArticle;
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
   * @var int
   *
   * @Serializer\Type("integer")
   */
  private $version;

  /**
   * @var string
   *
   * @Serializer\Type("string")
   */
  private $doi;

  /**
   * @var bool
   *
   * @Serializer\Type("boolean")
   */
  private $publish;

  /**
   * @var int
   *
   * @Serializer\Type("integer")
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
   * @var DateTime|null
   *
   * @Serializer\Type("DateTime<'Y-m-d\TH:i:sP'>")
   * @Serializer\SerializedName("pub-date")
   */
  private $pub_date;

  /**
   * @var DateTime|null
   *
   * @Serializer\Type("DateTime<'Y-m-d\TH:i:sP'>")
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
   * @var BaseContributor[]
   *
   * @Serializer\Type("array<eLife\EIF\ArticleVersion\BaseContributor>")
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
   * @param integer $version
   * @param string $doi
   * @param boolean $publish
   * @param integer $volume
   * @param string $elocation_id
   * @param string $article_id
   * @param string $article_version_id
   * @param DateTimeImmutable|null $pub_date
   * @param DateTimeImmutable|null $update
   * @param string $path
   * @param string $article_type
   * @param string $status
   * @param array $categories
   * @param array $keywords
   * @param RelatedArticle[] $related_articles
   * @param BaseContributor[] $contributors
   * @param Referenced $referenced
   * @param BaseFragment[] $fragments
   * @param Citation[] $citations
   */
  public function __construct(
    $title,
    $impact_statement,
    $version,
    $doi,
    $publish = FALSE,
    $volume,
    $elocation_id,
    $article_id,
    $article_version_id,
    DateTimeImmutable $pub_date = NULL,
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
    $this->version = (int) $version;
    $this->doi = (string) $doi;
    $this->publish = (bool) $publish;
    $this->volume = (int) $volume;
    $this->elocation_id = (string) $elocation_id;
    $this->article_id = (string) $article_id;
    $this->article_version_id = (string) $article_version_id;
    if ($pub_date) {
      $this->pub_date = DateTime::createFromFormat(DATE_RFC3339, $pub_date->setTimezone(new DateTimeZone('UTC'))->format(DATE_RFC3339));
    }
    if ($update) {
      $this->update = DateTime::createFromFormat(DATE_RFC3339, $update->setTimezone(new DateTimeZone('UTC'))->format(DATE_RFC3339));
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
    return $this->volume;
  }

  public function getElocationId() {
    return $this->elocation_id;
  }

  public function getArticleId() {
    return $this->article_id;
  }

  public function getManuscriptId() {
    return ltrim($this->getElocationId(), 'e');
  }

  public function getArticleVersionId() {
    return $this->article_version_id;
  }

  public function getPubDate() {
    if (NULL === $this->pub_date) {
      return NULL;
    }
    return DateTimeImmutable::createFromFormat(DATE_RFC3339, $this->pub_date->setTimezone(new DateTimeZone('UTC'))->format(DATE_RFC3339));
  }

  public function getUpdate() {
    if (NULL === $this->update) {
      return NULL;
    }

    return DateTimeImmutable::createFromFormat(DATE_RFC3339, $this->update->setTimezone(new DateTimeZone('UTC'))->format(DATE_RFC3339));
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

  /**
   * @param array|string $types
   * @param int $level
   *   set as 0 for all levels
   * @return array|Fragment[]
   */
  public function getFragmentsOfType($types, $level = 1) {
    if (!is_array($types)) {
      $types = [$types];
    }

    /* @param BaseFragment[] $fragments */
    $closure = function(array $fragments, $current_level = 1) use ($types, $level, &$closure) {
      $fragments_of_type = [];
      $next_level = $current_level + 1;
      foreach ($fragments as $fragment) {
        if ($fragment instanceof Fragment) {
          if (in_array($fragment->getType(), $types)) {
            $fragments_of_type[] = $fragment;
          }
        }

        if ($level === 0 || $next_level < $level) {
          $children_of_type = $closure($fragment->getFragments(), $next_level);
          if (!empty($children_of_type)) {
            $fragments_of_type = array_merge($fragments_of_type, $children_of_type);
          }
        }
      }

      return $fragments_of_type;
    };

    return $closure($this->fragments);
  }

  public function getCitations() {
    return $this->citations;
  }

  public function getCiteAs() {
    $cite_as = 'eLife ';
    $cite_as .= ($this->getPubDate()) ? $this->getPubDate()->format('Y') : date('Y');
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
      elseif ($contributor instanceof OnBehalfOfContributor) {
        if ($on_behalf_of = $contributor->getOnBehalfOf()) {
          $name['on_behalf_of'] = $on_behalf_of;
        }
      }
      if (!empty($name)) {
        $authors[] = implode(' ', $name);
      }
    }

    return $authors;
  }
}
