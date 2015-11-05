<?php
/**
 * @file
 * Contains \Drupal\elife_article\ElifeXslMarkupService.
 */

namespace Drupal\elife_article;

use eLifeIngestXsl\ConvertXML\XMLString;
use eLifeIngestXsl\ConvertXMLToHtml;
use Exception;

class ElifeXslMarkupService extends ElifeMarkupService {
  private $queries = [];
  private $arrange_queries = [];
  private $response = 'response';
  private $error = 'error';
  private $results = [];
  private $methods = [
    'aff' => 'getAffiliation',
    'doi' => 'getDoi',
    'main-text' => 'getMainText',
    'abstract' => 'getAbstract',
    'digest' => 'getDigest',
    'references' => 'getReferences',
    'acknowledgements' => 'getAcknowledgements',
    'decision-letter' => 'getDecisionLetter',
    'author-response' => 'getAuthorResponse',
    'datasets' => 'getDatasets',
    'author-info-group-authors' => 'getAuthorInfoGroupAuthors',
    'author-info-contributions' => 'getAuthorInfoContributions',
    'author-info-equal-contrib' => 'getAuthorInfoEqualContrib',
    'author-info-other-footnotes' => 'getAuthorInfoOtherFootnotes',
    'author-info-correspondence' => 'getAuthorInfoCorrespondence',
    'author-info-additional-address' => 'getAuthorInfoAdditionalAddress',
    'author-info-competing-interest' => 'getAuthorInfoCompetingInterest',
    'author-info-funding' => 'getAuthorInfoFunding',
    'article-info-identification' => 'getArticleInfoIdentification',
    'article-info-history' => 'getArticleInfoHistory',
    'article-info-ethics' => 'getArticleInfoEthics',
    'article-info-reviewing-editor' => 'getArticleInfoReviewingEditor',
    'article-info-license' => 'getArticleInfoLicense',
  ];
  private $htmls = [];
  private $xmls = [];
  private $replacements = [];

  /**
   * @param string $article_version_id
   * @param string $section
   * @param string $value
   */
  private function addQuery($article_version_id, $section, $value = NULL) {
    $query_id = [$article_version_id, $section];
    $method = $this->methods[$section];

    $query = ['method' => $method, 'params' => []];

    if ($value) {
      $query['params'] = [$value];
      $query_id[] = $value;
    }

    $this->queries[implode('::', $query_id)] = $query;
  }

  private function arrangeQuery() {
    $this->arrange_queries = [];
    foreach ($this->queries as $query_id => $query) {
      list($article_version_id) = explode('::', $query_id);
      $this->arrange_queries[$article_version_id][$query_id] = $query;
    }
  }

  /**
   * @return array
   *   Array of arranged queries.
   */
  public function getQuery() {
    $this->arrangeQuery();
    return $this->arrange_queries;
  }

  /**
   * @param string $article_version_id
   * @param string|array $section
   */
  public function addSectionQuery($article_version_id, $section) {
    $sections = (!is_array($section)) ? [$section] : $section;
    foreach ($sections as $section) {
      $this->addQuery($article_version_id, $section);
    }
  }

  /**
   * @param string $article_version_id
   * @param string $doi
   */
  public function addDoiQuery($article_version_id, $doi) {
    $this->addQuery($article_version_id, 'doi', $doi);
  }

  /**
   * @param string $article_version_id
   * @param string $aff_id
   */
  public function addAffiliationQuery($article_version_id, $aff_id) {
    $this->addQuery($article_version_id, 'aff', $aff_id);
  }

  public function submitQuery($post_process = TRUE) {
    $queries = $this->getQuery();
    $this->htmls = [];
    $this->results = [];
    foreach ($queries as $article_version_id => $article_ver_queries) {
      $html = $this->retrieveHtml($article_version_id);
      foreach ($article_ver_queries as $article_ver_query) {
        $query_id = array_merge([array_search($article_ver_query['method'], $this->methods)], $article_ver_query['params']);
        $query_id = implode('::', $query_id);

        $res = call_user_func_array([$html, $article_ver_query['method']], $article_ver_query['params']);
        $this->results[$article_version_id][$query_id] = [];
        if (!empty($res)) {
          if ($post_process) {
            $res = $this->postQueryProcess($res, $article_version_id, $query_id);
          }
          $this->results[$article_version_id][$query_id][] = $res;
        }
      }
    }
  }

  public function preloadReplacements() {
    $queries = $this->getQuery();
    foreach (array_keys($queries) as $article_version_id) {
      $preload_query = new ElifeXslMarkupService();
      $preload_query->addQuery($article_version_id, 'main-text');
      $preload_query->addQuery($article_version_id, 'author-response');
      $preload_query->submitQuery();
      foreach ($queries[$article_version_id] as $key => $query) {
        $replacement_key = str_replace($article_version_id . '::', '', $key);
        $this->replacements[$article_version_id][$replacement_key] = $preload_query->getReplacements($article_version_id);
      }
    }
  }

