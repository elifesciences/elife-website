<?php

namespace eLife\EIF;

interface JsonValidator {
  /**
   * @param string $json
   *
   * @throws InvalidJson
   * @throws JsonSchemaErrors
   */
  public function validate($json);
}
