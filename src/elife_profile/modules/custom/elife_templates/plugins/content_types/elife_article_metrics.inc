<?php
/**
 * @file
 * Server-side render function for the block rendering external metrics
 * (scopus, facebook etc)
 */

$plugin = array(
  'title' => t('Article - ALM metrics'),
  'single' => TRUE,
  'category' => array('eLife'),
  'edit form' => 'elife_article_metrics_edit',
  'render callback' => 'elife_article_metrics_render',
  'required context' => new ctools_context_required('Article Node', 'node'),
);

/**
 * Run-time rendering of the body of the block (content type).
 *
 * See ctools_plugin_examples for more advanced info
 */
function elife_article_metrics_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $article_version = $context->data;
  $dto = elife_article_version_to_dto($article_version);
  // e.g. '10.7554/eLife.00286';
  $doi = $dto->getDoi();
  $doi = lagotto_services_validate_doi($doi);
  if (empty($doi)) {
    $block->content = t('There is no valid DOI associated with this article.');
    return $block;
  }
  $variables['doi'] = $doi;

  $response = lagotto_services_fetch_work($doi, array('include_detail' => TRUE));

  if (empty($response)) {
    // This should be a permission denied error; handle it as such.
    watchdog('elife_templates', 'Citations search: Permisison denied.',
      array(
        '%code' => $response->code,
        '%doi' => $doi,
      ),
      WATCHDOG_WARNING);
    $block->content = t('Citations search error.');
    return $block;
  }

  $record = lagotto_services_record($response, 0);
  if (!empty($record['error']) && ($record['error'] > 0)) {
    watchdog('elife_templates', 'Lagotto API error %code for doi %doi (%msg)',
      array(
        '%code' => $record['error'],
        '%doi' => $doi,
        '%msg' => $record['message'],
      ),
      WATCHDOG_WARNING);

    $block->content = t(
      'Article error in citations search. Error: %msg',
      array('%msg' => $record['message'])
    );
    return $block;
  }
  elseif ($response->code == 404) {
    // Handle 404 - not found - for articles not in ALM DB.
    $block->content = t('Article not found in citations search.');
    return $block;
  }

  // [0] for the first article requested, but fixed because we only ever ask
  // for one article at a time.
  $sources = $record['sources'];

  // Make a list of providers in the source data.
  $providers = array();
  foreach ($sources as $provider) {
    $providers[] = $provider['name'];
  }

  $elife_templates = drupal_get_path('module', 'elife_templates');
  $elife_provider = array(
    'saved_cited' => array(
      'citeulike:total' => array(
        'called' => t('Saved'),
        'icon' => 'http://www.citeulike.org/favicon.ico',
      ),
      'mendeley:total' => array(
        'called' => t('Saved'),
        'icon' => 'http://www.mendeley.com/graphics/favicon.ico',
      ),
      'crossref:total' => array(
        'called' => t('Citations'),
        'icon' => 'http://www.crossref.org/favicon.ico',
      ),
      'scopus:total' => array(
        'called' => t('Citations'),
        'icon' => 'http://scopus.com/static/images/favicon.ico',
      ),
      'pubmed:total' => array(
        'called' => t('Citations'),
        'icon' => 'http://www.ncbi.nlm.nih.gov/favicon.ico',
      ),
      'pmceurope:total' => array(
        'called' => t('Citations'),
        'icon' => 'http://europepmc.org/favicon.ico',
      ),
      'f1000:total' => array(
        'called' => t('Score'),
        'icon' => $elife_templates . '/images/f1000.png',
      ),
    ),
    'discussed' => array(
      'facebook:total' => array(
        'called' => t('Likes'),
        'icon' => 'http://www.facebook.com/favicon.ico',
      ),
      'reddit:total' => array(
        'called' => t('Mentions'),
        'icon' => 'http://www.reddit.com/favicon.ico',
      ),
      'twitter_search:total' => array(
        'called' => t('Tweets'),
        'icon' => 'http://twitter.com/favicon.ico',
      ),
      'blogger:total' => array(
        'called' => t('Citations'),
        'icon' => 'http://www.blogger.com/favicon.ico',
      ),
      'natureblogs:total' => array(
        'called' => t('Citations'),
        'icon' => 'http://www.nature.com/favicon.ico',
      ),
      'scienceseeker:total' => array(
        'called' => t('Citations'),
      ),
      'wordpress:total' => array(
        'called' => t('Citations'),
        'icon' => 'http://www.wordpress.com/favicon.ico',
      ),
      'wikipedia:total' => array(
        'called' => t('Citations'),
        'icon' => 'http://www.wikipedia.com/favicon.ico',
      ),
    ),
  );

  $is_cited = FALSE;
  $arr_elife_prov = array();
  foreach ($elife_provider as $elife_prov => $elife_prov_list) {
    foreach (array_keys($elife_prov_list) as $elife_pair) {

      list($prov_name, $pr_stat) = explode(':', $elife_pair);

      $pos = array_search($prov_name, $providers);
      if ($pos !== FALSE) {
        $providerdata = $sources[$pos];
        $metrics = $providerdata['metrics'];
        $auxinfo = $elife_prov_list[$elife_pair];
        if (isset($metrics['total'])) {
          $val = $metrics[$pr_stat];
          if ($val > 0) {
            $ico = isset($auxinfo['icon']) ? $auxinfo['icon'] : NULL;
            $refn = isset($auxinfo['called']) ? $auxinfo['called'] : t('Discussed');
            $arr_elife_prov[$elife_prov][$elife_pair] = array(
              'value' => $val,
              'icon' => $ico,
              'url' => $providerdata['events_url'],
              'display_name' => $providerdata['display_name'],
              'display_prov_name' => $refn,
            );
            $is_cited = TRUE;
          }
        }
      }
    }
  }

  // If there are *any* citations, display a link to google scholar.
  if ($is_cited) {
    $arr_elife_prov['saved_cited']['google_scholar:citation'] = array(
      'icon' => 'http://scholar.google.com/favicon.ico',
      'url' => 'http://scholar.google.com/scholar?q=link:' . url('node/' . $context->data->nid, array('absolute' => TRUE)),
      'display_prov_name' => t('Citations via Google Scholar'),
    );
  }

  $ext_link_attrs = array(
    'attributes' => array(
      'external' => TRUE,
      'target' => '_blank',
    ));
  $serviceurl = lagotto_services_service_host();
  $alm_link = l(t("ALM"), "http://articlemetrics.github.io/", $ext_link_attrs);
  $info_link = l(t("eLife Article Metrics"), $serviceurl . '/articles/info:doi/' . $doi, $ext_link_attrs);
  $via_text = t('via !info_link courtesy of !alm_link', array(
    '!info_link' => $info_link,
    '!alm_link' => $alm_link,
  ));

  $variables['providers_list'] = $arr_elife_prov;
  $variables['doi'] = $doi;
  $variables['via'] = $via_text;
  $block->content = theme('elife_article_metrics_cited', $variables);
  return $block;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_metrics_edit($form, &$form_state) {
  return $form;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_metrics_edit_form_submit(&$form, &$form_state) {
  // Nothing.
}

/**
 * Preprocess function for elife_article_metrics_cited.
 */
function elife_templates_preprocess_elife_article_metrics_cited(&$variables) {
  $ext_link_attrs = array(
    'attributes' => array(
      'external' => TRUE,
      'target' => '_blank',
    ));

  foreach ($variables['providers_list'] as $pro_matric => $provider_list) {
    $items = array();
    foreach ($provider_list as $provider => $provider_data) {

      // Make the name of the source a link to the source detail, if provided.
      if (!empty($provider_data['url']) && !empty($provider_data['display_prov_name'])) {
        $provider_class_link = l($provider_data['display_prov_name'], $provider_data['url'], $ext_link_attrs);
      }
      elseif (!empty($provider_data['display_prov_name'])) {
        $provider_class_link = $provider_data['display_prov_name'];
      }
      else {
        $provider_class_link = FALSE;
      }

      // If an icon is provided display it, otherwise do nothing.
      if (!empty($provider_data['icon'])) {
        $provider_icon = array(
          'path' => $provider_data['icon'],
        );
        if (!empty($provider_data['display_name'])) {
          $provider_icon['attributes'] = array(
            'title' => $provider_data['display_name'],
          );
        }
        $provider_logo = theme('image', $provider_icon);
      }
      else {
        $provider_logo = FALSE;
      }

      // Make the source name also a link to the source detail, if provided.
      if (!empty($provider_data['url']) && !empty($provider_data['display_name'])) {
        $provider_name_link = l($provider_data['display_name'], $provider_data['url'], $ext_link_attrs);
      }
      elseif (!empty($provider_data['display_name'])) {
        $provider_name_link = $provider_data['display_name'];
      }
      else {
        $provider_name_link = FALSE;
      }

      // Construct the variables for this block and render.
      $variables_provider_data = array();
      if ($provider_logo) {
        $variables_provider_data['icon'] = $provider_logo;
      }
      if ($provider_class_link) {
        $variables_provider_data['class_link'] = $provider_class_link;
      }
      if (!empty($provider_data['value'])) {
        $variables_provider_data['value'] = $provider_data['value'];
      }
      if ($provider_name_link) {
        $variables_provider_data['name_link'] = $provider_name_link;
      }
      if (!empty($variables_provider_data)) {
        $items[] = theme('elife_article_metrics_provider_data', $variables_provider_data);
      }
    }
    $variables[$pro_matric]['list'] = theme('item_list', array(
      'items' => $items,
      'attributes' => array(
        'class' => 'providers-list',
      ),
    ));
  }
  return TRUE;
}
