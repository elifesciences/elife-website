<?php

namespace eLife\EIF\ArticleVersion\Contributor;

use eLife\EIF\ArticleVersion\Contributor;
use JMS\Serializer\Annotation as Serializer;

final class CollabContributor extends Contributor {
  /**
   * @var string
   *
   * @Serializer\Type("string")
   */
  private $collab;

  /**
   * @param string $type
   * @param boolean $corresp
   * @param string|null $id
   * @param string $group_author_key
   * @param array $references
   * @param string $collab
   */
  public function __construct(
    $type,
    $corresp,
    $id,
    $group_author_key,
    array $references,
    $collab
  ) {
    parent::__construct($type, $corresp, $id, $group_author_key,
      $references);
    $this->collab = $collab;
  }

  public function getCollab() {
    return $this->collab;
  }
}
