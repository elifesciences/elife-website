#!/usr/bin/env bash

basedir=$( cd $(dirname $0) ; pwd -P )

# Run behat tests
result=0
cd $basedir/tests/behat
./bin/behat --format progress --tags='~@develop'
rc=$?
if [ $rc != 0 ] ; then
    result=$rc
fi

exit $result
