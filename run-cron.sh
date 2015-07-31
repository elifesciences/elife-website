#!/usr/bin/env bash

SCRIPTPATH=$( cd $(dirname $0) ; pwd -P )

cd "$SCRIPTPATH"
if [ -e ./web/sites/default/settings.php ]; then
  cd web
  drush core-cron
fi
