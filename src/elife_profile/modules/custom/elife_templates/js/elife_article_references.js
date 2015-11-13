/**
 * eLife Article References
 * 
 * A reference list has an original listing order, but
 * the listing order may be changed and with sort controls. When the
 * references are listed out of their original order, the original
 * ordinal still needs to be displayed next to its associated reference.
 * 
 * For example, if the original order is:
 *  1. Shadows in a cave 
 *     Smith J, Bloggs F
 *
 *  2. Flawed hope and the ideal
 *     Clarke G, Zinelli T
 *     
 * Then when sorted by author name, the list would be:
 *  2. Flawed hope and the ideal
 *     Clarke G, Zinelli T
 *
 *  1. Shadows in a cave
 *     Smith J, Bloggs F
 *
 * To retain this information, in light of the unreliable nature of the 
 * reference's id value (e.g. "bib25" doesn't always correspond to the 25th
 * reference), the original order of the references is analysed and stored in 
 * referenceOrdinals on initial page load.
 *
 */
(function ($) {
  "use strict";
  var referenceOrdinals;
  
  $(function () {
    function buildOrdinalEl(data, $parent) {
      if (isNaN(parseInt(data, 10))) {
        throw new TypeError('Error establishing original reference ordinals. Ordinal data "' + data + '" is not a number.');
      }
      $parent.prepend($('<span class="reference-ordinal"> ' + data + '</span>'));
      $parent.addClass('no-counter');
    }

    function buildReferenceOrdinals() {
      var ordinals = {};
      $('.elife-reflinks-reflink', '#references').each(function (i) {
        var id = this.id;
        ordinals[id] = i + 1;
        buildOrdinalEl(ordinals[id], $(this));
      });
      return ordinals;
    }

    try {
      // Each reference's ordinal in the default sort order:
      // {id value: originalOrdinal} e.g. {"bib25", 25}
      referenceOrdinals = buildReferenceOrdinals();
    } catch (e) {
      // TODO: when implementing the reference sort, bail if this catches the TypeError thrown from buildOrdinalEl: the original ordinals will not be available.
      // Stops ref popups if original ordinals aren't available.
      $('a.xref-bibr').cluetip(null);
    }
  });

  Drupal.behaviors.eLifeArticleRef = {
    
    attach: function(context, settings) {
      
      $('a.xref-bibr', context).each(function() {
        $(this).attr('rel', $(this).attr('href'));
      });

      $('a.xref-bibr').cluetip({
        onActivate: function(event) {
          return Drupal.omega.getCurrentLayout() !== 'mobile';
        },
        
        local: true,
        cursor: 'pointer',
        showTitle: false, 
        width: '450px',
        arrows: true,
        hideLocal: false,
        sticky: true,
        mouseOutClose: 'both',
        closePosition: 'none',
        positionBy: 'topBottom',
        snapToEdge: true,
        dropShadow: false
      });
    }
  };
})(jQuery);
