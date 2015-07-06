<?php

namespace eLife\EIF\ArticleVersion;

use JMS\Serializer\Annotation as Serializer;

final class RelatedArticle {
  /**
   * @var string
   *
   * @Serializer\Type("string")
   */
  private $type;

  /**
   * @var string
   *
   * @Serializer\Type("string")
   */
  private $href;

  /**
   * @param string $type
   * @param string $href
   */
  public function __construct($type, $href) {
    $this->type = (string) $type;
    $this->href = (string) $href;
  }

  public function getType() {
    return $this->type;
  }

  public function getHref() {
    return $this->href;
  }
}
