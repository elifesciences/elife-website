<?php
/**
 * @file
 * templates/elife_front_matter.tpl.php
 */
?>
<!-- pattern start: headlines-secondary -->
<div class="headlines-secondary__item headlines-secondary__item--<?php print $display; ?> headlines-secondary__item_type--<?php print $section; ?>">
  <?php if ($image): ?>
  <?php print $image; ?>
  <?php endif; ?>
  <!--div class="headlines-secondary__item_type headlines-secondary__item_type--<?php print $section; ?>"><?php print $section_name; ?></div -->
  <div class="headlines-secondary__item_type"><?php print $section_name; ?></div>
  <?php print $title; ?>
</div>
<!-- pattern end: headlines-secondary -->
