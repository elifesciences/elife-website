<section class="home-cta__publish">
  <img class="home-cta__publish_image"
       src="<?php print drupal_get_path('module', 'elife_front_matter'); ?>/images/randy-portrait-sml.png"
       alt="<?php print $imagealt; ?>">

  <h2 class="home-cta__heading home-cta__heading--publish">
    <?php print $title; ?>
  </h2>

  <p class="home-cta__text home-cta__text--publish"><?php print $caption; ?></p>

  <a href="/about" class="home-cta__link"><?php print $read_more; ?></a>

</section>

<section class="home-cta__sign_up">
  <h2 class="home-cta__heading home-cta__heading--sign-up">
    <?php print $getelife_title; ?>
  </h2>

  <p class="home-cta__text home-cta__text--sign-up">
    <?php print $getelife_text; ?>
  </p>

  <?php print $sign_up_form; ?>

</section>
