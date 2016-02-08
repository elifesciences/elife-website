<?php
/**
 * @file
 * templates/elife_about.tpl.php
 */
?>
<!-- Headline hero -->
<div class="about-hero-wrapper">
  <header class="about-section about-hero">
    <h1 class="about-heading">Pain-free publishing
      <span class="about-heading__extra">for your best science.</span>
    </h1>
  </header>
  <div class="about-hero__overlay_wrapper">
    <div class="about-hero__overlay_wrapper_mid_line"></div>
    <section class="about-hero__overlay">
      <div class="about-hero__overlay_content">
        <cite>Randy Schekman <span>2013 Nobel Laureate, Editor-in-Chief</span></cite>
        <blockquote class="about-hero__overlay_quote">
          "It&rsquo;s no longer necessary to endure endless cycles of revision and requests for new experiments. eLife editors,
          who are all working scientists, commit to providing clear and constructive feedback quickly."
        </blockquote>
        <a  class="about-hero__overlay_video_link" href="#process"><div class="about-hero__overlay_video_link_inner">Watch video</div></a>
      </div> <!-- /.about-hero__overlay_content -->
      <div class="about-hero__overlay_funders">
        <!-- 303 x 74 -->
        <p class="about-hero__overlay_funders_text">Supported by:<p>
          <img class="about-hero__overlay_funders_image"
               src="<?php print drupal_get_path('module', 'elife_about') . '/images/Funder_logos_2014_54.png';?>"
               alt="Logos of the 3 eLife funders: Max Planck Institute, Howard Hughes Medical Institute and Wellcome Trust">
      </div> <!-- /.about-hero__overlay_funders -->
    </section> <!-- /.about-hero__overlay -->
  </div> <!-- /.about-hero__overlay_wrapper -->
</div> <!-- /.about-header-wrapper -->

