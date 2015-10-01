<?php

use Monolog\Handler\NullHandler;

$conf['elife_article_markup_service_factory'] = '_elife_article_mock_markup_service';
$conf['elife_node_binary'] = '%NODE_BIN%';

// Disable logging as we're not reading it.
$conf['elife_monolog_handlers'] = new NullHandler();

$conf['redis_client_host'] = '%REDIS_HOST%';
$conf['redis_client_port'] = %REDIS_PORT%;
