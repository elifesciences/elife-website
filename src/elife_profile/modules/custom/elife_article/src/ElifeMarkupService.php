<?php
/**
 * @file
 * Contains \Drupal\elife_article\ElifeMarkupService.
 */

namespace Drupal\elife_article;

abstract class ElifeMarkupService implements ElifeMarkupServiceInterface {
  public static $sections = [
    'abstract' => 'Abstract',
    'digest' => 'eLife digest',
    'main-text' => 'Main text',
    'references' => 'References',
    'acknowledgements' => 'Acknowledgements',
    'decision-letter' => 'Decision letter',
    'author-response' => 'Author response',
  ];

  /**
   * @return array
   *   Array of available section labels.
   */
  public static function getSectionLabels() {
    return self::$sections;
  }
}

