<?php

/**
 * @file
 * Override of simple view template to display a list of rows.
 * This specific template is used for content alerts.
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <div<?php print ($classes_array[$id]) ? ' class="' . $classes_array[$id] .'"' : ''; ?>>
    <?php print $row; ?>
  </div>
<?php endforeach; ?>
