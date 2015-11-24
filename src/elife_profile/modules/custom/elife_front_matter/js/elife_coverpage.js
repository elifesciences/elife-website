(function ($, window) {
  "use strict";
  Drupal.behaviors.elifeCoverPage = {
    attach: function () {
      $('body').once('elife-coverpage', function() {

        /**
         * Provides a way of recording and retrieving the current state of the
         * listing nav as chosen by the user (i.e. not just the state that the
         * media query has set).
         * Immediate function using the revealing module pattern
         * @returns {object} with the following methods:
         *               isClosed - @returns {boolean}
         *               setClosed - @param {boolean}
         */
        var chosenNavState = (function () {
          var isNavToggledClosed = true,
              getState = function () {
                return isNavToggledClosed;
              },
              setState = function (state) {
                isNavToggledClosed = state;
              };
            return {
              isClosed: getState,
              setClosed: setState
            };
          }()),

          /**
           * Duplicates the archive nav when viewport is wide enough.
           *   Removes any duplicates when in single column layout.
           *   Uses matchMedia, so make sure a suitable ployfill is available
           *   where necessary.
           */
            duplicateArchiveNav = function () {
            var checkToCloneMenu = function () {
              var $archiveNavs = $('.home-archive__list'),
                  numArchiveNavs = $('.home-archive__list').length;

              if (window.matchMedia("(min-width: 55em)").matches) {
                if (numArchiveNavs === 1) {
                  // clone archive nav to beneath article listing
                  $archiveNavs.eq(0).clone().appendTo('.home-article-listing-wrapper');
                }
              } else {
                if (numArchiveNavs > 1) {
                  // remove all but the first instance
                  $archiveNavs.each(function (i) {
                    if (i > 0) {
                      $(this).remove();
                    }
                  });
                }
              }
            };

            window.setTimeout(function () {
              window.addEventListener('resize', checkToCloneMenu, false);
              checkToCloneMenu();
            }, 0);
          },

          /**
           * Toggles display of .home-listings__list.
           *
           *   1. No js, single column:
           *       - display nav inline, with position static
           *       - no toggle available.
           *   2. With js, single column:
           *       - by default throw nav offscreen, but keep in DOM
           *       - the toggle control is made available through js
           *       - switching on the toggle overlays nav on top of articles, using
           *           a high z-index
           *       - toggle off throws offscreen
           *   3. Wide view:
           *       - nav always displayed on right hand side
           *           even when hidden in prev single col
           *               (e.g. if browser window enlarged).
           *
           * @param {string} state 'on', 'off' or 'toggle'
           */
            switchListingsNav = function (state) {
            // N.B. jQuery show/hide/toggle doesn't work here. It's over-
            //  opinionated about inline style injection in this case.
            var $list = $('.home-listings__list').eq(0),
                $toggleControl = $('.home-listings__toggle').eq(0),
                switchOn = function () {
                  $list.removeClass('off-screen');
                  $list.addClass('overlay');
                  chosenNavState.setClosed(false);
                  $toggleControl.addClass('open');
                },
                switchOff = function () {
                  $list.addClass('off-screen');
                  $list.removeClass('overlay');
                  chosenNavState.setClosed(true);
                  $toggleControl.removeClass('open');
                },
                toggle = function () {
                  if ($list.hasClass('off-screen')) {
                    switchOn();
                  } else {
                    switchOff();
                  }
                };
            switch (state) {
              case 'on':
                switchOn();
                break;

              case 'off':
                switchOff();
                break;

              case 'toggle':
                toggle();
                break;

              default:
                break;

            }
          },

          /**
           * Injects or removes span.home-listings__toggle, including setting up
           *   of event listener on injection.
           *
           * @param {string} state 'on', 'off' or 'toggle'
           */
          switchListingNavToggle = function (state) {
            var on = function () {
                  if ($('.home-listings__toggle').length === 0) {
                    $('.home-listings__heading').eq(0).append('<span class="home-listings__toggle"> <a href="#listings" title="toggle menu"><img src="' + Drupal.settings.elifeFrontMatter.path + '/images/arrow-down-blue-sml.png" alt="down arrow"/></a></span>');
                    $('.home-listings__toggle').on('click', function (e) {
                      e.preventDefault();
                      switchListingsNav('toggle');
                    });
                  }
                },
                off = function () {
                  $('.home-listings__toggle').remove();
                },
                toggle = function () {
                  if ($('.home-listings__toggle').length === 0) {
                    on();
                  } else {
                    off();
                  }
                };
            switch (state) {
              case 'on':
                on();
                break;

              case 'off':
                off();
                break;

              case 'toggle':
                toggle();
                break;

              default:
                break;
            }
          },

          /**
           * Controls how the listing nav is displayed, depending on the viewport
           *   width.
           */
          layoutListingNav = function () {
            if (!window.matchMedia("(min-width: 55em)").matches) {
              if (chosenNavState.isClosed()) {
                switchListingNavToggle('on');
                switchListingsNav('off');
              } else {
                switchListingNavToggle('on');
                switchListingsNav('on');
              }
            } else {
              switchListingsNav('on');
              switchListingNavToggle('off');
              // although here the viewport is wide and so nav listing
              //  menu is displayed, it's not a usser-decision, so from a
              // users' pov the nav listing is closed. (When the viewport
              // narrows, we don't want the menu displaying by default).
              chosenNavState.setClosed('true');
            }
          };

        duplicateArchiveNav();
        layoutListingNav();
        $(window).on('resize', layoutListingNav);
      });
    }
  };

  Drupal.behaviors.elifeCoverPageListingImages = {
    attach: function () {
      $('body').once('elife-coverpage-listing-images', function() {
        // When the viewport reaches minimum width, load the article list
        // images. If the images have already been loaded, show/hide them
        // depending on the viewport's width relative to the threshold.


        var document = window.document,
          imagesLoaded = false,
          widthThreshold = '(min-width: 31em)',

          isViewportWiderThan = function (widthAsString) {
            if (window.matchMedia && window.matchMedia(widthAsString).matches) {
              return true;
            }
          },

          showImages = function () {
            var $articles = $('.home-article-listing__list-item', '.home-article-listing-wrapper'),

              createImage = function(placeholder) {
                var image = document.createElement('IMG');
                image.src = placeholder.getAttribute('data-img') || '';
                image.alt = placeholder.getAttribute('data-alt') || '';
                image.width = '104';
                image.height = '145';
                return image;
              },

              createImageWrapper = function () {
                var wrapper = document.createElement('DIV');
                wrapper.classList.add('home-article-listing__list-item__image-wrapper');
                return wrapper;
              },

              getLink = function (article) {
                var link = article.querySelector('.highwire-cite-linked-title').cloneNode(true);
                // keep all the attributes, but throw away the content.
                link.innerHTML = '';
                return link;
              },

              getPlaceHolder = function (article) {
                return article.querySelector('.home-article-listing__list-item__image-placeholder');
              },

            // Replace image-placeholder with linked image.
              prepImageBlock = function (article) {
                var wrapper = createImageWrapper(),
                  link = getLink(article),
                  placeholder = getPlaceHolder(article);

                // build up image block
                if (placeholder.getAttribute('data-img') !== '') {
                  link.appendChild(createImage(placeholder));
                  wrapper.appendChild(link);
                  // add image block into DOM
                  article.replaceChild(wrapper, placeholder);
                }
              };

            // Show images if they've previously been loaded, otherwise load them.
            if (imagesLoaded) {
              $('.home-article-listing__list-item__image-wrapper').show();
            } else {
              $articles.each(function() {
                try {
                  prepImageBlock(this);
                } catch (e) {
                  console.log(e);
                }
              });
              imagesLoaded = true;
            }
          },

          hideImages = function () {
            // harmlessly does nothing if images not loaded.
            $('.home-article-listing__list-item__image-wrapper').hide();
          },

          resizeHandler = function () {
            // stop multiple resize events firing too quickly (militates against memory problems).
            window.setTimeout(function () {
              if (isViewportWiderThan(widthThreshold)) {
                showImages();
              } else {
                hideImages();
              }
            }, 5);

          };

        if (isViewportWiderThan(widthThreshold)) {
          showImages();
        }

        window.addEventListener('resize', resizeHandler, false);
      });
    }
  };
})(jQuery, this);
