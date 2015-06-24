<?php
/**
 * @file
 * templates/elife_front_matter_wrapper.tpl.php
 */
?>
<a href="#research-articles" class="articles-jump-link"><?php print t('Go to research articles'); ?></a>
<ol class="frontmatter">
  <?php if ($cover): ?>
  <li>
    <?php print $cover; ?>
  </li>
  <?php endif; ?>
  <?php if ($front_matter_col_1 || $front_matter_col_2): ?>
  <li class="headlines-secondary-wrapper">
    <?php if ($front_matter_col_1): ?>
    <?php print $front_matter_col_1; ?>
    <?php endif; ?>
    <?php if ($front_matter_col_2): ?>
      <?php print $front_matter_col_2; ?>
    <?php endif; ?>
  </li>
  <?php endif; ?>
</ol>
