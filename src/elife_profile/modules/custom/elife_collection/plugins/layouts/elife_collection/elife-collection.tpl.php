<?php

/**
 * @file
 * eLife: Collection Panels Layout.
 */

?>

<article>

  <?php if (!empty($content['hero_block'])): ?>
    <header class="elife-collection__hero-block">
      <?php print $content['hero_block']; ?>
    </header>
  <?php endif; ?>

  <?php if (!empty($content['content'])): ?>
    <section class="elife-collection__content<?php if (empty($content['sidebar'])): print ' elife-collection__content--full'; endif; ?>">
      <?php print $content['content']; ?>
    </section>
  <?php endif; ?>

  <?php if (!empty($content['sidebar'])): ?>
    <aside class="elife-collection__sidebar">
      <?php print $content['sidebar']; ?>
    </aside>
  <?php endif; ?>

</article>
