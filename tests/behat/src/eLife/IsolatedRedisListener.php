<?php

namespace eLife\Behat;

use Behat\Behat\EventDispatcher\Event\ExampleTested;
use Behat\Behat\EventDispatcher\Event\ScenarioTested;
use eLife\IsolatedDrupalBehatExtension\Event\WritingSiteSettingsFile;
use eLife\IsolatedDrupalBehatExtension\RandomString\RandomStringGenerator;
use Symfony\Component\EventDispatcher\EventSubscriberInterface as EventSubscriber;
use Symfony\Component\Process\ProcessBuilder;

final class IsolatedRedisListener implements EventSubscriber {
  /**
   * @var RandomStringGenerator
   */
  private $generator;

  public static function getSubscribedEvents()
  {
    return [
      WritingSiteSettingsFile::NAME => 'onWritingSiteSettingsFile',
      ScenarioTested::BEFORE => 'onBeforeScenarioTested',
      ExampleTested::BEFORE => 'onBeforeScenarioTested',
    ];
  }

  /**
   * @param RandomStringGenerator $generator
   */
  public function __construct(RandomStringGenerator $generator)
  {
    $this->generator = $generator;
  }

  /**
   * @param WritingSiteSettingsFile $event
   */
  public function onWritingSiteSettingsFile(WritingSiteSettingsFile $event)
  {
    $event->addSettings('$conf["cache_prefix"] = "' . $this->generator->generate() . '_";');

    $event->addSettings('unset($conf["path_inc"]);'); // TODO Don't know why this is needed
  }

  public function onBeforeScenarioTested()
  {
    ProcessBuilder::create()
      ->add('redis-cli')
      ->add('flushall')
      ->getProcess()
      ->mustRun();
  }
}
