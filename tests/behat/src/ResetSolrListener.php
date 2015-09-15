<?php

namespace eLife\Behat;

use Behat\Behat\EventDispatcher\Event\BeforeOutlineTested;
use Behat\Behat\EventDispatcher\Event\BeforeScenarioTested;
use Symfony\Component\EventDispatcher\EventSubscriberInterface as EventSubscriber;

final class ResetSolrListener implements EventSubscriber {
  public static function getSubscribedEvents() {
    return [
      BeforeScenarioTested::BEFORE => 'onBeforeTested',
      BeforeOutlineTested::BEFORE => 'onBeforeTested',
    ];
  }

  public function onBeforeTested() {
    $solr = clone search_api_server_load('elife_solr');

    unset($solr->options['site_hash']); // We need to remove everything.

    $solr->deleteItems();
    $solr->commit();
  }
}
