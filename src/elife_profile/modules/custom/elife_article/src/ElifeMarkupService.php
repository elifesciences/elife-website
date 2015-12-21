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
    'fig' => 'Main figures',
    'supplementary-material' => 'Supplementary Material',
    'references' => 'References',
    'acknowledgements' => 'Acknowledgements',
    'decision-letter' => 'Decision letter',
    'author-response' => 'Author response',
    'cc-link' => 'Creative commons',
    'original-article' => 'Original article',
    'metatags' => 'Metatags',
    'dc-description' => 'DC.Description',
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

  private static $section_filters = [
    'main' => '/^(abstract|digest|main\-text|references|acknowledgements|decision\-letter|author\-response)$/',
    'author-info' => '/^author\-info\-/',
    'article-info' => '/^article\-info\-/',
  ];

  /**
   * @param null|string $filter
   *
   * @return array
   *   Array of available section labels.
   */
  public static function getSectionLabels($filter = NULL) {
    if (is_null($filter) || !isset(self::$section_filters[$filter])) {
      $sections = self::$sections;
    }
    else {
      $sections = [];
      foreach (self::$sections as $section => $section_name) {
        if (preg_match(self::$section_filters[$filter], $section)) {
          $sections[$section] = $section_name;
        }
      }
    }
    return $sections;
  }
}
