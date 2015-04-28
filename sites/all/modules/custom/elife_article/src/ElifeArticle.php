<?php

/**
 * @file
 * Contains \Drupal\elife_article\ElifeArticle.
 */

namespace Drupal\elife_article;


class ElifeArticle {

  const DOI_PREFIX = '10.7554/eLife.';

  /**
   * Verify that the apath string is unique.
   *
   * @param $apath
   * @param string $bundle
   * @return bool
   */
  function uniqueApath($apath, $bundle = 'elife_article') {
    $nid = self::fromApath($apath, FALSE, $bundle);

    if (!empty($nid)) {
      return FALSE;
    }

    return TRUE;
  }

  /**
   * Retrieve the article node or node id from the doi.
   *
   * @todo - elife - nlisgo - This may return multiple results.
   *
   * @param $doi
   * @param bool $load
   * @param string $bundle
   * @return bool|mixed
   */
  function fromDoi($doi, $load = TRUE, $bundle = 'elife_article') {
    $doi_query = new ElifeEntityFieldQuery();
    $dois = $doi_query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', $bundle)
      ->fieldCondition('field_elife_a_doi', 'value', $doi, '=')
      // @todo - elife - nlisgo - perhaps only return the current version.
      ->execute();

    if (empty($dois['node'])) {
      return FALSE;
    }
    else {
      $node = array_shift($dois['node'])->nid;
      if ($load) {
        $node = node_load($node);
      }
    }

    return $node;
  }

  /**
   * Retrieve the article node or node id from the apath.
   *
   * @param $apath
   * @param bool $load
   * @param string $bundle
   * @return bool|mixed
   */
  function fromApath($apath, $load = TRUE, $bundle = 'elife_article') {
    $apath_query = new ElifeEntityFieldQuery();
    $apaths = $apath_query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', $bundle)
      ->fieldCondition('field_elife_a_apath', 'value', $apath, '=')
      ->execute();

    if (empty($apaths['node'])) {
      return FALSE;
    }
    else {
      $node = array_shift($apaths['node'])->nid;
      if ($load) {
        $node = node_load($node);
      }
    }

    return $node;
  }

  /**
   * Validate the doi string.
   *
   * @param string $doi
   * @return bool
   */
  public static function validateDoi($doi) {
    $pattern = '/^' . preg_quote(self::DOI_PREFIX, '/') . '[0-9]{5}(\.[0-9]+)?$/';
    $match = preg_match($pattern, $doi);
    if (empty($match)) {
      return FALSE;
    }

    return TRUE;
  }

  /**
   * Clean the title.
   *
   * @param string $title
   * @return string
   */
  public static function cleanTitle($title) {
    $title = self::unicodeFix($title, 'replace');

    $title = strip_tags($title);
    $title = htmlspecialchars_decode($title);

    $title = str_replace("\n", ' ', $title);
    $title = str_replace("  ", ' ', $title);

    if (mb_strlen($title) > 255) {
      //TODO: Trim on word boundary
      $title = mb_substr($title, 0, 254) . '…';
    }
    return $title;
  }

  /**
   * Evaluates whether a string needs unicode replacement.
   *
   * This is useful for drupal titles, which can't store html.
   *
   * Some titles have 4 byte unicode chars. Need to make sure those get removed
   * because the load will crash because the title field encoding is utf8. For a
   * thorough explanation see below link.
   *
   * @see https://drupal.org/node/1314214
   * @see http://magp.ie/2011/01/06/remove-non-utf8-characters-from-string-with-php/
   *
   * @param string $string
   *   the text to evaluate
   * @param string $action
   *   whether to return a replaced string or just check if needed
   *
   * @return boolean/string
   *   returns either TRUE/FALSE on 'check' or modified string on 'replace'
   */
  public static function unicodeFix($string, $action = 'replace') {
    switch ($action) {
      case 'check':
        // Check for overly long 2 byte sequences, as well as characters above
        // U+10000 and replace with ?.
        $two_byte = preg_match('/[\x00-\x08\x10\x0B\x0C\x0E-\x19\x7F]' .
          '|[\x00-\x7F][\x80-\xBF]+' .
          '|([\xC0\xC1]|[\xF0-\xFF])[\x80-\xBF]*' .
          '|[\xC2-\xDF]((?![\x80-\xBF])|[\x80-\xBF]{2,})' .
          '|[\xE0-\xEF](([\x80-\xBF](?![\x80-\xBF]))|(?![\x80-\xBF]{2})|[\x80-\xBF]{3,})/S',
          $string);

        // Reject overly long 3 byte sequences and UTF-16 surrogates and replace
        // with ?.
        $three_byte = preg_match('/\xE0[\x80-\x9F][\x80-\xBF]' .
          '|\xED[\xA0-\xBF][\x80-\xBF]/S', '?', $string);

        $has_replacement = FALSE;
        if ($two_byte == 1 || $three_byte == 1) {
          $has_replacement = TRUE;
        }
        return $has_replacement;

      case 'replace':
        // Reject overly long 2 byte sequences, as well as characters above
        // U+10000 and replace with ?.
        $string = preg_replace('/[\x00-\x08\x10\x0B\x0C\x0E-\x19\x7F]' .
          '|[\x00-\x7F][\x80-\xBF]+' .
          '|([\xC0\xC1]|[\xF0-\xFF])[\x80-\xBF]*' .
          '|[\xC2-\xDF]((?![\x80-\xBF])|[\x80-\xBF]{2,})' .
          '|[\xE0-\xEF](([\x80-\xBF](?![\x80-\xBF]))|(?![\x80-\xBF]{2})|[\x80-\xBF]{3,})/S',
          '?', $string);

        // Reject overly long 3 byte sequences and UTF-16 surrogates and replace
        // with ?.
        $string = preg_replace('/\xE0[\x80-\x9F][\x80-\xBF]' .
          '|\xED[\xA0-\xBF][\x80-\xBF]/S', '?', $string);

        return $string;
    }
  }
} 