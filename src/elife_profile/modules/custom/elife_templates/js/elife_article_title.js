(function ($) {
  Drupal.behaviors.articleTitleTip = {
    attach: function (context, settings) {
      $('.js-trigger-cluetip', context).each(function() {
        $(this).cluetip({
          arrows: false,
          cursor: 'pointer',
          sticky: true,
          local: true,
          hideLocal: false,
          mouseOutClose: false,
          activation: 'click',
          positionBy: 'auto',
          snapToEdge: true,
          showTitle: false,
          dropShadow: false,
          leftOffset: 20,
          width: 275
        });
      });
    }
  };
})(jQuery);
