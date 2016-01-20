<?php
/**
 * @file
 * Administration settings page definition for the content alerts.
 */

/**
 * Implements hook_admin_settings().
 */
function elife_content_alerts_admin_settings_form($form, &$form_state) {
  $form = array();
  $form['settings'] = array(
    '#type' => 'vertical_tabs',
    '#weight' => 50,
  );

  if (user_access('administer elife content alerts')) {
    $ats = t('@alert-type-short expands to VoR or PoA');
    $atl = t('@alert-type-long expands to Version of Record or Publish on Accept');
    $afm = t('@alert-from-month expands to the earliest month of articles included');
    $afd = t('@alert-from-date expands to the earliest date of articles included');
    $atm = t('@alert-to-month expands to the most recent month of articles included');
    $atd = t('@alert-to-date expands to the most recent date of articles included');
    $nametokenhelp = t('The name of the template in CiviCRM. @ats; @atl; @afm; @afd; @atm; $atd',
      array(
        '@ats' => $ats,
        '@atl' => $atl,
        '@afd' => $afd,
        '@afm' => $afm,
        '@atd' => $atd,
        '@atm' => $atm,
      )
    );
    $subjvortokenhelp = t('The subject line that will be used for the email. @ats; @atl; @afm; @afd; @atm; $atd',
      array(
        '@ats' => $ats,
        '@atl' => $atl,
        '@afd' => $afd,
        '@afm' => $afm,
        '@atd' => $atd,
        '@atm' => $atm,
      )
    );
    $subjpoatokenhelp = t('The subject line that will be used for the email. @ats; @atl; @afm; @afd; @atm; $atd',
      array(
        '@ats' => $ats,
        '@atl' => $atl,
        '@afd' => $afd,
        '@afm' => $afm,
        '@atd' => $atd,
        '@atm' => $atm,
      )
    );
    $possible_actions = array(
      0 => t('Disable all alerts'),
      1 => t('Just Create a mailing'),
      2 => t('Create and send a mailing')
    );
    $form['elife_content_alerts_mail_action'] = array(
      '#type' => 'radios',
      '#title' => t('Action'),
      '#default_value' => variable_get('elife_content_alerts_mail_action', '1'),
      '#options' => $possible_actions,
      '#description' => t('Disable stops alerts from being created or sent.'),
    );

    // Alerts creation settings.
    $form['alertrecipient'] = array(
      '#type' => 'fieldset',
      '#title' => t('Content Alerts Recipient'),
      '#group' => 'settings',
    );
    $form['alertrecipient']['elife_content_alerts_mail_recipient_vor'] = array(
      '#type' => 'textfield',
      '#title' => t('VoR Group name of recipients'),
      '#default_value' => variable_get('elife_content_alerts_mail_recipient_vor', 'Content alerts'),
    );
    $form['alertrecipient']['elife_content_alerts_mail_recipient_poa'] = array(
      '#type' => 'textfield',
      '#title' => t('PoA Group name of recipients'),
      '#default_value' => variable_get('elife_content_alerts_mail_recipient_poa', 'UPCOMING - Content alerts'),
    );

    // Alerts creation settings.
    $form['alertsender'] = array(
      '#type' => 'fieldset',
      '#title' => t('Content Alerts Sender'),
      '#group' => 'settings',
    );
    $form['alertsender']['elife_content_alerts_mail_creator_user'] = array(
      '#type' => 'textfield',
      '#title' => t('Alerts Mail-creator user (ID)'),
      '#description' => t('The ID of the CiviCRM user from which the mailing will be sent.'),
      '#default_value' => variable_get('elife_content_alerts_mail_creator_user', '1'),
    );
    $form['alertsender']['elife_content_alerts_mail_email'] = array(
      '#type' => 'textfield',
      '#title' => t('Alerts email address'),
      '#description' => $subjpoatokenhelp,
      '#default_value' => variable_get('elife_content_alerts_mail_email', 'staff@example.org'),
    );
    $form['alertsender']['elife_content_alerts_mail_email_displayname'] = array(
      '#type' => 'textfield',
      '#title' => t('Alerts email display-from name'),
      '#default_value' => variable_get('elife_content_alerts_mail_email_displayname', 'eLife Alerts'),
    );

    // Alerts creation settings.
    $form['alerttemplate'] = array(
      '#type' => 'fieldset',
      '#title' => t('Content Alerts Template'),
      '#group' => 'settings',
    );
    $form['alerttemplate']['elife_content_alerts_mail_template_name'] = array(
      '#type' => 'textfield',
      '#title' => t('Alerts email template name'),
      '#description' => $nametokenhelp,
      '#default_value' => variable_get('elife_content_alerts_mail_template_name', 'Alerts Mailing'),
    );
    $form['alerttemplate']['elife_content_alerts_mail_subject_vor'] = array(
      '#type' => 'textfield',
      '#title' => t('VoR Alerts email subject line'),
      '#description' => $subjvortokenhelp,
      '#default_value' => variable_get('elife_content_alerts_mail_subject_vor', 'News from eLife'),
    );
    $form['alerttemplate']['elife_content_alerts_mail_subject_poa'] = array(
      '#type' => 'textfield',
      '#title' => t('PoA Alerts email subject line'),
      '#description' => $subjpoatokenhelp,
      '#default_value' => variable_get('elife_content_alerts_mail_subject_poa', 'News from eLife'),
    );
  }

  if (user_access('edit elife content alerts headline')) {
    $exp_attributes = array(
      'class' => array(
        'error',
      ),
    );

    $link_options = array(
      'attributes' => array(
        'class' => array(
          'elife-content-alerts-mail-example-link',
        ),
      ),
    );

    $headlines = elife_content_alerts_messages($link_options);
    $prefix = 'elife_content_alerts_mail_';
    $preview_text = t('See in place');
    $preview_url = 'elife/content_alerts/';
    $preview_date = date('Y-m-d', strtotime('-6 days')) . '--' . date('Y-m-d');

    $link_options['attributes']['class'] = 'elife-content-alerts-mail-example-preview';

    // Alerts headline maintenance.
    $form['alertheadline'] = array(
      '#type' => 'fieldset',
      '#title' => t('Content Alerts - Headline'),
      '#group' => 'settings',
    );

    foreach (array('POA', 'VOR') as $type) {
      $exp_type_attributes = array();
      $args = array(
        '@type' => $type,
      );

      $type = strtolower($type);

      if ($exp_type = variable_get($prefix . $type . '_mess_exp')) {
        if (empty($form_state['input']) && _elife_content_alerts_messages_exp($exp_type)) {
          $exp_type_attributes = $exp_attributes;
          drupal_set_message(t('The message for @type content alerts has expired', $args), 'warning');
        }
      }

      $form['alertheadline'][$prefix . $type . '_mess'] = array(
        '#type' => 'textfield',
        '#title' => t('Alerts email @type message', $args),
        '#default_value' => variable_get($prefix . $type . '_mess'),
      );
      $form['alertheadline'][$prefix . $type . '_mess_link'] = array(
        '#type' => 'textfield',
        '#title' => t('Alerts email @type message link', $args),
        '#default_value' => variable_get($prefix . $type . '_mess_link'),
      );
      $form['alertheadline'][$prefix . $type . '_mess_exp'] = array(
        '#type' => 'textfield',
        '#title' => t('Alerts email @type message expiry date', $args),
        '#description' => t('YYYY-MM-DD or leave blank if the message should not expire'),
        '#default_value' => variable_get($prefix . $type . '_mess_exp'),
        '#attributes' => $exp_type_attributes,
      );

      if (!empty($headlines[strtoupper($type)])) {
        $headline = $headlines[strtoupper($type)];
        $form['alertheadline'][$prefix . $type . '_mess_markup'] = array(
          '#markup' => '<p class="elife-content-alerts-mail-example-' . $type . '">' . t('@type link: ', $args) . $headline . ' - ' . l($preview_text, $preview_url . strtoupper($type) . '/' . $preview_date, $link_options) . '</p>',
        );
      }
    }
  }
  return system_settings_form($form);
}

/**
 * Implements hook_form_validate().
 */
function elife_content_alerts_admin_settings_form_validate($form, &$form_state) {
  foreach (array('poa', 'vor') as $type) {
    $field_name = 'elife_content_alerts_mail_' . $type . '_mess_exp';
    if (!empty($form_state['values'][$field_name])) {
      if ($datetime = strtotime($form_state['values'][$field_name])) {
        $value = date('Y-m-d', $datetime);
      }
      else {
        $value = '';
      }
      $form_state['values'][$field_name] = $value;
    }
  }
}
