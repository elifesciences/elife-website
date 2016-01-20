<?php
/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <<?php print $group_element; ?><?php print drupal_attributes($group_attributes); ?> style="margin-right: 20px; float: left;"><a style="color: #0961AB; text-decoration: none" href="#<?php print strtolower(preg_replace('/[^a-zA-Z0-9-]+/', '-', $title)); ?>">
    <?php print $title; ?>
  </<?php print $group_element; ?>>
<?php endif; ?>
