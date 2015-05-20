#!/bin/bash
cd /srv/ingestor/
basedir=$PWD

export BEHAT_PARAMS="{\"extensions\": {\"Drupal\\\\DrupalExtension\": {\"drupal\": {\"drupal_root\": \"$basedir\"}}}}"

# Run behat tests
cd $basedir/sites/all/tests/behat
./bin/behat --config behat.ci.yml --tags='~@develop'

cd $basedir
sudo cat /var/log/apache2/error.log

# Run simpletest
# - drush en simpletest --yes
# - drush cc all
# - drush test-run 'eLife Services' --uri=http://127.0.0.1:80 --xml
# - cd $basedir
