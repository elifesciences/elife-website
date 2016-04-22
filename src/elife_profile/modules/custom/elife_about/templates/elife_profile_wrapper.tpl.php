<?php
/**
 * @file
 * templates/elife_profile_wrapper.tpl.php
 */
?>
<article class="aims-scope" id="aims-and-scope">
  <header class="aims-scope__header">
    <div class="aims-scope__would-be-hgroup">
      <h2 class="aims-scope__main_heading">Aims &amp; scope</h2>

      <p class="aims-scope__stand_first"><i>eLife</i> publishes outstanding
        research in the life sciences and biomedicine, from the most fundamental
        and theoretical work, through to translational, applied, and clinical
        research.
        Our <?php if ($senior_editors_count > 1): print $senior_editors_count; endif; ?>
        Senior editors and
        <?php if ($bre_count > 1): print $bre_count . '-member'; endif; ?> Board
        of Reviewing Editors are among the most respected and accomplished
        individuals in their fields &ndash; from human genetics and neuroscience
        to biophysics and epidemiology. Where necessary, our Senior editors will 
        also consult with external guest editors to evaluate new submissions.</p>
    </div>
  </header>
  <section class="aims-scope__people_subjects" id="people">
    <nav class="aims-scope__subject_list" id="subjectNav">
      <?php print $menu; ?>
    </nav>
    <?php print $leadership; ?>
    <?php print $regular; ?>
  </section>
</article>
