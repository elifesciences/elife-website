<?php
/**
 * @file
 * templates/elife_header.tpl.php
 */
?>
<div class="page_header" role="banner">
  <?php print $identity; ?>
  <nav class="header__nav">
    <?php print $header_li; ?>
    <?php if ($header_li_section || $header_li_category): ?>
    <ul>
      <li class="header__list_secondary">
        <?php print $header_li_section; ?>
        <?php print $header_li_category; ?>
      </li> <!-- /.header__list_secondary -->
    </ul>
    <?php endif; ?>
  </nav>
</div>
