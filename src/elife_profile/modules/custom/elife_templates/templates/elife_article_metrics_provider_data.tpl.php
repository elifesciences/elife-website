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
    <span class="metric-value"><?php echo $variables['value']; ?></span>
    <span class="metric-name"><?php echo $variables['class_link']; ?></span>
  </div>
</div>
