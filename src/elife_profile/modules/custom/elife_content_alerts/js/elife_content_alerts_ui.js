(function ($) {
  Drupal.behaviors.elifeContentAlertsUi = {
    attach: function (context, settings) {
      $('body', context).once('elife-content-alerts-ui', function () {
        var origin = window.location.protocol + '//' + window.location.host,
          args = window.location.pathname.substring(1).split('/').slice(2),
          status = args[0].toLowerCase(),
          dates = args[1].split('--');

        $.ajax({
          dataType: 'json',
          url: origin + '/elife/content_alerts_json/content_alerts_' + status + '/' + dates[1] + '/' + dates[0],
          // Time out after 30 secs.
          timeout: 30000,
          success: function (data) {
            var markup = $('<div class="elife_content_alerts_markup"></div>'),
              revealStr = Drupal.t('Reveal markup for content alert emails'),
              hideStr = Drupal.t('Hide markup for content alert emails'),
              textareaAttr = ' class="elife_copy_and_paste" style="width: 100%; height: 400px;"';

            markup.append('<h3>HTML</h3><textarea' + textareaAttr + '>' + data.html + '</textarea>');
            markup.append('<h3>Plain text</h3><textarea' + textareaAttr + '>' + data.plain + '</textarea>');
            markup.hide();
            markup.insertBefore($('#email'));
            $('<h2 class="elife_content_alerts_markup__title">' + revealStr + '</h2>').insertBefore(markup);
            $('.elife_content_alerts_markup__title').toggle(function () {
              $(this).text(hideStr);
              markup.show();
            }, function () {
              $(this).text(revealStr);
              markup.hide();
            });
          }
        });
      });
    }
  };
})(jQuery);
