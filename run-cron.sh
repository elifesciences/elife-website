#!/bin/bash -l
set -e # all commands must pass
cd "$(dirname "$0")"

if [ ! -e ./web/sites/default/settings.php ]; then
    echo "could not find web/sites/default/settings.php"
    exit 1;
fi

cd web
drush core-cron
