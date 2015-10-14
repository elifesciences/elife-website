<?php

/**
 * @file
 * Ctools render code for the article sidebar block.
 */

$plugin = [
  'title' => t('Article Toolbox'),
  'single' => TRUE,
  'category' => ['eLife'],
  'edit form' => 'elife_article_toolbox_edit',
  'render callback' => 'elife_article_toolbox_render',
  'required context' => new ctools_context_required('Article Node', 'node'),
];

/**
 * Run-time rendering of the body of the block (content type).
 *
 * See ctools_plugin_examples for more advanced info
 */
function elife_article_toolbox_render($subtype, $conf, $args, $context) {
  $variables['node'] = $context->data;
  $block = new stdClass();
  $block->content = theme('elife_article_toolbox', $variables);
  return $block;
}

/**
 * Theme render function for the eLife article 'toolbox' in the sidebar.
 *
 * Links to download alternate versions of the article, to change text size,
 * hooks for ShareThis, and the API entry point.
 *
 * @param array $variables
 *   Theme variables, containing 'node', the article node id.
 *
 * @return string
 *   The HTML for the block.
 */
function theme_elife_article_toolbox($variables) {
  $article_version = $variables['node'];
  $dto = elife_article_version_to_dto($article_version);

  $node_url = 'url=' . url('node/' . $article_version->nid, ['absolute' => TRUE]) . '&doi=' . $dto->getDoi();
  drupal_add_js(drupal_get_path('module', 'elife_templates') . '/js/elife_article_citation.js');
  drupal_add_js(['elife_article_toolbox' => ['url' => $node_url]], 'setting');

  $output = '';

  $article_tools_options = [
    'external' => TRUE,
    'html' => TRUE,
    'attributes' => [
      'title' => t('Article PDF'),
      'type' => 'application/pdf',
      'rel' => 'alternate',
      'class' => [
        'article-tools__link',
      ],
      'data-article-identifier' => $dto->getDoi(),
    ],
  ];

  $article_tools_links = [];
  $tools_list_item_class_names = [
    'article-tools__list_item',
  ];
  if (module_exists('elife_resources')) {
    // @todo - elife - nlisgo - may need to introduce the pdf in different way.
    $resources = new elifeResources();
    $resources->getArticle($dto->getDoi());
    $pdf_urls = $resources->getUrls();
    if (!empty($pdf_urls)) {
      foreach ($pdf_urls as $type => $pdfs) {
        $options = $article_tools_options;
        $options['attributes']['download'] = NULL;
        $options['attributes']['class'][] = 'article-tools__link--pdf-' . $type;
        $options['attributes']['data-download-type'] = 'pdf-' . $type;
        $options['attributes']['title'] = t('@type PDF', ['@type' => drupal_ucfirst($type)]);
        foreach ($pdfs as $pdf) {
          $link_title = t('@type', ['@type' => drupal_ucfirst($type)]);
          $article_tools_links[] = [
            'data' => l($link_title, $pdf['url'], $options),
            'classes' => $tools_list_item_class_names,
          ];
        }
      }
    }
  }

  if (!empty($article_tools_links)) {
    $output .= '<section class="article-tools">';
    $output .= '<h2 class="pane-title">' . t('Downloads:') . '</h2>';
    $output .= theme('item_list', [
      'items' => $article_tools_links,
      'attributes' => ['class' => 'article-tools__list inline'],
      'div_class' => 'no',
    ]);
    $output .= '</section>';
    $output .= '<div class="panel-separator"></div>';
  }


  $output .= '<div class="elife-share-wrapper">';
  // @todo - elife - nlisgo - configure sharethis
  $output .= sharethis_block_contents();
  $output .= "<script type='text/javascript'>stLight.options({onhover:false , doNotHash: true, doNotCopy: true, hashAddressBar: false});</script>";
  $output .= '</div>';

  $output .= '<div class="panel-separator"></div>';
  $output .= '<h2 class="pane-title">' . t('Reference tools:') . '</h2>';

  // @todo - elife - nlisgo - these are just placeholder links.
  // Download.
  $citations_options = [
    'RIS' => 'ris',
    'BibTeX' => 'bibtex',
  ];

  $download = '<div id="citations_options" class="article-toolbox-wrapper">';
  $download .= '<h5 class="citation-tooltip-head">' . t('Download Citations') . '</h5>';

  foreach ($citations_options as $name => $value) {
    $link_path = 'elife/citation/' . $article_version->nid . '/' . $value;
    $icon_image = drupal_html_class($name);
    $link_wrapper = '<span class="icon-citation-download icon-citation-' . $icon_image . '"></span>';
    $link_wrapper .= '<span class="name">' . $name . '</span>';
    $item_link = l($link_wrapper, $link_path, ['html' => TRUE]);
    $citations_item = $item_link;
    $citations_items[] = $citations_item;
  }

  $col1 = array_splice($citations_items, 1);
  $col2 = $citations_items;

  $download .= '<div class="citation-col">';
  $download .= theme('item_list', [
    'items' => $col1,
    'attributes' =>
      ['class' => 'citations-list'],
  ]);
  $download .= '</div>';
  $download .= '<div class="citation-col">';
  $download .= theme('item_list', [
    'items' => $col2,
    'attributes' =>
      ['class' => 'citations-list'],
  ]);
  $download .= '</div>';
  $download .= '</div>';

  // Open Links.
  $open_links = [
    [
      'title' => t('Mendeley'),
      'href' => 'http://www.mendeley.com/import',
      'attributes' => ['class' => ['mendeley']],
      'query' => [
        'doi' => $dto->getDoi(),
      ],
    ],
    [
      'title' => t('Readcube'),
      'href' => 'http://www.readcube.com/articles/' . $dto->getDoi(),
      'attributes' => ['class' => ['readcube']],
    ],
    [
      'title' => t('Papers App'),
      'attributes' => ['class' => ['papersapp']],
      'href' => 'papers2://url/' . url('node/' . $article_version->nid, ['absolute' => TRUE]),
      'query' => ['title' => $dto->getTitle()],
      'external' => TRUE,
    ],
    [
      'title' => t('Citeulike'),
      'external' => TRUE,
      'href' => 'http://www.citeulike.org/posturl',
      'attributes' => ['class' => ['citeulike']],
      'query' => [
        'url' => url('node/' . $article_version->nid, ['absolute' => TRUE]),
        'ourl' => url('node/' . $article_version->nid, ['absolute' => TRUE]),
        'title' => $dto->getTitle(),
        'doi' => $dto->getDoi(),
      ],
    ],
  ];

  $col1 = array_splice($open_links, 0, 2);
  $col2 = $open_links;

  $open = '<div id="open_options" class="article-toolbox-wrapper">';
  $open .= '<h5 class="citation-tooltip-head">' . t('Open Citations In...') . '</h5>';
  $open .= '<div class="citation-col">';
  $open .= theme('links', [
    'links' => $col1,
    'attributes' =>
      ['class' => 'citations-list'],
  ]);
  $open .= '</div>';
  $open .= '<div class="citation-col">';
  $open .= theme('links', [
    'links' => $col2,
    'attributes' =>
      ['class' => 'citations-list'],
  ]);
  $open .= '</div>';
  $open .= '</div>';

  $citation_links = [
    [
      'data' => l(t('Download'), '', [
        'fragment' => 'api_box',
        'external' => TRUE,
      ]),
      'children' => ['data' => $download],
      'id' => 'download',
      'class' => ['show-article-toolbox-tooltip'],
    ],
    [
      'data' => l(t('Open'), '', [
        'fragment' => 'api_box',
        'external' => TRUE,
      ]),
      'children' => ['data' => $open],
      'id' => 'open',
      'class' => ['show-article-toolbox-tooltip'],
    ],
  ];

  $output .= theme('item_list', [
    'items' => $citation_links,
    'attributes' => [
      'class' => [
        'citation-links',
        'links',
        'inline',
        'hidden-small',
      ],
    ],
  ]);

  return $output;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_toolbox_edit($form, &$form_state) {
  return $form;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_toolbox_edit_form_submit(&$form, &$form_state) {
  // Nothing.
}
