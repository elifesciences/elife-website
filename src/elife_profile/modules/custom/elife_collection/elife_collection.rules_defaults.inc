<?php
/**
 * @file
 * elife_collection.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function elife_collection_default_rules_configuration() {
  $items = array();
  $items['rules_elife_set_collection_title'] = entity_import('rules_config', '{ "rules_elife_set_collection_title" : {
      "LABEL" : "Set collection title (with sub-title)",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "eLife", "eLife Title" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_presave--elife_collection" : { "bundle" : "elife_collection" } },
      "IF" : [
        { "NOT data_is_empty" : { "data" : [ "node:field-elife-c-sub-title:value" ] } }
      ],
      "DO" : [
        { "data_set" : {
            "data" : [ "node:field-elife-title:value" ],
            "value" : "[node:field_elife_c_title]: [node:field_elife_c_sub_title]"
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
  $items['rules_elife_set_collection_title_without_sub_title'] = entity_import('rules_config', '{ "rules_elife_set_collection_title_without_sub_title" : {
      "LABEL" : "Set collection title (without sub-title)",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "eLife", "eLife Title" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_presave--elife_collection" : { "bundle" : "elife_collection" } },
      "IF" : [
        { "data_is_empty" : { "data" : [ "node:field-elife-c-sub-title:value" ] } }
      ],
      "DO" : [
        { "data_set" : {
            "data" : [ "node:field-elife-title:value" ],
            "value" : "[node:field_elife_c_title]"
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
