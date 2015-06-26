<?php

namespace Page\Element;

use Exception;
use SensioLabs\Behat\PageObjectExtension\PageObject\Element;

class ContentAlertsSignupForm extends Element {
  /**
   * @var array|string $selector
   */
  protected $selector = '#elife-content-alerts-sign-up-form';

  /**
   * @param $id
   * @return \Behat\Mink\Element\NodeElement|mixed|null
   */
  public function hasId($id)
  {
    $element = $this->find("css", 'input[name=custom_6]');
    $id_current = $element->getAttribute('value');
    if ($id !== $id_current) {
      throw new Exception('Expected value ' . $id . ' but found ' . $id_current);
    }
  }

  /**
   * @param $gid
   * @return \Behat\Mink\Element\NodeElement|mixed|null
   */
  public function hasGid($gid)
  {
    $actual_gid = FALSE;
    $action = $this->getAttribute('action');
    $action_url = parse_url($action);
    if (!empty($action_url['query'])) {
      $params = array();
      parse_str($action_url['query'], $params);
      if (isset($params['gid'])) {
        $actual_gid = $params['gid'];
      }
    }
    if ($gid !== $actual_gid) {
      throw new Exception('Expected value ' . $gid . ' not found');
    }
  }
}