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
if [ -d ./web/ ]; then
  chmod -R 777 ./web/
  rm -rf ./web
fi
drush make ./src/drupal.make.yml ./web
ln -s "../../src/elife_profile" "$SCRIPTPATH/web/profiles/"
ln -s "../../../src/settings.php" "$SCRIPTPATH/web/sites/default/"
if [ $DEV = true ] ; then
    ./remake.sh
else
    ./remake.sh --no-dev
fi
