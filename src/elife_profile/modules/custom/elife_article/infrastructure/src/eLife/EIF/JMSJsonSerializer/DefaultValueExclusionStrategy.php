<?php

namespace eLife\EIF\JMSJsonSerializer;

use JMS\Serializer\Context;
use JMS\Serializer\Exclusion\ExclusionStrategyInterface as ExclusionStrategy;
use JMS\Serializer\Metadata\ClassMetadata;
use JMS\Serializer\Metadata\PropertyMetadata;
use JMS\Serializer\SerializationContext;

final class DefaultValueExclusionStrategy implements ExclusionStrategy {
  public function shouldSkipClass(ClassMetadata $class, Context $context) {
    if (FALSE === $context instanceof SerializationContext) {
      return FALSE;
    }

    $default_properties = $class->reflection->getDefaultProperties();

    if (!count($default_properties)) {
      return FALSE;
    }

    $properties = [];
    foreach ($class->reflection->getProperties() as $property) {
      $property->setAccessible(TRUE);
      $properties[$property->name] = $property->getValue($context->getObject());
    }

    return $properties === $default_properties;
  }

  public function shouldSkipProperty(PropertyMetadata $property, Context $context) {
    if (FALSE === $context instanceof SerializationContext) {
      return FALSE;
    }

    $default_properties = $property->reflection->getDeclaringClass()
      ->getDefaultProperties();

    if (
      isset($default_properties[$property->name])
      &&
      $default_properties[$property->name] === $property->reflection->getValue($context->getObject())
    ) {
      return TRUE;
    }

    return FALSE;
  }
}
