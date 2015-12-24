<?php

namespace eLife\EIF\ArticleVersion;

use JMS\Serializer\Annotation as Serializer;

abstract class Contributor extends BaseContributor {

  /**
   * @var bool
   *
   * @Serializer\Type("boolean")
   */
  private $corresp = FALSE;

  /**
   * @var string|null
   *
   * @Serializer\Type("string")
   */
  private $id;

  /**
   * @var string|null
   *
   * @Serializer\Type("string")
   * @Serializer\SerializedName("group-author-key")
   */
  private $group_author_key;

  /**
   * @var array
   *
   * @Serializer\Type("array<string,array<string>>")
   */
  private $references = array();

  /**
   * @param string $type
   * @param boolean $corresp
   * @param string|null $id
   * @param string $group_author_key
   * @param array $references
   */
  public function __construct(
    $type,
    $corresp,
    $id,
    $group_author_key,
    array $references
  ) {
    parent::__construct($type);
    $this->corresp = (bool) $corresp;
    $this->id = $id;
    $this->group_author_key = $group_author_key;
    $this->references = $references;
  }

  final public function isCorresp() {
    return $this->corresp;
  }

  final public function getId() {
    return $this->id;
  }

  final public function getGroupAuthorKey() {
    return $this->group_author_key;
  }

  final public function getReferences() {
    return $this->references;
  }
}
