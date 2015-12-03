jQuery(document).ready(function($) {
  var url = Drupal.settings.elife_article_toolbox.url;
  $('.panel-separator--reference-tools, .reference-tools', '.sidebar-wrapper').removeClass('hidden');
  $('.st_reddit').after('<span class="st-mendeley"><a class="stButton" target="_blank" href="http://www.mendeley.com/import/?' + url + '"><span class="chicklets mendeley">Mendeley</span></a></span>');
  
  $('.api_button').click(function(){
    $('#api_box').toggle('fast');
    return false;
  });
 
  $('.citation-links > li').removeClass('show-article-toolbox-tooltip');
  
  $('.citation-links > li').hover(function(){
    $(this).toggleClass('show-article-toolbox-tooltip');
  }, function(){
    $(this).toggleClass('show-article-toolbox-tooltip');
  });
  
$('.print').click(function() {
    $('.ctools-collapsible-content').show();
    window.print();
    return false;
  });
});
