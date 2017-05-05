<?php
/**
 * @file
 * Contains \Drupal\elife_article\ElifeXslMarkupService.
 */

namespace Drupal\elife_article;

use eLifeIngestXsl\ConvertXML\XMLString;
use eLifeIngestXsl\ConvertXMLToHtml;
use Exception;
use RuntimeException;

class ElifeXslMarkupService extends ElifeMarkupService {
  public $archive = [];
  public $queries = [];
  public $arrange_queries = [];
  public $response = 'response';
  public $error = 'error';
  public $results = [];
  public $methods = [
    'aff' => 'getAffiliation',
    'author-aff' => 'getAuthorAffiliation',
    'doi' => 'getDoi',
    'dc-description' => 'getDcDescription',
    'main-text' => 'getMainText',
    'abstract' => 'getAbstract',
    'fig' => 'getMainFigures',
    'supplementary-material' => 'getSupplementaryMaterial',
    'digest' => 'getDigest',
    'references' => 'getReferences',
    'acknowledgements' => 'getAcknowledgements',
    'decision-letter' => 'getDecisionLetter',
    'author-response' => 'getAuthorResponse',
    'cc-link' => 'getCcLink',
    'original-article' => 'getOriginalArticle',
    'metatags' => 'getMetatags',
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
  public $htmls = [];
  public $xmls = [];
  public $replacements = [];

  private function archiveResults() {
    $key = $this->archiveKey();
    $this->archive[$key] = [
      'results' => $this->results,
      'queries' => $this->queries,
      'arrange_queries' => $this->arrange_queries,
    ];
  }

  public function recoverResults($archive = NULL) {
    $key = $this->archiveKey();
    if (is_null($archive) && !empty($this->archive[$key])) {
      $this->results = $this->archive[$key]['results'];
      $this->queries = $this->archive[$key]['queries'];
      $this->arrange_queries = $this->archive[$key]['arrange_queries'];
      $prepare_archive = $this->archive[$key];
    }
    elseif (!is_null($archive)) {
      $this->results = !empty($archive['results']) ? $archive['results'] : [];
      $this->queries = !empty($archive['queries']) ? $archive['queries'] : [];
      $this->getQuery();
      if (empty($this->results)) {
        $this->submitQuery();
      }
      else {
        $this->archiveResults();
      }
      $key = $this->archiveKey();
      $prepare_archive = $this->archive[$key];
    }
    else {
      $prepare_archive = [
        'results' => $this->results,
        'queries' => $this->queries,
        'arrange_queries' => $this->arrange_queries,
      ];
    }

    return $prepare_archive;
  }

  public function archiveFound($key = NULL) {
    if (is_null($key)) {
      $key = $this->archiveKey();
    }
    return isset($this->archive[$key]) ? TRUE : FALSE;
  }

  private function archiveKey() {
    return _elife_article_markup_query_key($this);
  }

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
   * @param string|null $doi
   */
  public function addDcDescriptionQuery($article_version_id, $doi = NULL) {
    $this->addQuery($article_version_id, 'dc-description', $doi);
  }

  /**
   * @param string $article_version_id
   * @param string $aff_id
   */
  public function addAffiliationQuery($article_version_id, $aff_id) {
    $this->addQuery($article_version_id, 'aff', $aff_id);
  }

  /**
   * @param string $article_version_id
   * @param string $pos
   */
  public function addAuthorAffiliationQuery($article_version_id, $pos) {
    $this->addQuery($article_version_id, 'author-aff', $pos);
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

    $this->archiveResults();
  }

  /**
   * @param string $markup
   * @param string $article_version_id
   * @param string $query_id
   * @return string mixed
   */
  protected function postQueryProcess($markup, $article_version_id, $query_id) {
    $found = preg_match_all('/\[(?:(?:graphic|inline\-graphic|animation|media|video)\-(?:[^\]]+)|[^\.]+\.zip)\]/', $markup, $matches);
    if ($found) {
      $replacements = $this->processPlaceHolders($matches[0], $article_version_id, $query_id);
      $markup = str_replace(array_keys($replacements), array_values($replacements), $markup);
    }

    return $markup;
  }

  protected function processPlaceHolders($placeholders, $article_version_id, $query_id) {
    $node = ElifeArticleVersion::fromId($article_version_id, TRUE, 'elife_article_ver', array(), 1, 'field_elife_a_article_version_id', TRUE);
    $dto = elife_article_version_to_dto($node);
    $placeholders = array_unique($placeholders);
    $replacements = array();
    $cdn = variable_get('elife_article_source_assets_base_path') . ':manuscript-id/:file';
    foreach ($placeholders as $placeholder) {
      if (preg_match('/^\[(?P<type>graphic)\-(?P<prefix>elife\-)(?P<manuscript_id>[0-9]{5,})(?P<suffix>.*)\-(?P<variant>small|medium|large|download)\]$/', $placeholder, $match)) {
        $file = $match['prefix'] . $match['manuscript_id'] . $match['suffix'];
        switch ($match['variant']) {
          case 'small':
            $file .= '-300w.jpg';
            break;

          case 'medium':
            $file .= '-480w.jpg';
            break;

          case 'large':
            $file .= '.jpg';
            break;

          case 'download':
            $file .= '-download.jpg';
            break;

          default:
            $file = '';
        }

        $replacements[$placeholder] = strtr($cdn, array(':manuscript-id' => $match['manuscript_id'], ':file' => $file));
      }
      elseif (preg_match('/^\[(?P<type>animation)\-(?P<prefix>elife\-)(?P<manuscript_id>[0-9]{5,})(?P<suffix>.*)\-(?P<variant>small|medium|large|download)\]$/', $placeholder, $match)) {
        $file = $match['prefix'] . $match['manuscript_id'] . $match['suffix'];
        switch ($match['variant']) {
          case 'small':
          case 'medium':
          case 'large':
            $file .= '.gif';
            break;

          case 'download':
            $file .= '-download.gif';
            break;

          default:
            $file = '';
        }

        $replacements[$placeholder] = strtr($cdn, array(':manuscript-id' => $match['manuscript_id'], ':file' => $file));
      }
      elseif (preg_match('/^\[(?P<type>inline\-graphic)\-(?P<prefix>elife\-)(?P<manuscript_id>[0-9]{5,})(?P<suffix>.*)\-(?P<article_type>research|nonresearch)\-(?P<fragment_type>box|fig|table|other)\]$/', $placeholder, $match)) {
        $file = $match['prefix'] . $match['manuscript_id'] . $match['suffix'] . '.jpg';
        $file = strtr($cdn, array(':manuscript-id' => $match['manuscript_id'], ':file' => $file));
        $replacement = sprintf('<img src="%s"/>', $file);
        if ($match['article_type'] == 'nonresearch' && $match['fragment_type'] == 'box') {
          $replacement = sprintf('<a href="%s" class="colorbox">' . $replacement . '</a>', $file);
        }
        $replacements[$placeholder] = $replacement;
      }
      elseif (preg_match('/^\[(?P<type>media)\-(?P<prefix>elife\-)(?P<manuscript_id>[0-9]{5,})(?P<suffix>.*)(?P<ext>\.[a-z0-9]+)\]$/', $placeholder, $match)) {
        $file = $match['prefix'] . $match['manuscript_id'] . $match['suffix'] . $match['ext'];
        $replacements[$placeholder] = strtr($cdn, array(':manuscript-id' => $match['manuscript_id'], ':file' => $file));
      }
      elseif (preg_match('/^\[(?P<type>video)\-(?P<video>.+)\-(?P<variant>inline|download)\]$/', $placeholder, $match)) {
        if ($glencoe = elife_article_doi_to_glencoe_data($dto->getDoi())) {
          $video_data = $glencoe->{$match['video']};
          if ($match['variant'] == 'download') {
            $replacements[$placeholder] = $video_data->mp4_href;
          }
          elseif ($match['variant'] == 'inline') {
            $variables = array(
              'poster' => $video_data->jpg_href,
              'mp4' => $video_data->mp4_href,
              'webm' => $video_data->webm_href,
              'ogv' => $video_data->ogv_href,
            );
            $replacements[$placeholder] = theme('elife_video', $variables);
          }
        }
      }
      elseif (preg_match('/^\[(?P<file>[^\.]+\.zip)\]$/', $placeholder, $match)) {
        $file = $match['file'];
        $replacements[$placeholder] = strtr($cdn, array(':manuscript-id' => $dto->getManuscriptId(), ':file' => $file));
      }
    }

    $this->replacements[$article_version_id][$query_id] = $replacements;
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
      $path = elife_article_version_source_xml_path($article_version_id);
      $context = stream_context_create(array('http' => array('timeout' => DEFAULT_HTTP_TIMEOUT)));
      $xml = @file_get_contents($path, false, $context);

      if(false === $xml) {
        throw new RuntimeException('Failed to retrieve XML for '.$article_version_id.' from '.$path);
      }

      $this->xmls[$article_version_id] = $xml;
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
        if (is_array($data)) {
          $output .= implode("\n", $data);
        }
      }
    }

    return $output;
  }

  public function load(ElifeMarkupServiceInterface $markup) {
    if ($markup instanceof ElifeXslMarkupService) {
      $archive = $markup->recoverResults();
      $this->recoverResults($archive);
    }
  }
}
