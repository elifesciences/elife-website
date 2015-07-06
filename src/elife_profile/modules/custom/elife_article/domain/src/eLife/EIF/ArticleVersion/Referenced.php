<?php

namespace eLife\EIF\ArticleVersion;

use eLife\EIF\ArticleVersion\Referenced\Funding;
use eLife\EIF\ArticleVersion\Referenced\RelatedObject;
use JMS\Serializer\Annotation as Serializer;

final class Referenced {
  /**
   * @var string[]
   *
   * @Serializer\Type("array<string,string>")
   * @Serializer\SerializedName("equal-contrib")
   */
  private $equal_contrib = [];

  /**
   * @var string[]
   *
   * @Serializer\Type("array<string,string>")
   */
  private $email = [];

  /**
   * @var Funding[]
   *
   * @Serializer\Type("array<string,eLife\EIF\ArticleVersion\Referenced\Funding>")
   */
  private $funding = [];

  /**
   * @var string[]
   *
   * @Serializer\Type("array<string,string>")
   * @Serializer\SerializedName("competing-interest")
   */
  private $competing_interest = [];

  /**
   * @var string[]
   *
   * @Serializer\Type("array<string,string>")
   */
  private $contribution = [];

  /**
   * @var string[]
   *
   * @Serializer\Type("array<string,string>")
   * @Serializer\SerializedName("present-address")
   */
  private $present_address = [];

  /**
   * @var Affiliation[]
   *
   * @Serializer\Type("array<string,eLife\EIF\ArticleVersion\Affiliation>")
   */
  private $affiliation = [];

  /**
   * @var RelatedObject[]
   *
   * @Serializer\Type("array<string,eLife\EIF\ArticleVersion\Referenced\RelatedObject>")
   * @Serializer\SerializedName("related-object")
   */
  private $related_object = []; // TODO

  /**
   * @param string[] $equal_contrib
   * @param string[] $email
   * @param Funding[] $funding
   * @param string[] $competing_interest
   * @param string[] $contribution
   * @param string[] $present_address
   * @param Affiliation[] $affiliation
   * @param RelatedObject[] $related_object
   */
  public function __construct(
    array $equal_contrib,
    array $email,
    array $funding,
    array $competing_interest,
    array $contribution,
    array $present_address,
    array $affiliation,
    array $related_object
  ) {
    $this->equal_contrib = $equal_contrib;
    $this->email = $email;
    $this->funding = $funding;
    $this->competing_interest = $competing_interest;
    $this->contribution = $contribution;
    $this->present_address = $present_address;
    $this->affiliation = $affiliation;
    $this->related_object = $related_object;
  }

  public function getEqualContrib() {
    return $this->equal_contrib;
  }

  public function getEmail() {
    return $this->email;
  }

  public function getFunding() {
    return $this->funding;
  }

  public function getCompetingInterest() {
    return $this->competing_interest;
  }

  public function getContribution() {
    return $this->contribution;
  }

  public function getPresentAddress() {
    return $this->present_address;
  }

  public function getAffiliation() {
    return $this->affiliation;
  }

  public function getRelatedObject() {
    return $this->related_object;
  }
}
