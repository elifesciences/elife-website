/**
 * @file
 * Adds the jump to behaviour to the monthly archive drop down
 */
(function ($, window) {
  Drupal.behaviors.elifeArchiveGoto = {
    attach: function () {
      var origin = window.location.protocol + '//' + window.location.host;

      $('#elife-archive-goto-form').once('elife-archive-goto', function () {
        if ($('#edit-elife-archive-month option[selected="selected"]').length === 0) {
          $('#edit-elife-archive-month').prepend('<option value="_none">' + $('#elife-archive-goto-form label').text() + '</option>');
          $('#elife-archive-goto-form label').hide();
          $('#edit-elife-archive-month')[0].selectedIndex = 0;
        }
      });

      $('#elife-archive-goto-form .form-submit').hide();

      $('#edit-elife-archive-month').change(function () {
        $('#edit-elife-archive-month option[value="_none"]').remove();
        window.location.replace(origin + $(this).val());
      });
    }
  };
})(jQuery, this);
