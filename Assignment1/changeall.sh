#!/bin/bash
#
# changes all occurences of an arbitrary pattern "from-pattern"
# to pattern "to-pattern" on files .h/.C/.cpp/.cc and prints
# the names of the changed files in sorted order
#
# usage: changeall [-r|-R] "from-pattern" "to-pattern" [directory]
# [-R|-r] represents the recursivity of the function 
# [directory] is the targeted directory 
# Examples: changeall -r "bla" "bloo"
# Examples: changeall "([ab])([ab])." "\2\1x" .
# requires: files names do not contain blank or special characters

usage() {
  printf "changeall [-r|-R] \"from-pattern\" \"to-pattern\" [directory]\n" 1>&2;
  exit 1
}
max_depth="-maxdepth 1"
directory="."
case "${1}" in
  '-r' | '-R' )
    max_depth=""
    shift ;;
esac
if [ \( $# -lt 2 \) -o \( $# -gt 3 \) ]; then
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
temp_file="$( mktemp -p . )"
for index in $( find ${directory} ${max_depth} -name "*.cpp" -o -name "*.C" -o -name "*.h" -o -name "*.cc" ); do
  suffix="$( echo "${index}" | sed -E "s:(.*)(\..*):\2:" )"
  prefix="$( echo "${index}" | sed -E "s:(.*)(\..*):\1:" )"
  helper="$( echo "${prefix}" | sed -En "s:${from_pattern}:${to_pattern}:gp" | egrep ".+" )"
  if [ "${helper}" = "" ]; then
    continue
  fi
  helper="${helper}${suffix}"
  echo "${helper}" >> "${temp_file}"
  mv "${index}" "${helper}" 2>"/dev/null"
done
cat "${temp_file}" | sort 
rm "${temp_file}"
exit 0
