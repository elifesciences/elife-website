(function ($) {
  Drupal.behaviors.elifeJumpLinks = {
    attach: function (context, settings) {
      $(function() {
        // Function that opens a section if it's collapsed
        var deCollapse = function($section) {
          if ($('.ctools-toggle.ctools-toggle-collapsed', $section).length) {
            $('.ctools-collapsible-handle', $section).trigger('click');
          }
        };

        var linkClicked = function($link) {
          var href = $link.attr('href');
          // Explicitly strip out the #fragment and use that as the target instead of relying on raw href.
          var target_id = href.substring(href.indexOf('#'));
          var $section = $(target_id);
          var panelTarget = $link.data('panel-ajax-tab');

          // The "#article" target is special, we always just trigger a click
          if (target_id === '#article') {
            $('a.panels-ajax-tab-tab[data-panel-name="' + panelTarget + '"]').trigger('click');
            $(window).scrollTop($section.offset().top);
            return false;
          }
          else if ($section.length > 0) {
            deCollapse($section);
            $(window).scrollTop($section.offset().top);
            return false;
          }
          else {
            $('a.panels-ajax-tab-tab[data-panel-name="' + panelTarget + '"]').panels_ajax_tabs_trigger(function() {
              $section = $(target_id);
              deCollapse($section);
              $(window).scrollTop($section.offset().top);

              //@@TODO: This is hack until the disqus module stops crapping-out on AJAX
              //@@TOOD: Patch the disqus module properly
              DISQUS.reset({
                reload: true,
                config: function () {
                  this.page.identifier = Drupal.settings.disqus.identifier;
                  this.page.url = Drupal.settings.disqus.url + "#!newthread";
                }
              });
              return false;
            });
          }
        };

        $('a.elife-article-jumplink', context).click(function() {
          linkClicked($(this));
          return false;
        });

        // Duplicate the sidebar into the floating region
        var $jumpLinks = $('.pane-elife-article-jumpto');
        var $jumpBlock = $('#article-jumplinks-anchor-region');
        var $jumpBlockContent = $('#jump-links-anchor-container');

        $jumpBlockContent.html('').html($jumpLinks.html());
        $jumpBlockContent.width($jumpLinks.width());
        $jumpBlockContent.height($jumpLinks.height());
        $jumpBlock.hide();

        $('a.elife-article-jumplink', $jumpBlock).click(function() {
          linkClicked($(this));
          return false;
        });

        // Duplicate sidebar into header for mobile nav
        var $mobileLinks = $('.pane-elife-article-jumpto .pane-content');
        var $newHeaderNav = $('.page_header .header__list_secondary');
        if (!$newHeaderNav.find('.elife-jumpto')[0]) {
          $('.header__list_secondary_close', $newHeaderNav).after($mobileLinks.html());
          $('a.elife-article-jumplink', $newHeaderNav).click(function() {
            $('.header__list_secondary').hide();
            linkClicked($(this));
            return false;
          });
        }

        // Back to Top Links for Ajax Tab Panes
        $('body').prepend('<a name="body-top" />');
        $('#panels-ajax-tab-container-elife-research-article-tabs .ctools-collapsible-content').append('<a class="back-to-top visible-small" href="#body-top">To Top</a>');


        // Sidebar floating functionality
        var past = false,
          topOffset = 0;

        if ($('body').hasClass('admin-menu')) {
          var topOffset = 15;
        }
        $(window).scroll(function() {
          var scroll_pos_test = $('.js-jumpblock-trigger').offset().top;
          var y_scroll_pos = window.pageYOffset;
          var currentLayout = Drupal.omega.getCurrentLayout();

          if (currentLayout != 'mobile') {

            if(past == false && y_scroll_pos > (scroll_pos_test - 28)) {
              past = true;
              $jumpBlock.css('position', 'fixed').css('top', topOffset).css('left', $('.sidebar-wrapper').offset().left);
              $jumpBlock.fadeIn(400);
            }
            if(past == true && y_scroll_pos <= (scroll_pos_test - 28)) {
              past = false;
              $jumpBlock.fadeOut(200);
            }

          }
        });

        $(window).resize(function(){
          var currentLayout = Drupal.omega.getCurrentLayout();

          if (currentLayout != 'mobile') {
            if (past) {
              $jumpBlock.css('left', $('.sidebar-wrapper').offset().left + 'px');
            }
          }

          $('body').bind('responsivelayout', function(e, d) {
            if (d.to == 'mobile') {
              $jumpBlock.hide();
            }
            if (d.from == 'mobile' && past) {
              $jumpBlock.fadeIn(400);
            }
            if(d.from != d.to) {
              $jumpBlockContent.width($jumpLinks.width());
              $jumpBlockContent.height($jumpLinks.height());
            }
          });
        });

        // Stop menu overlaying footer in wide article view.
        // (This has been put into its own self-contained IIFE to make it easy to refactor into a
        // separate file if desired. And to separate it out from the proto-spaghetti above.)
        (function (window, document, $, $jmpBlk) {
          "use strict";

          var $jumpBlock = $jmpBlk || $('#article-jumplinks-anchor-region'),
            jumpBlockHeight = $jumpBlock.height(),
            siteFooter = document.querySelector('.site-footer'),
          // A paddingAboveFooter of 43 is px-perfect for lining up bottom of menu with bottom of article in
          // Webkit, Gecko pushes up a bit too much with this value, Trident not quite enough. Looking at
          // our web stats, this is fine. On all platforms it looks so much better than it did.
            paddingAboveFooter = 43,

            /**
             * Moves the menu up if it would otherwise overlay the footer.
             *
             * @param footerBoundingRect The boundingClientRect of the footer
             */
            stopMenuOverlayingFooter = function (footerBoundingRect) {
              var smallestFooterTopNotCausingOverlay = jumpBlockHeight + paddingAboveFooter,
                moveTheMenuBy = footerBoundingRect.top - smallestFooterTopNotCausingOverlay;
              // We only ever want to move the menu up, not down, hence only care about a negative value.
              if (moveTheMenuBy < 0) {
                $jumpBlock.css('top', moveTheMenuBy);
              }
            },

            /**
             * Indicates whether the footer is visible on screen.
             *
             * @param footerBoundingRect The boundingClientRect of the footer
             * @returns {boolean} whether the footer is visible on the screen
             */
            isFooterVisible = function (footerBoundingRect) {
              if (footerBoundingRect.top < window.innerHeight && footerBoundingRect.bottom >= 0) {
                return true;
              }
              return false;
            };

          $(window).on('DOMContentLoaded load resize scroll', function () {
            var footerBoundingRect = siteFooter.getBoundingClientRect();
            if (isFooterVisible(footerBoundingRect)) {
              stopMenuOverlayingFooter(footerBoundingRect);
            }
          });

        }(window, window.document, jQuery, $jumpBlock, undefined));

      });
    }
  };
})(jQuery);
