<?php

use Drupal\DrupalExtension\Context\DrupalContext;

class IsolatedDrupalContext extends DrupalContext {
  /**
   * @BeforeScenario
   */
  public function isolate() {
    drupal_static_reset();
    drupal_path_alias_whitelist_rebuild();
    registry_update(); // TODO this is an ugly hack for ELPP-307.
  }

  public function cleanNodes() {
    $this->nodes = [];
  }

  public function cleanUsers() {
    $this->users = [];
  }

  public function cleanTerms() {
    $this->terms = [];
  }

  public function cleanRoles() {
    $this->roles = [];
  }

  public function assertCron() {
    /** @var \Drupal\Driver\DrushDriver $driver */
    $driver = $this->getDriver('drush');
    $driver->drush('elysia-cron');
  }

  public function parseEntityFields($entity_type, \stdClass $entity) {
    if ('taxonomy_term' === $entity_type && empty($entity->name)) {
      $entity->name = ''; // To avoid undefined property notice in taxonomy_term_save().
    }
    elseif ('taxonomy_term' === $entity_type && empty($entity->field_elife_title)) {
      $entity->field_elife_title = $entity->name;
    }

    parent::parseEntityFields($entity_type, $entity);

    // TODO the following is a hack to have the text format set correctly.

    $house_style_fields = [
      'field_elife_a_title' => 'elife_house_style',
      'field_elife_c_sub_title' => 'elife_house_style',
      'field_elife_c_text' => 'elife_full_html',
      'field_elife_c_title' => 'elife_house_style',
      'field_elife_i_title' => 'elife_house_style',
      'field_elife_n_text' => 'elife_full_html',
      'field_elife_p_text' => 'elife_full_html',
      'field_elife_p_title' => 'elife_house_style',
      'field_elife_pc_text_inverse' => 'elife_house_style',
      'field_elife_pc_title' => 'elife_house_style',
      'field_elife_title' => 'elife_house_style',
    ];

    foreach ($house_style_fields as $field => $format) {
      if (empty($entity->{$field})) {
        continue;
      }

      foreach ($entity->{$field} as $key => $value) {
        if (!is_string($value)) {
          continue;
        }

        $entity->{$field}[$key] = [
          'format' => $format,
          'value' => $value,
        ];
      }
    }
  }
}
