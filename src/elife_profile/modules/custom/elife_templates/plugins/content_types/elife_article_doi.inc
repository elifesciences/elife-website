<?php

$plugin = array(
  'title' => t('Article / Fragment - DOI, date, corrections, and other info'),
  'single' => TRUE,
  'category' => array('eLife'),
  'edit form' => 'elife_article_doi_edit',
  'render callback' => 'elife_article_doi_render',
  'required context' => new ctools_context_required('Article / Fragment Node', 'node'),
);

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function elife_article_doi_render($subtype, $conf, $args, $context) {
  $node = $context->data;

  $output = '<div class="pane-elife-doi">';

  // Print correction info first
  $corrections = highwire_get_corrections($node->nid);

  if (!empty($corrections)) {
    $output .= '<div class="elife-article-corrections">';

    foreach ($corrections as $correction) {
      if ($correction['type'] == 'Revision#addendum'){
        $output .= '<span class="elife-article-addendum"><i class="icon-exclamation-sign"></i>' . l('This article has been addended', 'node/' . $correction['correction']) . '</span>';
      }
      if ($correction['type'] == 'Revision#correction'){
        $output .= '<span class="elife-article-correction"><i class="icon-exclamation-sign"></i>' . l('This article has been corrected', 'node/' . $correction['correction']) . '</span>';
      }
      if ($correction['type'] == 'Revision#retraction') {
        $output .= '<span class="elife-article-retraction"><i class="icon-warning-sign"></i>' . l('This article has been retracted', 'node/' . $correction['correction']) .'</span>';
      }
    }

    $output .= '</div>';
  }

  // If this is a correction, we need to get the reverse link
  $article_type = $node->field_highwire_article_type[X][0]['value'];
  if (in_array($article_type, array('correction', 'retraction', 'addendum'))) {
    $output .= '<div class="elife-article-corrections">';

    $subject = elife_article_get_related($node->nid, 'Revision#subject');

    $articles = array();
    foreach ($subject as $item) {
      $articles[] = $item['entity_id'];
    }

    if (!empty($articles)) {
      $nodes = node_load_multiple($articles, array('type' => 'highwire_article'));

      if (!empty($nodes)) {
        foreach ($nodes as $nid => $article) {
          if ($article->field_highwire_article_ver[X][0]['value'] == "curr") {
            $items = $article;
          }
        }
      }
    }

    if ($article_type == 'addendum'){
      $output .= '<span class="elife-article-addendum">' . l('View the addended article', 'node/' . $items->nid) . '</span>';
    }
    if ($article_type == 'correction'){
      $output .= '<span class="elife-article-correction">' . l('View the corrected article', 'node/' . $items->nid) . '</span>';
    }
    if ($article_type == 'retraction') {
      $output .= '<span class="elife-article-retraction">' . l('View the retracted article', 'node/' . $items->nid) .'</span>';
    }

    $output .= '</div>';
  }

  // Now print DOI and other misc info
  if ($node->type == 'highwire_article') {
    if (intval($node->field_highwire_a_subcomponent[X][0]['value'])) {
      $label = $node->title . ' DOI';
    }
    else {
      $label = 'DOI';
    }
  }
  else if ($node->type == 'highwire_fragment') {
    $map = array(
      'table' => 'Table DOI',
      'figure' => 'Figure DOI',
      'executive-summary' => 'eLife digest DOI',
      'abstract' => 'Abstract DOI',
      'video' => 'Video DOI',
      'chem' => 'Chemical DOI',
      'supplementary-material' => 'Source data DOI',
    );

    $frag_type = $node->field_highwire_fragment_type[X][0]['value'];

    if (array_key_exists($frag_type, $map)) {
      $label = $map[$frag_type];
    }
    else {
      $label = 'DOI';
    }
  }
  else {
    $label = 'DOI';
  }

  $doi = 'http://dx.doi.org/' . $node->field_highwire_a_doi[X][0]['value'];
  $doi_link = l($doi, $doi);

  $output .= '<span class="highwire-doi-doi"><span class="highwire-doi-pre-label label">' . $label . ': </span><span class="elife-doi-doi">' . $doi_link . '</span></span>';

  // Cite as and pub-date info
  if ($node->type == 'highwire_article') {
    if (!intval($node->field_highwire_a_subcomponent[X][0]['value'])) {
      $info = highwire_token_extract_node_data($node);
      $epubdate = new DateTime($info['epubdate']);

      $output .= '<span class="highwire-doi-epubdate"><span class="highwire-doi-epubdate-label label">Published</span> <span class="highwire-doi-epubdate-data">' . $epubdate->format('F j, Y') . '</span></span>';
      if($node->field_highwire_article_early[X][0]['value'] == 1) {
        $output .= '<span class="highwire-doi-cite-as">
          <span class="highwire-doi-cite-as-label label">Cite as </span>
          <span class="highwire-doi-cite-as-data">eLife ' . $info['year'] . ';' . $node->field_highwire_a_doi[X][0]['value'] . '</span>
        </span>';

        $pdf_path = url('node/'. $node->nid) . '.full.pdf';
        $pdf_link = l('PDF', $pdf_path, array('external' => TRUE, 'html' => TRUE, 'attributes' => array('title' => 'PDF', 'type' => 'application/pdf', 'rel' => 'alternative')));

        $output .= '<span class="highwire-download-pdf">
          <span class="highwire-download-pdf label">Download </span>
          <span class="highwire-download-pdf-link">' . $pdf_link . '</span>
        </span>';
      }
      else {
        $output .= '<span class="highwire-doi-cite-as">
          <span class="highwire-doi-cite-as-label label">Cite as </span>
          <span class="highwire-doi-cite-as-data">eLife ' . $info['year'] . ';' . $info['volume'] . ':' . $info['slug'] . '</span>
        </span>';
      }
    }
  }

  $output .= '</div>';

  $block->content = $output;

  return $block;
}

/**
 * 'Edit form' callback for the content type.
 */
function elife_article_doi_edit($form, &$form_state) {
  return $form;
}

/**
 * 'Edit form' callback for the content type.
 */
function elife_article_doi_edit_form_submit(&$form, &$form_state) {
  // Nothing
}
