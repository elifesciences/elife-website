<?php
/**
 * @file
 * elife_early_careers_interviews.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function elife_early_careers_interviews_default_rules_configuration() {
  $items = array();
  $items['rules_elife_set_early_careers_interview_title'] = entity_import('rules_config', '{ "rules_elife_set_early_careers_interview_title" : {
      "LABEL" : "Set interview title",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "eLife", "eLife Title" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_presave--elife_early_careers_interview" : { "bundle" : "elife_early_careers_interview" } },
      "DO" : [
        { "data_set" : {
            "data" : [ "node:field-elife-title:value" ],
            "value" : "[node:field_elife_i_title]: an interview with [node:field_elife_i_first_name] [node:field_elife_i_last_name]"
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
  $items['rules_elife_set_interview_series_title'] = entity_import('rules_config', '{ "rules_elife_set_interview_series_title" : {
      "LABEL" : "Set interview series title (with sub-title)",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "eLife", "eLife Title" ],
      "REQUIRES" : [ "rules", "taxonomy" ],
      "ON" : { "taxonomy_term_presave--elife_i_series" : { "bundle" : "elife_i_series" } },
      "IF" : [
        { "NOT data_is_empty" : { "data" : [ "term:field-elife-is-sub-title:value" ] } }
      ],
      "DO" : [
        { "data_set" : {
            "data" : [ "term:field-elife-title:value" ],
            "value" : "[term:field_elife_is_title]: [term:field_elife_is_sub_title]"
          }
        },
        { "data_set" : {
            "data" : [ "term:field-elife-title:format" ],
            "value" : "elife_house_style"
          }
        }
      ]
    }
  }');
  $items['rules_elife_set_interview_series_title_without_sub_title'] = entity_import('rules_config', '{ "rules_elife_set_interview_series_title_without_sub_title" : {
      "LABEL" : "Set interview series title (without sub-title)",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "eLife", "eLife Title" ],
      "REQUIRES" : [ "rules", "taxonomy" ],
      "ON" : { "taxonomy_term_presave--elife_i_series" : { "bundle" : "elife_i_series" } },
      "IF" : [
        { "data_is_empty" : { "data" : [ "term:field-elife-is-sub-title:value" ] } }
      ],
      "DO" : [
        { "data_set" : {
            "data" : [ "term:field-elife-title:value" ],
            "value" : "[term:field_elife_is_title]"
          }
        },
        { "data_set" : {
            "data" : [ "term:field-elife-title:format" ],
            "value" : "elife_house_style"
          }
        }
      ]
    }
  }');
  return $items;
}
