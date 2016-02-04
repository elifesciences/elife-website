<p style="font-size: 14px; line-height: 22px; margin: 10px 0;">
<a href="<?php print $url; ?>" style="color: #0961AB; text-decoration: none;"><?php print $title; ?></a><br>
<?php if ($contributors): ?>
<span style="font-size: 12px; line-height: 18px; margin-top: 0; display: block">
<?php print $contributors; ?>
</span>
<?php endif; ?>
<?php if ($impact_statement): ?>
<span class="author-impact-statement" style="font-size: 11px; line-height: 18px; display: block; margin-top: 5px;">
<?php print $impact_statement; ?>
</span>
<?php endif; ?>
<?php if ($related): ?>
<span class="author-impact-statement" style="font-size: 11px; line-height: 18px; display: block; margin-top: 5px;">
<?php print $related; ?>
</span>
<?php endif; ?>
</p>
