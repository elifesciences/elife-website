<?php
/**
 * @file
 * elife_house_style.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function elife_house_style_default_rules_configuration() {
  $items = array();
  $items['rules_elife_set_node_title'] = entity_import('rules_config', '{ "rules_elife_set_node_title" : {
      "LABEL" : "Set node title",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "10",
      "OWNER" : "rules",
      "TAGS" : [ "eLife", "eLife Title" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_presave" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_elife_title" } }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "node:title" ], "value" : "[node:field-elife-title:value]" } }
      ]
    }
  }');
  $items['rules_set_taxonomy_term_title'] = entity_import('rules_config', '{ "rules_set_taxonomy_term_title" : {
      "LABEL" : "Set taxonomy term name",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "10",
      "OWNER" : "rules",
      "TAGS" : [ "eLife", "eLife Title" ],
      "REQUIRES" : [ "rules", "taxonomy" ],
      "ON" : { "taxonomy_term_presave" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "term" ], "field" : "field_elife_title" } }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "term:name" ], "value" : "[term:field-elife-title:value]" } }
      ]
    }
  }');
  return $items;
}
