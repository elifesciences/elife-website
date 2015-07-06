<?php

namespace eLife\EIF\ArticleVersion\Citation;

use JMS\Serializer\Annotation as Serializer;

final class Author {
  /**
   * @var string|null
   *
   * @Serializer\Type("string")
   * @Serializer\SerializedName("group-type")
   */
  private $group_type;

  /**
   * @var string|null
   *
   * @Serializer\Type("string")
   */
  private $surname;

  /**
   * @var string|null
   *
   * @Serializer\Type("string")
   * @Serializer\SerializedName("given-names")
   */
  private $given_names;

  /**
   * @var string|null
   *
   * @Serializer\Type("string")
   */
  private $suffix;

  /**
   * @var string|null
   *
   * @Serializer\Type("string")
   */
  private $collab;

  /**
   * @param string|null $group_type
   * @param string|null $surname
   * @param string|null $given_names
   * @param string|null $suffix
   * @param string|null $collab
   */
  public function __construct(
    $group_type,
    $surname,
    $given_names,
    $suffix,
    $collab
  ) {
    $this->group_type = $group_type;
    $this->surname = $surname;
    $this->given_names = $given_names;
    $this->suffix = $suffix;
    $this->collab = $collab;
  }

  public function getGroupType() {
    return $this->group_type;
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

  public function getCollab() {
    return $this->collab;
  }
}
