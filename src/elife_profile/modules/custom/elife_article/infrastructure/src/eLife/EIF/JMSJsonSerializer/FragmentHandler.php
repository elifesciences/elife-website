<?php

namespace eLife\EIF\JMSJsonSerializer;

use eLife\EIF\ArticleVersion\BaseFragment;
use eLife\EIF\ArticleVersion\Contributor;
use eLife\EIF\ArticleVersion\Fragment;
use eLife\EIF\ArticleVersion\SubArticle;
use JMS\Serializer\Handler\SubscribingHandlerInterface as SubscribingHandler;
use JMS\Serializer\GraphNavigator;
use JMS\Serializer\Context;
use JMS\Serializer\JsonDeserializationVisitor;

final class FragmentHandler implements SubscribingHandler {
  public static function getSubscribingMethods() {
    return [
      [
        'direction' => GraphNavigator::DIRECTION_DESERIALIZATION,
        'format' => 'json',
        'type' => BaseFragment::class,
        'method' => 'deserializeFragmentFromJson',
      ],
    ];
  }

  public function deserializeFragmentFromJson(
    JsonDeserializationVisitor $visitor,
    $data,
    array $type,
    Context $context
  ) {
    if ('sub-article' === $data['type']) {
      $type['name'] = SubArticle::class;
    }
    else {
      $type['name'] = Fragment::class;
      if (empty($data['title']) && 'abstract' === $data['type']) {
        $data['title'] = 'Abstract';
      }
    }

    return $context->getNavigator()->accept($data, $type, $context);
  }
}
