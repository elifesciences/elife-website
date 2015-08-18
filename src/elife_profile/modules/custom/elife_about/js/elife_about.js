/**
 * @file
 * Adds three behaviours to the About page.
 *
 * elifeAboutSectionScroll:
 *    Adds a scroll offset to allow for the height of the fixed nav (and a bit more)
 * when there is a hash in the location (either on page load or by clicking around
 * when already on the page.)
 *
 * elifeAboutNav:
 *    Controls the fixed top nav
 *
 * elifeAboutProfiles:
 *    Adds the behaviour to switch between profile sections and to display biographies
 * for people in an overlaid box underneath their photo.
 */

(function ($, window) {
  "use strict";
  Drupal.behaviors.elifeAboutSectionScroll = {
    attach: function () {
      Drupal.behaviors.elifeSectionScroll('elife-about-section-scroll');
    }
  };

  Drupal.behaviors.elifeAboutNav = {
    attach: function () {
      Drupal.behaviors.eLifeHeaderFloating($('.about-nav'), 'elife-about-nav');
    }
  };

  Drupal.behaviors.elifeAboutProfiles = {
    attach: function () {
      $('body').once('elife-about-profiles', function () {
        // Handles the setup for Aims and scope section.

        // Each list of people loaded from the subject menu is called a 'sheet'.
        // setupSheetDisplay controls display of these sheets.
        // It provides a function for toggling the display of a sheet.
        // The toggle function is used in two situations:
        //  - on page load the url hash is checked for a legitimate sheet id, and that sheet
        //      displayed; if there isn't a legitimate sheet id in the url hash, the
        //      leadership sheet is displayed by default.
        //  - by the event listener that setupSheetDisplay registers on the subject menu, to
        //      display sheet associated with a clicked-on menu item.
        var setupSheetDisplay = function () {

            /**
             * Given a prospective fragment id of a people listing, if it exists,
             * turn on the display of that listing, turn off the display of
             * all other, similar listings, and update the menu accordingly.
             * If it doesn't exist, do nothing.
             *
             * @param {string} id The id of the listing to show
             */
            var switchSheets = function (id) {
              var fragId = id,
                $frag;

              // normalise fragId to have exactly one leading # character
              if (fragId.indexOf('#') !== 0) {
                fragId = '#' + fragId;
              }

              $frag = $(fragId);

              // don't do anything if the fragment referenced by fragId doesn't exist,
              // or if the fragment is something we're not interested in
              if ($frag.length === 0 || !$frag.hasClass('aims-scope__people')) {
                return;
              }

              // turn all .aims-scope__people off...
              $('.aims-scope__people').not('.off').addClass('off');

              // ... before turning on the one we want...
              $($frag).removeClass('off');

              // ... and finally, updating the menu
              $('.aims-scope__subject_list_link', '#subjectNav').removeClass('active');
              $('#menu-' + fragId.substring(1, fragId.length)).addClass('active');
            };


            // Register event listener for displaying subject lists via the menu
            $('#subjectNav, #aboutNavEditorsLink').click(function (e) {
              var target = e.target,
                url = target.href,
                fragId = url.substring(url.indexOf('#') + 1, url.length);
              switchSheets(fragId);
            });

            // on page load, try to use any fragment id to display the respecctive
            // section. If there isn't one, display the first one by default.
            if($('.aims-scope__people').length) {
              switchSheets(window.location.hash || $('.aims-scope__people:first-of-type').attr('id'));
            }
          };

        setupSheetDisplay();

      });
    }
  };

})(jQuery, this);
