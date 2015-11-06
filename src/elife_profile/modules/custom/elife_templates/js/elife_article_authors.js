(function ($) {
  Drupal.behaviors.elifeArticleAuthors = {
    attach: function (context, settings) {
      $('body').once('elife-article-authors', function () {
        $('.author-list-full').addClass('visible-small');
        $('.elife-article-author-item', context).each(function() {
          if ($('.author-list-full .' + $(this).data('affiliation')).length > 0) {
            $(this).attr('data-tooltip-content', '|' + $('.author-list-full .' + $(this).data('affiliation')).html());
            $(this).addClass('elife-article-author-item-has-aff');
          }
        });

        $('.elife-article-author-item-has-aff', context).each(function() {
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
            $('.elife-institutions-list .' + $(this).data('affiliation')).addClass('institution-highlight');
          }, function() {
            $('.elife-institution').removeClass('institution-highlight');
          });
        });
      });
    }
  };
})(jQuery);
