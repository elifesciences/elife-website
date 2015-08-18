<?php
/**
 * @file
 * templates/elife_early_careers_profile_extra.tpl.php
 */
?>
<section class="ec-profiles__person_biog">
  <h5 class="ec-profiles__person_biog_title"><?php print $title; ?></h5>
  <?php if ($image_extra): ?>
    <?php print $image_extra; ?>
  <?php endif; ?>
  <p class="ec-profiles__person_biog_details"><?php print $details; ?></p>
</section>
<?php if ($additional): ?>
<section class="ec-profiles__person_competing">
  <?php if ($additional_label): ?>
  <h6 class="ec-profiles__person_competing_title"><?php print $additional_label; ?></h6>
  <?php endif; ?>
  <p class="ec-profiles__person_competing_text">
    <?php print $additional; ?>
  </p>
</section>
<?php endif; ?>
