<?php

/**
 * @file
 * elife_article_criticalrelation.tpl.php
 *
 * Variables:
 *  other_title : the title of the article linked to, with any prefix.
 *  other_authors : plain-text list of authors for the article
 *  other_citeas : 'cite as' html (includes italics)
 *  other_doi_link : anchor html for the DOI : <a href="http://dx.doi ..... </a>
 */
?>
<h3 class="<?php print $identifier; ?>__title"><?php print $other_title; ?></h3>
<section class="<?php print $identifier; ?>__bib_details">
  <?php print $other_authors; ?>
  <?php if ($other_impact_statement): ?>
    <div class="<?php print $identifier; ?>__bib_details__impact_statement">
      <?php print $other_impact_statement; ?>
    </div>
  <?php endif; ?>
  <div class="<?php print $identifier; ?>__bib_details__source"><?php print $other_citeas; ?></div>
  <div class="<?php print $identifier; ?>__bib_details__doi"><?php print t('DOI'); ?>: <?php print $other_doi_link; ?></div>
</section>
