<?php
/**
 * @file
 * elife_podcast.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function elife_podcast_default_rules_configuration() {
  $items = array();
  $items['rules_elife_set_podcast_chapter_title'] = entity_import('rules_config', '{ "rules_elife_set_podcast_chapter_title" : {
      "LABEL" : "Set podcast chapter title",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "1",
      "OWNER" : "rules",
      "TAGS" : [ "eLife", "eLife Title" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_presave--elife_podcast_chapter" : { "bundle" : "elife_podcast_chapter" } },
      "DO" : [
        { "data_set" : {
            "data" : [ "node:field-elife-title:value" ],
            "value" : "Episode [node:field-elife-pc-podcast:field-elife-p-episode-number] Chapter: [node:field_elife_pc_title]"
          }
        },
        { "data_set" : {
            "data" : [ "node:field-elife-title:format" ],
            "value" : [ "node:field-elife-pc-title:format" ]
          }
        }
      ]
    }
  }');
  $items['rules_elife_set_podcast_title'] = entity_import('rules_config', '{ "rules_elife_set_podcast_title" : {
      "LABEL" : "Set podcast title",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "eLife", "eLife Title" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_presave--elife_podcast" : { "bundle" : "elife_podcast" } },
      "DO" : [
        { "data_set" : {
            "data" : [ "node:field-elife-title:value" ],
            "value" : "Episode [node:field-elife-p-episode-number]: [node:field_elife_p_title]"
          }
        },
        { "data_set" : {
            "data" : [ "node:field-elife-title:format" ],
            "value" : [ "node:field-elife-p-title:format" ]
          }
        }
      ]
    }
  }');
  return $items;
}
