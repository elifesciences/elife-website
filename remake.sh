#!/usr/bin/env bash
set -e # all commands must pass

SCRIPTPATH=$( cd $(dirname $0) ; pwd -P )
DEV=true

while true;
do
    case "$1" in
      --no-dev)
          DEV=false
           shift
           ;;
      -*)
          echo "Error: Unknown option: $1" >&2
          exit 1
          ;;
      *)  # No more options
          break
          ;;
    esac
done

cd "$SCRIPTPATH"
rm -rf ./src/elife_profile/libraries/
rm -rf ./src/elife_profile/modules/contrib/
rm -rf ./src/elife_profile/themes/contrib/
if [ $DEV = true ] ; then
    drush make --no-core --concurrency=3 --no-recursion --contrib-destination=. ./src/elife_profile/elife_profile.make.dev.yml ./src/elife_profile
    npm install --prefix ./src/elife_profile/libraries/elife-eif-schema/
    composer install --prefer-dist --no-interaction
else
    drush make --no-core --concurrency=3 --no-recursion --contrib-destination=. ./src/elife_profile/elife_profile.make.yml ./src/elife_profile
    npm install --prefix ./src/elife_profile/libraries/elife-eif-schema/
    composer install --prefer-dist --no-interaction --no-dev --optimize-autoloader --classmap-authoritative
fi
