<?php

namespace eLife\EIF;

use JMS\Serializer\DeserializationContext;
use JMS\Serializer\SerializationContext;
use JMS\Serializer\SerializerInterface as Serializer;

final class JMSJsonSerializer implements JsonSerializer {
  /**
   * @var Serializer
   */
  private $serializer;

  /**
   * @var SerializationContext
   */
  private $serializationContext;

  /**
   * @var DeserializationContext
   */
  private $deserializationContext;

  /**
   * @param Serializer $serializer
   * @param SerializationContext $serializationContext
   * @param DeserializationContext $deserializationContext
   */
  public function __construct(Serializer $serializer, SerializationContext $serializationContext, DeserializationContext $deserializationContext) {
    $this->serializer = $serializer;
    $this->serializationContext = $serializationContext;
    $this->deserializationContext = $deserializationContext;
  }

  public function serialize(ArticleVersion $articleVersion) {
    return $this->serializer->serialize($articleVersion, 'json', $this->serializationContext);
  }

  public function deserialize($json) {
    return $this->serializer->deserialize($json, ArticleVersion::class, 'json', $this->deserializationContext);
  }
}
