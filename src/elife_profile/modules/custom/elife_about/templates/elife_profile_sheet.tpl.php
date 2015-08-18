<?php
/**
 * @file
 * templates/elife_profile_regular.tpl.php
 */
?>
<section
  class="aims-scope__people aims-scope__people--<?php print $sheet_id; ?>"
  id="<?php print $sheet_id; ?>">
  <h4 class="aims-scope__people_heading"><?php print $sheet_title; ?></h4>
  <?php foreach ($sections as $section): ?>
    <?php if (!empty($section['profiles'])): ?>
      <?php if (!empty($section['title'])): ?>
        <h5
          class="aims-scope__people_sub_heading<?php if ($section['title_id']): print ' aims-scope__people_sub_heading--' . $section['title_id']; endif; ?>">
          <?php print $section['title']; ?>
        </h5>
      <?php endif; ?>
      <?php print $section['profiles']; ?>
    <?php endif; ?>
  <?php endforeach; ?>
</section>
