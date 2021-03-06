<?php

/**
 * @file
 * elife_article_aff_details.inc
 */

use eLife\EIF\ArticleVersion;
use eLife\EIF\ArticleVersion\Contributor;
use eLife\EIF\ArticleVersion\Contributor\OnBehalfOfContributor;
use eLife\EIF\ArticleVersion\Contributor\PersonContributor;
use eLife\EIF\ArticleVersion\Contributor\PersonContributor\BylineContributor;
use eLife\EIF\ArticleVersion\Contributor\CollabContributor;

$plugin = array(
  'title' => t('Article affiliation details'),
  'single' => TRUE,
  'description' => t('Affiliation details - all authors with full affiliation details.'),
  'category' => array('eLife'),
  'edit form' => 'elife_article_aff_details_edit',
  'render callback' => 'elife_article_aff_details_render',
  'required context' => new ctools_context_required('Article Node', 'node'),
);

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function elife_article_aff_details_render($subtype, $conf, $args, $context) {
  drupal_add_js(drupal_get_path('module', 'elife_templates') . '/js/elife_article_authors.js');
  $article_version = $context->data;
  $dto = elife_article_version_to_dto($article_version);

  $authors_full = [];
  $contributors = $dto->getContributors();

  if (!empty($contributors)) {
    $contribs = $dto->getReferenced()->getContribution();
    foreach ($contribs as $key => $value) {
      $split = strpos($value, ': ');
      if (!$split) {
        $split = strpos($value, ', ');
      }
      if ($split) {
        $value = substr($value, $split + 2);
      }
      $contribs[$key] = $value;
    }

    $footnotes = [];
    foreach ($dto->getReferenced()->getFootNote() as $fn => $footnote) {
      $footnotes[$footnote->getType()][$fn] = $footnote->getValue();
    }

    // Prepare equal_contrib name lists so that we can easily strip a name out.
    $equal_contribs = [];
    foreach ($contributors as $co => $contributor) {
      if ($contributor instanceof Contributor) {
        if ($references = $contributor->getReferences()) {
          if (!empty($references['equal-contrib'])) {
            if ($contributor instanceof BylineContributor) {
              $name = [];
              if ($given_names = $contributor->getGivenNames()) {
                $name['given-names'] = $given_names;
              }
              if ($surname = $contributor->getSurname()) {
                $name['surname'] = $surname;
              }
              if ($suffix = $contributor->getSuffix()) {
                $name['suffix'] = $suffix;
              }
              foreach ($references['equal-contrib'] as $ec) {
                $equal_contribs[$ec][$co] = implode(' ', $name);
              }
            }
          }
        }
      }
    }

    foreach ($contributors as $co => $contributor) {
      if ($contributor->getType() != 'author') {
        continue;
      }
      $variables = [];
      $name = [];
      if ($contributor instanceof BylineContributor) {
        $name = $contributor->getNameParts();
        if ($orcid = $contributor->getOrcId()) {
          $orcid_options = array(
            'external' => TRUE,
            'attributes' => array(
              'target' => '_blank',
            ),
          );
          $orcid_image = theme('image', array(
            'path' => drupal_get_path('module', 'elife_templates') . '/images/orcid.png',
            'alt' => 'ORCID',
            'attributes' => array(
              'class' => 'corresp-icon',
            ),
          ));
          $variables['orcid_image'] = l($orcid_image, $orcid, array_merge(array('html' => TRUE), $orcid_options));

          $orcid = l($orcid, $orcid, $orcid_options);
          $variables['orcid'] = $orcid;
        }
      }
      elseif ($contributor instanceof CollabContributor) {
        if ($collab = $contributor->getName()) {
          $name['collab'] = $collab;
        }
      }
      elseif ($contributor instanceof OnBehalfOfContributor) {
        if ($on_behalf_of = $contributor->getName()) {
          $name['on-behalf-of'] = $on_behalf_of;
        }
      }

      if (!empty($name)) {
        $author = [];
        foreach ($name as $k => $n) {
          $author[] = '<span class="' . $k . '">' . $n . '</span>';
        }
        $variables['tooltip_name'] = implode(' ', $author);
        if ($contributor instanceof BylineContributor && $role = $contributor->getRole()) {
          $variables['tooltip_name'] .= ', <span class="role">' . $role . '</span>';
        }
      }

      $references = $contributor->getReferences();
      if (!empty($references['present-address'])) {
        $present_addresses = $dto->getReferenced()->getPresentAddress();
        $variables['present_addy'] = implode('; ', array_intersect_key($present_addresses, array_flip($references['present-address'])));
      }
      if (!empty($references['contribution'])) {
        $variables['contrib'] = implode('; ', array_intersect_key($contribs, array_flip($references['contribution'])));
      }
      if (!empty($references['foot-note']) && !empty($footnotes['other'])) {
        $variables['other_footnotes'] = array_intersect_key($footnotes['other'], array_flip($references['foot-note']));
      }
      if (!empty($references['contribution'])) {
        $variables['contrib'] = implode('; ', array_intersect_key($contribs, array_flip($references['contribution'])));
      }
      if (!empty($references['foot-note']) && !empty($footnotes['deceased'])) {
        $variables['deceased_footnote'] = implode('; ', array_intersect_key($footnotes['deceased'], array_flip($references['foot-note'])));
      }
      if (!empty($references['competing-interest'])) {
        $competing_interests = $dto->getReferenced()->getCompetingInterest();
        $conflicts = array_intersect_key($competing_interests, array_flip($references['competing-interest']));
        $conflict = [];
        foreach ($conflicts as $conf) {
          if (mb_strpos($conf, 'no competing interests') === FALSE) {
            $conflict[] = $conf;
          }
        }
        if (!empty($conflict)) {
          $variables['conflict'] = _elife_article_xmltohtml(implode(' ', $conflict)); // TODO sort
        }
      }
      if (!empty($references['equal-contrib'])) {
        $ecgs = [];
        foreach ($references['equal-contrib'] as $eq) {
          // Only display the other authors in the equal-contrib list.
          if (isset($equal_contribs[$eq][$co])) {
            $ecg = array_diff_key($equal_contribs[$eq], array_flip([$co]));
            if (!empty($ecg)) {
              $ecgs[] = implode(', ', $ecg);
            }
          }
        }
        $variables['equal_contrib_group'] = implode('; ', array_unique($ecgs));
      }

      if ($contributor instanceof Contributor) {
        _elife_article_aff_details_contrib_affiliations($variables, ($co + 1), $contributor, $dto);
      }

      if (!empty($references['email'])) {
        $emails = $dto->getReferenced()->getEmail();
        $emails = array_intersect_key($emails, array_flip($references['email']));
        $email = reset($emails);
        $variables['email'] = $email;
      }
      elseif ($contributor instanceof PersonContributor && $contributor->getEmail()) {
        $variables['email'] = $contributor->getEmail();
      }

      if (empty($variables['email']) && $contributor instanceof PersonContributor && count($contributor->getAffiliations())) {
        foreach ($contributor->getAffiliations() as $aff) {
          if ($email = $aff->getEmail()) {
            $variables['email'] = $email;
            break;
          }
        }
      }

      if (empty($variables['email']) && !empty($variables['affiliation']) &&
        preg_match('/^(?P<before>.*)\s<a [^>]*class=\"email\"[^>]*>(?P<email>[^\<]+)<\/a>(?P<after>.*)$/', $variables['affiliation'], $matches)) {
        $variables['affiliation'] = $matches['before'] . $matches['after'];
        $variables['email'] = $matches['email'];
      }

      $tooltip_content = theme('elife_article_author_tooltip', $variables);
      $authors_full[] = '<li class="item-' . $co . '">' . trim($tooltip_content) . '</li>';
    }
  }

  if (!empty($authors_full)) {
    $block = new stdClass();
    $block->title = t('Affiliation details');
    $block->content = '<div class="author-list-full ctools-collapsible-content"><ul>' . implode("\n", $authors_full) . '</ul></div>';
    return $block;
  }
}

/**
 * @param $variables
 * @param $pos
 * @param Contributor $contributor
 * @param ArticleVersion $dto
 * @return array
 */
function _elife_article_aff_details_contrib_affiliations(&$variables, $pos, Contributor $contributor, ArticleVersion $dto) {
  $markup = elife_article_markup_service();
  $markup->addAuthorAffiliationQuery($dto->getArticleVersionId(), $pos);
  $markup = _elife_article_markup_query($markup);
  if ($affiliation = $markup->output()) {
    $variables['affiliation'] = $affiliation;
  }
}

/**
 * Edit form callback for the content type.
 */
function elife_article_aff_details_edit($form, &$form_state) {
  return $form;
}

/**
 * Edit form callback for the content type.
 */
function elife_article_aff_details_edit_submit(&$form, &$form_state) {
  // Nothing.
}
