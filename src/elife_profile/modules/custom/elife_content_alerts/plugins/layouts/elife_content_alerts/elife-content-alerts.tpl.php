<?php

/**
 * @file
 * eLife: Content Alerts (VOR)
 */
?>
<table align="center" cellpadding="23" cellspacing="0" id="email" width="600" style="font-family: Helvetica, Arial, sans-serif; font-size: .85em; color: #333333;">
  <tbody>
    <tr>
      <td style="padding: 20px 0;">

        <table border="0" cellpadding="0" cellspacing="0" width="554">
          <tbody>

            <!--header starts-->
            <tr>
              <td>
              <?php if ($content['header']): ?>
                <?php print $content['header']; ?>
              <?php endif; ?>
                <table width="554" style="margin-bottom: 10px">
                  <tbody>
                    <tr>
                      <td style="height: 90px;">
                        <?php if ($content['logo']): ?>
                          <?php print $content['logo']; ?>
                        <?php endif; ?>
                      </td>
                      <td style="text-align:right;">
                        <p style="font-size: 12px;">New from <em>eLife</em><br>
                        <strong>
                        <?php if ($content['alert_date']): ?>
                          <?php print $content['alert_date']; ?>
                        <?php else: ?>
                          <?php print date('F j, Y'); ?>
                        <?php endif; ?>
                        </strong>
                        </p>
                      </td>
                    </tr>
                  </tbody>
                </table>

              </td>
            </tr>
            <!--header ends-->

            <?php if ($content['intro']): ?>
            <!--lead in and link to alert sign up-->
            <tr>
              <td style="padding: 0">

                <table width="554" style="border-top-width: 1px; border-top-color: #dfdddd; border-top-style: solid; border-bottom-width: 1px; border-bottom-color: #dfdddd; border-bottom-style: solid; padding: 5px 0; text-align:center;">
                  <tbody>
                    <tr>
                      <td align="center"><?php print $content['intro']; ?></td>
                    </tr>
                  </tbody>
                </table>

              </td>
            </tr>
            <!--lead in and link to alert sign up ends-->
            <?php endif; ?>

            <?php if ($content['categories']): ?>
            <!--quick links starts-->
            <tr>
              <td>

                <table width="554" style="border-bottom-width: 1px; border-bottom-style: solid; border-bottom-color: #dfdddd; margin-bottom: 20px;">
                  <tbody>
                    <tr>
                      <td style="padding-bottom: 20px; padding-top: 10px">

                        <?php print $content['categories']; ?>

                      </td>
                    </tr>
                  </tbody>
                </table>

              </td>
            </tr>
            <!--quick links ends-->
            <?php endif; ?>

            <?php if ($content['front']): ?>
            <!--front matter starts-->
            <tr>
              <td>

                <table width="554" style="border-bottom-width: 1px; border-bottom-style: solid; border-bottom-color: #dfdddd; margin-bottom: 20px">
                  <tbody>
                    <tr>
                      <td>

                        <h3 style="font-size: 14px; line-height: 22px; margin: 0;">Magazine</h3>

                        <?php print $content['front']; ?>

                      </td>
                    </tr>
                  </tbody>
                </table>

              </td>
            </tr>
            <!--front matter ends-->
            <?php endif; ?>

            <?php if ($content['content']): ?>
            <!--articles start-->
            <tr>
              <td>

                <table width="554" style="border-bottom-color: #dfdddd; border-bottom-width: 1px; border-bottom-style: solid; margin-bottom: 10px">
                  <tbody>
                    <tr>
                      <td>

                        <h3 style="font-size: 14px; line-height: 22px; margin: 0;">Research</h3>

                        <?php print $content['content']; ?>

                      </td>
                    </tr>
                  </tbody>
                </table>

              </td>
            </tr>
            <!--articles end-->
            <?php endif; ?>

            <!--small print-->
            <tr>
              <td>

                <table width="554" style="margin-bottom: 20px;">
                  <tbody>
                    <tr>
                      <td>
                        <p style="font-size:10px; line-height:22px; color:#929497;">For the media</p>
                        <p style="font-size:10px; line-height:22px; color:#929497;">Contact: Emily Packer on <a href="mailto:press@elifesciences.org" style="color: #0961AB;">press@elifesciences.org</a>, +44 (0)1223855373. Please cite <em>eLife</em> as the source of these articles and include a link to either the article or elifesciences.org. Thank you! More details available at <a href="http://elifesciences.org/for-the-press?utm_source=content_alert&utm_medium=email&utm_content=fulltext&utm_campaign=elife-alerts" style="color: #0961AB;">http://elifesciences.org/for-the-press</a>.</p>
                        <p style="font-size:10px; line-height:22px; color:#929497;">To be notified of new content at eLife, sign up at <a href="https://crm.elifesciences.org/crm/civicrm/profile/create?reset=1&gid=11" style="color: #0961AB;">https://crm.elifesciences.org/crm/civicrm/profile/create?reset=1&gid=11</a>.</p>
                        <p style="font-size:10px; line-height:22px; color:#929497;">eLife XML is available at Github.</p>
                        <p style="font-size:10px; line-height:22px; color:#929497;">Thanks for subscribing to receive alerts from eLife, the journal for the very best in life science and biomedical research, supported by the Howard Hughes Medical Institute, the Max Planck Society, and the Wellcome Trust. If you have any questions or comments, feel free to contact us.</p>
                      </td>
                    </tr>
                  </tbody>
                </table>

              </td>
            </tr>
            <!--small print ends-->

            <!--address-->
            <tr>
              <td>
                <table width="554" style="border-top-width: 1px; border-top-color: #dfdddd; border-top-style: solid; padding: 10px 0;">
                  <tbody>
                    <tr>
                      <td>
                        <p style="font-size:10px; line-height:22px; color:#929497;">© eLife Sciences Publications Ltd, subject to <a href="http://creativecommons.org/licenses/by/3.0/" style="color: #0961AB;">CC-BY license</a>, ISSN – 2050–084X</p>
                      </td>
                    </tr>
                  </tbody>
                </table>
                </table>
              </td>
            </tr>
            <!--address ends-->

          </tbody>
        </table><!--table 554px wide-->

      </td>
    </tr>
  </tbody>
</table><!--table 600px wide-->
