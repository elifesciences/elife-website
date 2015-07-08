(function ($) {
  Drupal.behaviors.elifeArticleAuthors = {
    attach: function (context, settings) {
      $('.elife-article-author-item', context).each(function() {
        $(this).cluetip({
          onActivate: function(event) {var currentLayout = Drupal.omega.getCurrentLayout(); return currentLayout == 'mobile' ? false : true;},
          arrows: true,
          cursor: 'pointer',
          titleAttribute: 'data-tooltip-content',
          splitTitle: '|',
          sticky: true,
          mouseOutClose: 'both',
          activation: 'hover',
          positionBy: 'topBottom',
          snapToEdge: true,
          showTitle: false,
          dropShadow: false,
          width: 450
        });

        $(this).hover(function() {
          var insts = $(this).attr('class').split(/\s+/);
          for (var inst in insts) {
            $('.elife-institutions-list .' + insts[inst]).addClass('institution-highlight');
          }
        }, function() {
          $('.elife-institution').removeClass('institution-highlight');
        });
      });
    }
  };
})(jQuery);
