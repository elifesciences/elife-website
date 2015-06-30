#!/usr/bin/env bash

basedir=$( cd $(dirname $0) ; pwd -P )

# Set flag to ingest citations
cd $basedir/web
drush vset elife_article_ingest_citations 1 -y
drush cc all

# Run behat tests
result=0
cd $basedir/tests/behat
./bin/behat --format progress --tags='~@develop'
rc=$?
if [ $rc != 0 ] ; then
    result=$rc
fi

# Delete flag to ingest citations
cd $basedir/web
drush vdel elife_article_ingest_citations -y
drush cc all

exit $result
