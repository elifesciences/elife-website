<?php

$databases = [
  'default' =>
    [
      'default' =>
        [
          'database' => 'elife_profile',
          'username' => 'root',
          'password' => '',
          'host' => 'localhost',
          'port' => '',
          'driver' => 'mysql',
          'prefix' => '',
        ],
    ],
];

$conf['elife_article_markup_service_factory'] = '_elife_article_mock_markup_service';
$conf['elife_node_binary'] = '%NODE_BIN%';
