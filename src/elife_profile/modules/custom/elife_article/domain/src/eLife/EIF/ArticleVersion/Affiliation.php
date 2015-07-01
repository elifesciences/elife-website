<?php

namespace eLife\EIF\ArticleVersion;

use JMS\Serializer\Annotation as Serializer;

final class Affiliation {
  /**
   * @var string|null
   *
   * @Serializer\Type("string")
   */
  private $dept;

  /**
   * @var string|null
   *
   * @Serializer\Type("string")
   */
  private $institution;

  /**
   * @var string|null
   *
   * @Serializer\Type("string")
   */
  private $city;

  /**
   * @var string|null
   *
   * @Serializer\Type("string")
   */
  private $country;

  /**
   * @param string|null $dept
   * @param string|null $institution
   * @param string|null $city
   * @param string|null $country
   */
  public function __construct($dept, $institution, $city, $country) {
    $this->dept = $dept;
    $this->institution = $institution;
    $this->city = $city;
    $this->country = $country;
  }

  public function getDept() {
    return $this->dept;
  }

  public function getInstitution() {
    return $this->institution;
  }

  public function getCity() {
    return $this->city;
  }

  public function getCountry() {
    return $this->country;
  }
}
