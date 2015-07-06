<?php

namespace eLife\EIF\ArticleVersion;

use JMS\Serializer\Annotation as Serializer;

final class Fragment extends BaseFragment {
  /**
   * @var string
   *
   * @Serializer\Type("string")
   */
  private $type;

  /**
   * @param string $type
   * @param string|null $title
   * @param string $doi
   * @param string $path
   * @param BaseFragment[] $fragments
   */
  public function __construct(
    $type,
    $title,
    $doi,
    $path,
    array $fragments
  ) {
    $this->type = $type;
    parent::__construct($title, $doi, $path, $fragments);
  }

  public function getType() {
    return $this->type;
  }
}
