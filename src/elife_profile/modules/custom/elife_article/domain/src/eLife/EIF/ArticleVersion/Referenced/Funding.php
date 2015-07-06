<?php

namespace eLife\EIF\ArticleVersion\Referenced;

use JMS\Serializer\Annotation as Serializer;

final class Funding {
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
   * @Serializer\SerializedName("id-type")
   */
  private $id_type;

  /**
   * @var string
   *
   * @Serializer\Type("string")
   */
  private $institution;

  /**
   * @var string|null
   *
   * @Serializer\Type("string")
   * @Serializer\SerializedName("institution-type")
   */
  private $institution_type;

  /**
   * @var string|null
   *
   * @Serializer\Type("string")
   * @Serializer\SerializedName("award-id")
   */
  private $award_id;

  /**
   * @param string|null $id
   * @param string|null $id_type
   * @param string $institution
   * @param string $institution_type
   * @param string|null $award_id
   */
  public function __construct(
    $id,
    $id_type,
    $institution,
    $institution_type,
    $award_id
  ) {
    $this->id = $id;
    $this->id_type = $id_type;
    $this->institution = $institution;
    $this->institution_type = $institution_type;
    $this->award_id = $award_id;
  }

  public function getId() {
    return $this->id;
  }

  public function getIdType() {
    return $this->id_type;
  }

  public function getInstitution() {
    return $this->institution;
  }

  public function getInstitutionType() {
    return $this->institution_type;
  }

  public function getAwardId() {
    return $this->award_id;
  }
}