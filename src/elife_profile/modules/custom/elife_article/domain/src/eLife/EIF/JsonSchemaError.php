<?php

namespace eLife\EIF;

final class JsonSchemaError {
  /**
   * @var string
   */
  private $field;

  /**
   * @var string
   */
  private $message;

  /**
   * @var string|array
   */
  private $value;

  public function __construct($field, $message, $value) {
    $this->field = (string) $field;
    $this->message = (string) $message;
    $this->value = $value;
  }

  /**
   * @return string
   */
  public function getField() {
    return $this->field;
  }

  /**
   * @return string
   */
  public function getMessage() {
    return $this->message;
  }

  /**
   * @return string|array
   */
  public function getValue() {
    return $this->value;
  }
}
