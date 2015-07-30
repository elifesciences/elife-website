#!/usr/bin/env bash

SCRIPTPATH=$( cd $(dirname $0) ; pwd -P )

cd "$SCRIPTPATH"
rm -rf ./src/elife_profile/libraries/
rm -rf ./src/elife_profile/modules/contrib/
rm -rf ./src/elife_profile/themes/contrib/
drush make --no-core --concurrency=3 --no-recursion --contrib-destination=. ./src/elife_profile/elife_profile.make.yml ./src/elife_profile
npm install --prefix ./src/elife_profile/libraries/elife-eif-schema/
# See https://github.com/wikimedia/composer-merge-plugin/issues/34#issuecomment-126305530 re the below
cp composer.lock composer.lock.orig
composer install --no-interaction
mv composer.lock.orig composer.lock
composer install --no-interaction
