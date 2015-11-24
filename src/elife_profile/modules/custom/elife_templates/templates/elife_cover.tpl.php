<?php
/**
 * @file
 * templates/elife_cover.tpl.php
 */

if (!empty($image_path)) {
  drupal_add_css('.headline-first--has-image {background-image:url("' . $image_path_mcr . '");} @media only all and (min-width: 26em) {.headline-first--has-image {background-image:url(' . $image_path_sml . ');}} @media only all and (min-width: 55em) {.headline-first--has-image {background-image:url(' . $image_path . ');}}', ['type' => 'inline']);
}

?>
<div class="headline-first-wrapper">
  <div class="headline-first<?php print (($additional_classes) ? ' ' . implode(' ', $additional_classes) : ''); ?>">
    <div class="headline-first__text_wrapper">
      <?php print $title; ?>
      <?php print $read_more; ?>
      <?php if ($caption): ?>
      <div class="headline-first__pic_credit"><?php print $caption; ?></div>
      <?php endif; ?>
    </div> <!-- /.headline-first__text_wrapper -->
  </div>
</div> <!-- /.headline-first-wrapper -->
