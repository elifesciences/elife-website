<?php

/**
 * @file
 * Override of simple view template to display a list of rows.
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <div<?php print ($classes_array[$id]) ? ' class="' . $classes_array[$id] .'"' : ''; ?>>
    <?php print $row; ?>
    <?php if ($contextual_node): ?>
      <?php print $contextual_node[$id]; ?>
    <?php endif; ?>
  </div>
<?php endforeach; ?>
