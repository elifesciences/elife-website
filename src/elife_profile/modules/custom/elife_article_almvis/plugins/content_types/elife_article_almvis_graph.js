/**
 * @file
 * Adds one behaviours to the Article Metrics page.
 *
 * elifeArticleAlmviz:
 *    Uses an AJAX query to read the article pageview data for the DOI
 *  provided in the associated DIV, and display that data by calling AlmViz
 *  graphing tool (which in turn uses D3).
 *
 *  The page must load D3, bootstrap.tooltip and almviz (alm.js).
 */
(function ($) {
  Drupal.behaviors.elifeArticleAlmviz = {
    attach: function (context, settings) {
      $('#elife-article-almvis-chart', context).each(function () {
        var html = { 
          name: 'html',
          display_name: Drupal.t('HTML views'),
          tooltip_text: Drupal.t('Total number of HTML page views for this article.')
        }

        var pdf = { 
          name: 'pdf',
          display_name: Drupal.t('PDF downloads'),
          tooltip_text: Drupal.t('Total number of PDF downloads for this article.')
        }

        var abstract = { 
          name: 'abstract',
          display_name: Drupal.t('Abstract views'),
          tooltip_text: Drupal.t('Total number of abstract page views for this article.')
        }

        if($(this).data('earlyarticle') == '1') {
          if($(this).data('pdf') == 'TRUE') {
            var data_categories = [abstract, pdf];
          }
          else {
            var data_categories = [abstract];
          }
        }
        else {
          if($(this).data('pdf') == 'TRUE') {
            var data_categories = [html, pdf];
          }
          else {
            var data_categories = [html];
          }
        }

        $.getJSON(settings.basePath + 'elife/article-pageview-data/' + $(this).data('doi'), function (jsondata) {
          var options = {
            almStatsJson: jsondata,
            dailyNDays: Drupal.settings.elifeArticleAlmvis.dailyNDays - 1,
            baseUrl: settings.basePath,
            chartHeight: 150,
            chartWidth: 425,
            minItemsToShowGraph: {
              minEventsForYearly: 1,
              minEventsForMonthly: 1,
              minEventsForDaily: 1,
              minYearsForYearly: 2,
              minMonthsForMonthly: 2,
              minDaysForDaily: 1
            },
            vizDiv: '#elife-article-almvis-chart',
            hasIcon: [],
            showTitle: false,
            showSources: false,
            showSourceLinks: false,
            categories: data_categories
          };
          var almviz = new AlmViz(options);
          if (almviz.initViz) {
            almviz.initViz();
          }
        });
      });
    }
  };
})(jQuery);
