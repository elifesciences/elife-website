<?php if ($wrapper): ?><div<?php print $attributes; ?>><?php endif; ?>  
  <div<?php print $content_attributes; ?>>    
		<?php if ($messages): ?>
      <div id="messages" class="grid-<?php print ($columns - 2); ?> push-2"><?php print $messages; ?></div>
    <?php endif; ?>
    <?php print $content; ?>
  </div>
<?php if ($wrapper): ?></div><?php endif; ?>