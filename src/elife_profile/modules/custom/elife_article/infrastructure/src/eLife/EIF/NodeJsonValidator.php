<?php

namespace eLife\EIF;

use LogicException;
use Symfony\Component\Process\Process;

final class NodeJsonValidator implements JsonValidator {
  private $path;

  public function __construct($path) {
    $this->path = $path;
  }

  public function validate($json) {
    $json = (string) $json;

    $process = new Process($this->path, NULL, NULL, $json);
    $process->setTimeout(2);
    $process->run();

    if (!$process->isSuccessful()) {
      throw $this->outputToException($process->getOutput());
    }
  }

  private function outputToException($string) {
    $json = @json_decode($string, TRUE);

    if (FALSE === $json) {
      return new LogicException('Doh');
    }

    $errors = [];

    foreach ($json as $item) {
      $errors[] = new JsonSchemaError(
        $item['field'],
        $item['message'],
        $item['value']
      );
    }

    return new JsonSchemaErrors($errors);
  }
}
