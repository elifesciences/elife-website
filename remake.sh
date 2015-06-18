#!/usr/bin/env bash

SCRIPTPATH=$( cd $(dirname $0) ; pwd -P )

cd "$SCRIPTPATH"
rm -rf ./src/libraries/
rm -rf ./src/modules/contrib/
rm -rf ./src/themes/contrib/
drush make --no-core --concurrency=3 --contrib-destination=. ./src/elife_profile.make.yml ./src
