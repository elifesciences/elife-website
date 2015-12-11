<?php

namespace eLife\Behat;

use eLife\IsolatedDrupalBehatExtension\Event\WritingSiteSettingsFile;
use Symfony\Component\EventDispatcher\EventSubscriberInterface as EventSubscriber;

final class EnvironmentListener implements EventSubscriber {
  public static function getSubscribedEvents() {
    return [
      WritingSiteSettingsFile::NAME => 'onWritingSiteSettingsFile',
    ];
  }

  /**
   * @param WritingSiteSettingsFile $event
   */
  public function onWritingSiteSettingsFile(WritingSiteSettingsFile $event) {
    $event->addSettings('$conf["elife_environment"] = ELIFE_ENVIRONMENT_TESTING;');
  }
}
