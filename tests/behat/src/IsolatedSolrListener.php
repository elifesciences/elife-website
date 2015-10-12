<?php

namespace eLife\Behat;

use Behat\Behat\EventDispatcher\Event\ExampleTested;
use Behat\Behat\EventDispatcher\Event\ScenarioTested;
use eLife\IsolatedDrupalBehatExtension\Event\WritingSiteSettingsFile;
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

  public static function getSubscribedEvents() {
    return [
      ScenarioTested::BEFORE => 'onBeforeTested',
      ExampleTested::BEFORE => 'onBeforeTested',
      WritingSiteSettingsFile::NAME => 'onWritingSiteSettingsFile',
    ];
  }

  /**
   * @param HttpClient $httpClient
   */
  public function __construct(HttpClient $httpClient) {
    $this->httpClient = $httpClient;
  }

  public function onBeforeTested() {
    $baseUrl = rtrim($this->httpClient->getBaseUrl(), '/');

    try {
      $this->httpClient->get($baseUrl . '/update?stream.body=<delete><query>*:*</query></delete>&commit=true');
    } catch (RequestException $e) {
      throw new RuntimeException('Failed to clear the Solr index', 0, $e);
    }
  }

  /**
   * @param WritingSiteSettingsFile $event
   */
  public function onWritingSiteSettingsFile(WritingSiteSettingsFile $event) {
    $uri = Url::fromString($this->httpClient->getBaseUrl());

    $event->addSettings('$conf["search_api_override_mode"] = "default";');
    $event->addSettings('$conf["search_api_override_servers"] = [
      "elife_solr" => [
        "options" => [
          "scheme" => "' . $uri->getScheme() . '",
          "host" => "' . $uri->getHost() . '",
          "port" => "' . $uri->getPort() . '",
          "path" => "' . rtrim($uri->getPath(), '/') . '",
        ],
      ],
    ];');
    $event->addSettings('$conf["search_api_solr_site_hash"] = "elife_solr_test";');
  }
}
