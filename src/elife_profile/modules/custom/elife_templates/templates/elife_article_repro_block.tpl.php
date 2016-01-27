<?php

/**
 * @file
 * templates/elife_article_repro_block.tpl.php
 */
?>
<!-- pattern: repro-study-item -->
<article class="repro-study-item<?php print ($identifier) ? ' repro-study-item--' . $identifier : ''; ?>">
  <div class="repro-study-item__inner">
    <h4 class="repro-study-item__type">
      <?php print $title; ?>
    </h4>
    <?php if ($date): ?>
    <time class="repro-study-item__date"<?php print ($date_machine) ? ' datetime="' . $date_machine . '"' : ''; ?>><?php print $date; ?></time>
    <?php endif; ?>
    <?php print $details; ?>
  </div>
</article>
<!-- / pattern: repro-study-item -->
