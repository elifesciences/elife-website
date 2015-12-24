<?php

namespace eLife\EIF\ArticleVersion\Contributor\PersonContributor;

use eLife\EIF\ArticleVersion\Affiliation;
use eLife\EIF\ArticleVersion\Contributor;
use eLife\EIF\ArticleVersion\Contributor\PersonContributor;
use JMS\Serializer\Annotation as Serializer;

final class BylineContributor extends PersonContributor {
  /**
   * @var bool
   *
   * @Serializer\Type("boolean")
   * @Serializer\SerializedName("equal-contrib")
   */
  private $equal_contrib = FALSE;

  /**
   * @var bool
   *
   * @Serializer\Type("boolean")
   */
  private $deceased = FALSE;

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
   * @param string|null $email
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
    $email,
    $orcid,
    $role,
    array $affiliations
  ) {
    parent::__construct($type, $corresp, $id, $group_author_key, $references,
      (string) $surname, (string) $given_names, $suffix, $email, $affiliations);
    $this->equal_contrib = (bool) $equal_contrib;
    $this->deceased = (bool) $deceased;
    $this->orcid = $orcid;
    $this->role = $role;
  }

  public function isEqualContrib() {
    return $this->equal_contrib;
  }

  public function isDeceased() {
    return $this->deceased;
  }

  public function getOrcId() {
    return $this->orcid;
  }

  public function getRole() {
    return $this->role;
  }
}
