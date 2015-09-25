<?php

/**
 * @file
 * elife_entities/templates/elife_hero_block.tpl.php
 */

if (!empty($content['field_elife_h_image_colour'])):
  $colour = $content['field_elife_h_image_colour']['#items'][0]['value'];
else:
  $colour = 'dark';
endif;

drupal_add_css(sprintf('.%s .hero-block__primary_content { background-image: url("%s") }', 'hero-block--' . $variables['nid'], image_style_url('elife_hero_block', $content['field_elife_h_image'][0]['#item']['uri'])), array('type' => 'inline'));

?>

<div
  class="hero-block<?php if ('light' === $colour): ?> hero-block--light<?php endif; ?> hero-block--<?php print $variables['nid']; ?>">
  <div class="hero-block__primary_content">
    <?php if (!empty($content['field_elife_h_credit'])): ?>
      <span class="hero-block__image_credit">
      <?php print $content['field_elife_h_credit']['#items'][0]['safe_value']; ?>
    </span>
    <?php endif; ?>
    <h1 class="hero-block__title"><?php print $title; ?></h1>
    <?php if (!empty($content['field_elife_h_sub_title'])): ?>
      <h2 class="hero-block__sub_title">
        <?php print $content['field_elife_h_sub_title']['#items'][0]['safe_value']; ?>
      </h2>
    <?php endif; ?>

    <?php if (!empty($content['field_elife_cta_link'])): ?>
      <div class="hero-block__cta cta">
        <?php if (!empty($content['field_elife_cta_text'])): ?>
          <span class="cta__text">
          <?php print $content['field_elife_cta_text']['#items'][0]['safe_value']; ?>
        </span>
        <?php endif; ?>
        <a
          href="<?php print $content['field_elife_cta_link']['#items'][0]['display_url']; ?>"
          class="cta__link">
          <?php print $content['field_elife_cta_link']['#items'][0]['title']; ?>
        </a>
      </div>
    <?php endif; ?>
  </div>

  <?php if (!empty($field_elife_cc)): ?>
    <ol class="hero-block__content-column content-column">
      <?php foreach ($field_elife_cc as $i => $field): ?>
        <li
          class="content-column__item content-column__item--<?php print $content['field_elife_cc'][$i]['entity']['field_collection_item'][$field['value']]['field_elife_cc_type']['#items'][0]['value'] ?>">
          <div
            class="content-column__type"><?php print $content['field_elife_cc'][$i]['entity']['field_collection_item'][$field['value']]['field_elife_cc_type'][0]['#markup'] ?></div>
          <a
            href="<?php print $content['field_elife_cc'][$i]['entity']['field_collection_item'][$field['value']]['field_elife_cc_link']['#items'][0]['display_url'] ?>"
            class="content-column__title">
            <?php print str_replace(':', ':<br>', $content['field_elife_cc'][$i]['entity']['field_collection_item'][$field['value']]['field_elife_cc_link']['#items'][0]['title']); ?>
          </a>
        </li>
      <?php endforeach; ?>
    </ol>
  <?php endif; ?>

</div>

