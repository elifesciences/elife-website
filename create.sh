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
if [ $DEV = true ] ; then
    ./setup.sh
else
    ./setup.sh --no-dev
fi
./install.sh
