<?php

/**
 * @file
 * templates/elife_article_detail.tpl.php
 */
?>
<?php if ($image): ?>
  <?php print $image; ?>
<?php endif; ?>

<?php if ($summary): ?>
<div class="<?php print $identifier; ?>__summary"><?php print $summary; ?></div>
<?php endif; ?>

<?php print $author; ?>
<?php if ($doi || $date): ?>
<div class="<?php print $identifier; ?>__doi">
  <?php print $doi; ?>
  <?php if ($date): ?>
    <time class="<?php print $identifier; ?>__date"<?php print ($date_machine) ? ' datetime="' . $date_machine . '"' : ''; ?>><?php print $date; ?></time>
  <?php endif; ?>
</div>
<?php endif; ?>