  public function getReplacements($article_version_id) {
    $replacements = $this->replacements[$article_version_id];
    $aggregate = [];
    foreach ($replacements as $query => $reps) {
      $aggregate = array_merge($aggregate, $reps);
    }
    return $aggregate;
  }

  /**
   * @param string $markup
   * @param string $article_version_id
   * @param string $query_id
   * @return string mixed
   */
  protected function postQueryProcess($markup, $article_version_id, $query_id) {
    // @todo - elife - nlisgo - Introduce post process steps here.
    // For example substitute paths to files.
    $found = preg_match_all('/\[(?:graphic|inline\-graphic|animation|media|video)\-(?:[^\]]+)\]/', $markup, $matches);
    if ($found) {
      $replacements = $this->processPlaceHolders($matches[0], $article_version_id, $query_id);
      $markup = str_replace(array_keys($replacements), array_values($replacements), $markup);
    }
    return $markup;
  }

  protected function processPlaceHolders($placeholders, $article_version_id, $query_id) {
    if (empty($this->replacements[$article_version_id][$query_id])) {
      $placeholders = array_unique($placeholders);

      $positions = [];
      foreach ($placeholders as $placeholder) {
        if (preg_match('/^\[(?P<type>animation|graphic|media)\-elife\-[0-9]{5}\-?(?P<resp>resp)?\-fig(?P<fig_id>[0-9]+)\-(?P<subtype>[a-z]+)(?P<subtype_id>[0-9]+)/', $placeholder, $match)) {
          $key = ($match['subtype'] == 'figsupp') ? $match['subtype'] : $match['type'];
          $value = ($match['subtype'] != 'v') ? $match['fig_id'] . '.' . $match['subtype'] . $match['subtype_id'] : $match['fig_id'];
          if (empty($positions[$key]) || !in_array($value, $positions[$key])) {
            $positions[$key][] = $value;
          }
        }
      }

      $replacements = array();
      $author_response_first_fig = 0;
      foreach ($placeholders as $placeholder) {
        $details = explode('-', trim($placeholder, '[]'));
        $group = array_shift($details);
        if ($group == 'inline') {
          $group .= '-' . array_shift($details);
        }
        if ($group == 'graphic') {
          $prefix = array_shift($details);
          $variant = array_pop($details);
          $version = ltrim(array_pop($details), 'v');
          $manuscript_id = array_shift($details);
          $fig_id = $subarticle = array_shift($details);
          if (strpos($subarticle, 'fig') === 0) {
            $fig_id = str_replace('fig', '', $fig_id);
            $subarticle = NULL;
          }
          else {
            if ($author_response_first_fig !== FALSE || $author_response_first_fig > 0) {
              $author_response_query = new ElifeXslMarkupService();
              $author_response_query->addQuery($article_version_id, 'author-response');
              $author_response_query->submitQuery(FALSE);
              $author_response = $author_response_query->output();
              if (preg_match('/<div id=\"fig(?P<author_response_first_fig>[0-9]+)/', $author_response, $match)) {
                $author_response_first_fig = $match['author_response_first_fig'] - 1;
              }
              else {
                $author_response_first_fig = FALSE;
              }
            }
            $fig_id = str_replace('fig', '', array_shift($details)) + $author_response_first_fig;
          }
          $fig_supp_id = (!empty($details)) ? str_replace('figsupp', '', array_shift($details)) : NULL;

          $replacement = 'http://cdn.elifesciences.org/elife-articles/' . $manuscript_id . '/jpg/' . $prefix . $manuscript_id;

          if ($fig_supp_id) {
            $fs_pos = $fig_id . '.figsupp' . $fig_supp_id;
            $replacement .= 'fs' . str_pad(array_search($fs_pos, $positions['figsupp']) + 1, 3, "0", STR_PAD_LEFT);
          }
          else {
            $replacement .= 'f' . str_pad(array_search($fig_id, $positions['graphic']) + 1 + $author_response_first_fig, 3, "0", STR_PAD_LEFT);
          }

          $replacement .= '.jpg';
        }
        elseif ($group == 'animation') {
          $prefix = array_shift($details);
          $variant = array_pop($details);
          $version = ltrim(array_pop($details), 'v');
          $manuscript_id = array_shift($details);
          $fig_id = str_replace('fig', '', array_shift($details));

          $replacement = 'http://cdn.elifesciences.org/elife-articles/' . $manuscript_id . '/jpg/' . $prefix . $manuscript_id;

          $replacement .= 'f' . str_pad(count($positions['graphic']) + array_search($fig_id, $positions['animation']) + 1, 3, "0", STR_PAD_LEFT);

          $replacement .= '.gif';
        }
        elseif ($group == 'inline-graphic') {
          $prefix = array_shift($details);
          $parent_fragment = array_pop($details);
          $article_type = array_pop($details);
          $version = ltrim(array_pop($details), 'v');
          $manuscript_id = array_shift($details);
          $inf_id = str_replace('inf', '', array_shift($details));
          $inf = 'inf' . str_pad($inf_id, 3, "0", STR_PAD_LEFT);
          $file = sprintf('http://cdn.elifesciences.org/elife-articles/%s/jpg/%s.jpg', $manuscript_id, $prefix . $manuscript_id . $inf);

          $replacement = sprintf('<img src="%s"/>', $file);
          if ($article_type == 'nonresearch' && $parent_fragment == 'box') {
            $replacement = sprintf('<a href="%s" class="colorbox">' . $replacement . '</a>', $file);
          }
        }
        elseif ($group == 'media') {
          $prefix = array_shift($details);
          list($version, $ext) = explode('.', array_pop($details));
          $version = ltrim($version, 'v');
          $manuscript_id = array_shift($details);
          $fig_id = str_replace('fig', '', array_shift($details));
          $fig_supp_id = array_shift($details);

          $replacement = sprintf('http://cdn.elifesciences.org/elife-articles/%s/suppl/%s', $manuscript_id, $prefix . $manuscript_id);

          $fs_pos = $fig_id . '.' . $fig_supp_id;
          $replacement .= 's' . str_pad(array_search($fs_pos, $positions['media']) + 1, 3, "0", STR_PAD_LEFT);

          $replacement .= '.' . $ext;
        }
        else {
          $replacement = '{{' . $group . '-' . implode('-', $details) . '}}';
        }
        $replacements[$placeholder] = $replacement;
      }
      $this->replacements[$article_version_id][$query_id] = $replacements;
    }
    return $this->replacements[$article_version_id][$query_id];
  }

