<?php

// Make sure we're in the Drupal directory.
chdir(__DIR__ . '/../../web');

$url = parse_url($_SERVER['REQUEST_URI']);

if (file_exists('.' . $url['path'])) {
  // Serve the requested resource as-is.
  return FALSE;
}

// Populate the "q" query key with the path, skip the leading slash.
$_GET['q'] = $_REQUEST['q'] = ltrim($url['path'], '/');

// Run Drupal.
require 'index.php';
