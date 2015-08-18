<?php
/**
 * @file
 * templates/elife_early_careers_spotlight.tpl.php
 */
?>
<article class="ec-section--latest__item">
  <div class="ec-section--latest__item_body">
    <?php if ($section_heading): ?>
    <h2 class="ec-section__heading"><?php print $section_heading; ?></h2>
    <?php endif; ?>
    <h3 class="ec-section--latest__item_title"><?php print $title; ?></h3>
    <?php if ($body): ?>
    <div class="ec-section--latest__item_text"><?php print $body; ?></div>
    <?php endif; ?>
  </div>
  <?php print $view_more; ?>
</article>
