<?php
/**
 * @file
 * elife_article_reference.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function elife_article_reference_default_rules_configuration() {
  $items = array();
  $items['rules_elife_set_article_reference_title'] = entity_import('rules_config', '{ "rules_elife_set_article_reference_title" : {
      "LABEL" : "Set article reference title",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "eLife", "eLife Title" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_presave--elife_article_reference" : { "bundle" : "elife_article_reference" } },
      "DO" : [
        { "data_set" : {
            "data" : [ "node:field-elife-title:value" ],
            "value" : "[node:field-elife-a-article-id]: [node:field_elife_a_title]"
          }
        },
        { "data_set" : {
            "data" : [ "node:field-elife-title:format" ],
            "value" : "elife_house_style"
          }
        }
      ]
    }
  }');
  return $items;
}
