<?php

/**
 * @file
 * elife_entities/templates/elife_hero_block.tpl.php
 */

$id = preg_replace('/[^A-Za-z0-9 ]/', '', uniqid('', TRUE));

if (!empty($image_path)) {
  if (file_uri_scheme($image_path)) {
    $image_path = image_style_url('elife_hero_block', $image_path);
  }
  drupal_add_css(sprintf('.%s .hero-block__primary_content { background-image: url("%s") }', 'hero-block--' . $id, $image_path), array('type' => 'inline'));
}

if (empty($image_colour)) {
  $image_colour = empty($image_path) ? 'light' : 'dark';
}

?>

<div
  class="hero-block<?php if ('light' === $image_colour): ?> hero-block--light<?php endif; ?> hero-block--<?php print $id; ?>">
  <div class="hero-block__primary_content">
    <?php if (!empty($credit)): ?>
      <span class="hero-block__image_credit">
      <?php print $credit; ?>
    </span>
    <?php endif; ?>
    <h1 class="hero-block__title"><?php print $title; ?></h1>
    <?php if (!empty($sub_title)): ?>
      <h2 class="hero-block__sub_title">
        <?php print $sub_title; ?>
      </h2>
    <?php endif; ?>

    <?php if (!empty($cta_link_text) && !empty($cta_link_url)): ?>
      <div class="hero-block__cta cta">
        <?php if (!empty($cta_text)): ?>
          <span class="cta__text">
          <?php print $cta_text; ?>
        </span>
        <?php endif; ?>
        <a href="<?php print $cta_link_url; ?>" class="cta__link">
          <?php print $cta_link_text; ?>
        </a>
      </div>
    <?php endif; ?>

    <?php if (!empty($player)): ?>
      <div class="hero-block__player player">
        <audio controls <?php if ($player_autoplay): ?>autoplay<?php endif; ?> class="player__player">
          <source src="<?php print $player; ?>" type="audio/mpeg; codecs=mp3"/>
        </audio>
        <a href="<?php print $player; ?>" class="player__download">Download</a>
      </div>
    <?php endif; ?>
  </div>

  <?php if (!empty($content_column_items)): ?>
    <ol class="hero-block__content-column content-column">
      <?php foreach ($content_column_items as $i => $content_column_item): ?>
        <li
          class="content-column__item content-column__item--<?php print strtolower($content_column_item['type']); ?>">
          <div
            class="content-column__type"><?php print $content_column_item['type']; ?></div>
          <a href="<?php print $content_column_item['url'] ?>"
             class="content-column__title">
            <?php print str_replace(':', ':<br>', $content_column_item['text']); ?>
          </a>
        </li>
      <?php endforeach; ?>
    </ol>
  <?php endif; ?>

</div>
