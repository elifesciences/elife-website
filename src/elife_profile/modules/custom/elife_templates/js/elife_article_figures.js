/**
 * eLife Article Figures
 */
(function ($) {
  Drupal.behaviors.eLifeArticleFigures = {
    attach: function(context, settings) {
      var triggerFigGroupJump = function (ref) {
        $('.elife-fig-slider-img a[href="' + ref + '"]').each(function() {
          $(this).trigger('mouseover');
        });
      };

      // Fit the images to their frame
      $('.elife-fig-slider-img', context).each(function() {
        var $image = $('img', this);
        var size = $(this).height();
        
        if ($image.height() > $image.width()) {
          $image.css('width', size);
        }
        else {
          $image.css('height', size);
        }
      });
      
      // Carousel
      $('.elife-fig-slider-wrapper', context).once('eLifeArticleFiguresSlider', function() {
        // @todo - elife - nlisgo - this carousel needs to be tested
        var $wrapper = $(this);
        var numItems = $('.elife-fig-slider-secondary', $wrapper).length;
        
        $('.figure-carousel', $wrapper).css('overflow', 'hidden');
        var numPer = 4; // Number of items per carousel-slide
        if (numItems > numPer) {
        
          var scrollTarget;
          var sliderIndex = 1;
          var pages = Math.ceil(numItems / numPer);
          var height = $('.figure-carousel', $wrapper).outerHeight();
          var partHeight = $('.elife-fig-slider-secondary').outerHeight();
          
          $('.figure-carousel-inner-wrapper', $wrapper).prepend('<div class="button-disabled figure-carousel-up"></div>');
          $('.figure-carousel-inner-wrapper', $wrapper).append ('<div class="figure-carousel-down"></div>');
          
          $('.figure-carousel-up, .figure-carousel-down', $wrapper).click(function() {
            
            $('.figure-carousel-down', $wrapper).removeClass('button-disabled');
            $('.figure-carousel-up', $wrapper).removeClass('button-disabled');
            
            if ($(this).hasClass('figure-carousel-down')) {
              sliderIndex++;
            }
            else {
              sliderIndex--;
            }
            
            // Clamp the slide-index and apply disabled class if needed
            if (sliderIndex <= 1) {
              $('.figure-carousel-up', $wrapper).addClass('button-disabled');
              sliderIndex = 1;
            }
            if (sliderIndex >= pages) {
              $('.figure-carousel-down', $wrapper).addClass('button-disabled');
              sliderIndex = pages;
            }
            
            // Set the scroll target
            if ($(this).hasClass('figure-carousel-down')) {
              if (sliderIndex == pages) {
                scrollTarget = 'max';
              }
              else {
                scrollTarget = (height*(sliderIndex-1)) + 'px';
              }
            }
            else {
              if (sliderIndex == 1){
                scrollTarget = '0px';
              }
              else {
                scrollTarget = (height*(sliderIndex-1)) + 'px';
              }
            }
            
            // Move the carousel
            $('.figure-carousel', $wrapper).scrollTo(scrollTarget, 500);
          });
        }
      });
      
      // Image switcher
      $('.fig-inline-img-set-carousel', context).each(function() {
        var set = this;

        $('.fig', set).hide();
        $('.fig:first', set).show();
        
        $('.elife-fig-slider-img a', set).hover(function() {
          $('.elife-fig-slider-img').removeClass('active-icon');
          $(this).parent().addClass('active-icon');
          $('.fig', set).hide();
          $($(this).attr('href'), set).parent().show();
        });
        
        $('.elife-fig-slider-img:first', set).addClass('active-icon');
      });
      
      // Anchor triggers for image-switcher
      $('a.xref-fig').click(function() {
        var target = $(this).attr('href');
        triggerFigGroupJump(target);
      });

      $(window).bind('hashchange', function () {
        // @todo - elife - nlisgo - If page accessed with fragment identifier then trigger mouseover
        triggerFigGroupReference(window.location.hash);
      });

      $('.fig-inline-img-set-carousel', context).each(function () {
        var rel = 'gallery-fragment-figures-' + $('.fig-inline-img-set:first', $(this)).attr('id');
        $('.fig-inline-img a', $(this)).attr('rel', rel);
      });

      $('.fig-inline-img a', context).each(function () {
        var $figCaption = $('.fig-caption', $(this).closest('.fig-expansion')).clone(),
          figCaptionHtml;
        $('.elife-figure-links, .supplementary-material', $figCaption).remove();
        figCaptionHtml = $figCaption[0].outerHTML;

        $(this).data('figure-caption', figCaptionHtml);
      });
      $('a.figure-expand-popup', context).colorbox({title: false, inline: true, width: 1000, height: 500, current: "{current} of {total}"});

      // Colorbox modifications
      $(document).bind('cbox_complete', function(){
        if ($.colorbox.element().hasClass('figure-expand-popup')) {

          // Decode the caption as it is in the data attribute and put it in the caption area
          var decodeCaption = function() {
            var $title = $('#cboxTitle', '#cboxContent');
            var caption = $("<div/>").html($.colorbox.element().data('figure-caption'));
            $title.css('display', 'none');
            $title.html(caption);
          };
          var href = $.colorbox.element().attr('href');
          // Disable the current trigger that shows the figure description
          $('img', '#cboxLoadedContent').unbind('mouseover').unbind('mouseout');
          $('#cboxOverlay').unbind('mouseover');

          decodeCaption();

          $('.elife-cboxfigure-link-wrapper', '#cboxCurrent').remove();
          var $links = $('<span class="elife-cboxfigure-link-wrapper"/>');

          $links.append('<span class="elife-cboxfigure-link elife-cboxfigure-desc first"><a href="#">View caption</a><span> | ');
          $links.append('<span class="elife-cboxfigure-link elife-cboxfigure-wind"><a href="' + href + '" target="_blank">Open in new window</a><span> | ');
          $links.append('<span class="elife-cboxfigure-link elife-cboxfigure-down last"><a href="' + href + '?download=true">Download figure</a><span>');

          $('#cboxCurrent', '#cboxContent').append($links);
          $('#cboxCurrent', '#cboxContent').show();

          $('.elife-cboxfigure-desc a').click(function() {
            $('#cboxTitle', '#cboxContent').toggle();
            return false;
          });

        }
      });

      $(document).bind('cbox_cleanup', function(){
        $('#cboxTitle', '#cboxContent').empty();
      });
    }
  };
})(jQuery);

