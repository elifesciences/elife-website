<?php
/**
 * @file
 * templates/elife_footer.tpl.php
 */
?>
<div class="site-footer">
  <section class="site-footer__funders">
    <div class="site-footer__funders__inner">
      <span class="site-footer__funders_intro">
        <?php print t('eLife is supported by'); ?>
      </span>
      <span class="site-footer__funder_img">
      <?php print theme_image(array(
        'path' => drupal_get_path('module', 'elife_footer') . '/images/Funder_logos_2014_106.png',
        'alt' => t('eLife funder logos'),
        'attributes' => array(),
      )); ?>
      </span>

    </div>
  </section><!-- /.site-footer__funders -->
  <section class="site-footer__main">
    <section class="site-footer__text_and_links">
      <div class="site-footer__identity">
        <?php print theme_image(array(
          'path' => drupal_get_path('module', 'elife_footer') . '/images/eLife-logo.png',
          'alt' => t('eLife visual identity'),
          'attributes' => array(),
        )); ?>
      </div>
      <div class="h-card vcard">
        <?php if ($details): ?>
          <p class="site-footer__statement_text">
            <?php print $details; ?>
          </p>
        <?php endif; ?>
        <?php if ($company_info): ?>
          <p class="site-footer__company-info">
            <?php print $company_info; ?>
          </p>
        <?php endif; ?>
        <address class="site-footer__address">
          <div class="p-name fn"><?php print $address_fn; ?></div>
          <div class="p-street-address street-address"><?php print $address_ln1; ?></div>
          <div><span class="p-locality locality"><?php print $address_loc; ?></span>
            <span class="p-postal-code postal-code"><?php print $address_pc; ?></span>
          </div>
          <div class="p-country-name country-name"><?php print $address_cn; ?></div>
        </address>
      </div> <!-- /.h-card /.v-card-->
    </section> <!-- /.site-footer__text_and_links -->

    <section class="site-footer__social">
      <h2 class="site-footer__social_heading"><?php print t('Follow us'); ?></h2>
      <?php print $social_links; ?>
    </section> <!-- /.site_footer__social -->

    <section class="site-footer__links">
      <?php print $misc_links; ?>
      <?php print $section_links; ?>
    </section> <!-- /.site-footer__links -->
  </section>

  <section class="site-footer__copyright-line">
    <?php print t('&copy; @date eLife Sciences Publications Ltd. Subject to a !cc_license, except where otherwise noted. ISSN: 2050-084X',
      array(
        '@date' => date('Y'),
        '!cc_license' => l(t('Creative Commons Attribution license'),
          'http://creativecommons.org/licenses/by/4.0/',
          array('external' => TRUE)))); ?>
  </section>
</div>
