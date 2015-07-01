<?php

namespace eLife\EIF;

use Exception;
use UnexpectedValueException;

class JsonSchemaErrors extends UnexpectedValueException {
  /**
   * @var JsonSchemaError[]
   */
  protected $errors;

  /**
   * @param JsonSchemaError[] $errors
   * @param Exception $previous
   */
  public function __construct(array $errors, Exception $previous = NULL) {
    parent::__construct('JSON does not match the schema', 0, $previous);

    $this->errors = $errors;
  }

  /**
   * @return JsonSchemaError[]
   */
  public function getErrors() {
    return $this->errors;
  }
}
