<?php

namespace eLife\EIF\ArticleVersion\Contributor;

use eLife\EIF\ArticleVersion\Affiliation;
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
   * @var Affiliation[]
   *
   * @Serializer\Type("array<eLife\EIF\ArticleVersion\Affiliation>")
   */
  private $affiliations = array();

  /**
   * @param string $type
   * @param boolean $corresp
   * @param string|null $id
   * @param string $group_author_key
   * @param array $references
   * @param string $collab
   * @param Affiliation[] $affiliations
   */
  public function __construct(
    $type,
    $corresp,
    $id,
    $group_author_key,
    array $references,
    $collab,
    array $affiliations
  ) {
    parent::__construct($type, $corresp, $id, $group_author_key,
      $references);
    $this->collab = $collab;
    $this->affiliations = $affiliations;
  }

  public function getCollab() {
    return $this->collab;
  }

  public function getName() {
    return $this->getCollab();
  }

  public function getShortName() {
    return $this->getName();
  }

  public function getAffiliations() {
    return $this->affiliations;
  }
}
