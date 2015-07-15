<?php

namespace eLife\EIF\JMSJsonSerializer;

use eLife\EIF\ArticleVersion\Contributor;
use eLife\EIF\ArticleVersion\Contributor\PersonContributor\BylineContributor;
use eLife\EIF\ArticleVersion\Contributor\CollabContributor;
use eLife\EIF\ArticleVersion\Contributor\PersonContributor\NonBylineContributor;
use JMS\Serializer\Handler\HandlerRegistry;
use JMS\Serializer\Handler\SubscribingHandlerInterface as SubscribingHandler;
use JMS\Serializer\GraphNavigator;
use JMS\Serializer\Context;
use JMS\Serializer\JsonDeserializationVisitor;
use JMS\Serializer\JsonSerializationVisitor;

final class ContributorHandler implements SubscribingHandler {
  public static function getSubscribingMethods() {
    return [
      [
        'direction' => GraphNavigator::DIRECTION_DESERIALIZATION,
        'format' => 'json',
        'type' => Contributor::class,
        'method' => 'deserializeContributorFromJson',
      ],
    ];
  }

  public function deserializeContributorFromJson(
    JsonDeserializationVisitor $visitor,
    $data,
    array $type,
    Context $context
  ) {
    if (isset($data['collab'])) {
      $type['name'] = CollabContributor::class;
    }
    elseif (isset($data['type']) && preg_match('/\s+non\-byline\s+/', ' ' . $data['type'] . ' ')) {
      $type['name'] = NonBylineContributor::class;
    }
    else {
      $type['name'] = BylineContributor::class;
    }

    return $context->getNavigator()->accept($data, $type, $context);
  }
}
