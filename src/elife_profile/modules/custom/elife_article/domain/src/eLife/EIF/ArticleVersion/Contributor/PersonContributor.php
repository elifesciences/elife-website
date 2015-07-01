<?php

namespace eLife\EIF\ArticleVersion\Contributor;

use eLife\EIF\ArticleVersion\Affiliation;
use eLife\EIF\ArticleVersion\Contributor;
use JMS\Serializer\Annotation as Serializer;

final class PersonContributor extends Contributor {
  /**
   * @var string
   *
   * @Serializer\Type("string")
   * @Serializer\SerializedName("equal-contrib")
   */
  private $equal_contrib = 'no';

  /**
   * @var string
   *
   * @Serializer\Type("string")
   */
  private $deceased = 'no';

  /**
   * @var string
   *
   * @Serializer\Type("string")
   */
  private $surname;

  /**
   * @var string
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
  private $orcid;

  /**
   * @var string|null
   *
   * @Serializer\Type("string")
   */
  private $role;

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
   * @param boolean $equal_contrib
   * @param boolean $deceased
   * @param string $surname
   * @param string $given_names
   * @param string|null $suffix
   * @param string|null $orcid
   * @param string|null $role
   * @param Affiliation[] $affiliations
   */
  public function __construct(
    $type,
    $corresp,
    $id,
    $group_author_key,
    array $references,
    $equal_contrib,
    $deceased,
    $surname,
    $given_names,
    $suffix,
    $orcid,
    $role,
    array $affiliations
  ) {
    parent::__construct($type, $corresp, $id, $group_author_key,
      $references);
    $this->equal_contrib = ($equal_contrib ? 'yes' : 'no');
    $this->deceased = ($deceased ? 'yes' : 'no');
    $this->surname = (string) $surname;
    $this->given_names = (string) $given_names;
    $this->suffix = $suffix;
    $this->orcid = $orcid;
    $this->role = $role;
    $this->affiliations = $affiliations;
  }

  public function isEqualContrib() {
    return 'yes' === $this->equal_contrib;
  }

  public function isDeceased() {
    return 'yes' === $this->deceased;
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

  public function getOrcId() {
    return $this->orcid;
  }

  public function getRole() {
    return $this->role;
  }

  public function getAffiliations() {
    return $this->affiliations;
  }
}
