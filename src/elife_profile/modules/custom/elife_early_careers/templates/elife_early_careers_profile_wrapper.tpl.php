<?php
/**
 * @file
 * templates/elife_early_careers_profile_wrapper.tpl.php
 */
?>
<article class="ec-profiles" id="advisory-group">
  <header class="ec-profiles__header">
    <div class="ec-profiles__would-be-hgroup">
      <h2 class="ec-profiles__main_heading">The eLife early-career advisory group</h2>
      <p class="ec-profiles__stand_first">eLife has invited a group of junior investigators to help guide the direction of the journal and to help us re-shape science publishing. The early-career advisory group includes graduate students, post-docs, and junior group leaders from laboratories across the world.</p>
    </div>
  </header>
  <?php if (!empty($profiles)): ?>
  <section class="ec-profiles__people">
    <?php print $profiles; ?>
  </section>
  <?php endif; ?>
  <footer class="ec-profiles__footer">
    <p class="ec-profiles__footer_text">The advisory group is invited by the eLife executive. <a href="#share-your-voice">We want your input, too</a>.</p>
  </footer>
</article>
