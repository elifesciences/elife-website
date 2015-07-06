<?php

namespace eLife\EIF\JMSJsonSerializer;

use eLife\EIF\ArticleVersion\SubArticle;
use JMS\Serializer\EventDispatcher\EventSubscriberInterface as EventSubscriber;
use JMS\Serializer\EventDispatcher\ObjectEvent;

final class SubArticleSubscriber implements EventSubscriber {
  public static function getSubscribedEvents() {
    return [
      [
        'event' => 'serializer.post_serialize',
        'method' => 'onPostSerialize'
      ]
    ];
  }

  public function onPostSerialize(ObjectEvent $event) {
    if (SubArticle::class === $event->getType()['name']) {
      $event->getVisitor()->addData('type', 'sub-article');
    }
  }
}
