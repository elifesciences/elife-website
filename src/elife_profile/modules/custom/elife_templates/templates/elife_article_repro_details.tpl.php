<?php

/**
 * @file
 * elife_entities/templates/elife_article_repro_details.tpl.php
 */
?>
<section class="repro-study-item__bib_details">
  <?php print $author; ?>
  <?php if ($source): ?>
  <div class="repro-study-item__bib_details__source"><?php print $source; ?></div>
  <?php endif; ?>
  <?php if ($doi): ?>
  <div class="repro-study-item__bib_details__doi"><?php print $doi; ?></div>
  <?php endif; ?>
</section>
