/**
 * Defines behaviour for digests.
 */

(function (window, document, $, undefined) {
  "use strict";

  /**
   * Returns the date string one year ahead from the current date.
   * @returns {string} The date one year in the future
   */
  var oneYearFromNow = function oneYearFromNow() {
      var date = new Date();
      date.setTime(date.getTime() + 1000 * 60 * 60 * 24 * 365);
      return date.toUTCString();
    },

    /**
     * Data used in the digest cookie.
     */
    dataForDigestCookie = {
      'name': 'digestState',
      'value': {
        'closed': 'closed',
        'open': 'open'
      },
      'path': '/content/',
      'getDuration': oneYearFromNow
    },

    /**
     * Sets a cookie recording the state of the digest.
     *
     * @param cookieData Data describing the cookie to set
     * @param digestState {String} "open" or "closed" (derived from cookieData)
     */
    setDigestCookie = function setDigestCookie(cookieData, digestState) {
      var cookie = cookieData.name + '=' + cookieData.value[digestState];
      // expires not max-age because IE8.
      cookie += '; expires=' + cookieData.getDuration();
      cookie += '; path=' + cookieData.path;
      document.cookie = cookie;
    },

    /**
     * Describes whether the digest state is set to closed.
     *
     * @param cookieData Data describing the cookie to investigate
     * @returns {boolean} True if the digest state is set to closed
     */
    isDigestSetClosed = function isDigestSetClosed(cookieData) {
      var isSetClosed = false,
        cookies = document.cookie.length ? document.cookie.split('; ') : [];
      $.each(cookies, function (i, cookie) {
        var eqPos = cookie.indexOf('='),
          name = cookie.substring(0, eqPos),
          value;
        if (window.decodeURIComponent(name) === cookieData.name) {
          value = window.decodeURIComponent(cookie.substring(eqPos + 1));
          if (value === cookieData.value.closed) {
            isSetClosed = true;
          }
        }
      });
      
      return isSetClosed;
    },

    /**
     * Hide page section without triggering a click event.
     *
     * A click event will be registered to GA, but GA should only be notified
     * when a user actively clicks on the toggle, not when it's automatically
     * hidden based on the cookie.
     *
     * @param $section The jQuery object containing the section to hide
     */
    hideSection = function hideSection($section) {
      $('.ctools-toggle', $section).addClass('ctools-toggle-collapsed');
      $('.ctools-collapsible-content', $section).css('display', 'none');
    },

    /**
     * Returns the bottom y position of the top third of the screen.
     */
    getReadingZoneLimit = function getReadingZoneLimit() {
      return window.innerHeight / 3;
    },

    /**
     * Returns true if the digest is in the top third of the screen.
     *
     * The top third of the screen is defined here as the reading zone.
     * When the digest is in this area, we assume the user is reading it.
     *
     * @returns {boolean} True if the digest top is in the top third of the screen
     */
    isDigestInReadingZone = function isDigestInReadingZone($digest) {
      var tooLow = isDigestBelowReadingZone($digest),
        tooHigh = isDigestAboveReadingZone($digest);
      return !tooLow && !tooHigh;
    },

    /**
     * Returns true if the digest is below the reading zone.
     *
     * @param $digest The digest
     * @returns {boolean} true if the digest is below the reading zone
     */
    isDigestBelowReadingZone = function isDigestBelowReadingZone($digest) {
      var digestTop = $digest.offset().top,
        digestTopFromWindowTop = digestTop - $(window).scrollTop();
      return digestTopFromWindowTop > getReadingZoneLimit();
    },

    /**
     * Returns true if the digest is above the reading zone.
     *
     * @param $digest The digest
     * @returns {boolean} true if the digest is above the reading zone
     */
    isDigestAboveReadingZone = function isDigestAboveReadingZone($digest) {
      var digestBottom = $digest.offset().top + $digest.height(),
        digestBottomFromWindowTop = digestBottom - $(window).scrollTop();
      return digestBottomFromWindowTop <= 0;
    },

    /**
     * Sends digest events to GA.
     *
     * @param action The GA action to log
     */
    sendToGa = function sendToGa(action) {

      try {
        if (ga) {
          // Create the ga tracker if it hasn't already been created.
          if (!ga.getByName('interactionTracking')) {
            ga('create', 'UA-48379231-2', {'name': 'interactionTracking'});
          }
          ga('interactionTracking.send', 'event', 'Digest', action);
        }
      } catch (e) {
        // If something goes wrong with the tracking, fail silently.
      }
    };

// Opening/closing:
//  Digests default by open.
//  Once a user closes one digest, a cookie is set so all digests appear
//  closed to them. Once a user opens a digest, all digests now appear
//  open to them again.
//
// Reading/skipping:
//  Applies to open digests only
//  The reading zone is defined as the top third of the browser window.
//  If not already read or skipped:
//    - A digest entering the reading zone starts the reading timer. The reading
//      timer will register that the digest has been read if it's not cancelled
//      within 20s.
//    - A digests dropping below the reading zone cancels the timer.
//    - A digest moving above the reading zone will cancel the timer and
//      register that the digest has been skipped.

  $(function () {
    var $digest = $('#digest'),
      isDigestShown,
      digestReadTimer = -1,
      isDigestRead = false,
      isDigestSkipped = false;

    if (!$digest.length) {
      return;
    }

    // Honour cookie if already set; set cookie based on digest state.
    if (isDigestSetClosed(dataForDigestCookie)) {
      hideSection($digest);
      isDigestShown = false;
      setDigestCookie(dataForDigestCookie, dataForDigestCookie.value.closed);
    } else {
      setDigestCookie(dataForDigestCookie, dataForDigestCookie.value.open);
      isDigestShown = true;
    }

    // Set digest cookie appropriately on show/hide clicks.
    $('.pane-title.ctools-collapsible-handle, .ctools-toggle', $digest).click(
      function () {
        if (isDigestShown) {
          setDigestCookie(dataForDigestCookie, dataForDigestCookie.value.closed);
          isDigestShown = false;
        } else {
          setDigestCookie(dataForDigestCookie, dataForDigestCookie.value.open);
          isDigestShown = true;
        }
      }
    );

    $(window).scroll(function () {
      // A closed digest does not appear in read/skipped stats.
      if (!isDigestShown) {
        return
      }

      // Set a timer when the digest is in the reading zone, that gets cleared:
      //  - when 20s elapses & a 'read' event is triggered
      //  - or when the digest moves above the reading zone before the 20s and a 'skipped' event is triggered.
      //  - or when the digest moves back below the reading zone, not triggering anything
      if (!isDigestRead && !isDigestSkipped) {

        if (isDigestInReadingZone($digest) && digestReadTimer === -1) {
          digestReadTimer = window.setTimeout(function () {
            isDigestRead = true;
            sendToGa('read');
          }, 20000);

        } else if (isDigestBelowReadingZone($digest) && digestReadTimer > -1) {
            window.clearTimeout(digestReadTimer);
            digestReadTimer = -1;

        } else if (isDigestAboveReadingZone($digest)) {
          try {
            window.clearTimeout(digestReadTimer);
          } catch (e) {
            // There may not be any timeout to clear (e.g. a jumplink was used
            // to access content below the digest, so the scroll event didn't fire).
          }
          digestReadTimer = -1;
          isDigestSkipped = true;
          sendToGa('skipped');
        }
      }
    });
  });

}(window, window.document, jQuery));
