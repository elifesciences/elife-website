#!/usr/bin/env bash

SCRIPTPATH=$( cd $(dirname $0) ; pwd -P )

cd "$SCRIPTPATH"
rm -rf ./src/elife_profile/libraries/
rm -rf ./src/elife_profile/modules/contrib/
rm -rf ./src/elife_profile/themes/contrib/
drush make --no-core --concurrency=3 --contrib-destination=. ./src/elife_profile/elife_profile.make.yml ./src/elife_profile
npm install --prefix ./src/elife_profile/libraries/elife-eif-schema/
composer install --no-interaction --working-dir=./src
