/**
 * @file
 * Adds behaviours to the Early careers page.
 */

(function ($, window) {
  "use strict";
  Drupal.behaviors.elifeEarlyCareersSectionScroll = {
    attach: function () {
      Drupal.behaviors.elifeSectionScroll('elife-ec-section-scroll');
    }
  };

  Drupal.behaviors.elifeEarlyCareersNav = {
    attach: function () {
      Drupal.behaviors.eLifeHeaderFloating($('.ec-nav'), 'elife-ec-nav');
    }
  };

})(jQuery, this);
