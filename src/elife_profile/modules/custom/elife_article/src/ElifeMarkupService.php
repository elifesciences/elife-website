<?php
/**
 * @file
 * Contains \Drupal\elife_article\ElifeMarkupService.
 */

namespace Drupal\elife_article;

abstract class ElifeMarkupService {
  protected $sections = [
    'main-text' => 'Main text',
    'abstract' => 'Abstract',
    'digest' => 'Digest',
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

