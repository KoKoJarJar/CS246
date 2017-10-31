#!/bin/bash
#
# Regression scrips which checks a program's input and output
# with expect behaviours and regressions
#
# usage: regress program [-o options] [prefix file] [-p prefix-list]
# program: program being tested
# -o options: the default program options
# prefix file: file containing the name of input files (without .in)
# -p prefix-list: list of file names for inputs (without .in)
# both aforementioned options can be used together
# examples:
# regress cat -o -n -p test
# cat -n is being tested on test.in
# regress regress -o "cat -o -n -p -test" -p input
# restrictions:
# the input and output files have suffixes .in and .out resp.
# names should not contain special characters or blanks
# files called xxx.args can be used to individually pass
# the program options for test xxx.in and expected output xxx.out
# (overrides default -o for the specific xxx.in)

usage() {
  echo "regress program [-o option] [prefix file] [-p prefix-list]" 1>&2
  exit 1
}
program="${1}"
shift
if [ $# -eq 0 ]; then
  usage
fi
while [ $# -gt 0 ]; do
  case ${1} in
    '-o' )
      shift
      opts="${1}" ;;
    '-p' )
      shift
      while [ $# -gt 0 ]; do
        prefix_list="${prefix_list} ${1}"
        shift
      done ;;
    [!-]* )
      if [ "${signal}" != "" ]; then
        usage
      fi
      signal="yes"
      prefix_file="${1}"
      if [ ! \( -f "${prefix_file}" -a -r "${prefix_file}" \) ]; then
        echo "${prefix_file} doesn't have read access or it doesn't exist" 1>&2
      else
        prefix_list="$( sed -E "s:[[space]]+: :g" < "${prefix_file}" | tr '\n' ' ' )"
      fi ;;
    '-h' ) usage ;;
    * ) usage ;;
  esac
  shift
done
if [ "${prefix_list}" = "" ]; then
  echo "No input files specified" 1>&2
  exit 1
fi
if [ $# -gt 0 ]; then
  usage
fi
temp_file=$( mktemp -p . )
for arg in ${prefix_list}; do
  input_name="${arg}.in"
  output_name="${arg}.out"
  if [ ! \( -r "${input_name}" -a -f "${input_name}" \) ]; then
    echo "${input_name} doesn't have read access or it doesn't exist" 1>&2
    continue
  fi
  if [ ! \( -r "${output_name}" -a -f "${output_name}" \) ]; then
    echo "${output_name} doesn't have read access or it doesn't exist" 1>&2
    continue
  fi
  args_name="${arg}.args"
  current_test_opts="${opts}"
  if [ \( -r "${args_name}" -a -f "${args_name}" \) ]; then
    current_test_opts="$( sed -E "s:[[space]]+: :g" < "${args_name}" | tr '\n' ' ' )"
  fi
  ${program} ${current_test_opts} < "${input_name}" 1>"${temp_file}" 2>"/dev/null"
  if [ ${?} -ne 0 ]; then
    echo "${program} could not process ${input_name}" 1>&2
    continue
  fi
  diff="$(diff "${temp_file}" "${output_name}")"
  if [ "${diff}" = "" ]; then
    echo "identical output for prefix \"${arg}\""
  else
    echo "\"${arg}\":"
    echo "${diff}"
  fi
done
rm "${temp_file}"
exit 0
