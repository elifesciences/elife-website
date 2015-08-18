<?php
/**
 * @file
 * templates/elife_early_careers.tpl.php
 */
?>
<section role="main" class="ec-wrapper">
  <section class="ec-hero-wrapper">
    <header class="ec-section ec-section--hero">
      <h1 class="ec-section__heading">What eLife offers <br />early-career researchers</h1>
    </header>
    <div class="ec-hero__overlay_wrapper">
      <section class="ec-hero__overlay">
        <div class="ec-hero__overlay_content">
          <p class="ec-hero__overlay_text">eLife is committed to meeting the needs and aspirations of early-career researchers, by highlighting their accomplishments and making them an active part of the eLife initiative. Learn more here, and get involved.</p>
        </div> <!-- /.ec-hero__overlay_content -->
      </section> <!-- /.ec-hero__overlay -->
    </div> <!-- /.ec-hero__overlay_wrapper -->
  </section> <!-- / .ec-hero-wrapper -->

  <?php if ($spotlight): ?>
  <section class="ec-section ec-section--latest">
    <?php print $spotlight; ?>
  </section> <!-- /.ec-section--latest -->
  <?php endif; ?>

  <section class="ec-section ec-section--showcase">
    <header id="early-career-spotlight">
      <h2 class="ec-section__heading">Spotlight on early careers</h2>
      <p class="ec-section--showcase__text">eLife showcases junior investigators and their work in a number of ways. These include the opportunity to present at prestigious meetings, interviews on the journal website, and various events. eLife editors are also willing to write letters of recommendation on behalf of the early-career authors of eLife papers.</p>
      <p class="ec-section--showcase__text">Read more about the ways in which eLife highlights early-career researchers:</p>
    </header>
    <article class="ec-section--showcase__item ec-section--showcase__item--presentation">
      <div class="ec-section--showcase__item_body">
        <h3 class="ec-section--showcase__item_title"><a href="#presentation-series">The eLife-sponsored presentation series</a></h3>
        <p class="ec-section--showcase__item_text">Twice a year the pre-tenure authors on a selection of outstanding eLife papers are invited to present at a scientific meeting organized by one of eLife&rsquo;s founders.</p>
      </div>
      <a class="ec-section--showcase__more_link" href="#presentation-series">Read more</a>
    </article>
    <article class="ec-section--showcase__item ec-section--showcase__item--interview">
      <div class="ec-section--showcase__item_body">
        <h3 class="ec-section--showcase__item_title"><a href="<?php print url('Discovery-drivers-eLife-interviews-early-stage-researchers'); ?>">Early-career researchers speak out</a></h3>
        <p class="ec-section--showcase__item_text">In a series of interviews with early-career researchers, eLife explores how they became interested in science, what they are working on at present, and what they hope to achieve in the future.</p>
      </div>
      <a class="ec-section--showcase__more_link" href="<?php print url('Discovery-drivers-eLife-interviews-early-stage-researchers'); ?>">Learn more</a>
    </article>
    <article class="ec-section--showcase__item ec-section--showcase__item--lab">
      <div class="ec-section--showcase__item_body">
        <h3 class="ec-section--showcase__item_title"><a href="<?php print url('elife-news/twitter-takeover'); ?>">Look inside another lab</a></h3>
        <p class="ec-section--showcase__item_text">In 2014, eLife provided an opportunity to look inside four different labs around the world, as research groups in England, Germany and the US took over the eLife Twitter account to talk about their work, reveal the coolest things in their labs, discuss the most exciting developments in their fields, and introduce us to some group members.</p>
      </div>
      <a class="ec-section--showcase__more_link" href="<?php print url('elife-news/twitter-takeover'); ?>">Learn more</a>
    </article>
    <article class="ec-section--showcase__item ec-section--showcase__item--recommend">
      <div class="ec-section--showcase__item_body">
        <h3 class="ec-section--showcase__item_title">Letters of recommendation</h3>
        <p class="ec-section--showcase__item_text">Graduate students and postdocs need letters of recommendation when they apply for jobs and fellowships. The Senior editors of eLife have, therefore, agreed to write a letter of recommendation on behalf of the first author if requested. Dozens of junior investigators have already benefitted from this service.</p>
      </div>
    </article>
    <article class="ec-section--showcase__item ec-section--showcase__item--podcast">
      <div class="ec-section--showcase__item_body">
        <h3 class="ec-section--showcase__item_title"><a href="<?php print url('podcast'); ?>">The eLife podcast</a></h3>
        <p class="ec-section--showcase__item_text">Our monthly podcasts feature short interviews about selected eLife articles. The interviews frequently involve the early-career researchers responsible for the work.</p>
      </div>
      <a class="ec-section--showcase__more_link" href="<?php print url('podcast'); ?>">Learn more</a>
    </article>
    <article class="ec-section--showcase__item ec-section--showcase__item--researchers">
      <div class="ec-section--showcase__item_body">
        <h3 class="ec-section--showcase__item_title"><a href="<?php print url('content/2/e01633'); ?>">Editorial: eLife and early-career researchers</a></h3>
        <p class="ec-section--showcase__item_text">Those near the start of their career may have time on their side, but when you have an exciting story to tell, and the competition on the career ladder is intense, the last thing you can afford to happen is for your work to languish in a seemingly endless editorial process.</p>
      </div>
      <a class="ec-section--showcase__more_link" href="<?php print url('content/2/e01633'); ?>">Read more</a>
    </article>
    <section class="ec-section--showcase__cta">
      <p class="ec-section--showcase__text">We want to hear from you. If you have questions, comments, or to share your experience and input, contact us:</p>
      <a class="ec-section--showcase__link" href="#share-your-voice">Share your voice</a>
    </section>
  </section> <!-- /.ec-section--showcase -->

  <?php print $profiles; ?>

  <section class="ec-section ec-section--presentations">
    <h2 class="ec-section__heading" id="presentation-series">The eLife-sponsored presentation series</h2>
    <h3 class="ec-section--presentations__subheading">The eLife-sponsored presentation series was first announced in October 2013 to highlight the work of scientists who have yet to become fully established in their respective fields.</h3>
    <p class="ec-section--presentations__body">Twice a year, eLife editors select a small number of the papers published in the journal that will – they feel – prove to be significant in various areas of the life and biomedical sciences. The pre-tenure authors on these papers are then given the opportunity to present at a scientific meeting of one of eLife’s founding organisations – the Howard Hughes Medical Institute, the Max Planck Society and the Wellcome Trust.</p>
    <?php if ($presentation_links): ?>
      <?php if ($presentation_links_title): ?>
        <h3 class="ec-section--presentations__list_title"><?php print $presentation_links_title; ?>:</h3>
      <?php endif; ?>
      <?php print $presentation_links; ?>
    <?php endif; ?>
  </section> <!-- /.ec-section--presentations -->

  <section class="ec-section ec-section--voice">
    <header id="share-your-voice">
      <h2 class="ec-section__heading">Share your voice</h2>
    </header>
    <article class="ec-section--voice__item">
      <p class="ec-section--voice__item_text">The community behind eLife – including the research funders who support the journal, the editors and referees who run the peer review process, and our early-career advisory group – are keenly aware of the pressures faced by junior investigators, and are working to create a more positive publishing experience that will, among other things, help early-career researchers receive the recognition they deserve.</p>
    </article>
    <article class="ec-section--voice__item">
      <p class="ec-section--voice__item_text">We are also keen to hear what you have to say. Contact us by email or Twitter and a member of our advisory group will respond:</p>
      <ul class="ec-section--voice__item_list">
        <li class="ec-section--voice__item_list_item ec-section--voice__item_list_item--mail"><a href="mailto:careers@elifesciences.org">careers@elifesciences.org</a></li>
        <li class="ec-section--voice__item_list_item ec-section--voice__item_list_item--tweet"><a href="http://twitter.com/eLife_careers">@eLife_careers</a></li>
      </ul>
    </article>
    <article class="ec-section--voice__item">
      <ul class="ec-section--voice__item_list">
        <li class="ec-section--voice__item_list_item ec-section--voice__item_list_item--news"><a href="http://crm.elifesciences.org/crm/civicrm/profile/create?reset=1&amp;gid=26">Sign up for news and discussion</a> on our work for early-career scientists</li>
      </ul>
    </article>
  </section> <!-- /.ec-section--voice -->

  <section class="ec-section ec-section--cta">
    <h2 class="ec-section__heading">You can be part of the eLife initiative</h2>
    <a href="<?php print url('http://crm.elifesciences.org/crm/civicrm/profile/create?reset=1&gid=26'); ?>" class="ec-section--cta__link">Share your voice</a>
  </section> <!-- /.ec-section--cta -->
</section> <!-- /.ec-wrapper -->
