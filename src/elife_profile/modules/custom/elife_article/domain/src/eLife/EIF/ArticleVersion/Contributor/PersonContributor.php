<?php

namespace eLife\EIF\ArticleVersion\Contributor;

use eLife\EIF\ArticleVersion\Contributor;
use JMS\Serializer\Annotation as Serializer;

abstract class PersonContributor extends Contributor {

  /**
   * @var string
   *
   * @Serializer\Type("string")
   */
  protected $surname;

  /**
   * @var string
   *
   * @Serializer\Type("string")
   * @Serializer\SerializedName("given-names")
   */
  protected $given_names;

  /**
   * @var string|null
   *
   * @Serializer\Type("string")
   */
  protected $suffix;

  /**
   * @param string $type
   * @param boolean $corresp
   * @param string|null $id
   * @param string $group_author_key
   * @param array $references
   * @param string $surname
   * @param string $given_names
   * @param string|null $suffix
   */
  public function __construct(
    $type,
    $corresp,
    $id,
    $group_author_key,
    array $references,
    $surname,
    $given_names,
    $suffix
  ) {
    parent::__construct($type, $corresp, $id, $group_author_key,
      $references);
    $this->surname = (string) $surname;
    $this->given_names = (string) $given_names;
    $this->suffix = $suffix;
  }

  public function getSurname() {
    return $this->surname;
  }

  public function getGivenNames() {
    return $this->given_names;
  }

  public function getSuffix() {
    return $this->suffix;
  }
}
