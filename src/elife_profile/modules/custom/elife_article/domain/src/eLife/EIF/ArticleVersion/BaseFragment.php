<?php

namespace eLife\EIF\ArticleVersion;

use JMS\Serializer\Annotation as Serializer;

abstract class BaseFragment {
  /**
   * @var string|null
   *
   * @Serializer\Type("string")
   */
  protected $title;

  /**
   * @var string
   *
   * @Serializer\Type("string")
   */
  protected $doi;

  /**
   * @var string
   *
   * @Serializer\Type("string")
   */
  protected $path;

  /**
   * @var BaseFragment[]
   *
   * @Serializer\Type("array<eLife\EIF\ArticleVersion\BaseFragment>")
   */
  protected $fragments = [];

  /**
   * @param string|null $title
   * @param string $doi
   * @param string $path
   * @param BaseFragment[] $fragments
   */
  public function __construct(
    $title,
    $doi,
    $path,
    array $fragments
  ) {
    $this->title = $title;
    $this->doi = $doi;
    $this->path = $path;
    $this->fragments = $fragments;
  }

  final public function getTitle() {
    return $this->title;
  }

  /**
   * @param bool $url
   * @return string
   */
  final public function getDoi($url = FALSE) {
    return ($url) ? 'http://dx.doi.org/' . $this->doi : $this->doi;
  }

  final public function getPath() {
    return $this->path;
  }

  final public function getFragments() {
    return $this->fragments;
  }
}
