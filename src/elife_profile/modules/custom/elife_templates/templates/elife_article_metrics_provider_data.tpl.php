<?php
/**
 * @file
 * Template for an individual eLife provider on the article metrics page.
 */
?>
<div>
  <span class="provider-icon"><?php echo $variables['icon']; ?></span>
  <span class="provider-name"><?php echo $variables['name_link']; ?></span>
  <div class="provider-details">
    <?php if (array_key_exists('value', $variables)): ?>
        <span class="metric-value"><?php echo $variables['value']; ?></span>
    <?php endif; ?>
    <span class="metric-name"><?php echo $variables['class_link']; ?></span>
  </div>
</div>
