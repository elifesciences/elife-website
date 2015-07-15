<?php

namespace eLife\EIF\ArticleVersion\Referenced;

use JMS\Serializer\Annotation as Serializer;

final class FootNote {

  /**
   * @var string|null
   *
   * @Serializer\Type("string")
   */
  private $type;

  /**
   * @var string
   *
   * @Serializer\Type("string")
   */
  private $value;

  /**
   * @param string $type
   * @param string $value
   */
  public function __construct(
    $type,
    $value
  ) {
    $this->type = $type;
    $this->value = $value;
  }

  public function getType() {
    return $this->type;
  }

  public function getValue() {
    return $this->value;
  }
}