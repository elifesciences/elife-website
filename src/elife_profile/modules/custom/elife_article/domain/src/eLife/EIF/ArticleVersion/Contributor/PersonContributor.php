<?php

namespace eLife\EIF\ArticleVersion\Contributor;

use eLife\EIF\ArticleVersion\Affiliation;
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
   * @var string|null
   *
   * @Serializer\Type("string")
   */
  protected $email;

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
   * @param string $surname
   * @param string $given_names
   * @param string|null $suffix
   * @param string|null $email
   * @param Affiliation[] $affiliations
   */
  public function __construct(
    $type,
    $corresp,
    $id,
    $group_author_key,
    array $references,
    $surname,
    $given_names,
    $suffix,
    $email,
    array $affiliations
  ) {
    parent::__construct($type, $corresp, $id, $group_author_key,
      $references);
    $this->surname = (string) $surname;
    $this->given_names = (string) $given_names;
    $this->suffix = $suffix;
    $this->email = $email;
    $this->affiliations = $affiliations;
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

  public function getEmail() {
    return $this->email;
  }

  public function getAffiliations() {
    return $this->affiliations;
  }

  final public function getName() {
    return implode(' ', $this->getNameParts());
  }

  final public function getShortName() {
    $parts = $this->getNameParts();

    if (!empty($parts['given-names'])) {
      preg_match_all("/[A-Z]/", ucwords(strtolower($parts['given-names'])), $parts['given-names']);
      $parts['given-names'] = implode('', $parts['given-names'][0]);
    }

    return implode(' ', $parts);
  }

  final public function getNameParts() {
    $parts = [];
    if ($given_names = $this->getGivenNames()) {
      $parts['given-names'] = $given_names;
    }
    if ($surname = $this->getSurname()) {
      $parts['surname'] = $surname;
    }
    if ($suffix = $this->getSuffix()) {
      $parts['suffix'] = $suffix;
    }

    return $parts;
  }
}
