<?php

namespace eLife\EIF\ArticleVersion\Contributor;

use eLife\EIF\ArticleVersion\BaseContributor;
use JMS\Serializer\Annotation as Serializer;

final class OnBehalfOfContributor extends BaseContributor {
  /**
   * @var string
   *
   * @Serializer\Type("string")
   * @Serializer\SerializedName("on-behalf-of")
   */
  private $on_behalf_of;

  /**
   * @param string $type
   * @param string $on_behalf_of
   */
  public function __construct(
    $type,
    $on_behalf_of
  ) {
    parent::__construct($type);
    $this->on_behalf_of = $on_behalf_of;
  }

  public function getOnBehalfOf() {
    return $this->on_behalf_of;
  }

  public function getName() {
    return $this->getOnBehalfOf();
  }

  public function getShortName() {
    return $this->getName();
  }
}
