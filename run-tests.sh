#!/usr/bin/env bash

basedir=$( cd $(dirname $0) ; pwd -P )

# Run behat tests
cd $basedir/tests/behat
./bin/behat --format progress --tags='~@develop'

# Run simpletest
# - drush en simpletest --yes
# - drush cc all
# - drush test-run 'eLife Services' --uri=http://127.0.0.1:80 --xml
# - cd $basedir