<!-- Why publish with us -->
<section class="about-section about-why-us" id="why">
  <div class="about-why-us__wrapper">
    <h2 class="about-heading">Why publish with us?</h2>
    <ul class="about-why-us__list">
      <li class="about-why-us__list_item">
        <h3 class="about-why-us__list_item_heading">
          <div class="about-why-us__list_item_hook">Speed</div>
          Get your results out fast
        </h3>
        <p class="about-why-us__list_item_details">Initial decisions are made in a few days, post-review decisions in
          about a month, and most articles go through only one round of revision. Every author also has the option to
          make their accepted manuscript openly available shortly after receiving a final decision.</p>
      </li>
      <li class="about-why-us__list_item">
        <h3 class="about-why-us__list_item_heading">
          <div class="about-why-us__list_item_hook">Great backing</div>
          We support early career scientists
        </h3>
        <p class="about-why-us__list_item_details">To support job, tenure and funding applications, the eLife Senior
          editor who handles your paper is willing to write a letter of recommendation that describes the significance
          of your article.</p>
      </li>
      <li class="about-why-us__list_item">
        <h3 class="about-why-us__list_item_heading">
          <div class="about-why-us__list_item_hook">Review process</div>
          Taking the pain out of peer review
        </h3>
        <p class="about-why-us__list_item_details">The scientist editors who run eLife will give you feedback that&rsquo;s
          constructive and fair.  If invited to revise your work, you&rsquo;ll receive a single consolidated list of comments,
          so that you know exactly what you need to do to get your work published.</p>
      </li>
      <li class="about-why-us__list_item">
        <h3 class="about-why-us__list_item_heading">
          <div class="about-why-us__list_item_hook">Research assessment</div>
          eLife will not promote the Impact Factor
        </h3>
        <p class="about-why-us__list_item_details">We&rsquo;ll promote your work, and provide quantitative and qualitative
          indicators about its reach and influence. eLife is working to expand and enrich the concept of research impact
          beyond the use of a single number and a journal name.</p>
      </li>
      <li class="about-why-us__list_item">
        <h3 class="about-why-us__list_item_heading">
          <div class="about-why-us__list_item_hook">Reach</div>
          Get great exposure
        </h3>
        <p class="about-why-us__list_item_details">eLife papers get great media coverage in venues like the New York Times
          and National Geographic. We make every paper more accessible to a broad set of readers &ndash; including
          students, colleagues in other fields, and the public &ndash; through Impact statements, plain language summaries
          (eLife Digests), and selected expert commentaries (eLife Insights). eLife articles are immediately and freely
          available to the world &ndash; and there&rsquo;s no cost to publish.</p>
      </li>
      <li class="about-why-us__list_item">
        <h3 class="about-why-us__list_item_heading">
          <div class="about-why-us__list_item_hook">Community driven</div>
          Scientists make the decisions
        </h3>
        <p class="about-why-us__list_item_details">eLife is a unique, non-profit, researcher-driven initiative. Editorial
          decisions are made exclusively by working scientists in your field.</p>
      </li>
    </ul>
    <!-- Not enouh pseudo elements to hang decorations off :-(  -->
    <div class="about-why-us__decoration"></div>
  </div> <!-- /.about-why-us__wrapper -->
  <ul class="about-why-us__testimonials_list">
    <li class="about-why-us__testimonial">
      <cite>Marianne Bronner <span>Caltech</span></cite>
      <blockquote class="about-why-us__testimonial_quote">
        "We had a great experience publishing in eLife and were particularly amazed at the great publicity the paper
        received. My post-docs are now convinced that this is a good place to publish so I&rsquo;m confident that the next
        paper we consider sending to [a high profile journal] will go to eLife."
      </blockquote>
    </li>
    <li class="about-why-us__testimonial">
      <cite>Bassem Hassan <span>KU Leuven</span></cite>
      <blockquote class="about-why-us__testimonial_quote">
        "The reviewer consultation process where the reviewers, the reviewing editor and the senior editor all work
        together is fantastic. What a unique and positive experience. eLife is a truly transformative journal."
      </blockquote>
    </li>
    <li class="about-why-us__testimonial">
      <cite>Wolf B. Frommer <span>Carnegie Institution for Science</span></cite>
      <blockquote class="about-why-us__testimonial_quote">
        "I am very happy my paper was accepted by <i>eLife</i>, but I have to say that it was a wonderful experience all
        around. Constructive criticism, plus rapid decisions and no big fuss. Congratulations for setting this journal
        up ... you guys will take <i>eLife</i> to the top."
      </blockquote>
    </li>
  </ul> <!-- /.about-why-us__testimonials_list -->
</section> <!-- /.about-why-us -->

<?php print $profiles; ?>

<div style="clear: both;"></div>

<!-- Review process -->
<section class="about-section about-review-process" id="process">
  <h2 class="about-heading">Review process</h2>
  <div class="about-review-process__embed_wrapper_outer">
    <div class="about-review-process__embed_wrapper">
      <iframe src="http://player.vimeo.com/video/49775707?title=0&amp;byline=0&amp;portrait=0" width="500"
              height="281" frameborder="0" webkitallowfullscreen mozallowfullscreen allowfullscreen></iframe>
    </div> <!-- /.about-review-process__embed_wrapper -->
  </div> <!-- /.about-review-process__embed_wrapper_outer -->
  <div class="about-review-process__wrapper">
    <div class="about-review-process__text_wrapper">

      <p class="about-review-process__intro">At eLife, we&rsquo;ve taken a fresh approach to peer review to save you time, and to
        provide clear direction and constructive input. Decisions are quick and efficient; revision requests are designed
        to be clear and manageable; and multiple rounds of revision are usually avoided. Here&rsquo;s how it works:</p>
      <ol class="about-review-process__list">
        <li>
          <h3 class="about-review-process__list_term">Initial decisions are delivered quickly</h3>
          <div class="about-review-process__list_definition">Our Senior editors decide whether initial submissions are
            appropriate for in-depth peer review, usually in consultation with members of the Board of Reviewing
            Editors.</div>
        </li>
        <li>
          <h3 class="about-review-process__list_term">Active scientists make all decisions</h3>
          <div class="about-review-process__list_definition">A Senior editor assigns a member of the Board of Reviewing
            Editors to oversee the peer-review process. The Reviewing editor usually reviews the article him or herself,
            calling on one or two additional reviewers as needed.</div>
        </li>
        <li>
          <h3 class="about-review-process__list_term">Revision requests are consolidated</h3>
          <div class="about-review-process__list_definition">Reviewers get together online to discuss their recommendations,
            refining their feedback, and striving to provide clear and concise guidance. If the work needs essential
            revisions before it can be published, the Reviewing editor incorporates those requirements into a single set
            of instructions.</div>
        </li>
        <li>
          <h3 class="about-review-process__list_term">Limited rounds of revision</h3>
          <div class="about-review-process__list_definition">Additional rounds of revision are largely eliminated, as the
            Reviewing editor is able to assess most revised submissions without further outside review.</div>
        </li>
        <li>
          <h3 class="about-review-process__list_term">Decisions and responses are available for all to read</h3>
          <div class="about-review-process__list_definition">In the interests of openness and transparency we publish
            the most substantive parts of the decision letter after review and the associated author responses.</div>
        </li>
      </ol>
    </div> <!-- /.about-review-process__text_wrapper -->
    <div class="about-review-process__facets">
      <div class="about-review-process__facet">
        <div class="about-review-process__facet_datum">3</div>
        <div class="about-review-process__facet_unit">days to initial decision&nbsp;<sup>*</sup></div>
      </div>
      <div class="about-review-process__facet">
        <div class="about-review-process__facet_datum">29</div>
        <div class="about-review-process__facet_unit">days to post-review decision&nbsp;<sup>*</sup></div>
      </div>
      <div class="about-review-process__facet">
        <div class="about-review-process__facet_datum">90</div>
        <div class="about-review-process__facet_unit">days submission to acceptance&nbsp;<sup>*</sup></div>
      </div>
      <div class="about-review-process__facets_qualifier">* median times, through the end of April 2014</div>
    </div> <!-- /.about-review-process__facets -->
  </div>
  <div class="clear"></div>
</section> <!-- /.about-review-process -->

<!-- Submit -->
<section class="about-section about-submit-cta">
  <h2 class="about-heading">Working on something interesting?</h2>
  <a href="https://crm.elifesciences.org/crm/civicrm/event/register?reset=1&id=14" class="about-submit-cta_link">Let us know now</a>
</section> <!-- /.about-submit-cta -->
