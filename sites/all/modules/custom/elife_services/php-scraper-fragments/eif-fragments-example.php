<?php

include_once 'eif-fragments-inc.php';

$input = 'kitchen-sink.xml';

// Target an existing article XML by uncommenting the code below.
// $manuscript_id = '00288';
// $input = "https://s3.amazonaws.com/elife-cdn/elife-articles/{$manuscript_id}/elife{$manuscript_id}.xml";

// Set to TRUE if you want to add preferred paths in addition to the existing paths.
$add_preferred_paths = FALSE;

// Set to TRUE if you want to verify the response code of the paths on the http://elifesciences.org site.
$check_url_response = FALSE;

$xml = simplexml_load_file($input);

$volume = $xml->xpath('//article-meta/volume')[0];
$publisher_id = $xml->xpath('//article-meta/article-id[@pub-id-type="publisher-id"]')[0];
$url_prefix = 'content/' . $volume . '/e' . $publisher_id;

$eif_fragments = generate_eif_fragments($xml, $url_prefix, $add_preferred_paths, $check_url_response);

print prettyPrint(str_replace("\/", "/", json_encode($eif_fragments, JSON_UNESCAPED_UNICODE)));

exit;
