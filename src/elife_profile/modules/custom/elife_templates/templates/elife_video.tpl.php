<?php

/**
 * @file
 * templates/elife_video.tpl.php
 */
?>
<video controls="controls" poster="<?php print $poster; ?>" preload="none" style="background-color:black">
<source src="<?php print $mp4; ?>" type="video/mp4; codecs=&quot;avc1.42E01E, mp4a.40.2&quot;"/>
<source src="<?php print $ogv; ?>" type="video/ogg; codecs=&quot;theora, vorbis&quot;"/>
<img src="h<?php print $poster; ?>"/>
Your browser does not appear to support HTML5 video. Please upgrade your browser.
</video>
