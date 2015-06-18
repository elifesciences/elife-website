#!/usr/bin/env bash

SCRIPTPATH=$( cd $(dirname $0) ; pwd -P )

cd "$SCRIPTPATH"
if [ -d ./web/ ]; then
  chmod -R 777 ./web/
  rm -rf ./web
fi
drush make ./src/drupal.make.yml ./web
ln -s "$SCRIPTPATH/src/" "$SCRIPTPATH/web/profiles/"
mv ./web/profiles/src ./web/profiles/elife_profile
cp ./settings.php ./web/sites/default
./remake.sh
cd ./web
drush site-install elife_profile --account-name=admin --account-pass=password --site-name="eLife Sciences" --yes
