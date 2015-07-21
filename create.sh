#!/usr/bin/env bash

SCRIPTPATH=$( cd $(dirname $0) ; pwd -P )

cd "$SCRIPTPATH"
if [ -d ./web/ ]; then
  chmod -R 777 ./web/
  rm -rf ./web
fi
drush make ./src/drupal.make.yml ./web
ln -s "../../src/elife_profile" "$SCRIPTPATH/web/profiles/"
ln -s "../../../src/settings.php" "$SCRIPTPATH/web/sites/default/"
./remake.sh
cd ./web
/usr/bin/env PHP_OPTIONS="-d sendmail_path=`which true`" drush site-install elife_profile --account-name=admin --account-pass=password --site-name="eLife Sciences" --yes
