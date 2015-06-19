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
<div class="panel-display panels-960-layout elife-home-layout" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="panel-row-wrapper panel-row-first clearfix equal-height-container">
  
		<?php if ($content['top_main']): ?>
  		<div class="panel-panel panel-region-top-main grid-21 alpha equal-height-element">
  			<div class="bg-container bg-bottom"></div>
  			<div class="bg-container bg-top"></div>
  			<div class="inside"><?php print $content['top_main']; ?></div>
  		</div>
		<?php endif; ?>
  	
		<?php if ($content['top_side_first'] || $content['top_side_second'] || $content['top_side_third']): ?>
  		<div class="top-side-wrapper grid-9 omega equal-height-element equal-height-container">
				<?php if ($content['top_side_first']): ?>
					<div class="panel-panel panel-region-top-side-first equal-height-element">
		  			<div class="inside">
							<?php print $content['top_side_first']; ?>
						</div>
					</div>
				<?php endif; ?>
				
				<?php if ($content['top_side_second']): ?>
					<div class="panel-panel panel-region-top-side-second equal-height-element">
		  			<div class="inside">
							<?php print $content['top_side_second']; ?>
						</div>
					</div>
				<?php endif; ?>
  			
  			<?php if ($content['top_side_third']): ?>
					<div class="panel-panel panel-region-top-side-third ctools-toggle-region">
		  			<div class="inside">
							<?php print $content['top_side_third']; ?>
						</div>
						<div class="arrow"></div>
					</div>
				<?php endif; ?>
  				
  		</div>
		<?php endif; ?>
  
  </div>
  
  <div class="panel-row-wrapper elife-home-middle clearfix">
  	
  	<div class="middle-wrapper grid-30 alpha omega">
			<?php if ($content['middle']): ?>
	  		<div class="panel-panel panel-region-middle panel-region-collapsible">
	  			<div class="inside"><?php print $content['middle']; ?></div>
	  		</div>
  		<?php endif; ?>
  	</div>
  	
  </div>
  
  <div class="panel-row-wrapper panel-row-last clearfix equal-height-container">
		
		<?php if ($content['bottom_first']): ?>
  		<div class="panel-panel panel-region-bottom-first grid-11 alpha equal-height-element">
  			<div class="inside"><?php print $content['bottom_first']; ?></div>
  		</div>
		<?php endif; ?>
		
		<?php if ($content['bottom_second']): ?>
  		<div class="panel-panel panel-region-bottom-second grid-10 equal-height-element">
  			<div class="inside"><?php print $content['bottom_second']; ?></div>
  		</div>
		<?php endif; ?>
  	
		<?php if ($content['bottom_third']): ?>
  		<div class="panel-panel panel-region-bottom-third grid-9 omega equal-height-element">
  			<div class="inside"><?php print $content['bottom_third']; ?></div>
  		</div>
		<?php endif; ?>
		
	</div>
</div>

