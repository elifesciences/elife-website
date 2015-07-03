<?php

namespace eLife\EIF\ArticleVersion;

use JMS\Serializer\Annotation as Serializer;

final class SubArticle extends BaseFragment {
  /**
   * @var Contributor[]
   *
   * @Serializer\Type("array<eLife\EIF\ArticleVersion\Contributor>")
   */
  private $contributors = [];

  /**
   * @param string|null $title
   * @param string $doi
   * @param string $path
   * @param BaseFragment[] $fragments
   * @param Contributor[] $contributors
   */
  public function __construct(
    $title,
    $doi,
    $path,
    array $fragments,
    array $contributors
  ) {
    parent::__construct($title, $doi, $path, $fragments);
    $this->contributors = $contributors;
  }

  public function getContributors() {
    return $this->contributors;
  }
}
