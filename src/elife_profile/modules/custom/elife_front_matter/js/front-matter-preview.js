(function ($, window) {
  "use strict";
  Drupal.behaviors.elifeCoverPagePreview = {
    attach: function () {
      var origin = window.location.protocol + '//' + window.location.host,
        // Set behaviour for dropdown when selection made.
        limitDropdownChange = function ($dropdownEl, $messageEl, $wrapperEl) {
          setLimitFromDropdown($dropdownEl, false);
          $dropdownEl.change(function () {
            setLimitFromDropdown($(this), true, $messageEl, $wrapperEl);
          });
        },
        // Prepare a dropdown element to be introduced to the markup.
        prepareLimitDropdown = function (colPos) {
          var limit = parseInt(Drupal.settings.elifeCoverPagePreview.colItemsLimit),
            activeOpt,
            output = '',
            i,
            oUrl = Drupal.settings.basePath + 'front-matter/previewitems/',
            oUrlValPre = '',
            oUrlValPost = '',
            oUrlJoin,
            selected;

          if (colPos === 2) {
            activeOpt = parseInt(Drupal.settings.elifeCoverPagePreview.colItems2);
            oUrlValPre = '0/0/';
          }
          else {
            activeOpt = parseInt(Drupal.settings.elifeCoverPagePreview.colItems1);
            oUrlValPre = '0/';
            oUrlValPost = '/0';
          }

          output += '<label>' + Drupal.t('Items to display') + ': ';
          output += '<select class="front-matter-limit-set">';
          for (i = limit; i >= 1; i--) {
            oUrlJoin = oUrl + oUrlValPre + i + oUrlValPost;
            selected = '';
            if (i === activeOpt) {
              selected = ' selected="selected"';
            }
            output += '<option value="' + oUrlJoin + '"' + selected + '>' + i + '</option>';
          }
          output += '</select>';
          output += '</label>';

          return output;
        },
        // Prepare a button to transfer nodes from preview to live entityqueues.
        prepareTransferButton = function (colPos) {
          var activeOpt,
            output = '',
            oUrl = Drupal.settings.basePath + 'front-matter/preview2live/',
            oUrlValPre = '',
            oUrlValPost = '',
            oUrlJoin,
            oClass,
            bText;

          if (colPos === 1) {
            activeOpt = Drupal.settings.elifeCoverPagePreview.colItems1;
            oUrlValPre = '0/';
            oUrlValPost = '/0';
            oClass = '1';
            bText = Drupal.t('Transfer <span class="items">@items</span> item(s) in column @col to live', {
              '@items': activeOpt,
              '@col': 1
            });
          }
          else if (colPos === 2) {
            activeOpt = parseInt(Drupal.settings.elifeCoverPagePreview.colItems2);
            oUrlValPre = '0/0/';
            oClass = '2';
            bText = Drupal.t('Transfer <span class="items">@items</span> item(s) in column @col to live', {
              '@items': activeOpt,
              '@col': 2
            });
          }
          else if (colPos === 3) {
            activeOpt = '1';
            oUrlValPost = '/0/0';
            oClass = 'cover';
            bText = Drupal.t('Transfer cover to live');
          }
          else {
            activeOpt = Drupal.settings.elifeCoverPagePreview.colItems1;
            activeOpt += '/';
            activeOpt += Drupal.settings.elifeCoverPagePreview.colItems2;
            oUrlValPre = '1/';
            oClass = 'all';
            bText = Drupal.t('Transfer both columns and cover to live');
          }

          oUrlJoin = oUrl + oUrlValPre + activeOpt + oUrlValPost;
          output += '<form class="front-matter-transfer-live front-matter-transfer-live-' + oClass + '" action="' + oUrlJoin + '">';
          output += '<button>' + bText + '</button>';
          output += '</form>';

          return output;
        },
        // Set class on element to indicate ajax processing.
        indicateAjaxProcessStart = function ($wrapperEl) {
          $wrapperEl = prepareWrapperEl($wrapperEl);
          $wrapperEl.addClass('frontmatter-widgets-ajax-processing');
        },
        // Set class and behaviour on element to indicate ajax processed.
        indicateAjaxProcessStop = function ($wrapperEl, type) {
          var classExtra = '',
            processedClass = 'frontmatter-widgets-ajax-processed';

          switch (type) {
            case 'error':
              classExtra = '-error';
              break;
            case 'warning':
              classExtra = '-warning';
              break;
            default:
              break;
          }

          processedClass += classExtra;

          $wrapperEl = prepareWrapperEl($wrapperEl);
          $wrapperEl.removeClass('frontmatter-widgets-ajax-processing');
          $wrapperEl.addClass(processedClass);
          setTimeout(function(){
            $wrapperEl.removeClass(processedClass);
          }, 1000);
        },
        // When selection made on dropdown, react to choice by adjusting stored limit and display.
        setLimitFromDropdown = function ($selEl, jsonGet, $messageEl, $wrapperEl) {
          var $parentEl = $selEl.closest('.view-elife-coverpage-front-matter'),
            selURL = $selEl.val(),
            selVal = $('option:selected', $selEl).text();
          $wrapperEl = prepareWrapperEl($wrapperEl);

          if (jsonGet) {
            disableWidgets();
            hideMessages($messageEl);
            indicateAjaxProcessStart($wrapperEl);
            $.ajax({
              dataType: 'json',
              url: origin + selURL,
              // Time out after 30 secs.
              timeout: 30000,
              success: function (data) {
                displayMessages(data.messages, $messageEl);
                alterLimitDisplay(selVal, $parentEl);
                alterTransferLinks(data.transferLinks);
                indicateAjaxProcessStop($wrapperEl);
                enableWidgets();
              },
              error: function () {
                displayErrorMessage($messageEl);
                indicateAjaxProcessStop($wrapperEl, 'error');
                enableWidgets();
              }
            });
          }
          else {
            alterLimitDisplay(selVal, $parentEl);
          }
        },
        // Display the appropriate number of items in each column based upon selected option.
        alterLimitDisplay = function (selVal, $parentEl) {
          $('.view-content > div', $parentEl).hide();
          $('.view-content > div:lt(' + selVal + ')', $parentEl).show();
          $('.front-matter-transfer-live span.items', $parentEl).text(selVal);
        },
        // Alter the action attribute of the transfer forms appropriately.
        alterTransferLinks = function (transferLinks) {
          $('.front-matter-transfer-live-1').attr('action', transferLinks.col1);
          $('.front-matter-transfer-live-2').attr('action', transferLinks.col2);
          $('.front-matter-transfer-live-all').attr('action', transferLinks.all);
        },
        // Transfer the appropriate number of nodes to the live entityqueue.
        transferToLive = function ($formEl, $messageEl, $wrapperEl) {
          $wrapperEl = prepareWrapperEl($wrapperEl);
          $formEl.submit(function () {
            disableWidgets();
            hideMessages($messageEl);
            indicateAjaxProcessStart($wrapperEl);
            $.ajax({
              dataType: 'json',
              url: $(this).attr('action'),
              // Time out after 30 secs.
              timeout: 30000,
              success: function (data) {
                displayMessages(data.messages, $messageEl);
                indicateAjaxProcessStop($wrapperEl);
                enableWidgets();
              },
              error: function () {
                displayErrorMessage($messageEl);
                indicateAjaxProcessStop($wrapperEl, 'error');
                enableWidgets();
              }
            });
            return false;
          });
        },
        // Set default element if one isn't provided.
        prepareWrapperEl = function ($wrapperEl) {
          return $wrapperEl || $('.zone-content');
        },
        // Set default element if one isn't provided.
        prepareMessageEl = function ($messageEl) {
          return $messageEl || $('.zone-content');
        },
        // Set default element if one isn't provided.
        prepareWidgetEl = function ($widgetEl) {
          return $widgetEl || $('.frontmatter-widgets-wrapper');
        },
        // Hide display messages.
        hideMessages = function ($messageEl) {
          $messageEl = prepareMessageEl($messageEl);
          $('.js-messages', $messageEl).hide();
        },
        // Output an error message.
        displayErrorMessage = function ($messageEl, message) {
          var _message = message || Drupal.t('Failed to perform operation.'),
            messages = [_message];
          $messageEl = prepareMessageEl($messageEl);
          displayMessages(messages, $messageEl, 'error');
        },
        // Output the supplied messages in the element provided.
        displayMessages = function (messages, $messageEl, type) {
          $messageEl = prepareMessageEl($messageEl);
          if (!type) {
            type = 'status';
          }
          else {
            type = type.toLowerCase();
          }

          if ($('.js-messages', $messageEl).length == 0) {
            $messageEl.prepend('<div class="js-messages"><div class="messages"></div></div>');
            $('.js-messages .messages', $messageEl).prepend('<h2 class="element-invisible"><span class="js-message-type"></span> ' + Drupal.t('message') + '</h2><ul></ul>');
            $('.js-messages', $messageEl).click(function () {
              hideMessages($messageEl);
            });
          }
          else {
            $('.js-messages ul', $messageEl).html('');
          }

          $('.js-messages .messages', $messageEl).attr('class', 'messages ' + type);
          $('.js-message-type', $messageEl).text(Drupal.t(type.charAt(0).toUpperCase() + type.slice(1)));

          $.each(messages, function (index, message) {
            $('.js-messages ul', $messageEl).append('<li>' + message + '</li>');
          });

          $('.js-messages', $messageEl).show();
        },
        // Display widget UI elements.
        disableWidgets = function ($widgetEl) {
          $widgetEl = prepareWidgetEl($widgetEl);
          $('select, input, button', $widgetEl).attr('disabled','disabled');
        },
        // Enable widget UI elements.
        enableWidgets = function ($widgetEl) {
          $widgetEl = prepareWidgetEl($widgetEl);
          $('select, input, button', $widgetEl).removeAttr('disabled');
        },
        // Remove contenteditable attribute from element.
        removeContentEditable = function ($wrapperEl) {
          $wrapperEl = prepareWrapperEl($wrapperEl);
          $wrapperEl.removeAttr('contenteditable');
        },
        // Add contenteditable attribute to element.
        setContentEditable = function ($wrapperEl, state) {
          var setState = 'true';
          if (Drupal.settings.elifeCoverPagePreview.allowContentEditable) {
            $wrapperEl = prepareWrapperEl($wrapperEl);

            if (state === false) {
              setState = 'false';
            }

            $wrapperEl.attr('contenteditable', setState);
          }
        };

      // Run this javascript on the first load of the page.
      $('body').once('elife-front-matter-preview', function () {
        var $frontmatter = $('.pane-elife-front-matter-elife-front-matter'),
          $cover = $('.view-display-id-cover_article'),
          $col1 = $('.view-display-id-front_matter_col_1'),
          $col2 = $('.view-display-id-front_matter_col_2'),
          $widgetsWrapCover,
          $widgetsWrapCol1,
          $widgetsWrapCol2,
          $messageElCover,
          $messageElCol1,
          $messageElCol2;

        // Set click behaviour of .home-listing to offer toggle for UI preview widgets.
        $('.home-listings').toggle(function () {
          $frontmatter.addClass('frontmatter-preview-hide');
          removeContentEditable($frontmatter);
          return false;
        }, function () {
          $frontmatter.removeClass('frontmatter-preview-hide');
          setContentEditable($frontmatter);
          return false;
        });

        // Prepare markup and output UI preview widgets.
        $cover.append('<div class="frontmatter-widgets-wrapper"></div>');
        $widgetsWrapCover = $('.frontmatter-widgets-wrapper', $cover);
        $col1.append('<div class="frontmatter-widgets-wrapper"></div>');
        $widgetsWrapCol1 = $('.frontmatter-widgets-wrapper', $col1);
        $col2.append('<div class="frontmatter-widgets-wrapper"></div>');
        $widgetsWrapCol2 = $('.frontmatter-widgets-wrapper', $col2);
        $widgetsWrapCover.append('<div class="frontmatter-widgets-messages"></div>');
        $widgetsWrapCol1.append('<div class="frontmatter-widgets-messages"></div>');
        $widgetsWrapCol2.append('<div class="frontmatter-widgets-messages"></div>');
        $messageElCover = $('.frontmatter-widgets-messages', $widgetsWrapCover);
        $messageElCol1 = $('.frontmatter-widgets-messages', $widgetsWrapCol1);
        $messageElCol2 = $('.frontmatter-widgets-messages', $widgetsWrapCol2);

        $widgetsWrapCover.append(prepareTransferButton(3));
        $widgetsWrapCol1.append(prepareLimitDropdown(1));
        $widgetsWrapCol1.append(prepareTransferButton(1));
        $widgetsWrapCol2.append(prepareLimitDropdown(2));
        $widgetsWrapCol2.append(prepareTransferButton(2));
        $widgetsWrapCover.append(prepareTransferButton());

        // Set behaviour of UI preview widgets.
        limitDropdownChange($('.front-matter-limit-set', $widgetsWrapCol1), $messageElCol1, $widgetsWrapCol1);
        limitDropdownChange($('.front-matter-limit-set', $widgetsWrapCol2), $messageElCol2, $widgetsWrapCol2);

        transferToLive($('.front-matter-transfer-live-cover', $widgetsWrapCover), $messageElCover, $widgetsWrapCover);
        transferToLive($('.front-matter-transfer-live-1', $widgetsWrapCol1), $messageElCol1, $widgetsWrapCol1);
        transferToLive($('.front-matter-transfer-live-2', $widgetsWrapCol2), $messageElCol2, $widgetsWrapCol2);
        transferToLive($('.front-matter-transfer-live-all', $widgetsWrapCover), $messageElCover, $widgetsWrapCover);

        setContentEditable($('.frontmatter-widgets-wrapper'), false);
        setContentEditable($('.contextual-links-wrapper'), false);
        setContentEditable($frontmatter);
      });
    }
  };
})(jQuery, this);
