<?php

namespace eLife\Monolog;

use DateTime;
use DateTimeInterface;
use Monolog\Formatter\JsonFormatter;

/**
 * Formats Monolog log items in the eLife JSON standard.
 */
final class eLifeJsonFormatter extends JsonFormatter {
  /**
   * Process name.
   *
   * @var string
   */
  private $processName;

  /**
   * Constructor.
   *
   * @param string $process_name
   *   Process name.
   */
  public function __construct($process_name) {
    $this->processName = $process_name;

    parent::__construct();
  }

  /**
   * {@inheritdoc}
   */
  public function format(array $record) {
    $replacement = [];

    $map = [
      'timestamp' => 'datetime',
      'log_level' => 'level_name',
      'section' => 'channel',
      'message' => 'message',
      'context' => 'context',
      'extra' => 'extra',
    ];

    foreach ($map as $new => $old) {
      if (isset($record[$old])) {
        $value = $record[$old];
      }
      else {
        $value = NULL;
      }

      if ($value instanceof DateTime || $value instanceof DateTimeInterface) {
        $value = $value->getTimestamp();
      }

      $replacement[$new] = $value;
    }

    $replacement['process'] = $this->processName;

    return parent::format($replacement);
  }

  /**
   * {@inheritdoc}
   */
  public function formatBatch(array $records) {
    return array_map([$this, 'format'], $records);
  }

}
