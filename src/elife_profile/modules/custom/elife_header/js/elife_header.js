/**
 * @file
 * Adds the behaviour for elife header
 */
(function ($, window) {
  Drupal.behaviors.elifeHeader = {
    attach: function () {
      $('body').once('elife-header', function () {

        var $secondaryMenu = $('.header__list_secondary'),
          $interviewsMenu = $('.header__list_secondary--interviews'),
          $categoryMenu = $('.header__list_secondary--category'),
          $secondaryMenuItems = $('.header__list_secondary_item'),
          $menuLink = $('<li class="header__list_item--menu"><a href="#" class="header__list_link header__list_link--menu">' + Drupal.t('Menu') + '</a></li>');

        // Show individual category links. (They are hidden without js, but can still be visited by following the
        //  link to the all subjects page).
        $secondaryMenuItems.removeClass('hidden');

        // create the interview heading inside the menu
        $('<h3 class="header__list_secondary--interviews__heading">' + Drupal.t('Interviews') + '</h3>').insertBefore($interviewsMenu);

        // create the category heading inside the menu
        $('<h3 class="header__list_secondary--category__heading">' + Drupal.t('Subjects') + '</h3>').insertBefore($categoryMenu);

        // create the close button inside the menu and register an event handler on it
        $('<a class="header__list_secondary_close" href="#">' + Drupal.t('Close') + '</a>').prependTo('.header__list_secondary');
        $('.header__list_secondary_close').on('click', function (e) {
          $secondaryMenu.hide();
        });

        // create the menu link and register an event handler on it
        $('.header__list').eq(0).append($menuLink);
        $menuLink.on('click', function (e) {
          $secondaryMenu.toggle();
        });

      });
    }
  };

  Drupal.behaviors.eLifeHeaderFloating = function(nav, once_class) {
    if (once_class == undefined) {
      once_class = 'elife-floating-nav';
    }
    $('body').once(once_class, function () {
      var ecNavPos = function () {
        var $nav = nav,
          minScroll = $('.page_header').height(),
          top = $(window).scrollTop();

        if (top > minScroll) {
          $nav.css({position: "fixed"});
        } else {
          $nav.css({position: "relative"});
        }
      };

      ecNavPos();
      $(window).scroll(function () {
        ecNavPos();
      });
    });
  }

  Drupal.behaviors.elifeSectionScroll = function (once_class) {
    if (once_class == undefined) {
      once_class = 'elife-section-scroll';
    }
    $('body').once(once_class, function () {

      //  - verify that the new hash is a valid id of a DOM element
      //  - prevent any default event behaviour (but don't stop propogation)
      //  - scroll to the element
      //  - scroll up 100 pixels to avoid the fixed nav
      var scrollOutFromNav = function (frag, e) {
        var $destination = $(frag),
          currentY;
        if ($destination.length === 0) {
          return;
        }
        if (e && typeof e.preventDefault === 'function') {
          e.preventDefault();
        }
        currentY = $(window).scrollTop();
        $(window).scrollTop($destination);
        $(window).scrollTop(currentY - 100);
      };

      // Register an event listener to fire when location.hash changes.
      $(window).on('hashchange', function (e) {
        scrollOutFromNav(location.hash, e);
      });

      $(window).on('load', function (e) {
        var hash = location.hash;
        if (hash.length > 0) {
          scrollOutFromNav(location.hash, e);
        }
      });

    });
  };
})(jQuery, this);
