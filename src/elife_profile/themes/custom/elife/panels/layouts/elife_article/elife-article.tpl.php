<?php
/**
 * @file
 * eLife Article Layout
 *
 * Copyright (c) 2010-2011 Board of Trustees, Leland Stanford Jr. University
 * This software is open-source licensed under the GNU Public License Version 2 or later
 * The full license is available in the LICENSE.TXT file at the root of this repository
 */
?>
<div class="panel-display panels-960-layout elife-article-layout" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="panel-row-wrapper panel-row-first clearfix">
  
  <?php if (!$content['side_top'] && !$content['side_bottom']): ?>
  	<div class="top-wrapper grid-30 alpha omega">
  <?php else: ?>
  	<div class="top-wrapper grid-21 suffix-9 alpha omega">
  <?php endif; ?>
			<?php if ($content['top']): ?>
	  		<div class="panel-panel panel-region-content-top">
	  			<div class="inside"><?php print $content['top']; ?></div>
	  		</div>
  		<?php endif; ?>
  	</div>
  
  </div>
  
  <div class="panel-row-wrapper panel-row-last clearfix">
		
		<?php if (!$content['side_top'] && !$content['side_bottom']): ?>
	  	<div class="main-wrapper grid-30 alpha omega">
	  <?php else: ?>
	  	<div class="main-wrapper grid-21 alpha">
	  <?php endif; ?>
			<?php if ($content['main']): ?>
				<div class="panel-panel panel-region-main-content">
				  <div class="inside"><?php print $content['main']; ?></div>
				</div>
			<?php endif; ?>
		</div>	
		
		<?php if ($content['side_top'] || $content['side_bottom'] || $content['side_lens'] || $content['side_link']): ?>
			<div class="sidebar-wrapper grid-9 omega">
        <?php if ($content['side_link']): ?>
          <div class="panel-panel panel-region-sidebar-link">
            <?php print $content['side_link']; ?>
          </div>
        <?php endif; ?>
				<?php if ($content['side_top']): ?>
				  <div class="panel-panel panel-region-sidebar-top">
				    <div class="inside"><?php print $content['side_top']; ?></div>
				  </div>
				<?php endif; ?>
				<?php if ($content['side_bottom']): ?>
					<div class="panel-panel panel-region-sidebar-bottom" id="article-jumplinks-anchor-region">
				    <div class="inside"><?php print $content['side_bottom']; ?></div>
				  </div>
			  <?php endif; ?>
			</div>
		<?php endif; ?>
		
	</div>
</div>

