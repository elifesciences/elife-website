<?php

namespace eLife\Behat;

use eLife\IsolatedDrupalBehatExtension\Event\WritingSiteSettingsFile;
use Symfony\Component\EventDispatcher\EventSubscriberInterface as EventSubscriber;

final class DisableCacheListener implements EventSubscriber {
  public static function getSubscribedEvents() {
    return [
      WritingSiteSettingsFile::NAME => 'onWritingSiteSettingsFile',
    ];
  }

  /**
   * @param WritingSiteSettingsFile $event
   */
  public function onWritingSiteSettingsFile(WritingSiteSettingsFile $event) {
    $event->addSettings('if (!class_exists("DrupalFakeCache")) { $conf["cache_backends"][] = "includes/cache-install.inc"; }');
    $event->addSettings('$conf["cache_class_cache_views_data"] = "DrupalFakeCache";');
    $event->addSettings('$conf["cache_class_cache_panels"] = "DrupalFakeCache";');
  }
}
