<?php
/**
 * @file
 * Contains \Drupal\elife_article\ElifeMarkupService.
 */

namespace Drupal\elife_article;

abstract class ElifeMarkupService implements ElifeMarkupServiceInterface {
  private static $sections = [
    'abstract' => 'Abstract',
    'digest' => 'eLife digest',
    'main-text' => 'Main text',
    'references' => 'References',
    'acknowledgements' => 'Acknowledgements',
    'decision-letter' => 'Decision letter',
    'author-response' => 'Author response',
    'datasets' => 'Major datasets',
    'author-info-group-authors' => 'Other contributors',
    'author-info-equal-contrib' => 'Equal contributions',
    'author-info-other-footnotes' => 'Other Footnotes',
    'author-info-contributions' => 'Author contributions',
    'author-info-correspondence' => 'For corresponsdence',
    'author-info-additional-address' => 'Additional address',
    'author-info-competing-interest' => 'Competing interests',
    'author-info-funding' => 'Funding',
    'article-info-identification' => 'Identification',
    'article-info-history' => 'Publication history',
    'article-info-ethics' => 'Ethics',
    'article-info-reviewing-editor' => 'Reviewing editor',
    'article-info-license' => 'Copyright',
  ];

  /**
   * @return array
   *   Array of available section labels.
   */
  public static function getSectionLabels() {
    return self::$sections;
  }
}

