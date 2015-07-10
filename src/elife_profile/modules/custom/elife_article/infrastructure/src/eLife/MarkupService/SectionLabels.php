<?php

namespace eLife\MarkupService;

final class SectionLabels {
  /**
   * @var array
   */
  private static $sectionLabels = [
    'main-text' => 'Main text',
    'abstract' => 'Abstract',
    'digest' => 'Digest',
    'references' => 'References',
    'acknowledgements' => 'Acknowledgements',
    'decision-letter' => 'Decision letter',
    'author-response' => 'Author response',
  ];

  private function __construct() {
  }

  /**
   * @return array
   *   Array of available section labels.
   */
  public static function getSectionLabels() {
    return self::$sectionLabels;
  }

  /**
   * @return array
   *   Array of available sections.
   */
  public static function getSections() {
    return array_keys(self::$sectionLabels);
  }
}
