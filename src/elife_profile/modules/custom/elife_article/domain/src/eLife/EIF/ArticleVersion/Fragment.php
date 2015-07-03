<?php

namespace eLife\EIF\ArticleVersion;

use JMS\Serializer\Annotation as Serializer;

final class Fragment {
  /**
   * @var string
   *
   * @Serializer\Type("string")
   */
  private $type;

  /**
   * @var string|null
   *
   * @Serializer\Type("string")
   */
  private $title;

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
  private $path;

  /**
   * @var Fragment[]
   *
   * @Serializer\Type("array<eLife\EIF\ArticleVersion\Fragment>")
   */
  private $fragments = [];

  /**
   * @var Contributor[]
   *
   * @Serializer\Type("array<eLife\EIF\ArticleVersion\Contributor>")
   */
  private $contributors = [];

  /**
   * @param string $type
   * @param string|null $title
   * @param string $doi
   * @param string $path
   * @param Fragment[] $fragments
   * @param Contributor[] $contributors
   */
  public function __construct(
    $type,
    $title,
    $doi,
    $path,
    array $fragments,
    array $contributors
  ) {
    $this->type = $type;
    $this->title = $title;
    $this->doi = $doi;
    $this->path = $path;
    $this->fragments = $fragments;
    $this->contributors = $contributors;
  }

  public function getType() {
    return $this->type;
  }

  public function getTitle() {
    if (empty($this->title) && 'abstract' === $this->getType()) {
      return 'Abstract';
    }

    return $this->title;
  }

  public function getDoi() {
    return $this->doi;
  }

  public function getPath() {
    return $this->path;
  }

  public function getFragments() {
    return $this->fragments;
  }

  public function getContributors() {
    return $this->contributors;
  }
}
