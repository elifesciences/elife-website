(function ($) {
  Drupal.behaviors.manipulateFormElements = {
    attach: function(context, settings) {
      
    // Allow form radio labels to be "clickable" on iPad & iPhone.
    if (navigator.userAgent.match(/iPhone/i) || navigator.userAgent.match(/iPod/i) || navigator.userAgent.match(/iPad/i)) {
      $('label[for]').click(function () {
        var el = $(this).attr('for');
        if ($('#' + el + '[type=radio], #' + el + '[type=checkbox]').attr('selected', !$('#' + el).attr('selected'))) {
          return;
        } else {
          $('#' + el)[0].focus();
        }
      });
    }
         
    // Give the login form some love
    $('#user-login-form .login-submit-link').click(function(){
    	$('#user-login-form').submit();
    	return false;
    });
    }
  };
  
  Drupal.behaviors.mobileMenu = {
    attach: function (context, settings) {
      //START
      
      // Mobile Menu toggle
      var $mobilePane = $('.pane-menu-menu-mobile-menu', context);
      $mobilePane.find('.pane-title').click(function(){
        $mobilePane.find('.pane-content').toggleClass('expanded');  
      });
      // Submenus
      $mobilePane.find('ul.menu li.expanded a').click(function(e){
        e.preventDefault();
        $(this).parent('li').toggleClass('show');
      });

      // Expand search when focused
      var $quicksearch = $('.pane-elife-searchlist-quicksearch', context);
      $quicksearch.find('input').focus(function(){ $quicksearch.addClass('focus'); });
      $quicksearch.find('input').blur(function(){ $quicksearch.removeClass('focus'); });
    
      
      //END
    }
  };  
  
})(jQuery);
