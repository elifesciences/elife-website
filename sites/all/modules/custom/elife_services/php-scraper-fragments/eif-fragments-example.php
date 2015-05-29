<?php

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


function generate_eif_fragments(SimpleXMLElement $xml, $url_prefix, $add_preferred_paths, $check_url_response = FALSE) {
  $fragments = array();
  $except_subarticles = xml_parse_fragments($xml, $url_prefix, $structure, 'ancestor::sub-article', '', $add_preferred_paths);
  $only_subarticles = xml_parse_fragments($xml, $url_prefix, $structure, '', 'ancestor::sub-article', $add_preferred_paths);

  foreach ($only_subarticles as $k => $subarticle) {
    if ($only_subarticles[$k]['type'] == 'sub-article') {
      unset($only_subarticles[$k]['type']);
    }
  }

  if (!empty($except_subarticles)) {
    $except_sub = prepare_fragment_array($except_subarticles, $structure, $check_url_response);
    $fragments['fragment'] = $except_sub;
  }

  if (!empty($only_subarticles)) {
    $only_sub = prepare_fragment_array($only_subarticles, $structure, $check_url_response);
    $fragments['sub-article'] = $only_sub;
  }

  if (!empty($fragments)) {
    $fragments = array(
      'children' => $fragments,
    );
  }

  return $fragments;
}

function url_prefixes() {
  $default = array(
    'fig' => 'F',
    'table-wrap' => 'T',
    'boxed-text' => 'B',
    'supplementary-material' => 'DC',
    'abstract' => 'abstract-',
    'media' => 'media-',
  );
  $preferred = array(
    'supplementary-material' => 'SD',
    'abstract' => 'abstract-',
    'media' => 'M',
  );
  $preferred += $default;
  $child = array(
    'fig' => 'FS',
  );
  $child += $preferred;

  return array(
    'default' => $default,
    'preferred' => $preferred,
    'child' => $child,
  );
}

function fragment_types() {
  return array(
    'fig',
    'table-wrap',
    'boxed-text',
    'supplementary-material',
    'abstract',
    'media',
    'sub-article',
  );
}

function xml_parse_fragments(SimpleXMLElement $xml, $url_prefix, &$structure = array(), $exclude = '', $include = '', $add_preferred_paths = FALSE) {
  $fragments = array();

  $title = $xml->xpath('//title-group/article-title')[0];
  $article_doi = $xml->xpath('//article-meta/article-id[@pub-id-type="doi"]')[0];

  $xpath_doi = '-id[@pub-id-type="doi"][contains(text(), "10.7554/eLife.")]';
  $xpath_object_doi = 'object' . $xpath_doi;
  $xpath_article_doi = 'article' . $xpath_doi;

  $fragment_dois = $xml->xpath('//' . $xpath_object_doi . ' | //' . $xpath_article_doi);

  $url_prefixes = url_prefixes();

  $prefixes = $url_prefixes['default'];
  $parent_prefixes = $url_prefixes['preferred'];
  $child_prefixes = $url_prefixes['child'];

  $fragment_types = fragment_types();

  $possible_xpath = '//' . implode(' | //', $fragment_types);

  $parent_types = $fragment_types;
  $parent_types[] = 'fig-group/fig';
  $parent_xpath = 'ancestor::' . implode(' | ancestor::', $parent_types);

  $possible_fragments = $xml->xpath($possible_xpath);

  $types = array();
  $parent_types = array();
  $child_types = array();

  $slugs = array();
  $preferred_slugs = array();

  foreach ($possible_fragments as $possible_fragment) {
    $skip = FALSE;

    if ($fragment_doi = $possible_fragment[0]->xpath($xpath_object_doi . ' | front-stub/' . $xpath_article_doi)) {
      $doi = (string) $fragment_doi[0];
      if (!empty($exclude) && $fragment_doi[0]->xpath($exclude)) {
        $skip = TRUE;
      }
      elseif (!empty($include) && !$fragment_doi[0]->xpath($include)) {
        $skip = TRUE;
      }
      $object_or_article = $fragment_doi[0]->getName();
      if ($object_or_article == 'article-id') {
        $fragment = $fragment_doi[0]->xpath('../..');
      }
      else {
        $fragment = $fragment_doi[0]->xpath('..');
      }
    }
    else {
      $doi = '';
      $fragment = $possible_fragment[0];
      $skip = TRUE;
    }

    if ($doi == $article_doi) {
      continue;
    }

    $type = $fragment[0]->getName();
    $types[$type][] = $doi;

    $frag = array(
      'type' => $type,
      'doi' => $doi,
      'path' => $url_prefix . '/',
    );

    $preferred_path = $frag['path'];

    if ($type == 'abstract' && !empty($fragment[0]['abstract-type'])) {
      $frag['abstract-type'] = (string) $fragment[0]['abstract-type'];
    }

    if ($fragment[0]->label) {
      $frag['title'] = (string) $fragment[0]->label;
    }
    elseif ($title = $fragment[0]->xpath('front-stub/title-group/article-title')) {
      $frag['title'] = (string) $title[0];
    }

    $parent_fragment = $fragment[0]->xpath($parent_xpath);
    $parent_found = FALSE;
    if ($parent_fragment) {
      $parent_doi = $parent_fragment[0]->xpath($xpath_object_doi . ' | front-stub/' . $xpath_article_doi);
      if ($parent_doi) {
        $parent_doi = (string) $parent_doi[0];
        if ($parent_doi != $doi) {
          $frag['path'] .= $slugs[$parent_doi] . '/';
          $preferred_path .= $preferred_slugs[$parent_doi] . '/';
          $parent_found = TRUE;
          if (!$skip) {
            $structure[$parent_doi][$doi] = array();
          }
        }
      }
    }

    if (!$parent_found) {
      if (!$skip) {
        $structure[$doi] = array();
      }
      $child_types = array();
      $parent_types[$type][] = $doi;
    }
    else {
      $child_types[$type][] = $doi;
    }

    $slug = (!empty($prefixes[$type])) ? $prefixes[$type] : '';

    $preferred_prefixes = $parent_prefixes;
    if ($parent_found) {
      $preferred_prefixes = $child_prefixes;
    }
    $preferred_slug = (!empty($preferred_prefixes[$type])) ? $preferred_prefixes[$type] : '';


    if (!empty($prefixes[$type])) {
      $slug .= count($types[$type]);
    }
    else {
      $types['other'][] = $doi;
      $slug .= count($types['other']);
    }

    if (!empty($preferred_prefixes[$type])) {
      if ($parent_found) {
        $preferred_slug .= count($child_types[$type]);
      }
      else {
        $preferred_slug .= count($parent_types[$type]);
      }
    }
    else {
      if ($parent_found) {
        $child_types['other'][] = $doi;
        $preferred_slug .= count($child_types['other']);
      }
      else {
        $parent_types['other'][] = $doi;
        $preferred_slug .= count($parent_types['other']);
      }
    }

    $slugs[$doi] = $slug;
    $frag['path'] .= $slug;

    if (!empty($frag['title']) && $frag['title'] == 'Decision letter') {
      $preferred_slug = 'decision';
    }
    elseif (!empty($frag['title']) && $frag['title'] == 'Author response') {
      $preferred_slug = 'response';
    }
    elseif ($type == 'abstract' && !empty($frag['abstract-type']) && $frag['abstract-type'] == 'executive-summary') {
      $preferred_slug = 'digest';
    }
    elseif ($type == 'abstract') {
      $preferred_slug = 'abstract';
    }

    $preferred_slugs[$doi] = $preferred_slug;
    $preferred_path .= $preferred_slug;

    if ($add_preferred_paths) {
      $frag['preferred_path'] = $preferred_path;
    }

    if (!$skip) {
      $fragments[$doi] = $frag;
    }
  }

  return $fragments;
}

