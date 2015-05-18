<?php

use Behat\Behat\Tester\Exception\PendingException;
use Drupal\DrupalExtension\Context\RawDrupalContext;
use Behat\Behat\Context\SnippetAcceptingContext;
use Drupal\elife_article\ElifeArticle;
use Behat\Behat\Hook\Scope\BeforeStepScope;

/**
 * Defines application features from the specific context.
 */
class FeatureContext extends RawDrupalContext implements SnippetAcceptingContext {

  /**
   * Keep track of maximum node id.
   *
   * @var int
   */
  protected $maxNid = 0;

  /**
   * Keep track of maximum term id.
   *
   * @var int
   */
  protected $maxTid = 0;

  /**
   * Keep track of maximum relation id.
   *
   * @var int
   */
  protected $maxRid = 0;

  /**
   * Flag to determine whether max queries have been run.
   *
   * @var bool
   */
  private $maxQueriesRun = FALSE;

  /**
   * Initializes context.
   */
  public function __construct() {
  }

  /**
   * Store maximum entity ids.
   *
   * @BeforeStep
   *
   * @param BeforeStepScope $scope
   */
  public function beforeStepRunMaxQueries(BeforeStepScope $scope) {
    if (!$this->maxQueriesRun) {
      $text = $scope->getStep()->getText();
      if (preg_match('/send a (POST|PUT) request to "[^\"]+" with body\:$/i', $text)) {
        $result = db_query_range("SELECT nid FROM {node} ORDER BY nid DESC", 0, 1)->fetchField();
        if ($result) {
          $this->maxNid = $result;
        }
        $result = db_query_range("SELECT tid FROM {taxonomy_term_data} ORDER BY tid DESC", 0, 1)->fetchField();
        if ($result) {
          $this->maxTid = $result;
        }
        $result = db_query_range("SELECT rid FROM {relation} ORDER BY rid DESC", 0, 1)->fetchField();
        if ($result) {
          $this->maxRid = $result;
        }
        $this->maxQueriesRun = TRUE;
      }
    }
  }

  /**
   * Delete entities above maximum ids.
   *
   * @AfterScenario
   */
  public function afterScenario() {
    if ($this->maxQueriesRun) {
      $results = db_select('node', 'n')
        ->fields('n', array('nid'))
        ->condition('n.nid', $this->maxNid, '>')
        ->execute();

      $nids = array();
      foreach ($results as $result) {
        $nids[] = $result->nid;
      }

      if (!empty($nids)) {
        node_delete_multiple($nids);
      }

      $results = db_select('taxonomy_term_data', 't')
        ->fields('t', array('tid'))
        ->condition('t.tid', $this->maxTid, '>')
        ->execute();

      foreach ($results as $result) {
        taxonomy_term_delete($result->tid);
      }

      $results = db_select('relation', 'r')
        ->fields('r', array('rid'))
        ->condition('r.rid', $this->maxRid, '>')
        ->execute();

      $rids = array();
      foreach ($results as $result) {
        $rids[] = $result->rid;
      }

      if (!empty($rids)) {
        relation_delete_multiple($rids);
      }
    }
  }
}
