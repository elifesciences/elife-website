/**
 * @file
 * Adds behaviours to the person profiles.
 */

(function ($, window) {
  "use strict";

  Drupal.behaviors.elifePersonProfile = {
    attach: function () {
      $('body').once('view-elife-person-profiles', function () {

        // setupBiogs controls the display of the extended biographies for those people who
        //  have them.
        //  It turns off the display of all such biogs (but keeps them in the DOM), and sets
        //   an event listener on links to them to display them when pressed.
        var setupBiogs = function () {
          var $biogs = $('.person-profile__biog-wrapper'),
            $arrows = $('.person-profile__biog-arrow'),
            $peopleLinks = $('.person-profile__link-js-hook'),
            moduleFolder,

            /**
             * Toggle the display of the biography with the specified id.
             *
             * @param {string} id The id of the biography
             * @leftPosn {number} The left position at which to place the biography
             * @arrowLeftPosn {number} The left position at which to place the arrow
             */
            toggleBiog = function ($biog, leftPosn, arrowLeftPosn) {
              var $arrow,
                $widthDefiningContainer;

              // normalise biogId to have exactly one leading # character
              $arrow = $('.person-profile__biog-arrow', $biog);

              // turn off all the other biogs and arrows, turn on ours, and position it
              // so the left edge of the biog is onscreen and the arrow sits beneath the
              // clicked link.
              $biogs.not($biog).addClass('off');
              $biog.toggleClass('off');

              $arrows.not($arrow).addClass('off');
              $arrow.toggleClass('off');

              // Treat the extended profiles differently on smaller devices.
              if (window.matchMedia('(min-width: 46.9375em)').matches) {
                // set the width of $biog.parent() to fit, and not overlay the menu
                $widthDefiningContainer = $biog.parents('.view-elife-person-profiles').eq(0);
                $biog.parent().width($widthDefiningContainer.width() - 64).css({position: 'absolute'});

                $biog.parent().offset({left: leftPosn});

                if ($arrow.hasClass('off')) {
                  $arrow.offset({left: -9999});
                }
                else {
                  $arrow.offset({left: arrowLeftPosn});
                }
              }
              else {
                $biog.parent().css({left: 0});
                $biog.parent().width('100%').css({position: 'relative', 'max-width': '100vw'});
              }
            },


            /**
             *   Handle click event on a photo-item to open/close a biography
             *   @param {Event object} e The event
             */
            handleBiogDisplay = function (e) {
              var $biog,
                $biogIndex,
                isDisplacable,
                leftPosn,
                arrowLeftPosn,
                noCoi;

              e.preventDefault();

              $biog = $(this).closest('.person-profile--extended').find('.person-profile__biog-wrapper').eq(0);

              // Work out how much to offset the biog to the left:
              // By default, position it close to the left hand edge of what's
              // on screen.
              leftPosn = $(this).parents('.view-elife-person-profiles').eq(0).offset().left + 32;

              // work out where to position the up arrow on the top of the box,
              //  relative to the link clicked
              arrowLeftPosn = $(this).offset().left + 84;

              // When there's no conflict of interest block and the window.width > 901px,
              // a biog triggered from the 3rd or 4th column needs displacing to sit under
              // the correct photo.
              noCoi = !!$biog.closest('.person-profile__biog-outer--no-coi').length;
              $biogIndex = $biog.closest('.person-profile--extended').prevAll().size() + 1;
              isDisplacable = !($biogIndex % 3) || !($biogIndex % 4);
              if (noCoi && isDisplacable && $(window).width() > 901) {
                leftPosn += 200;
              }

              toggleBiog($biog, leftPosn, arrowLeftPosn);
            },

            /**
             *   Handle click event on its close button to close an open biography
             */
            closeBiog = function (e) {
              var $biog = $(this).parents('.person-profile--extended').find('.person-profile__biog-wrapper').eq(0);
              e.preventDefault();
              toggleBiog($biog);
            };

          // throw all biogs off screen
          $biogs.addClass('off');
          $arrows.addClass('off');

          // Register listeners to:
          //  - toggle display of respective biographies
          $peopleLinks.on('click', handleBiogDisplay);

          moduleFolder = Drupal.settings.elifePersonProfile.moduleFolder;
          $('.person-profile__biog-wrapper section:last-child').append('<a href="#" class="person-profile__biog-close" title="' + Drupal.t('Close') + '"><img src="' + moduleFolder + '/images/close-lt-on-dk.png" alt="' + Drupal.t('Close biography') + '"></a>');

          //  - close biog when close button pressed
          $('.person-profile__biog-close').on('click', closeBiog);
        };

        // introduce markup for arrow placement for extended profiles
        $('.person-profile__biog-wrapper').prepend('<div class="person-profile__biog-arrow"></div>');

        // duplicate img for extended biog
        $('img.person-profile__biog-image--in-flow').each(function () {
          var $imgClone = $(this).clone().removeClass('person-profile__biog-image--in-flow');
          $('.person-profile__figure-caption', $(this).parents('.person-profile--extended')).prepend($imgClone);
        });

        setupBiogs();

      });
    }
  };

})(jQuery, this);
