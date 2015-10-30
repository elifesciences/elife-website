/**
 * eLife Article References pop up
 */
(function ($) {
  Drupal.behaviors.eLifeArticleRef = {
    attach: function(context, settings) {
      $('a.xref-bibr', context).each(function() {
        $(this).attr('rel', $(this).attr('href'));
      });

      $('a.xref-bibr').cluetip({
        onActivate: function(event) {var currentLayout = Drupal.omega.getCurrentLayout(); return currentLayout == 'mobile' ? false : true;},
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
