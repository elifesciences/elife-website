<div<?php print $attributes; ?>>
  <div<?php print $content_attributes; ?>>
  	<?php if (isset($breadcrumb) && $breadcrumb !== ''): ?>
      <div id="breadcrumb"><?php print $breadcrumb; ?></div>
    <?php endif; ?> 
    <?php print $content; ?>
  </div>
</div>