(function ($) {
  Drupal.behaviors.eLifeFigDataTab = {
    attach: function(context, settings) {
      $('.elife-fig-data-title-jump-link', context).each(function() {
        var $href = $('a', this).attr('href');
        
        if ($href && $($href).length == 0) {
          $(this).hide();
        }
      });
    }
  };
})(jQuery);