  /**
   * @param string $article_version_id
   * @return ConvertXMLToHtml
   */
  public function retrieveHtml($article_version_id) {
    $xml = $this->retrieveXml($article_version_id);
    if (!empty($xml)) {
      $convert_xml_to_html = $this->retrieveHtmlCache($article_version_id);
      if (!empty($convert_xml_to_html[$article_version_id])) {
        return $convert_xml_to_html[$article_version_id];
      }
    }
  }

  /**
   * @param string $article_version__id
   * @return ConvertXMLToHtml[]
   */
  public function retrieveHtmlCache($article_version_id) {
    $cache = &drupal_static(__FUNCTION__, []);

    if (!isset($cache[$article_version_id])) {
      $xml = $this->retrieveXml($article_version_id);
      if (!empty($xml)) {
        $convert_xml_to_html = new ConvertXMLToHtml(XMLString::fromString($xml));
        $cache[$article_version_id] = $convert_xml_to_html;
      }
    }

    return $cache;
  }

  public function retrieveXml($article_version_id) {
    $xml = $this->retrieveXmlCache($article_version_id);
    if (!empty($xml[$article_version_id])) {
      return $xml[$article_version_id];
    }
  }

  private function retrieveXmlCache($article_version_id) {
    $cache = &drupal_static(__FUNCTION__, []);

    if (!isset($cache[$article_version_id])) {
      $xml = $this->getXml($article_version_id);
      $cache[$article_version_id] = $xml;
    }

    return $cache;
  }

  public function setXml($article_version_id, $xml = NULL) {
    if (!isset($this->xmls[$article_version_id])) {
      if (empty($xml)) {
        $xml = elife_article_version_source_xml_path($article_version_id);
      }
      $this->xmls[$article_version_id] = file_get_contents($xml);
    }
  }

  protected function getXml($article_version_id) {
    if (!isset($this->xmls[$article_version_id])) {
      $this->setXml($article_version_id);
    }
    return $this->xmls[$article_version_id];
  }

  public function processResponse() {
    $this->results = $this->queries;
  }

  /**
   * @return string
   *   Return response string.
   */
  public function getResponse() {
    return $this->response;
  }

  /**
   * @return string
   *   Return error string.
   */
  public function getError() {
    return $this->error;
  }

  /**
   * @return array
   *   Return error string.
   */
  public function getResults() {
    if (empty($this->results)) {
      $this->processResponse();
    }

    return $this->results;
  }


  /**
   * @param string $article_version_id
   *   Article id.
   *
   * @return array
   *   Array of results.
   * @throws \Exception
   */
  public function getResult($article_version_id) {
    if (empty($this->results)) {
      $this->processResponse();
    }
    $results = (isset($this->results[$article_version_id])) ? $this->results[$article_version_id] : [];

    return $results;
  }

  /**
   * @return string
   *   HTML output from markup query.
   */
  public function output() {
    $results = $this->getResults();
    $output = '';
    foreach ($results as $article_ver_queries) {
      foreach ($article_ver_queries as $data) {
        $output .= implode("\n", $data);
      }
    }

    return $output;
  }
}

