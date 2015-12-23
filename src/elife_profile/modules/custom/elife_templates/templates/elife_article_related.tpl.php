<?php

/**
 * @file
 * templates/elife_article_related.tpl.php
 */
?>
<div class="elife-article-citation elife-citation-type-elife-article">
  <article class="elife-cite elife-citation-elife-small">
    <div class="elife-cite-title"><cite><?php print $title; ?></cite></div>
    <?php if ($authors): ?>
    <div class="elife-cite-authors"><?php print $authors; ?></div>
    <?php endif; ?>
    <?php if ($cats_and_heads): ?>
    <div class="elife-cite-categories"><?php print $cats_and_heads; ?></div>
    <?php endif; ?>
  </article>
</div>