function prepare_fragment_array($fragments, $structure, $check_url_response = FALSE) {
  $frag_arr = array();
  foreach ($structure as $doi => $child_structure) {
    if (isset($fragments[$doi])) {
      $frag = $fragments[$doi];
      if (!empty($child_structure)) {
        $children = prepare_fragment_array($fragments, $child_structure);
        $frag['children'] = array(
          'fragment' => $children,
        );
      }
      if ($check_url_response && isset($frag['path'])) {
        $frag['response_code'] = check_url_response($frag['path']);
      }
      $frag_arr[] = $frag;
    }
  }

  return $frag_arr;
}

/**
 * @see http://stackoverflow.com/questions/6054033/pretty-printing-json-with-php
 */
function prettyPrint($json) {
  $result = '';
  $level = 0;
  $in_quotes = FALSE;
  $in_escape = FALSE;
  $ends_line_level = NULL;
  $json_length = strlen($json);

  for ($i = 0; $i < $json_length; $i++) {
    $char = $json[$i];
    $new_line_level = NULL;
    $post = "";
    if ($ends_line_level !== NULL) {
      $new_line_level = $ends_line_level;
      $ends_line_level = NULL;
    }
    if ($in_escape) {
      $in_escape = FALSE;
    }
    else if ($char === '"') {
      $in_quotes = !$in_quotes;
    }
    else if (!$in_quotes) {
      switch ($char) {
        case '}':
        case ']':
          $level--;
          $ends_line_level = NULL;
          $new_line_level = $level;
          break;

        case '{':
        case '[':
          $level++;
        case ',':
          $ends_line_level = $level;
          break;

        case ':':
          $post = " ";
          break;

        case " ":
        case "\t":
        case "\n":
        case "\r":
          $char = "";
          $ends_line_level = $new_line_level;
          $new_line_level = NULL;
          break;
      }
    }
    else if ($char === '\\') {
      $in_escape = TRUE;
    }
    if ($new_line_level !== NULL) {
      $result .= "\n" . str_repeat("  ", $new_line_level);
    }
    $result .= $char . $post;
  }

  return $result;
}

function check_url_response($url) {
  $base_url = 'http://elifesciences.org/';
  $handle = curl_init($base_url . $url);
  curl_setopt($handle, CURLOPT_RETURNTRANSFER, TRUE);

  $response = curl_exec($handle);

  $httpCode = curl_getinfo($handle, CURLINFO_HTTP_CODE);

  curl_close($handle);

  return $httpCode;
}
