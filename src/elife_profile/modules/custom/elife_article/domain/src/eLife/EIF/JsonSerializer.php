<?php

namespace eLife\EIF;

use eLife\EIF\ArticleVersion;

interface JsonSerializer {
  /**
   * @param ArticleVersion $articleVersion
   *
   * @return string
   */
  public function serialize(ArticleVersion $articleVersion);

  /**
   * @param string $json
   *
   * @return ArticleVersion
   *
   * @throws InvalidJson
   */
  public function deserialize($json);
}
