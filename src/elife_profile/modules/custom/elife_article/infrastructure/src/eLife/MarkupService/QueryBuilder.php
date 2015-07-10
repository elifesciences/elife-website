<?php

namespace eLife\MarkupService;

final class QueryBuilder {
  /**
   * @var array
   */
  private $queries = [];

  /**
   * @var array
   */
  private $xpaths = [
    'doi' => "//*[@data-doi='%s']",
    'main-text' => "//*[contains(concat(' ', @class, ' '), ' section ')]",
    'abstract' => "//*[@id='abstract']",
    'digest' => "//*[@id='elife-digest']",
    'references' => "//*[@id='references']",
    'acknowledgements' => "//*[@id='ack-1']",
    'decision-letter' => "//*[@id='decision-letter']",
    'author-response' => "//*[@id='author-response']",
  ];

  /**
   * @return static
   */
  public static function create() {
    return new static();
  }

  /**
   * @param string $article_id
   * @param string $section
   *
   * @return $this
   */
  public function addSectionQuery($article_id, $section) {
    $this->addQuery($article_id, $section);

    return $this;
  }

  /**
   * @param string $article_id
   * @param string $doi
   *
   * @return $this
   */
  public function addDoiQuery($article_id, $doi) {
    $this->addQuery($article_id, 'doi', $doi);

    return $this;
  }

  public function build() {
    return new Query($this->queries);
  }

  /**
   * @param string $article_id
   * @param string $section
   * @param string $value
   */
  private function addQuery($article_id, $section, $value = NULL) {
    $xpath = $this->xpaths[$section];
    if ($value) {
      $xpath = sprintf($xpath, $value);
    }
    if (!isset($this->queries[$article_id]) || !in_array($xpath, $this->queries[$article_id])) {
      $this->queries[$article_id][] = $xpath;
    }
  }
}
