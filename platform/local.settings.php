<?php

$platform = json_decode(base64_decode($_SERVER['PLATFORM_RELATIONSHIPS']), TRUE);

$platform_database = reset($platform['database']);
$platform_solr = reset($platform['solr']);
$platform_redis = reset($platform['redis']);

$databases = [
  'default' =>
    [
      'default' =>
        [
          'database' => $platform_database['path'],
          'username' => $platform_database['username'],
          'password' => $platform_database['password'],
          'host' => $platform_database['host'],
          'port' => $platform_database['port'],
          'driver' => $platform_database['scheme'],
          'prefix' => '',
        ],
    ],
];

$conf['elife_cache_dir'] = sprintf('%s/%s-%s-%s', sys_get_temp_dir(), 'elife', $_SERVER['PLATFORM_PROJECT'], $_SERVER['PLATFORM_ENVIRONMENT']);
$conf['elife_environment'] = ELIFE_ENVIRONMENT_PRODUCTION;

$conf['search_api_override_mode'] = 'default';
$conf['search_api_override_servers']['elife_solr']['options']['host'] = $platform_solr['host'];
$conf['search_api_override_servers']['elife_solr']['options']['port'] = $platform_solr['port'];
$conf['search_api_override_servers']['elife_solr']['options']['path'] = '/' . ltrim($platform_solr['path'], '/');

$conf['redis_client_host'] = $platform_redis['host'];
$conf['redis_client_port'] = $platform_redis['port'];

$conf['imagemagick_convert'] = '/usr/bin/convert';
