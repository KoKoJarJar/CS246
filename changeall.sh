#!/bin/bash
# changeall [-r|-R] "from-pattern" "to-pattern" [directory]
# changs all occurences of an arbitrary pattern "from-pattern"
# to pattern "to-pattern" on files .h/.C/.cpp/.cc and prints
# the names of the changed files in sorted order
# [-R|-r] represents the recursivity of the function and [directory]
# is the targeted directory, if absent the script is called on the
# working directory
# requires: files names do not contain blank or special characters

usage() {
  printf "\n changeall [-r|-R] \"from-pattern\" \"to-pattern\" [directory]" 1>&2;
  exit 1
}
max_depth="-maxdepth 0"
directory=""
case "${1}" in
  '-r' | '-R' )
    maxdepth=""
    shift ;;
esac
if [ \( $# -lt 2 \) -a \( $# -gt 3 \) ]; then
  usage
elif [ $# -eq 3 ]; then
  directory="${3}"
  if [ ! \( \( -d "${directory}" \) -a \( -x "${directory}" \) \) ]; then
    echo "not a directory or no permissions given" 1>&2;
    exit 1
  fi
fi
from_pattern="${1}"
to_pattern="${2}"
temp_file="$( mktemp . )"
for index in $(find "${max_depth}" "${directory}" "*.{cc,cpp,C,h}"); do
  helper=echo "${index}" | sed "s:"${from_pattern}":${to_pattern}:g" | egrep ".+"
  if [ "${helper}" = "" ]; then
    continue
  fi
  "${helper}" >> "${temp_file}"
  mv "${index}" "${helper}"
done
$( cat "${temp_file}" | sort>&1 )

