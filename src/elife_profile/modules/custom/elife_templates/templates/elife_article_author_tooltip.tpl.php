<?php

/**
 * @file
 * elife_templates/templates/elife_article_author_tooltip.tpl.php
 */
?>
<div class="author-tooltip">
  <div class="author-tooltip-name"><?php print $tooltip_name; ?></div>
  <?php if ($affiliation): ?>
    <div class="author-tooltip-affiliation"><span class="author-tooltip-text"><?php print $affiliation; ?></span></div>
  <?php endif; ?>
  <?php if ($present_addy): ?>
    <div class="author-tooltip-present-address"><span class="author-tooltip-label"><?php print t('Present address'); ?>: </span><span class="author-tooltip-text"><p><?php print $present_addy; ?></p></span></div>
  <?php endif; ?>
  <?php if ($contrib): ?>
    <div class="author-tooltip-contrib"><span class="author-tooltip-label"><?php print t('Contribution'); ?>: </span><span class="author-tooltip-text"><?php print $contrib; ?></span></div>
  <?php endif; ?>
  <?php if ($tooltip_authors_listed): ?>
    <span class="author-tooltip-label"><?php print t('Listed in alphabetical order with'); ?>:</span>
    <p><?php print $tooltip_authors_listed; ?></p>
  <?php endif; ?>
  <?php if ($email): ?>
    <div class="author-tooltip-corresp"><span class="author-tooltip-label"><?php print t('For correspondence'); ?>: </span><span class="author-tooltip-text"><?php print l($email, 'mailto:' . $email, array('absolute' => TRUE)); ?></span></div>
  <?php endif; ?>
  <?php if ($orcid): ?>
    <div class="author-tooltip-orcid"><span class="author-tooltip-label"><?php print $orcid_image; ?>: </span><span class="author-tooltip-text"><?php print $orcid; ?></span></div>
  <?php endif; ?>
  <?php if ($conflict): ?>
    <div class="author-tooltip-conflict"><span class="author-tooltip-label"><?php print t('Competing Interests'); ?>: </span><span class="author-tooltip-text"><?php print $conflict; ?></span></div>
  <?php else: ?>
    <div class="author-tooltip-conflict"><span class="author-tooltip-text"><i><?php print t('No competing interests declared'); ?></i></span></div>
  <?php endif; ?>
  <?php if ($equal_contrib_group): ?>
    <div class="author-tooltip-equal-contrib"><span class="author-tooltip-label"><?php print t('Contributed equally with'); ?>: </span><span class="author-tooltip-text"><?php print $equal_contrib_group; ?></span></div>
  <?php endif; ?>
  <?php if ($deceased): ?>
    <?php print $deceased; ?>
  <?php endif; ?>
</div>
