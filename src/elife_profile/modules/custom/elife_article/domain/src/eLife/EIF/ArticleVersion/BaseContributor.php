<?php

namespace eLife\EIF\ArticleVersion;

use JMS\Serializer\Annotation as Serializer;

abstract class BaseContributor {
  /**
   * @var string
   *
   * @Serializer\Type("string")
   */
  private $type;

  /**
   * @param string $type
   */
  public function __construct(
    $type
  ) {
    $this->type = (string) $type;
  }

  final public function getType() {
    return $this->type;
  }

  abstract function getName();

  abstract function getShortName();
}
