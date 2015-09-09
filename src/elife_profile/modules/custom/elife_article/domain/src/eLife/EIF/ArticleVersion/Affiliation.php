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
   * @var string|null
   *
   * @Serializer\Type("string")
   */
  private $email;

  /**
   * @param string|null $dept
   * @param string|null $institution
   * @param string|null $city
   * @param string|null $country
   * @param string|null $email
   */
  public function __construct($dept, $institution, $city, $country, $email) {
    $this->dept = $dept;
    $this->institution = $institution;
    $this->city = $city;
    $this->country = $country;
    $this->email = $email;
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

  public function getEmail() {
    return $this->email;
  }
}
