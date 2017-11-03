#!/bin/bash
usage () {
  echo "This command needs a valid file name"
}
if [ $# -ne 1 ]; then
  usage
  exit 1;
elif [ ! \( -f ${1} \) ]; then
  usage
  exit 1
fi
file_name="${1}"
egrep -i "a" "${file_name}" | \
egrep -i "e" | egrep -i "u" | egrep -i "o" | \
egrep -i "i"
exit 0
