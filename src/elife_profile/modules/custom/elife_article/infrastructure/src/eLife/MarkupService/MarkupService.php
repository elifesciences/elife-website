<?php

namespace eLife\MarkupService;

interface MarkupService {
  /**
   * @param Query $query
   *
   * @return string
   *
   * @throws MarkupNotFound
   */
  public function query(Query $query);
}
