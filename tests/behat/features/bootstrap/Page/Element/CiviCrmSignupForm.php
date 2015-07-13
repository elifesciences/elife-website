<?php

namespace Page\Element;

use Exception;
use SensioLabs\Behat\PageObjectExtension\PageObject\Element;

class CiviCrmSignupForm extends Element {
  /**
   * @var array|string $selector
   */
  protected $selector = array('xpath' => '//form[@action="/crm/civicrm/profile/create"]');

  /**
   * @param $id
   * @return \Behat\Mink\Element\NodeElement|mixed|null
   */
  public function hasId($id)
  {
    $element = $this->find("css", 'input[name=custom_6]');
    if(!$element) {
      throw $this->elementNotFound('input', 'css', 'input[name=custom_6]');
    }
    $id_current = $element->getAttribute('value');
    if ($id !== $id_current) {
      throw new Exception('Expected value ' . $id . ' but found ' . $id_current);
    }
  }
}