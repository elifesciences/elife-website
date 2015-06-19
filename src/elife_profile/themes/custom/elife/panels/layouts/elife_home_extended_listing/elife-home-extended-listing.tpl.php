<?php
/**
 * @file
 * eLife Home Layout
 */
?>
<div class="panel-display panels-960-layout elife-home-layout equal-height-container" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

    <!-- Narrow view: appears in source order
         Wide view: Float to top right -->
    <div class="home-section-high grid-9 omega">
        <div class="equal-height-container equal-height-element">
            <?php if ($content['top_side_first_new']): ?>
            <!-- Search box -->
            <div class="panel-panel equal-height-element">
                <div class="inside">
                    <h2 class="pane-title not-on-narrow"><?php print t('Search eLife') ?></h2>
                    <?php print $content['top_side_first_new']; ?>
                </div>
            </div>
            <?php endif; ?>


            <?php if ($content['top_side_second_new']): ?>
            <!-- alerts signup -->
            <div class="panel-panel equal-height-element">
                <div class="inside"><?php print $content['top_side_second_new']; ?></div>
            </div>
            <?php endif; ?>


            <?php if ($content['top_side_third_new']): ?>
            <!-- subject categories toggle -->
            <div class="panel-panel ctools-toggle-region">
                <div class="inside"><?php print $content['top_side_third_new']; ?></div>
                <div class="above-subject-list-spacer"></div> <!-- BEWARE: presentational markup!  -->
            </div>
            <?php endif; ?>
        </div> <!-- /.equal-height-container -->

        <!-- subject categories listing -->
        <div class="panel-panel panel-row-wrapper elife-home-middle clearfix">
            <div class="">
                <div class="panel-panel panel-region-middle panel-region-collapsible">
                    <div class="inside"><?php print $content['middle_new']; ?></div>
                </div>
            </div>
        </div> <!-- /.elife-home-middle -->
    </div> <!-- /.home-section-high -->



    <!-- Narrow view: appears in source order
         Wide view: float to top left-->
    <div class="home-section-medium grid-21 alpha equal-height-element">
        <?php if ($content['top_main_new']): ?>
        <!-- Editors' choice -->
        <div class="panel-panel panel-region-top-main home-ed-choice">
            <div class="bg-container bg-bottom"></div>
            <div class="bg-container bg-top"></div>
            <div class="inside"><?php print $content['top_main_new']; ?></div>
        </div> <!-- /.home-ed-choice -->
        <?php endif; ?>

        <?php if ($content['bottom_first_new']): ?>
        <!-- article listing -->
        <div class="home-article-listing-wrapper">
            <div class="panel-panel">
                <div class="inside"><?php print $content['bottom_first_new']; ?></div>
            </div> <!-- / .home-article-listing-wrapper -->
        </div>
        <?php endif; ?>
    </div> <!-- /.home-section-medium -->



    <!-- Narrow view: appears in source order
         Wide view: float to bottom right-->

    <div class="home-section-low grid-9 omega"> <!-- float right -->
        <?php if ($content['bottom_third_new']): ?>
        <!-- Learn more & funders info -->
        <div class="panel-panel panel-region-bottom-third alpha omega">
            <div class="inside"><?php print $content['bottom_third_new']; ?></div>
        </div>
        <?php endif; ?>
    </div> <!-- / .home-section-low -->


</div> <!-- /.panels-960-layout -->
