#!/usr/bin/env bash

basedir=$( cd $(dirname $0) ; pwd -P )
bdpcdir=$basedir/bin/bdpc
behatdir=$basedir/tests/behat
TAGS="~@develop"
FORMAT="progress"

#########################
# The command line help #
#########################
display_help() {
    echo "Usage: $(basename "$0") [-h] [--tags <tags>] [--format <format>]"
    echo
    echo "   --tags    set tags argument for behat"
    echo "   --format  set format argument for behat"
    exit 1
}

################################
# Check if parameters options  #
# are given on the commandline #
################################
while true;
do
    case "$1" in
      -h | --help)
          display_help
          exit 0
          ;;
      --tags)
          TAGS="$2"
           shift 2
           ;;
      --format)
          FORMAT="$2"
           shift 2
           ;;
      -*)
          echo "Error: Unknown option: $1" >&2
          ## or call function display_help
          exit 1
          ;;
      *)  # No more options
          break
          ;;
    esac
done

# Run behat tests
result=0
cd $behatdir
echo "$behatdir: $bdpcdir --format '$FORMAT' --tags '$TAGS'"
$bdpcdir --format "$FORMAT" --tags "$TAGS"
rc=$?
if [ $rc != 0 ] ; then
    result=$rc
fi

exit $result
