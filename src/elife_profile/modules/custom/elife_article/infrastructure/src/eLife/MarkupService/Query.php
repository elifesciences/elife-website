<?php

namespace eLife\MarkupService;

final class Query {
  /**
   * @var array
   */
  private $queries = [];

  /**
   * @param array $queries
   */
  public function __construct(array $queries) {
    $this->queries = $queries;
  }

  /**
   * @return string
   */
  public function __toString() {
    return $this->getValue();
  }

  /**
   * @return string
   */
  public function getValue() {
    $content = '';
    foreach ($this->queries as $article_id => $article_queries) {
      $content .= '<article id="' . $article_id . '">';
      foreach ($article_queries as $article_query) {
        $content .= '<query xpath="' . $article_query . '" ></query>';
      }
      $content .= '</article>';
    }

    if (!empty($content)) {
      return '<xmltohtml>' . $content . '</xmltohtml>';
    }

    return '';
  }
}
