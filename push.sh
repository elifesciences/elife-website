#!/bin/bash
set -e
# since platform.sh may return a 0 exit code on push
# even in case of errors, we check also the output being printed

if [ "$#" -ne 2 ]; then
    echo Usage: ./push.sh REMOTE BRANCH
    exit 1
fi

remote=$1
branch=$2
result=$(git push "$remote" "$branch" 2>&1)
echo "$result"

if [[ "$result" == *"[error]"* ]]; then
    echo "Result contains [error] instances"
    exit 2
fi
