#!/usr/bin/env bash

SCRIPTPATH=$( cd $(dirname $0) ; pwd -P )

cd "$SCRIPTPATH/web"
/usr/bin/env PHP_OPTIONS="-d sendmail_path=`which true`" drush site-install elife_profile --account-name=admin --account-pass=password --site-name="eLife Sciences" --yes
