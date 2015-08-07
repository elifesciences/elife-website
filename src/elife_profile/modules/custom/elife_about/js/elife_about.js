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

  Drupal.behaviors.elifeAboutBRE = {
    attach: function () {
      $('body').once('elife-about-bre', function () {
        // Handles the introduction of an all reviewing editors list.
        var id = 'bre',
          // boolean to indicate the reviewing editors have been loaded.
          bre_load = false,
          moduleFolder = Drupal.settings.elifeAbout.moduleFolder,
          isElementInViewport = function (el) {
            var rect;

            if (el instanceof $) {
              el = el.get(0);
            }

            rect = el.getBoundingClientRect();

            // Return when top of element has risen above the bottom of the viewport.
            return rect.top <= (window.innerHeight || window.document.documentElement.clientHeight);
          },
          profilesInViewport = function () {
            return isElementInViewport($('#aims-and-scope'));
          },
          scrollHandler = function () {
            // stop multiple scroll events firing too quickly (mitigates against memory problems).
            window.setTimeout(function () {
              if (profilesInViewport()) {
                loadBre();
              }
            }, 5);
          },
          // Prepare menu item and empty section for BRE.
          prepBre = function () {
            var label = Drupal.t('All reviewing editors'),
              tmp,
              tmp_id = 'leadership';

            // Create link to all reviewing editors.
            tmp = $('#menu-' + tmp_id).closest('li').next('li').clone();
            $('a', tmp).attr('href', '#' + id).attr('id', 'menu-' + id).text(label);
            tmp.insertAfter($('#menu-' + tmp_id).closest('li'));

            // Create section to contain markup of all reviewing editors.
            tmp = $('#' + tmp_id).clone();
            tmp.removeClass('aims-scope__people--' + tmp_id);
            tmp.addClass('aims-scope__people--' + id);
            tmp.attr('id', id);
            $('.aims-scope__people_heading', tmp).text(label);
            $('div, h5', tmp).remove();
            tmp.insertAfter($('#leadership'));
          },
          // Load or show all reviewing editors list.
          loadBre = function () {
            // Attempt to load BRE if prep has been done.
            if (!bre_load && $('#' + id).length > 0) {
              // Set flag to indicate that loading is happening.
              bre_load = true;

              // Stop resize scroll listener.
              $(window).off('DOMContentLoaded load resize scroll', scrollHandler);

              // Introduce loading gif.
              $('<img class="loading" src="' + moduleFolder + '/images/loading.gif" />').appendTo($('#' + id));

              // Retrieve all BRE via ajax
              $.ajax({
                url: Drupal.settings.basePath + 'about-bre',
                dataType: 'html',
                type: 'GET',
                // Time out after 30 secs.
                timeout: 30000,
                success: function(html) {
                  $(html).appendTo($('#' + id));
                  // Remove loading gif.
                  $('.loading').remove();
                },
                error: function(x, t, m) {
                  // Remove loading gif.
                  $('.loading').remove();
                  $('<div class="messages warning"><p>' + Drupal.t('Editors failed to load.') + '</p></div>').appendTo($('#' + id));
                }
              });
            }
          };

        prepBre();

        // Start resize scroll listener.
        $(window).on('DOMContentLoaded load resize scroll', scrollHandler);

      });
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
            // section. If there isn't one, display leadership by default.
            switchSheets(window.location.hash || 'leadership');
          },


        // setupBiogs controls the display of the extended biographies for those people who
        //  have them.
        //  It turns off the display of all such biogs (but keeps them in the DOM), and sets
        //   an event listener on links to them to display them when pressed.
          setupBiogs = function () {
            var $biogs = $('.aims-scope__person_biog_wrapper', '#aims-and-scope'),
              $arrows = $('.aims-scope__person_biog_arrow'),
              $peopleLinks = $('.aims-scope__person_link_js_hook'),
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
                $arrow = $('.aims-scope__person_biog_arrow', $biog);

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
                  $widthDefiningContainer = $biog.parents('.aims-scope__people').eq(0);
                  $biog.parent().width($widthDefiningContainer.width() - 64).css({position: 'absolute'});

                  $biog.parent().offset({ left: leftPosn });

                  if ($arrow.hasClass('off')) {
                    $arrow.offset({ left: -9999 });
                  }
                  else {
                    $arrow.offset({ left: arrowLeftPosn });
                  }
                }
                else {
                  $biog.parent().css({ left: 0 });
                  $biog.parent().width('100%').css({position: 'relative'});
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

                $biog = $(this).closest('.aims-scope__person--extended').find('.aims-scope__person_biog_wrapper').eq(0);

                // Work out how much to offset the biog to the left:
                // By default, position it close to the left hand edge of what's
                // on screen.
                leftPosn = $('#people').offset().left + 32;

                // work out where to position the up arrow on the top of the box,
                //  relative to the link clicked
                arrowLeftPosn = $(this).offset().left + 84;

                // When there's no conflict of interest block and the window.width > 901px,
                // a biog triggered from the 3rd or 4th column needs displacing to sit under
                // the correct photo.
                noCoi = !!$biog.closest('.aims-scope__person_biog_outer--no-coi').length;
                $biogIndex = $biog.closest('.aims-scope__person--extended').prevAll().size() + 1;
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
                var $biog = $(this).parents('.aims-scope__person--extended').find('.aims-scope__person_biog_wrapper').eq(0);
                e.preventDefault();
                toggleBiog($biog);
              };

            // throw all biogs off screen
            $biogs.addClass('off');
            $arrows.addClass('off');

            // Register listeners to:
            //  - toggle display of respective biographies
            $peopleLinks.on('click', handleBiogDisplay);
            moduleFolder = Drupal.settings.elifeAbout.moduleFolder;
            $('.aims-scope__person_biog_wrapper section:last-child').append('<a href="#" class="aims-scope__person_biog_close" title="' + Drupal.t('Close') + '"><img src="' + moduleFolder + '/images/close-lt-on-dk.png" alt="' + Drupal.t('Close biography') + '"></a>');

            //  - close biog when close button pressed
            $('.aims-scope__person_biog_close').on('click', closeBiog);
          };

        // introduce markup for arrow placement for extended profiles
        $('.aims-scope__person_biog_wrapper').prepend('<div class="aims-scope__person_biog_arrow"></div>');

        // duplicate img for extended biog
        $('img.aims-scope__person_biog_image--in-flow').each(function () {
          var $imgClone = $(this).clone().removeClass('aims-scope__person_biog_image--in-flow');
          $('.aims-scope__person_figure_caption', $(this).parents('.aims-scope__person--extended')).prepend($imgClone);
        });


        setupSheetDisplay();
        setupBiogs();

      });
    }
  };

})(jQuery, this);
