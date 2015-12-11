<?php

namespace eLife\Behat;

use Behat\Behat\EventDispatcher\Event\ExampleTested;
use Behat\Behat\EventDispatcher\Event\ScenarioTested;
use eLife\IsolatedDrupalBehatExtension\Event\WritingSiteSettingsFile;
use eLife\IsolatedDrupalBehatExtension\RandomString\RandomStringGenerator;
use GuzzleHttp\ClientInterface as HttpClient;
use GuzzleHttp\Exception\RequestException;
use GuzzleHttp\Url;
use RuntimeException;
use Symfony\Component\EventDispatcher\EventSubscriberInterface as EventSubscriber;

final class IsolatedSolrListener implements EventSubscriber {
  /**
   * @var HttpClient
   */
  private $httpClient;

  /**
   * @var Url
   */
  private $baseUrl;

  /**
   * @var RandomStringGenerator
   */
  private $stringGenerator;

  /**
   * This is reset before each scenario.
   *
   * @var string
   */
  private $siteHash;

  public static function getSubscribedEvents() {
    return [
      ScenarioTested::BEFORE => ['onBeforeTested', 256],
      ExampleTested::BEFORE => ['onBeforeTested', 256],
      ScenarioTested::AFTER => 'onAfterTested',
      ExampleTested::AFTER => 'onAfterTested',
      WritingSiteSettingsFile::NAME => 'onWritingSiteSettingsFile',
    ];
  }

  /**
   * @param HttpClient $httpClient
   * @param RandomStringGenerator $stringGenerator
   */
  public function __construct(HttpClient $httpClient, RandomStringGenerator $stringGenerator) {
    $this->httpClient = $httpClient;
    $this->baseUrl = Url::fromString($this->httpClient->getBaseUrl());
    $this->baseUrl->setPath(rtrim($this->baseUrl->getPath(), '/'));
    $this->stringGenerator = $stringGenerator;

    register_shutdown_function(function () {
      $this->onAfterTested(); // In case of a fatal error.
    });
  }

  public function onBeforeTested() {
    $this->siteHash = $this->stringGenerator->generate();
  }

  public function onAfterTested() {
    if (empty($this->siteHash)) {
      return;
    }

    try {
      $this->httpClient->get($this->baseUrl . '/update?stream.body=<delete><query>hash:' . $this->siteHash . '</query></delete>&commit=true');
    } catch (RequestException $e) {
      throw new RuntimeException('Failed to clear the Solr index', 0, $e);
    }
  }

  /**
   * @param WritingSiteSettingsFile $event
   */
  public function onWritingSiteSettingsFile(WritingSiteSettingsFile $event) {
    $event->addSettings('$conf["search_api_override_mode"] = "default";');
    $event->addSettings('$conf["search_api_override_servers"] = [
      "elife_solr" => [
        "options" => [
          "scheme" => "' . $this->baseUrl->getScheme() . '",
          "host" => "' . $this->baseUrl->getHost() . '",
          "port" => "' . $this->baseUrl->getPort() . '",
          "path" => "' . $this->baseUrl->getPath() . '",
        ],
      ],
    ];');
    $event->addSettings('$conf["search_api_solr_site_hash"] = "' . $this->siteHash . '";');
  }
}
