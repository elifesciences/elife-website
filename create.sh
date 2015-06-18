#!/usr/bin/env bash

SCRIPTPATH=$( cd $(dirname $0) ; pwd -P )

cd "$SCRIPTPATH"
if [ -d ./web/ ]; then
  chmod -R 777 ./web/
  rm -rf ./web
fi
drush make ./src/drupal.make.yml ./web
ln -s "$SCRIPTPATH/src/elife_profile" "$SCRIPTPATH/web/profiles/"
ln -s "$SCRIPTPATH/src/settings.php" "$SCRIPTPATH/web/sites/default/"
./remake.sh
cd ./web
drush site-install elife_profile --account-name=admin --account-pass=password --site-name="eLife Sciences" --yes
