#!/usr/bin/env bash
set -e # all commands must pass

SCRIPTPATH=$( cd $(dirname $0) ; pwd -P )

cd "$SCRIPTPATH/web"
redis-cli flushall
/usr/bin/env PHP_OPTIONS="-d sendmail_path=`which true`" drush site-install elife_profile --account-name=admin --account-pass=password --site-name="eLife" --yes
drush variable-delete --exact node_access_needs_rebuild --yes # As there's no content, no need to do anything.
