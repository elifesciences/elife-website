#!/usr/bin/env bash
set -e # all commands must pass

SCRIPTPATH=$( cd $(dirname $0) ; pwd -P )

cd "$SCRIPTPATH/web"
drush variable-set --exact maintenance_mode 1 --yes
drush registry-rebuild
drush updatedb --yes
drush features-revert-all --yes
drush elife-environment-modules
if [[ $(drush php-eval "print node_access_needs_rebuild()") == "1" ]]; then drush node-access-rebuild; fi;
drush variable-set --exact maintenance_mode 0 --yes
