<?php
/**
 * @file
 * elife_users.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function elife_users_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Article Publisher' => 'eLife Article Publisher',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(),
    'module' => 'views',
  );

  // Exported permission: 'access all webform results'.
  $permissions['access all webform results'] = array(
    'name' => 'access all webform results',
    'roles' => array(),
    'module' => 'webform',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'eLife Administrator' => 'eLife Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access own webform results'.
  $permissions['access own webform results'] = array(
    'name' => 'access own webform results',
    'roles' => array(),
    'module' => 'webform',
  );

  // Exported permission: 'access own webform submissions'.
  $permissions['access own webform submissions'] = array(
    'name' => 'access own webform submissions',
    'roles' => array(),
    'module' => 'webform',
  );

  // Exported permission: 'access rules debug'.
  $permissions['access rules debug'] = array(
    'name' => 'access rules debug',
    'roles' => array(),
    'module' => 'rules',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'admin_display_suite'.
  $permissions['admin_display_suite'] = array(
    'name' => 'admin_display_suite',
    'roles' => array(),
    'module' => 'ds',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer advanced pane settings'.
  $permissions['administer advanced pane settings'] = array(
    'name' => 'administer advanced pane settings',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(),
    'module' => 'block',
  );

  // Exported permission: 'administer cer settings'.
  $permissions['administer cer settings'] = array(
    'name' => 'administer cer settings',
    'roles' => array(),
    'module' => 'cer',
  );

  // Exported permission: 'administer ckeditor'.
  $permissions['administer ckeditor'] = array(
    'name' => 'administer ckeditor',
    'roles' => array(),
    'module' => 'ckeditor',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer elife_article'.
  $permissions['administer elife_article'] = array(
    'name' => 'administer elife_article',
    'roles' => array(),
    'module' => 'elife_article',
  );

  // Exported permission: 'administer elife_article assets source'.
  $permissions['administer elife_article assets source'] = array(
    'name' => 'administer elife_article assets source',
    'roles' => array(),
    'module' => 'elife_article',
  );

  // Exported permission: 'administer elife_resources'.
  $permissions['administer elife_resources'] = array(
    'name' => 'administer elife_resources',
    'roles' => array(),
    'module' => 'elife_resources',
  );

  // Exported permission: 'administer elysia_cron'.
  $permissions['administer elysia_cron'] = array(
    'name' => 'administer elysia_cron',
    'roles' => array(),
    'module' => 'elysia_cron',
  );

  // Exported permission: 'administer entityqueue'.
  $permissions['administer entityqueue'] = array(
    'name' => 'administer entityqueue',
    'roles' => array(),
    'module' => 'entityqueue',
  );

  // Exported permission: 'administer facets'.
  $permissions['administer facets'] = array(
    'name' => 'administer facets',
    'roles' => array(),
    'module' => 'facetapi',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(),
    'module' => 'features',
  );

  // Exported permission: 'administer field collections'.
  $permissions['administer field collections'] = array(
    'name' => 'administer field collections',
    'roles' => array(),
    'module' => 'field_collection',
  );

  // Exported permission: 'administer fieldgroups'.
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(),
    'module' => 'field_group',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(),
    'module' => 'image',
  );

  // Exported permission: 'administer imagecache external'.
  $permissions['administer imagecache external'] = array(
    'name' => 'administer imagecache external',
    'roles' => array(),
    'module' => 'imagecache_external',
  );

  // Exported permission: 'administer imce'.
  $permissions['administer imce'] = array(
    'name' => 'administer imce',
    'roles' => array(),
    'module' => 'imce',
  );

  // Exported permission: 'administer mathjax'.
  $permissions['administer mathjax'] = array(
    'name' => 'administer mathjax',
    'roles' => array(),
    'module' => 'mathjax',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(),
    'module' => 'menu',
  );

  // Exported permission: 'administer meta tags'.
  $permissions['administer meta tags'] = array(
    'name' => 'administer meta tags',
    'roles' => array(),
    'module' => 'metatag',
  );

  // Exported permission: 'administer mini panels'.
  $permissions['administer mini panels'] = array(
    'name' => 'administer mini panels',
    'roles' => array(),
    'module' => 'panels_mini',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer page manager'.
  $permissions['administer page manager'] = array(
    'name' => 'administer page manager',
    'roles' => array(),
    'module' => 'page_manager',
  );

  // Exported permission: 'administer page theme'.
  $permissions['administer page theme'] = array(
    'name' => 'administer page theme',
    'roles' => array(),
    'module' => 'page_theme',
  );

  // Exported permission: 'administer pane access'.
  $permissions['administer pane access'] = array(
    'name' => 'administer pane access',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels layouts'.
  $permissions['administer panels layouts'] = array(
    'name' => 'administer panels layouts',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels styles'.
  $permissions['administer panels styles'] = array(
    'name' => 'administer panels styles',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(),
    'module' => 'pathauto',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer realname'.
  $permissions['administer realname'] = array(
    'name' => 'administer realname',
    'roles' => array(),
    'module' => 'realname',
  );

  // Exported permission: 'administer redirects'.
  $permissions['administer redirects'] = array(
    'name' => 'administer redirects',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
    ),
    'module' => 'redirect',
  );

  // Exported permission: 'administer rh_node'.
  $permissions['administer rh_node'] = array(
    'name' => 'administer rh_node',
    'roles' => array(),
    'module' => 'rabbit_hole',
  );

  // Exported permission: 'administer rules'.
  $permissions['administer rules'] = array(
    'name' => 'administer rules',
    'roles' => array(),
    'module' => 'rules',
  );

  // Exported permission: 'administer scheduler'.
  $permissions['administer scheduler'] = array(
    'name' => 'administer scheduler',
    'roles' => array(),
    'module' => 'scheduler',
  );

  // Exported permission: 'administer search_api'.
  $permissions['administer search_api'] = array(
    'name' => 'administer search_api',
    'roles' => array(),
    'module' => 'search_api',
  );

  // Exported permission: 'administer services'.
  $permissions['administer services'] = array(
    'name' => 'administer services',
    'roles' => array(),
    'module' => 'services',
  );

  // Exported permission: 'administer sharethis'.
  $permissions['administer sharethis'] = array(
    'name' => 'administer sharethis',
    'roles' => array(),
    'module' => 'sharethis',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(),
    'module' => 'path',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(),
    'module' => 'views',
  );

  // Exported permission: 'administer xmlsitemap'.
  $permissions['administer xmlsitemap'] = array(
    'name' => 'administer xmlsitemap',
    'roles' => array(),
    'module' => 'xmlsitemap',
  );

  // Exported permission: 'advanced migration information'.
  $permissions['advanced migration information'] = array(
    'name' => 'advanced migration information',
    'roles' => array(),
    'module' => 'migrate',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'bypass rh_node'.
  $permissions['bypass rh_node'] = array(
    'name' => 'bypass rh_node',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'rabbit_hole',
  );

  // Exported permission: 'bypass rules access'.
  $permissions['bypass rules access'] = array(
    'name' => 'bypass rules access',
    'roles' => array(),
    'module' => 'rules',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'change layouts in place editing'.
  $permissions['change layouts in place editing'] = array(
    'name' => 'change layouts in place editing',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'create elife_annual_report content'.
  $permissions['create elife_annual_report content'] = array(
    'name' => 'create elife_annual_report content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create elife_article content'.
  $permissions['create elife_article content'] = array(
    'name' => 'create elife_article content',
    'roles' => array(
      'eLife Article Publisher' => 'eLife Article Publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create elife_article_reference content'.
  $permissions['create elife_article_reference content'] = array(
    'name' => 'create elife_article_reference content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create elife_article_ver content'.
  $permissions['create elife_article_ver content'] = array(
    'name' => 'create elife_article_ver content',
    'roles' => array(
      'eLife Article Publisher' => 'eLife Article Publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create elife_collection content'.
  $permissions['create elife_collection content'] = array(
    'name' => 'create elife_collection content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create elife_contributor content'.
  $permissions['create elife_contributor content'] = array(
    'name' => 'create elife_contributor content',
    'roles' => array(
      'eLife Article Publisher' => 'eLife Article Publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create elife_cover content'.
  $permissions['create elife_cover content'] = array(
    'name' => 'create elife_cover content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create elife_early_careers_interview content'.
  $permissions['create elife_early_careers_interview content'] = array(
    'name' => 'create elife_early_careers_interview content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create elife_early_careers_spotlight content'.
  $permissions['create elife_early_careers_spotlight content'] = array(
    'name' => 'create elife_early_careers_spotlight content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create elife_event content'.
  $permissions['create elife_event content'] = array(
    'name' => 'create elife_event content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create elife_fragment content'.
  $permissions['create elife_fragment content'] = array(
    'name' => 'create elife_fragment content',
    'roles' => array(
      'eLife Article Publisher' => 'eLife Article Publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create elife_front_matter content'.
  $permissions['create elife_front_matter content'] = array(
    'name' => 'create elife_front_matter content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create elife_labs_entry content'.
  $permissions['create elife_labs_entry content'] = array(
    'name' => 'create elife_labs_entry content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create elife_news_article content'.
  $permissions['create elife_news_article content'] = array(
    'name' => 'create elife_news_article content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create elife_organisation content'.
  $permissions['create elife_organisation content'] = array(
    'name' => 'create elife_organisation content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create elife_person_profile content'.
  $permissions['create elife_person_profile content'] = array(
    'name' => 'create elife_person_profile content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create elife_podcast content'.
  $permissions['create elife_podcast content'] = array(
    'name' => 'create elife_podcast content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create elife_podcast_chapter content'.
  $permissions['create elife_podcast_chapter content'] = array(
    'name' => 'create elife_podcast_chapter content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create elife_term_reference content'.
  $permissions['create elife_term_reference content'] = array(
    'name' => 'create elife_term_reference content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create mini panels'.
  $permissions['create mini panels'] = array(
    'name' => 'create mini panels',
    'roles' => array(),
    'module' => 'panels_mini',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'path',
  );

  // Exported permission: 'create webform content'.
  $permissions['create webform content'] = array(
    'name' => 'create webform content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'customize ckeditor'.
  $permissions['customize ckeditor'] = array(
    'name' => 'customize ckeditor',
    'roles' => array(),
    'module' => 'ckeditor',
  );

  // Exported permission: 'delete all webform submissions'.
  $permissions['delete all webform submissions'] = array(
    'name' => 'delete all webform submissions',
    'roles' => array(),
    'module' => 'webform',
  );

  // Exported permission: 'delete any elife_annual_report content'.
  $permissions['delete any elife_annual_report content'] = array(
    'name' => 'delete any elife_annual_report content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any elife_article content'.
  $permissions['delete any elife_article content'] = array(
    'name' => 'delete any elife_article content',
    'roles' => array(
      'eLife Article Publisher' => 'eLife Article Publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any elife_article_reference content'.
  $permissions['delete any elife_article_reference content'] = array(
    'name' => 'delete any elife_article_reference content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any elife_article_ver content'.
  $permissions['delete any elife_article_ver content'] = array(
    'name' => 'delete any elife_article_ver content',
    'roles' => array(
      'eLife Article Publisher' => 'eLife Article Publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any elife_collection content'.
  $permissions['delete any elife_collection content'] = array(
    'name' => 'delete any elife_collection content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any elife_contributor content'.
  $permissions['delete any elife_contributor content'] = array(
    'name' => 'delete any elife_contributor content',
    'roles' => array(
      'eLife Article Publisher' => 'eLife Article Publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any elife_cover content'.
  $permissions['delete any elife_cover content'] = array(
    'name' => 'delete any elife_cover content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any elife_early_careers_interview content'.
  $permissions['delete any elife_early_careers_interview content'] = array(
    'name' => 'delete any elife_early_careers_interview content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any elife_early_careers_spotlight content'.
  $permissions['delete any elife_early_careers_spotlight content'] = array(
    'name' => 'delete any elife_early_careers_spotlight content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any elife_event content'.
  $permissions['delete any elife_event content'] = array(
    'name' => 'delete any elife_event content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any elife_fragment content'.
  $permissions['delete any elife_fragment content'] = array(
    'name' => 'delete any elife_fragment content',
    'roles' => array(
      'eLife Article Publisher' => 'eLife Article Publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any elife_front_matter content'.
  $permissions['delete any elife_front_matter content'] = array(
    'name' => 'delete any elife_front_matter content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any elife_labs_entry content'.
  $permissions['delete any elife_labs_entry content'] = array(
    'name' => 'delete any elife_labs_entry content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any elife_news_article content'.
  $permissions['delete any elife_news_article content'] = array(
    'name' => 'delete any elife_news_article content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any elife_organisation content'.
  $permissions['delete any elife_organisation content'] = array(
    'name' => 'delete any elife_organisation content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any elife_person_profile content'.
  $permissions['delete any elife_person_profile content'] = array(
    'name' => 'delete any elife_person_profile content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any elife_podcast content'.
  $permissions['delete any elife_podcast content'] = array(
    'name' => 'delete any elife_podcast content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any elife_podcast_chapter content'.
  $permissions['delete any elife_podcast_chapter content'] = array(
    'name' => 'delete any elife_podcast_chapter content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any elife_term_reference content'.
  $permissions['delete any elife_term_reference content'] = array(
    'name' => 'delete any elife_term_reference content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any webform content'.
  $permissions['delete any webform content'] = array(
    'name' => 'delete any webform content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own elife_annual_report content'.
  $permissions['delete own elife_annual_report content'] = array(
    'name' => 'delete own elife_annual_report content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own elife_article content'.
  $permissions['delete own elife_article content'] = array(
    'name' => 'delete own elife_article content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own elife_article_reference content'.
  $permissions['delete own elife_article_reference content'] = array(
    'name' => 'delete own elife_article_reference content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own elife_article_ver content'.
  $permissions['delete own elife_article_ver content'] = array(
    'name' => 'delete own elife_article_ver content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own elife_collection content'.
  $permissions['delete own elife_collection content'] = array(
    'name' => 'delete own elife_collection content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own elife_contributor content'.
  $permissions['delete own elife_contributor content'] = array(
    'name' => 'delete own elife_contributor content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own elife_cover content'.
  $permissions['delete own elife_cover content'] = array(
    'name' => 'delete own elife_cover content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own elife_early_careers_interview content'.
  $permissions['delete own elife_early_careers_interview content'] = array(
    'name' => 'delete own elife_early_careers_interview content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own elife_early_careers_spotlight content'.
  $permissions['delete own elife_early_careers_spotlight content'] = array(
    'name' => 'delete own elife_early_careers_spotlight content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own elife_event content'.
  $permissions['delete own elife_event content'] = array(
    'name' => 'delete own elife_event content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own elife_fragment content'.
  $permissions['delete own elife_fragment content'] = array(
    'name' => 'delete own elife_fragment content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own elife_front_matter content'.
  $permissions['delete own elife_front_matter content'] = array(
    'name' => 'delete own elife_front_matter content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own elife_labs_entry content'.
  $permissions['delete own elife_labs_entry content'] = array(
    'name' => 'delete own elife_labs_entry content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own elife_news_article content'.
  $permissions['delete own elife_news_article content'] = array(
    'name' => 'delete own elife_news_article content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own elife_organisation content'.
  $permissions['delete own elife_organisation content'] = array(
    'name' => 'delete own elife_organisation content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own elife_person_profile content'.
  $permissions['delete own elife_person_profile content'] = array(
    'name' => 'delete own elife_person_profile content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own elife_podcast content'.
  $permissions['delete own elife_podcast content'] = array(
    'name' => 'delete own elife_podcast content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own elife_podcast_chapter content'.
  $permissions['delete own elife_podcast_chapter content'] = array(
    'name' => 'delete own elife_podcast_chapter content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own elife_term_reference content'.
  $permissions['delete own elife_term_reference content'] = array(
    'name' => 'delete own elife_term_reference content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own webform content'.
  $permissions['delete own webform content'] = array(
    'name' => 'delete own webform content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own webform submissions'.
  $permissions['delete own webform submissions'] = array(
    'name' => 'delete own webform submissions',
    'roles' => array(),
    'module' => 'webform',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in elife_categories'.
  $permissions['delete terms in elife_categories'] = array(
    'name' => 'delete terms in elife_categories',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in elife_headings'.
  $permissions['delete terms in elife_headings'] = array(
    'name' => 'delete terms in elife_headings',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in elife_keywords'.
  $permissions['delete terms in elife_keywords'] = array(
    'name' => 'delete terms in elife_keywords',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in elife_n_category'.
  $permissions['delete terms in elife_n_category'] = array(
    'name' => 'delete terms in elife_n_category',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in elife_pp_experimental_organism'.
  $permissions['delete terms in elife_pp_experimental_organism'] = array(
    'name' => 'delete terms in elife_pp_experimental_organism',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in elife_pp_expertise'.
  $permissions['delete terms in elife_pp_expertise'] = array(
    'name' => 'delete terms in elife_pp_expertise',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in elife_pp_research_focus'.
  $permissions['delete terms in elife_pp_research_focus'] = array(
    'name' => 'delete terms in elife_pp_research_focus',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'display drupal links'.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(),
    'module' => 'admin_menu',
  );

  // Exported permission: 'edit all webform submissions'.
  $permissions['edit all webform submissions'] = array(
    'name' => 'edit all webform submissions',
    'roles' => array(),
    'module' => 'webform',
  );

  // Exported permission: 'edit any elife_annual_report content'.
  $permissions['edit any elife_annual_report content'] = array(
    'name' => 'edit any elife_annual_report content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any elife_article content'.
  $permissions['edit any elife_article content'] = array(
    'name' => 'edit any elife_article content',
    'roles' => array(
      'eLife Article Publisher' => 'eLife Article Publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any elife_article_reference content'.
  $permissions['edit any elife_article_reference content'] = array(
    'name' => 'edit any elife_article_reference content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any elife_article_ver content'.
  $permissions['edit any elife_article_ver content'] = array(
    'name' => 'edit any elife_article_ver content',
    'roles' => array(
      'eLife Article Publisher' => 'eLife Article Publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any elife_collection content'.
  $permissions['edit any elife_collection content'] = array(
    'name' => 'edit any elife_collection content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any elife_contributor content'.
  $permissions['edit any elife_contributor content'] = array(
    'name' => 'edit any elife_contributor content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any elife_cover content'.
  $permissions['edit any elife_cover content'] = array(
    'name' => 'edit any elife_cover content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any elife_early_careers_interview content'.
  $permissions['edit any elife_early_careers_interview content'] = array(
    'name' => 'edit any elife_early_careers_interview content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any elife_early_careers_spotlight content'.
  $permissions['edit any elife_early_careers_spotlight content'] = array(
    'name' => 'edit any elife_early_careers_spotlight content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any elife_event content'.
  $permissions['edit any elife_event content'] = array(
    'name' => 'edit any elife_event content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any elife_fragment content'.
  $permissions['edit any elife_fragment content'] = array(
    'name' => 'edit any elife_fragment content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any elife_front_matter content'.
  $permissions['edit any elife_front_matter content'] = array(
    'name' => 'edit any elife_front_matter content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any elife_labs_entry content'.
  $permissions['edit any elife_labs_entry content'] = array(
    'name' => 'edit any elife_labs_entry content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any elife_news_article content'.
  $permissions['edit any elife_news_article content'] = array(
    'name' => 'edit any elife_news_article content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any elife_organisation content'.
  $permissions['edit any elife_organisation content'] = array(
    'name' => 'edit any elife_organisation content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any elife_person_profile content'.
  $permissions['edit any elife_person_profile content'] = array(
    'name' => 'edit any elife_person_profile content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any elife_podcast content'.
  $permissions['edit any elife_podcast content'] = array(
    'name' => 'edit any elife_podcast content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any elife_podcast_chapter content'.
  $permissions['edit any elife_podcast_chapter content'] = array(
    'name' => 'edit any elife_podcast_chapter content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any elife_term_reference content'.
  $permissions['edit any elife_term_reference content'] = array(
    'name' => 'edit any elife_term_reference content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any webform content'.
  $permissions['edit any webform content'] = array(
    'name' => 'edit any webform content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit meta tags'.
  $permissions['edit meta tags'] = array(
    'name' => 'edit meta tags',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit own elife_annual_report content'.
  $permissions['edit own elife_annual_report content'] = array(
    'name' => 'edit own elife_annual_report content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own elife_article content'.
  $permissions['edit own elife_article content'] = array(
    'name' => 'edit own elife_article content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own elife_article_reference content'.
  $permissions['edit own elife_article_reference content'] = array(
    'name' => 'edit own elife_article_reference content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own elife_article_ver content'.
  $permissions['edit own elife_article_ver content'] = array(
    'name' => 'edit own elife_article_ver content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own elife_collection content'.
  $permissions['edit own elife_collection content'] = array(
    'name' => 'edit own elife_collection content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own elife_contributor content'.
  $permissions['edit own elife_contributor content'] = array(
    'name' => 'edit own elife_contributor content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own elife_cover content'.
  $permissions['edit own elife_cover content'] = array(
    'name' => 'edit own elife_cover content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own elife_early_careers_interview content'.
  $permissions['edit own elife_early_careers_interview content'] = array(
    'name' => 'edit own elife_early_careers_interview content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own elife_early_careers_spotlight content'.
  $permissions['edit own elife_early_careers_spotlight content'] = array(
    'name' => 'edit own elife_early_careers_spotlight content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own elife_event content'.
  $permissions['edit own elife_event content'] = array(
    'name' => 'edit own elife_event content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own elife_fragment content'.
  $permissions['edit own elife_fragment content'] = array(
    'name' => 'edit own elife_fragment content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own elife_front_matter content'.
  $permissions['edit own elife_front_matter content'] = array(
    'name' => 'edit own elife_front_matter content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own elife_labs_entry content'.
  $permissions['edit own elife_labs_entry content'] = array(
    'name' => 'edit own elife_labs_entry content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own elife_news_article content'.
  $permissions['edit own elife_news_article content'] = array(
    'name' => 'edit own elife_news_article content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own elife_organisation content'.
  $permissions['edit own elife_organisation content'] = array(
    'name' => 'edit own elife_organisation content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own elife_person_profile content'.
  $permissions['edit own elife_person_profile content'] = array(
    'name' => 'edit own elife_person_profile content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own elife_podcast content'.
  $permissions['edit own elife_podcast content'] = array(
    'name' => 'edit own elife_podcast content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own elife_podcast_chapter content'.
  $permissions['edit own elife_podcast_chapter content'] = array(
    'name' => 'edit own elife_podcast_chapter content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own elife_term_reference content'.
  $permissions['edit own elife_term_reference content'] = array(
    'name' => 'edit own elife_term_reference content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform content'.
  $permissions['edit own webform content'] = array(
    'name' => 'edit own webform content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform submissions'.
  $permissions['edit own webform submissions'] = array(
    'name' => 'edit own webform submissions',
    'roles' => array(),
    'module' => 'webform',
  );

  // Exported permission: 'edit terms in elife_categories'.
  $permissions['edit terms in elife_categories'] = array(
    'name' => 'edit terms in elife_categories',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in elife_headings'.
  $permissions['edit terms in elife_headings'] = array(
    'name' => 'edit terms in elife_headings',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in elife_keywords'.
  $permissions['edit terms in elife_keywords'] = array(
    'name' => 'edit terms in elife_keywords',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in elife_n_category'.
  $permissions['edit terms in elife_n_category'] = array(
    'name' => 'edit terms in elife_n_category',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in elife_pp_experimental_organism'.
  $permissions['edit terms in elife_pp_experimental_organism'] = array(
    'name' => 'edit terms in elife_pp_experimental_organism',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in elife_pp_expertise'.
  $permissions['edit terms in elife_pp_expertise'] = array(
    'name' => 'edit terms in elife_pp_expertise',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in elife_pp_research_focus'.
  $permissions['edit terms in elife_pp_research_focus'] = array(
    'name' => 'edit terms in elife_pp_research_focus',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit webform components'.
  $permissions['edit webform components'] = array(
    'name' => 'edit webform components',
    'roles' => array(),
    'module' => 'webform',
  );

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(),
    'module' => 'admin_menu',
  );

  // Exported permission: 'front matter preview'.
  $permissions['front matter preview'] = array(
    'name' => 'front matter preview',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'elife_front_matter',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(),
    'module' => 'features',
  );

  // Exported permission: 'get a system variable'.
  $permissions['get a system variable'] = array(
    'name' => 'get a system variable',
    'roles' => array(),
    'module' => 'services',
  );

  // Exported permission: 'get any binary files'.
  $permissions['get any binary files'] = array(
    'name' => 'get any binary files',
    'roles' => array(),
    'module' => 'services',
  );

  // Exported permission: 'get own binary files'.
  $permissions['get own binary files'] = array(
    'name' => 'get own binary files',
    'roles' => array(),
    'module' => 'services',
  );

  // Exported permission: 'locally edit front matter titles'.
  $permissions['locally edit front matter titles'] = array(
    'name' => 'locally edit front matter titles',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'elife_front_matter',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(),
    'module' => 'features',
  );

  // Exported permission: 'manipulate all entityqueues'.
  $permissions['manipulate all entityqueues'] = array(
    'name' => 'manipulate all entityqueues',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: 'manipulate entityqueues'.
  $permissions['manipulate entityqueues'] = array(
    'name' => 'manipulate entityqueues',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: 'migration information'.
  $permissions['migration information'] = array(
    'name' => 'migration information',
    'roles' => array(),
    'module' => 'migrate',
  );

  // Exported permission: 'notify of path changes'.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(),
    'module' => 'pathauto',
  );

  // Exported permission: 'perform unlimited index queries'.
  $permissions['perform unlimited index queries'] = array(
    'name' => 'perform unlimited index queries',
    'roles' => array(),
    'module' => 'services',
  );

  // Exported permission: 'php redirect rh_node'.
  $permissions['php redirect rh_node'] = array(
    'name' => 'php redirect rh_node',
    'roles' => array(),
    'module' => 'rabbit_hole',
  );

  // Exported permission: 'preview focal point'.
  $permissions['preview focal point'] = array(
    'name' => 'preview focal point',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'focal_point',
  );

  // Exported permission: 'rename features'.
  $permissions['rename features'] = array(
    'name' => 'rename features',
    'roles' => array(),
    'module' => 'features',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'save file information'.
  $permissions['save file information'] = array(
    'name' => 'save file information',
    'roles' => array(),
    'module' => 'services',
  );

  // Exported permission: 'schedule (un)publishing of nodes'.
  $permissions['schedule (un)publishing of nodes'] = array(
    'name' => 'schedule (un)publishing of nodes',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'scheduler',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'set a system variable'.
  $permissions['set a system variable'] = array(
    'name' => 'set a system variable',
    'roles' => array(),
    'module' => 'services',
  );

  // Exported permission: 'show format selection for cer'.
  $permissions['show format selection for cer'] = array(
    'name' => 'show format selection for cer',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for country'.
  $permissions['show format selection for country'] = array(
    'name' => 'show format selection for country',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for entityqueue_subqueue'.
  $permissions['show format selection for entityqueue_subqueue'] = array(
    'name' => 'show format selection for entityqueue_subqueue',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for field_collection_item'.
  $permissions['show format selection for field_collection_item'] = array(
    'name' => 'show format selection for field_collection_item',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for node'.
  $permissions['show format selection for node'] = array(
    'name' => 'show format selection for node',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for rules_config'.
  $permissions['show format selection for rules_config'] = array(
    'name' => 'show format selection for rules_config',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for taxonomy_term'.
  $permissions['show format selection for taxonomy_term'] = array(
    'name' => 'show format selection for taxonomy_term',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for user'.
  $permissions['show format selection for user'] = array(
    'name' => 'show format selection for user',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format tips'.
  $permissions['show format tips'] = array(
    'name' => 'show format tips',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show more format tips link'.
  $permissions['show more format tips link'] = array(
    'name' => 'show more format tips link',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'update elife_cover entityqueue'.
  $permissions['update elife_cover entityqueue'] = array(
    'name' => 'update elife_cover entityqueue',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: 'update elife_cover_preview entityqueue'.
  $permissions['update elife_cover_preview entityqueue'] = array(
    'name' => 'update elife_cover_preview entityqueue',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: 'update elife_front_matter_col_1 entityqueue'.
  $permissions['update elife_front_matter_col_1 entityqueue'] = array(
    'name' => 'update elife_front_matter_col_1 entityqueue',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: 'update elife_front_matter_col_2 entityqueue'.
  $permissions['update elife_front_matter_col_2 entityqueue'] = array(
    'name' => 'update elife_front_matter_col_2 entityqueue',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: 'update elife_front_matter_preview_col_1 entityqueue'.
  $permissions['update elife_front_matter_preview_col_1 entityqueue'] = array(
    'name' => 'update elife_front_matter_preview_col_1 entityqueue',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: 'update elife_front_matter_preview_col_2 entityqueue'.
  $permissions['update elife_front_matter_preview_col_2 entityqueue'] = array(
    'name' => 'update elife_front_matter_preview_col_2 entityqueue',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: 'use PHP for label patterns'.
  $permissions['use PHP for label patterns'] = array(
    'name' => 'use PHP for label patterns',
    'roles' => array(),
    'module' => 'auto_entitylabel',
  );

  // Exported permission: 'use ctools import'.
  $permissions['use ctools import'] = array(
    'name' => 'use ctools import',
    'roles' => array(),
    'module' => 'ctools',
  );

  // Exported permission: 'use ipe with page manager'.
  $permissions['use ipe with page manager'] = array(
    'name' => 'use ipe with page manager',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'use page manager'.
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(),
    'module' => 'page_manager',
  );

  // Exported permission: 'use panels caching features'.
  $permissions['use panels caching features'] = array(
    'name' => 'use panels caching features',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'use panels dashboard'.
  $permissions['use panels dashboard'] = array(
    'name' => 'use panels dashboard',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'use panels in place editing'.
  $permissions['use panels in place editing'] = array(
    'name' => 'use panels in place editing',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'use panels locks'.
  $permissions['use panels locks'] = array(
    'name' => 'use panels locks',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'use text format elife_full_html'.
  $permissions['use text format elife_full_html'] = array(
    'name' => 'use text format elife_full_html',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format elife_house_style'.
  $permissions['use text format elife_house_style'] = array(
    'name' => 'use text format elife_house_style',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'view any unpublished content'.
  $permissions['view any unpublished content'] = array(
    'name' => 'view any unpublished content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished elife_annual_report content'.
  $permissions['view any unpublished elife_annual_report content'] = array(
    'name' => 'view any unpublished elife_annual_report content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished elife_article content'.
  $permissions['view any unpublished elife_article content'] = array(
    'name' => 'view any unpublished elife_article content',
    'roles' => array(),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished elife_article_reference content'.
  $permissions['view any unpublished elife_article_reference content'] = array(
    'name' => 'view any unpublished elife_article_reference content',
    'roles' => array(),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished elife_article_ver content'.
  $permissions['view any unpublished elife_article_ver content'] = array(
    'name' => 'view any unpublished elife_article_ver content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Article Publisher' => 'eLife Article Publisher',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished elife_collection content'.
  $permissions['view any unpublished elife_collection content'] = array(
    'name' => 'view any unpublished elife_collection content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished elife_contributor content'.
  $permissions['view any unpublished elife_contributor content'] = array(
    'name' => 'view any unpublished elife_contributor content',
    'roles' => array(),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished elife_cover content'.
  $permissions['view any unpublished elife_cover content'] = array(
    'name' => 'view any unpublished elife_cover content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished elife_early_careers_interview content'.
  $permissions['view any unpublished elife_early_careers_interview content'] = array(
    'name' => 'view any unpublished elife_early_careers_interview content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished elife_early_careers_spotlight content'.
  $permissions['view any unpublished elife_early_careers_spotlight content'] = array(
    'name' => 'view any unpublished elife_early_careers_spotlight content',
    'roles' => array(),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished elife_event content'.
  $permissions['view any unpublished elife_event content'] = array(
    'name' => 'view any unpublished elife_event content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished elife_fragment content'.
  $permissions['view any unpublished elife_fragment content'] = array(
    'name' => 'view any unpublished elife_fragment content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Article Publisher' => 'eLife Article Publisher',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished elife_front_matter content'.
  $permissions['view any unpublished elife_front_matter content'] = array(
    'name' => 'view any unpublished elife_front_matter content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished elife_labs_entry content'.
  $permissions['view any unpublished elife_labs_entry content'] = array(
    'name' => 'view any unpublished elife_labs_entry content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished elife_news_article content'.
  $permissions['view any unpublished elife_news_article content'] = array(
    'name' => 'view any unpublished elife_news_article content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished elife_organisation content'.
  $permissions['view any unpublished elife_organisation content'] = array(
    'name' => 'view any unpublished elife_organisation content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished elife_person_profile content'.
  $permissions['view any unpublished elife_person_profile content'] = array(
    'name' => 'view any unpublished elife_person_profile content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished elife_podcast content'.
  $permissions['view any unpublished elife_podcast content'] = array(
    'name' => 'view any unpublished elife_podcast content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished elife_podcast_chapter content'.
  $permissions['view any unpublished elife_podcast_chapter content'] = array(
    'name' => 'view any unpublished elife_podcast_chapter content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished elife_term_reference content'.
  $permissions['view any unpublished elife_term_reference content'] = array(
    'name' => 'view any unpublished elife_term_reference content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished webform content'.
  $permissions['view any unpublished webform content'] = array(
    'name' => 'view any unpublished webform content',
    'roles' => array(),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view pane admin links'.
  $permissions['view pane admin links'] = array(
    'name' => 'view pane admin links',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'view scheduled content'.
  $permissions['view scheduled content'] = array(
    'name' => 'view scheduled content',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'scheduler',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'eLife Administrator' => 'eLife Administrator',
      'eLife Editor' => 'eLife Editor',
    ),
    'module' => 'system',
  );

  return $permissions;
}
