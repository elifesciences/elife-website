eLife Controller Module
=====================

By Nathan Lisgo for eLife
nathan@aeopus.com

=====================

Controller module to handle enabling/disabling of modules and reverting features amongst other things

The purpose of this module is to allow the updates to a project to be automated. In many cases this is achievable
without a controller module but in the instance of needing to introduce and enable a new module or to revert a specific
feature then specific instructions would need to be provided to be carried out at the point of deployment.

For example, if the rules module was introduced to the code base and the developer wanted to ensure that the module was
enabled on either UAT or PROD then the specific module would need to be enabled after the code was introduced. With a
controller module you can trigger the enabling/disabling of modules in an update hook and simply require the release
manager to hit update.php or `drush updatedb` and then the outstanding updates will be run.

Here is an example of how to enable the Rules module by using the update hook in the elife_profile_controller.install file:

/**
 * Enabling Rules module
 */
function elife_profile_controller_update_7000()
{
  $modules = array('rules');
  drupal_install_modules($modules);
}
