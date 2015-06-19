<?php

/**
 * @file
 * elife_entities/templates/elife_article.tpl.php
 */
?>
<article class="<?php print $identifier; ?><?php print ($section_id) ? ' ' . $identifier . '--' . $section_id : ''; ?>">
  <?php print $section; ?>
  <h3 class="<?php print $identifier; ?>__heading"><?php print $title; ?></h3>
  <?php print $detail; ?>
</article>
