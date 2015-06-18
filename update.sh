#!/usr/bin/env bash

SCRIPTPATH=$( cd $(dirname $0) ; pwd -P )

cd "$SCRIPTPATH/web"
drush variable-set --exact maintenance_mode 1 --yes
drush registry-rebuild
drush updatedb --yes
drush features-revert-all --yes
drush variable-set --exact maintenance_mode 0 --yes
