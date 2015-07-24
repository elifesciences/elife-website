<?php

/**
 * @file
 * elife_article_criticalrelation_block.tpl.php
 *
 * Variables:
 *  reln_type_id : relation type CSS id
 *  reln_type : relation type CSS tag
 *  reln_title : relation title
 *  criticalrelations : blocks for each critical relation of this type
 */
?>
<section<?php print ($reln_type_id) ? ' id="' . $reln_type_id . '"' : ''; ?> class="<?php print $identifier; ?><?php print ($reln_type) ? ' ' . $identifier . '--' . $reln_type : ''; ?> ctools-collapsible-container">
  <h2 class="<?php print $identifier; ?>__type pane-title ctools-collapsible-handle"><?php print $reln_title; ?></h2>
  <div class="ctools-collapsible-content">
    <div class="highwire-markup">
      <div class="section inner">
        <?php print theme('item_list', array('items' => $criticalrelations, 'type' => 'ol', 'div_class' => 'no', 'attributes' => array('class' => $list_class))); ?>
      </div>
    </div>
  </div>
</section>
