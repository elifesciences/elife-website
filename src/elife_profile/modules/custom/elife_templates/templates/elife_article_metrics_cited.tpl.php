<?php
/**
 * @file
 * Template for the eLife providers list on the article metrics page.
 */

?>
<div id="metrics_cited">
<div class="via"><?php echo $via; ?></div>
<?php
  foreach ($providers_list as $pro_matric => $provider_list):
    $prov_name_div = ($pro_matric == 'discussed') ? t('Discussed') : t('Saved and cited');
?>
  <div id="<?php echo $pro_matric; ?>">
    <h2 class="pane-title provider"><?php print $prov_name_div; ?></h2>
    <?php echo $variables[$pro_matric]['list']; ?>
  </div>
<?php endforeach; ?>
</div>
