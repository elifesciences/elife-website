<?php

/**
 * @file
 * templates/elife_video.tpl.php
 *
 * N.B. Changes to this file won't manifest until the elife_markup table is truncated.
 */
?>
<video controls="controls" poster="<?php print $poster; ?>" preload="metadata">
  <source src="<?php print $mp4; ?>" type='video/mp4; codecs="avc1.42E01E, mp4a.40.2"' />
  <source src="<?php print $webm; ?>" type='video/webm; codecs="vp8.0, vorbis"' />
  <source src="<?php print $ogv; ?>" type='video/ogg; codecs="theora, vorbis"' />
  <img src="<?php print $poster; ?>" />
  <p>This video cannot be played in place because your browser does support HTML5 video. You may still download the video for offline viewing in <a href="<?php print $mp4; ?>">mp4</a>, <a href="<?php print $webm; ?>">webm</a> or <a href="<?php print $ogv; ?>">ogg</a> formats.</p>
</video>
