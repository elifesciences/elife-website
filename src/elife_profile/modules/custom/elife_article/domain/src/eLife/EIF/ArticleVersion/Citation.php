<?php

namespace eLife\EIF\ArticleVersion;

use eLife\EIF\ArticleVersion\Citation\Author;
use JMS\Serializer\Annotation as Serializer;

final class Citation {
  /**
   * @var Author[]
   *
   * @Serializer\Type("array<eLife\EIF\ArticleVersion\Citation\Author>")
   */
  private $authors = [];

  /**
   * @var string|null
   *
   * @Serializer\Type("string")
   */
  private $year;

  /**
   * @var string|null
   *
   * @Serializer\Type("string")
   */
  private $title;

  /**
   * @var string|null
   *
   * @Serializer\Type("string")
   */
  private $source;

  /**
   * @var string|null
   *
   * @Serializer\Type("string")
   */
  private $doi;

  /**
   * @var string|null
   *
   * @Serializer\Type("string")
   */
  private $comment;

  /**
   * @param Author[] $authors
   * @param string|null $year
   * @param string|null $title
   * @param string|null $source
   * @param string|null $doi
   * @param string|null $comment
   */
  public function __construct(
    array $authors,
    $year,
    $title,
    $source,
    $doi,
    $comment
  ) {
    $this->authors = $authors;
    $this->year = $year;
    $this->title = $title;
    $this->source = $source;
    $this->doi = $doi;
    $this->comment = $comment;
  }

  public function getAuthors() {
    return $this->authors;
  }

  public function getYear() {
    return $this->year;
  }

  public function getTitle() {
    return $this->title;
  }

  public function getSource() {
    return $this->source;
  }

  public function getDoi() {
    return $this->doi;
  }

  public function getComment() {
    return $this->comment;
  }
}
