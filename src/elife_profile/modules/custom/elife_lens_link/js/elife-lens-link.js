/**
 * @file
 * Code for Lens link.
 */
(function (window, document, undefined) {
  "use strict";

  /**
   * Return true if some modern browser features are available.
   *
   * @return {boolean} true if some modern browser features are available.
   */
  var canProbablyUseLens = function canProbablyUseLens() {
      return (!!document.querySelector &&
              !!document.querySelector('body').classList &&
              !! window.matchMedia &&
              !! window.requestAnimationFrame &&
              !! Object.keys);
    },

    /**
     * Return true if the provided display criterion is met.
     *
     * @param displayCriterion Media statement defining display criterion
     * @returns {boolean} Whether the display criterion is met
     */
    isEnoughSpaceToDisplayLensLink = function isEnoughSpaceToDisplayLensLink(displayCriterion) {
      return window.matchMedia(displayCriterion).matches;
    },

    /**
     * Return the Lens version of the article, or octothorpe if not available.
     *
     * @returns {string} The path to the Lens version of the article.
     */
    getPathToLensVersion = function getPathToLensVersion() {
      // If path derivation screws up, make the path an empty fragment so as not
      // to break the user's navigation further.
      return Drupal.settings.elife_lens_link.lensUri || '#';
    },

    /**
     * Convenience method to inject the Lens link at a particular DOM position.
     *
     * If the attachment point has a next element sibling, the link is
     * attached immediately before attachPoint. If not, it's attached as a
     * child of attachPoint.
     *
     * @param link The link element to inject
     * @param attachPoint The element to attach it before/under.
     */
    injectLink = function injectLink(link, attachPoint) {
      if (attachPoint.nextElementSibling) {
        attachPoint.parentNode.insertBefore(link, attachPoint.nextElementSibling);
      } else {
        attachPoint.appendChild(link);
      }
    },

    /**
     * Inline URI-encoded SVG image data URI for the book image.
     *
     * @type {string}
     */
    svgDataBookUriEnc = 'data:image/svg+xml;charset=utf-8,%3C%3Fxml%20version%3D%221.0%22%20encoding%3D%22utf-8%22%3F%3E%3Csvg%20version%3D%221.1%22%20id%3D%22Layer_1%22%20xmlns%3D%22http%3A%2F%2Fwww.w3.org%2F2000%2Fsvg%22%20xmlns%3Axlink%3D%22http%3A%2F%2Fwww.w3.org%2F1999%2Fxlink%22%20x%3D%220px%22%20y%3D%220px%22%20viewBox%3D%220%200%2040%2032%22%20xml%3Aspace%3D%22preserve%22%3E%0A%20%20%20%20%20%20%3Cstyle%20type%3D%22text%2Fcss%22%3E%0A%09%20%20%20%20.st0%7Bfill%3Anone%3Bstroke%3A%23FFFFFF%3Bstroke-width%3A2.992%3Bstroke-linecap%3Around%3Bstroke-linejoin%3Around%3Bstroke-miterlimit%3A10%3B%7D%0A%20%20%20%20%20%20%3C%2Fstyle%3E%0A%20%20%20%20%20%20%3Cg%20id%3D%22XMLID_2_%22%3E%0A%20%20%20%20%20%20%20%20%20%20%3Cpath%20id%3D%22XMLID_4_%22%20class%3D%22st0%22%20d%3D%22M4%2C28.7c0%2C0%2C8-6.8%2C16%2C0v-22c-8-6.8-16%2C0-16%2C0V28.7z%22%2F%3E%0A%20%20%20%20%20%20%20%20%20%20%3Cpath%20id%3D%22XMLID_3_%22%20class%3D%22st0%22%20d%3D%22M36%2C28.7c0%2C0-8-6.8-16%2C0v-22c8-6.8%2C16%2C0%2C16%2C0V28.7z%22%2F%3E%0A%20%20%20%20%20%20%3C%2Fg%3E%0A%20%20%3C%2Fsvg%3E',

    /**
     * Build the HTML for the Lens link.
     *
     * @param defineBehaviour Function that defines the behaviour to bind
     * @return {HTMLElement} The built element with bound behaviour
     */
    buildLensLink = function buildLensLink(defineBehaviour) {
      var linkWrapper = document.createElement('DIV'),
        link = document.createElement('A'),
        img = document.createElement('IMG'),
        text1 = document.createElement('DIV'),
        text2 = document.createElement('DIV');

      linkWrapper.classList.add('lens-link');
      link.classList.add('lens-link__link');
      link.href = getPathToLensVersion();
      img.classList.add('lens-link__image');
      img.src = svgDataBookUriEnc;
      img.alt = 'eLife Lens icon';
      text1.classList.add('lens-link__text');
      text1.innerHTML = 'Read eLife articles distraction free';
      text2.classList.add('lens-link__extra');
      text2.innerHTML = 'Powered by Lens';

      link.appendChild(img);
      linkWrapper.appendChild(link);
      text1.appendChild(text2);
      linkWrapper.appendChild(text1);
      // Delivers consistent results whether or not logged in.
      injectLink(linkWrapper, document.querySelector('.elife-article-layout'));
      defineBehaviour(linkWrapper);
      return linkWrapper;
    },

    /**
     * Define the behaviour for the Lens link.
     */
    lensLinkBehaviour = function lensLinkBehaviour(link) {
      var lensLinkEl = link.querySelector('.lens-link__link'),
        lensLinkText = link.querySelector('.lens-link__text'),

        hideLensLinkText = function hideLensLinkText() {
          lensLinkText.classList.add('fadeout');
          // Allow the article text under faded lensLinkText to be selectable.
          // Keep delay slightly longer than the duration specified in 
          // elife_lens_link.css:a.lens-link__link transition property.
          var delayInMs = 1500;
          window.setTimeout(function () {
            lensLinkText.classList.add('collapse');
          }, delayInMs);

        },

        showLensLink = function showLensLink() {
          lensLinkText.classList.remove('collapse');
          lensLinkText.classList.remove('fadeout');
          unmuteLensLink();
        },

        muteLensLink = function muteLensLink() {
          lensLinkEl.classList.add('knockback');
        },

        unmuteLensLink = function unmuteLensLink() {
          lensLinkEl.classList.remove('knockback');
        },

      // Used to determine when scrolling has finished.
        scrollTimer = -1;

      // After 2s:
      //  - hide Lens link text
      //  - allow Lens link to be muted on scroll
      //  -   and unmuted ~0.5s after scrolling has finished.
      window.setTimeout(function () {
        hideLensLinkText();
        window.addEventListener('scroll', function () {
          muteLensLink();
        }, false);

        // Initialise the scroll timer.
        scrollTimer = window.setTimeout(function () {
          unmuteLensLink();
        }, 500);
      }, 2000);

      // Separate scroll handler: we don't want this one to be subject to the
      // timeout.
      window.addEventListener('scroll', function () {
        // Reset scroll timer on scroll.
        if (scrollTimer > -1) {
          window.clearTimeout(scrollTimer);
          // If 0.5s elapsed since the most recent scroll event, unmute link.
          scrollTimer = window.setTimeout(function () {
            unmuteLensLink();
          }, 500);
        }

        // Anchor/unanchor link depending on scroll position.
        if (link.getBoundingClientRect().top <= 75 && link.style.position !== 'fixed') {
          link.classList.add('anchor-to-top');
        }

        if (window.pageYOffset < 275 && link.style.position !== 'relative') {
          link.classList.remove('anchor-to-top');
        }
      }, false);

      lensLinkEl.addEventListener('mouseenter', showLensLink, false);
      lensLinkEl.addEventListener('mouseleave', hideLensLinkText, false);
    },

    /**
     * Sends Lens link events to GA.
     *
     * If provided, hitCallback is invoked by ga.send after Google has
     * received the event data. (See:
     * https://developers.google.com/analytics/devguides/collection/analyticsjs/advanced)
     * Used here to ensure Google receives click events from links that will
     * unload the page, before the page is unloaded. If ga is unavailable,
     * hitCallback is explicitly invoked here to ensure the intention behind
     * the original click is honoured.
     *
     *
     * @param action The GA action to log
     * @param message The GA message to log
     * @param hitCallback callback function to run once Google received data
     */
    sendToGa = function sendToGa(action, message, hitCallback) {
      // Determine if Google Analytics has loaded, giving it to local
      // variable ga if it has.
      var ga = (function (candidate) {
        var isValid = !!candidate &&
                      candidate.hasOwnProperty('loaded') &&
                      candidate.loaded;
        if (isValid) {
          return candidate;
        }
      }(window.ga));
      // If there's been a problem loading ga, any hitCallback won't run,
      // so if one is supplied, explicitly invoke it here.
      // (Might be better to use throw with try/catch for this.)
      if (!ga && typeof hitCallback === 'function') {
        hitCallback();
        return;
      } else {
        // No ga object available.
        return
      }
      // Create the ga tracker if it hasn't already been created.
      if (!ga.getByName('interactionTracking')) {
        ga('create', 'UA-48379231-2', {'name': 'interactionTracking'});
      }
      if (typeof hitCallback === 'function') {
        ga('interactionTracking.send', 'event', 'Lens link', action, message,
          {'hitCallback': hitCallback});
      } else {
        ga('interactionTracking.send', 'event', 'Lens link', action, message);
      }
    },

    /**
     * Sets up logging message to GA when el is hovered over for thresholdInMs.
     *
     * @param el Element to log hovers over
     * @param message Message to send to GA
     * @param thresholdInMs Time mouse must hover before event logged
     */
    setupHoverLogging = function setupHoverLogging(el, message, thresholdInMs) {
      var hoverTracker = -1,
        hoverTarget = (function (elmt) {
          if (elmt.nodeName === 'A') {
            return elmt;
          }
          return elmt.querySelector('a');
        }(el)),

        handleMouseEnter = function handleMouseEnter() {
          if (hoverTracker > -1) {
            window.clearTimeout(hoverTracker);
          }
          hoverTracker = window.setTimeout(function () {
            sendToGa('Hover', message);
            hoverTracker = -1;
          }, thresholdInMs);
        },

        handleMouseLeave = function handleMouseLeave() {
          if (hoverTracker > -1) {
            window.clearTimeout(hoverTracker);
          }
        };

      hoverTarget.addEventListener('mouseenter', handleMouseEnter, false);
      hoverTarget.addEventListener('mouseleave', handleMouseLeave, false);
    },

    displayCriterion = '(min-width: 768px)',

    gaMessage = 'Lens Button',

    /**
     * Set up event handlers to log Lens link interactions to GA.
     *
     * @param link Link to attach event handlers to
     * @param message Message to send to GA.
     */
    setupEventHandlersGa = function setupEventHandlersGa(link, message) {

      var significantHoverTimeInMs = 600,

        handleClick = function handleClick(e) {
          var target = e.target,

            dispatchNewClick = function dispatchNewClick() {
              // Use old style event creation so doesn't break IE.
              var newEvent = document.createEvent('MouseEvents');
              newEvent.initEvent("click", true, true);
              target.dispatchEvent(newEvent);
            };

          e.preventDefault();
          link.removeEventListener('click', handleClick, false);
          sendToGa('Click', message, dispatchNewClick);
        };

      link.addEventListener('click', handleClick, false);
      setupHoverLogging(link, message, significantHoverTimeInMs);
    },

    isLoadFired = false,

    /**
     * If there's enough space, build the Lens link then stop trying to.
     */
    handleResize = function handleResize() {
      var lensLink;
      if (isEnoughSpaceToDisplayLensLink(displayCriterion)) {
        lensLink = buildLensLink(lensLinkBehaviour);
        window.removeEventListener('resize', handleResize, false);
        if (isLoadFired) {
          sendToGa('Displayed', gaMessage);
          setupEventHandlersGa(lensLink, gaMessage);
        }
      }
    };

  /*
   * Summary of intention re event sequencing.
   *
   * On DOMContentLoaded:
   *  if not capable or not on article page:
   *     bail
   *  if wide enough:
   *     show link within 1 second
   *  else on resize:
   *    if wide enough:
   *      show link
   *      stop checking each resize
   *    if load has fired:
   *      set up event handlers for GA messages
   *
   * on load:
   *   set flag indicating load has fired
   *   if link already shown:
   *     set up event handlers for GA messages
   * */
  window.addEventListener('DOMContentLoaded', function () {
    var lensLink = null,
      loadTimer;
console.log('Inside DOMContentLoaded');
    // Bail if the browser is not likely to be able to use Lens,
    // or there is no Lens version available.
    if (!canProbablyUseLens() || getPathToLensVersion() === '#') {
      return;
    }

    if (isEnoughSpaceToDisplayLensLink(displayCriterion)) {
      // Show lens link max 1 second after DOMContentLoaded, whether or not load has
      // fired by then.
      loadTimer = window.setTimeout(function () {
        lensLink = buildLensLink(lensLinkBehaviour);
      }, 1000);
    } else {
      // There is an edge case here: if  the viewport is resized before timeout
      // finished, the element will be displayed earlier than the timeout.
      // This is not a concern.
      window.addEventListener('resize', handleResize, false);
    }

    // Once load fired, initialise the link if it's not been done yet, then
    // set up GA-related event handlers.
    window.addEventListener('load', function () {
      isLoadFired = true;
      if (!lensLink) {
        window.clearTimeout(loadTimer);
        lensLink = buildLensLink(lensLinkBehaviour);
      }
      sendToGa('Displayed', gaMessage);
      setupEventHandlersGa(lensLink, gaMessage);
    }, false);
  }, false);

}(window, window.document));
