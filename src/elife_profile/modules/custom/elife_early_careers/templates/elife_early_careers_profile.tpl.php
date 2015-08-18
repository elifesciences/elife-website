<?php
/**
 * @file
 * templates/elife_early_careers_profile.tpl.php
 */
?>
<div<?php print $profile_attributes; ?>>
  <?php if ($image_extra): ?>
    <figure class="ec-profiles__person_link">
      <figcaption class="ec-profiles__person_figure_caption">
        <h5 class="ec-profiles__person_figure_caption_name p-name fn"><?php print $title; ?></h5>
        <?php if ($profile_title): ?>
          <p class="ec-profiles__person_figure_caption_suppl role"><?php print $profile_title; ?></p>
        <?php endif; ?>
        <?php if ($affiliation): ?>
          <p class="ec-profiles__person_figure_caption_suppl p-org org"><?php print $affiliation; ?></p>
        <?php endif; ?>
      </figcaption>
    </figure>
  <?php else: ?>
    <h5 class="p-name fn"><?php print $title; ?></h5>
    <?php if ($profile_title): ?>
      <p class="ec-profiles__person_suppl role"><?php print $profile_title; ?></p>
    <?php endif; ?>
    <?php if ($affiliation): ?>
      <div class="ec-profiles__person_suppl p-org org"><?php print $affiliation; ?></div>
    <?php endif; ?>
  <?php endif; ?>
</div>

<?php if ($profile_extra): ?>
  <div class="<?php print ($coi) ? 'ec-profiles__person_biog_outer' : 'ec-profiles__person_biog_outer--no-coi'; ?>">
    <div class="ec-profiles__person_biog_wrapper">
      <?php print $profile_extra; ?>
    </div>
  </div>
<?php endif; ?>
