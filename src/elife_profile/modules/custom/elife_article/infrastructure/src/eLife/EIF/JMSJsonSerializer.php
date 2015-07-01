<?php

namespace eLife\EIF;

use JMS\Serializer\SerializerInterface as Serializer;

final class JMSJsonSerializer implements JsonSerializer {
  /**
   * @var Serializer
   */
  private $serializer;

  /**
   * @param Serializer $serializer
   */
  public function __construct(Serializer $serializer) {
    $this->serializer = $serializer;
  }

  public function serialize(ArticleVersion $articleVersion) {
    return $this->serializer->serialize($articleVersion, 'json');
  }

  public function deserialize($json) {
    return $this->serializer->deserialize($json, ArticleVersion::class, 'json');
  }
}
