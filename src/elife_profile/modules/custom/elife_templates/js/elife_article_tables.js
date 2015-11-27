/**
 * eLife Article Tables
 */
(function ($) {
  Drupal.behaviors.eLifeArticleTables = {
    attach: function(context, settings) {
      var $tables = $('.table-expansion');
      var $tablesToCollapse = $();
      $tables.each(function () {
        if (!$(this).parents('.fragment-type--table-wrap').length) {
          $tablesToCollapse = $tablesToCollapse.add(this);
        }
      });
      if ($tablesToCollapse.length) {
        var setupTableColorbox = function () {
          var $fragment_tables = $('a[rel="gallery-fragment-tables"]', context);
          $fragment_tables.once(function () {
            var $wrapper = $(this).closest('.table-expansion').clone();
            $('.table-inline', $wrapper).remove();
            $('table, .table-foot', $wrapper).show();
            $(this).data('table-html', $wrapper.html());
          });

          $fragment_tables.colorbox({title: false, width: 1050, height: 615, html: function () { return $(this).data('table-html'); }, className: 'table-expansion', current: "{current} of {total}"});
        };

        $('.table-expansion', context).once('eLifeArticleTableExpansion', function () {
          $(this).prepend('<div class="table-inline"><div class="callout"><span>View this table:</span><ul class="callout-links"><li><a href="#" class="table-expand-popup" rel="gallery-fragment-tables">View popup</a></li><li><a href="#" class="table-expand-inline">View inline</a></li></ul></div></div>');
        });
        $('a.table-expand-inline', context).once('eLifeArticleTablesMarkup', function() {
          $(this, context).each(function() {
            var $inlineToggler = $(this);
            var $table = $('table, .table-foot', $inlineToggler.closest('.table-expansion'));

            $table.hide();
            
            $inlineToggler.click(function(event) {
              var $target = $(this);
              event.preventDefault();
              if ($table.is(':hidden')) {
                $table.show();
                $target.html('Collapse inline');
              } else {
                $table.hide();
                $target.html('View inline');
              }
            });
          });
        });
        setupTableColorbox();
      }
    }
  };
})(jQuery);
