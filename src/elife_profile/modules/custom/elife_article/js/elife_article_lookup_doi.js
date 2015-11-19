/**
 * Lookup DOI Redirect
 */
(function($) {
  $('document').ready(function() {
    var timerCount = Drupal.settings.doi_redirection.count;

    // tick the timer from timeCount to 0 n then redirect to url
    function redirectCountDown() {
      timerCount--;

      // redirect to url on timerCount zero and clear interval
      if(timerCount == 0) {
        clearInterval(timer);
        window.location = Drupal.settings.doi_redirection.url;
      }

      // fill the timerCount 
      $('#doi_countdown').html(timerCount);
    }
    // set the interval 
    var timer = setInterval(redirectCountDown, 1000);
  });
})(jQuery);
