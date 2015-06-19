<?php

/**
 * @file
 * elife_entities/templates/elife_hero.tpl.php
 */
?>
<section class="hero-image-page-intro<?php print ($identifier) ? ' hero-image-page-intro--' . $identifier : ''; ?>">
  <div class="hero-image-page-intro__image_container"></div>
  <div class="hero-image-page-intro__outer">
    <h1 class="hero-image-page-intro__heading">
      <?php if ($title_detail): ?>
        <span class="hero-image-page-intro__heading_detail"><?php print $title_detail; ?></span>
      <?php endif; ?>
      <?php print $title; ?>
    </h1>
    <?php if ($body || $details): ?>
    <div class="hero-image-page-intro__inner">
      <?php if ($body): ?>
      <div class="hero-image-page-intro__text"><?php print $body; ?></div>
      <?php endif; ?>
      <?php print $details; ?>
    </div> <!-- /.hero-image-page-intro__inner -->
    <?php endif; ?>
  </div> <!-- /.hero-image-page-intro__outer -->
</section>
