<?php
/**
 * @file
 * panels/layouts/elife_omega_coverpage/elife_omega_coverpage.tpl.php
 */
?>
<div class="panel-display omega-grid"<?php print (!empty($css_id)) ? " id=\"$css_id\"" : ''; ?>>

  <section class="site-header">
    <?php print $content['top']; ?>
  </section><!-- /.site-header -->

  <?php print $content['banner']; ?>

  <div class="home-listings-wrapper">
    <section class="home-listings" id="research-articles">
    <h2 class="home-listings__heading"><?php print t('Latest research'); ?></h2>
      <nav id="listings" role="navigation" class="home-listings__list">
        <?php print $content['nav']; ?>
      </nav>
      <section class="home-article-listing-wrapper">
        <?php print $content['middle']; ?>
        <a href="<?php print url('browse'); ?>" class="home-article-listing__more_articles"><?php print t('More articles'); ?></a>
      </section> <!-- /.home-article-listing-wrapper -->
    </section><!-- /.home-listings -->
  </div><!-- /.home-listings-wrapper -->

  <?php if ($content['action']): ?>
  <section class="home-cta">
    <?php print $content['action']; ?>
  </section><!-- /.home-cta -->
  <?php endif; ?>

  <?php if ($content['bottom']): ?>
  <section class="home-bottom">
    <?php print $content['bottom']; ?>
  </section><!-- /.home-bottom -->
  <?php endif; ?>
</div>
